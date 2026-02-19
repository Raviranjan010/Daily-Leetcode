Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 

Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:

Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.




class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0;
        vector<int>v;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            int zero = 0, one = 0;
            if(s[i] == '0') {
                while(j < s.size() && s[j] == '0') {
                    zero++;
                    j++;
                }
            }
            else {
                while(j < s.size() && s[j] == '1') {
                    one++;
                    j++;
                }
            }
            i = j;
            v.push_back(max(one, zero));
        }
        for(int i = 0; i < v.size()-1; i++) {
            res = res + min(v[i], v[i+1]);
        }
        return res;
    }
};
