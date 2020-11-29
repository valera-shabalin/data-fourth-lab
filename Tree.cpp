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
TreeNode& Tree::GetMax(TreeNode* Root) const
{
	Root = (Root == nullptr) ? this->Root : Root;

	while (Root->RightChild != nullptr)
	{
		Root = Root->RightChild;
	}

	return *Root;
}

/* �������� ���������� ������� � ������ */
TreeNode& Tree::GetMin(TreeNode* Root) const
{
	Root = (Root == nullptr) ? this->Root : Root;

	while (Root->LeftChild != nullptr)
	{
		Root = Root->LeftChild;
	}

	return *Root;
}

/* �������� ������� � ������ */
Tree& Tree::InsertNode(int value) {
	if (this->IsEmpty())
	{
		this->Root = new TreeNode(value);
	}
	else
	{
		this->Root->InsertChild(value);
	}

	this->count++;

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
