#include <vector>
#include <string>

using namespace std;

class Solution {

public: 
    vector<int> char_map;

    Solution() : char_map(26) {}

    bool is_alien_sorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            char_map[order[i] - 'a'] = i;
        }

        for (int i = 1; i < words.size(); i++) {
            if (compare(words[i - 1], words[i]) > 0) {
                return false;
            }
        }
        return true;
    }


private:

    int compare(string& word1, string& word2) {
        int i = 0;
        int j = 0;
        int char_compare_val = 0;

        while (i < word1.size() && j < word2.size() && char_compare_val == 0) {
            char_compare_val = char_map[word1[i] - 'a'] - char_map[word2[j] - 'a'];
            
            i ++;
            j ++;
        }

        if (char_compare_val == 0) {
            return word1.size() - word2.size();
        } else {
            return char_compare_val;
        }
    }
};
