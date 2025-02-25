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

  // Add the new request time to the front of the deque
  requests.push_front(t);
  // Remove requests that are older than 3000 ms from the current time
  while (!requests.empty() && requests.back() < t - 3000)
  {
    requests.pop_back();
  }
  // Return the number of requests in the last 3000 ms
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
