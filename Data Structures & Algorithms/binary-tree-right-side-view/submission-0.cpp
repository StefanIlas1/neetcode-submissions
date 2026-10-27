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

// Go layer by layer and get the rightmost real node at each level.
// This is breadth-first search (BFS), not depth-first search (DFS).

// Use a queue to process levels and a result vector to store their rightmost values.
// The queue holds pointers to tree nodes, not separate copies of their values.
// Add the root pointer to the initially empty queue.

// Start rightSide at nullptr: we haven't found a real node on this level yet.
// Reset rightSide at the beginning of every level.

// Save the queue's current size as qLen.
// Process exactly qLen entries so newly added children wait for the next level.

// q.front() reads the pointer at the front and copies it into node.
// q.pop() removes that pointer from the FRONT of the queue, not the back.
// Removing the pointer from the queue does not delete the tree node.

// If node isn't nullptr, store its pointer in rightSide.
// Update rightSide for each real node encountered on this level.

// Add children to the queue in left-to-right order: left first, then right.
// This makes the last real node processed on each level the rightmost one.

// After processing the level, add rightSide->val to res if rightSide isn't nullptr.
// Use rightSide->val, not right->val.
// Return the result vector.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);

        while(!q.empty()) {
            TreeNode* rightSide = nullptr;
            int qLen = q.size();
            for (int i = 0; i < qLen; i++){
                TreeNode* node =  q.front();
                q.pop();

                if(node) {
                    rightSide = node;
                    q.push(node->left);
                    q.push(node->right);
                }

            }
            if(rightSide) {
                res.push_back(rightSide->val);
            }
        }

        return res;
        
    }
};