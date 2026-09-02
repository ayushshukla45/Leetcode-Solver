class Solution {
public:
    vector<int> sortedSquares(vector<int>& main) {

        vector<int> a;
        vector<int> b;

        // Separate negative and positive numbers
        for (int i = 0; i < main.size(); i++) {

            if (main[i] < 0) {
                a.push_back(main[i] * main[i]);
            }
            else {
                b.push_back(main[i] * main[i]);
            }
        }
            
        // Reverse negative squares
        reverse(a.begin(), a.end());

        // Merge a and b
        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size()) {

            if (a[i] < b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
         
        
        // Remaining elements of a
        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        // Remaining elements of b
        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};