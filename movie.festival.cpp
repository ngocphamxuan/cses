#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int movieFestival(int n, vector<pair<int, int>>& movies) {
            int res = 0;
            sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b) {
                if(a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            });
            // 5, 8 , 9
            int lastEnd = 0;
            for(auto movie: movies) {
                if(movie.first >= lastEnd) {
                    res++;
                    lastEnd = movie.second;
                }
            }
            // 3, 5, 9
            return res;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> movies;
    for(int i = 0; i<n; i++) {
        int begin, end;
        cin>>begin>>end;
        movies.push_back({begin, end});
    }
    Solution ob;
    cout<<ob.movieFestival(n, movies)<<endl;
}