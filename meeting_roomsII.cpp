#include <vector>
#include <algorithm>

using namespace std;

int min_meeting_rooms(vector<vector<int>>& intervals) {
    if (intervals.size() == 0) {
        return 0;
    }

    vector<int> start;
    vector<int> end;

    for (int i = 0; i < intervals.size(); i++) {
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int res = 0;
    int endPoint = 0;

    for (int i = 0; i < start.size(); i++) {
        if (start[i] < end[endPoint]) {
            res ++;
        } else {
            endPoint ++;
        }
    }

    return res;
}