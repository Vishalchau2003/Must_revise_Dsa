#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void find(int ind, int n, string &s, vector<string> &path,
              vector<vector<string>> &ans) {

        if (ind == n) {
            ans.push_back(path);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (isPalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i - ind + 1));
                find(i + 1, n, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        find(0, s.size(), s, path, ans);

        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    vector<vector<string>> ans = obj.partition(s);

    for (auto &partition : ans) {
        cout << "[ ";
        for (auto &str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}