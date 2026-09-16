class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = -1;
        int right = -1;

        // Find the first position from the left
        // where the array is decreasing
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                left = i;
                break;
            }
        }   

        // Already sorted
        if (left == -1) {
            return 0;
        }

        // Find the last position from the right
        // where the array is decreasing
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] > nums[i]) {
                right = i;
                break;
            }
        }

        // Find minimum and maximum in the unsorted part
        int minimum = nums[left];
        int maximum = nums[left];

        for (int i = left; i <= right; i++) {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }

        // Expand left if needed
        while (left > 0 && nums[left - 1] > minimum) {
            left--;
        }

        // Expand right if needed
        while (right < n - 1 && nums[right + 1] < maximum) {
            right++;
        }

        return right - left + 1;
    }
};