#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int getDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

int main() {
    // 建立範例二元樹：
    //      1
    //     / \
    //    2   3
    //   / 
    //  4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    
    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Max depth of binary tree: " << depth << endl; 

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}