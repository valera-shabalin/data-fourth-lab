#include <iostream>

#include "Tree.h"
#include "TreeNode.h"

using namespace std;

/* ����������� */
Tree::Tree() 
{
	this->Root = nullptr;
	this->count = 0;
}

/* ���������� TODO */
Tree::~Tree() 
{
	this->count = 0;
}

/* ��������� ������ �� ������� */
bool Tree::IsEmpty() const
{
	return this->Root == nullptr;
}

/* �������� ���������� ������� � ������ */
int Tree::GetMax() const
{
	TreeNode* Tmp = this->Root;

	while (Tmp->RightChild != nullptr)
	{
		Tmp = Tmp->RightChild;
	}

	return Tmp->data;
}

/* �������� ���������� ������� � ������ */
int Tree::GetMin() const
{
	TreeNode* Tmp = this->Root;

	while (Tmp->LeftChild != nullptr)
	{
		Tmp = Tmp->LeftChild;
	}

	return Tmp->data;
}

/* �������� ������� � ������ */
Tree& Tree::InsertNode(int data) 
{
	if (this->IsEmpty())
	{
		this->Root = new TreeNode(data);
	}
	else
	{
		this->InsertNodeHelper(*this->Root, data);
	}

	this->count++;

	return *this;
}

void Tree::InsertNodeHelper(TreeNode& Root, int data) 
{
	if (data < Root.data)
	{
		if (Root.LeftChild != nullptr)
		{
			InsertNodeHelper(*Root.LeftChild, data);
		}
		else
		{
			Root.LeftChild = new TreeNode(data);
		}
	}
	else
	{
		if (Root.RightChild != nullptr)
		{
			InsertNodeHelper(*Root.RightChild, data);
		}
		else
		{
			Root.RightChild = new TreeNode(data);
		}
	}
}

/* ������� ������� �� ������ TODO */
Tree& Tree::DeleteNode() 
{
	return *this;
}

/* ������� */
TreeNode* Tree::GetRoot() const 
{
	return this->Root;
}

size_t Tree::GetCount() const
{
	return this->count;
}
