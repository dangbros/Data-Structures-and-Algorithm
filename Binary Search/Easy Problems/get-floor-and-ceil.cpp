#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // Sort the array for binary search
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int low = 0, high = n - 1;
        int floor = -1, ceil = -1;
        
        // Find floor using binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                floor = arr[mid];  // Possible floor
                low = mid + 1;     // Look for larger index on the right
            } else {
                high = mid - 1;    // Look on the left
            }
        }
        
        // Reset low and high for ceil search
        low = 0;
        high = n - 1;
        
        // Find ceil using binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ceil = arr[mid];   // Possible ceil
                high = mid - 1;    // Look for smaller index on the left
            } else {
                low = mid + 1;     // Look on the right
            }
        }
        
        // Return the result as a vector
        return {floor, ceil};
    }
};

int main() {
    // Example input
    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    int x = 4;

    Solution ob;
    vector<int> result = ob.getFloorAndCeil(x, arr);

    // Output the result
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}
