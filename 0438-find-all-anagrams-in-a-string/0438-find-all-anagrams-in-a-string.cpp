
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) {
            return ans;
        }

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        for (int i = 0; i < m; i++) {
            pFreq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }

        if (pFreq == windowFreq) {
            ans.push_back(0);
        }

        for (int right = m; right < n; right++) {
            windowFreq[s[right] - 'a']++;

            windowFreq[s[right - m] - 'a']--;

            if (pFreq == windowFreq) {
                ans.push_back(right - m + 1);
            }
        }

        return ans;
    }
};
