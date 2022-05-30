/*
Given a string, find the length of the longest substring, which has all distinct characters.

Incomplete
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0; 
    int currLength = 0;
    int windowStart = 0;
    unordered_map<char, int> charFreqMap;

    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
        char rightChar = str[windowEnd];
        charFreqMap[rightChar]++;

        // while the char already exists in the map, slide the window in from the left, holding the right edge fixed
        while (charFreqMap[rightChar]) {
            char leftChar = str[windowStart];
            charFreqMap[leftChar]--;
            if (charFreqMap[leftChar] < 1) {
                charFreqMap.erase(leftChar);
            }
        }

        maxLength = max(maxLength, windowStart - windowEnd + 1);
    }
    return maxLength;
  }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DO NOT INCLUDE BELOW IN SUBMISISON     ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testCases() {
    vector<string> case_arrs {"aabccbb", "abbbb","abccde"};
    vector<int> output {3,2,3};

    for (int i = 0; i < case_arrs.size(); i++) {
        int solve = NoRepeatSubstring().findLength(case_arrs[i]);
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