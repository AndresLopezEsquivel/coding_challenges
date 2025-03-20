#include <iostream>
#include <stack>
#include <unordered_map>

int h(int n)
{
  int a = 1;
  int b = 2;
  for(int i = 3; i <= n; i++)
  {
    int k = a + b;
    a = b;
    b = k;
  }
  return b;
}

int g(int n)
{
  int ways = 0;
  std::stack<int> s;
  s.push(0);
  while(!s.empty())
  {
    int num = s.top();
    s.pop();
    for(int i = 1; i < 3; i++)
    {
      if(num + i == n) ways++;
      if(num + i < n) s.push(num + i);
    }
  }
  return ways;
}

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
  // std::unordered_map<int,int> solutions;
  // return f(n, solutions);
  // return g(n);
  return h(n);
}

int main()
{
  std::cout << "n = 2 : " << climb_stairs(2) << std::endl;
  std::cout << "n = 3 : " << climb_stairs(3) << std::endl;
  std::cout << "n = 4 : " << climb_stairs(4) << std::endl;
  return 0;
}
