#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <ctype.h>

#define TABLE_SIZE 10000
int collisioncount = 0;
int searching = 0;

typedef struct node
{
  int data;
  struct node *next;
}
node;
void insert();

node** gethashtable() {
  node** hashtable = calloc(TABLE_SIZE, sizeof(node*));
  return hashtable;
}
int getlocation(int value) {
  if(value <0) {
    return (value % TABLE_SIZE) + TABLE_SIZE;
  }
  return value % TABLE_SIZE;
}

void tableinsert(node** hashtable, int value) {
  int location = getlocation(value);
  if(hashtable[location] == NULL) {
    //hashtable[location] = malloc(sizeof(node*));

    node* head = NULL;
    insert(&head, value);

    hashtable[location] = head;
  } else{
    collisioncount++;
    node* head = hashtable[location];
    insert(&head, value);
    hashtable[location] = head;

  }
}

node* create(node*next, int target) {
  node* new = (struct node*)malloc(sizeof(struct node));

  new->data = target;
  new->next = next;

  return new;
}

int contains(node** head, int value) {
  if(*head == NULL) {
    return 0;
  }
node* ptr = *head;
int gate = 0;

while(ptr!=NULL) {
  if(ptr->data == value) {
    gate = 1;
    return gate;
  }
ptr = ptr->next;
}

gate = 0;
return gate;
}

void insert(node** head, int target) {
  int canary = contains(head, target);
  if(canary == 1) {
    return;
  }

  node* new = create(NULL, target);

  if(*head == NULL) {
    (*head) = new;
    return;
  }


node *pointer = *head;


  while(pointer->next != NULL) {
    pointer = pointer->next;
  }
  pointer->next = new;
}

void display(node** hashtable) {

  for(int i = 0; i < TABLE_SIZE; i++) {
    node* head = hashtable[i];

    printf("The index is: %d\n", i);

    if (head == NULL) {
      printf("NULL");
    } else {
      node* temp = head;

      while (temp != NULL) {
        printf("The node is: %d\n", temp->data);
        temp = temp->next;
      }
    }
    printf("New line \n");
  }

}

void search(node**hashtable, int target, int key) {
  if(hashtable[key] == NULL) {
    return;
  }
  if(hashtable[key] != NULL) {
    node* curr = hashtable[key];

    while(curr != NULL) {
      if(curr->data == target) {
        searching++;
        return;
      }
      curr = curr->next;
    }
  }

}

void unload(node**hashtable)
{
        node* temp;
        node* crawler;

        for(int n = 0; n < TABLE_SIZE; n++)
        {
            if (hashtable[n] != NULL)
            {

                crawler = hashtable[n];
                while (crawler != NULL)
                {
                    temp = crawler->next;
                    free(crawler);
                    crawler = temp;

                }
                hashtable[n] = NULL;

            }
            if(hashtable[n] == NULL) {
              free(hashtable[n]);
            }

        }
        return;
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

  int fnum[50];

  for(int i = 0; i <numcount; i++) {
  fnum[i] = atoi(num[i]);
  }
  fclose(fp);
  fnum[numcount] = '\0';
  command[commandcount] = '\0';

  //Program code starts here



int searchcount = 0;
node** table = gethashtable();
for(int j = 0; j <numcount; j++) {
if(command[j] == 'i') {
  tableinsert(table, fnum[j]);
}
if(command[j] == 's') {
  int temp = getlocation(fnum[j]);
search(table, fnum[j], temp);
}

}
printf("%d\n", collisioncount);
//display(table)
printf("%d\n", searching);
unload(table);

free(table);




return 0;

}
