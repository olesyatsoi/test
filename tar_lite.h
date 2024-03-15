#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
typedef struct {
  int c;
  int l;
  int r;
  int s;
  int h;
} Flags;


int init_flags(int argc, char* argv[], Flags* flags);
