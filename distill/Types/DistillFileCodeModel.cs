using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using EnvDTE;

namespace Distill.Types
{
    public class DistillFileCodeModel : FileCodeModel
    {
        public CodeElement CodeElementFromPoint(TextPoint Point, vsCMElement Scope)
        {
            throw new NotImplementedException();
        }

        public CodeNamespace AddNamespace(string Name, object Position)
        {
            throw new NotImplementedException();
        }

        public CodeClass AddClass(string Name, object Position, object Bases, object ImplementedInterfaces, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeInterface AddInterface(string Name, object Position, object Bases, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeFunction AddFunction(string Name, vsCMFunction Kind, object Type, object Position, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeVariable AddVariable(string Name, object Type, object Position, vsCMAccess Access = vsCMAccess.vsCMAccessDefault)
        {
            throw new NotImplementedException();
        }

        public CodeAttribute AddAttribute(string Name, string Value, object Position)
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

        public void Remove(object Element)
        {
            throw new NotImplementedException();
        }

        public DTE DTE
        {
            get { throw new NotImplementedException(); }
        }

        public ProjectItem Parent
        {
            get { throw new NotImplementedException(); }
        }

        public string Language
        {
            get { throw new NotImplementedException(); }
        }

        public CodeElements CodeElements
        {
            get { return codeElements; }
            set { codeElements = (DistillCodeElements)value;}
        }

        private DistillCodeElements codeElements;
    }
}
