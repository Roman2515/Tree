#include <iostream>
#include "tree.h"
using namespace std;


int main()
{
    cout << "Select options:\n\t1. Add node\n\t2. View tree\n\t3. Scearch\n";
    int op;
    int in;
    string st;
    Tree<int, string> Od;

    while (true) {
        cin >> op;
    switch (op) {
    case 1:
        cout << "set key : ";
        cin >> in;
        cout << "set data : ";
        cin >> st;
        Od.insertNode(in, st);
        break;
    case 2:
        Od.preOrderTraversal();
    case 3:
        cin >> in;
        if (Od.treeScearch(in, st))
            cout << "key " << in << " is data: " << st << endl;
        else
            cout << "key not found\n";
    default:
            cout << "not found\n";
        break;
    }
    }

}
