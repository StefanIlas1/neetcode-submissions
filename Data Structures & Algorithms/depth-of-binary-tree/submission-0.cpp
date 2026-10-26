/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //DEPTH FIRST SEARCH -> there's itterative and recursive depth first search.. 

class Solution {
public:
    int maxDepth(TreeNode* root) {
       if(!root) { return 0;}

       return 1 + max(maxDepth(root->left), maxDepth(root->right));

        
    }
};
