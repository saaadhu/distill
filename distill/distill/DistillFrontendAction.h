#pragma once

#include "clang\Frontend\FrontendAction.h"
#include "clang\Frontend\FrontendActions.h"
#include "DistillASTConsumer.h"
#include "DistillCodeClassWrapper.h"


namespace Distill
{
	class DistillFrontendAction : public clang::ASTFrontendAction
	{
	public:
		DistillFrontendAction(std::vector<DistillCodeClassWrapper>& classes) : m_classes(classes) {}

		virtual clang::ASTConsumer *CreateASTConsumer(
			clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
				return new DistillASTConsumer(m_classes);
		}
	private:
		std::vector<DistillCodeClassWrapper> &m_classes;
	};
}