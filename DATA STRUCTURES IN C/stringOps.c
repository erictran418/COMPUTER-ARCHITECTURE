#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char word[50];
  int counter = 0;



for(int i = 1; i<argc; i++) {

for(int j = 0; j < strlen(argv[i]); j++) {
  if(argv[i][j] == 'a' || argv[i][j] == 'e' || argv[i][j] == 'i' || argv[i][j] == 'o' || argv[i][j] == 'u' || argv[i][j] == 'A' || argv[i][j] == 'E' || argv[i][j] == 'I' || argv[i][j] == 'O' || argv[i][j] == 'U') {
    word[counter] = argv[i][j];
    counter++;
  }
}

}
word[counter] = '\0';

printf("%s\n", word);
return 0;

}
