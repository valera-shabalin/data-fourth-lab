#include <iostream>

#include "Tree.h"
#include "TreeNode.h"

using namespace std;

bool Tree::debug = false;
size_t Tree::static_id = 0;

/* �������� ��������������� ������ */
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

void Tree::ClearHelper(TreeNode& Node)
{
	if (&Node != nullptr)
	{
		ClearHelper(*Node.RightChild);
		ClearHelper(*Node.LeftChild);

		delete& Node;

		this->count--;
	}
}

int Tree::GetNodesSummHelper(const TreeNode& Node, int value) const
{
	if (Node.LeftChild != nullptr || Node.RightChild != nullptr)
	{
		value += Node.data;
		value = (Node.LeftChild != nullptr) ? GetNodesSummHelper(*Node.LeftChild, value) : value;
		value = (Node.RightChild != nullptr) ? GetNodesSummHelper(*Node.RightChild, value) : value;
	}

	return value;
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

	this->ClearHelper(*this->Root);
	this->count = 0;
	this->id = 0;
}

/* ��������� ������ �� ������� */
bool Tree::IsEmpty() const
{
	return this->Root == nullptr;
}

/* �������� ���������� ������� � ������ */
TreeNode* Tree::GetMaxNode(TreeNode* Node) const
{
	TreeNode* Tmp = (Node == nullptr) ? this->Root : Node;

	while (Tmp->RightChild != nullptr)
	{
		Tmp = Tmp->RightChild;
	}

	return Tmp;
}

/* �������� ���������� ������� � ������ */
TreeNode* Tree::GetMinNode(TreeNode* Node) const
{
	TreeNode* Tmp = (Node == nullptr) ? this->Root : Node;

	while (Tmp->LeftChild != nullptr)
	{
		Tmp = Tmp->LeftChild;
	}

	return Tmp;
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

/* ���������� ����� �������������� ����� ������ TODO */
int Tree::GetNodesSumm() const
{
	return this->GetNodesSummHelper(*this->Root, 0);
}

/* ����� ������ � ������� */
void Tree::Print() const
{
	cout << endl;
	this->PrintHelper(*this->Root, 0);
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

size_t Tree::GetId() const {
	return this->id;
}
