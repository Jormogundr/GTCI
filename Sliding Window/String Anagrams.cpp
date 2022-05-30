using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    // TODO: Write your code here
    int matched = 0;
    int windowStart = 0;

    // hash map for character frequency in pattern string in form character : frequency
    // slide window over pattern string. if rightmost char is in the map, decrement frequency of char in map
    // when all keys have values = 0, then we have an anagram 
    unordered_map<char, int> freqMap;
    for (auto c : pattern) {
        freqMap[c]++;
    }

    // sliding window loop
    for (int windowEnd = 0; windowEnd < str.size(); windowEnd++) {
        char rightChar = str[windowEnd];
        if (freqMap.find(rightChar) != freqMap.end()) {
            freqMap[rightChar]--;
        }
        if (freqMap[rightChar] == 0) {
            matched++;
        }

        // check for true anagram conditions before sliding window
        if (matched == freqMap.size()) {
            resultIndices.push_back(windowStart);
        }

        // slide left edge of window along
        if (windowEnd >= pattern.size() - 1) {
            char leftChar = str[windowStart++];
            if (freqMap.find(leftChar) != freqMap.end()) {
                // only decrement match count if sliding the window negates our anagram found condition
                if (freqMap[leftChar] == 0) {
                matched--;
                }
                // increment char in map since it's being moved out of the window
                freqMap[leftChar]++;
            }
        }
    }
    return resultIndices;
  }
};

int main() {
    StringAnagrams solve1;
    StringAnagrams solve2;
    const string q1 = "ppqp";
    const string p1 = "pq";
    const string q2 = "abbcabc";
    const string p2 = "abc";
    const vector<int> expectedOutput1{1, 2};
    const vector<int> expectedOutput2{2, 3, 4};
    if (solve1.findStringAnagrams(q1, p1) == expectedOutput1) {
        cout << "pog 1" << endl;
    }
    else {
        cout << "not pog 1" << endl;
    }
    if (solve1.findStringAnagrams(q2, p2) == expectedOutput2) {
        cout << "pog 2" << endl;
    }
    else {
        cout << "not pog 2" << endl;
    }
    return 0;
}