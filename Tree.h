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
		/* ����������� � ���������� */
		Tree();
		~Tree();

		/* �������� ������ */
		TreeNode* get_max();
		TreeNode* get_min();

		/* ������� */
		TreeNode* get_root() const;
	};
}

#endif