#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

class TreeNode
{
public:
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode() = default;
    TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(val), left(left), right(right) {}

    static void printTree(TreeNode* root);
    static int getTreeHeight(TreeNode* root);

private:
    static void printTree(TreeNode* root, int level, int trailingSpacesWidth);
    static int getTreeHeight(TreeNode* root, int currentHeight);
    static void getPrintSpacesWidth(int level, int height, int& outLeadingSpacesWidth, int& outTrailingSpacesWidth);
};

inline void TreeNode::printTree(TreeNode* root)
{
    int height = getTreeHeight(root);
    if (height == 0)
        std::cout << "Empty Tree!" << std::endl;

    int leadingSpacesWidth, trailingSpacesWidth;

    for (int i = 1; i <= height; ++i)
    {
        getPrintSpacesWidth(i, height, leadingSpacesWidth, trailingSpacesWidth);
        if (leadingSpacesWidth > 0)
            printf("%*c", leadingSpacesWidth, ' ');
        printTree(root, i, trailingSpacesWidth);
        std::cout << std::endl;
    }
}

inline void TreeNode::printTree(TreeNode* root, int level, int trailingSpacesWidth)
{
    if (level == 1)
    {
        std::string printChar = root ? std::to_string(root->val) : "N";
        std::cout << printChar;
        printf("%*c", trailingSpacesWidth, ' ');
    }
    else if (level > 1)
    {
        TreeNode* left = root ? root->left : nullptr;
        TreeNode* right = root ? root->right : nullptr;
        printTree(left, level - 1, trailingSpacesWidth);
        printTree(right, level - 1, trailingSpacesWidth);
    }
}

inline void TreeNode::getPrintSpacesWidth(int level, int height, int& outLeadingSpacesWidth, int& outTrailingSpacesWidth)
{
    int diff = height - level;
    outLeadingSpacesWidth = pow(2, diff) - 1;
    outTrailingSpacesWidth = pow(2, diff + 1) - 1;
}

inline int TreeNode::getTreeHeight(TreeNode* root)
{
    return getTreeHeight(root, 0);
}

inline int TreeNode::getTreeHeight(TreeNode* root, int currentHeight)
{
    if (root)
    {
        ++currentHeight;
        return std::max(getTreeHeight(root->left, currentHeight), getTreeHeight(root->right, currentHeight));
    }
    return currentHeight;
}