#include <vector>
#include <string>

using namespace std;

class LetterCombinations {

private:
    vector<string> letter_combinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }

        vector<string> mappings = {
            "0",
            "1",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        string temp;
        backtracking(res, mappings, temp, digits);

        return res;
    }

private:
    void backtracking(vector<string>& res, const vector<string>& mappings, string& temp, const string& digits) {
        if (temp.size() == digits.size()) {
            res.emplace_back(temp);
            return;
        }

        for (char c : mappings[digits[temp.size()] - '0']) { // temp.size() increases as backtracking increases, thus do not need an index variable to track;
            temp.push_back(c);
            backtracking(res, mappings, temp, digits);
            temp.pop_back();
        }
    }
};
