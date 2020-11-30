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
	/* Конструктор и деструктор */
	Tree();
	~Tree();

	/* Проверка на пустоту */
	bool IsEmpty() const;

	/* Поиск минимального и максимального значений */
	int GetMax() const;
	int GetMin() const;

	/* Вставка узла в дерево */
	Tree& InsertNode(int data);

	/* Удаление узла из дерева */
	Tree& DeleteNode();

	/* Геттеры */
	TreeNode* GetRoot() const;
	size_t GetCount() const;
};

#endif