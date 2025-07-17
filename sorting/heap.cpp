#include<bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;         // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Heap sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      // Move current root to end
        heapify(arr, i, 0);        // Heapify reduced heap
    }
}

int main() {
    vector<int> arr = {9, 8, 76, 5, 4, 3, 2, 1};
    
    heapSort(arr);
    
    for(auto& el : arr)
        cout << el << " ";

    return 0;
}
