#include <stdio.h>
#include <string.h>
#include <ctype.h>

char p[10][10];
int n;

void FIRST(char c)
{
    int i;  

    if (!isupper(c))
    {
        printf("%c ", c);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (p[i][0] == c)
        {
            if (p[i][2] == '#')
                printf("# ");
            else
                FIRST(p[i][2]);
        }
    }
}

void FOLLOW(char c)
{
    int i, j;

    if (c == p[0][0])
        printf("$ ");

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

int main()
{
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions:\n");

    for (i = 0; i < n; i++)
        scanf("%s", p[i]);

    printf("\nFIRST:\n");

    for (i = 0; i < n; i++)
    {
        c = p[i][0];

        printf("FIRST(%c) = { ", c);
        FIRST(c);
        printf("}\n");
    }

    printf("\nFOLLOW:\n");

    for (i = 0; i < n; i++)
    {
        c = p[i][0];

        printf("FOLLOW(%c) = { ", c);
        FOLLOW(c);
        printf("}\n");
    }

    return 0;
}