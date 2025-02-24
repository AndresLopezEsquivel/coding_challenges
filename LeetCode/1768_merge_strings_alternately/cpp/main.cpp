#include <iostream>
#include <string>

class Solution
{
  public:
  std::string merge_alternately(const std::string &word1, const std::string &word2);
};

std::string Solution::merge_alternately(const std::string &word1, const std::string &word2)
{
  std::string combined_str;
  int min_size = std::min(word1.size(), word2.size());

  for(int i = 0; i < min_size; i++)
  {
    combined_str += word1.at(i);
    combined_str += word2.at(i);
  }

  combined_str += word1.substr(min_size);
  combined_str += word2.substr(min_size);

  return combined_str;
}


int main()
{
  Solution solution;
  std::string word1 {"abc"};
  std::string word2 {"pqrst"};

  std::cout << "word1: " << word1 << std::endl;
  std::cout << "word2: " << word2 << std::endl;
  std::cout << "combined: " << solution.merge_alternately(word1, word2) << std::endl;
  return 0;
}
