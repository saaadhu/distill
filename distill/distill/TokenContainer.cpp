#include "Stdafx.h"
#include "TokenContainer.h"


namespace Distill
{
	List<System::Object ^>^ TokenContainer::MapMethods()
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

	List<System::Object ^>^ TokenContainer::MapVariables()
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


	List<System::Object ^>^ TokenContainer::MapUnion()
	{
		int length = unions.size();
		List<System::Object ^>^ c = gcnew List<System::Object ^>();
		for (int i = 0 ; i<length; ++i)
		{
			DistillCodeStruct ^cl = gcnew DistillCodeStruct(EnvDTE::vsCMElement::vsCMElementUnion);
			cl->Name = ToManagedString(unions[i].Name.c_str());
			cl->FullName = ToManagedString(unions[i].FullName.c_str());
			c->Add(cl);
		}

		return c;
	}


	List<System::Object ^>^ TokenContainer::MapStruct()
	{
		int length = structs.size();
		List<System::Object ^>^ c = gcnew List<System::Object ^>();
		for (int i = 0 ; i<length; ++i)
		{
			DistillCodeStruct ^cl = gcnew DistillCodeStruct(EnvDTE::vsCMElement::vsCMElementStruct);
			cl->Name = ToManagedString(structs[i].Name.c_str());
			cl->FullName = ToManagedString(structs[i].FullName.c_str());
			c->Add(cl);
		}
		return c;
	}

	List<System::Object ^>^ TokenContainer::MapClasses()
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

	List<System::Object ^>^ TokenContainer::MapFunctions()
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

	DistillFileCodeModel^ TokenContainer::CodeModel()
	{

		DistillFileCodeModel ^model = gcnew DistillFileCodeModel();
		List<Object ^>^ elements = gcnew List<Object ^>();

		auto classElements = MapClasses();
		auto functionElements = MapFunctions();
		auto methodElements = MapMethods();
		auto variableElements = MapVariables();
		auto structElements = MapStruct();
		auto unionElements = MapUnion();

		elements->AddRange(classElements);
		elements->AddRange(functionElements);
		elements->AddRange(methodElements);
		elements->AddRange(variableElements);
		elements->AddRange(structElements);
		elements->AddRange(unionElements);
		model->CodeElements = gcnew DistillCodeElements(elements);
		return model;
	}
}