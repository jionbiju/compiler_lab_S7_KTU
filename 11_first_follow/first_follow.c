#include <stdio.h>
#include <string.h>
#include <ctype.h>

char p[10][10];
char res[20]; 
int n, m = 0;

void addToResult(char c)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (res[i] == c)
            return; 
    }
    res[m++] = c;
}

void FIRST(char c)
{
    int i;

    if (!isupper(c))
    {
        addToResult(c);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (p[i][0] == c)
        {
            if (p[i][2] == '#')
                addToResult('#');
            else
                FIRST(p[i][2]);
        }
    }
}

void FOLLOW(char c)
{
    int i, j;

    if (c == p[0][0])
        addToResult('$');

    for (i = 0; i < n; i++)
    {
        for (j = 2; p[i][j] != '\0'; j++)
        {
            if (p[i][j] == c)
            {
                if (p[i][j + 1] != '\0')
                    FIRST(p[i][j + 1]);

                else if (c != p[i][0])
                    FOLLOW(p[i][0]);
            }
        }
    }
}

int isAlreadyPrinted(int currentIndex)
{
    for (int k = 0; k < currentIndex; k++)
    {
        if (p[k][0] == p[currentIndex][0])
            return 1;
    }
    return 0;
}

int main()
{
    int i, j;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions:\n");
    for (i = 0; i < n; i++)
        scanf("%s", p[i]);

    printf("\nFIRST:\n");
    for (i = 0; i < n; i++)
    {
        if (isAlreadyPrinted(i))
            continue; 

        c = p[i][0];
        m = 0;
        FIRST(c);

        printf("FIRST(%c) = { ", c);
        for (j = 0; j < m; j++)
            printf("%c ", res[j]);
        printf("}\n");
    }

    printf("\nFOLLOW:\n");
    for (i = 0; i < n; i++)
    {
        if (isAlreadyPrinted(i))
            continue; 

        c = p[i][0];
        m = 0; 
        FOLLOW(c);

        printf("FOLLOW(%c) = { ", c);
        for (j = 0; j < m; j++)
            printf("%c ", res[j]);
        printf("}\n");
    }

    return 0;
}
/*
Find the first and follow of the given productions.
Enter number of productions: 4
Enter productions:
S=(L)
S=a
L=S
L=cS

FIRST:
FIRST(S) = { ( a }
FIRST(L) = { ( a c }

FOLLOW:
FOLLOW(S) = { $ ) }
FOLLOW(L) = { ) }
*/