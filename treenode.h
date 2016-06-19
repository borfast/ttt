#ifndef _TREENODE_H
#define _TREENODE_H

#include <vector>

class TreeNode {
  private:
    TreeNode *parent;
    std::vector<TreeNode *> children;
    int value;

  public:
    TreeNode(int value);

    TreeNode *getParent();
    std::vector<TreeNode *> getChildren();
    int getValue();
    void setValue(int value);
};

#endif /* _TREENODE_H */
