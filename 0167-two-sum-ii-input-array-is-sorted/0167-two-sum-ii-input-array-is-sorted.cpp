class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int  slow =0;
        int fast = numbers.size() -1;

        while ( slow < fast){
            int sum = numbers[slow] + numbers[fast];

            if ( sum == target){
                return {slow +1  , fast +1};
            }
            else if ( sum < target) {
                slow++;
            }
            else
            fast--;
        }
        return {};
    }
};