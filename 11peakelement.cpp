#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;

    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Peak found
        if (nums[mid] > nums[mid - 1] &&
            nums[mid] > nums[mid + 1]) {
            return mid;
        }

        // Increasing slope
        if (nums[mid] > nums[mid - 1]) {
            low = mid + 1;
        }
        // Decreasing slope
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int peakIndex = findPeakElement(nums);

    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;

    return 0;
}
