using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using EnvDTE;

namespace Distill.Types
{
    public class DistillCodeClass : EnvDTE.CodeClass, EnvDTE.CodeElement
    {

        public TextPoint GetStartPoint(vsCMPart Part = vsCMPart.vsCMPartWholeWithAttributes)
        {
            throw new NotImplementedException();
        }

        public TextPoint GetEndPoint(vsCMPart Part = vsCMPart.vsCMPartWholeWithAttributes)
        {
            throw new NotImplementedException();
        }

        public CodeElement AddBase(object Base, object Position)
        {
            throw new NotImplementedException();
        }

        public CodeAttribute AddAttribute(string Name, string Value, object Position)
        {
            throw new NotImplementedException();
        }

        public void RemoveBase(object Element)
        {
            throw new NotImplementedException();
        }

        public void RemoveMember(object Element)
        {
            throw new NotImplementedException();
        }

        public CodeInterface AddImplementedInterface(object Base, object Position)
        {
            throw new NotImplementedException();
        }

        public CodeFunction AddFunction(string Name, vsCMFunction Kind, object Type, object Position, vsCMAccess Access, object Location)
        {
            throw new NotImplementedException();
        }

        public CodeVariable AddVariable(string Name, object Type, object Position, vsCMAccess Access, object Location)
        {
            throw new NotImplementedException();
        }

        public CodeProperty AddProperty(string GetterName, string PutterName, object Type, object Position, vsCMAccess Access, object Location)
        {
            throw new NotImplementedException();
        }

        public CodeClass AddClass(string Name, object Position, object Bases, object ImplementedInterfaces, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeStruct AddStruct(string Name, object Position, object Bases, object ImplementedInterfaces, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeEnum AddEnum(string Name, object Position, object Bases, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeDelegate AddDelegate(string Name, object Type, object Position, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public void RemoveInterface(object Element)
        {
            throw new NotImplementedException();
        }

        public DTE DTE
        {
            get { throw new NotImplementedException(); }
        }

        public CodeElements Collection
        {
            get { throw new NotImplementedException(); }
        }

        public string Name
        {
            get { return name; }
            set
            {
                OriginalName = name; name = value; 
            }
        }

        public string OriginalName { get; set; }

        public string FullName { get; set; }

        public ProjectItem ProjectItem
        {
            get { throw new NotImplementedException(); }
        }

        public vsCMElement Kind
        {
            get { throw new NotImplementedException(); }
        }

        public bool IsCodeType
        {
            get { throw new NotImplementedException(); }
        }

        public vsCMInfoLocation InfoLocation
        {
            get { throw new NotImplementedException(); }
        }

        public CodeElements Children
        {
            get { throw new NotImplementedException(); }
        }

        public string Language
        {
            get { throw new NotImplementedException(); }
        }

        public TextPoint StartPoint
        {
            get { throw new NotImplementedException(); }
        }

        public TextPoint EndPoint
        {
            get { throw new NotImplementedException(); }
        }

        public object ExtenderNames
        {
            get { throw new NotImplementedException(); }
        }

        public object get_Extender(string ExtenderName)
        {
            throw new NotImplementedException();
        }

        public string ExtenderCATID
        {
            get { throw new NotImplementedException(); }
        }

        public object Parent
        {
            get { throw new NotImplementedException(); }
        }

        public CodeNamespace Namespace
        {
            get { throw new NotImplementedException(); }
        }

        public CodeElements Bases
        {
            get { throw new NotImplementedException(); }
        }

        public CodeElements Members
        {
            get { throw new NotImplementedException(); }
        }

        public vsCMAccess Access
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public CodeElements Attributes
        {
            get { throw new NotImplementedException(); }
        }

        public string DocComment
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public string Comment
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public bool get_IsDerivedFrom(string FullName)
        {
            throw new NotImplementedException();
        }

        public CodeElements DerivedTypes
        {
            get { throw new NotImplementedException(); }
        }

        public CodeElements ImplementedInterfaces
        {
            get { throw new NotImplementedException(); }
        }

        public bool IsAbstract
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        private string name;


        dynamic CodeElement.ExtenderNames
        {
            get { throw new NotImplementedException(); }
        }
    }
}
