#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long stickLengths(vector<int>& sticks) {
            int n = sticks.size();
            long long res = 0;
            sort(sticks.begin(), sticks.end());
            int median = sticks[n/2];
            for(int i = 0; i<n; i++) {
                res += abs(median - sticks[i]);
            }
            return res;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> sticks(n);
    for(int i = 0; i<n; i++) cin>>sticks[i];
    Solution ob;
    cout<<ob.stickLengths(sticks)<<endl;
    return 0;
}