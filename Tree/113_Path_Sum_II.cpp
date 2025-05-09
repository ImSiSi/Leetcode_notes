#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void traversal(TreeNode* root, vector<vector<int>>& result, int targetSum, vector<int> list) {
        list.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            int sum = 0;
            for (int val : list) {
                sum += val;
            }
            if (sum == targetSum)
                result.push_back(list);
            return;
        }
        if (root->left) {
            traversal(root->left, result, targetSum, list);
        }
        if (root->right) {
            traversal(root->right, result, targetSum, list);
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return {};
        vector<int> list;
        vector<vector<int>> result;
        traversal(root, result, targetSum, list);
        return result;
    }
};

int main() {
    // 建立範例二元樹：
    //      5
    //     / \
    //    4   8
    //   /   / \
    //  11  13  4
    // /  \      \
    //7    2      1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int target = 22;
    Solution sol;
    vector<vector<int>> paths = sol.pathSum(root, target);

    cout << "Paths with sum " << target << ":\n";
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}