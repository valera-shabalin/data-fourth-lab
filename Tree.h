#ifndef _TREE_H
#define _TREE_H

namespace tree 
{
	class Tree 
	{
		friend class TreeNode;
	private:
		class TreeNode* Root;
	public:
		/* Конструктор и деструктор */
		Tree();
		~Tree();

		/* Основные методы */
		TreeNode* get_max();
		TreeNode* get_min();

		/* Геттеры */
		TreeNode* get_root() const;
	};
}

#endif