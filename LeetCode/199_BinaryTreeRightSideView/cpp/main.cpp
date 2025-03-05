#include <deque>
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
  os << "[";
  for(auto it = v.begin(); it != std::prev(v.end()); it++)
    os << *it << ", ";
  os << *std::prev(v.end()) << "]";
  return os;
}

class Node
{
  public:
  Node* left;
  Node* right;
  int value;
  Node() : value{0}, right{nullptr}, left{nullptr} {}
  Node(int value) : value{value}, right{nullptr}, left{nullptr} {}
};

std::vector<int> right_side_view(Node* root)
{
  std::vector<int> values;
  std::deque<Node*> nodes;
  nodes.push_back(root);
  while(!nodes.empty())
  {
    values.push_back(nodes.back()->value);
    int level_size = nodes.size();
    for(int i = 0; i < level_size; i++)
    {
      Node* tmp = nodes.front();
      nodes.pop_front();
      if(tmp->left) nodes.push_back(tmp->left);
      if(tmp->right) nodes.push_back(tmp->right);
    }
  }
  return values;
}

int main()
{
  Node* root_1 = new Node{1};
  root_1->left = new Node{2};
  root_1->right = new Node{3};
  root_1->left->right = new Node{5};
  root_1->right->right = new Node{4};

  Node* root_2 = new Node{1};
  root_2->right = new Node{3};
  root_2->left = new Node{2};
  root_2->left->left = new Node{4};
  root_2->left->left->left = new Node{5};

  std::cout << "root_1 : " << right_side_view(root_1) << std::endl;
  std::cout << "root_2 : " << right_side_view(root_2) << std::endl;

  return 0;
}
