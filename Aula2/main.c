#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>   /* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#define Ex(a)  

int ex1 ()
{
    pid_t p;
    if (!(p= fork()))
    {
        p= getpid ();
        printf ("Filho com o pid : %i\n", p);
    }
    else
    {
        p= getpid ();
        printf ("Pai com o pid : %i\n", p);
    }
    return 0;
}

int main ()
{
    
}