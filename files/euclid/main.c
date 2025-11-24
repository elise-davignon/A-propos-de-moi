#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int n = 0;
    int *numbers = NULL;

    int i = 0;

    do
    {
        printf ("Combien de nombres ? (au moins 2) :\t");
        scanf ("%d", &n);
    }
    while (n <= 1);

    numbers = (int *) malloc (n * sizeof (int));

    for (i = 0; i < n; i ++)
    {
        do
        {
            printf ("Nombre #%d :\t", i+1);
            scanf ("%d", &numbers[i]);
        }
        while (numbers[i] < 1);
    }

    printf ("Le PGCD des nombres ");
    for (i = 0; i < n; i ++)
    {
        printf ("%d", numbers[i]);
        if (i+1 < n)
            printf (",");
        printf (" ");
    }

    printf ("est %d !\n", gcd (n, numbers));

    system("PAUSE");
    return 0;
}

int gcd (int n, int numbers[])
{
    int i = 0;
    int *newNumbers = NULL;
    int v = 0;
    int m = 0;

    printf ("\n\tGCD\t");
    for (i = 0; i < n; i++)
        printf ("%d\t", numbers[i]);

    if ( allEqual (n, numbers) )
        return numbers[0];

    else
    {
        m = minimum (n, numbers);

        newNumbers = (int *) malloc (n * sizeof (int));

        for (i = 0; i < n; i ++)
        {
            if (numbers[i] == m)
                newNumbers[i] = numbers[i];
            else
                newNumbers[i] = numbers[i] - m;
        }

        v = gcd (n, newNumbers);

        free (newNumbers);
        return v;
    }
}

int allEqual (int n, int numbers[])
{
    int i = 0;
    int v = 0;

    v = numbers[0];
    for (i = 1; i < n; i++)
    {
        if (numbers[i] != v)
            return 0;
    }
    return 1;
}

int minimum (int n, int numbers[])
{
    int i = 0;
    int v = 0;

    v = numbers[0];
    for (i = 1; i < n; i++)
    {
        if (numbers[i] < v)
            v = numbers[i];
    }

    return v;
}
