#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Check if the target element is at mid
        if (arr[mid] == target) {
            return mid; // Element found, return its index
        }
        // If target is smaller, search the left half
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, search the right half
        else {
            left = mid + 1;
        }
    }

    return -1; // Element not found, return -1
}

int main() {
    int size;

    // Ask user for array size
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];

    // Ask user to input the elements (must be sorted)
    cout << "Enter " << size << " elements in ascending order: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    // Ask user for the target element to search
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}
