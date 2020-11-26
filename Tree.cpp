#include "Tree.h"
#include "TreeNode.h"

using namespace std;
using namespace tree_node;

namespace tree 
{
	/* Конструктор */
	Tree::Tree() 
	{
		this->Root = nullptr;
	}

	/* Деструктор */
	Tree::~Tree() 
	{

	}

	/* Получить наибольший элемент в дереве */
	TreeNode* Tree::get_max()
	{
		
	}

	/* Получить наименьший элемент в дереве */
	TreeNode* Tree::get_min()
	{

	}

	/* Геттеры */
	TreeNode* Tree::get_root() const 
	{
		return this->Root;
	}
}
