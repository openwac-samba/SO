#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define size 1000

int main ()
{
    char buf [size];
    int bytes;
    while ((bytes= read (STDIN_FILENO, buf, size))> 0)
        write (STDOUT_FILENO, buf, bytes);
}