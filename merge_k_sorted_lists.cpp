#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ListNodeComparator { // priority queue default is maxheap
    bool operator() (const ListNode& l1, const ListNode& l2) {
        return l1.val > l2.val; // minheap
    }
};

ListNode* merge_k_lists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return nullptr;
    }

    priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> pq;

    for (ListNode* node : lists) {
        if (node != nullptr) {
            pq.push(node);
        }
    }

    ListNode dummy;
    ListNode* l3 = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        l3->next = node;
        l3 = l3->next;

        if (node->next != nullptr) {
            pq.push(node->next);
        }
    }

    return dummy.next;
}