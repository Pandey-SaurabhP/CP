#include <bits/stdc++.h>
using namespace std;

// Function to return maximum points
int maxPointCount(int arr[], int K, int size)
{
    // Initialization of current points
    // and max points so far
    int curr_points = 0;
    int max_points = 0;

    vector <int> pre(size + 1, 0);
    pre[0] = 0;

    // Add elements from the beginning
    for (int i = 0; i < K; i++) {
        curr_points += arr[i];
        max_points = max(curr_points, max_points);
        pre[i + 1] = max_points;
    }

    for(auto it : pre){
        cout << it << " ";
    }
    cout << "\n";

    // Points to the end of array element
    int j = size - 1;

    vector <int> suff(size + 1, 0);
    // Add K elements from end of array
    for (int i = K - 1; i >= 0; i--) {
        curr_points = curr_points + arr[j] - arr[i];
        max_points = max(curr_points, max_points);

        suff[i] = max_points;

        // Decrement the value for j
        j--;
    }

    for(auto it : suff){
        cout << it << " ";
    }
    cout << "\n";

    j = size - K;

    for (; j < size; j++) {
        curr_points = curr_points - arr[j];
        max_points = max(curr_points, max_points);
    }

    // Return the final result
    return max_points;
}

// Driver code
int main()
{
    int arr[] = { 2, 1, 6, 3, 1 };

    int N = sizeof(arr) / sizeof(arr[0]);

    int K = 2;

    cout << maxPointCount(arr, K, N);

    return 0;
}
