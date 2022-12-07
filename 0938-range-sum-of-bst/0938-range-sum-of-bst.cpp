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
    int rangeSumBST(TreeNode* root, int low, int high) {
       int result = 0;
        vector<TreeNode*> s{root};
        while (!s.empty()) {
            auto node = s.back(); s.pop_back();
            if (node) {
                if (low <= node->val && node->val <= high) {
                    result += node->val;
                }
                if (low <= node->val) {
                    s.emplace_back(node->left);
                }
                if (node->val <= high) {
                    s.emplace_back(node->right);
                }
            }
        }
        return result;
    }
};