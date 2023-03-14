#include <unistd.h>     /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h>   /* chamadas wait*() e macros relacionadas */
#include <stdio.h>
#include <stdlib.h>

int ex1 ()
{
    printf ("ID Proc : %i \tID Proc Pai : %i\n", getpid (), getppid());
    return 0;
}

int ex2 ()
{
    int f= fork();
    int status;
    switch (f)
    {
        //Erro
        case -1:
            exit (1);
            break;
        //Filho
        case 0:                                         
            printf ("Filho com o p_id %i, processo pai p_id %i\n", getpid (), getppid ());
            break;
        //Pai
        default:
            printf ("Pai com o p_id %i, filho de %i, e tem como filho %i\n", getpid (), getppid (), f);
            wait (&status);
    }
    return 0;
}

int ex3 ()
{
    int f, status;
    for (int i= 0; i< 10; i++)
    {
        //Filho
        if (!(f= fork()))
        {
            printf ("Filho com p_id: %i\n", getpid ());
            //Saida do cículo clean
            i= 10;
        }
        else
        {
            wait (&status);
            if (WIFEXITED (status))
                printf ("Processo filho concluiu com estado %i\n", WEXITSTATUS (status));
            else
                printf ("Processozito sofreu\n");
        }
    }
    return 0;
}

int main (int argsc, char* argsv [])
{
    if (argsc== 2)
    {
        int n= atoi (argsv [1]);
        switch (n)
        {
            case 1:
                ex1 ();
                break;
            case 2:
                ex2 ();
                break;
            case 3:
                ex3 ();
                break;
        }
    }
    else
        return 1;
    return 0;
}