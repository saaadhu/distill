#pragma once

#include "clang\Frontend\FrontendAction.h"
#include "clang\Frontend\FrontendActions.h"
#include "DistillASTConsumer.h"

namespace Distill
{
	class DistillFrontendAction : public clang::ASTFrontendAction
	{
	public:
		
		virtual clang::ASTConsumer *CreateASTConsumer(
			clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
				return new DistillASTConsumer;
		}
		
	};
}