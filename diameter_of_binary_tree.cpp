#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class DiameterOfBinaryTree {
public:
    int diameter_of_binary_tree(TreeNode* root) {
        max_depth(root);
        return currMax;
    }

private:
    int currMax = 0;

    int max_depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = max_depth(root->left);
        int right = max_depth(root->right);

        currMax = max(currMax, left + right);

        return max(left, right) + 1;
    }
};
