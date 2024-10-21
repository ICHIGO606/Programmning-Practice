#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Populate the min-heap with the first k elements
    for (int i = 0; i < k; ++i) {
        minHeap.push(nums[i]);
    }

    // For the rest of the elements, if it's larger than the top of the heap, replace the top with it
    for (int i = k; i < nums.size(); ++i) {
        if (nums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    // The kth largest element is the top of the min-heap
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5,6, 6, 4}; // Example array
    int k = 2; // Find the 2nd largest element

    int kthLargest = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << kthLargest << endl;

    return 0;
}
