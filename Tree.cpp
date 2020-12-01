#include <iostream>

#include "Tree.h"
#include "TreeNode.h"

using namespace std;

bool Tree::debug = true;
size_t Tree::static_id = 0;

/* ����������� */
Tree::Tree() 
{
	this->Root = nullptr;
	this->count = 0;
	this->id = ++static_id;
	if (debug) cout << "����������� " << this->id << endl;
}

/* ���������� */
Tree::~Tree() 
{
	if (debug) cout << "���������� " << this->id << endl;
	this->DeleteHelper(*this->Root);
	this->count = 0;
	this->id = 0;
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

void Tree::InsertNodeHelper(TreeNode& Node, int data)
{
	if (data < Node.data)
	{
		if (Node.LeftChild != nullptr)
		{
			InsertNodeHelper(*Node.LeftChild, data);
		}
		else
		{
			Node.LeftChild = new TreeNode(data);
		}
	}
	else
	{
		if (Node.RightChild != nullptr)
		{
			InsertNodeHelper(*Node.RightChild, data);
		}
		else
		{
			Node.RightChild = new TreeNode(data);
		}
	}
}

/* ������� ������� �� ������ TODO */
Tree& Tree::DeleteNode(int data) 
{
	return *this;
}

void Tree::DeleteHelper(TreeNode& Node) 
{
	if (&Node != nullptr)
	{
		DeleteHelper(*Node.RightChild);
		DeleteHelper(*Node.LeftChild);
		delete &Node;
		this->count--;
	}
}

/* ����� ������ � ������� */
void Tree::Print() const
{
	this->PrintHelper(*this->Root, 0);
}

void Tree::PrintHelper(const TreeNode& Node, size_t length) const 
{
	if (&Node != nullptr)
	{
		PrintHelper(*Node.RightChild, length + 1);
		cout << "| ";
		for (size_t i = 1; i <= length; i++) cout << "  ";
		cout << Node.data << endl;
		PrintHelper(*Node.LeftChild, length + 1);
	}
}

/* ���������� ��������� ������ */
ostream& operator << (ostream& out, Tree& Tree) {
	Tree.Print();
	return out;
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
