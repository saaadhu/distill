#pragma once

#include "clang\Frontend\FrontendAction.h"
#include "clang\Frontend\FrontendActions.h"
#include "DistillASTConsumer.h"
#include "TokenContainer.h"


namespace Distill
{
	class DistillFrontendAction : public clang::ASTFrontendAction
	{
	public:
		DistillFrontendAction(TokenContainer& container) : m_container(container) {}

		virtual clang::ASTConsumer *CreateASTConsumer(
			clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
				return new DistillASTConsumer(m_container);
		}
	private:
		TokenContainer &m_container;

	};
}