#ifndef _TREE_NODE_H
#define _TREE_NODE_H

namespace tree_node 
{
	class TreeNode 
	{
	private:
		int data;
		TreeNode* LeftChild;
		TreeNode* RightChild;
	public:
		/* ����������� � ���������� */
		TreeNode(int data = 0);
		~TreeNode();
		/* ������� */
		int get_data() const;
		TreeNode* get_left_child() const;
		TreeNode* get_right_child() const;
		/* ������� */
		TreeNode* set_data(int data);
	};
}

#endif

