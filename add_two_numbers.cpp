using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* add_two_numbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

    ListNode dummy;
    ListNode* l3 = &dummy; // l3 is a pointer to ListNode, it points to the address of dummy;

    int carry = 0;

    while (l1 && l2) {
        int digitVal = l1->val + l2->val + carry;
        l3->next = new ListNode(digitVal % 10);
        l3 = l3->next;
        carry = digitVal / 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        int digitVal = l1->val + carry;
        l3->next = new ListNode(digitVal % 10);
        l3 = l3->next;
        carry = digitVal / 10;
        l1 = l1->next;
    }

    while (l2) {
        int digitVal = l2->val + carry;
        l3->next = new ListNode(digitVal % 10);
        l3 = l3->next;
        carry = digitVal / 10;
        l2 = l2->next;
    }

    if (carry != 0) {
        l3->next = new ListNode(carry);
    }

    return dummy.next; // dummy.next is the same as (&dummy)->next or (*(&dummy)).next;
}
