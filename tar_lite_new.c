#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int c;
  int l;
  int r;
  int s;
  int h;
} Options;

void add_name_of_files(char *template_string, char *new_template);
//void create_new_archive(int *argc, char *argv[], char *name_of_archive,
//                              Options *options);
void flag_parser(int *argc, char *argv[], Options *options);

int main(int argc, char *argv[]) {
  char name_of_archive[4096];
  //if (argc == 1) {
  //  exit(1);
  //}

  Options options = {0};
  flag_parser(&argc, argv, &options);
  argc -= optind;
  argv += optind;
  strcat(name_of_archive, argv[0]);
  argc--;
  argv++;
  printf("%d\n", options.c);
  printf("%d\n", options.l);
  printf("%s", name_of_archive);
  if (argc == 0) {
    exit(1);
  }
  //void create_new_archive(int *argc, char *argv[], char *name_of_archive,
//                              Options *options);
  return 0;
}

void flag_parser(int *argc, char *argv[], Options *options) {
  int opt;
  while ((opt = getopt(*argc, argv, "clrsh")) != -1) {
    switch (opt) {
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'r':
        options->r = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'h':
        options->h = 1;
        break;        
      case '?':
        fprintf(
            stderr,
            "error");
        break;
    }
  }
}
