#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> subdomain_visits(vector<string>& cpdomains) {
    unordered_map<string, int> um;

    for (string& cp : cpdomains) {
        auto loc = cp.find(" ");
        int n = stoi(cp.substr(0, loc));
        string s = cp.substr(loc + 1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                string d = s.substr(i + 1);
                um[d] += n;
            }
        }
        um[s] += n;
    }

    vector<string> res;
    for (auto entry : um) {
        res.push_back(to_string(entry.second) + " " + entry.first);
    }

    return res;
}
