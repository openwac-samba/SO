#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

ssize_t readln(int fd)
{
    char c;
    int sum= 0;
    while (read (fd, &c, 1)> 0)
    {
        if (c== '\n')
            return sum;
        sum++;
    }
    return sum;
}

int main ()
{
    int lines= 0, temp, chars= 0;
    while ((temp= readln (STDIN_FILENO)))
    {
        lines ++;
        chars+= temp;
    }
    printf ("File had %i lines and %i chars.\n", lines, chars);
}