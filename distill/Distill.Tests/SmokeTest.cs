using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using Distill.Types;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Distill.Tests
{
    [TestClass]
    public class SmokeTest
    {
        [TestMethod]
        public void CppClass_GetName_ReturnsName()
        {
            var model = provider.Process(@"class MyClass{};");
            Assert.AreEqual(1, model.CodeElements.Count);
            Assert.AreEqual("MyClass", ((DistillCodeClass) model.CodeElements.Item(0)).Name);
        }

        [TestMethod]
        public void CppClass_GetFullName_ReturnsFQName()
        {
            var model = provider.Process(@"namespace Foo { class MyClass{}; }");
            Assert.AreEqual(1, model.CodeElements.Count);
            Assert.AreEqual("Foo::MyClass", ((DistillCodeClass) model.CodeElements.Item(0)).FullName);
        }

        [TestMethod]
        public void CppFunction_GetNameAndFullName_ReturnsNameAndFQName()
        {
            var model = provider.Process(@"namespace Foo { void Crap() {} }");
            Assert.AreEqual(1, model.CodeElements.Count);
            Assert.AreEqual("Crap", ((DistillCodeFunction) model.CodeElements.Item(0)).Name);
            Assert.AreEqual("Foo::Crap", ((DistillCodeFunction) model.CodeElements.Item(0)).FullName);
        }

        private CodeModelProvider provider;

        [TestInitialize]
        public void Setup()
        {
            provider = new CodeModelProvider(@"E:\Test.cpp", new List<string>(), new List<string>(),
                                                 Language.CPlusPlus, Arch.AVR32);
        }



    }
}
