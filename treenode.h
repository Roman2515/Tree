#ifndef TREENODE_H
#define TREENODE_H

template <class NODEKEY, class NODEDATA> class Tree;

template <class NODEKEY, class NODEDATA>
class TreeNode{
    friend class Tree<NODEKEY, NODEDATA>;
public:
    TreeNode(const NODEKEY &, const NODEDATA &);
    NODEKEY getData(NODEDATA &) const;
private:
    TreeNode * leftptr;
    TreeNode *rightptr;
    NODEKEY key;
    NODEDATA data;
};

template <class NODEKEY, class NODEDATA>
TreeNode<NODEKEY, NODEDATA>::TreeNode(const NODEKEY &k, const NODEDATA &d)
{
    key = k;
    data = d;
    leftptr = rightptr = nullptr;
}

template <class NODEKEY, class NODEDATA>
NODEKEY TreeNode<NODEKEY, NODEDATA>::getData(NODEDATA &d) const
{
    d = data;
    return key;
}

#endif // TREENODE_H
