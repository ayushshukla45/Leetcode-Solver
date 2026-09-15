class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;

        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {

            // Find next valid character in s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if (skipS > 0) {
                    skipS--;
                    i--;
                }
                else {
                    break;
                }
            }

            // Find next valid character in t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if (skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }

            // Compare valid characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

             //One string has a character, other doesn't
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};