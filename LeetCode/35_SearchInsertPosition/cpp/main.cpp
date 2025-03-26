#include <iostream>
#include <string>
#include <vector>

// This is a modified version of binary search to find the index of the number
// in the sorted array. If the number is not found, it returns the index where
// the number should be inserted to keep the array sorted.
// The time complexity of this algorithm is O(log n) where n is the size of the
// array. The space complexity is O(1) since we are not using any extra space
// except for a few variables.
int search_insert(const std::vector<int>& v, int number)
{
  if(number > v.back()) return v.size();
  int upper_idx = v.size() - 1;
  int lower_idx = 0;
  int mid_idx = 0;
  while(lower_idx <= upper_idx)
  {
    mid_idx = (upper_idx + lower_idx) / 2;
    if(number > v[mid_idx])
    {
      lower_idx = mid_idx + 1;
    }
    else if (number < v[mid_idx])
    {
      upper_idx = mid_idx - 1;
    }
    else
    {
      return mid_idx;
    }
  }
  return lower_idx;
}

void run_test(const std::vector<int>& v, int number, int expected, std::string test_name)
{
  int result = search_insert(v, number);
  if (result == expected)
  {
    std::cout << test_name << " passed." << std::endl;
  }
  else
  {
    std::cout << test_name << " failed. Expected " << expected << " but got " << result << "." << std::endl;
  }
}

int main()
{
  run_test({1, 3, 5, 6}, 5, 2, "Test 1");
  run_test({1, 3, 5, 6}, 2, 1, "Test 2");
  run_test({1, 3, 5, 6}, 7, 4, "Test 3");
  run_test({1, 3, 5, 6}, 3, 1, "Test 4");
  run_test({1, 3, 5, 6}, 0, 0, "Test 5");
  run_test({1, 3, 5, 6}, 8, 4, "Test 6");
  run_test({1, 3, 5, 6}, 4, 2, "Test 7");

  return 0;
}
