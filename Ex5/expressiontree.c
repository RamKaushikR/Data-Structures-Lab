#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct tree
{
  char key;
  struct tree *left,*right;
};
typedef struct tree Tree;
struct node
{
  Tree *data;
  struct node *back;
};
typedef struct node Node;
Tree *gettree()
{
  return (Tree *)malloc(sizeof(Tree));
}
Node *getnode()
{
  return (Node *)malloc(sizeof(Node));
}
Tree *create(Tree *root, char a)
{
  root=gettree();
  root->key=a;
  root->left=root->right=NULL;
  return root;
}
Node *push(Node *top, Tree *root)
{
  Node *temp;
  if(top==NULL)
  {
    top=getnode();
    top->data=root;
    top->back=NULL;
  }
  else
  {
    temp=getnode();
    temp->data=root;
    temp->back=top;
    top=temp;
  }
  return top;
}
Node *pop(Node *top)
{
  Node *p=top;
  if(top!=NULL)
    top=top->back;
  free(p);
  return top;
}
void preorder(Tree *root)
{
  printf("%c",root->key);
  if(root->left!=NULL)
    preorder(root->left);
  if(root->right!=NULL)
    preorder(root->right);
}
void inorder(Tree *root)
{
  if(root->left!=NULL)
    inorder(root->left);
  printf("%c",root->key);
  if(root->right!=NULL)
    inorder(root->right);
}
void postorder(Tree *root)
{
  if(root->left!=NULL)
    postorder(root->left);
  if(root->right!=NULL)
    postorder(root->right);
  printf("%c",root->key);
}
void main()
{
  char *postfix=(char *)malloc(sizeof(100));
  Tree *root,*b[2];
  Node *top=getnode();
  int i=0;
  scanf("%s",postfix);
  while(postfix[i]!='\0')
  {
    root=create(root,postfix[i]);
    if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='%' || postfix[i]=='^')
    {
      for(int j=0;j<2;j++)
      {
	b[j]=gettree();
	b[j]=top->data;
	top=pop(top);
      }
      root->right=b[0];
      root->left=b[1];
    }
    top=push(top,root);
    i++;
  }
  preorder(top->data);
  printf("\n");
  inorder(top->data);
  printf("\n");
  postorder(top->data);
  printf("\n");
}
  
