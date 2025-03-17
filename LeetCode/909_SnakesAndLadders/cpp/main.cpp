#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

std::ostream& operator<<(
  std::ostream& os,
  const std::vector<std::pair<int,int>>& v)
{
  for(auto pair : v)
  {
    os << "[";
    os << pair.first << ", ";
    os << pair.second << "]";
    os << std::endl;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const std::pair<int, int> p)
{
  os << "[" << p.first << ", " << p.second << "]";
  return os;
}


std::pair<int,int> get_indexes_of(
  int pos,
  std::vector<std::vector<int>>& grid)
{
  int grid_w = grid.front().size();
  int grid_h = grid.size();
  int r = (pos - 1) / grid_w;
  int c = (pos - 1) % grid_w;
  // Since the grid is alternating:
  c = r % 2 == 0 ? c : grid_w - (c + 1);
  r = grid_h - (r + 1);
  return std::make_pair(r,c);
}

void snakes_and_ladders(std::vector<std::vector<int>>& board)
{
  int board_h = board.size();
  int board_w = board.front().size();
  std::vector<bool> visited ((board_h * board_w) + 1, false);
  std::deque<int> q;
  q.push_back(1);
  visited[1] = true;
  while(!q.empty())
  {
    int curr_pos = q.front();
    q.pop_front();
    std::cout << curr_pos << std::endl;
    std::cout << "[ ";
    for(size_t i = 1; i < 7; i++)
    {
      int next_pos = curr_pos + i;
      if(next_pos > board_h * board_w) continue;
      std::pair<int,int> next_idx = get_indexes_of(next_pos, board);
      if(board[next_idx.first][next_idx.second] != -1)
        next_pos = board[next_idx.first][next_idx.second];
      if(!visited[next_pos])
      {
        visited[next_pos] = true;
        q.push_back(next_pos);
      }
      std::cout << next_pos << " ";
    }
    std::cout << "]" << std::endl;
  }
}

int main()
{
  std::vector<std::vector<int>> board_1
  {
    {-1, 2, -1},
    {-1, 9, 7},
    {-1, 5, -1}
  };

  std::vector<std::vector<int>> board_2
  {
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,35,-1,-1,13,-1},
    {-1,-1,-1,-1,-1,-1},
    {-1,15,-1,-1,-1,-1}
  };

  // std::cout << get_indexes_of(1,board_1) << std::endl;
  // std::cout << get_indexes_of(2,board_1) << std::endl;
  // std::cout << get_indexes_of(3,board_1) << std::endl;
  // std::cout << get_indexes_of(4,board_1) << std::endl;
  // std::cout << get_indexes_of(5,board_1) << std::endl;
  // std::cout << get_indexes_of(6,board_1) << std::endl;
  snakes_and_ladders(board_2);

  return 0;
}
