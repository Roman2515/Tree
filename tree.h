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
    ~Tree();
    void insertNode(const NODEKEY &, const NODEDATA &);
    bool isEmpty();
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal()const;
    bool treeScearch(const NODEKEY &value, NODEDATA &);
    int treeSize();
    bool deleteNode(const NODEKEY &);
    void clear();
private:
    TreeNode<NODEKEY, NODEDATA> *rootptr;
    int treesize;

    bool insertNodeHelper(TreeNode<NODEKEY, NODEDATA> **, const NODEKEY &, const NODEDATA & );
    void preOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    void inOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    void postOrderHelper(TreeNode<NODEKEY, NODEDATA> *) const;
    bool treeScearchHelper(TreeNode<NODEKEY, NODEDATA> *, const NODEKEY &, NODEDATA &);
    bool deleteNodeHelper(TreeNode<NODEKEY, NODEDATA> *, const NODEKEY &);
    void clearHelper(TreeNode<NODEKEY, NODEDATA> *);
};

template <class NODEKEY, class NODEDATA>
Tree<NODEKEY, NODEDATA>::Tree() { rootptr = nullptr; treesize = 0; }

template <class NODEKEY, class NODEDATA>
Tree<NODEKEY, NODEDATA>::~Tree()
{
    clearHelper(rootptr);
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::insertNode(const NODEKEY &value, const NODEDATA &vol)
{
    if (insertNodeHelper(&rootptr, value, vol))
        treesize++;
}

template <class NODEKEY, class NODEDATA>
bool Tree<NODEKEY, NODEDATA>::insertNodeHelper(TreeNode<NODEKEY, NODEDATA> **ptr, const NODEKEY &value, const NODEDATA &vol)
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
            {
                std::cout << value << " is allready now" << std::endl;
                return false;
            }

    return true;
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
    std::cout << "  |  ";
    preOrderHelper( rootptr );
    std::cout << std::endl;
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

template <class NODEKEY, class NODEDATA>
int Tree<NODEKEY, NODEDATA>::treeSize()
{
    return treesize;
}

template <class NODEKEY, class NODEDATA>
bool Tree<NODEKEY, NODEDATA>::deleteNode(const NODEKEY &value)
{
    if (deleteNodeHelper(rootptr, value))
        return true;
    return false;
}

template <class NODEKEY, class NODEDATA>
bool Tree<NODEKEY, NODEDATA>::deleteNodeHelper(TreeNode<NODEKEY, NODEDATA> *ptr, const NODEKEY &value)
            {
                TreeNode<NODEKEY, NODEDATA> *pointer = ptr;
                TreeNode<NODEKEY, NODEDATA> *parent  = NULL;

                while (pointer != NULL && pointer -> key != value)
                {
                        parent = pointer;
                        if (value < pointer -> key)
                                pointer = pointer -> leftptr;
                        else
                                pointer = pointer -> rightptr;
                }

                if (pointer != NULL)
                {
                    if ( parent == NULL )
                    {
                        if ( pointer -> leftptr == NULL && pointer -> rightptr == NULL )					//	если нет ни одного из детей
                        {
                            delete rootptr;
                            rootptr = NULL;
                            treesize = 0;
                            return true;
                        };

                        if ( pointer -> leftptr == NULL && pointer -> rightptr != NULL )					//	если нет левого потомка но есть правый
                        {
                            parent = rootptr;
                            rootptr = rootptr -> rightptr;
                            delete parent;
                            --treesize;
                            return true;
                        };

                        if ( pointer -> rightptr == NULL && pointer -> leftptr != NULL )
                        {
                            parent = rootptr;
                            rootptr = rootptr -> leftptr;
                            delete parent;
                            --treesize;
                            return true;
                        };

                        if ( pointer -> rightptr != NULL && pointer -> leftptr != NULL )
                        {
                            if ( pointer -> rightptr -> leftptr == NULL )
                            {
                                TreeNode<NODEKEY, NODEDATA> *removed = pointer -> rightptr;
                                pointer -> data = pointer -> rightptr -> data;
                                pointer -> key = pointer -> rightptr -> key;
                                pointer -> rightptr = pointer -> rightptr -> rightptr;
                                delete removed;
                                --treesize;
                                return true;
                            }
                            else
                            {
                                TreeNode<NODEKEY, NODEDATA> *mostLeft = pointer -> rightptr;
                                TreeNode<NODEKEY, NODEDATA> *mostLeftParent = pointer;

                                while (mostLeft -> leftptr != NULL)
                                {
                                        mostLeftParent = mostLeft;
                                        mostLeft = mostLeft->leftptr;
                                }

                                pointer -> key = mostLeft -> key;
                                pointer -> data = mostLeft -> data;
                                mostLeftParent -> leftptr = mostLeft -> rightptr;
                                delete mostLeft;
                                --treesize;
                                return true;
                            };
                        };
                    };

                    if ( pointer -> leftptr == NULL && pointer -> rightptr == NULL )					//	если нет ни одного из детей
                    {
                        if ( parent -> leftptr == pointer ) parent -> leftptr = NULL;
                        else parent -> rightptr = NULL;
                        delete pointer;
                        --treesize;
                        return true;
                    };

                    if ( pointer -> leftptr == NULL && pointer -> rightptr != NULL )					//	если нет левого потомка но есть правый
                    {
                        if ( parent -> leftptr == pointer ) parent -> leftptr = pointer -> rightptr;
                        else parent -> rightptr = pointer -> rightptr;
                        delete pointer;
                        --treesize;
                        return true;
                    };

                    if ( pointer -> rightptr == NULL && pointer -> leftptr != NULL )
                    {
                        if ( parent -> leftptr == pointer ) parent -> leftptr = pointer -> leftptr;
                        else parent -> rightptr = pointer -> leftptr;
                        delete pointer;
                        --treesize;
                        return true;
                    };

                    if ( pointer -> rightptr != NULL && pointer -> leftptr != NULL )
                    {
                        if ( pointer -> rightptr -> leftptr == NULL )
                        {
                            TreeNode<NODEKEY, NODEDATA> *removed = pointer -> rightptr;
                            pointer -> data = pointer -> rightptr -> data;
                            pointer -> key = pointer -> rightptr -> key;
                            pointer -> rightptr = pointer -> rightptr -> rightptr;
                            delete removed;
                            --treesize;
                        }
                        else
                        {
                            TreeNode<NODEKEY, NODEDATA> *mostLeft = pointer -> rightptr;
                            TreeNode<NODEKEY, NODEDATA> *mostLeftParent = pointer;

                            while (mostLeft -> leftptr != NULL)
                            {
                                    mostLeftParent = mostLeft;
                                    mostLeft = mostLeft->leftptr;
                            }

                            pointer -> key = mostLeft -> key;
                            pointer -> data = mostLeft -> data;
                            mostLeftParent -> leftptr = mostLeft -> rightptr;
                            delete mostLeft;
                            --treesize;
                        };
                        return true;
                    };
                };
                return false;
            };

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::clear()
{
    clearHelper(rootptr);
}

template <class NODEKEY, class NODEDATA>
void Tree<NODEKEY, NODEDATA>::clearHelper(TreeNode<NODEKEY, NODEDATA> *ptr)
{
    if( ptr != nullptr )
    {
        clearHelper(ptr->leftptr);
        clearHelper(ptr->rightptr);
        delete ptr;
    }
    rootptr = nullptr;
    treesize = 0;
}

#endif // TREE_H
