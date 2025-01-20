#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> array, int target) {
    int l = 0;
    int r = array.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int result = binary_search(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

