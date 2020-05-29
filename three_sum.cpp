#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> three_sum(vector<int>& nums) {
    vector<vector<int>> res;

    if (nums.size() < 3) {
        return res;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i ++) {
        if ((i == 0) || (i > 0 && nums[i] != nums[i - 1])) {
            int low = i + 1;
            int high = nums.size() - 1;
            int target = -nums[i];

            while (low < high) {
                if (nums[low] + nums[high] == target) {
                    vector<int> templist = {nums[i], nums[low], nums[high]};
                    res.push_back(templist);
                    while (low < high && nums[low] == nums[low + 1]) {
                        low ++;
                    }
                    while (low < high && nums[high] == nums[high - 1]) {
                        high --;
                    }
                    low ++;
                    high --;
                } else if (nums[low] + nums[high] < target) {
                    low ++;
                } else {
                    high --;
                }
            }
        }
    }
    return res;
}