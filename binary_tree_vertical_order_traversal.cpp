#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

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

class BSTVerticalOrder {
public:
    vector<vector<int>> vertical_order(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        unordered_map<int, vector<int>> um;
        queue<TreeNode*> q;
        queue<int> cols;

        q.emplace(root);
        cols.emplace(0);

        int min = 0;
        int max = 0;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            int col = cols.front();
            cols.pop();

            um[col].push_back(node->val);

            if (node->left != nullptr) {
                q.emplace(node->left);
                cols.emplace(col - 1);
                min = std::min(min, col - 1);
            }

            if (node->right != nullptr) {
                q.emplace(node->right);
                cols.emplace(col + 1);
                max = std::max(max, col + 1);
            }
        }
        
        for (int i = min; i <= max; i++) {
            res.push_back(um[i]);
        }

        return res;
    }
};
