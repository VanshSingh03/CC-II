class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;

        while (even != nullptr && even->next != nullptr) {

            // Move odd pointer to next odd node
            odd->next = even->next;
            odd = odd->next;

            // Move even pointer to next even node
            even->next = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};