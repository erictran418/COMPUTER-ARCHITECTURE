#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int second_power (int x) {
  return x && (!(x&(x-1)));
  //if second_power returns 1 then it is a power of 2
}

unsigned long long int get(unsigned long long int number, int place) {
  int result = (number>>place) & 1;
  return result;
}
struct Cache {
long long int age;
long long int set;
long long int tag;
long long int valid;
long long int full;
};

int fullcheck(struct Cache cache[1000][1000], long long int set, long long int line) {
  return 0;
}

int main(int argc, char* argv[])
{

if(argc!=6) {
  printf("error\n");
  return 1;
}
//checks if argv[1]/cachesize is valid and power of 2
if(isdigit(*argv[1])) {
  int x = atoi(argv[1]);
  x = second_power(x);
  if(x != 1) {
    printf("error\n");
    return 1;
  }
} else {
printf("error\n");
return 1;
}

//checks if argv[2]/associativity is valid
char str1[100];
char *str2;

strcpy(str1, argv[2]);
strtok_r(str1,":",&str2);
if(strcmp(str1, "direct") == 0 || strcmp(str1, "assoc") == 0) {
  if(strcmp(str1, "direct") == 0 && strcmp(str2, "") != 0) {
    printf("error\n");
    return 1;
  }

  if(strcmp(str1, "assoc") == 0 && strcmp(str2, "") != 0) {
    if(isdigit(*str2)) {
      int x = atoi(str2);
      x = second_power(x);
      if(x != 1) {
        printf("error\n");
        return 1;
      }
    } else {
    printf("error\n");
    return 1;
    }
  }
  }
 else {
  printf("error\n");
  return 1;
}


//checks if argv[3]/replacepolicy is valid
char str3[100];
strcpy(str3, argv[3]);
if(strcmp(argv[3], "lru") == 0 || strcmp(argv[3], "fifo") == 0) {
} else {
  printf("error\n");
  return 1;
}

//checks if argv[4]/blocksize is valid and a power of 2
if(isdigit(*argv[4])) {
  int x = atoi(argv[4]);
  x = second_power(x);
  if(x != 1) {
    printf("error\n");
    return 1;
  }
} else {
printf("error\n");
return 1;
}
//maincode
long long int CacheHits = 0;
long long int CacheMisses = 0;
long long int MemWrite = 0;
long long int MemRead = 0;

long long int cachesize;
long long int blocksize;
long long int sets;
long long int lines;
long long int n;
/*
offsetbits = log(blocksize)/log(2)
setbits = log(numberofsets)/log(2)
tagbits = 48 - (offsetbits+setbits)
*/
//direct
if(strcmp(str1, "direct") == 0) {
cachesize = atoi(argv[1]);
blocksize = atoi(argv[4]);
if(blocksize>cachesize) {
  printf("error");
  return 1;
}
lines = 1;
sets = cachesize/blocksize;
long long int offsetbits = log(blocksize)/log(2);
long long int setbits = log(sets)/log(2);
long long int tagbits = 48 - (offsetbits+setbits);

//printf("cachesize:%lld blocksize:%lld sets:%lld\n", cachesize, blocksize, sets);
//printf("offsetbits:%lld setbits:%lld tagbits:%lld\n", offsetbits, setbits, tagbits);

struct Cache cache[sets][lines];
for(int i = 0; i < sets; i++) {
  cache[i][0].valid=0;
  cache[i][0].tag = 0;
}
FILE *fp = fopen(argv[5], "r");

if(fp == NULL) {
  printf("error\n");
  return(1);
}

char str[100];
char pc[100];
char command[100];
char address[100];
int full = 0;


 while(fgets(str, 100, fp) ) {
  sscanf(str, "%s %s %s", pc, command, address);
  if(strcmp(pc,"#eof") == 0) {
    break;
  }
  //printf("%s %s %s\n", pc, command, address);
  long long int addy;
  long long int set;
  long long int tag;
  sscanf(address, "%llx", &addy);

  int tagwork = 48-tagbits;
  tag = addy/pow(2,tagwork);
  //int setwork = 48-setbits;

  set = addy / (long long int) pow(2,offsetbits);
  set = set % (long long int) pow(2,setbits);

  //printf("address: %lld\n", addy);
  //printf("tag: %lld\n", tag);
  //printf("set: %lld\n",set);
/*
  for(int i = 0; i <sets; i++) {
  printf("cache[%d][0].tag = %lld\n", i, cache[i][0].tag);
  }
*/
if(strcmp(command, "W") == 0) {
MemWrite++;

if(cache[set][0].valid == 1 && cache[set][0].tag == tag) {
CacheHits++;
}
 else {
  cache[set][0].valid = 1;
  cache[set][0].tag = tag;
  MemRead++;
  CacheMisses++;
}
} else {
  if(cache[set][0].valid == 1 && cache[set][0].tag == tag) {
  CacheHits++;
  }
   else {
    cache[set][0].valid = 1;
    cache[set][0].tag = tag;
    MemRead++;
    CacheMisses++;
  }
}
}
fclose(fp);
printf("Memory reads: %lld\nMemory writes: %lld\nCache hits: %lld\nCache misses: %lld\n", MemRead, MemWrite, CacheHits, CacheMisses);
}



//assoc and assoc:n
/*assoc test
256 assoc lru 4 tracer1.txt
512 assoc lru 8 tracer1.txt
512 assoc fifo 16 tracer1.txt
*/
if(strcmp(str1, "assoc") == 0) {
if(strcmp(str2, "") == 0) {
cachesize = atoi(argv[1]);
blocksize = atoi(argv[4]);
if(blocksize>cachesize) {
  printf("error\n");
  return 1;
}
sets = 1;
lines = cachesize/blocksize;
long long int offsetbits = log(blocksize)/log(2);
long long int setbits = log(sets)/log(2);
long long int tagbits = 48 - (offsetbits+setbits);

//printf("lines:%lld\noffsetbits:%lld\nsetbits:%lld\ntagbits:%lld\n", lines, offsetbits, setbits, tagbits);

char str[100];
char pc[100];
char command[100];
char address[100];
int full = 0;
struct Cache cache[sets][lines];
for(int i = 0; i < lines ;i++) {
    cache[0][i].age = 0;
    cache[0][i].valid = 0;
}

FILE *fp = fopen(argv[5], "r");

if(fp == NULL) {
  printf("error\n");
  return(1);
}

if(strcmp(str3, "lru") == 0) {
int breek = 0;

  while(fgets(str, 100, fp) ) {
    int fullcount = 0;
    for(int i = 0; i < lines ;i++) {
      if(cache[0][i].valid == 1) {
        cache[0][i].age++;
        fullcount++;
      }
      if(fullcount == lines) {
        breek = 1;
      }
    }
   sscanf(str, "%s %s %s", pc, command, address);
   if(strcmp(pc,"#eof") == 0) {
     break;
   }
   //printf("%s %s %s\n", pc, command, address);
   long long int addy;
   long long int set;
   long long int tag;
   sscanf(address, "%llx", &addy);

   int tagwork = 48-tagbits;
   tag = addy/pow(2,tagwork);
   set = addy / (long long int) pow(2,offsetbits);
   set = set % (long long int) pow(2,setbits);

   if(breek == 1) {
     if(strcmp(command,"W") == 0) {
       MemWrite++;
       int agee = 0;
       long long int place;
       int check = 0;
       for(int i = 0; i < lines; i++) {
         if(cache[0][i].tag == tag) {
           CacheHits++;
           cache[0][i].age = 0;
           check = 1;
           break;
         }

       }
       if(check == 0) {
         for(int i = 0; i < lines; i++) {
           if(cache[0][i].age > agee) {
             agee = cache[0][i].age;
             place = i;
           }
         }
         cache[0][place].tag = tag;
         cache[0][place].age = 0;
         MemRead++;
         CacheMisses++;
       }

     } else {
       int agee = 0;
       long long int place;
       int check = 0;
       for(int i = 0; i < lines; i++) {
         if(cache[0][i].tag == tag) {
           CacheHits++;
           cache[0][i].age = 0;
           check = 1;
           break;
         }

       }
       if(check == 0) {
         for(int i = 0; i < lines; i++) {
           if(cache[0][i].age > agee) {
             agee = cache[0][i].age;
             place = i;
           }
         }
         cache[0][place].tag = tag;
         cache[0][place].age = 0;
         MemRead++;
         CacheMisses++;
       }

     }

   } else {

     if(strcmp(command, "W") == 0) {
       MemWrite++;
       for(int i = 0; i < lines; i++) {
         if(cache[0][i].valid == 1 && cache[0][i].tag == tag) {
          CacheHits++;
          cache[0][i].age = 0;
          break;
        } else if(cache[0][i].valid !=1){
          MemRead++;
          CacheMisses++;
          cache[0][i].tag = tag;
          cache[0][i].valid = 1;
          break;
        }
       }

     } else {
       for(int i = 0; i < lines; i++) {
         if(cache[0][i].valid == 1 && cache[0][i].tag ==tag) {
           CacheHits++;
           cache[0][i].age = 0;
           break;
         } else if(cache[0][i].valid != 1) {
           MemRead++;
           CacheMisses++;
           cache[0][i].tag = tag;
           cache[0][i].valid = 1;
           break;
         }
       }

     }

   }

//while border
  }
  fclose(fp);
  printf("Memory reads: %lld\nMemory writes: %lld\nCache hits: %lld\nCache misses: %lld\n", MemRead, MemWrite, CacheHits, CacheMisses);
}
//assoc fifo
 else {
  int breek = 0;

    while(fgets(str, 100, fp) ) {
      int fullcount = 0;
      for(int i = 0; i < lines ;i++) {
        if(cache[0][i].valid == 1) {
          cache[0][i].age++;
          fullcount++;
        }
        if(fullcount == lines) {
          breek = 1;
        }
      }
     sscanf(str, "%s %s %s", pc, command, address);
     if(strcmp(pc,"#eof") == 0) {
       break;
     }
     //printf("%s %s %s\n", pc, command, address);
     long long int addy;
     long long int set;
     long long int tag;
     sscanf(address, "%llx", &addy);

     int tagwork = 48-tagbits;
     tag = addy/pow(2,tagwork);
     set = addy / (long long int) pow(2,offsetbits);
     set = set % (long long int) pow(2,setbits);

     if(breek == 1) {
      if(strcmp(command,"W")==0) {
        MemWrite++;
        int d = -1;
        long long int place;
        long long int agee = 0;
        for(int i = 0; i < lines; i++) {
          if(cache[0][i].valid == 1 && cache[0][i].tag==tag) {
            CacheHits++;
            d = 0;
            break;
          }
        }
        if(d == -1) {
         for(int i = 0; i < lines; i++) {
           if(cache[0][i].age > agee) {
             agee = cache[0][i].age;
             place = i;
           }
         }
         cache[0][place].age = 0;
         cache[0][place].tag = tag;
         MemRead++;
         CacheMisses++;
        }

      } else {
        int d = -1;
        long long int place;
        long long int agee = 0;
        for(int i = 0; i < lines; i++) {
          if(cache[0][i].valid == 1 && cache[0][i].tag==tag) {
            CacheHits++;
            d = 0;
            break;
          }
        }
        if(d == -1) {
         for(int i = 0; i < lines; i++) {
           if(cache[0][i].age > agee) {
             agee = cache[0][i].age;
             place = i;
           }
         }
         cache[0][place].age = 0;
         cache[0][place].tag = tag;
         MemRead++;
         CacheMisses++;
        }
      }

    } else {
       int d = -1;
       if(strcmp(command, "W") == 0) {
         MemWrite++;
         for(int i = 0; i < lines; i++) {
           if(cache[0][i].valid == 1 && cache[0][i].tag==tag) {
             CacheHits++;
             d = 0;
             break;
           }
         }
         if(d == -1) {
          for(int i = 0; i < lines; i++) {
            if(cache[0][i].valid !=1) {
              cache[0][i].valid = 1;
              cache[0][i].tag = tag;
              MemRead++;
              CacheMisses++;
              break;
            }
          }
         }

       } else {
         for(int i = 0; i < lines; i++) {
           if(cache[0][i].valid == 1 && cache[0][i].tag==tag) {
             CacheHits++;
             d = 0;
             break;
           }
         }
         if(d == -1) {
          for(int i = 0; i < lines; i++) {
            if(cache[0][i].valid !=1) {
              cache[0][i].valid = 1;
              cache[0][i].tag = tag;
              MemRead++;
              CacheMisses++;
              break;
            }
          }
         }

       }

     }
  //while border
    }
    fclose(fp);
    printf("Memory reads: %lld\nMemory writes: %lld\nCache hits: %lld\nCache misses: %lld\n", MemRead, MemWrite, CacheHits, CacheMisses);
}

} //assoc:n
else{
  cachesize = atoi(argv[1]);
  blocksize = atoi(argv[4]);
  n = atoi(str2);
  lines = n;
  sets = cachesize/(n*blocksize);
  if(cachesize < n*blocksize) {
    printf("error\n");
    return 1;
  }
  long long int offsetbits = log(blocksize)/log(2);
  long long int setbits = log(sets)/log(2);
  long long int tagbits = 48 - (offsetbits+setbits);
  char str[100];
  char pc[100];
  char command[100];
  char address[100];
  FILE *fp = fopen(argv[5], "r");


  struct Cache cache[sets][n];
  for(int i = 0; i < sets; i++) {
    for(int j = 0; j < n; j++) {
      cache[i][j].valid = 0;
      cache[i][j].age = 0;
    }
  }
  if(strcmp(str3, "lru") == 0) {
      while(fgets(str, 100, fp) ) {

        for(int i = 0; i < sets; i++) {
          int fullcounter = 0;
          for(int j = 0; j < n; j++) {
          if(cache[i][j].valid == 1) {
            cache[i][j].age++;
            fullcounter++;
          }
          if(fullcounter == n) {
            cache[i][0].full == 1;
          }
          }
        }

       sscanf(str, "%s %s %s", pc, command, address);
       if(strcmp(pc,"#eof") == 0) {
         break;
       }
       //printf("%s %s %s\n", pc, command, address);
       long long int addy;
       long long int set;
       long long int tag;
       sscanf(address, "%llx", &addy);

       int tagwork = 48-tagbits;
       tag = addy/pow(2,tagwork);
       set = addy / (long long int) pow(2,offsetbits);
       set = set % (long long int) pow(2,setbits);

       if(strcmp(command, "W") == 0) {
         MemWrite++;
         int d = -1;
         for(int i = 0; i < n; i++) {
           if(cache[set][i].valid==1 && cache[set][i].tag == tag) {
             CacheHits++;
             cache[set][i].age = 0;
             d = 0;
             break;
           }
         }
         for(int i = 0; i < n; i++) {
           if(cache[set][i].valid!=1) {
             cache[set][i].tag = tag;
             cache[set][i].valid = 1;
             MemRead++;
             CacheMisses++;
             d = 0;
             break;
           }
         }
         if(d==-1) {
           long long int agee = 0;
           long long int place;
           for(int i = 0; i < n; i++) {
             if (cache[set][i].age > agee) {
               agee = cache[set][i].age;
               place = i;
             }
           }
           cache[set][place].tag = tag;
           MemRead++;
           CacheMisses++;
           d = 10;
         }

       } else {
         int d = -1;
         for(int i = 0; i < n; i++) {
           if(cache[set][i].valid==1 && cache[set][i].tag == tag) {
             CacheHits++;
             cache[set][i].age = 0;
             d = 0;
             break;
           }
         }
         for(int i = 0; i < n; i++) {
           if(cache[set][i].valid!=1) {
             cache[set][i].tag = tag;
             cache[set][i].valid = 1;
             MemRead++;
             CacheMisses++;
             d = 0;
             break;

           }
         }
         if(d==-1) {
           long long int agee = 0;
           long long int place;
           for(int i = 0; i < n; i++) {
             if (cache[set][i].age > agee) {
               agee = cache[set][i].age;
               place = i;
             }
           }
           cache[set][place].tag = tag;
           MemRead++;
           CacheMisses++;
           d = 10;
         }

       }
}
fclose(fp);
printf("Memory reads: %lld\nMemory writes: %lld\nCache hits: %lld\nCache misses: %lld\n", MemRead, MemWrite, CacheHits, CacheMisses);

  } else {
    while(fgets(str, 100, fp) ) {

      for(int i = 0; i < sets; i++) {
        int fullcounter = 0;
        for(int j = 0; j < n; j++) {
        if(cache[i][j].valid == 1) {
          cache[i][j].age++;
          fullcounter++;
        }
        if(fullcounter == n) {
          cache[i][0].full == 1;
        }
        }
      }

     sscanf(str, "%s %s %s", pc, command, address);
     if(strcmp(pc,"#eof") == 0) {
       break;
     }
     //printf("%s %s %s\n", pc, command, address);
     long long int addy;
     long long int set;
     long long int tag;
     sscanf(address, "%llx", &addy);

     int tagwork = 48-tagbits;
     tag = addy/pow(2,tagwork);
     set = addy / (long long int) pow(2,offsetbits);
     set = set % (long long int) pow(2,setbits);

     if(strcmp(command, "W") == 0) {
       MemWrite++;
       int d = -1;
       for(int i = 0; i < n; i++) {
         if(cache[set][i].valid==1 && cache[set][i].tag == tag) {
           CacheHits++;
           d = 0;
           break;
         }
       }
       for(int i = 0; i < n; i++) {
         if(cache[set][i].valid!=1) {
           cache[set][i].tag = tag;
           cache[set][i].valid = 1;
           MemRead++;
           CacheMisses++;
           d = 0;
           break;
         }
       }
       if(d==-1) {
         long long int agee = 0;
         long long int place;
         for(int i = 0; i < n; i++) {
           if (cache[set][i].age > agee) {
             agee = cache[set][i].age;
             place = i;
           }
         }
         cache[set][place].tag = tag;
         MemRead++;
         CacheMisses++;
         d = 10;
       }

     } else {
       int d = -1;
       for(int i = 0; i < n; i++) {
         if(cache[set][i].valid==1 && cache[set][i].tag == tag) {
           CacheHits++;
           d = 0;
           break;
         }
       }
       for(int i = 0; i < n; i++) {
         if(cache[set][i].valid!=1) {
           cache[set][i].tag = tag;
           cache[set][i].valid = 1;
           MemRead++;
           CacheMisses++;
           d = 0;
           break;

         }
       }
       if(d==-1) {
         long long int agee = 0;
         long long int place;
         for(int i = 0; i < n; i++) {
           if (cache[set][i].age > agee) {
             agee = cache[set][i].age;
             place = i;
           }
         }
         cache[set][place].tag = tag;
         MemRead++;
         CacheMisses++;
         d = 10;
       }

     }
}
fclose(fp);
printf("Memory reads: %lld\nMemory writes: %lld\nCache hits: %lld\nCache misses: %lld\n", MemRead, MemWrite, CacheHits, CacheMisses);
  }

}

}


return 0;
}
