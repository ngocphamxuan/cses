#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int ferrisWheel(int n, int x, vector<int> &weights) {
            sort(weights.begin(), weights.end());
            int res = 0;
            int l = 0, r = n-1;
            while(l<r) {
                if(weights[l]<= x - weights[r]) {
                    l++;
                    r--;
                    res++;
                }
                else {
                    r--;
                    res++;
                }
            }
            if(l == r) res++; 
            return res;
        }
};

int main() {
    int n, x;
    cin>>n;
    cin>>x;
    vector<int> weights(n);
    for(int i = 0; i<n; i++) {
        cin>>weights[i];
    }
    Solution ob;
    cout<<ob.ferrisWheel(n, x, weights)<<endl;
}