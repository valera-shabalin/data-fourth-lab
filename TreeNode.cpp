#include "TreeNode.h"

using namespace std;


/* ����������� */
TreeNode::TreeNode(int data) 
{
	this->data = data;
	this->LeftChild = this->RightChild = nullptr;
}

/* ���������� */
TreeNode::~TreeNode() 
{
	this->data = 0;
	this->LeftChild = this->RightChild = nullptr;
}

/* ������� */
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

/* ������� */
TreeNode& TreeNode::SetData(int data)
{
	this->data = data;
	return *this;
}

