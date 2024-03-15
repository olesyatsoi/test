#include "tar_lite.h"

int main(int argc, char* argv[]) {
  Flags flags = {0};
  init_flags(argc, argv, &flags);
  while (optind < argc) {
    //print_files(argv, &flags);
    optind++;
  }
  printf("%d", flags.c);
  return 0;
  //  optind - индекс первого элемента не являющегося флагом
}

int init_flags(int argc, char* argv[], Flags* flags) {
  const char* short_flags =
      "clr";  // символы, которые будем искать в argv, указываются в
                   // произвольном порядке
  static struct option long_flags[] = {
      {"see", no_argument, NULL, 's'},
      {"help", no_argument, NULL, 'h'},
  };
  // {"имя длинного флага", нужно ли передавать флагу значения/аргументы, в
  // какую переменную записать полученные данные, какой символ вернет функция}
  int opt;
  //в getopt_long последним параметром передается индекс текущего параметра
  while ((opt = getopt_long(argc, argv, short_flags, long_flags, NULL)) != -1) {
    switch (opt) {
      case 'c':
        flags->c = 1;
        break;
      case 'l':
        flags->l = 1;
        break;
      case 'r':
        flags->r = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 'h':
        flags->h = 1;
        break;
      default:
        printf("error\n");
        break;
    }
  }

  return 0;
}

