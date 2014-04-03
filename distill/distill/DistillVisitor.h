#pragma once 

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "DistillCodeClassWrapper.h"
#include "DistillCodeFunctionWrapper.h"
#include <vector>

namespace Distill
{
	class DistillVisitor : public clang::RecursiveASTVisitor<DistillVisitor>
	{
	public:

		DistillVisitor(std::vector<DistillCodeClassWrapper>& classes,
			std::vector<DistillCodeFunctionWrapper>& functions
			) : m_classes(classes), m_functions(functions) {}

		bool TraverseDecl(clang::Decl *D);
		bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration);
		bool VisitFunctionDecl(clang::FunctionDecl *Declaration);
		bool VisitCXXMethodDecl(clang::FunctionDecl *Declaration);

	private:
		std::vector<DistillCodeClassWrapper> &m_classes;
		std::vector<DistillCodeFunctionWrapper> &m_functions;
	};
}
