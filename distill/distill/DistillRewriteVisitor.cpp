#include "Stdafx.h"
#pragma unmanaged;
#include <iostream>
#include "DistillRewriteVisitor.h"

using namespace Distill;

bool DistillRewriteVisitor::VisitFunctionDecl(clang::FunctionDecl *Declaration)
{
	if (Declaration->getNameAsString() == m_oldName)
	{
		m_rewriter.ReplaceText (Declaration->getNameInfo().getSourceRange(), m_newName);
	}
	return true;
}

bool DistillRewriteVisitor::VisitCXXMethodDecl(clang::FunctionDecl *Declaration)
{
	if (Declaration->getNameAsString() == m_oldName)
	{
		m_rewriter.ReplaceText (Declaration->getNameInfo().getSourceRange(), m_newName);
	}
	return true;
}

std::string DistillRewriteVisitor::GetMutatedText(clang::FileID id)
{
	const clang::RewriteBuffer *buf = 
          m_rewriter.getRewriteBufferFor(id);
     std::string modifiedText = std::string(buf->begin(), buf->end());
	 return modifiedText;
}

 bool DistillRewriteVisitor::TraverseDecl(clang::Decl *D)
{
	return clang::RecursiveASTVisitor<DistillRewriteVisitor>::TraverseDecl(D);
}
