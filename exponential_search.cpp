#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int key) {
    if (arr[0] == key) return 0;
    int i = 1;
    while (i < n && arr[i] <= key) i *= 2;
    return binarySearch(arr, i / 2, min(i, n - 1), key);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int index = exponentialSearch(arr, n, key);
    if (index != -1) cout << "Found at index: " << index << endl;
    else cout << "Not found\n";

    return 0;
}
