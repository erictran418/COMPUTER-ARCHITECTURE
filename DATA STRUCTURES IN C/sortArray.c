#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void ascendinginsertionSort(int arr[], int count) {
int i, key, j;

for(i = 1; i < count; i++) {
key = arr[i];
j= i-1;

while(j >= 0 && arr[j] > key) {
arr[j+1] = arr[j];
j = j-1;
}
arr[j+1] = key;
}
}




void descendinginsertionSort(int arr[], int count) {
  int i, key, j;

for(i=1; i<count;i++) {
  j = i;

  while(j>0 && arr[j] > arr[j-1]) {
    key = arr[j];
    arr[j]=arr[j-1];
    arr[j-1] = key;
    j--;
  }
}


}

int main(int argc, char* argv[])
{

FILE *fp;
fp = fopen(argv[1], "r");
char line[200];

fgets(line, 200, fp);
int x = atoi(line);


int c;
int length = 0;
char temp[500];

if(fp) {
  while((c = getc(fp)) != EOF) {
    temp[length] = c;
    length++;

  }
}

temp[length] = '\0';

char a[50][50];
int count = 0;
char work[50] = "";

int i = 0;
for(i; i < length; i++) {
if (isspace(temp[i])) {
  strcpy(a[count], work);
  count++;
  strcpy(work, "");
} else {
  strncat(work, &temp[i], 1);
}
}

char test[50] = "";



while(strcmp(work,test)!=0) {
  strcpy(a[count], work);
  count++;
  strcpy(work, "");
}

strcpy(a[count], "\0");



int odd[50];
int even[50];
int oddcount = 0;
int evencount = 0;


for(int u = 0; u < count; u++) {

int z = atoi(a[u]);


if(z == 0) {
  even[evencount] = z;
  evencount++;
  continue;
}
if(z%2==0) {
  even[evencount] = z;
  evencount++;
  continue;
} else {
  odd[oddcount] = z;
  oddcount++;
  continue;
}
}




ascendinginsertionSort(even, evencount);
descendinginsertionSort(odd, oddcount);

int final[50];
int marker = 0;
for (int r = 0; r < evencount; r++) {
  final[marker] = even[r];
  marker++;
}
for(int p = 0; p < oddcount; p++) {
  final[marker] = odd[p];
  marker++;
}

for(int e = 0; e<marker;e++) {
  printf("%d\t", final[e]);
}




fclose(fp);



return 0;

}
