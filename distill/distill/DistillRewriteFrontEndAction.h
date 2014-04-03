#pragma once

#include "clang\Frontend\FrontendAction.h"
#include "clang\Frontend\FrontendActions.h"
#include "DistillRewriteASTConsumer.h"
#include "clang/Rewrite/Core/Rewriter.h"

namespace Distill
{
	class DistillRewriteFrontendAction : public clang::ASTFrontendAction
	{
	public:
		DistillRewriteFrontendAction(const std::string &oldName, const std::string &name, std::string &modifiedText) : originalName(oldName), newName(name), mutatedText(modifiedText) {}

		virtual clang::ASTConsumer *CreateASTConsumer(
			clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
				return new DistillRewriteASTConsumer(originalName, newName, mutatedText);
		}
	private:
		const std::string originalName;
		const std::string newName;
		std::string &mutatedText;
	};
}