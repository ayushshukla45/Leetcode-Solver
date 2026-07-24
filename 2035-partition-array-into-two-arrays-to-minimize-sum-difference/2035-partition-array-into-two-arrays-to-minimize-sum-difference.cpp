class Solution {
public:

    int minimumDifference(vector<int>& nums)
    {
        int n = nums.size() / 2;
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        vector<vector<int>> left(n + 1);
        vector<vector<int>> right(n + 1);

        for(int mask = 0; mask < (1 << n); mask++)
        {
            int count = 0;
            int leftSum = 0;
            int rightSum = 0;

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    count++;

                    leftSum += nums[i];

                    rightSum += nums[i + n];
                }
            }

            left[count].push_back(leftSum);

            right[count].push_back(rightSum);
        }

        for(int i = 0; i <= n; i++)
        {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        for(int count = 0; count <= n; count++)
        {
            for(int leftSum : left[count])
            {
                int remaining = n - count;

                int target = totalSum / 2 - leftSum;

                auto it = lower_bound(
                    right[remaining].begin(),
                    right[remaining].end(),
                    target
                );

                if(it != right[remaining].end())
                {
                    int sum = leftSum + *it;

                    ans = min(
                        ans,
                        abs(totalSum - 2 * sum)
                    );
                }

                if(it != right[remaining].begin())
                {
                    it--;

                    int sum = leftSum + *it;

                    ans = min(
                        ans,
                        abs(totalSum - 2 * sum)
                    );
                }
            }
        }

        return ans;
    }
};