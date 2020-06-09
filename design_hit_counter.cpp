#include <vector>

using namespace std;

class HitCounter{
public:
    
    HitCounter() : times(300), hits(300) {}

    void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index] ++;
        }
    }

    int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) {
                total += hits[i];
            }
        }
        return total;
    }

private:
    vector<int> times;
    vector<int> hits;

};
