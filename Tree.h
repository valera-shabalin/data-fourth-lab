#ifndef _TREE_H
#define _TREE_H

class Tree 
{
	friend class TreeNode;
private:
	class TreeNode* Root;
	size_t count, id;
	static bool debug;
	static size_t static_id;

	void InsertNodeHelper(TreeNode& Node, int data);
	void ClearHelper(TreeNode& Node);
	int GetNodesSummHelper(const TreeNode& Node, int value) const;
	void PrintHelper(const TreeNode& Node, size_t length) const;
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

	/* �������� ���� �� ������ TODO */
	Tree& DeleteNode(int data);

	/* ���������� ����� �������������� ����� ������ */
	int GetNodesSumm() const;

	/* ����� ������ � ������� */
	void Print() const;

	/* ���������� ��������� ������ */
	friend std::ostream& operator << (std::ostream& out, Tree& Tree);

	/* ������� */
	TreeNode* GetRoot() const;
	size_t GetCount() const;
};

#endif