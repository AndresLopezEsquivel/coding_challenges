#include <deque>
#include <iostream>
#include <vector>

void dfs_traverse_grid(int root_row, int root_col, std::vector<std::vector<int>>& grid)
{
  if(root_row < 0 || root_row >= grid.size()) return;
  if(root_col < 0 || root_col >= grid.front().size()) return;
  if(grid[root_row][root_col] == 0) return;
  grid[root_row][root_col] = 0;
  dfs_traverse_grid(root_row - 1, root_col, grid);
  dfs_traverse_grid(root_row + 1, root_col, grid);
  dfs_traverse_grid(root_row, root_col - 1, grid);
  dfs_traverse_grid(root_row, root_col + 1, grid);
}

void bfs_traverse_grid(int root_row, int root_col, std::vector<std::vector<int>>& grid)
{
  int grid_rows = grid.size();
  int grid_cols = grid.front().size();
  std::deque<std::pair<int,int>> cells;
  grid[root_row][root_col] = 0;
  cells.push_back(std::make_pair(root_row, root_col));
  while(!cells.empty())
  {
    std::pair<int,int> curr_cell = cells.front();
    cells.pop_front();
    std::vector<std::pair<int,int>> adj_cells {
      std::make_pair(curr_cell.first - 1, curr_cell.second),
      std::make_pair(curr_cell.first + 1, curr_cell.second),
      std::make_pair(curr_cell.first, curr_cell.second - 1),
      std::make_pair(curr_cell.first, curr_cell.second + 1),
    };
    for(auto& adj_cell : adj_cells)
    {
      // adj_cell.first => row
      // adj_cell.second => column
      if(adj_cell.first < 0 || adj_cell.first >= grid_rows) continue;
      if(adj_cell.second < 0 || adj_cell.second >= grid_cols) continue;
      if(grid[adj_cell.first][adj_cell.second] == 0) continue;
      grid[adj_cell.first][adj_cell.second] = 0;
      cells.push_back(std::make_pair(adj_cell.first, adj_cell.second));
    }
  }
}

int num_islands(std::vector<std::vector<int>>& grid)
{
  int islands {0};
  for(int i = 0; i < grid.size(); i++)
  {
    for(int j = 0; j < grid.front().size(); j++)
    {
      if(grid[i][j] == 0) continue;
      // bfs_traverse_grid(i,j,grid);
      dfs_traverse_grid(i,j,grid);

      islands++;
    }
  }
  return islands;
}

void run_test(const std::vector<std::vector<int>>& grid, int expected, const std::string& test_name) {
  std::vector<std::vector<int>> grid_copy = grid;
  int result = num_islands(grid_copy);
  if (result == expected) {
    std::cout << test_name << " passed." << std::endl;
  } else {
    std::cout << test_name << " failed. Expected " << expected << " but got " << result << "." << std::endl;
  }
}

int main() {
  std::vector<std::vector<int>> island_1 {
    {1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1}
  };
  run_test(island_1, 4, "Test Case 1");

  std::vector<std::vector<int>> island_2 {
    {1, 1, 1, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  run_test(island_2, 1, "Test Case 2");

  std::vector<std::vector<int>> island_3 {
    {1, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 0, 0, 0, 1}
  };
  run_test(island_3, 5, "Test Case 3");

  std::vector<std::vector<int>> island_4 {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1}
  };
  run_test(island_4, 3, "Test Case 4");

  std::vector<std::vector<int>> island_5 {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
  };
  run_test(island_5, 0, "Test Case 5");

  return 0;
}
