#include <iostream>

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
int Tree::GetMax() const
{
	TreeNode* Tmp = this->Root;

	while (Tmp->RightChild != nullptr)
	{
		Tmp = Tmp->RightChild;
	}

	return Tmp->data;
}

/* Получить наименьший элемент в дереве */
int Tree::GetMin() const
{
	TreeNode* Tmp = this->Root;

	while (Tmp->LeftChild != nullptr)
	{
		Tmp = Tmp->LeftChild;
	}

	return Tmp->data;
}

/* Вставить элемент в дерево */
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

/* Удалить элемент из дерева TODO */
Tree& Tree::DeleteNode() 
{
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
