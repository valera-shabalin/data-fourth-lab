#ifndef _TREE_NODE_H
#define _TREE_NODE_H

class TreeNode 
{
	friend class Tree;
private:
	int data;
	TreeNode *LeftChild, *RightChild;
public:
	/* ����������� � ���������� */
	TreeNode(int data = 0);
	~TreeNode();

	/* ������� */
	int GetData() const;
	TreeNode* GetLeftChild() const;
	TreeNode* GetRightChild() const;

	/* ������� */
	TreeNode* SetData(int data);
};

#endif

