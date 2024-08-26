class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        ListNode* p = list1;
        ListNode* q = list2;
        while (p && q) {
            if (p->val < q->val) {
                tail->next = p;
                p = p->next;
            }

            else {
                tail->next = q;
                q = q->next;
            }
            tail=tail->next;
        }
        if (p) {
            tail->next = p;
        }
        if (q) {
            tail->next = q;
        }
        return dummy.next;
    }
};