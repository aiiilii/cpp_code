#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class LowestCommonAncesterOfBinaryTree {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            return p;
        } else if (root == q) {
            return q;
        }

        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap.emplace(root, nullptr);

        queue<TreeNode*> que;
        que.emplace(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            
            if (node->left != nullptr) {
                parentMap.emplace(node->left, node);
                que.emplace(node->left);
            }
            if (node->right != nullptr) {
                parentMap.emplace(node->right, node);
                que.emplace(node->right);
            }

            que.pop();
        }

        unordered_set<TreeNode*> ancestors;

        while (p != nullptr) {
            ancestors.emplace(p);
            p = parentMap[p];
        }
        while (ancestors.find(q) == ancestors.end()) { // does not contain;
            q = parentMap[q];
        }

        return q;
    }
};
