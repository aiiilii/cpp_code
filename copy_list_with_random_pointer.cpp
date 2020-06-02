#include <unordered_map>

using namespace std;

class Node {
public :
    int val;
    Node* next;
    Node* random;

    Node(int x) {
        val = x;
        next = nullptr;
        random = nullptr;
    }
};

Node* copy_random_list(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    unordered_map<Node*, Node*> um;

    Node dummy(0);
    Node* curr = &dummy;
    Node* newNode = nullptr;

    while (head != nullptr) {
        auto it = um.find(head);
        if (it != um.end()) {
            newNode = it->second; // same as um[head], but better efficiency;
        } else {
            newNode = new Node(head->val);
            um[head] = newNode;
        }

        if (head->random != nullptr) {
            auto f = um.find(head->random);
            if (f != um.end()) {
                newNode->random = f->second; // um[head->random];
            } else {
                newNode->random = new Node(head->random->val);
                um[head->random] = newNode->random;
            }
        }

        curr->next = newNode;
        curr = curr->next;
        head = head->next;
    }

    return dummy.next;
}