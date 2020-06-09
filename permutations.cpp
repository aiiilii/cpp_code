#include <vector>

using namespace std;

class Permutations {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }

        vector<bool> used;
        used.resize(nums.size(), false);
        vector<int> templist;

        backtracking(res, nums, used, templist);
        return res;
    }

private:
    void backtracking(vector<vector<int>>& res, vector<int>& nums, vector<bool>& used, vector<int>& templist) {
        if (templist.size() == nums.size()) {
            res.push_back(templist);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            templist.push_back(nums[i]);
            used[i] = true;
            backtracking(res, nums, used, templist);
            used[i] = false;
            templist.pop_back();
        }
    }
};
