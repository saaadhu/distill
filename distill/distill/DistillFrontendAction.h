#pragma once

#include "clang\Frontend\FrontendAction.h"
#include "clang\Frontend\FrontendActions.h"
#include "DistillASTConsumer.h"
#include "DistillCodeClassWrapper.h"
#include "DistillCodeVariableWrapper.h"
#include "DistillCodeFunctionWrapper.h"
#include "DistillCodeStructWrapper.h"


namespace Distill
{
	class DistillFrontendAction : public clang::ASTFrontendAction
	{
	public:
		DistillFrontendAction(std::vector<DistillCodeClassWrapper>& classes,
			std::vector<DistillCodeFunctionWrapper>& functions, 
			std::vector<DistillCodeFunctionWrapper>& methods, 
			std::vector<DistillCodeVariableWrapper>& variables,
			std::vector<DistillCodeStructWrapper>& structs
			) : m_classes(classes), m_functions(functions), m_methods(methods), m_variables(variables), m_struct(structs){}

		virtual clang::ASTConsumer *CreateASTConsumer(
			clang::CompilerInstance &Compiler, llvm::StringRef InFile) {
				return new DistillASTConsumer(m_classes, m_functions, m_methods, m_variables, m_struct);
		}
	private:
		std::vector<DistillCodeClassWrapper> &m_classes;
		std::vector<DistillCodeFunctionWrapper> &m_functions;
		std::vector<DistillCodeFunctionWrapper> &m_methods;
		std::vector<DistillCodeVariableWrapper> &m_variables;
		std::vector<DistillCodeStructWrapper> &m_struct;

	};
}