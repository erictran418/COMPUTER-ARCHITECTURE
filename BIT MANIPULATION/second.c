#include <stdio.h>
#include <stdlib.h>

int pair = 0;
int count = 0;
int combo = 0;

int get(unsigned short number, int place);

int main(int argc, char* argv[])
{
unsigned short x = atoi(argv[1]);

for(int i = 0; i < 16; i++) {
  int z = get(x,i);

  if(z == 1) {

  count++;
  combo++;

  if(combo%2==0) {
    pair++;
  }
  } else {

    combo = 0;
  }

}

if(count%2==0) {
printf("Even-Parity\t%d\n",pair);
} else {
printf("Odd-Parity\t%d\n",pair);
}

}

int get(unsigned short number, int place) {
  int result = (number>>place) & 1;
  return result;
}
