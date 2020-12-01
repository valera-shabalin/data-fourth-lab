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
	void DeleteHelper(TreeNode& Node);
	void PrintHelper(const TreeNode& Node, size_t length) const;
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

	/* Удаление узла из дерева TODO */
	Tree& DeleteNode(int data);

	/* Вывод дерева в консоль */
	void Print() const;

	/* Перегрузка оператора вывода */
	friend std::ostream& operator << (std::ostream& out, Tree& Tree);

	/* Геттеры */
	TreeNode* GetRoot() const;
	size_t GetCount() const;
};

#endif