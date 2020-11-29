#ifndef _TREE_H
#define _TREE_H

class Tree 
{
	friend class TreeNode;
private:
	class TreeNode* Root;
	size_t count;
public:
	/* ����������� � ���������� */
	Tree();
	~Tree();

	/* �������� ������ */
	bool IsEmpty() const;
	TreeNode& GetMax(TreeNode* Root = nullptr) const;
	TreeNode& GetMin(TreeNode* Root = nullptr) const;
	Tree& InsertNode(int value);

	/* ������� */
	TreeNode* GetRoot() const;
};

#endif