class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = -1;
        int right = -1;

        int maxSeen = nums[0];

        // Find the right boundary
        for (int i = 1; i < n; i++) {
            if (nums[i] < maxSeen) {
                right = i;
            } else {
                maxSeen = nums[i];
            }
        }

        // If right is still -1, array is already sorted
        if (right == -1) {
            return 0;
        }

        int minSeen = nums[n - 1];

        // Find the left boundary
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minSeen) {
                left = i;
            } else {
                minSeen = nums[i];
            }
        }

        return right - left + 1;
    }
};