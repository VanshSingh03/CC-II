class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Remove 0 or 1
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenHead = even;

        // Rearrange Nodes
        while (even != nullptr && even->next != nullptr) {

            // Odd Nodes
            odd->next = even->next;
            odd = odd->next;

            // Even Nodes
            even->next = odd->next;
            even = even->next;
        }

        // Rearrange Nodes
        odd->next = evenHead;

        return head;
    }
};