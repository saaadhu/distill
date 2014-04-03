#pragma once

#include "clang\AST\ASTConsumer.h"
#include "clang\AST\ASTContext.h"
#include "DistillRewriteVisitor.h"
#include <vector>
#include "clang/Rewrite/Core/Rewriter.h"

namespace Distill
{
	class DistillRewriteASTConsumer : public clang::ASTConsumer 
	{
	public:
		DistillRewriteASTConsumer(const std::string &originalName, const std::string &newName, std::string &modifiedText):
		  m_Visitor (originalName, newName), mutatedString(modifiedText) {}

		virtual void HandleTranslationUnit(clang::ASTContext &Context) {
			m_Visitor.m_rewriter = clang::Rewriter(Context.getSourceManager(), Context.getLangOpts());
			m_Visitor.TraverseDecl(Context.getTranslationUnitDecl());
			mutatedString = m_Visitor.GetMutatedText(Context.getSourceManager().getMainFileID());
		}

	private:
		DistillRewriteVisitor m_Visitor;
		std::string &mutatedString;
	};
}
