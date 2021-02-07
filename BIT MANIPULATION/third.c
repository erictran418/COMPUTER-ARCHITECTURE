#include <stdio.h>
#include <stdlib.h>


int get(unsigned short number, int place);

int main(int argc, char* argv[])
{
int forward = 0;
int backward = 15;
int breakWall = 0;
unsigned short x = atoi(argv[1]);

do{
if(get(x, backward) != get(x, forward)) {
  breakWall++;
}
backward--;
forward++;
}while(backward>=0);

if(breakWall==0) {
  printf("Is-Palindrome\n");
} else {
  printf("Not-Palindrome\n");
}

}

int get(unsigned short number, int place) {
  int result = (number>>place) & 1;
  return result;
}
