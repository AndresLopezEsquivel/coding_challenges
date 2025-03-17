#include <iostream>
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

std::vector<std::pair<int,int>> get_adj(
  int r,
  int c,
  std::vector<std::vector<int>>& board)
{

}

int main()
{
  std::vector<std::vector<int>> board_1 {
    // {-1, 2, -1},
    // {-1, 9, 7},
    // {-1, 5, -1}
    {-1, -1, -1},
    {-1, -1, -1}
  };



  std::cout << get_indexes_of(1,board_1) << std::endl;
  std::cout << get_indexes_of(2,board_1) << std::endl;
  std::cout << get_indexes_of(3,board_1) << std::endl;
  std::cout << get_indexes_of(4,board_1) << std::endl;
  std::cout << get_indexes_of(5,board_1) << std::endl;
  std::cout << get_indexes_of(6,board_1) << std::endl;

  return 0;
}
