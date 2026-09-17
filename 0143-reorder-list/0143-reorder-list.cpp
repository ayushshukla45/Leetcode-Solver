class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is the last node of the first half
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        second = prev;

        // Step 3: Merge the two halves
        ListNode* first = head;

        while (second != nullptr) {
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};