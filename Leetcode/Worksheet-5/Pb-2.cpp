class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* oddHead = nullptr;
        ListNode* oddTail = nullptr;

        ListNode* evenHead = nullptr;
        ListNode* evenTail = nullptr;

        ListNode* current = head;
        int position = 1;

        while (current != nullptr) {

            if (position % 2 == 1) {

                if (oddHead == nullptr) {
                    oddHead = current;
                    oddTail = current;
                } else {
                    oddTail->next = current;
                    oddTail = current;
                }

            } else {

                if (evenHead == nullptr) {
                    evenHead = current;
                    evenTail = current;
                } else {
                    evenTail->next = current;
                    evenTail = current;
                }
            }

            current = current->next;
            position++;
        }

        oddTail->next = evenHead;

        evenTail->next = nullptr;

        return oddHead;
    }
};