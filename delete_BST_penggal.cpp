#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int value)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
}

void inorderTraversal(struct node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

struct node *delNode(struct node *root, int key)
{
  if (root == NULL)
    return root;

  if (key < root->data)
  {
    root->left = delNode(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = delNode(root->right, key);
  }
  else
  {
    if (root->left == NULL)
    {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = root->right;
    while (temp->left != NULL)
    {
      temp = temp->left;
    }
    root->data = temp->data;
    root->right = delNode(root->right, temp->data);
  }
  return root;
}

int main()
{
  struct node *root = newNode(52);
  root->left = newNode(33);
  root->right = newNode(72);
  root->left->left = newNode(20);
  root->left->right = newNode(40);
  root->right->left = newNode(60);
  root->right->right = newNode(85);
  root->left->left->left = newNode(15);
  root->left->left->right = newNode(25);
  root->right->left->left = newNode(55);
  root->right->left->right = newNode(62);
  printf("Inorder traversal pada tree: ");
  inorderTraversal(root);

  int key = 52;
  root = delNode(root, key);
  int key1 = 20;
  root = delNode(root, key1);
  int key2 = 60;
  root = delNode(root, key2);
  printf("\nInorder traversal setelah dihapus %d, %d, dan %d: ", key, key1, key2);
  inorderTraversal(root);
  printf("\n");

  return 0;
}
