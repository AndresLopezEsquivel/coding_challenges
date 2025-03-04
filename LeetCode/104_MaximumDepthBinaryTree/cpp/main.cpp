#include <deque>
#include <iostream>
#include <cmath>

class Node
{
  public:
  int value;
  Node* left;
  Node* right;
  Node(int value) : value{value}, left{nullptr}, right{nullptr} {};
};

int max_depth_bfs(Node* root)
{
  if (!root) return 0;
  std::deque<Node*> nodes;
  nodes.push_back(root);
  int depth = 0;

  while (!nodes.empty())
  {
    int level_size = nodes.size();
    for (int i = 0; i < level_size; ++i)
    {
      Node* tmp = nodes.front();
      nodes.pop_front();
      if (tmp->left) nodes.push_back(tmp->left);
      if (tmp->right) nodes.push_back(tmp->right);
    }
    depth++;
  }

  return depth;
}

int main()
{
  Node* root = new Node{3};
  root->left = new Node{9};
  root->right = new Node{20};
  root->right->left = new Node{15};
  root->right->right = new Node{7};
  std::cout << "Depth: " << max_depth_bfs(root) << std::endl;
  return 0;
}
