#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int get(int number, int place) {
  int result = (number>>place) & 1;
  return result;
}

struct Matrix {
char name[100];
int data;
int length;
};

int findplace(struct Matrix yup[][50], int n1, char name[100]) {

for(int i = 0; i < n1; i++) {
  //printf("%s %d ",yup[0][i].name, i);
  if(strcmp(yup[0][i].name, name) == 0) {
    return i;
  }

}
  return -1;
}

int main(int argc, char* argv[])
{
char delim[] = " \t\r\n\v\f";
/*
int test = 2;
for(int i = 0; i < 9; i++) {
printf("%d", get(test,i));
}
printf("\n");
*/
FILE *fp = fopen(argv[1], "r");
char line[100];
char str[100];
char *p = NULL;
//INPUTVAR
fgets(line, 100, fp);
p = strtok(line, delim);
int st1 = 0;
int n1 = 0;
while(p != NULL) {
  strcpy(str,p);
  if(st1 == 1) {
    n1 = atoi(str);
    //printf("This is n1: %d\n", n1);
    st1 = 43;
  }
  if(strcmp(str, "INPUTVAR") == 0) {
  st1 = 1;
  }
  p = strtok(NULL, delim);
}

rewind(fp);
struct Matrix inputvar[(int)(pow(2,n1))][50];
//printf("%d\n",(int)(pow(2,n1)));

fgets(line, 100, fp);
p = strtok(line, delim);
int it1 = 0;
int colcount1 = 0;

while(p != NULL) {
  if(it1 <= 1) {
    p = strtok(NULL, delim);
  } else {
    strcpy(str,p);
    //printf("%s\n",str);
    strcpy(inputvar[0][colcount1].name,str);
    //printf("inputvar[0][%d].name = %s\n",colcount1,inputvar[0][colcount1].name);
    p = strtok(NULL, delim);
    colcount1++;
  }
  it1++;
}


//OUTPUTVAR
fgets(line, 100, fp);
p = strtok(line, delim);
int st2 = 0;
int n2 = 0;
while(p != NULL) {
  strcpy(str,p);
  if(st2 == 1) {
    n2 = atoi(str);
    //printf("This is n2: %d\n", n2);
    st2 = 43;
  }
  if(strcmp(str, "OUTPUTVAR") == 0) {
  st2 = 1;
  }
  p = strtok(NULL, delim);
}

rewind(fp);
struct Matrix outputvar[(int)(pow(2,n1))][50];
//printf("%d\n",(int)(pow(2,n2)));

fgets(line, 100, fp);
fgets(line, 100, fp);

p = strtok(line, delim);
int it2 = 0;
int colcount2 = 0;

while(p != NULL) {
  if(it2 <= 1) {
    p = strtok(NULL, delim);
  } else {
    strcpy(str,p);
    //printf("%s\n",str);
    strcpy(outputvar[0][colcount2].name,str);
    //printf("outputvar[0][%d].name = %s\n",colcount2,outputvar[0][colcount2].name);
    p = strtok(NULL, delim);
    colcount2++;
  }
  it2++;
}

int exp1 = (int)(pow(2,n1));
//printf("%d\n",exp1);

  for(int j = 0; j < exp1; j++) {
    int binplace = n1;
    for(int i = 0; i < n1; i++) {
      binplace--;
      inputvar[j][i].data = get(j,binplace);
      //printf("%d",inputvar[j][i].data);
    }
    //printf("\n");
  }

int afterinput1 = n1;


//Rest of the FILE
char list[900][100];


int listsize = 0;
while(fgets(line, 100, fp) != NULL) {
  p = strtok(line, delim);

  while(p != NULL) {
    strcpy(list[listsize],p);
      p = strtok(NULL, delim);
      listsize++;
  }
}

char command[900][100];
char ops[900][100];
int commandsize = 0;
int opsize = 0;

for(int i = 0; i < listsize; i++) {
if(strcmp(list[i], "NOT") == 0 || strcmp(list[i], "AND") == 0 || strcmp(list[i], "OR") == 0 || strcmp(list[i], "NAND") == 0 || strcmp(list[i], "NOR") == 0 ||strcmp(list[i], "XOR") == 0) {

} else {
  if(findplace(inputvar, afterinput1, list[i]) == -1 && findplace(outputvar, n2, list[i]) == -1) {
    strcpy(inputvar[0][afterinput1].name, list[i]);
    afterinput1++;
  }
}
}

for(int i = 0; i < listsize; i++) {
if(strcmp(list[i], "NOT") == 0 || strcmp(list[i], "AND") == 0 || strcmp(list[i], "OR") == 0 || strcmp(list[i], "NAND") == 0 || strcmp(list[i], "NOR") == 0 ||strcmp(list[i], "XOR") == 0) {
strcpy(command[commandsize], list[i]);
commandsize++;
} else {
    strcpy(ops[opsize], list[i]);
    opsize++;

}
}
/*
for(int i = 0; i <commandsize;i++) {
  printf("%s\n",command[i]);
}
printf("\n");
for(int i = 0; i <opsize;i++) {
  printf("%s\n",ops[i]);
}
*/
/*
  for(int i = 0; i < afterinput1; i++) {
    printf("[0][%d].name = %s ",i,inputvar[0][i].name);
  }
  printf("\n");
  for(int i = 0; i < n2; i++) {
    printf("[0][%d].name = %s ",i,outputvar[0][i].name);
  }
  printf("\n");

/*
for(int i = 0; i < listsize; i++) {
  printf("%s\n", list[i]);
}
printf("%d\n",listsize);
*/

int work = 0;
for(int i = 0; i < commandsize; i++) {
  if(work>opsize) {
    break;
  }
//
if(strcmp(command[i], "NOT") == 0) {
  int a = work;
  int b = work+1;
  int p1 = findplace(inputvar, afterinput1, ops[a]);
  int p2 = findplace(inputvar,afterinput1, ops[b]);
  if(p2 == -1) {
    p2 = findplace(outputvar, n2, ops[b]);
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1) {
        outputvar[x][p2].data = 0;
      } else {
        outputvar[x][p2].data = 1;
      }
    }

  } else {
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1) {
        inputvar[x][p2].data = 0;
      } else {
        inputvar[x][p2].data = 1;
      }
    }
  }
  work = b+1;
}
//
else if(strcmp(command[i], "AND") == 0) {
  int a = work;
  int b = work+1;
  int c = work+2;
  int p1 = findplace(inputvar, afterinput1, ops[a]);
  int p2 = findplace(inputvar,afterinput1, ops[b]);
  int p3 = findplace(inputvar,afterinput1, ops[c]);

  if(p3 == -1) {
    p3 = findplace(outputvar, n2, ops[c]);
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 && inputvar[x][p2].data==1) {
        outputvar[x][p3].data = 1;
      } else {
        outputvar[x][p3].data = 0;
      }
    }

  } else {
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 && inputvar[x][p2].data==1) {
        inputvar[x][p3].data = 1;
      } else {
        inputvar[x][p3].data = 0;
      }
    }
  }
  work = c+1;
}
//
else if(strcmp(command[i], "OR") == 0) {
  int a = work;
  int b = work+1;
  int c = work+2;
  int p1 = findplace(inputvar, afterinput1, ops[a]);
  int p2 = findplace(inputvar,afterinput1, ops[b]);
  int p3 = findplace(inputvar,afterinput1, ops[c]);
  if(p3 == -1) {
    p3 = findplace(outputvar, n2, ops[c]);
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 || inputvar[x][p2].data==1) {
        outputvar[x][p3].data = 1;
      } else {
        outputvar[x][p3].data = 0;
      }
    }
  } else {
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 || inputvar[x][p2].data==1) {
        inputvar[x][p3].data = 1;
      } else {
        inputvar[x][p3].data = 0;
      }
    }
  }
  work = c+1;
}
//
else if(strcmp(command[i], "NAND") == 0) {
  int a = work;
  int b = work+1;
  int c = work+2;
  int p1 = findplace(inputvar, afterinput1, ops[a]);
  int p2 = findplace(inputvar,afterinput1, ops[b]);
  int p3 = findplace(inputvar,afterinput1, ops[c]);
  if(p3 == -1) {
    p3 = findplace(outputvar, n2, ops[c]);
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 0 || inputvar[x][p2].data==0) {
        outputvar[x][p3].data = 1;
      } else {
        outputvar[x][p3].data = 0;
      }
    }
  } else {
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 || inputvar[x][p2].data==1) {
        inputvar[x][p3].data = 1;
      } else {
        inputvar[x][p3].data = 0;
      }
    }
  }
  work = c+1;
}
//
else if(strcmp(command[i], "NOR") == 0) {
  int a = work;
  int b = work+1;
  int c = work+2;
  int p1 = findplace(inputvar, afterinput1, ops[a]);
  int p2 = findplace(inputvar,afterinput1, ops[b]);
  int p3 = findplace(inputvar,afterinput1, ops[c]);
  if(p3 == -1) {
    p3 = findplace(outputvar, n2, ops[c]);
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 0 && inputvar[x][p2].data==0) {
        outputvar[x][p3].data = 1;
      } else {
        outputvar[x][p3].data = 0;
      }
    }
  } else {
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 0 && inputvar[x][p2].data==0) {
        inputvar[x][p3].data = 1;
      } else {
        inputvar[x][p3].data = 0;
      }
    }

  }
  work = c+1;
}
//
else if(strcmp(command[i], "XOR") == 0) {
  int a = work;
  int b = work+1;
  int c = work+2;
  int p1 = findplace(inputvar, afterinput1, ops[a]);
  int p2 = findplace(inputvar,afterinput1, ops[b]);
  int p3 = findplace(inputvar,afterinput1, ops[c]);
  if(p3 == -1) {
    p3 = findplace(outputvar, n2, ops[c]);
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 && inputvar[x][p2].data==0) {
        outputvar[x][p3].data = 1;
      } else if(inputvar[x][p1].data == 0 && inputvar[x][p2].data==1){
        outputvar[x][p3].data = 1;
      } else {
        outputvar[x][p3].data = 0;
      }
    }
  } else {
    for(int x = 0; x < exp1; x++) {
      if(inputvar[x][p1].data == 1 && inputvar[x][p2].data==0) {
        inputvar[x][p3].data = 1;
      } else if(inputvar[x][p1].data == 0 && inputvar[x][p2].data==1){
        inputvar[x][p3].data = 1;
      } else {
        inputvar[x][p3].data = 0;
      }
    }
  }
  work = c+1;
}
//
}

for(int i = 0; i < exp1; i++) {
  for(int j = 0; j < n1; j++) {
    printf("%d ",inputvar[i][j].data);
  }
  for(int x = 0; x < n2; x++) {
    printf("%d ", outputvar[i][x].data);
  }
  printf("\n");
}









}
