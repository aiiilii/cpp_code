#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.size() < 2) {
        //return new vector<int>[0];
    }
    
    unordered_map<int, int> map;
    vector<int> res;
    

    for (int i = 0; i < nums.size(); i++) {
        if (map.find(target - nums[i]) != map.end()) {
            
        }
    }

    return res;
}

int main() {
    unordered_map<int, int> map;
    map[3] = 1;
    return 0;
}