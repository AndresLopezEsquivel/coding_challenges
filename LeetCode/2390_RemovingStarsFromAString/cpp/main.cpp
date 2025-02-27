#include <iostream>
#include <stack>
#include <string>

std::string remove_stars(std::string s)
{
  std::string r;
  std::stack<char> c;

  for(int i = 0; i < s.size(); i++)
  {
    if(s[i] == '*')
    {
      c.pop();
    }
    else
    {
      c.push(s[i]);
    }
  }

  while(!c.empty())
  {
    r = c.top() + r;
    c.pop();
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
