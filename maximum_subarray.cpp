#include <vector>

using namespace std;

int max_subarray(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }

    int mx = nums[0];
    int sum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = max(nums[i], sum + nums[i]);
        mx = max(mx, sum);
    }

    return mx;
}