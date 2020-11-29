#include <iostream>

#include "Tree.h"

using namespace std;

int main() 
{
    setlocale(LC_CTYPE, "Rus");

    Tree t = Tree();

    t.InsertNode(4);

    TreeNode* root = t.GetRoot();
    root.InsertChild(6);
    
    cout << t.GetCount();
}

