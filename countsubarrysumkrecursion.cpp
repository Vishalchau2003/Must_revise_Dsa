#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void count(int i, int n, int &cnt, int sum, vector<int> &arr, int target) {

        // Base Case
        if (i == n) {
            if (sum == target)
                cnt++;
            return;
        }

        // Take the current element
        count(i + 1, n, cnt, sum + arr[i], arr, target);

        // Do not take the current element
        count(i + 1, n, cnt, sum, arr, target);
    }

    int perfectSum(vector<int> &arr, int target) {
        int cnt = 0;
        count(0, arr.size(), cnt, 0, arr, target);
        return cnt;
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    Solution obj;

    cout << "\nNumber of subsets having sum " << target << " = "
         << obj.perfectSum(arr, target) << endl;

    return 0;
}

/*
======================== EXAMPLE ========================

Input:
Enter size of array: 2
Enter array elements: 2 0
Enter target sum: 2

Recursion Tree:

                    (i=0, sum=0)
                   /            \
              Take 2          Not Take
             (i=1,sum=2)      (i=1,sum=0)
             /        \        /        \
        Take 0    Not Take   Take 0   Not Take
       (2,2)       (2,2)      (2,0)     (2,0)

Base Case (i == n):

(2,2) -> Valid subset {2,0}
(2,2) -> Valid subset {2}
(2,0) -> Invalid
(2,0) -> Invalid

Output:
Number of subsets having sum 2 = 2

---------------------------------------------------------

Why NOT write:

if(sum == target){
    cnt++;
    return;
}

Suppose we reach:

(i=1, sum=2)

There is still one element (0) left.

If we return immediately, we miss:

Take 0      -> {2,0}
Not Take 0  -> {2}

Both are different valid subsets.

Hence, we should stop recursion only after
all elements have been processed (i == n).

=========================================================
*/