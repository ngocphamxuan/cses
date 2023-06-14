#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long missingCoinSum(vector<int>& coins) {
            long long sum = 0;
            sort(coins.begin(), coins.end());
            for(int i = 0; i<coins.size(); i++) {
                // nếu số coin hiện tại mà k tới được sum + 1 thì in kết quả
                if(coins[i] > sum + 1) break;
                sum += coins[i];
            }
            return sum + 1;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int i = 0; i<n; i++) cin>>coins[i];
    Solution ob;
    cout<<ob.missingCoinSum(coins)<<endl;
    return 0;
}