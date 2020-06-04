#include <string>
#include <unordered_map>

using namespace std;

bool is_isomorphic(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> mapS;
    unordered_map<char, int> mapT;

    for (int i = 0; i < s.size(); i++) {
        int indexS;
        int indexT;

        auto itS = mapS.find(s[i]);
        if (itS != mapS.end()) { // contains
            indexS = itS->second;
        } else {
            indexS = -1;
        }

        auto itT = mapT.find(t[i]);
        if (itT != mapT.end()) {
            indexT = itT->second;
        } else {
            indexT = -1;
        }

        if (indexS != indexT) {
            return false;
        }

        mapS[s[i]] = i;
        mapT[t[i]] = i;
    }
    return true;
}