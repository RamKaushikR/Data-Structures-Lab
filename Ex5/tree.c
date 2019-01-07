#include<stdio.h>
#include<stdlib.h>
struct tree
{
  int key;
  struct tree *left,*right;
};
typedef struct tree Tree;
Tree *gettree()
{
  return (Tree *)malloc(sizeof(Tree));
}
void preorder(Tree *root)
{
  printf("%d ",root->key);
  if(root->left!=NULL)
    preorder(root->left);
  if(root->right!=NULL)
    preorder(root->right);
}
void inorder(Tree *root)
{
  if(root->left!=NULL)
    inorder(root->left);
  printf("%d ",root->key);
  if(root->right!=NULL)
    inorder(root->right);
}
void postorder(Tree *root)
{
  if(root->left!=NULL)
    postorder(root->left);
  if(root->right!=NULL)
    postorder(root->right);
  printf("%d ",root->key);
}
Tree *insert(Tree *root, Tree *ins)
{
  Tree *temp=root;
  if(root==NULL)
    root=ins;
  else if(temp->key>=ins->key)
  {
    temp=insert(temp->left,ins);
    root->left=temp;
  }
  else
  {
    temp=insert(temp->right,ins);
    root->right=temp;
  }
  return root;
}
void main()
{
  Tree *root=NULL,*temp=NULL;
  int a;
  scanf("%d",&a);
  while(a!=-1)
  {
    temp=gettree();
    temp->key=a;
    temp->left=temp->right=NULL;
    root=insert(root,temp);
    scanf("%d",&a);
  }
  printf("Preorder:\n");
  preorder(root);
  printf("\nInorder:\n");
  inorder(root);
  printf("\nPostorder:\n");
  postorder(root);
  printf("\n");
}
  
    
  
