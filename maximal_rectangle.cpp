Easy Maximal Rectangle in a Binary Matrix (C++)

Ravi-Ranjan
50 Days Badge 2025
0
a few seconds ago
C++
Intuition
The idea is to treat each row as the base of a histogram.
For every row, we build heights of consecutive 1s column-wise.
Once the histogram is ready, we try to find the largest rectangle of 1s ending at that row.

Instead of checking the whole matrix repeatedly, we reuse previous row information, which makes the solution efficient.

Approach
Maintain a height array h[] where:

h[j] = number of consecutive '1's above (including current row) in column j.

For each row:

Update h[] based on whether the current cell is '1' or '0'.

For every column j, move leftwards:

Track the minimum height so far.

Compute area = minHeight × width.

Update the maximum area.

Return the maximum rectangle area found.

This effectively checks all possible rectangles formed using histogram logic.

Complexity
⋅TimeComplexity:

O(rows x cols^2)
(For each row, we scan columns and expand left)
⋅SpaceComplexity:

O(cols)

(Height array)

Code
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> h(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1')
                    h[j] += 1;
                else
                    h[j] = 0;}
            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == '0')
                    continue;
                int minHeight = INT_MAX;
                for (int k = j; k >= 0; k--) {
                    minHeight = min(minHeight, h[k]);
                    ans = max(ans, minHeight * (j - k + 1)); 
                }
            }}
        return ans;
    }
};
