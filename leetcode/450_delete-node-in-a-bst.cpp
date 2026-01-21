/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root) {
            auto v = root->val;
            if (v > key) {
                root->left = deleteNode(root->left, key);
            } else if (v < key) {
                root->right = deleteNode(root->right, key);
            } else {
                if (root->left == NULL && root->right == NULL) {
                    return NULL;
                }
                if (root->left == NULL || root->right == NULL) {
                    return root->left ? root->left : root->right;
                }

                auto tmp = root->left;
                while (tmp->right != NULL) {
                    tmp = tmp->right;
                }
                tmp->right = root->right;
                return root->left;
            }
        }
        return root;
    }
};