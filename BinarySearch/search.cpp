#include <bits/stdc++.h>
using namespace std;

int main() {
    int target = 26;
    vector<int> nums = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
    int low = 0;
    int high = nums.size() - 1;
    int found = 0, position = -1, i = 0;

    while (low <= high) {
        ++i;
        int middle = low + (high - low) / 2;
        
        if (nums[middle] > target) {
            high = middle - 1;  // Decrease high normally
        } else if (nums[middle] < target) {
            low = middle + 1;  // Increase low normally
        } else {
            found = 1;
            position = middle;
            break;
        }
    }

    if (found) 
        cout << "Found at index " << position << " in " << i << " iterations!" << endl;
    else 
        cout << "Not found!" << endl;

    return 0;
}
