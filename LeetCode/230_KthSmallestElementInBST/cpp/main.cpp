#include <iostream>

class Node
{
  public:
  Node* left;
  Node* right;
  int value;
  Node() : value{0}, left{nullptr}, right{nullptr} {}
  Node(int value) : value{value}, left{nullptr}, right{nullptr} {}
};

void in_order_traversal(Node* node, int& k, int& min)
{
  if(!node) return;
  in_order_traversal(node->left, k, min);
  // Once we reach the smallest item, we need to iterate k times to reach the kth smallest
  if(--k == 0)
    min = node->value;
  in_order_traversal(node->right, k, min);
}

int kth_smallest(Node* root, int k)
{
  int min = -1;
  in_order_traversal(root, k, min);
  return min;
}

int main()
{
  Node* root_1 = new Node{3};
  root_1->left = new Node{1};
  root_1->left->right = new Node{2};
  root_1->right = new Node{4};

  Node* root_2 = new Node{5};
  root_2->left = new Node{3};
  root_2->right = new Node{6};
  root_2->left->left = new Node{2};
  root_2->left->right = new Node{4};
  root_2->left->left->left = new Node{1};

  std::cout << "root_1 : " << kth_smallest(root_1, 1) << std::endl;
  std::cout << "root_2 : " << kth_smallest(root_2, 3) << std::endl;
  return 0;
}
