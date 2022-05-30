using namespace std;

#include <iostream>
#include <vector>

// An improvement over using binary search, which would be O(NlogN). This is O(N)

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int left = 0;
    int right = arr.size() - 1;
    int sum;
    for (int i = 0; i < arr.size(); i++) {
        sum = arr[left] + arr[right];
        if (sum == targetSum) {return make_pair(left, right);}
        else if (sum > targetSum) {right--;}
        else {left++;}
    }
    return make_pair(-1, -1);
  }
};

int main() {
    vector<int> arr{1,2,3,4,6};
    pair<int, int> solve = PairWithTargetSum::search(arr, 6);
    cout << solve.first << " " << solve.second << endl;
    return 0;
}
