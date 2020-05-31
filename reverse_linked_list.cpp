using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Iterative solution
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode dummy;
    dummy.next = head;

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* curr_next;

    while (curr != nullptr) {
        curr_next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr_next;
    }

    return prev;
}


