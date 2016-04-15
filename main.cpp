#include <iostream>
#include "tree.h"
using namespace std;


int main()
{
    cout << "Select options:\n\t1. Add node\n\t2. View tree\n\t3. Scearch\n\t4. Deleted\n\t5. Clear tree\n\t6. Size\n\t7. Exit\n";
    int op;
    int in;
    string st;
    Tree<int, string> Od;

    while (op != 7) {
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
        break;
    case 3:
        cin >> in;
        if (Od.treeScearch(in, st))
            cout << "key " << in << " have data: " << st << endl;
        else
            cout << "key not found\n";
        break;
    case 4:
        cin >> in;
        if(Od.deleteNode(in))
            cout << "delete complete\n";
        else
            cout << "delete aborted\n";
        break;
    case 5:
        Od.clear();
        cout << "tree is clear\n";
        break;
    case 6:
        cout << "tree size: " << Od.treeSize() << endl;
        break;
    case 7:
        cout << "DONE!";
        break;
    default:
        cout << "command not found\n";
        break;
    }
    }

}
