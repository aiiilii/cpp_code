#include <vector>
#include <algorithm>

using namespace std;

bool can_attend_meetings(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
        return true;
    }

    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) -> bool {
        return a[0] < b[0];
    });

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }
    return true;
}