#include <vector>
#include <string>

using namespace std;

/**
 * For each letter encountered, process the last occurrence of that letter, extending the current partition [anchor, j] appropriately.
 * We need an array last[char] -> index of S where char occurs last. Then, let anchor and j be the start and end of the current partition. 
*/
vector<int> partition_labels(string S) {
    vector<int> last;
    last.resize(26);

    for (int i = 0; i < S.size(); i++) {
        last[S[i] - 'a'] = i;
    }

    int j = 0;
    int anchor = 0;
    vector<int> res;

    for (int i = 0; i < S.size(); i++) {
        j = max(j, last[S[i] - 'a']); // If we are at a label that occurs last at some index after j, we'll extend the partition j = last[c].
        if (i == j) { // If we are at the end of the partition (i == j) then we'll append a partition size to our answer, and set the start of our new partition to i+1.
            res.push_back(i - anchor + 1);
            anchor = i + 1;
        }
    }

    return res;
}
