using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class ReverseK {
public:
    ListNode* reverse_k_group(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }

        ListNode dummy;
        dummy.next = head;
        ListNode* begin = &dummy;

        int i = 0;
        while (head != nullptr) {
            i++;
            if (i % k == 0) { // in this case, i == k
                begin = reverse(begin, head->next);
                head = begin->next; // jump to the next section
            } else {
                head = head->next;
            }
        }
        return dummy.next;
    }

private:
    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* curr = begin->next;
        ListNode* prev = begin;
        ListNode* first = curr;
        ListNode* curr_next = nullptr;

        while (curr != end) {
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        begin->next = prev; // prev is the new head after reversing;
        first->next = curr;

        return first; // first is the last node after reversing, returning it will be the new prev;
    }
};
