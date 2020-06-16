#include <vector>
#include <algorithm>

using namespace std;

class CombinationSum {
public:
    vector<vector<int>> combination_sum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0) {
            return res;
        }

        sort(candidates.begin(), candidates.end());

        vector<int> templist;
        backtracking(res, templist, candidates, target, 0);

        return res;
    }

private:
    void backtracking(vector<vector<int>>& res, vector<int>& templist, vector<int>& candidates, int remain, int start) {
        if (remain < 0) {
            return;
        } else if (remain == 0) {
            res.push_back(templist);
            return;
        } else {
            for (int i = start; i < candidates.size(); i++) {
                templist.push_back(candidates[i]);

                if (remain - candidates[i] < 0) {
                    templist.pop_back();
                    return;
                }

                backtracking(res, templist, candidates, remain - candidates[i], i);
                templist.pop_back();
            }
        }
    }
};
