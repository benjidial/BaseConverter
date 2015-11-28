/*
The MIT License (MIT)

Copyright (c) 2015 Benji Dial

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/* * * * * * * * *
 * BaseConverter *
 * by Benji Dial *
 * Beta v0.1.0-b *
 * * * * * * * * */

enum exitcodes
{
  OK = 0,
  NO_ARGS,
  INV_ARGS,
  BASE_TOO_LARGE_FOR_AUTO,
  NOT_ENOUGH_DIGITS,
  NO_MEM_DIGITS,
  NO_MEM_OUTPUT
};

void help(char *name)
{
  printf("Help for %s\n", name);
  printf("Command Line:\n");
  printf("  %s dec base [digits [decimalpoint]]\n", name);
  printf("  %s --help\n\n", name);
  printf("  --help  Outputs this help text.\n");
  printf("  dec     This is the decimal input.\n");
  printf("  base    This is the base to convert it to.\n");
  printf("  digits  These are the digits for the base.\n");
  printf("          If not supplied, the following will be used:\n");
  printf("          0123456789abcdefghijklmnopqrstuvwxyz\n");
  printf("  decimalpoint  This goes after the unit digit.\n");
  printf("                If not specified, '.' is used.\n\n");
  printf("  Examples:\n");
  printf("    %s 1729 6\n", name);
  printf("    %s 42 16\n", name);
  printf("    %s 10 2 O|\n", name);
  printf("    %s 126 12 0123456789XE ;\n\n\n", name);
  printf("Return Values:\n");
  printf("  0   OK\n");
  printf("  1   No Arguments\n");
  printf("  2   Invalid Arguments\n");
  printf("  3   Base Too Large For Automatic Digits\n");
  printf("  4   Not Enough Digits For Base\n");
  printf("  5   Couldn't Allocate Memory For Digits\n");
  printf("  6   Couldn't Allocate Memory For Output\n");
}

int main(int argc, char *argv[])
{
  double dec;
  double decBackup;
  int base;
  char *digits;
  char decimalPoint;
  char *output;

  /* Begin argument processing */
  if (argc == 1)
  {
    fprintf(stderr, "No arguments supplied!\nDo %s --help for help.\n", argv[0]);
    exit(NO_ARGS);
  }
  if (!strcmp(argv[1], "--help"))
  {
    help(argv[0]);
    exit(OK);
  }
  if (argc == 2)
  {
    fprintf(stderr, "Invalid arguments!\nDo %s --help for help.\n", argv[0]);
    exit(INV_ARGS);
  }
  sscanf(argv[1], "%lf", &dec);
  decBackup = dec;
  sscanf(argv[2], "%d", &base);
  if (argc = 3)
  {
    if (base > 36)
    {
      fprintf(stderr, "Automatic digit definitions are only available for bases up to 36.\nPlease supply the digits you would like to use.\nDo %s --help for help.\n", argv[0]);
      exit(BASE_TOO_LARGE_FOR_AUTO);
    }
    digits = "0123456789abcdefghijklmnopqrstuvwxyz";
  }
  else if ((int)strlen(argv[3]) >= base)
  {
    if ((int)strlen(argv[3]) > base)
    {
      fprintf(stderr, "Too many digits were supplied, ignoring rest.\n");
      argv[3][base] = '\0';
    }
    digits = (char*)malloc(base + 1);
    if (digits == NULL)
    {
      fprintf(stderr, "Failed to allocate %d bytes to store digits.\nTry using a smaller base.\n", base + 1);
      exit(NO_MEM_DIGITS);
    }
    strcpy(digits, argv[3]);
  }
  else if (base > 36)
  {
    fprintf(stderr, "Not enough digits were supplied! (Expected %d, got %d)\nDo %s --help for help.\n", base, (int)strlen(argv[3]), argv[0]);
    exit(NOT_ENOUGH_DIGITS);
  }
  else
  {
    fprintf(stderr, "Not enough digits were supplied, using default for rest.\n");
    digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    strncpy(digits, argv[3], strlen(argv[3]));
  }
  decimalPoint = '.';
  if (argc > 4)
    decimalPoint = argv[4][0];
  /* End argument processing */

  /* Begin conversion */
  output = (char*)malloc(64);
  if (output == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for output.\n");
    exit(NO_MEM_OUTPUT);
  }
  int pos = 0;
  long intpart = floor(dec);
  dec -= floor(dec);
  int power;
  for (power = ceil(log(intpart) / log(base)); power--; power >= 0)
  {
    output[pos] = digits[(int)floor(intpart / pow(base, power))];
    pos++;
    intpart %= (long)pow(base, power);
  }
  output[pos] = decimalPoint;
  if (dec != 0)
    pos++;
  while (dec > 0)
  {
    dec *= base;
    output[pos] = digits[(int)floor(dec)];
    pos++;
    dec -= floor(dec);
  }
  output[pos] = '\0';
  /* End conversion */

  printf("%lf is %s in base %d.\n", decBackup, output, base);
  free(output);
  exit(OK);
}
