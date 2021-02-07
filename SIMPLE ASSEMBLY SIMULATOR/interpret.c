#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int decide(char xyz[100]) {
  if(isalpha(xyz[0])) {
    return 1337;
  } else {
    return 42;
  }
  return 0;
}
int main(int argc, char* argv[])
{
short int ax;
short int bx;
short int cx;
short int dx;

FILE *fp = fopen(argv[1], "r");
if(fp == NULL) {
  return(-1);
}


int pagecount = 0;
char str[100];
char matrix[100][100];

 while(fgets(str, 100, fp)){
  strcpy(matrix[pagecount],str);
  pagecount++;
}
fclose(fp);

char *command = malloc(128);
for(int i = 0; i < pagecount; i++) {
  if(isalpha(matrix[i][0])) {
    sscanf(matrix[i], "%s", command);

if(strcmp(command, "add") == 0) {
  char op1[100];
  char op2[100];
  sscanf(matrix[ i], "%s %s %s",command, op1, op2);

  if(strcmp(op1, "ax") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax+ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx+ax;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx+ax;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx+ax;
    }
  } else if(strcmp(op1, "bx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax+bx;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx+bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx+bx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx+bx;
    }
  } else if(strcmp(op1, "cx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax+cx;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx+cx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx+cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx+cx;
    }

  } else if(strcmp(op1, "dx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax+dx;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx+dx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx+dx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx+dx;
    }
  } else {
    short int temp = atoi(op1);
    if(strcmp(op2, "ax") == 0) {
      ax = ax+temp;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx+temp;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx+temp;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx+temp;
    }
    continue;
  }
    continue;
} else if(strcmp(command, "sub") == 0) {
  char op1[100];
  char op2[100];
  sscanf(matrix[ i], "%s %s %s",command, op1, op2);

  if(strcmp(op1, "ax") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax-ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx-ax;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx-ax;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx-ax;
    }
  } else if(strcmp(op1, "bx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax-bx;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx-bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx-bx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx-bx;
    }
  } else if(strcmp(op1, "cx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax-cx;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx-cx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx-cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx-cx;
    }

  } else if(strcmp(op1, "dx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax-dx;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx-dx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx-dx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx-dx;
    }
  } else {
    short int temp = atoi(op1);
    if(strcmp(op2, "ax") == 0) {
      ax = ax-temp;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx-temp;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx-temp;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx-temp;
    }
    continue;
  }
  continue;
} else if(strcmp(command, "mul") == 0) {
      char op1[100];
      char op2[100];
      sscanf(matrix[ i], "%s %s %s",command, op1, op2);

      if(strcmp(op1, "ax") == 0) {
        if(strcmp(op2, "ax") == 0) {
          ax = ax*ax;
        } else if(strcmp(op2, "bx") == 0) {
          bx = bx*ax;
        } else if(strcmp(op2, "cx") == 0) {
          cx = cx*ax;
        } else if(strcmp(op2, "dx") == 0) {
          dx = dx*ax;
        }
      } else if(strcmp(op1, "bx") == 0) {
        if(strcmp(op2, "ax") == 0) {
          ax = ax*bx;
        } else if(strcmp(op2, "bx") == 0) {
          bx = bx*bx;
        } else if(strcmp(op2, "cx") == 0) {
          cx = cx*bx;
        } else if(strcmp(op2, "dx") == 0) {
          dx = dx*bx;
        }
      } else if(strcmp(op1, "cx") == 0) {
        if(strcmp(op2, "ax") == 0) {
          ax = ax*cx;
        } else if(strcmp(op2, "bx") == 0) {
          bx = bx*cx;
        } else if(strcmp(op2, "cx") == 0) {
          cx = cx*cx;
        } else if(strcmp(op2, "dx") == 0) {
          dx = dx*cx;
        }

      } else if(strcmp(op1, "dx") == 0) {
        if(strcmp(op2, "ax") == 0) {
          ax = ax*dx;
        } else if(strcmp(op2, "bx") == 0) {
          bx = bx*dx;
        } else if(strcmp(op2, "cx") == 0) {
          cx = cx*dx;
        } else if(strcmp(op2, "dx") == 0) {
          dx = dx*dx;
        }
      } else {
        short int temp = atoi(op1);
        if(strcmp(op2, "ax") == 0) {
          ax = ax*temp;
        } else if(strcmp(op2, "bx") == 0) {
          bx = bx*temp;
        } else if(strcmp(op2, "cx") == 0) {
          cx = cx*temp;
        } else if(strcmp(op2, "dx") == 0) {
          dx = dx*temp;
        }
        continue;
      }
continue;
} else if(strcmp(command, "div") == 0) {
  char op1[100];
  char op2[100];
  sscanf(matrix[ i], "%s %s %s",command, op1, op2);

  if(strcmp(op1, "ax") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = ax/ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = ax/bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = ax/cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = ax/dx;
    }
  } else if(strcmp(op1, "bx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = bx/ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = bx/bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = bx/cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = bx/dx;
    }
  } else if(strcmp(op1, "cx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = cx/ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = cx/bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = cx/cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = cx/dx;
    }

  } else if(strcmp(op1, "dx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      ax = dx/ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = dx/bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = dx/cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = dx/dx;
    }
  } else {
    short int temp = atoi(op1);
    if(strcmp(op2, "ax") == 0) {
      ax = temp/ax;
    } else if(strcmp(op2, "bx") == 0) {
      bx = temp/bx;
    } else if(strcmp(op2, "cx") == 0) {
      cx = temp/cx;
    } else if(strcmp(op2, "dx") == 0) {
      dx = temp/dx;
    }
    continue;
  }
continue;
} else if(strcmp(command, "mov") == 0) {
  char op1[100];
  char op2[100];
  sscanf(matrix[ i], "%s %s %s",command, op1, op2);

  if(strcmp(op1, "ax") == 0) {
    if(strcmp(op2, "ax") == 0) {
      short int temp = ax;
      ax = temp;
    } else if(strcmp(op2, "bx") == 0) {
      short int temp = ax;
      bx = temp;
    } else if(strcmp(op2, "cx") == 0) {
      short int temp = ax;
      cx = temp;
    } else if(strcmp(op2, "dx") == 0) {
      short int temp = ax;
      dx = temp;
    }
  } else if(strcmp(op1, "bx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      short int temp = bx;
      ax = temp;
    } else if(strcmp(op2, "bx") == 0) {
      short int temp = bx;
      bx = temp;
    } else if(strcmp(op2, "cx") == 0) {
      short int temp = bx;
      cx = temp;
    } else if(strcmp(op2, "dx") == 0) {
      short int temp = bx;
      dx = temp;
    }
  } else if(strcmp(op1, "cx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      short int temp = cx;
      ax = temp;
    } else if(strcmp(op2, "bx") == 0) {
      short int temp = cx;
      bx = temp;
    } else if(strcmp(op2, "cx") == 0) {
      short int temp = cx;
      cx = temp;
    } else if(strcmp(op2, "dx") == 0) {
      short int temp = cx;
      dx = temp;
    }
  } else if(strcmp(op1, "dx") == 0) {
    if(strcmp(op2, "ax") == 0) {
      short int temp = dx;
      ax = temp;
    } else if(strcmp(op2, "bx") == 0) {
      short int temp = dx;
      bx = temp;
    } else if(strcmp(op2, "cx") == 0) {
      short int temp = dx;
      cx = temp;
    } else if(strcmp(op2, "dx") == 0) {
      short int temp = dx;
      dx = temp;
    }
  } else {
    short int temp = atoi(op1);
    if(strcmp(op2, "ax") == 0) {
      ax = temp;
    } else if(strcmp(op2, "bx") == 0) {
      bx = temp;
    } else if(strcmp(op2, "cx") == 0) {
      cx = temp;
    } else if(strcmp(op2, "dx") == 0) {
      dx = temp;
    }
    continue;
  }
continue;
} else if(strcmp(command, "jmp") == 0) {
  char temp[100];
  sscanf(matrix[i], "%s %s",command, temp);
  int t1 = atoi(temp);
  t1 = t1-1;
  //printf("This is ax %d\n", ax);
  i = t1;
continue;
} else if(strcmp(command, "je") == 0) {
  char op1[100];
  char op2[100];
  char op3[100];
  sscanf(matrix[ i], "%s %s %s %s",command, op1, op2, op3);
  //printf("%s %s %s\n", op1, op2, op3);
  int t1 = decide(op2);

  short int bin1 = 0;
  short int bin2 = 0;
  if(isalpha(op2[0])) {
    if(strcmp(op2, "ax") == 0) {
      bin1 = ax;
    } else if(strcmp(op2, "bx") == 0) {
      bin1 = bx;
    } else if(strcmp(op2, "cx") == 0) {
      bin1 = cx;
    } else if(strcmp(op2, "dx") == 0) {
      bin1 = dx;
    }
  } else {
    bin1 = atoi(op2);
  }

  if(isalpha(op3[0])) {
    if(strcmp(op3, "ax") == 0) {
      bin2 = ax;
    } else if(strcmp(op3, "bx") == 0) {
      bin2 = bx;
    } else if(strcmp(op3, "cx") == 0) {
      bin2 = cx;
    } else if(strcmp(op3, "dx") == 0) {
      bin2 = dx;
    }
  } else {
    bin2 = atoi(op3);
  }

  if(bin1 == bin2) {
    int t1 = atoi(op1);
    t1 = t1-1;
    i = t1;
    continue;
  }
continue;
} else if(strcmp(command, "jne") == 0) {
  char op1[100];
  char op2[100];
  char op3[100];
  sscanf(matrix[ i], "%s %s %s %s",command, op1, op2, op3);
  //printf("%s %s %s\n", op1, op2, op3);
  int t1 = decide(op2);

  short int bin1 = 0;
  short int bin2 = 0;
  if(isalpha(op2[0])) {
    if(strcmp(op2, "ax") == 0) {
      bin1 = ax;
    } else if(strcmp(op2, "bx") == 0) {
      bin1 = bx;
    } else if(strcmp(op2, "cx") == 0) {
      bin1 = cx;
    } else if(strcmp(op2, "dx") == 0) {
      bin1 = dx;
    }
  } else {
    bin1 = atoi(op2);
  }

  if(isalpha(op3[0])) {
    if(strcmp(op3, "ax") == 0) {
      bin2 = ax;
    } else if(strcmp(op3, "bx") == 0) {
      bin2 = bx;
    } else if(strcmp(op3, "cx") == 0) {
      bin2 = cx;
    } else if(strcmp(op3, "dx") == 0) {
      bin2 = dx;
    }
  } else {
    bin2 = atoi(op3);
  }

  if(bin1 != bin2) {
    int t1 = atoi(op1);
    t1 = t1-1;
    i = t1;
    continue;
  }
continue;
} else if(strcmp(command, "jg") == 0) {
  char op1[100];
  char op2[100];
  char op3[100];
  sscanf(matrix[ i], "%s %s %s %s",command, op1, op2, op3);
  //printf("%s %s %s\n", op1, op2, op3);
  int t1 = decide(op2);

  short int bin1 = 0;
  short int bin2 = 0;
  if(isalpha(op2[0])) {
    if(strcmp(op2, "ax") == 0) {
      bin1 = ax;
    } else if(strcmp(op2, "bx") == 0) {
      bin1 = bx;
    } else if(strcmp(op2, "cx") == 0) {
      bin1 = cx;
    } else if(strcmp(op2, "dx") == 0) {
      bin1 = dx;
    }
  } else {
    bin1 = atoi(op2);
  }

  if(isalpha(op3[0])) {
    if(strcmp(op3, "ax") == 0) {
      bin2 = ax;
    } else if(strcmp(op3, "bx") == 0) {
      bin2 = bx;
    } else if(strcmp(op3, "cx") == 0) {
      bin2 = cx;
    } else if(strcmp(op3, "dx") == 0) {
      bin2 = dx;
    }
  } else {
    bin2 = atoi(op3);
  }

  if(bin1 > bin2) {
    int t1 = atoi(op1);
    t1 = t1-1;
    i = t1;
    continue;
  }
continue;
} else if(strcmp(command, "jge") == 0) {
  char op1[100];
  char op2[100];
  char op3[100];
  sscanf(matrix[ i], "%s %s %s %s",command, op1, op2, op3);
  //printf("%s %s %s\n", op1, op2, op3);
  int t1 = decide(op2);

  short int bin1 = 0;
  short int bin2 = 0;
  if(isalpha(op2[0])) {
    if(strcmp(op2, "ax") == 0) {
      bin1 = ax;
    } else if(strcmp(op2, "bx") == 0) {
      bin1 = bx;
    } else if(strcmp(op2, "cx") == 0) {
      bin1 = cx;
    } else if(strcmp(op2, "dx") == 0) {
      bin1 = dx;
    }
  } else {
    bin1 = atoi(op2);
  }

  if(isalpha(op3[0])) {
    if(strcmp(op3, "ax") == 0) {
      bin2 = ax;
    } else if(strcmp(op3, "bx") == 0) {
      bin2 = bx;
    } else if(strcmp(op3, "cx") == 0) {
      bin2 = cx;
    } else if(strcmp(op3, "dx") == 0) {
      bin2 = dx;
    }
  } else {
    bin2 = atoi(op3);
  }

  if(bin1 > bin2 || bin1 == bin2) {
    int t1 = atoi(op1);
    t1 = t1-1;
    i = t1;
    continue;
  }
continue;
} else if(strcmp(command, "jl") == 0) {
  char op1[100];
  char op2[100];
  char op3[100];
  sscanf(matrix[ i], "%s %s %s %s",command, op1, op2, op3);
  //printf("%s %s %s\n", op1, op2, op3);
  int t1 = decide(op2);

  short int bin1 = 0;
  short int bin2 = 0;
  if(isalpha(op2[0])) {
    if(strcmp(op2, "ax") == 0) {
      bin1 = ax;
    } else if(strcmp(op2, "bx") == 0) {
      bin1 = bx;
    } else if(strcmp(op2, "cx") == 0) {
      bin1 = cx;
    } else if(strcmp(op2, "dx") == 0) {
      bin1 = dx;
    }
  } else {
    bin1 = atoi(op2);
  }

  if(isalpha(op3[0])) {
    if(strcmp(op3, "ax") == 0) {
      bin2 = ax;
    } else if(strcmp(op3, "bx") == 0) {
      bin2 = bx;
    } else if(strcmp(op3, "cx") == 0) {
      bin2 = cx;
    } else if(strcmp(op3, "dx") == 0) {
      bin2 = dx;
    }
  } else {
    bin2 = atoi(op3);
  }

  if(bin1 < bin2) {
    int t1 = atoi(op1);
    t1 = t1-1;
    i = t1;
    continue;
  }
continue;
} else if(strcmp(command, "jle") == 0) {
  char op1[100];
  char op2[100];
  char op3[100];
  sscanf(matrix[ i], "%s %s %s %s",command, op1, op2, op3);
  //printf("%s %s %s\n", op1, op2, op3);
  int t1 = decide(op2);

  short int bin1 = 0;
  short int bin2 = 0;
  if(isalpha(op2[0])) {
    if(strcmp(op2, "ax") == 0) {
      bin1 = ax;
    } else if(strcmp(op2, "bx") == 0) {
      bin1 = bx;
    } else if(strcmp(op2, "cx") == 0) {
      bin1 = cx;
    } else if(strcmp(op2, "dx") == 0) {
      bin1 = dx;
    }
  } else {
    bin1 = atoi(op2);
  }

  if(isalpha(op3[0])) {
    if(strcmp(op3, "ax") == 0) {
      bin2 = ax;
    } else if(strcmp(op3, "bx") == 0) {
      bin2 = bx;
    } else if(strcmp(op3, "cx") == 0) {
      bin2 = cx;
    } else if(strcmp(op3, "dx") == 0) {
      bin2 = dx;
    }
  } else {
    bin2 = atoi(op3);
  }

  if(bin1 < bin2 || bin1 == bin2) {
    int t1 = atoi(op1);
    t1 = t1-1;
    i = t1;
    continue;
  }


continue;
} else if(strcmp(command, "read") == 0) {
  char temp[100];
  scanf("%s", temp);
  char *regi = malloc(128);
  sscanf(matrix[i], "%s %s",command, regi);

      if(strcmp(regi, "ax") == 0) {
        ax = atoi(temp);
      } else if(strcmp(regi, "bx") == 0) {
        bx = atoi(temp);
      } else if(strcmp(regi, "cx") == 0) {
        cx = atoi(temp);
      } else if(strcmp(regi, "dx") == 0) {
        dx = atoi(temp);
      }
      free(regi);
continue;
} else if(strcmp(command, "print") == 0) {
//  printf("Register State ax:%d bx:%d cx:%d dx:%d\n", ax, bx, cx, dx);
  char *regi = malloc(128);
//  printf("This is ax :%d\n", ax);
  sscanf(matrix[i], "%s %s",command, regi);
      if(strcmp(regi, "ax") == 0) {
        printf("%d", ax);
      } else if(strcmp(regi, "bx") == 0) {
        printf("%d", bx);
      } else if(strcmp(regi, "cx") == 0) {
        printf("%d", cx);
      } else if(strcmp(regi, "dx") == 0) {
        printf("%d", dx);
      } else {
        printf("%d", atoi(regi));
      }
      free(regi);
continue;
}
  } else {
    continue;
  }

}
printf("\n");
return(0);
}
