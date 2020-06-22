#include <vector>
#include <unordered_map>

using namespace std;


/** 
 * Maintain a min-PriorityQueue with the least frequently used element at the top. 
 * When frequency changes, then we need to re-heapify. Native STL PriorityQueue does not support this so we write our own.
 * Index Priority Queue - both a Prioriity Queue and a Hash Map
 * 
 * When we evict an element, but multiple elements may have the same (minimum) frequency, then we need to evict the least recently used element.
 * To handle this, maintain a timestamp variable for each element in the LFU, which indicates the latest timestamp when we access it.
 * In our PQ, when two elements have the same frequency, the least recently used one will be close to the root.
*/

struct Node {
public:
    int key;
    int val;
    int freq;
    int timestamp; // the latest timestamp when this element is accessed;
    Node() : key(-1), val(-1), freq(0), timestamp(-1) {}
    Node(int key, int val, int timestamp) : key(key), val(val), freq(1), timestamp(timestamp) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        Node* dummy = new Node();
        pq.push_back(dummy); // the pq start from pq[1];
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
    vector<Node*> pq; // A PriorityQueue, with the least usage frequency and least recently used element at the top;
    unordered_map<int, int> um; // A mapping from the key of the element to its index in the PriorityQueue
    int maxCapacity;
    int ts; // timestamp: indicate the timestamp of the latest operation of an element. 

    /** 
     * Recursively sink a node in priority queue. A node will be sinked when its frequency is larger than any of its children nodes, 
     * or the node has the same frequency with a child, but it is recently updated.
    */
    void sink(int index) {
        int left = 2 * index;
        int right = 2 * index + 1;
        int target = index;

        // If the left child has the same frequency, we probably need to swap the parent node and the child node, 
        // because the parent node is recently accessed, and the left child node was accessed at an older time stamp.
        if (left < pq.size() && pq[left]->freq <= pq[target]->freq) {
            target = left;
        }

        // If right child has the same frequency and an older timestamp, we must swap it.
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

    /** 
     * Recursively swim a node in priority queue. A node will be swimmed, when its frequency is less than its parent node.
     * If the node has the same frequency with its parent, it is not needed to be swimmed, because it is recently accessed.
    */
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
