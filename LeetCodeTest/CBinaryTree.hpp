//
//  CBinaryTree.hpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#ifndef CBinaryTree_hpp
#define CBinaryTree_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "BasicDataStructure.h"

using namespace std;

namespace BinaryTree {
    class CBinaryTree {
    private:
        TreeNode *m_pRoot;
        vector <string> m_treeString;
        void traversal(TreeNode *pNode);
        
        // DFS (Depth-first)
        void traversalPreOrder(TreeNode *pLeaf, vector <int> &orderVal);
        void traversalInOrder(TreeNode *pLeaf, vector <int> &orderVal);
        void traversalPostOrder(TreeNode *pLeaf, vector <int> &orderVal);
        void traversalBFS(TreeNode *pLeaf, vector <int> &orderVal);
        
    public:
        static const int DFS_PREORDER = 0;
        static const int DFS_INORDER = 1;
        static const int DFS_POSTORDER = 2;
        static const int BFS = 3;
        
        CBinaryTree(): m_pRoot(0) {};
        ~CBinaryTree();
        void initBinaryTree(const int *pArray, int nArraySize);
        void insertTreeNode(TreeNode **ppTreeNode, TreeNode *pNode);
        void destroyTree();
        void deleteLeaf(TreeNode **ppLeaf);
        
        int getTreeMaxDepth();
        int getTreeMinDepth();
        int getTreeHeight();
        
        int getMaxDepth(TreeNode *pLeaf);
        int getMinDepth(TreeNode *pLeaf);
        int getHeight(TreeNode *pLeaf);
        
        void traversal(vector <int> &orderVal, int nDfsOption = DFS_PREORDER);
        TreeNode *invertTree(TreeNode *root);
        // BFS (Breadth-first)
        // ???
        
        void printTree();
        void printTreeByNode(TreeNode *pNode, int height, int lvl = 0);
        
        
        TreeNode * getRoot() { return m_pRoot; };
    };
}
#endif /* CBinaryTree_hpp */
