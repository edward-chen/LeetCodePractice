//
//  CBinaryTree.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/29.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include "CBinaryTree.hpp"


//============================
//Class Binary tree
//============================

using namespace BinaryTree;

void CBinaryTree::initBinaryTree(const int *pArray, int nArraySize) {
    if (!pArray) {
        return;
    }
    
    for (int i = 0; i < nArraySize; i++) {
        TreeNode *pNode = new TreeNode (pArray[i]);
        insertTreeNode(&m_pRoot, pNode);
    }
}

void CBinaryTree::insertTreeNode(TreeNode **ppTreeNode, TreeNode *pNode) {
    if (!(*ppTreeNode)) {
        *ppTreeNode = pNode;
        return;
    }
    TreeNode *pTreeNode = *ppTreeNode;
    
    if (pTreeNode->val > pNode->val) {
        insertTreeNode(&pTreeNode->left, pNode);
    } else if (pTreeNode->val < pNode->val) {
        insertTreeNode(&pTreeNode->right, pNode);
    }
}

TreeNode *CBinaryTree::createTreeNode(int val) {
    TreeNode *pNode = NULL;
    if (val) {
        pNode = new TreeNode(val);
    }
    
    return pNode;
}

void CBinaryTree::initBinaryTree_LCFormat(const int *pArray, unsigned int nArraySize) {
    // Leet Code format array
    //           1
    //          / \
    //         2   3
    //            /
    //           4
    //            \
    //             5
    //
    // The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
    // input here will be ==================> "{1,2,3,0,0,4,0,0,5}". (0 means null here)
    //
    queue<TreeNode *> tmpQ;
    int nLvlNodeCnt = 2;
    int nRestSize = nArraySize;
    
    if (nRestSize) {
        if (m_pRoot = createTreeNode(*(pArray++))) {
            tmpQ.push(m_pRoot);
        }
        nRestSize--;
    }
    
    while(nRestSize) {
        int nNextLvlNodeCnt = 0;
        for (int i = 0; i < nLvlNodeCnt / 2; i++) {
            TreeNode *pNode = tmpQ.front();
            tmpQ.pop();
            
            // handle left leaf
            if (pNode->left = createTreeNode(*(pArray++))) {
                tmpQ.push(pNode->left);
                nNextLvlNodeCnt += 2;
            }
            nRestSize--;
            
            if (pNode->right = createTreeNode(*(pArray++))) {
                tmpQ.push(pNode->right);
                nNextLvlNodeCnt += 2;
            }
            nRestSize--;
        }
        
        nLvlNodeCnt = nNextLvlNodeCnt;
    }
}


CBinaryTree::~CBinaryTree() {
    destroyTree();
}

void CBinaryTree::destroyTree() {
    // TODO: need to implement code here
    deleteLeaf(&m_pRoot);
    m_pRoot = NULL;
}

void CBinaryTree::deleteLeaf(TreeNode **ppLeaf) {
    TreeNode *pLeaf = *ppLeaf;
    if (pLeaf) {
        deleteLeaf(&pLeaf->left);
        deleteLeaf(&pLeaf->right);
        delete pLeaf;
        pLeaf = NULL;
    }
}

int CBinaryTree::getTreeMaxDepth() {
    return getMaxDepth(m_pRoot);
}

int CBinaryTree::getTreeMinDepth() {
    return getMinDepth(m_pRoot);
}

int CBinaryTree::getMaxDepth(TreeNode *pLeaf) {
    int nLDepth = 0, nRDepth = 0, nDepth = 0;
    if (pLeaf) {
        nLDepth = getMaxDepth(pLeaf->left) + 1;
        nRDepth = getMaxDepth(pLeaf->right) + 1;
        nDepth = (nLDepth > nRDepth) ? nLDepth: nRDepth;
    }
    
    return nDepth;
}

int CBinaryTree::getMinDepth(TreeNode *pLeaf) {
    int nLDepth = 0, nRDepth = 0, nDepth = 0;
    if (pLeaf) {
        nLDepth = getMinDepth(pLeaf->left) + 1;
        nRDepth = getMinDepth(pLeaf->right) + 1;
        
        if (nLDepth != nRDepth) {
            if (nLDepth == 1) {
                // means Left is NULL, use right depth
                return nRDepth;
            } else if (nRDepth == 1) {
                // means Right i NULL, use left depth
                return nLDepth;
            } else {
                // return smaller if both left and right not null
                return (nLDepth > nRDepth) ? nRDepth: nLDepth;
            }
        } else {
            // same Depth,
            return nLDepth;
        }
    }
    
    // root is null, return 0;
    return nDepth;
}

int CBinaryTree::getHeight(TreeNode *pLeaf) {
    int nLeftH = -1, nRightH = -1, nHeight = -1;
    if (pLeaf) {
        nLeftH = getHeight(pLeaf->left) + 1;
        nRightH = getHeight(pLeaf->right) + 1;
        //printf("pLeaf val: %d\n", pLeaf->val);
        //printf("LH: %d, LR: %d\n", nLeftH, nRightH);
        nHeight = (nLeftH > nRightH) ? nLeftH: nRightH;
    }
    
    return nHeight;
}

int CBinaryTree::getTreeHeight() {
    return getHeight(m_pRoot);
}

// DFS
void CBinaryTree::traversalPreOrder(TreeNode *pLeaf, vector <int> &orderVal) {
    // root -> left subtree --> right subtree
    // root at the first position
    if (pLeaf) {
        //printf("%d ", pLeaf->val);
        orderVal.push_back(pLeaf->val);
        traversalPreOrder(pLeaf->left, orderVal);
        traversalPreOrder(pLeaf->right, orderVal);
    }
}

void CBinaryTree::traversalInOrder(TreeNode *pLeaf, vector <int> &orderVal) {
    // left subtree -> root -> right subtree
    // root at then middle position
    if (pLeaf) {
        traversalInOrder(pLeaf->left, orderVal);
        orderVal.push_back(pLeaf->val);
        traversalInOrder(pLeaf->right, orderVal);
    }
}

void CBinaryTree::traversalPostOrder(TreeNode *pLeaf, vector <int> &orderVal) {
    // left subtree -> right subtree -> root
    // root at the end position
    if (pLeaf) {
        traversalPostOrder(pLeaf->left, orderVal);
        traversalPostOrder(pLeaf->right, orderVal);
        orderVal.push_back(pLeaf->val);
    }
}

void CBinaryTree::traversalBFS(TreeNode *pLeaf, vector <int> &orderVal) {
    if (pLeaf) {
        queue <TreeNode *> tmp;
        tmp.push(pLeaf);
        
        while(!tmp.empty()) {
            TreeNode *pRootNode = tmp.front();
            tmp.pop();
            
            orderVal.push_back(pRootNode->val);
            
            if (pRootNode->left) tmp.push(pRootNode->left);
            if (pRootNode->right) tmp.push(pRootNode->right);
        }
    }
}

void CBinaryTree::traversal(vector <int> &orderVal, int nDfsOption) {
    int size = 0;
    orderVal.clear();
    
    switch (nDfsOption){
        case DFS_PREORDER:
            printf("Traversal  preOder: {");
            traversalPreOrder(m_pRoot, orderVal);
            break;
        case DFS_INORDER:
            printf("Traversal   inOder: {");
            traversalInOrder(m_pRoot, orderVal);
            break;
        case DFS_POSTORDER:
            printf("Traversal postOder: {");
            traversalPostOrder(m_pRoot, orderVal);
            break;
        case BFS:
            printf("Traversal BFS: {");
            traversalBFS(m_pRoot, orderVal);
            break;
        default:
            break;
    };
    
    // Debug
    size = orderVal.size();
    if (size) {
        for (int i = 0; i < size; i++) {
            printf(" %d", orderVal[i]);
        }
        printf(" }\n");
    }
}

TreeNode *CBinaryTree::invertTree(TreeNode *root) {
    if (root) {
        /*
        TreeNode *pTmp = root->left;
        root->left = root->right;
        root->right = pTmp;
        */
        swap(root->left, root->right);
        //root->left = invertTree(root->left);
        invertTree(root->left);
        //root->right = invertTree(root->right);
        invertTree(root->right);

    }
    return root;
}


void CBinaryTree::printTree() {
    int nHeight = getHeight(m_pRoot);
    printTreeByNode(m_pRoot, nHeight);
}

void CBinaryTree::printTreeByNode(TreeNode *pNode, int height, int lvl) {
    string msg;
    char msgArr[50] = {0};
    char tabArr[10] = {0};
    if (height == -1) {
        if (!lvl) printf("$$ tree is empty!! $$ \n");
        return;
    }
    
    //char tabArr[10] = {0};
    int repeat = height - lvl + 1;
    for (int i  = 0; i < repeat; i++ )
        strcat(tabArr, "\t");
    
    // TODO: need to implement here
    
    if (pNode) {
        sprintf(msgArr, "[level: %02d] %s[%3d]\n", lvl, tabArr, pNode->val);
        printTreeByNode(pNode->left, height, lvl + 1);
        printTreeByNode(pNode->right, height, lvl + 1);
    } else {
        sprintf(msgArr, "[level: %02d] %s[   ]\n", lvl, tabArr);
    }
}

