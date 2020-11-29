#ifndef _TREE_NODE_H
#define _TREE_NODE_H

class TreeNode 
{
	friend class Tree;
private:
	int data;
	TreeNode* LeftChild;
	TreeNode* RightChild;
public:
	/* ����������� � ���������� */
	TreeNode(int data = 0);
	~TreeNode();

	/* �������� ������ */
	TreeNode& InsertChild(int value);

	/* ������� */
	int GetData() const;
	TreeNode& GetLeftChild() const;
	TreeNode& GetRightChild() const;

	/* ������� */
	TreeNode& SetData(int data);
};

#endif

