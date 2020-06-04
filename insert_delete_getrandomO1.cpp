#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {

public:

    RandomizedSet() {

    }

    // Inserts a value to the set. Returns true if the set did not already contain the specified element.
    bool insert(int val) {
        auto it = um.find(val);
        if (it != um.end()) { // contains
            return false;
        } else { // did not find "it"
            nums.push_back(val);
            um[val] = nums.size() - 1;
            return true;
        }
    }

    // Removes a value from the set. Returns true if the set contained the specified element.
    bool remove(int val) {
        auto it = um.find(val);
        if (it == um.end()) {
            return false;
        }
        int index = it->second;
        if (index < nums.size() - 1) {
            int last_val = nums[nums.size() - 1]; // save the last element
            nums[index] = last_val; // override the index element to be the last element
            um[last_val] = index; // override and connect the last element with index in the map;
        }
        um.erase(val);
        nums.pop_back();
        return true;
    }

    // Get a random element from the set.
    int get_random() {
        return nums[rand() % nums.size()]; // get a zero-based number from [0 - nums.size()-1];
    }

private:

    vector<int> nums;
    unordered_map<int, int> um;

};