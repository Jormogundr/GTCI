/*
Given an array of positive numbers and a positive number ‘k,’ find the maximum sum of any contiguous subarray of size ‘k’.
*/

using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    int windowStart = 0;
    int windowSum = 0;

    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
        windowSum += arr[windowEnd];
        if (windowEnd >= k - 1) {
            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
            windowSum -= arr[windowStart];
            windowStart++;
        }
    }
    return maxSum;
  }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DO NOT INCLUDE BELOW IN SUBMISISON     ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testCases() {
    vector<vector<int>> case_arrs {
        {2, 1, 5, 1, 3, 2},
        {2, 3, 4, 1, 5}
    };
    vector<int> k {3, 2};
    vector<int> output {9,7};

    for (int i = 0; i < case_arrs.size(); i++) {
        int solve = MaxSumSubArrayOfSizeK().findMaxSumSubArray(k[i], case_arrs[i]);

        if (solve == output[i]) {
            cout << "Success for " << solve << " == " << output[i] << endl;
        }
        else {
            cout << "Failure for " << solve << " =/= " << output[i] << endl;
        }
    }

}

int main() {
    testCases();
    return 0;
}