#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();
 
    // Constructor initializes a single integer.
    NestedInteger(int value);
 
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
 
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
 
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
 
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger>& getList() const;
};

class NestedListWeightSum {
public:
    int depth_sum(vector<NestedInteger>& nestedList) {
        return depth_sum_helper(nestedList, 1);
    }

private:
    int depth_sum_helper(vector<NestedInteger>& list, int depth) {
        int sum = 0;
        for (NestedInteger n : list) {
            if (n.isInteger()) {
                sum += n.getInteger() * depth;
            } else {
                sum += depth_sum_helper(n.getList(), depth + 1);
            }
        }
        return sum;
    }
};
