#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

    if (nums.size() < 2) {
        return res;
    }
    
    unordered_map<int, int> um;
    
    for (int i = 0; i < nums.size(); i++) {
        // auto is used when we do not know what type the um.find returns, in this case auto is int
        auto f = um.find(target - nums[i]);
        // if .find() != .end(), then it means FOUND/Contains!
        if (f != um.end()) {
            res.push_back(f->second); // first is KEY, second is VALUE;
            res.push_back(i);
            break;
        }
        um[nums[i]] = i;
    }

    return res;
}

int main() {
    return 0;
}