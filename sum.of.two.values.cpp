#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void SumOfTwoValues(int target, vector<int> &nums)
    {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (dict.count(complement) > 0)
            {
                cout << dict[complement] << " " << i + 1 << endl;
                return;
            }
            dict[nums[i]] = i + 1;
        }
        cout << "IMPOSSIBLE" << endl;
        return;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    map<int, int> dict;
    // unordered_map<int, int> dict

    // unordered_map sử dụng hashtable để map, khi các key khác nhau quá nhiều, bộ nhớ không đủ
    // worst case time to search: O(n)
    // map sử dụng rebalance tree, search time luôn là O(log(n))
    // ở đây, nếu sử dụng map => O(nlog(n))
    // nếu sử dụng unordered_map => O(n) khi array nhỏ, O(n^2) khi số phần tử khác nhau tăng lên
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
        int complement = target - nums[i];
        if (dict.count(complement) > 0)
        {
            cout << dict[complement] << " " << i + 1 << endl;
            return 0;
        }
        dict[nums[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}