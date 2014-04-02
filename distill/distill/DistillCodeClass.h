#include "StringUtilities.h"
#include "DistillCodeClassWrapper.h"

namespace Distill
{
public ref class DistillCodeClass
{
public:
	DistillCodeClass (DistillCodeClassWrapper &dccw)
	{
		name = ToManagedString(dccw.Name.c_str());
	}

	property String^ Name {
		String ^ get()
		{
			return name;
		}
	}

private:
	String ^name;
};
}