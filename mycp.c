#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int copy (const char* from, const char* to)
{
    int fd_from= open (from, O_RDONLY);
    int fd_to= open (to, O_CREAT | O_TRUNC | O_WRONLY, 0660);
    int size= lseek (fd_from, 0, SEEK_END);                                     //Set size for the buffer
    lseek (fd_from, 0, SEEK_SET);                                               //Reset the FT pos
    char buf [size];
    if (read (fd_from, buf, size)<= 0 || write (fd_to, buf, size)<= 0)
        return -1;
    return 0;
}

int main (int argc, const char* argv[])
{ 
    if (argc== 3)
        return copy (argv [1], argv [2]);
    else
        return -1;
}