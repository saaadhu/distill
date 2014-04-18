#pragma once

#include "clang\AST\ASTConsumer.h"
#include "clang\AST\ASTContext.h"
#include "DistillVisitor.h"
#include <vector>

namespace Distill
{
	class DistillASTConsumer : public clang::ASTConsumer 
	{
	public:
		DistillASTConsumer(TokenContainer &container) : m_Visitor(container){}

		virtual void HandleTranslationUnit(clang::ASTContext& Context)
		{
			m_Visitor.TraverseDecl(Context.getTranslationUnitDecl());
		}
		
	private:
		DistillVisitor m_Visitor;
	};
}

