/*
Given a string and a pattern, find out if the string contains any permutation of the pattern.

Permutation is defined as the re-arranging of the characters of the string. For example, “abc” has the following six permutations:

abc
acb
bac
bca
cab
cba
If a string has ‘n’ distinct characters, it will have n!n! permutations.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StringPermutation {
 public:
    // Iterative function to find permutations of a string
    vector<string> permutations(string s)
    {
        int n = s.length();
        vector<string> perms;
    
        // base cases
        if (n == 0) {
            return perms;
        }
        if (n == 1) {
            cout << s;
            perms.push_back(s);
            return perms;
        }
    
        // sort the string in a natural order
        sort(s.begin(), s.end());
    
        while (1)
        {
            cout << s << " ";
            perms.push_back(s);
    
            /* The following code will rearrange the string to the next lexicographically
            ordered permutation (if any) or return if we are already at the
            highest possible permutation */
    
            // Find the largest index `i` such that `s[i-1]` is less than `s[i]`
            int i = n - 1;
            while (s[i-1] >= s[i])
            {
                // if `i` is the first index of the string, we are already at the last
                // possible permutation (string is sorted in reverse order)
                if (--i == 0) {
                    return perms;
                }
            }
    
            // find the highest index `j` to the right of index `i` such that
            // `s[j] > s[i-1]` (`s[i…n-1]` is sorted in reverse order)
    
            int j = n - 1;
            while (j > i && s[j] <= s[i - 1]) {
                j--;
            }
    
            // swap character at index `i-1` with index `j`
            swap(s[i - 1], s[j]);
    
            // reverse substring `s[i…n-1]`
            reverse (s.begin() + i, s.end());
        }
        return perms;
    };
 
    static bool findPermutation(const string &str, const string &pattern) {    
        vector<string> patternPerms = StringPermutation().permutations(pattern);
        int windowStart = 0;
        for (int i = 0; i < patternPerms.size(); i++) {
            for (int windowEnd = pattern.size(); windowEnd < str.size(); windowEnd++) {
                string window = str.substr(windowStart, pattern.size());
                if (patternPerms[i] == window) {
                    return true;
                }
                windowStart++;
            }

        }
        return false;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  DO NOT INCLUDE BELOW IN SUBMISISON     ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void testCases() {
    vector<string> strings{"oidbcaf", "odicf", "bcdxabcdy", "aaacb"};
    vector<string> patterns{"abc", "dc", "bcdyabcdx", "abc"};
    vector<bool> output {true, false, true, true};

    for (int i = 0; i < strings.size(); i++) {
        bool solve = StringPermutation().findPermutation(strings[i], patterns[i]);

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