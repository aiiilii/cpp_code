#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> k_closest(vector<vector<int>>& points, int K) {
    vector<vector<int>> res;
    if (points.size() == 0 || K == 0) {
        return res;
    }

    auto comp = [](const vector<int>& a, const vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]); // default maxHeap priority queue
    };
    typedef priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> my_priority_queue_t;
    my_priority_queue_t maxHeap(comp);

    for (auto point : points) {
        maxHeap.emplace(point);
        if (maxHeap.size() > K) {
            maxHeap.pop();
        }
    }

    while (!maxHeap.empty()){
        res.emplace_back(maxHeap.top());
        maxHeap.pop();
    }
    return res;
}

