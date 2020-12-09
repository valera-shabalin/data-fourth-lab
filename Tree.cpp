#include <iostream>

#include "Tree.h"
#include "TreeNode.h"

using namespace std;

bool Tree::debug = false;
size_t Tree::static_id = 0;

/* Закрытие вспомогательные методы */
void Tree::InsertNodeHelper(TreeNode& Node, int data)
{
	if (data < Node.data)
	{
		if (Node.LeftChild != nullptr)
		{
			InsertNodeHelper(*Node.LeftChild, data);
		}
		else
		{
			Node.LeftChild = new TreeNode(data);
		}
	}
	else
	{
		if (Node.RightChild != nullptr)
		{
			InsertNodeHelper(*Node.RightChild, data);
		}
		else
		{
			Node.RightChild = new TreeNode(data);
		}
	}
}

TreeNode* Tree::DeleteNodeHelper(TreeNode* Node, int data)
{
	if (Node == nullptr)
	{
		return nullptr;
	}

	if (data < Node->data)
	{
		Node->LeftChild = this->DeleteNodeHelper(Node->LeftChild, data);
		return Node;
	}
	else if (data > Node->data)
	{
		Node->RightChild = this->DeleteNodeHelper(Node->RightChild, data);
		return Node;
	}
	else if (Node->LeftChild != nullptr && Node->RightChild != nullptr)
	{
		TreeNode* Tmp = this->GetMaxNode(Node->LeftChild);
		Node->data = Tmp->data;
		Node->LeftChild = this->DeleteNodeHelper(Node->RightChild, Tmp->data);
		return Node;
	}
	else
	{
		if (Node->LeftChild != nullptr)
		{
			TreeNode* Tmp = Node->LeftChild;
			delete Node;
			return Tmp;
		}
		else if (Node->RightChild != nullptr)
		{
			TreeNode* Tmp = Node->RightChild;
			delete Node;
			return Tmp;
		}
		else
		{
			delete Node;
			return nullptr;
		}
	}
}

void Tree::ClearHelper(TreeNode& Node)
{
	if (&Node != nullptr)
	{
		ClearHelper(*Node.RightChild);
		ClearHelper(*Node.LeftChild);

		delete& Node;

		this->count--;
	}
}

int Tree::GetNodesSummHelper(const TreeNode& Node, int value) const
{
	if (Node.LeftChild != nullptr || Node.RightChild != nullptr)
	{
		value += Node.data;
		value = (Node.LeftChild != nullptr) ? GetNodesSummHelper(*Node.LeftChild, value) : value;
		value = (Node.RightChild != nullptr) ? GetNodesSummHelper(*Node.RightChild, value) : value;
	}

	return value;
}

void Tree::PrintHelper(const TreeNode& Node, size_t length) const
{
	if (&Node != nullptr)
	{
		PrintHelper(*Node.RightChild, length + 1);

		cout << "| ";
		for (size_t i = 1; i <= length; i++) cout << "  ";
		cout << Node.data << endl;

		PrintHelper(*Node.LeftChild, length + 1);
	}
}

void Tree::InOrderHelper(const TreeNode& Node) const
{
	if (&Node != nullptr)
	{
		/* Именно здесь мы что-то делаем с данными, например, выводим или ищем */
		this->InOrderHelper(*Node.LeftChild);
		this->InOrderHelper(*Node.RightChild);
	}
}

void Tree::PreOrderHelper(const TreeNode& Node) const
{
	if (&Node != nullptr)
	{
		this->InOrderHelper(*Node.LeftChild);
		this->InOrderHelper(*Node.RightChild);
		/* Именно здесь мы что-то делаем с данными, например, выводим или ищем */
	}
}

/* Конструктор */
Tree::Tree() 
{
	this->Root = nullptr;
	this->count = 0;
	this->id = ++static_id;

	if (debug) cout << "Конструктор " << this->id << endl;
}

/* Деструктор */
Tree::~Tree() 
{
	if (debug) cout << "Деструктор " << this->id << endl;

	this->ClearHelper(*this->Root);
	this->count = 0;
	this->id = 0;
}

/* Проверить дерево на пустоту */
bool Tree::IsEmpty() const
{
	return this->Root == nullptr;
}

/* Получить наибольший элемент в дереве */
TreeNode* Tree::GetMaxNode(TreeNode* Node) const
{
	TreeNode* Tmp = (Node == nullptr) ? this->Root : Node;

	while (Tmp->RightChild != nullptr)
	{
		Tmp = Tmp->RightChild;
	}

	return Tmp;
}

/* Получить наименьший элемент в дереве */
TreeNode* Tree::GetMinNode(TreeNode* Node) const
{
	TreeNode* Tmp = (Node == nullptr) ? this->Root : Node;

	while (Tmp->LeftChild != nullptr)
	{
		Tmp = Tmp->LeftChild;
	}

	return Tmp;
}

/* Вставить элемент в дерево */
Tree& Tree::InsertNode(int data) 
{
	if (this->IsEmpty())
	{
		this->Root = new TreeNode(data);
	}
	else
	{
		this->InsertNodeHelper(*this->Root, data);
	}

	this->count++;

	return *this;
}

/* Удалить узел из дерева */
Tree& Tree::DeleteNode(int data)
{
	this->DeleteNodeHelper(this->Root, data);
	this->count--;

	return *this;
}

/* Подсчитать сумму нетерминальных узлов дерева TODO */
int Tree::GetNodesSumm() const
{
	return this->GetNodesSummHelper(*this->Root, 0);
}

/* Вывод дерева в консоль */
void Tree::Print() const
{
	cout << endl;
	this->PrintHelper(*this->Root, 0);
}

/* Прямой обход дерева */
Tree& Tree::InOrder()
{
	this->InOrderHelper(*this->Root);
	return *this;
}

/* Обратный обход дерева */
Tree& Tree::PreOrder()
{
	this->PreOrderHelper(*this->Root);
	return *this;
}

/* Перегрузка оператора вывода */
ostream& operator << (ostream& out, Tree& Tree) {
	Tree.Print();
	return out;
}

/* Геттеры */
TreeNode* Tree::GetRoot() const 
{
	return this->Root;
}

size_t Tree::GetCount() const
{
	return this->count;
}

size_t Tree::GetId() const {
	return this->id;
}
