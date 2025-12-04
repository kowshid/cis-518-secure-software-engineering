/* Chapter 3, Section 3.1.1 */

#include <stdio.h>

void prnenv();

extern char** environ;

void main(int argc, char* argv[])
{
	prnenv();
}

void prnenv() {
   int i = 0;
   while (environ[i] != NULL) {
      printf("%s\n", environ[i++]);
   }
}
