#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxCustomer(int n, vector<pair<int, int>>& timeArrivals) {
            int res = 0, curr = 0;
            vector<pair<int, int>> events;
            for(auto it: timeArrivals) {
                events.push_back({it.first, 0});
                events.push_back({it.second, 1});
            }
            sort(events.begin(), events.end());
            for(auto event: events) {
                if(event.second == 1) curr--;
                else curr++;
                res = max(curr, res);
            }
            // 2 3 4 
            //    
            // 5 4 6
            return res;
        }
};

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> timeArrivals;
    for(int i = 0; i<n; i++) {
        int first, second;
        cin>>first>>second;
        timeArrivals.push_back({first, second});
    }
    Solution ob;
    cout<<ob.maxCustomer(n, timeArrivals)<<endl;

}