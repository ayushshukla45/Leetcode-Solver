/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Helper function to reverse a linked list
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find middle using slow-fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;  // key fix for even length

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Reverse second half
        ListNode* chotahead = rev(slow->next);
        // slow->next = NULL; // optional split for clarity

        // Step 3: Compare both halves
        ListNode* left = head;
        ListNode* right = chotahead;

        while (right != NULL) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
