#pragma once

#include "clang\AST\ASTConsumer.h"
#include "clang\AST\ASTContext.h"
#include "DistillVisitor.h"
#include "DistillCodeClassWrapper.h"
#include <vector>

namespace clang
{
	class CXXRecordDecl;
}

namespace Distill
{
	class DistillASTConsumer : public clang::ASTConsumer 
	{
	public:
		DistillASTConsumer(std::vector<DistillCodeClassWrapper>& classes) : m_Visitor(classes){}

		virtual void HandleTranslationUnit(clang::ASTContext &Context) {
			m_Visitor.TraverseDecl(Context.getTranslationUnitDecl());
		}
		
	private:
		DistillVisitor m_Visitor;
	};
}

