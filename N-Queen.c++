
class Solution {
public:
    int ans = 0;

    void backtrack(int n, int row, int cols, int diag1, int diag2) {
        if (row == n) {
            ans++;
            return;
        }

        int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

        while (available) {
            int bit = available & -available;
            available -= bit;

            backtrack(n, row + 1, cols | bit, (diag1 | bit) << 1,
                      (diag2 | bit) >> 1);
        }
    }

    int totalNQueens(int n) {
        ans = 0;
        backtrack(n, 0, 0, 0, 0);
        return ans;
    }
};
