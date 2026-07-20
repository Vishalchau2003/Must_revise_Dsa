#include <bits/stdc++.h>
using namespace std;

void solve(int ind, int target, vector<int> &arr,
           vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (arr[i] > target)
            continue;

        ds.push_back(arr[i]);
        solve(i, target - arr[i], arr, ds, ans); // Reuse allowed
        ds.pop_back();
    }
}

int main()
{
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> target;

    vector<vector<int>> ans;
    vector<int> ds;

    solve(0, target, arr, ds, ans);

    for (auto &v : ans)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}