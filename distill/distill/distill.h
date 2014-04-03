// distill.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace Distill::Types;

namespace clang
{
	class CompilerInstance;
	class CompilerInvocation;
}

class StoredDiagnosticClient;

namespace Distill {

	public enum class Arch
	{
		AVR,
		AVR32,
		ARM
	};

	public enum class Language {
		C,
		CPlusPlus,
		C99,
		CPlusPlus11
	};

	public ref class CodeModelProvider
	{
	public:
		CodeModelProvider (String ^file, List<String ^> ^pSymbols, List<String ^> ^iPaths, Language lang, Arch a);
		Distill::Types::DistillFileCodeModel ^Process(String^ contents);
		String^ RenameFunction(String^ oldName, String ^newName, String ^contents);

	private:

		clang::CompilerInstance* CreateCompilerInstance();
		void DestroyCompilerInstance (clang::CompilerInstance *);

		clang::CompilerInvocation* CreateInvocation();

		clang::CompilerInvocation* m_pInvocation;
		clang::CompilerInstance *m_pInstance;
		StoredDiagnosticClient *m_pDiagnosticClient;
		const char *filePath;
		List<String ^> ^includePaths;
		List<String ^> ^predefinedSymbols;
		Language language;
		Arch arch;
	};
}
