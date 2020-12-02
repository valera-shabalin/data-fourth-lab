#include <iostream>

#include "Tree.h"

using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "Rus");

    Tree t = Tree();

    t.InsertNode(10).InsertNode(5).InsertNode(3).InsertNode(15).InsertNode(18).InsertNode(8).InsertNode(9);

    cout << "Исходное дерево" << t;

    cout << "Сумма нетерминальных узлов дерева равна " << t.GetNodesSumm() << endl;
}

