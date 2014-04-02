using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Distill.Tests
{
    [TestClass]
    public class SmokeTest
    {
        [TestMethod]
        public void Foo()
        {
            var provider = new CodeModelProvider(@"E:\Test.cpp", new List<string>(), new List<string>(),
                                                 Language.CPlusPlus, Arch.AVR32);
            provider.Process(@"class C{};");
        }
    }
}
