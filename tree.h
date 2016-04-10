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
    bool isEmpty();
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal()const;
    bool treeScearch(const NODEKEY &value, NODEDATA &);
private:
    TreeNode<NODEKEY, NODEDATA> *rootptr;

    void insertNodeHelper(TreeNode<NODEKEY, NODEDATA> **, const NODEKEY &, const NODEDATA & );
    void preOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    void inOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    void postOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    bool treeScearchHelper(TreeNode<NODEKEY, NODEDATA> *, const NODEKEY &, NODEDATA &);
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
bool Tree<NODEKEY, NODEDATA>::isEmpty()
{
    if (rootptr == nullptr)
        return false;
    else
        return true;
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::preOrderTraversal() const
{
    preOrderHelper( rootptr );
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::preOrderHelper(TreeNode<NODEKEY, NODEDATA> *ptr) const
{
    if (ptr != nullptr)
    {
        std::cout << ptr->key << " : " << ptr->data << "  |  ";
        preOrderHelper(ptr->leftptr);
        preOrderHelper(ptr->rightptr);
    }
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
        inOrderHelper(ptr->leftptr);
        std::cout << ptr->key << " : " << ptr->data << "  |  ";
        inOrderHelper(ptr->rightptr);
    }
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::postOrderTraversal() const
{
    postOrderHelper( rootptr );
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::postOrderHelper(TreeNode<NODEKEY, NODEDATA> *ptr) const
{
    if (ptr != nullptr)
    {
        postOrderHelper( ptr->leftptr);
        postOrderHelper( ptr->rightptr);
        std::cout << ptr->key << " : " << ptr->data << "  |  ";
    }
}

template <class NODEKEY, class NODEDATA>
bool Tree<NODEKEY, NODEDATA>::treeScearch(const NODEKEY &value, NODEDATA &val)
{
    if (isEmpty())
    return treeScearchHelper(rootptr, value, val);
    std::cout << "tree is empty";
    return false;
}

template <class NODEKEY, class NODEDATA>
bool Tree<NODEKEY, NODEDATA>::treeScearchHelper(TreeNode<NODEKEY, NODEDATA> *ptr, const NODEKEY &value, NODEDATA &val)
{
    if (ptr == nullptr)
        return false;
    if (value == ptr->key)
    {
         val = ptr->data;
         return true;
    }
    if (value < ptr->key)
        treeScearchHelper(ptr->leftptr, value, val);
    else if (value > ptr->key)
        treeScearchHelper(ptr->rightptr, value, val);
}


#endif // TREE_H
