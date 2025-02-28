#include <iostream>
#include <queue>
#include <vector>
#include <climits>

int find_kth_largest(const std::vector<int>& nums, int k)
{
  if (k > nums.size()) {
    throw std::invalid_argument("k cannot be greater than the size of the input vector");
  }

  std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

  for (int n : nums)
  {
    min_pq.push(n);
    if (min_pq.size() > k)
    {
      min_pq.pop();
    }
  }

  return min_pq.top();
}

int main()
{
  std::vector<int> nums {3,2,1,5,6,4};
  std::cout << "1st largest : " << find_kth_largest(nums, 1) << std::endl;
  std::cout << "2nd largest : " << find_kth_largest(nums, 2) << std::endl;

  nums = {3,2,3,1,2,4,5,5,6};
  std::cout << "4th largest : " << find_kth_largest(nums, 4) << std::endl;
  return 0;
}
