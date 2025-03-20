#include <iostream>
#include <unordered_map>

int f(int n, std::unordered_map<int,int>& s)
{
  if(n == 0) return 1;
  if(n < 0) return 0;

  if(s.find(n) == s.end())
    s[n] = f(n - 1, s) + f(n - 2, s);

  return s[n];
}

int climb_stairs(int n)
{
  std::unordered_map<int,int> solutions;
  return f(n, solutions);
}

int main()
{
  std::cout << "n = 2 : " << climb_stairs(2) << std::endl;
  std::cout << "n = 3 : " << climb_stairs(3) << std::endl;
  return 0;
}
