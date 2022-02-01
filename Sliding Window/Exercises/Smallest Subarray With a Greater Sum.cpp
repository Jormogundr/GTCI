/*
Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.
*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
   int windowStart = 0;
   int windowSum = 0;
   int lengthOfSmallestSubArray = numeric_limits<int>::max();

   for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
       windowSum += arr[windowEnd];
       while(windowSum >= S) {
           lengthOfSmallestSubArray = min(lengthOfSmallestSubArray, windowEnd - windowStart + 1);
           windowSum -= arr[windowStart];
           windowStart++;
       }
   }   
   return lengthOfSmallestSubArray;
  }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DO NOT INCLUDE BELOW IN SUBMISISON     ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testCases() {
    vector<vector<int>> case_arrs {
        {2, 1, 5, 2, 3, 2},
        {2, 1, 5, 2, 8},
        {3, 4, 1, 1, 6}
    };
    vector<int> k {7, 7, 8};
    vector<int> output {2, 1, 3};

    for (int i = 0; i < case_arrs.size(); i++) {
        int solve = MinSizeSubArraySum().findMinSubArray(k[i], case_arrs[i]);

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