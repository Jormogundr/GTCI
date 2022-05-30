#include <iostream>
#include <algorithm>
using namespace std;
 
// Function to find lexicographically next permutations of a string.
// It returns true if the string could be rearranged as a lexicographically
// greater permutation; otherwise, it returns false.
bool next_permutation(string &str, int n)
{
    // find the largest index `i` such that `str[i-1]` is less than `str[i]`
    int i = n - 1;
    while (str[i - 1] >= str[i])
    {
        // if `i` is the first index of the string, that means we are already
        // at the highest possible permutation, i.e., the string is sorted in
        // descending order
        if (--i == 0) {
            return false;
        }
    }
 
    /* If we reach here, the substring `str[i…n)` is sorted in descending order
       i.e., str[i-1] < str[i] >= str[i+1] >= str[i+2] >= … >= str[n-1] */
 
    // find the highest index `j` to the right of index `i` such that
    // str[j] > str[i-1]
    int j = n - 1;
    while (j > i && str[j] <= str[i - 1]) {
        j--;
    }
 
    // swap character at index `i-1` with index `j`
    swap(str[i - 1], str[j]);
 
    // reverse substring `str[i…n)` and return true
    reverse (str.begin() + i, str.end());
 
    return true;
}
 
// Function to find all lexicographically next permutations of a string
void permutations(string str)
{
    int n = str.length();
 
    // base case
    if (n == 0) {
        return;
    }
 
    // base case
    if (n == 1) {
        cout << str;
        return;
    }
 
    while (1)
    {
        // print the current permutation
        cout << str << " ";
 
        // find the next lexicographically ordered permutation
        if (!next_permutation(str, str.length())) {
            break;
        }
    }
}
 
int main()
{
    string str = "BADC";
 
    permutations(str);
 
    return 0;
}