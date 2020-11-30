#include <iostream>

#include "Tree.h"

using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "Rus");

    Tree t = Tree();

    t.InsertNode(4).InsertNode(5).InsertNode(2).InsertNode(2).InsertNode(10).InsertNode(3).InsertNode(20);

    int max = t.GetMax();
    
    cout << t.GetCount() << " " << max;
}

