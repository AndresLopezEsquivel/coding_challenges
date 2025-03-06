#include <iostream>
#include <memory>

class Node
{
  public:
  Node* left;
  Node* right;
  int value;
  Node() : value{0}, left{nullptr}, right{nullptr} {}
  Node(int value) : value{value}, left{nullptr}, right{nullptr} {}
  ~Node() {
    delete left;
    delete right;
  }
};

void in_order_traversal(Node* node, int& k, int& kth_smallest_value)
{
  if(!node) return;
  in_order_traversal(node->left, k, kth_smallest_value);
  // Once we reach the smallest item, we need to iterate k times to reach the kth smallest
  if(--k == 0)
    kth_smallest_value = node->value;
  in_order_traversal(node->right, k, kth_smallest_value);
}

int kth_smallest(Node* root, int k)
{
  int kth_smallest_value = -1;
  in_order_traversal(root, k, kth_smallest_value);
  return kth_smallest_value;
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

  std::cout << "The 1st smallest element in root_1: " << kth_smallest(root_1, 1) << std::endl;
  std::cout << "The 3rd smallest element in root_2: " << kth_smallest(root_2, 3) << std::endl;

  delete root_1;
  delete root_2;

  return 0;
}
