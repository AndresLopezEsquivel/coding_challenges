#include <iostream>
#include <stack>
#include <string>

std::string remove_stars(std::string s)
{
  std::string r;

  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '*')
    {
      if(!r.empty()) r.pop_back();
    }
    else
    {
      r.push_back(s[i]);
    }
  }

  return r;
}

int main()
{
  std::string s {"leet**cod*e"};
  std::cout << "Before removing stars: " << s << std::endl;
  std::cout << "After removing stars: " << remove_stars(s) << std::endl;
  return 0;
}
