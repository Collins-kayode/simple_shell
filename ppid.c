<<<<<<< HEAD
#include  <stdio.h>
=======
>>>>>>> 22ff61e5abc00727327f2d503e5582c1c80564e0
#include <unistd.h>
#include <stdio.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */

int main(void)
{
    pid_t my_ppid;

    my_ppid = getppid();
    printf("%u\n", my_ppid);
    return (0);
}
