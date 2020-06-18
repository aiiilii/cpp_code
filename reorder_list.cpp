using namespace std;

struct ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ReorderList {
public:
    void reorder_list(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* l1 = head;

        // find the middle node of the list;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // break the list from the middle;
        prev->next = nullptr;

        // reverse the latter half of the list;
        ListNode* l2 = reverse(slow);

        // merge the two lists;
        merge(l1, l2);
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* curr_next = nullptr;

        while (curr != nullptr) {
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {
        while (l2 != nullptr) {
            ListNode* curr_next = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = curr_next;
        }
    }
};
