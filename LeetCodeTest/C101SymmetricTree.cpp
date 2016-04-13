//
//  C101SymmetricTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/11.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C101SymmetricTree.hpp"


using namespace BT_SymmetricTree;

/* 
// ================================================
//   This is a typical symmetric tree
// ================================================
//       1
//      / \
//     2   2
//    / \ / \
//   3  4 4  3
//
// ================================================
//   This is not a symmetric tree
// ================================================
//       1
//      / \
//     2   2
//      \   \
//      3    3
//
*/

/*
int Solution::traversalPreOrder(TreeNode *root, vector<int> &output) {
    if (root) {
        output.push_back(root->val);
        
        traversalPreOrder(root->left, output);
        if (!root->left && root->right) output.push_back(-1);
        
        traversalPreOrder(root->right, output);
        if (root->left && !root->right) output.push_back(-1);
        
    }
    return (int) output.size();
}

int Solution::traversalInOrder(TreeNode *root, vector<int> &output) {
    if (root) {
        traversalInOrder(root->left, output);
        if (!root->left && root->right) output.push_back(-1);
        output.push_back(root->val);
        if (root->left && !root->right) output.push_back(-1);
        traversalInOrder(root->right, output);
    }
    return (int) output.size();
}

int Solution::traversalBFS(TreeNode *root, vector<int> &output) {
    int size = 0;
    
    queue<TreeNode *> tmpQueue;
    TreeNode emptyNode(-1);
    if (root) {
        tmpQueue.push(root);
        
        while(!tmpQueue.empty()) {
            TreeNode *pNode = tmpQueue.front();
            tmpQueue.pop();
            
            output.push_back(pNode->val);
            
            
            if (pNode->left) tmpQueue.push(pNode->left);
            if (pNode->right) tmpQueue.push(pNode->right);
        }
        
        size = output.size();
    }
    return size;
}

*/

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    bool bRet = true;
    
    do {
        if (!p && !q) {
            break;
        }
        
        if (p && !q || !p && q) {
            bRet = false;
            break;
        }
        
        if (p->val == q->val) {
            if (!(bRet = isSameTree(p->left, q->left))) break;
            if (!(bRet = isSameTree(p->right, q->right))) break;
        } else {
            bRet = false;
        }
    } while (false);
    
    
    return bRet;
}

void Solution::invertTree(TreeNode *pNode) {
    if (pNode) {
        swap(pNode->left, pNode->right);
        invertTree(pNode->left);
        invertTree(pNode->right);
    }
}


bool Solution::isSymmetric(TreeNode *root) {
    bool bRet = false;
    
    if (root) {
        if (root->left && root->right) {
            invertTree(root->right); // ??? recursive  way???
            bRet = isSameTree(root->left, root->right);
        } else if (!root->left && !root->right) {
            // only root
            bRet = true;
        }
    } else {
        // empty tree
        bRet = true;
    }
    
    return bRet;
}

bool Solution::isSymmetricRecursive(TreeNode *root) {
    bool bRet = false;

    
    return bRet;
}