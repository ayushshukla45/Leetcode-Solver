class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // Step 1: Find the meeting point inside the cycle
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if (slow == fast) {
                break;
            }
        }

        // Step 2: Find the starting point of the cycle
        slow = 0;

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};