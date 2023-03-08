#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char s[10];
    int ret;
    while ((ret= read (STDIN_FILENO, s, 10))> 0)
    {
        write (STDOUT_FILENO, s, ret);
    }
    return 0;
}