#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    string the_word;
    TrieNode() : children(vector<TrieNode*>(26, nullptr)) {} //26 is the size, nullptr is placeholder
};

class Trie {
public:
    TrieNode* get_root() {
        return root;
    }

    Trie(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            add_word(word);
        }
    }

    void add_word(const string& word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (temp->children[c - 'a'] == nullptr) {
                temp->children[c - 'a'] = new TrieNode();
            }
            temp = temp->children[c - 'a'];
        }
        temp->the_word = word;
    }

private:
    TrieNode* root;
};

class WordSearchII {
public:
    vector<string> find_words(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->get_root();

        vector<string> res;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* temp, vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || temp->children[c - 'a'] == nullptr) {
            return;
        }

        temp = temp->children[c - 'a'];
        if (temp->the_word.size() != 0) {
            res.push_back(temp->the_word);
            temp->the_word = "";
        }

        board[i][j] = '#';

        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++) {
            if (i + dx[k] >= 0 && i + dx[k] < board.size() && j + dy[k] >= 0 && j + dy[k] < board[i].size()) {
                dfs(board, i + dx[k], j + dy[k], temp, res);
            }
        }

        board[i][j] = c;
    }
};
