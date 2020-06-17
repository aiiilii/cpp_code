#include <vector>

using namespace std;

void move_zeroes(vector<int>& nums) {
    if (nums.size() == 0) {
        return;
    }

    int i = -1;
    int j = 0;

    while (j < nums.size()) {
        if (nums[j] != 0) {
            i++;
            // swap
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        j++;
    }
}
