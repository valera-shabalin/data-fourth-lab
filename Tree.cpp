#include "Tree.h"
#include "TreeNode.h"

using namespace std;
using namespace tree_node;

namespace tree 
{
	/* ����������� */
	Tree::Tree() 
	{
		this->Root = nullptr;
	}

	/* ���������� */
	Tree::~Tree() 
	{

	}

	/* �������� ���������� ������� � ������ */
	TreeNode* Tree::get_max()
	{
		
	}

	/* �������� ���������� ������� � ������ */
	TreeNode* Tree::get_min()
	{

	}

	/* ������� */
	TreeNode* Tree::get_root() const 
	{
		return this->Root;
	}
}
