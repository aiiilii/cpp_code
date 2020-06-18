#include <stack>

using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        left_most_inorder(root);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* topMostNode = st.top();
        st.pop();

        if (topMostNode->right != nullptr) {
            left_most_inorder(topMostNode->right);
        }
        return topMostNode->val;
    }

    /** @return whether we have a next smallest number */
    bool hadNext() {
        return st.size() > 0;
    }

private:
    stack<TreeNode*> st;

    void left_most_inorder(TreeNode* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};
