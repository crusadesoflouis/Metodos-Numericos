#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv){
  char *mvalue = NULL;
  char *ivalue = NULL;
  char *qvalue = NULL;
  char *ovalue = NULL;
  int c;
  while ((c = getopt (argc, argv, "m:i:o:q:")) != -1)
    switch (c){
      case 'm':
        mvalue = optarg;
        break;
      case 'i':
        ivalue = optarg;
        break;
      case 'q':
        qvalue = optarg;
        break;
      case 'o':
        ovalue = optarg;
        break;
      default:
        abort();
    }
  
  return 0;
}
