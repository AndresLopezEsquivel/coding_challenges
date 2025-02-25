#include <deque>
#include <iostream>

std::ostream& operator<<(std::ostream& os, std::deque<int> d)
{
  std::cout << "[";
  for(auto n : d)
    std::cout << n << " ";
  std::cout << "]";
  return os;
}

class RecentCounter
{
  private:
  std::deque<int> requests;
  public:
  RecentCounter() {}
  int ping(int t);
  const std::deque<int>& get_requests() const { return requests; }
};

int RecentCounter::ping(int t)
{
  // t : time in [ms]
  // Returns the number of requets from the past 3000 [ms] (including the new one)
  // Specifically, returns the number of requests that have happened in [t - 3000, t]
  requests.push_front(t);
  int t_tmp = requests.back();
  while (!(t - 3000 <= t_tmp && t_tmp <= t))
  {
    requests.pop_back();
    t_tmp = requests.back();
  }
  return requests.size();
}

int main()
{
  RecentCounter recent_counter;
  std::cout << recent_counter.get_requests() << std::endl;
  std::cout << "t : " << 1  << " => "<< recent_counter.ping(1) << std::endl;
  std::cout << recent_counter.get_requests() << std::endl;
  std::cout << "t : " << 100 << " => " << recent_counter.ping(100) << std::endl;
  std::cout << recent_counter.get_requests() << std::endl;
  std::cout << "t : " << 3001 << " => " << recent_counter.ping(3001) << std::endl;
  std::cout << recent_counter.get_requests() << std::endl;
  std::cout << "t : " << 3002 << " => " << recent_counter.ping(3002) << std::endl;
  std::cout << recent_counter.get_requests() << std::endl;
  std::cout << "t : " << 6001 << " => " << recent_counter.ping(6001) << std::endl;
  std::cout << recent_counter.get_requests() << std::endl;
  return 0;
}
