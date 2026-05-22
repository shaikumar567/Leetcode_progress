class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int len = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        k %= len;

        if (k == 0) {
            return head;
        }

        int move = len - k;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (move > 0) {
            prev = curr;
            curr = curr->next;
            move--;
        }

        prev->next = nullptr;
        tail->next = head;

        return curr;
    }
};