#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

// Code to solve: https://cses.fi/problemset/task/1083/

void init_random_generator()
{
  // Seed random generator with current time
  srand(static_cast<unsigned>(time(0)));
}

int generate_random_int(unsigned int lower_lim, unsigned int upper_lim)
{
  // Generate a random number in the range [N, M]:
  // 1. rand() % (M - N + 1): Generates a number in the range [0, M - N]
  // 2. Adding N shifts the range to [N, M], making the bounds inclusive
  return rand() % (upper_lim - lower_lim + 1) + lower_lim;
}

std::ostream& operator<<(std::ostream& os, std::vector<int>& sequence)
{
  if (sequence.empty())
  {
    os << "[]";
    return os;
  }

  os << "[";
  os << *sequence.begin();
  for(auto it = next(sequence.begin()); it != sequence.end(); it++)
  {
    os << ", " << *it;
  }
  os << "]";
  return os;
}

void populate_sequence(std::vector<int> &sequence, int n)
{
  size_t index_to_remove = generate_random_int(0, n - 1);

  for(size_t i = 0; i < n; i++)
  {
    if(i == index_to_remove) continue;
    sequence.push_back(i + 1);
  }
}

int find_missing(std::vector<int> &sequence)
{
  for(size_t i = 1; i <= sequence.size() + 1; i++)
  {
    auto it = std::find(sequence.begin(), sequence.end(), i);
    if(it == sequence.end()) return i;
  }
  return -1;
}

int main()
{
  init_random_generator();
  std::vector<int> sequence;
  populate_sequence(sequence, 5);
  std::cout << sequence << std::endl;
  int missing_number = find_missing(sequence);
  std::cout << "The missing number is: " << missing_number << std::endl;

  return 0;
}
