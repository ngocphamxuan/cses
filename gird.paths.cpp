#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
class Solution
{
public:
    int countPaths(string &description)
    {
        int n = description.length();
        int dp[7][7];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        // dp[i][j] = số đường đi 0, 0 tới điểm (i, j)
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
        int col = 0, row = 0;
        for (auto move : description)
        {
            if (move == 'D')
                row++;
            if (move == 'U')
                row--;
            if (move == 'L')
                col--;
            if (move == 'R')
                col++;
            if (row < 0 || row >= 7 || col < 0 || col >= 7)
                return 0;
        }
        return dp[row][col];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string description;
    cin >> description;
    Solution ob;
    cout << ob.countPaths(description) << endl;
    return 0;
}