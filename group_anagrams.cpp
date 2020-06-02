#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> group_anagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> um;

    for (string& str : strs) {
        string sortedstr = str;
        sort(sortedstr.begin(), sortedstr.end());

        vector<string> first = um[sortedstr];
        first.push_back(str);
        um[sortedstr] = first;
    }

    vector<vector<string>> res;

    for (auto i = um.begin(); i != um.end(); i++) {
        res.push_back(i->second);
    }

    return res;
}