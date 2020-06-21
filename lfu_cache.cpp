#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
public:
    int key;
    int val;
    int freq;
    int timestamp;
    Node() : key(-1), val(-1), freq(0), timestamp(-1) {}
    Node(int key, int val, int timestamp) : key(key), val(val), freq(1), timestamp(timestamp) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        Node* dummy = new Node();
        pq.push_back(dummy);
        ts = 0;
    }

    int get(int key) {
        if (!um.count(key)) {
            return -1;
        }
        int index = um[key];
        int val = pq[index]->val;

        pq[index]->freq++;
        pq[index]->timestamp = ++ts;

        sink(index);
        return val;
    }

    void put(int key, int value) {
        if (maxCapacity == 0) {
            return;
        }

        if (um.count(key)) { // .count checks for the count the number of elements present, thus checks if the elements exists --> contains
            int index = um[key];
            pq[index]->val = value;
            get(key);
        } else {
            if (pq.size() - 1 == maxCapacity) {
                int oldKey = pq[1]->key;
                um.erase(oldKey);
                Node* newNode = new Node(key, value, ++ts);
                pq[1] = newNode;
                um[key] = 1;
                sink(1);
            } else {
                Node* newNode = new Node(key, value, ++ts);
                pq.push_back(newNode);
                um[key] = pq.size() - 1;
                swim(pq.size() - 1);
            }
        }
    }

private:
    vector<Node*> pq;
    unordered_map<int, int> um;
    int maxCapacity;
    int ts;

    void sink(int index) {
        int left = 2 * index;
        int right = 2 * index + 1;
        int target = index;

        if (left < pq.size() && pq[left]->freq <= pq[target]->freq) {
            target = left;
        }

        if (right < pq.size()) {
            if (pq[right]->freq < pq[target]->freq || (pq[right]->freq == pq[target]->freq && pq[right]->timestamp < pq[target]->timestamp)) {
                target = right;
            }
        }

        if (target != index) {
            myswap(target, index);
            sink(target);
        }
    }

    void swim(int index) {
        int par = index / 2;
        while (par > 0 && pq[par]->freq > pq[index]->freq) {
            myswap(par, index);
            index = par;
            par /= 2;
        }
    }

    void myswap(int id1, int id2) {
        swap(pq[id1], pq[id2]);
        um[pq[id1]->key] = id1;
        um[pq[id2]->key] = id2;
    }
};
