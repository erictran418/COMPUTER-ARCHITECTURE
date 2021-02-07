#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>

typedef struct node
{
  int data;
  struct node *next;
}

node;

node* create(node*next, int target) {
  node* new = (struct node*)malloc(sizeof(struct node));

  new->data = target;
  new->next = next;

  return new;
}
void insert(node** head, int target) {
  node* new = create(NULL, target);

  if(*head == NULL) {
    (*head) = new;
    return;
  }
node *pointer = *head;
node* current = pointer;
//target<first node
if(target <= pointer->data) {
new->next = pointer;
(*head) = new;
return;
}

  while(pointer != NULL) {
  if(target>pointer->data) {
  current=pointer;
  pointer = pointer->next;
  }else {
    new->next = pointer;
    current->next = new;
    return;
  }
  }
  //new node larger than anything in list
  current->next = new;
  new->next = NULL;
  return;

}

void delete(node** head, int target) {

  if(*head == NULL) {
    return;
  }
  node *pointer = *head;
  node *curr = pointer;

  //target is first node/if its only 1 node in list
  if(pointer->data == target) {
    curr = pointer->next;
    free(pointer);
    (*head) = curr;
    return;
  }
  while(pointer != NULL) {
    if (pointer->data == target){
      curr->next = pointer->next;
      free(pointer);
      return;
    } else {
      curr = pointer;
      pointer = pointer->next;
    }
  }
  return;

}

void freelist(struct node* head){
  node* temp = head;
  while (head != NULL) {
  temp = head;
  head = head->next;
  free(temp);
}

}

void duplicatedelete(struct node* head)
{
    if(head==NULL) {
      return;
    }

    node* curr = head;
    node* prev;

    while (curr->next != NULL)
    {
       if (curr->data != curr->next->data)
       {
            curr = curr->next;

       }
       else
       {
         prev = curr->next->next;
         free(curr->next);
         curr->next = prev;
       }
    }
}

int main(int argc, char* argv[])
{
  FILE *fp;
  fp = fopen(argv[1], "r");


  int c;
  char temp[200];
  int length = 0;

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
  char command[50];
  char work[50] = "";
  int numcount = 0;
  int commandcount = 0;

  int workcount = 0;

  for(int i = 0; i < length; i++) {
  if(isalpha(temp[i])) {
    command[commandcount] = temp[i];
    commandcount++;
  }

  else {
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

  int fnum[50];

  for(int i = 0; i <numcount; i++) {
  fnum[i] = atoi(num[i]);
  }
  fnum[numcount] = '\0';
  command[commandcount] = '\0';

/*
  for(int i = 0; i<commandcount; i++) {
    printf("%c\n", command[i]);
  }

  for(int i = 0; i<numcount; i++) {
    printf("%d\n", fnum[i]);
  }
  */
  /*Everything above is to read the info
  and create 2 arrays of which the linked list operations
  are being commanded to do*/
  fclose(fp);

  node *p = NULL;
  int first = 0;


  for(int i = 0; i < commandcount; i++) {
    if(command[i] == 'i') {
      if(first == 0) {
      insert(&p, fnum[i]);
      first++;
      continue;
    }
    insert(&p, fnum[i]);
  }
  if(command[i] == 'd') {
    delete(&p, fnum[i]);
  }
}
  node*head=p;
  int fcount = 0;

  while(p!=NULL) {
    fcount++;
    p = p->next;
  }
  printf("%d \n", fcount);

  p=head;


  duplicatedelete(p);
  while(p!=NULL) {
    printf("%d\t", p->data);
    p=p->next;
  }
  p=head;

  freelist(p);


  return 0;
}
