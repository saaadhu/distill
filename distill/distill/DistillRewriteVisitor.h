#pragma once 

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Rewrite/Frontend/Rewriters.h"
#include <string>

namespace Distill
{
	class DistillRewriteVisitor : public clang::RecursiveASTVisitor<DistillRewriteVisitor>
	{
	public:

		DistillRewriteVisitor(const std::string &oldName, const std::string &newName) : m_oldName(oldName), m_newName(newName) {}

		bool TraverseDecl(clang::Decl *D);
		bool VisitFunctionDecl(clang::FunctionDecl *Declaration);
		bool VisitCXXMethodDecl(clang::FunctionDecl *Declaration);

		clang::Rewriter m_rewriter;
		std::string GetMutatedText(clang::FileID id);
	private:
		const std::string m_oldName;
		const std::string m_newName;
	};
}
