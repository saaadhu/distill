#include "Stdafx.h"
#pragma unmanaged;
#include <iostream>
#include "DistillVisitor.h"

using namespace Distill;


bool DistillVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration)
{
	std::cout << "Got here";
	return true;
}

bool DistillVisitor::TraverseDecl(clang::Decl *D)
{
	return clang::RecursiveASTVisitor<DistillVisitor>::TraverseDecl(D);
}