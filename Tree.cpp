#include "Tree.h"
#include "TreeNode.h"

using namespace std;

/* Конструктор */
Tree::Tree() 
{
	this->Root = nullptr;
	this->count = 0;
}

/* Деструктор TODO */
Tree::~Tree() 
{
	this->count = 0;
}

/* Проверить дерево на пустоту */
bool Tree::IsEmpty() const
{
	return this->Root == nullptr;
}

/* Получить наибольший элемент в дереве */
TreeNode& Tree::GetMax(TreeNode* Root) const
{
	Root = (Root == nullptr) ? this->Root : Root;

	while (Root->RightChild != nullptr)
	{
		Root = Root->RightChild;
	}

	return *Root;
}

/* Получить наименьший элемент в дереве */
TreeNode& Tree::GetMin(TreeNode* Root) const
{
	Root = (Root == nullptr) ? this->Root : Root;

	while (Root->LeftChild != nullptr)
	{
		Root = Root->LeftChild;
	}

	return *Root;
}

/* Вставить элемент в дерево */
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

/* Геттеры */
TreeNode* Tree::GetRoot() const 
{
	return this->Root;
}
size_t Tree::GetCount() const
{
	return this->count;
}
