#pragma once 

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "DistillCodeClassWrapper.h"
#include "DistillCodeFunctionWrapper.h"
#include "DistillCodeVariableWrapper.h"
#include "DistillCodeStructWrapper.h"
#include <vector>

namespace Distill
{
	class DistillVisitor : public clang::RecursiveASTVisitor<DistillVisitor>
	{
	public:

		DistillVisitor(std::vector<DistillCodeClassWrapper>& classes,
			std::vector<DistillCodeFunctionWrapper>& functions,
			std::vector<DistillCodeFunctionWrapper>& methods,
			std::vector<DistillCodeVariableWrapper>& variables,
			std::vector<DistillCodeStructWrapper>& structs
			) : m_classes(classes), m_functions(functions), m_methods(methods), m_variables(variables), m_struct(structs) {}

		bool TraverseDecl(clang::Decl *D);
		bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration);
		bool VisitFunctionDecl(clang::FunctionDecl *Declaration);
		bool VisitCXXMethodDecl(clang::FunctionDecl *Declaration);

	private:
		std::vector<DistillCodeClassWrapper> &m_classes;
		std::vector<DistillCodeFunctionWrapper> &m_functions;
		std::vector<DistillCodeFunctionWrapper> &m_methods;
		std::vector<DistillCodeVariableWrapper> &m_variables;
		std::vector<DistillCodeStructWrapper> &m_struct;
	};
}
