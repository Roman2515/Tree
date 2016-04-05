#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "treenode.h"
#include <assert.h>

template <class NODEKEY, class NODEDATA>
class Tree
{
public:
    Tree();
    void insertNode(const NODEKEY &, const NODEDATA &);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal()const;
private:
    TreeNode<NODEKEY, NODEDATA> *rootptr;

    void insertNodeHelper(TreeNode<NODEKEY, NODEDATA> **, const NODEKEY &, const NODEDATA & );
    void preOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    void inOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    void postOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
};

template <class NODEKEY, class NODEDATA>
Tree<NODEKEY, NODEDATA>::Tree() { rootptr = nullptr; }

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::insertNode(const NODEKEY &value, const NODEDATA &vol)
{
    insertNodeHelper(&rootptr, value, vol);
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::insertNodeHelper(TreeNode<NODEKEY, NODEDATA> **ptr, const NODEKEY &value, const NODEDATA &vol)
{
    if (*ptr == nullptr) {
        *ptr = new TreeNode<NODEKEY, NODEDATA> (value, vol);
        assert(*ptr != nullptr);
    }
    else
        if (value < (*ptr)->key)
            insertNodeHelper( &((*ptr)->leftptr), value, vol);
        else
            if (value > (*ptr)->key)
                insertNodeHelper( &((*ptr)->rightptr), value, vol);
        else
                std::cout << value << " is allready now" << std::endl;
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::inOrderTraversal() const
{
    inOrderHelper( rootptr );
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::inOrderHelper(TreeNode<NODEKEY, NODEDATA> *ptr) const
{
    if (ptr != nullptr)
    {
        inOrderHelper( ptr->leftptr);
        std::cout << ptr->key << " : " << ptr->data << "  |  ";
        inOrderHelper( ptr->rightptr);
    }
}


#endif // TREE_H
