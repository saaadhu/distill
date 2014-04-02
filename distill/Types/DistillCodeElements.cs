using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using EnvDTE;

namespace Distill.Types
{
    public class DistillCodeElements : CodeElements
    {
        public DistillCodeElements(List<object> objects )
        {
            this.objects = objects;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return objects.GetEnumerator();
        }

        public CodeElement Item(object index)
        {
            return (CodeElement) objects[(int) index];
        }

        public void Reserved1(object Element)
        {
            throw new NotImplementedException();
        }

        public bool CreateUniqueID(string Prefix, ref string NewName)
        {
            return true;
        }

        public DTE DTE
        {
            get { throw new NotImplementedException(); }
        }

        public object Parent
        {
            get { throw new NotImplementedException(); }
        }

        public int Count
        {
            get { return objects.Count(); }
        }

        IEnumerator CodeElements.GetEnumerator()
        {
            return objects.GetEnumerator();
        }

        List<object>  objects = new List<object>();
    }
}
