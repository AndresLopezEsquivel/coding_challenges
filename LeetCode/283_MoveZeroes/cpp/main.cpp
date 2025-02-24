#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream &os, const std::vector<int>& v)
{
  os << "[";
  for(auto it = v.begin(); it != std::prev(v.end()); it++)
    os << *it << ", ";
  os << *std::prev(v.end()) << "]" << std::endl;
  return os;
}

void move_zeroes(std::vector<int>& numbers)
{
  int idx_zero = -1;
  for(int i = 0; i < numbers.size(); i++)
  {
    if(numbers.at(i) == 0 && idx_zero == -1) idx_zero = i;
    if(numbers.at(i) != 0 && idx_zero >= 0)
    {
      std::swap(numbers.at(idx_zero), numbers.at(i));
      idx_zero++;
    }
  }
}

int main()
{
  std::vector<int> numbers {0, 0, 0, 1, 2, 3};
  std::cout << "Before: " << numbers << std::endl;
  move_zeroes(numbers);
  std::cout << "After: " << numbers << std::endl;
  return 0;
}
