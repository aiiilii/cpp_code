#include <vector>

using namespace std;

class ListNode {
public:
    int key;
    int val;
    ListNode* next;
    ListNode() : key(0), val(0), next(nullptr) {}
    ListNode(int key, int val) : key(key), val(val), next(nullptr) {}
    ListNode(int key, int val, ListNode* next) : key(key), val(val), next(next) {}
};

class MyHashMap {
public:

    MyHashMap() :nodes(2069, nullptr) {}

    void put(int key, int value) {
        int idx = get_index(key);
        ListNode* head = nodes[idx];
        ListNode* node = head;

        while (node != nullptr) {
            if (node->key == key) {
                node->val = value;
                return;
            }
            node = node->next;
        }
        ListNode* newNode = new ListNode(key, value);
        newNode->next = head;
        nodes[idx] = newNode;
    }

    int get(int key) {
        int idx = get_index(key);
        ListNode* node = nodes[idx];

        while (node != nullptr) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }
        return -1;
    }

    void remove(int key) {
        int idx = get_index(key);
        ListNode* node = nodes[idx];
        ListNode* prev = nullptr;

        while (node != nullptr) {
            if (node->key == key) {
                if (prev != nullptr) { // if the found is not the first one, then skip the current node and connect prev with node->next;
                    prev->next = node->next;
                } else { // if the found is the first one, then move nodes[idx] to node->next, but prev does not change, prev still is nullptr;
                    nodes[idx] = node->next;
                }
                return;
            }
            prev = node;
            node = node->next;
        }
    }

    int get_index(int key) {
        return key % 2069;
    }

private:
    vector<ListNode*> nodes;
};
