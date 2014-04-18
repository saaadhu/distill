#pragma once 

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "TokenContainer.h"
#include <vector>

namespace Distill
{
	class DistillVisitor : public clang::RecursiveASTVisitor<DistillVisitor>
	{
	public:
		DistillVisitor(TokenContainer &container) : m_container(container){}

		bool TraverseDecl(clang::Decl *D);
		bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration);
		bool VisitVarDecl(clang::VarDecl *Declaration);
		bool VisitFieldDecl(clang::FieldDecl *Declaration);
		bool VisitFunctionDecl(clang::FunctionDecl *Declaration);
		bool VisitCXXMethodDecl(clang::FunctionDecl *Declaration);

	private:
		TokenContainer &m_container;
	};
}