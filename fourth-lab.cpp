#include <iostream>
#include <fstream>

#include "Tree.h"

using namespace std;

int RandInt(int min, int max) 
{
    return min + rand() % (max - min);
}

void PrintMenu()
{
    system("cls");
    cout << "Выберите действие: " << endl <<
        "1. Заполнить дерево из файла;" << endl <<
        "2. Заполнить дерево случайными данными;" << endl <<
        "3. Заполнить дерево самостоятельно;" << endl <<
        "4. Выход." << endl;
    cout << ">";
}

int GetVariable() 
{
    int variable = 0;

    cin >> variable;

    while (variable < 1 || variable > 4) {
        cout << "Неверное значение. Попробуйте ещё раз: ";
        cin >> variable;
    }

    return variable;
}

int main() 
{
    setlocale(LC_CTYPE, "Rus");

    int variable = 0, x = 0;
    size_t count = 0;
    string fileName;
    ifstream file;

    do {
        Tree tree = Tree();

        PrintMenu();

        variable = GetVariable();

        switch (variable) 
        {
        case 1:
            cout << "Введите название файла: ";
            
            cin >> fileName;

            file.open(fileName);

            while (file >> x)
            {
                tree.InsertNode(x);
            }

            tree.DeleteNode(32);

            cout << "Полученное дерево: " << tree;
            cout << "Сумма не терминальный узлов: " << tree.GetNodesSumm() << endl;
            system("pause");

            file.close();
            break;
        case 2:
            cout << "Введите нужное количество узлов в дереве: ";
            cin >> count;

            for (size_t i = 0; i < count; i++)
            {
                tree.InsertNode(RandInt(-10, 10));
            }

            cout << "Полученное дерево: " << tree;
            cout << "Сумма не терминальный узлов: " << tree.GetNodesSumm() << endl;
            system("pause");
            break;
        case 3:
            cout << "Заполняйте дерево. Введите -1, чтобы закончить: " << endl;

            do
            {
                cout << ">";
                cin >> x;
                tree.InsertNode(x);
            } while (x != -1);

            cout << "Полученное дерево: " << tree;
            cout << "Сумма не терминальный узлов: " << tree.GetNodesSumm() << endl;
            system("pause");
            break;
        }
    } while (variable != 4);

    return 0;
}

