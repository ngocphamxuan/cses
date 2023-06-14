#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubArraySum(vector<long long> &nums)
    {
        int n = nums.size();
        vector<long long> dp(n);
        dp[0] = nums[0];
        long long res = dp[0];
        for(int i = 1; i<n; i++) {
            dp[i] = max( dp[i-1] + nums[i] , nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i = 0; i<n; i++) cin>>nums[i];
    Solution ob;
    cout<<ob.maxSubArraySum(nums)<<endl;
}