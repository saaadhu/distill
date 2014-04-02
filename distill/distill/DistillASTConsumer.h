#pragma once

#include "clang\AST\ASTConsumer.h"
#include "clang\AST\ASTContext.h"
#include "DistillVisitor.h"

namespace Distill
{
	class DistillASTConsumer : public clang::ASTConsumer 
	{
	public:
		virtual void HandleTranslationUnit(clang::ASTContext &Context) {
			DistillVisitor p;
			p.TraverseDecl(Context.getTranslationUnitDecl());
		}
	private:
	};
}

