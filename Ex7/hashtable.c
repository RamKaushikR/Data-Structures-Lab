#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20
struct node {
  int data;   
  int key;
};
typedef struct node Node;
Node *getnode(){
  return (Node *)malloc(sizeof(Node));
}
Node* hashArray[SIZE]; 
Node* dummyItem;
Node* item;
int hashCode(int key) {
  return key % SIZE;
}
Node *search(int key) {
  int hashIndex = hashCode(key);  
  while(hashArray[hashIndex] != NULL) {
    if(hashArray[hashIndex]->key == key)
      return hashArray[hashIndex]; 
    ++hashIndex;
    hashIndex %= SIZE;
  }        
  return NULL;        
}
void insert(int key,int data) {
  Node *item = getnode();
  item->data = data;  
  item->key = key;
  int hashIndex = hashCode(key);
  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
    ++hashIndex;
    hashIndex %= SIZE;
  }
  hashArray[hashIndex] = item;
}
Node* delete(Node* item) {
  int key = item->key;
  int hashIndex = hashCode(key);
  while(hashArray[hashIndex] != NULL) {
    if(hashArray[hashIndex]->key == key) {
      Node* temp = hashArray[hashIndex]; 
      hashArray[hashIndex] = dummyItem; 
      return temp;
    }
    ++hashIndex;
    hashIndex %= SIZE;
  }      
  return NULL;        
}

void display() {
  int i;
  for(i = 0; i<SIZE-1; i++) {
    if(hashArray[i] != NULL)
      printf("(%d,%d)%d ",hashArray[i]->key,hashArray[i]->data,i);
  }
  if(hashArray[i]!=NULL)
    printf("(%d,%d)",hashArray[i]->key,hashArray[i]->data);
  printf("\n");
}
int main() {
  dummyItem = getnode();
  dummyItem->data = -1;  
  dummyItem->key = -1; 
  insert(1, 20);
  insert(2, 70);
  insert(42, 80);
  insert(4, 25);
  insert(12, 44);
  insert(14, 32);
  insert(17, 11);
  insert(13, 78);
  insert(37, 97);
  display();
  item = search(37);
  if(item != NULL) {
    printf("Element found: %d\n", item->data);
  }
  else {
    printf("Element not found\n");
  }
  delete(item);
  item = search(37);
  if(item != NULL) {
    printf("Element found: %d\n", item->data);
  }
  else {
    printf("Element not found\n");
  }
}
