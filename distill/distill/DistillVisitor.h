#pragma once 

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

namespace Distill
{
	class DistillVisitor : public clang::RecursiveASTVisitor<DistillVisitor>
	{
	public:
		bool TraverseDecl(clang::Decl *D);
		bool VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration);
	};
}
