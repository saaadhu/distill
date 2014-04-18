#pragma once

#include "StringUtilities.h"
#include "DistillCodeClassWrapper.h"
#include "DistillCodeFunctionWrapper.h"
#include "DistillCodeVariableWrapper.h"
#include "DistillCodeStructWrapper.h"
#include <vector>


using namespace Distill;
using namespace Distill::Types;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

namespace Distill
{
	class TokenContainer
	{
	public:

		List<System::Object ^>^ MapMethods();
		List<System::Object ^>^ MapVariables();
		List<System::Object ^>^ MapUnion();
		List<System::Object ^>^ MapStruct();
		List<System::Object ^>^ MapClasses();
		List<System::Object ^>^ MapFunctions();
		DistillFileCodeModel^ CodeModel();

		std::vector<DistillCodeClassWrapper> classes;
		std::vector<DistillCodeFunctionWrapper> functions;
		std::vector<DistillCodeFunctionWrapper> methods;
		std::vector<DistillCodeVariableWrapper> variables;
		std::vector<DistillCodeStructWrapper> structs;
		std::vector<DistillCodeStructWrapper> unions;

	};
}