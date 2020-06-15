#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> top_k_frequent(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.size() == 0 || k == 0) {
        return res;
    }

    unordered_map<int, int> um;
    for (int num: nums) {
        um[num] ++;
    }

    auto comp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };
    typedef priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> my_priority_queue_t;
    my_priority_queue_t minHeap(comp);

    for (auto entry : um) {
        minHeap.emplace(make_pair(entry.first, entry.second));
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    while (!minHeap.empty()) {
        res.emplace_back(minHeap.top().first);
        minHeap.pop();
    }

    return res;
}
