🚀 Daily DSA Practice – Smallest Subtree with All the Deepest Nodes

LeetCode: 865
Difficulty: Medium
Topic: Binary Tree, DFS

🧠 Problem Summary

Given a binary tree, return the smallest subtree that contains all the deepest nodes in the tree.
A deepest node is one with the maximum depth from the root.

💡 Intuition

The smallest subtree containing all deepest nodes is the Lowest Common Ancestor (LCA) of those nodes.

If deepest nodes exist in both left and right subtrees, the current node is the answer.

If they exist only on one side, continue searching in that subtree.

This can be determined by comparing the heights of left and right subtrees.

⚙️ Approach

Compute the height of the left and right subtrees.

If both heights are equal → return current node.

If left height is greater → recurse left.

If right height is greater → recurse right.

Continue until the smallest valid subtree is found.

⏱️ Complexity

Time Complexity: O(n²)

Space Complexity: O(n) (recursion stack)

💻 Code (C++)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */


Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

Constraints:

The number of nodes in the tree will be in the range [1, 500].
0 <= Node.val <= 500
The values of the nodes in the tree are unique.
 

Note: This question is the same as 1123: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/










# code
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return nullptr;

        int leftH = height(root->left);
        int rightH = height(root->right);

        if (leftH == rightH) return root;
        if (leftH > rightH) return subtreeWithAllDeepest(root->left);
        return subtreeWithAllDeepest(root->right);
    }

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
