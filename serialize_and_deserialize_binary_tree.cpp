#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root) {
    if (root == nullptr) {
        return "";
    }
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* deserialize(string data) {
    if (data == "") {
        return nullptr;
    }
    stringstream s(data);
    return deserialize_helper(s);
}

TreeNode* deserialize_helper(stringstream& s) {
    string str;
    getline(s, str, ',');
    if (str == "") {
        return nullptr;
    } else {
        TreeNode* node = new TreeNode(stoi(str));
        node->left = deserialize_helper(s);
        node->right = deserialize_helper(s);
        return node;
    }
}