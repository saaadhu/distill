// distill.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace Distill {

	public enum Arch
	{
		AVR,
		AVR32,
		ARM
	};

	public enum Language {
		C,
		CPlusPlus,
		C99,
		CPlusPlus11
	};

	public ref class CodeModelProvider
	{
	public:
		CodeModelProvider (String ^fileContents, List<String ^> ^predefinedSymbols, List<String ^> ^includePaths, Language language, Arch arch)
		{
		}
	};
}
