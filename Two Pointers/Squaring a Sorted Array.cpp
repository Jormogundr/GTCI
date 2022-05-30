using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int right = n - 1;
    int left = 0;
    int count = 1;
    while(left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];
        if (leftSquare > rightSquare) {
            squares[n - count] = leftSquare;
            left++;
        }
        else if (leftSquare == rightSquare) {
            squares[n - count] = leftSquare;
            left++;
        }
        else {
            squares[n - count] = rightSquare;
            right--;
        }
        count++;
    }
    return squares;
  }
};


int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}