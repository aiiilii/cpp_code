#include <string>
#include<unordered_map>
#include <map>

using namespace std;

class TimeMap {

public:
    
    unordered_map<string, map<int, string>> um;

    TimeMap() {

    }

    // Time - single operation O(n), total O(n)
    // Space - O(n), assuming every {timestamp, value} is unique
    void set(string key, string value, int timestamp) {
        um[key].insert({timestamp, value});
    }

    // Time - single operation O(log n), total O(n log n)
    string get(string key, int timestamp) {
        auto it = um[key].upper_bound(timestamp);
        if (it == um[key].begin()) {
            return "";
        } else {
            return prev(it)->second;
        }
    }
};
