#include "StringUtilities.h"
#include "DistillCodeClassWrapper.h"

namespace Distill
{
public ref class DistillCodeClass : public EnvDTE::CodeClass
{
public:
	DistillCodeClass (DistillCodeClassWrapper &dccw)
	{
		name = ToManagedString(dccw.Name.c_str());
	}

	virtual property EnvDTE::DTE^ DTE
	{
		EnvDTE::DTE^ get() { return dte; }
		void set(EnvDTE::DTE ^d) { dte = d; }
	}

	virtual property EnvDTE::CodeElements^ Collection
	{
		EnvDTE::CodeElements^ get() { return children; }
		void set(EnvDTE::CodeElements ^d) { children = d; }
	}

	virtual property EnvDTE::CodeElements^ Children
	{
		EnvDTE::CodeElements^ get() { return children; }
	}

	virtual property EnvDTE::CodeElements^ Members
	{
		EnvDTE::CodeElements^ get() { return children; }
	}

	/*
	virtual property System::String^ default[int]
	{
		System::String^ get() { return def; }
		void set(System::String ^d) { def = d; }
	}
	*/
	property String^ Name {
		String ^ get() { return name; }
		void set(String ^x) { name = x; }
	}


	virtual property String^ FullName {
		String ^ get()
		{
			return name;
		}
	}

	virtual property EnvDTE::ProjectItem^ ProjectItem
	{
		EnvDTE::ProjectItem^ get() {  return item; }
		void set (EnvDTE::ProjectItem ^i) { item = i; }
	}

	virtual property EnvDTE::vsCMElement Kind
	{
		EnvDTE::vsCMElement get() {  return kind; }
		void set (EnvDTE::vsCMElement i) { kind = i; }
	}

	virtual property bool IsCodeType
	{
		bool get() { return true; }
	}

	virtual property EnvDTE::vsCMInfoLocation InfoLocation
	{
		EnvDTE::vsCMInfoLocation get() { return location; }
	}

	virtual property String^ Language {
		String ^ get()
		{
			return "C++";
		}
	}

	virtual property EnvDTE::TextPoint ^StartPoint {
		EnvDTE::TextPoint^ get() { return start; }
		void set(EnvDTE::TextPoint ^v) { start = v; }
	}

	virtual property EnvDTE::TextPoint ^EndPoint {
		EnvDTE::TextPoint^ get() { return end; }
		void set(EnvDTE::TextPoint ^v) { end = v; }
	}

	virtual property System::Object^ ExtenderNames {
		System::Object^ get() { return nullptr; }
	}

	virtual property System::Object^ Extender[String ^] {
		System::Object^ get(System::String ^x) { return nullptr; }
	}

	virtual property System::Object^ Parent {
		System::Object^ get() { return parent; }
	}

	virtual property String^ ExtenderCATID {
		String ^ get()
		{
			return "";
		}
	}

	virtual property String^ DocComment {
		String ^ get() { return ""; }
		void set (String ^s) {}
	}

	virtual property String^ Comment {
		String ^ get() { return ""; }
		void set (String ^s) {}
	}

	virtual property EnvDTE::CodeNamespace^ Namespace
	{
		EnvDTE::CodeNamespace^ get() { return _namespace; }
	}

	virtual property EnvDTE::CodeElements^ Bases
	{
		EnvDTE::CodeElements^ get() { return nullptr; }
	}

	virtual property EnvDTE::CodeElements^ Attributes
	{
		EnvDTE::CodeElements^ get() { return attributes; }
	}

	virtual property EnvDTE::vsCMAccess Access
	{
		EnvDTE::vsCMAccess get() { return access; }
		void set (EnvDTE::vsCMAccess a) { access = a;}
	}

	virtual property bool IsDerivedFrom[String ^]
	{
		bool get(System::String ^) { return false; }
	}

	virtual property EnvDTE::CodeElements^ DerivedTypes
	{
		EnvDTE::CodeElements^ get() { return derivedTypes; }
	}

	virtual property EnvDTE::CodeElements^ ImplementedInterfaces
	{
		EnvDTE::CodeElements^ get() { return implementedInterfaces; }
	}

	virtual property bool IsAbstract
	{
		bool get() { return _abstract; }
		void set(bool value) { _abstract = value; }
	}

	virtual EnvDTE::TextPoint ^GetStartPoint(EnvDTE::vsCMPart) { return nullptr; }
	virtual EnvDTE::TextPoint ^GetEndPoint(EnvDTE::vsCMPart) { return nullptr; }
	virtual EnvDTE::CodeElement ^AddBase(System::Object ^a, System::Object ^b) { return nullptr; }
	virtual EnvDTE::CodeAttribute ^AddAttribute(System::String ^a, System::String ^b, System::Object ^c) { return nullptr; }
	virtual void RemoveBase(System::Object ^a) { }
	virtual void RemoveMember(System::Object ^a) { }
	virtual EnvDTE::CodeInterface ^AddImplementedInterface(System::Object ^a, System::Object ^b) { return nullptr; }
	virtual EnvDTE::CodeFunction ^AddFunction(System::String ^a, EnvDTE::vsCMFunction b, System::Object ^c, System::Object ^d, EnvDTE::vsCMAccess e, System::Object ^f) { return nullptr; }
	virtual EnvDTE::CodeVariable ^AddVariable(System::String ^a, System::Object ^c, System::Object ^d, EnvDTE::vsCMAccess e, System::Object ^f) { return nullptr; }
	virtual EnvDTE::CodeProperty ^AddProperty(System::String ^ x, System::String ^a, System::Object ^c, System::Object ^d, EnvDTE::vsCMAccess e, System::Object ^f) { return nullptr; }
	virtual EnvDTE::CodeClass ^AddClass(System::String ^a, System::Object ^c, System::Object ^d, System::Object ^f, EnvDTE::vsCMAccess v) { return nullptr; }
	virtual EnvDTE::CodeStruct ^AddStruct(System::String ^a, System::Object ^c, System::Object ^d, System::Object ^f, EnvDTE::vsCMAccess m) { return nullptr; }
	virtual EnvDTE::CodeEnum ^AddEnum(System::String ^a, System::Object ^c, System::Object ^d, EnvDTE::vsCMAccess m) { return nullptr; }
	virtual EnvDTE::CodeDelegate ^AddDelegate(System::String ^a, System::Object ^c, System::Object ^d, EnvDTE::vsCMAccess m) { return nullptr; }
	virtual void RemoveInterface(System::Object ^){}


private:
	String ^name;
	EnvDTE::DTE^ dte;
	EnvDTE::ProjectItem^ item;
	EnvDTE::vsCMElement kind;
	EnvDTE::CodeElements^ children;
	EnvDTE::TextPoint^ start;
	EnvDTE::TextPoint^ end;
	EnvDTE::vsCMInfoLocation location;
	System::Object ^parent;
	EnvDTE::CodeNamespace ^_namespace;
	EnvDTE::vsCMAccess access;
	String ^def;
	EnvDTE::CodeElements ^attributes;
	EnvDTE::CodeElements ^derivedTypes;
	EnvDTE::CodeElements ^implementedInterfaces;
	bool _abstract;
};
}