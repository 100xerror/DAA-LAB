#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary Search Implementation
int binarySearch(const vector<int>& arr, int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, low, mid - 1, target);
        return binarySearch(arr, mid + 1, high, target);
    }
    return -1;
}

// Merge Sort Implementation
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort Implementation
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Maximum Subarray Sum Implementation
int maxSubarraySum(const vector<int>& arr) {
    int max_sum = arr[0], current_sum = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main() {
    // Binary Search
    vector<int> binarySearchArr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int index = binarySearch(binarySearchArr, 0, binarySearchArr.size() - 1, target);
    cout << "Element found at index: " << index << endl;

    // Merge Sort
    vector<int> mergeSortArr = {12, 11, 13, 5, 6, 7};
    mergeSort(mergeSortArr, 0, mergeSortArr.size() - 1);
    cout << "Sorted array using Merge Sort: ";
    for (int num : mergeSortArr) cout << num << " ";
    cout << endl;

    // Quick Sort
    vector<int> quickSortArr = {4, 2, 6, 9, 2};
    quickSort(quickSortArr, 0, quickSortArr.size() - 1);
    cout << "Sorted array using Quick Sort: ";
    for (int num : quickSortArr) cout << num << " ";
    cout << endl;

    // Maximum Subarray Sum
    vector<int> maxSubarrayArr = {-2, -5, 6, -2, -3, 1, 5, -6};
    int maxSumResult = maxSubarraySum(maxSubarrayArr);
    cout << "Maximum subarray sum is: " << maxSumResult << endl;

    return 0;
}

