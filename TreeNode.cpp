#include "TreeNode.h"

using namespace std;


/* Конструктор */
TreeNode::TreeNode(int data) 
{
	this->data = data;
	this->LeftChild = this->RightChild = nullptr;
}

/* Деструктор */
TreeNode::~TreeNode() 
{
	this->data = 0;
	this->LeftChild = this->RightChild = nullptr;
}

/* Геттеры */
int TreeNode::GetData() const 
{
	return this->data;
}

TreeNode& TreeNode::GetLeftChild() const
{
	return *this->LeftChild;
}

TreeNode& TreeNode::GetRightChild() const
{
	return *this->RightChild;
}

/* Сеттеры */
TreeNode& TreeNode::SetData(int data)
{
	this->data = data;
	return *this;
}

