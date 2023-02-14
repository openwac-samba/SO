#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int pos;
    int size;
    char* str;
}string;

string* init_string ()
{
    string* s= malloc (sizeof (string));
    s->pos= 0;
    s->size= 100;
    s->str= malloc (100* sizeof (char));
    return s;
}

void more_string (string* s)
{
    s->size<<= 1;
    s->str= realloc (s->str, s->size* sizeof(char));
}

void free_string (string* s)
{
    free (s->str);
    free (s);
}

int main (int argc, const char* argv[])
{
    string* s= init_string ();
    while (fgets (&s->str[s->pos], 100, stdin))
    {
        s->pos+= strlen (&s->str[s->pos]);
        if (s->pos- strlen(s->str)<100)
            more_string (s);
    }
    puts (s->str);
    free_string (s);
}