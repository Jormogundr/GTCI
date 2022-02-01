/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include<vector>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int windowStart = 0;
    unordered_map<char, int> charFreqMap;

    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
        char rightChar = str[windowEnd];
        charFreqMap[rightChar] += 1;
    }

    
    return maxLength;
  }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DO NOT INCLUDE BELOW IN SUBMISISON     ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testCases() {
    vector<string> case_arrs {"araaci", "araaci","cbbebi","cbbebi"};
    vector<int> k {2,1,3,10};
    vector<int> output {4,2,5,6};

    for (int i = 0; i < case_arrs.size(); i++) {
        int solve = LongestSubstringKDistinct().findLength(case_arrs[i], k[i]);
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