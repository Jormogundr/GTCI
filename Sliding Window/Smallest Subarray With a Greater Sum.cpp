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