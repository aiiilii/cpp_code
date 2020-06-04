#include <vector>
#include <unordered_map>

using namespace std;

// Hashmap approach - saving the presum into map
int subarray_sum1(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    
    if (nums.size() == 0) {
        return count;
    }
    
    unordered_map<int, int> um;
    um.emplace(0, 1);
    
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        
        auto it = um.find(sum - k);
        if (it != um.end()) {
            count += it->second;
        }
        um[sum]++;
    }
    return count;
}



// Culmulative sum approach - time limit exceeded
int subarray_sum(vector<int>& nums, int k) {
    int count = 0;
    vector<int> sum(nums.size() + 1);
    sum[0] = 0;
    
    for (int i = 1; i <= nums.size(); i++) {
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    
    for (int start = 0; start < nums.size(); start++) {
        for (int end = start + 1; end <= nums.size(); end ++) {
            if (sum[end] - sum[start] == k) {
                count ++;
            }
        }
    }
    return count;
}