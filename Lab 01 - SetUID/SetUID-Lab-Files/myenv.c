#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main()
{
	char *argv[2];
	
	argv[0] = "/usr/bin/env";
	argv[1] = NULL;
	
	execve("/usr/bin/env", argv, NULL);
	
	//execve("/usr/bin/env", argv, environ);
	
	//char *newenv[3];
	//newenv[0] = "AAA=aaa"; newenv[1] = "BBB=bbb"; newenv[2] = NULL;
	//execve("/usr/bin/env", argv, newenv);
	
	return 0;
}
