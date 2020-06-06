#include <vector>
#include <queue>

using namespace std;

int find_kth_largest(vector<int>& nums, int k) {
    auto comp = [](const int a, const int b) {
        return a > b;	
    };
    typedef priority_queue<int, vector<int>, decltype(comp)> my_priority_queue_t;
    my_priority_queue_t minheap(comp);

    for (int num : nums) {
        minheap.emplace(num);
        if (minheap.size() > k) {
            minheap.pop();
        }
    } 

    return minheap.top();
}
