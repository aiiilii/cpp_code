#include <vector>
#include <bits/stdc++.h> 

using namespace std;

// Binary search approach
int search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }

    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] < target && nums[high] >= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}


// Using c++ built in function
int search1(vector<int>& nums, int target) {
    auto it = find(nums.begin(), nums.end(), target);
    if (it != nums.end()) { // found
        return distance(nums.begin(), it);
    } else {
        return -1;
    }
}