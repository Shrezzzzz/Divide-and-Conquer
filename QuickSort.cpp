#include <iostream>
using namespace std;

// Function to partition the array into two halves and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    // Traverse through the array and rearrange elements
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {  // If the element is smaller than or equal to pivot
            i++;
            swap(arr[i], arr[j]);  // Swap arr[i] and arr[j]
        }
    }
    
    // Swap the pivot element with the element at i+1
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the pivot index
}

// Function to implement quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);  // Get the pivot index

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int size;

    // Ask user for array size
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];

    // Ask user to input the elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Call quickSort function
    quickSort(arr, 0, size - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

