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

class Solution {
public:

    int solve(TreeNode* root, int &ans) {

        // Base case
        if(root == nullptr) {
            return 0;
        }

        // Maximum contribution from left subtree
        // If negative, take 0 instead
        int left = max(0, solve(root->left, ans));

        // Maximum contribution from right subtree
        // If negative, take 0 instead
        int right = max(0, solve(root->right, ans));

        // Path passing through current node
        // left subtree + root + right subtree
        ans = max(ans, left + right + root->val);

        // Return max single path to parent
        // Parent can take only one side
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        // Stores overall maximum path sum
        int ans = INT_MIN;

        // DFS traversal
        solve(root, ans);

        // Final answer
        return ans;
    }
};