using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Distill.Types
{
  public class DistillCodeVariable : EnvDTE.CodeVariable, EnvDTE.CodeElement
  {
    public DistillCodeVariable()
    {

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
      get { return EnvDTE.vsCMElement.vsCMElementVariable; }
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

    public EnvDTE.CodeElements Attributes
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

    public dynamic InitExpression
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

    public bool IsConstant
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

    public bool IsShared
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

    public dynamic Parent
    {
      get { throw new NotImplementedException(); }
    }

    public EnvDTE.CodeTypeRef Type
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

    public string get_Prototype(int Flags = 0)
    {
      throw new NotImplementedException();
    }
  }
}
