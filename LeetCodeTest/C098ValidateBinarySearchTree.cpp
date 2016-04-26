//
//  C098ValidateBinarySearchTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/4/22.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "C098ValidateBinarySearchTree.hpp"

using namespace BT_ValidateBT;

bool Solution::isValidBST(TreeNode *root) {
    // 28 ms
    bool bRet = true;
    do {
        if (!root) break;
        
        int val;
        vector <node> rootVal;
        node rootNode(root->val, 1);
        rootVal.push_back(rootNode);
        if (root->left) {
            val = root->left->val;
            if (val >= root->val) {
                bRet = false;
                break;
            }
            
            
            if (!(bRet = isValidBST(root->left, rootVal)))
                break;
        }
        
        rootVal.pop_back();
        rootNode.setDir(2);
        rootVal.push_back(rootNode);
        
        if (root->right) {
            val = root->right->val;
            if (val <= root->val) {
                bRet = false;
                break;
            }
            
            if (!(bRet = isValidBST(root->right, rootVal)))
                break;
        }
    } while (false);
    return bRet;
}

bool Solution::isValidBST(TreeNode *root, vector <node> &rootVal) {
    bool bRet = true;
    do {
        int val = root->val;
        
        if (root->left && root->right) {
            int lval = root->left->val;
            int rval = root->right->val;
            if ((lval >= val || !validForEachRoot(lval, rootVal)) ||
                (rval <= val || !validForEachRoot(rval, rootVal))) {
                bRet = false;
                break;
            }
        
            node rootNode(val, 1);
            rootVal.push_back(rootNode);
            if (!(bRet = isValidBST(root->left, rootVal))) break;
            
            rootVal.pop_back();
            rootNode.setDir(2);
            rootVal.push_back(rootNode);
            
            if (!(bRet = isValidBST(root->right, rootVal))) break;
            
            rootVal.pop_back();
        } else if (root->left) {
            int lval = root->left->val;
            
            if (lval >= val || !validForEachRoot(lval, rootVal)) {
                bRet = false;
                break;
            }
            
            node rootNode(val, 1);
            rootVal.push_back(rootNode);
            if (!(bRet = isValidBST(root->left, rootVal))) break;
            
            rootVal.pop_back();
        } else if (root->right) {
            int rval = root->right->val;
            if (rval <= val || !validForEachRoot(rval, rootVal)) {
                bRet = false;
                break;
            }
            
            node rootNode(val, 2);
            rootVal.push_back(rootNode);
            if (!(bRet = isValidBST(root->right, rootVal))) break;
            
            rootVal.pop_back();
        }
    } while (false);
    
    return bRet;
}

bool Solution::validForEachRoot(int val, vector<node> &rootVal) {
    bool bRet = true;
    
    do {
        for (vector<node>::reverse_iterator it = rootVal.rbegin(); it < rootVal.rend(); it++) {
            node *pNode = &(*it);
            if (pNode->m_nFromDir == 1) {
                if (val >= pNode->m_nVal) {
                    bRet = false;
                    break;
                }
            } else if (pNode->m_nFromDir == 2) {
                if (val <= pNode->m_nVal) {
                    bRet = false;
                    break;
                }
            }
        }
    } while (false);
    
    return bRet;
}

bool Solution::isValidBSTFunc(TreeNode *root, int nOpt) {
    bool bRet = false;
    
    switch (nOpt) {
        case E_DFS_PREORDER:
            bRet = isValidBST(root);
            break;
        case E_DFS_INORDER:
            bRet = isValidBST_Inorder(root);
        default:
            printf("Currently, only support preorder and inorder\n");
            break;
    }

    return bRet;
}

bool Solution::isValidBST_Inorder(TreeNode *root) {
    // 12 ms
    bool bRet = true;
    do {
        if (!root) break;
        
        if (!isValidBST_Inorder(root->left) || !isValidForIndorder(root) ||
            !isValidBST_Inorder(root->right)) {
            bRet = false;
            break;
        }
    } while (false);
    
    return bRet;
}

bool Solution::isValidForIndorder(TreeNode *root) {
    bool bRet = true;
    do {
        if (!m_prevNode) {
            m_prevNode = root;
            break;
        }
        
        if (m_prevNode->val >= root->val) {
            bRet = false;
            break;
        }
        
        m_prevNode = root;
    } while (false);
    
    return bRet;
}
