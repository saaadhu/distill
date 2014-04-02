#pragma once 

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "DistillCodeClassWrapper.h"
#include <vector>

namespace Distill
{
	class DistillVisitor : public clang::RecursiveASTVisitor<DistillVisitor>
	{
	public:

		DistillVisitor(std::vector<DistillCodeClassWrapper>& classes) : m_classes(classes) {}

		bool TraverseDecl(clang::Decl *D);
		bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration);

	private:
		std::vector<DistillCodeClassWrapper> &m_classes;
	};
}
