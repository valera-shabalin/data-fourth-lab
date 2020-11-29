#ifndef _TREE_H
#define _TREE_H

class Tree 
{
	friend class TreeNode;
private:
	class TreeNode* Root;
	size_t count;
public:
	/* Конструктор и деструктор */
	Tree();
	~Tree();

	/* Основные методы */
	bool IsEmpty() const;
	TreeNode& GetMax(TreeNode* Root = nullptr) const;
	TreeNode& GetMin(TreeNode* Root = nullptr) const;
	Tree& InsertNode(int value);

	/* Геттеры */
	TreeNode* GetRoot() const;
};

#endif