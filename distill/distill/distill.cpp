// This is the main DLL file.

#include "stdafx.h"


#include "clang\Frontend\ASTUnit.h"
#include "clang\Frontend\CompilerInvocation.h"
#include "clang\Frontend\CompilerInstance.h"
#include "clang\Frontend\FrontendAction.h"
#include "clang\Frontend\FrontendActions.h"

#include "distill.h"
#include "StringUtilities.h"
#include "DistillFrontendAction.h"
#include "DistillCodeClassWrapper.h"
#include "DistillCodeFunctionWrapper.h"
#include "DistillCodeVariableWrapper.h"
#include "DistillCodeStructWrapper.h"

using namespace Distill;
using namespace Distill::Types;
using namespace System::Runtime::InteropServices;

class StoredDiagnosticClient : public clang::DiagnosticConsumer
{
	std::vector<clang::StoredDiagnostic> diags;

public:
	virtual void HandleDiagnostic(clang::DiagnosticsEngine::Level DiagLevel,
		const clang::Diagnostic& Info)
	{
		diags.push_back(clang::StoredDiagnostic(DiagLevel, Info));
	}

	virtual bool IncludeInDiagnosticsCount() const { return true; }

	void clear() { diags.clear(); }

	unsigned int size() { return diags.size(); }
	clang::StoredDiagnostic& getDiagInfo(unsigned int elementIndex)
	{
		return diags[elementIndex];
	}

	virtual DiagnosticConsumer *clone(clang::DiagnosticsEngine &Diags) const
	{
		StoredDiagnosticClient *client = new StoredDiagnosticClient();
		client->diags = diags;
		return client;
	}
};

CodeModelProvider::CodeModelProvider(String ^file, List<String ^> ^pSymbols, List<String ^> ^iPaths, Language lang, Arch a)
{
	includePaths = iPaths;
	predefinedSymbols = pSymbols;
	language = lang;
	arch = a;
	filePath = (const char *) ToCString(file);
}

List<System::Object ^>^ MapClasses(std::vector<DistillCodeClassWrapper> &classes)
{
	int length = classes.size();
	List<System::Object ^>^ c = gcnew List<System::Object ^>();
	for (int i = 0 ; i<length; ++i)
	{
		DistillCodeClass ^cl = gcnew DistillCodeClass();
		cl->Name = ToManagedString(classes[i].Name.c_str());
		cl->FullName = ToManagedString(classes[i].FullName.c_str());
		c->Add(cl);
	}

	return c;
}

List<System::Object ^>^ MapFunctions(std::vector<DistillCodeFunctionWrapper> &functions)
{
	int length = functions.size();
	List<System::Object ^>^ c = gcnew List<System::Object ^>();
	for (int i = 0 ; i<length; ++i)
	{
		DistillCodeFunction ^cl = gcnew DistillCodeFunction();
		cl->Name = ToManagedString(functions[i].Name.c_str());
		cl->FullName = ToManagedString(functions[i].FullName.c_str());
		c->Add(cl);
	}

	return c;
}

List<System::Object ^>^ MapMethods(std::vector<DistillCodeFunctionWrapper> &methods)
{
	int length = methods.size();
	List<System::Object ^>^ c = gcnew List<System::Object ^>();
	for (int i = 0 ; i<length; ++i)
	{
		DistillCodeFunction ^cl = gcnew DistillCodeFunction();
		cl->Name = ToManagedString(methods[i].Name.c_str());
		cl->FullName = ToManagedString(methods[i].FullName.c_str());
		c->Add(cl);
	}

	return c;
}

List<System::Object ^>^ MapVariables(std::vector<DistillCodeVariableWrapper> &variables)
{
	int length = variables.size();
	List<System::Object ^>^ c = gcnew List<System::Object ^>();
	for (int i = 0 ; i<length; ++i)
	{
		DistillCodeVariable ^cl = gcnew DistillCodeVariable();
		cl->Name = ToManagedString(variables[i].Name.c_str());
		cl->FullName = ToManagedString(variables[i].FullName.c_str());
		c->Add(cl);
	}

	return c;
}


List<System::Object ^>^ MapUnion(std::vector<DistillCodeStructWrapper> &unionMembers)
{
	int length = unionMembers.size();
	List<System::Object ^>^ c = gcnew List<System::Object ^>();
	for (int i = 0 ; i<length; ++i)
	{
		DistillCodeStruct ^cl = gcnew DistillCodeStruct(EnvDTE::vsCMElement::vsCMElementUnion);
		cl->Name = ToManagedString(unionMembers[i].Name.c_str());
		cl->FullName = ToManagedString(unionMembers[i].FullName.c_str());
		c->Add(cl);
	}

	return c;
}


List<System::Object ^>^ MapStruct(std::vector<DistillCodeStructWrapper> &structMembers)
{
	int length = structMembers.size();
	List<System::Object ^>^ c = gcnew List<System::Object ^>();
	for (int i = 0 ; i<length; ++i)
	{
		DistillCodeStruct ^cl = gcnew DistillCodeStruct(EnvDTE::vsCMElement::vsCMElementStruct);
		cl->Name = ToManagedString(structMembers[i].Name.c_str());
		cl->FullName = ToManagedString(structMembers[i].FullName.c_str());
		c->Add(cl);
	}
	return c;
}


DistillFileCodeModel^ CodeModelProvider::Process(String ^contents)
{
	const char *pContents = ToCString(contents);
	m_pInstance = CreateCompilerInstance();
	m_pInvocation = CreateInvocation();

	if (pContents)
		m_pInvocation->getPreprocessorOpts().addRemappedFile(filePath, llvm::MemoryBuffer::getMemBufferCopy(pContents));

	m_pInstance->setInvocation(m_pInvocation);

	std::vector<DistillCodeClassWrapper> classes;
	std::vector<DistillCodeFunctionWrapper> functions;
	std::vector<DistillCodeFunctionWrapper> methods;
	std::vector<DistillCodeVariableWrapper> variables;
	std::vector<DistillCodeStructWrapper> structs;
	std::vector<DistillCodeStructWrapper> unions;
	DistillFrontendAction action (classes, functions, methods, variables, structs, unions);
	m_pInstance->ExecuteAction (action);

	DistillFileCodeModel ^model = gcnew DistillFileCodeModel();
	List<Object ^>^ elements = gcnew List<Object ^>();

	auto classElements = MapClasses(classes);
	auto functionElements = MapFunctions (functions);
	auto methodElements = MapMethods(methods);
	auto variableElements = MapVariables(variables);
	auto structElements = MapStruct(structs);
	auto unionElements = MapUnion(unions);

	elements->AddRange(classElements);
	elements->AddRange(functionElements);
	elements->AddRange(methodElements);
	elements->AddRange(variableElements);
	elements->AddRange(structElements);
	elements->AddRange(unionElements);


	Marshal::FreeHGlobal(IntPtr((void *)pContents));
	m_pInvocation->getPreprocessorOpts().clearRemappedFiles();

	DestroyCompilerInstance(m_pInstance);
	model->CodeElements = gcnew DistillCodeElements(elements);
	return model;
}


clang::CompilerInstance* CodeModelProvider::CreateCompilerInstance()
{
	clang::CompilerInstance *pInstance = new clang::CompilerInstance();
	m_pDiagnosticClient = new StoredDiagnosticClient();
	pInstance->createDiagnostics(m_pDiagnosticClient, true);
	return pInstance;
}

clang::CompilerInvocation* CodeModelProvider::CreateInvocation()
{
	clang::CompilerInvocation *pInvocation = new clang::CompilerInvocation();
	pInvocation->getFrontendOpts().Inputs.push_back(clang::FrontendInputFile(filePath, clang::IK_CXX));
	pInvocation->getFrontendOpts().ProgramAction = clang::frontend::ParseSyntaxOnly;
	if (arch == Arch::AVR)
		pInvocation->getTargetOpts().Triple = "avr-unknown-none";
	else if (arch == Arch::ARM)
		pInvocation->getTargetOpts().Triple = "arm-unknown-linux-gnu";
	else
		pInvocation->getTargetOpts().Triple = "i386-unknown-linux-gnu";


	for each(String^ path in includePaths)
	{
		pInvocation->getHeaderSearchOpts().AddPath(ToCString(path), clang::frontend::Angled, false, true);
	}

	for each(String^ symbol in predefinedSymbols)
	{
		pInvocation->getPreprocessorOpts().addMacroDef(ToCString(symbol));
	}

	// HACK: Use preprocessor hacking to reduce named address spaces to blanks, so that they won't show up as errors
	// Really dangerous, but until Clang knows about these, it will keep flagging them as errors.
	array<String^> ^addressSpaces = { "__flash", "__flash1", "__flash2", "__flash3", "__flash4", "__flash5", "__memx" };
	for each(String ^addressSpace in addressSpaces)
	{
		pInvocation->getPreprocessorOpts().addMacroDef(ToCString(addressSpace + "="));
	}

	pInvocation->getLangOpts()->C99 = language == Language::C99 ? 1 : 0;
	pInvocation->getLangOpts()->GNUMode = 1;
	pInvocation->getLangOpts()->GNUKeywords = 1;
	pInvocation->getLangOpts()->Bool = 1;
	pInvocation->getLangOpts()->LineComment = 1;
	pInvocation->getLangOpts()->CPlusPlus = (language == Language::CPlusPlus || language == Language::CPlusPlus11) ? 1 : 0;
	pInvocation->getLangOpts()->CPlusPlus11 = language == Language::CPlusPlus11 ? 1 : 0;
	pInvocation->getLangOpts()->CXXExceptions = 1;

	if (language == Language::CPlusPlus || language == Language::CPlusPlus11)
		pInvocation->getLangOpts()->ImplicitInt = 0;

	return pInvocation;
}

void CodeModelProvider::DestroyCompilerInstance(clang::CompilerInstance *p)
{
	if (p)
		delete p;
}