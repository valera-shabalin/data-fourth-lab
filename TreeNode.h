#ifndef _TREE_NODE_H
#define _TREE_NODE_H

class TreeNode 
{
	friend class Tree;
private:
	int data;
	TreeNode *LeftChild, *RightChild;
public:
	/* Конструктор и деструктор */
	TreeNode(int data = 0);
	~TreeNode();

	/* Геттеры */
	int GetData() const;
	TreeNode* GetLeftChild() const;
	TreeNode* GetRightChild() const;

	/* Сеттеры */
	TreeNode* SetData(int data);
};

#endif

