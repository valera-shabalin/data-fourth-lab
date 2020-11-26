#include "TreeNode.h"

using namespace std;

namespace tree_node 
{
	/* Конструктор */
	TreeNode::TreeNode(int data) 
	{
		this->data = data;
		this->LeftChild = this->RightChild = nullptr;
	}

	/* Деструктор */
	TreeNode::~TreeNode() 
	{
		
	}

	/* Геттеры */
	int TreeNode::get_data() const 
	{
		return this->data;
	}

	TreeNode* TreeNode::get_left_child() const
	{
		return this->LeftChild;
	}

	TreeNode* TreeNode::get_right_child() const
	{
		return this->RightChild;
	}

	/* Сеттеры */
	TreeNode* TreeNode::set_data(int data)
	{
		this->data = data;
		return this;
	}
}
