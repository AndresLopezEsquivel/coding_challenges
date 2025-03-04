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

int max_depth(Node* root)
{
  if (!root) return -1;
  int depth = 1;
  std::deque<Node*> nodes;
  Node* tmp = root;
  nodes.push_back(tmp);
  while(nodes.size() > 0)
  {
    tmp = nodes.front();
    nodes.pop_front();
    if(tmp->left || tmp->right)
    {
      depth++;
      if(tmp->left) nodes.push_back(tmp->left);
      if(tmp->right) nodes.push_back(tmp->right);
    }
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
  std::cout << "Depth: " << max_depth(root) << std::endl;
  return 0;
}
