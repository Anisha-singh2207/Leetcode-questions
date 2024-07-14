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
class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;

        // Add the current node's value to the path
        path.push_back(root->val);

        // If it's a leaf node and the path sum equals targetSum, add the path to the result
        if (!root->left && !root->right && targetSum == root->val) {
            result.push_back(path);
        }

        // Continue the search on the left and right subtree
        if (root->left) {
            dfs(root->left, targetSum - root->val, path, result);
        }
        if (root->right) {
            dfs(root->right, targetSum - root->val, path, result);
        }

        // Backtrack: remove the current node's value from the path
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }
};
