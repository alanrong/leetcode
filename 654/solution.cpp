/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 1) {
            TreeNode *n = new TreeNode(nums[0]);
            return n;
        } else if (nums.size() == 0) {
            return NULL;
        }
        int pos = findMax(nums);
        TreeNode *root = new TreeNode(nums[pos]);
        vector<int> left(nums.begin(), nums.begin()+pos);
        vector<int> right(nums.begin()+pos+1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
private:
    size_t findMax(vector<int>& nums) {
        int max = 0;
        size_t idx = 0;
        for(int i = 0; i < nums.size();i++) {
            if (nums[i] > max) {
                max = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};