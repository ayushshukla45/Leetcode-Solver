class Solution {
public:

    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool direction = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // slow must have the same direction
                if ((nums[slow] > 0) != direction) {
                    break;
                }

                int slowNext = nextIndex(nums, slow);

                // self-loop is not allowed
                if (slowNext == slow) {
                    break;
                }

                // fast first step
                if ((nums[fast] > 0) != direction) {
                    break;
                }

                int fastNext = nextIndex(nums, fast);

                // self-loop
                if (fastNext == fast) {
                    break;
                }

                // fast second step must also have same direction
                if ((nums[fastNext] > 0) != direction) {
                    break;
                }

                int fastNextNext = nextIndex(nums, fastNext);

                // IMPORTANT: reject self-loop on second fast step
                if (fastNextNext == fastNext) {
                    break;
                }

                slow = slowNext;
                fast = fastNextNext;

                if (slow == fast) {
                    return true;
                }
            }
        }

        return false;
    }
};