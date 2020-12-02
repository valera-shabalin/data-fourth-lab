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
	/* Конструктор и деструктор */
	Tree();
	~Tree();

	/* Проверка на пустоту */
	bool IsEmpty() const;

	/* Поиск минимального и максимального значений */
	TreeNode* GetMaxNode(TreeNode* Node = nullptr) const;
	TreeNode* GetMinNode(TreeNode* Node = nullptr) const;

	/* Вставка узла в дерево */
	Tree& InsertNode(int data);

	/* Подсчитать сумму нетерминальных узлов дерева */
	int GetNodesSumm() const;

	/* Вывод дерева в консоль */
	void Print() const;

	/* Перегрузка оператора вывода */
	friend std::ostream& operator << (std::ostream& out, Tree& Tree);

	/* Геттеры */
	TreeNode* GetRoot() const;
	size_t GetCount() const;
	size_t GetId() const;
};

#endif