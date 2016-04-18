//
//  main.cpp
//  LeetCodeTest
//
//  Created by ChenYi-Hung on 2016/3/10.
//  Copyright © 2016年 ChenYi-Hung. All rights reserved.
//

#include <iostream>
#include "CBinaryTree.hpp"

#include "C001TwoSum.hpp"
#include "C002Add2Nums.hpp"
#include "C003LengthOfLongestSubstring.hpp"
#include "C035SearchInsertPosition.hpp"

#include "C094BinaryTreeInorderTraversal.hpp"
#include "C104MaxDepthOfBTree.hpp"
#include "C111MinDepthOfBTree.hpp"
#include "C114BinaryTreePreorderTraversal.hpp"
#include "C145BinaryTreePostorderTraversal.hpp"
#include "C226InvertBinaryTree.hpp"
#include "C100SameTree.hpp"
#include "C101SymmetricTree.hpp"
#include "C102_BinaryTreeLevelOrderTraversal.hpp"
#include "C103BinaryTreeZigzagLevelOrderTraversal.hpp"
#include "C257BinaryTreePath.hpp"
#include "C113PathSumII.hpp"

#include "C206ReverseLinkedList.hpp"
#include "C092ReverseLinkedListII.hpp"

#define ARRAYSIZE(array, type) sizeof (array) / sizeof(type)

void printHeader(const char *msg);
void printTail(const char *msg);

void initVector(vector<int> &input, const int *pArray);

void test001_TwoSum(int *pArray, int nArraySize, int target);
void test002_Add2Nums(int *pA, int *pB, int nSizeA, int nSizeB);
void test003_LengthOfLongestSubString();


void test035_SearchInsertPosition(int *pArray, int nArraySize, int target);


void test094_InorderTraversalBTree(int *pArray, int nArraySize);
void test104_MaxDepthOfBTree(int *pArray, int nArraySize);
void test111_MinDepthOfBTree(int *pArray, int nArraySize);
void test114_PreorderTraversalBTree(int *pArray, int nArraySize);
void test145_PostorderTraversalBTree(int *pArray, int nArraySize);
void test226_InvertBinaryTree(int *pArray, int nArraySize);
void test100_SameTree(int *pArray, int nPSize, int *qArray, int nQSize);
void test101_SymmetricTree(int *pArray, int nArraySize);
void test102_BinaryTreeLevelOrderTraversal(int *pArray, int nArraySize);
void test103_BinaryTreeZigzagLevelOrderTraversal(int *pArray, int nArraySize);
void test257_BinaryTreePath(int *pArray, int nArraySize);
void test113_BinaryTreePathSumII(int *pArray, int nArraySize, int sum);

void test206_ReverseLinkedList();
void test092_ReverseLinkedListII();

void testBinaryTreeBasicFunc(int *pArray, int nArraySize);

using namespace BinaryTree;
using namespace std;

void dumpVector(vector <int> &input, const char *pszMsg);
void dumpVectorVectorInt(vector <vector<int>> &input, const char *pszMsg);
void dumpArray(const int *pArray, const char *pszMsg, unsigned int nSize);

int main(int argc, const char * argv[]) {
    // insert code here...
    /*
    {
        int array [] = {1, 3, 6, 10, 14};
        int nSize = sizeof(array) / sizeof(int);
        int target = 9;
        test001_TwoSum(array, nSize, target);
    }
    
    {
        int dataA[] = {2, 4, 6};
        int dataB[] = {6, 9, 10};
        int nSizeA = sizeof(dataA)/sizeof(int);
        int nSizeB = sizeof(dataB)/sizeof(int);
        
        test002_Add2Nums(dataA, dataB, nSizeA, nSizeB);
    }
        
    {
        int array [] = {1, 3, 6, 10, 14};
        int nSize = sizeof(array) / sizeof (int);
        int target = 2;
        test035_SearchInsertPosition(array, nSize, target);
    }
    */
    
    {
        int array [] = {5, 1, 3, 10, 9, 7};
        int nSize = sizeof(array) / sizeof (int);
        
        int aArray [] = {5, 1, 3, 10, 9, 7};
        int bArray [] = {5, 3, 1, 10, 9, 7};
        int nbSize = sizeof(bArray) / sizeof (int);
        
        
        
        test104_MaxDepthOfBTree(array, nSize);
        test111_MinDepthOfBTree(array, nSize);
        
        
        test114_PreorderTraversalBTree(array, nSize);
        test094_InorderTraversalBTree(array, nSize);
        test145_PostorderTraversalBTree(array, nSize);
    
        test226_InvertBinaryTree(array, nSize);
        
        test100_SameTree(array, nSize, aArray, nSize);
        test100_SameTree(array, nSize, bArray, nbSize);
        
        int sysArrayTest[] = {1, 2, 3, 3, 0, 2, 0};
        //int sysArrayTest[] = {5,4,1,0,1,0,4,2,0,2,0};
        //int a [] = {1, 2, 2, 3, 0, 0, 3, 4, 0, 0 ,4};
        //int b [] = {1, 2, 2, 3, 0, 0, 3};
        //int c [] = {1, 2, 2, 3, 5, 5, 3};
        test101_SymmetricTree(sysArrayTest, sizeof(sysArrayTest)/sizeof(int));
        
        
        int a [] = {1,2,3,4,5};
        //int b [] = {3, 9, 20, 0, 0, 15, 7};
        //int c [] = {1,2,3,4,0,0,5};
        test102_BinaryTreeLevelOrderTraversal(a, ARRAYSIZE(a, int));
        
        test103_BinaryTreeZigzagLevelOrderTraversal(a,ARRAYSIZE(a, int));
        
        
        int pathStr [] = {1, 2, 3, 0, 5};
        test257_BinaryTreePath(pathStr, ARRAYSIZE(pathStr, int));
        
        //int pathSumII [] = {5,4,8,11,0,13,4,7,2, 0, 0, 5,1};
        int pathSumII [] = {1, -2, -3,1,3,-2,0,-1};
        int sum = 2;
        test113_BinaryTreePathSumII(pathSumII, ARRAYSIZE(pathSumII, int), sum);
        
        // Test
        testBinaryTreeBasicFunc(array, nSize);
    }
    
     /*
    {
        test206_ReverseLinkedList();
        test092_ReverseLinkedListII();
    }
    
    
    test003_LengthOfLongestSubString();
    */
    
    return 0;
}

void printHeader(const char *msg) {
    printf("-------------------------------\n");
    printf("%s\n", msg);
    printf("-------------------------------\n");
}
void printTail(const char *msg) {
    printHeader(msg);
}

void initVector(vector <int> &input, const int *pArray, int nSize) {
    
    input.assign(pArray, pArray + nSize);

    dumpVector(input, "input");
}

void dumpVector(vector <int> &input, const char *pszMsg) {
    printf("%s: {", pszMsg);
    
    int nSize = input.size();
    for (int i = 0; i < nSize; i++) {
        //input.push_back(pArray[i]);
        
        if (i != nSize - 1) {
            printf("%d, ", input[i]);
        } else {
            printf("%d", input[i]);
        }
    }
    printf("}\n");
}

void dumpVector(vector<string> &input, const char *pszMsg) {
    printf("%s: {", pszMsg);
    
    int nSize = input.size();
    for (int i = 0; i < nSize; i++) {
        //input.push_back(pArray[i]);
        
        if (i != nSize - 1) {
            printf("%s, ", input[i].c_str());
        } else {
            printf("%s", input[i].c_str());
        }
    }
    printf("}\n");
}

void dumpVectorVectorInt(vector <vector<int>> &input, const char *pszMsg) {
    int i = 0, j;
    printf("%s\n", pszMsg);
    printf("[\n");
    for (; i < input.size(); i++) {
        printf("  [");
        vector<int> innerInput = input[i];
        for (j = 0; j < innerInput.size(); j++) {
            printf("%d", innerInput[j]);
            
            if (j != innerInput.size() - 1) {
                printf(",");
            }
            
        }
        
        if (i != input.size() - 1) {
            printf("],\n");
        } else {
            printf("]\n");
        }
    }
    
    printf("]\n");
}


void dumpArray(const int *pArray, const char *pszMsg, unsigned int nSize) {
    printf("%s: {", pszMsg);
    
    for (int i = 0; i < nSize; i++) {
        if (i != nSize - 1) {
            printf("%d, ", pArray[i]);
        } else {
            printf("%d", pArray[i]);
        }
    }
    printf("}\n");

}

//-----------------------
void testBinaryTreeBasicFunc(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    bTree.initBinaryTree(pArray, nArraySize);
    
    printHeader("### Start test binary tree basic function");
    
    int treeH = bTree.getTreeHeight();
    printf("tree height: %d\n", treeH);
    
    int maxDepth = bTree.getTreeMaxDepth();
    printf("tree max dep: %d\n", maxDepth);
    
    int minDepth = bTree.getTreeMinDepth();
    printf("tree min dep: %d\n", minDepth);
    
    //bTree.printTree();
    vector <int> orderVal;
    bTree.traversal(orderVal, CBinaryTree::DFS_PREORDER);
    bTree.traversal(orderVal, CBinaryTree::DFS_INORDER);
    bTree.traversal(orderVal, CBinaryTree::DFS_POSTORDER);
    bTree.traversal(orderVal, CBinaryTree::BFS);

    printTail("### End test binary tree baic function");
}

//========================================
void test001_TwoSum(int *pArray, int nArraySize, int target) {
    vector <int> input;
    vector <int> output;
    //int arr [] = {2,1,9,4,4,56,90,3};
    //int target = 8;
    
    //int arr [] = {-3,1, 4, 56,90,3};
    //int target = 94;
    //int arr [] = {0, 2, 3, 0};
    //int target = 0;
    initVector(input, pArray, nArraySize);
    printf("target: %d\n", target);
    
    
    printHeader("## Start test 001: two sum");
    
    two_sum::Solution sol;
    output = sol.twoSum(input, target);
    
    
    printf("output: {%d, %d}\n", output[0], output[1]);
    
    printTail("## End test 001: two sum");
}

void test002_Add2Nums(int *pA, int *pB, int nSizeA, int nSizeB) {
    //int dataA[] = {2, 4, 6};
    //int dataB[] = {6, 9, 10};
    
    printHeader("## Start test 002: add 2 nums");
    
    add2nums::CTestGen testGen;
    add2nums::Solution sol(1);
    ListNode *pLA = testGen.initList(pA, nSizeA);
    ListNode *pLB = testGen.initList(pB, nSizeB);
    
    testGen.dumpList(pLA);
    testGen.dumpList(pLB);
    
    ListNode *pLResult = sol.addTwoNumbers(pLA, pLB);

    testGen.dumpList(pLResult);
    
    testGen.freeList(pLA);
    testGen.freeList(pLB);
    testGen.freeList(pLResult);
    
    printTail("## End test 002: add 2 nums");
    printf("\n");
}

void test003_LengthOfLongestSubString() {
    string input = "anviaj"; //"tmmzuxt";//"aaca"; //"eee";
    
    printHeader("## Start test 003: length of longest subString");
    
    
    LengthOfLongestSubstring::Solution sol;
    //int length = sol.lengthOfLongestSubstring(input);
    int length = sol.lengthOfLongestSubstringFunc(input, E_ITERATIVE);
    
    printf("length of longest sub string of %s is: %d\n", input.c_str(), length);
    
    length = sol.lengthOfLongestSubstringFunc(input, E_DP);
    

    printf("length of longest sub string (dp) of %s is: %d\n", input.c_str(), length);
    
    printTail("## End test 003: length of longest subString");
    

}

void test035_SearchInsertPosition(int *pArray, int nArraySize, int target) {
    //int array [] = {1, 3, 6, 10 , 13};
    //int target = 2;
    
    printHeader("## Start test 035: search insert position");
    
    vector<int> input;
    initVector(input, pArray, nArraySize);
    printf("target: %d\n", target);
    
    searchingInsertPosition::Solution sol;
    int nHitPos = sol.searchInsertSTL(input, target);
    printf("pos: %d\n", nHitPos);

    nHitPos = sol.searchInsertBinarySearchVer(input, target);
    printf("pos: %d\n", nHitPos);

    printTail("## end test 0035: search insert position");
}

void test094_InorderTraversalBTree(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    BinaryTreeInorderTraversal::Solution sol;
    
    printHeader("## Start test 094: inorder traversal of BTree");
    
    bTree.initBinaryTree(pArray, nArraySize);
    vector<int> output = sol.inorderTraversal(bTree.getRoot());
    
    dumpVector(output, "output");
    
    printTail("## End test 094: inorder traversal of BTree");
}

void test104_MaxDepthOfBTree(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    maxDepthOfBTree::Solution sol;
    
    printHeader("## Start test 104: max depth of Binary tree");
    
    bTree.initBinaryTree(pArray, nArraySize);
    int maxDepth = sol.maxDepth(bTree.getRoot());
    printf("max depth: %d\n", maxDepth);
    
    printTail("## End test 104: max depth of Binary tree");
}

void test111_MinDepthOfBTree(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    minDepthOfBTree::Solution sol;
    
    printHeader("## Start test 111: min Depth of BTree");
    
    bTree.initBinaryTree(pArray, nArraySize);
    int minDepth = sol.minDepth(bTree.getRoot());
    printf("min depth: %d\n", minDepth);

    
    printTail("## End test 111: min Depth of BTree");
}

void test114_PreorderTraversalBTree(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    BinaryTreePreorderTraversal::Solution sol;
    
    printHeader("## Start test 114: preorder traversal of BTree");
    
    bTree.initBinaryTree(pArray, nArraySize);
    vector<int> output = sol.preorderTraversal(bTree.getRoot());
    
    dumpVector(output, "output");
    
    
    printTail("## End test 114: preorder traversal of BTree");
}


void test145_PostorderTraversalBTree(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    BinaryTreePostorderTraversal::Solution sol;

    printHeader("## Start test 145: post order traversal of BTree");
    
    bTree.initBinaryTree(pArray, nArraySize);
    vector<int> output = sol.postorderTraversal(bTree.getRoot());
    
    dumpVector(output, "output");
    
    
    printTail("## End test 145: post order traversal of BTree");
}

void test226_InvertBinaryTree(int *pArray, int nArraySize) {
    CBinaryTree bTree;
    BT_InvertBinaryTree::Solution sol;
    vector <int> output;
    
    printHeader("## Start test 226: Invert BTree");
    
    bTree.initBinaryTree(pArray, nArraySize);
    printf ("before invert, ");
    bTree.traversal(output, CBinaryTree::BFS);
    
    TreeNode *pNode = sol.invertTree(bTree.getRoot());
    //bTree.invertTree(bTree.getRoot());
    
    printf ("after  invert, ");
    bTree.traversal(output, CBinaryTree::BFS);
    
    printTail("## End test 226: Invert BTree");
}

void test100_SameTree(int *pArray, int nPSize, int *qArray, int nQSize) {
    CBinaryTree bATree, bBTree;
    
    printHeader("## Start test 100: Is same tree");
    vector <int> outputA, outputB;
    
    bATree.initBinaryTree(pArray, nPSize);
    bBTree.initBinaryTree(qArray, nQSize);
    BT_SameTree::Solution sol;
    

    bool bRet = sol.isSameTree(bATree.getRoot(), bBTree.getRoot());
    printf("Is same tree: %s\n", bRet ? "Yes" : "No");
    bATree.traversal(outputA);
    bBTree.traversal(outputB);
    
    printHeader("## End test 100: Is same tree");
}

void test101_SymmetricTree(int *pArray, int nSize) {
    printHeader("## Start test 101: Is Symmetric Tree");
    CBinaryTree bTree;
    BT_SymmetricTree::Solution sol;
    
    dumpArray(pArray, "input array: ", nSize);
    bTree.initBinaryTree_LCFormat(pArray, nSize);
    bool bIsSymmetric = sol.isSymmetric(bTree.getRoot());
    
    
    printf("Is Sysmmetric tree: %s\n", (bIsSymmetric) ? "Yes" : "No");
    printTail("## End test 101: Is Symmetric Tree");
}

void test102_BinaryTreeLevelOrderTraversal(int *pArray, int nSize) {
    printHeader("## Start test 102: Binary tree level order Traversal");
    CBinaryTree bTree;
    BT_BFS::Solution sol;
    
    dumpArray(pArray, "input array: ", nSize);
    bTree.initBinaryTree_LCFormat(pArray, nSize);
    vector<vector<int>> output = sol.levelOrder(bTree.getRoot());
    
    dumpVectorVectorInt(output, "output: ");
    
    printTail("## End test 102: Binary tree level order Traversal");

}

void test103_BinaryTreeZigzagLevelOrderTraversal(int *pArray, int nSize) {
    printHeader("## Start test 103: Binary tree Zigzag level order Traversal");
    CBinaryTree bTree;
    BT_BFS_Zigzag::Solution sol;
    
    dumpArray(pArray, "input array: ", nSize);
    bTree.initBinaryTree_LCFormat(pArray, nSize);
    vector<vector<int>> output = sol.zigzagLevelOrder(bTree.getRoot());
    
    dumpVectorVectorInt(output, "output: ");
    
    printTail("## End test 103: Binary tree Zigzag level order Traversal");
    
}


void test257_BinaryTreePath(int *pArray, int nSize) {
    printHeader("## Start test 257: Binary tree Path");
    CBinaryTree bTree;
    BT_Path::Solution sol;
    
    dumpArray(pArray, "input array: ", nSize);
    bTree.initBinaryTree_LCFormat(pArray, nSize);
    vector<string> output = sol.binaryTreePaths(bTree.getRoot());
    
    dumpVector(output, "output: ");
    
    printTail("## End test 257: Binary tree Path");
}


void test113_BinaryTreePathSumII(int *pArray, int nSize, int sum) {
    printHeader("## Start test 113: Binary tree Path Sum II");
    CBinaryTree bTree;
    BT_TreePathSum::Solution sol;
    
    dumpArray(pArray, "input array: ", nSize);
    bTree.initBinaryTree_LCFormat(pArray, nSize);
    vector<vector <int>> output = sol.pathSum(bTree.getRoot(), sum);
    
    dumpVectorVectorInt(output, "output: ");
    
    printTail("## End test 113: Binary tree Path Sum II");
}

void test206_ReverseLinkedList() {
    printHeader("## Start test 206: reverse Linked list");
    
    ReverseLinkedList::Solution sol;
    ListNode *pNode = sol.reverseListFunc(sol.getHead(), E_ITERATIVE);
    sol.dumpList(pNode, "reverse linked list (iterative)");
    
    sol.setHead(pNode);
    pNode = sol.reverseListFunc(sol.getHead(), E_RECURSIVE);
    sol.dumpList(pNode, "reverse linked list (recursive)");
    
    printTail("## End test 206: reverse Linked list");
}

void test092_ReverseLinkedListII() {
    printHeader("## Start test 092: reverse Linked list II");
    
    ReverseLinkedListII::Solution sol;
    int m = 3, n = 5;
    ListNode *pNode;
    pNode = sol.reverseBetweenFunc(sol.getHead(), m, n, E_ITERATIVE);
    
    char msg[100] = {0};
    sprintf(msg, "reverse linked list II @ (%d, %d)", m, n);
    
    sol.dumpList(pNode, msg);
    
    sol.setHead(pNode);
    
    //m = 3, n = 10;
    pNode = sol.reverseBetweenFunc(sol.getHead(), m, n, E_RECURSIVE);
    
    sprintf(msg, "reverse linked list II @ (%d, %d)", m, n);
    sol.dumpList(pNode, msg);
    
    
    printTail("## End test 206: reverse Linked list II");
}

