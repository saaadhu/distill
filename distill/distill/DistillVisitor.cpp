#include "Stdafx.h"
#pragma unmanaged;
#include <iostream>
#include "DistillVisitor.h"
#include "clang\AST\Type.h"


using namespace Distill;

bool DistillVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl *Declaration)
{
	clang::TagTypeKind kind = Declaration->getTagKind();
	if(kind == clang::TagTypeKind::TTK_Class || kind == clang::TagTypeKind::TTK_Interface)
	{
		DistillCodeClassWrapper w;
		w.Name = Declaration->getNameAsString();
		w.FullName = Declaration->getQualifiedNameAsString();
		m_container.classes.push_back (w);
		return true;
	}

	else if (kind == clang::TagTypeKind::TTK_Struct)
	{
		DistillCodeStructWrapper w;
		w.Name = Declaration->getNameAsString();
		w.FullName = Declaration->getQualifiedNameAsString();
		m_container.structs.push_back (w);
		return true;
	}

	else if (kind == clang::TagTypeKind::TTK_Union)
	{
		DistillCodeStructWrapper w;
		w.Name = Declaration->getNameAsString();
		w.FullName = Declaration->getQualifiedNameAsString();
		m_container.unions.push_back (w);
		return true;
	}

	return false;
}


bool DistillVisitor::VisitVarDecl(clang::VarDecl *Declaration)
{

	DistillCodeVariableWrapper w;
	w.Name = Declaration->getNameAsString();
	w.FullName = Declaration->getQualifiedNameAsString();
	m_container.variables.push_back (w);
	return true;
}

bool DistillVisitor::VisitFieldDecl(clang::FieldDecl *Declaration)
{
	return true;
}



bool DistillVisitor::VisitFunctionDecl(clang::FunctionDecl *Declaration)
{
	DistillCodeFunctionWrapper w;
	w.Name = Declaration->getNameAsString();
	w.FullName = Declaration->getQualifiedNameAsString();
	m_container.functions.push_back (w);
	return true;
}

bool DistillVisitor::VisitCXXMethodDecl(clang::FunctionDecl *Declaration)
{
	DistillCodeFunctionWrapper w;
	w.Name = Declaration->getNameAsString();
	w.FullName = Declaration->getQualifiedNameAsString();
	m_container.methods.push_back (w);
	return true;
}



bool DistillVisitor::TraverseDecl(clang::Decl *D)
{
	return clang::RecursiveASTVisitor<DistillVisitor>::TraverseDecl(D);
}