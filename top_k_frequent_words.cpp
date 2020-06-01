#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> top_k_frequent(vector<string>& words, int k) {
    vector<string> res;
    if (words.size() == 0 || k == 0) {
        return res;
    }

    unordered_map<string, int> um;

    for (string& word : words) {
        um[word] ++;
    }

    auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second || (a.second == b.second && a.first < b.first); // minheap, but if frequencies equal, then maxheap for the reverse alphabetical order;
    };
    typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> my_priority_queue_t;
    my_priority_queue_t minHeap(comp);

    for (auto entry : um) {
        minHeap.emplace(entry.first, entry.second);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    while (!minHeap.empty()) {
        res.insert(res.begin(), minHeap.top().first); // insert bottom of the minheap to the front of the res;
        minHeap.pop();
    }

    return res;
}