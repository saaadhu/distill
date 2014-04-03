using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using EnvDTE;

namespace Distill.Types
{
    public class DistillCodeFunction : CodeFunction, CodeElement
    {
        public TextPoint GetStartPoint(vsCMPart Part = vsCMPart.vsCMPartWholeWithAttributes)
        {
            throw new NotImplementedException();
        }

        public TextPoint GetEndPoint(vsCMPart Part = vsCMPart.vsCMPartWholeWithAttributes)
        {
            throw new NotImplementedException();
        }

        public CodeParameter AddParameter(string Name, object Type, object Position)
        {
            throw new NotImplementedException();
        }

        public CodeAttribute AddAttribute(string Name, string Value, object Position)
        {
            throw new NotImplementedException();
        }

        public void RemoveParameter(object Element)
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

        public string Name { get; set; }

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

        public vsCMFunction FunctionKind
        {
            get { throw new NotImplementedException(); }
        }

        public string get_Prototype(int Flags = 0)
        {
            throw new NotImplementedException();
        }

        public CodeTypeRef Type
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public CodeElements Parameters
        {
            get { throw new NotImplementedException(); }
        }

        public vsCMAccess Access
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public bool IsOverloaded
        {
            get { throw new NotImplementedException(); }
        }

        public bool IsShared
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public bool MustImplement
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }

        public CodeElements Overloads
        {
            get { throw new NotImplementedException(); }
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

        public bool CanOverride
        {
            get { throw new NotImplementedException(); }
            set { throw new NotImplementedException(); }
        }
    }
}
