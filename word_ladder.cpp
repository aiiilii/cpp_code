#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int ladder_length(string beginWord, string endWord, vector<string>& wordList) {
    if (wordList.size() == 0) {
        return 0;
    }

    unordered_set<string> dict;
    for (auto word : wordList) {
        dict.emplace(word);
    }
    auto it = dict.find(endWord);
    if (it == dict.end()) {
        return 0;
    }

    unordered_set<string> begin;
    unordered_set<string> end;

    begin.emplace(beginWord);
    end.emplace(endWord);
    dict.erase(beginWord);
    dict.erase(endWord);

    int step = 2;

    while (!begin.empty()) {
        unordered_set<string> temp;
        for (string word : begin) {
            for (int i = 0; i < word.size(); i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    auto f = end.find(word);
                    if (f != end.end()) {
                        return step;
                    }
                    auto f2 = dict.find(word);
                    if (f2 != dict.end()) {
                        temp.emplace(word);
                        dict.erase(word);
                    }
                }
                word[i] = orig;
            }
        }
        step++;
        if (temp.size() <= end.size()) {
            begin = temp;
        } else {
            begin = end;
            end = temp;
        }
    }
    return 0;
}
