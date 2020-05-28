#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

    if (nums.size() < 2) {
        return res;
    }
    
    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end()) {
            res.push_back(map[target - nums[i]]);
            res.push_back(i);
            break;
        }
        map[nums[i]] = i;
    }

    return res;
}

int main() {
    return 0;
}