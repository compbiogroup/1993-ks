/**********************************************************
 *
 * Author: Klairton L. Brito, klairton@ic.unicamp.br
 *
 **********************************************************/

#include <iostream>
#include <getopt.h>
#include <stdlib.h>

#include "breakpoint.h"
#include "reversal.h"
#include "permutation.h"
#include "events.h"
#include "algorithm.h"

void help(char progname[]) {
  printf("usage: %s [options] \n", progname);
  printf("options: \n");
  printf("\t--size or -s: size of the genome\n");
  printf("\t--permutations or -p: total number of permutations\n");
  printf("\t--input or -i: input file with the permutations\n");
  printf("\n");
}

void check_params(char progname[], int size, int permutations, FILE *input){
  bool error = false;

  if (size <= 0) {
    printf("- Invalid genome size.\n");
    error = true;
  }

  if (permutations <= 0) {
    printf("- Invalid total number of permutations.\n");
    error = true;
  } 

  if(!input){
    printf("- Invalid input file.\n");
    error = true;
  }

  if(error) {
    printf("Use \"%s --help\" to check the parameters.\n", progname);
    exit(EXIT_FAILURE); 
  }
}

int main (int argc, char *argv[]) {
  avocado::Permutation *pi = NULL;
  int i, j, size = 0, permutations = 0;
  FILE *input = NULL;
  extern char *optarg;
  char op;
  struct option longopts[] = {
    {"size", 1, NULL, 's'},
    {"permutations", 1, NULL, 'p'},
    {"input", 1, NULL, 'i'},
    {"help", 0, NULL, 'h'},
  };

  while ((op = getopt_long(argc, argv, "s:p:i:h", longopts, NULL)) != -1) {
    switch (op) {
      case 's':
      size = atoi(optarg);
      break;
      case 'p':
      permutations = atoi(optarg);
      break;
      case 'i':
      input = fopen(optarg, "r");
      break;
      case 'h':
      help(argv[0]);
      exit(EXIT_SUCCESS);
    }
  }

  check_params(argv[0], size, permutations, input);

  pi = new avocado::Permutation(size);

  for(i = 0; i < permutations; i++) {
    for(j = 1; j <= size; j++) {
      if(!fscanf(input, "%d,", &pi->elements[j])){
        printf("ERROR -- check input file ---\n");
        exit(EXIT_FAILURE);
      }
    }
    avocado::Algorithm algorithm;
    std::vector<avocado::Reversal> sequence = algorithm.Run(pi);
    std::cout << sequence.size() << " - ";
    std::cout << "[";
    for (int i = 0; i < sequence.size(); i++)
    {
      (i == 0) ? std::cout << sequence[i] : std::cout << "," << sequence[i];
    }
    std::cout << "]";
    std::cout << std::endl;
    sequence.clear();
  }  
  delete pi;
  return EXIT_SUCCESS;
}