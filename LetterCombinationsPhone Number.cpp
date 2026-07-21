#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void find(int idx, int n, string &s, string &digits,
              unordered_map<char, string> &hashmap,
              vector<string> &ans) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }

        char ch = digits[idx];
        string str = hashmap[ch];

        for (int i = 0; i < str.size(); i++) {
            s.push_back(str[i]);
            find(idx + 1, n, s, digits, hashmap, ans);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> hashmap;

        hashmap['2'] = "abc";
        hashmap['3'] = "def";
        hashmap['4'] = "ghi";
        hashmap['5'] = "jkl";
        hashmap['6'] = "mno";
        hashmap['7'] = "pqrs";
        hashmap['8'] = "tuv";
        hashmap['9'] = "wxyz";

        vector<string> ans;
        string s;

        find(0, digits.size(), s, digits, hashmap, ans);

        return ans;
    }
};

int main() {
    string digits;
    cin >> digits;

    Solution obj;
    vector<string> ans = obj.letterCombinations(digits);

    for (string str : ans) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}