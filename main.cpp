#include <iostream>
#include "tree.h"
using namespace std;


int main()
{
    int in;
    string st;
    Tree<int, string> Od;
    for(int i = 0; i < 5; i++)
    {
        cout << "set key : ";
        cin >> in;
        cout << "set data : ";
        cin >> st;
        Od.insertNode(in, st);
    }
    Od.inOrderTraversal();
}
