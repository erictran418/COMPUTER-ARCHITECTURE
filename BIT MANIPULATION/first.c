#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int getter(unsigned short number, int place);
unsigned short setter(unsigned short number, int place, int target);
unsigned short inverse(unsigned short number, int place);

int main(int argc, char* argv[])
{
/*
unsigned short x = 5;
int work = 15;
do{
  printf("%d", get(x, work));
  work--;
} while(work>=0);
printf("\n");
*/
FILE *fp = fopen(argv[1], "r");
int filesize;
fseek(fp, 0L, SEEK_END);
filesize = ftell(fp);
rewind(fp);
int c;
fscanf(fp, "%d", &c);
unsigned short x = (unsigned short)c;

int length = 0;
char temp[filesize];

if(fp) {
  while((c = getc(fp)) != EOF) {
    if(isspace(c) && length == 0) {
      continue;
    }
    temp[length] = c;
    length++;
  }
}
fclose(fp);

char buffer[500] = "";
char a[filesize][filesize];
int count = 0;
char space[50] = "";

for(int i = 0; i < length; i++) {
if(isspace(temp[i])) {
  if(strcmp(buffer, space) == 0) {
    continue;
  }
  strcpy(a[count], buffer);
    count++;
    strcpy(buffer, "");

}

if(isalpha(temp[i])) {
  strncat(buffer, &temp[i], 1);

}

if(isdigit(temp[i])) {
  strncat(buffer, &temp[i], 1);

}
}
if(buffer != "") {
  strcpy(a[count], buffer);
    count++;
}
/*
for(int i = 0; i <count; i++) {
  printf("%s\n", a[i]);
}
*/
char set[50] = "set";
char get[50] = "get";
char comp[50] = "comp";

for(int i = 0; i < count; i++) {
  int c = i+1;
  int b = i+2;

  if(strcmp(a[i],set) == 0) {
  int tc = atoi(a[c]);
  int tb = atoi(a[b]);
  x = setter(x, tc, tb);
  printf("%d\n", x);
  continue;
  }
  if(strcmp(a[i],get) == 0) {
  int temp = atoi(a[c]);
  printf("%d\n", getter(x, temp));
  continue;
  }
  if(strcmp(a[i],comp) == 0) {
    int tc = atoi(a[c]);
    int tb = atoi(a[b]);
    x = inverse(x, tc);
    printf("%d\n", x);
    continue;

  }

}




return 0;
}

int getter(unsigned short number, int place) {

  int result = (number>>place) & 1;
  return result;
}

unsigned short setter(unsigned short number, int place, int target) {

unsigned short result;
if(target == 1) {
  result = (1<<place) | number;
  return result;
} else {
  result = number & ~(1<<place);
  return result;
}

}

unsigned short inverse(unsigned short number, int place) {

unsigned short result = number^(1<<place);
return result;
}
