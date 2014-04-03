#include "Stdafx.h"
#pragma unmanaged;
#include <iostream>
#include "DistillVisitor.h"
#include "DistillCodeClassWrapper.h"


using namespace Distill;

bool DistillVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration)
{
	DistillCodeClassWrapper w;
	w.Name = Declaration->getNameAsString();
	w.FullName = Declaration->getQualifiedNameAsString();
	m_classes.push_back (w);
	return true;
}

bool DistillVisitor::VisitFunctionDecl(clang::FunctionDecl *Declaration)
{
	DistillCodeFunctionWrapper w;
	w.Name = Declaration->getNameAsString();
	w.FullName = Declaration->getQualifiedNameAsString();
	m_functions.push_back (w);
	return true;
}

bool DistillVisitor::VisitCXXMethodDecl(clang::FunctionDecl *Declaration)
{
	DistillCodeFunctionWrapper w;
	w.Name = Declaration->getNameAsString();
	w.FullName = Declaration->getQualifiedNameAsString();
	m_functions.push_back (w);
	return true;
}

 bool DistillVisitor::TraverseDecl(clang::Decl *D)
{
	return clang::RecursiveASTVisitor<DistillVisitor>::TraverseDecl(D);
}
