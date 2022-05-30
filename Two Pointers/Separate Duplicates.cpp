using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    int nextNonDuplicate = 1;  // index of the next non-duplicate element
    for (int next = 0; next < arr.size(); next++) {
      if (arr[nextNonDuplicate - 1] != arr[next]) {
        arr[nextNonDuplicate] = arr[next];
        nextNonDuplicate++;
      }
    }

    return nextNonDuplicate;
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}
