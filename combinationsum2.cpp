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
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        solve(i + 1, target - arr[i], arr, ds, ans); // Use once
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

    sort(arr.begin(), arr.end());

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