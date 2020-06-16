#include <vector>

using namespace std;

class FindFirstAndLastInSortedArray {
public:
    vector<int> search_range(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if (nums.size() == 0) {
            return res;
        }

        res[0] = findLeft(nums, target);
        res[1] = findRight(nums, target);

        return res;
    }

private:
    int findLeft(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                high = mid;
            } else if (target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (nums[low] == target) {
            return low;
        }
        return -1;
    }

    int findRight(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low + 1) / 2; // +1 because using ceiling number for mid to avoid infinite loop;
            if (nums[mid] == target) {
                low = mid;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (nums[high] == target) {
            return high;
        }
        return -1;
    }
};
