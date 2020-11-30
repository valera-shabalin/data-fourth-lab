#ifndef _TREE_H
#define _TREE_H

class Tree 
{
	friend class TreeNode;
private:
	class TreeNode* Root;
	size_t count;

	void InsertNodeHelper(TreeNode& Root, int data);
public:
	/* ����������� � ���������� */
	Tree();
	~Tree();

	/* �������� �� ������� */
	bool IsEmpty() const;

	/* ����� ������������ � ������������� �������� */
	int GetMax() const;
	int GetMin() const;

	/* ������� ���� � ������ */
	Tree& InsertNode(int data);

	/* �������� ���� �� ������ */
	Tree& DeleteNode();

	/* ������� */
	TreeNode* GetRoot() const;
	size_t GetCount() const;
};

#endif