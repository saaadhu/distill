#pragma once

#include "clang\AST\ASTConsumer.h"
#include "clang\AST\ASTContext.h"
#include "DistillVisitor.h"
#include "DistillCodeClassWrapper.h"
#include "DistillCodeFunctionWrapper.h"
#include "DistillCodeVariableWrapper.h"
#include "DistillCodeStructWrapper.h"
#include <vector>

namespace Distill
{
	class DistillASTConsumer : public clang::ASTConsumer 
	{
	public:
		DistillASTConsumer(std::vector<DistillCodeClassWrapper>& classes,
			std::vector<DistillCodeFunctionWrapper>& functions,
			std::vector<DistillCodeFunctionWrapper>&   methods,
			std::vector<DistillCodeVariableWrapper>& variables,
			std::vector<DistillCodeStructWrapper>& structs
			) : m_Visitor(classes, functions, methods, variables, structs){}

		virtual void HandleTranslationUnit(clang::ASTContext &Context) {
			m_Visitor.TraverseDecl(Context.getTranslationUnitDecl());
		}
		
	private:
		DistillVisitor m_Visitor;
	};
}

