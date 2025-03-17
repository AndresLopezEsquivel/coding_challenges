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

std::pair<int,int> get_indexes(
  int pos,
  std::vector<std::vector<int>>& board)
{
  int board_w = board.front().size();
  int board_h = board.size();
  int r = (pos - 1) / board_w;
  int offset = (pos - 1) % board_w;
  int c = r % 2 == 0 ? offset : board_w - 1 - offset;
  r = board_h - (r + 1);
  return std::make_pair(r,c);
}

std::vector<std::pair<int,int>> get_adj(
  int r,
  int c,
  std::vector<std::vector<int>>& board)
{
  // (i,j) <= (row, column) <= zero-based
  std::vector<std::pair<int,int>> adjs;

  // If (r,c) is out of bounds
  int board_h = board.size();
  int board_w = board.front().size();
  if(r < 0 || board_h <= r) return adjs;
  if(c < 0 || board_w <= c) return adjs;

  // (0, cf) <= Indexes of the last element of the board
  int cf = board.size() % 2 == 0 ? 0 : board.front().size();
  if((r == 0) && (c == cf)) return adjs;

  if(board[r][c] != -1) adjs.push_back(get_indexes(board[r][c],board));

  char dir = 'r'; // r stands for right
  if(board_h % 2 == 0)
  {
    if((r + 1) % 2 != 0) dir = 'l';
  }
  else
  {
    if((r + 1) % 2 == 0) dir = 'l';
  }

  if(c == 0)
  {
    if(dir == 'r') adjs.push_back(std::make_pair(r, c + 1));
    else adjs.push_back(std::make_pair(r - 1, c));
  }

  if(c == board_w - 1)
  {
    if(dir == 'r') adjs.push_back(std::make_pair(r - 1, c));
    else adjs.push_back(std::make_pair(r, c + 1));
  }

  // BEGIN: DEBUGGING
  // std::cout << "board_h : " << board_h << std::endl;
  // std::cout << "board_w : " << board_w << std::endl;
  // std::cout << "r : " << r << std::endl;
  // std::cout << "c : " << c << std::endl;
  // std::cout << "dir : " << dir << std::endl;
  // END: DEBUGGING

  return adjs;
}

int main()
{
  std::vector<std::vector<int>> board_1 {
    {-1, -1},
    {-1, 3}
  };

  std::cout << get_adj(1, 1, board_1) << std::endl;
  return 0;
}
