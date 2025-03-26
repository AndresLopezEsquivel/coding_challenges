#include <iostream>
#include <string>
#include <vector>

int binary_search(const std::vector<int>& v, int number)
{
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
  return -1;
}

void run_test(const std::vector<int>& v, int number, int expected, std::string test_name)
{
  int result = binary_search(v, number);
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
  run_test({1, 3, 5, 6}, 2, -1, "Test 2");
  run_test({1, 3, 5, 6}, 7, -1, "Test 3");
  run_test({1, 3, 5, 6}, 3, 1, "Test 4");

  return 0;
}
