using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Distill.Types
{
  public class DistillCodeStruct : EnvDTE.CodeStruct, EnvDTE.CodeElement
  {

    EnvDTE.vsCMElement kind;
    public DistillCodeStruct(EnvDTE.vsCMElement kind)
    {
      this.kind = kind;
      
    }


    public EnvDTE.CodeElements Children
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.CodeElements Collection
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.DTE DTE
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.TextPoint EndPoint
    {
      get { throw new NotImplementedException(); }
    }

    public string ExtenderCATID
    {
      get { throw new NotImplementedException(); }
    }

    public dynamic ExtenderNames
    {
      get { throw new NotImplementedException(); }
    }

    public string FullName
    {
      get;
      set;
    }

    public EnvDTE.TextPoint GetEndPoint(EnvDTE.vsCMPart Part = EnvDTE.vsCMPart.vsCMPartWholeWithAttributes)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.TextPoint GetStartPoint(EnvDTE.vsCMPart Part = EnvDTE.vsCMPart.vsCMPartWholeWithAttributes)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.vsCMInfoLocation InfoLocation
    {
      get { throw new NotImplementedException(); }
    }

    public bool IsCodeType
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.vsCMElement Kind
    {
      get { return kind; }
    }

    public string Language
    {
      get { throw new NotImplementedException(); }
    }

    public string Name
    {
      get;
      set;
    }

    public EnvDTE.ProjectItem ProjectItem
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.TextPoint StartPoint
    {
      get { throw new NotImplementedException(); }
    }

    public dynamic get_Extender(string ExtenderName)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.vsCMAccess Access
    {
      get
      {
        throw new NotImplementedException();
      }
      set
      {
        throw new NotImplementedException();
      }
    }

    public EnvDTE.CodeAttribute AddAttribute(string Name, string Value, object Position)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeElement AddBase(object Base, object Position)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeClass AddClass(string Name, object Position, object Bases, object ImplementedInterfaces, EnvDTE.vsCMAccess Access )
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeDelegate AddDelegate(string Name, object Type, object Position, EnvDTE.vsCMAccess Access = EnvDTE.vsCMAccess.vsCMAccessDefault)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeEnum AddEnum(string Name, object Position, object Bases, EnvDTE.vsCMAccess Access = EnvDTE.vsCMAccess.vsCMAccessDefault)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeFunction AddFunction(string Name, EnvDTE.vsCMFunction Kind, object Type, object Position, EnvDTE.vsCMAccess Access , object Location)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeInterface AddImplementedInterface(object Base, object Position)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeProperty AddProperty(string GetterName, string PutterName, object Type, object Position, EnvDTE.vsCMAccess Access , object Location)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeStruct AddStruct(string Name, object Position, object Bases, object ImplementedInterfaces, EnvDTE.vsCMAccess Access = EnvDTE.vsCMAccess.vsCMAccessDefault)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeVariable AddVariable(string Name, object Type, object Position, EnvDTE.vsCMAccess Access , object Location)
    {
      throw new NotImplementedException();
    }

    public EnvDTE.CodeElements Attributes
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.CodeElements Bases
    {
      get { throw new NotImplementedException(); }
    }

    public string Comment
    {
      get
      {
        throw new NotImplementedException();
      }
      set
      {
        throw new NotImplementedException();
      }
    }

    public EnvDTE.CodeElements DerivedTypes
    {
      get { throw new NotImplementedException(); }
    }

    public string DocComment
    {
      get
      {
        throw new NotImplementedException();
      }
      set
      {
        throw new NotImplementedException();
      }
    }

    public EnvDTE.CodeElements ImplementedInterfaces
    {
      get { throw new NotImplementedException(); }
    }

    public bool IsAbstract
    {
      get
      {
        throw new NotImplementedException();
      }
      set
      {
        throw new NotImplementedException();
      }
    }

    public EnvDTE.CodeElements Members
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.CodeNamespace Namespace
    {
      get { throw new NotImplementedException(); }
    }

    public dynamic Parent
    {
      get { throw new NotImplementedException(); }
    }

    public void RemoveBase(object Element)
    {
      throw new NotImplementedException();
    }

    public void RemoveInterface(object Element)
    {
      throw new NotImplementedException();
    }

    public void RemoveMember(object Element)
    {
      throw new NotImplementedException();
    }

    public bool get_IsDerivedFrom(string FullName)
    {
      throw new NotImplementedException();
    }
  }
}
