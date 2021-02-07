#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>

struct node {
  int key;
  struct node *left, *right;
}
node;

struct node *createNode(int value) {

  struct node *new = (struct node *)malloc(sizeof(struct node));
  new->key = value;
  new->left = NULL;
  new->right = NULL;
  return new;

}

struct node* insert(struct node* node, int value) {
  if(node == NULL) {
    return createNode(value);
  }

  if(value < node->key) {
    node->left = insert(node->left, value);
  } else if(value > node->key) {
    node->right = insert(node->right, value);
  }
  return node;

}

void inorderTraversal(struct node*root) {

  if(root != NULL) {
    inorderTraversal(root->left);
    printf("%d\t", root->key);
    inorderTraversal(root->right);
  }
}
void deallocate(struct node* root) {
    //do nothing if passed a non-existent node
    if(root == NULL) {
      return;
    }

    //now onto the recursion
    deallocate(root->left);
    deallocate(root->right);

    free(root);
}

int main(int argc, char* argv[])
{
  FILE *fp;
  fp = fopen(argv[1], "r");



  int c;
  int length = 0;
  char temp[500];


  if(fp) {
    while((c = getc(fp)) != EOF) {
      if(isspace(c)) {

      } else {
      temp[length] = c;
      length++;
    }

    }
  }
  temp[length] = '\0';

  char num[50][50];
  char work[50] = "";
  int numcount = 0;

  int workcount = 0;

  for(int i = 0; i < length; i++) {
  if(isalpha(temp[i])) {

  }

  if(isdigit(temp[i]) || temp[i] == '-') {
  strncat(work, &temp[i], 1);
  workcount++;
  }

  if(isalpha(temp[i]) && workcount>0) {
  strcpy(num[numcount], work);
  numcount++;
  strcpy(work, "");
  workcount = 0;
  }
  }

  if(workcount>0) {
    strcpy(num[numcount], work);
    numcount++;
    strcpy(work, "");
  }
  char tester[50] = "";
  if(strcmp(num[0],tester) == 0) {


    printf("error\t");
    return 0;

  }

  int fnum[50];

  for(int i = 0; i <numcount; i++) {
  fnum[i] = atoi(num[i]);
  }
  fclose(fp);
  fnum[numcount] = '\0';
/*BST code starts here*/

  struct node *root = NULL;
  root = insert(root, fnum[0]);


  for(int i = 1; i<numcount; i++) {
    insert(root, fnum[i]);
  }

  inorderTraversal(root);
  deallocate(root);
  return 0;



}
