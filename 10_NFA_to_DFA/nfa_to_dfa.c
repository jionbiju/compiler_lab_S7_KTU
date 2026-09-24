#include <stdio.h>

int n, m;
int nfa[10][10][10];
int count[10][10];

int dfa[20][10];
int trans[20][10];
int dfa_count = 0;

int exists(int s[])
{
    int i, j;

    for (i = 0; i < dfa_count; i++)
    {
        for (j = 0; j < n; j++)
            if (dfa[i][j] != s[j])
                break;

        if (j == n)
            return i;
    }

    return -1;
}

void add(int s[])
{
    int i;

    for (i = 0; i < n; i++)
        dfa[dfa_count][i] = s[i];

    dfa_count++;
}

int main()
{
    int i, j, k, x;
    int temp[10];
    int next, pos;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter number of symbols: ");
    scanf("%d", &m);

    /* Read NFA */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("q%d on %d: ", i, j);

            scanf("%d", &count[i][j]);

            for (k = 0; k < count[i][j]; k++)
                scanf("%d", &nfa[i][j][k]);
        }
    }

    /* Start with {q0} */
    for (i = 0; i < n; i++)
        temp[i] = 0;

    temp[0] = 1;
    add(temp);

    /* Conversion */
    for (i = 0; i < dfa_count; i++)
    {
        for (j = 0; j < m; j++)
        {
            /* Clear temporary state */
            for (k = 0; k < n; k++)
                temp[k] = 0;

            /* Find all destinations */
            for (k = 0; k < n; k++)
            {
                if (dfa[i][k])
                {
                    for (x = 0; x < count[k][j]; x++)
                    {
                        next = nfa[k][j][x];
                        temp[next] = 1;
                    }
                }
            }

            /* Find or create state */
            pos = exists(temp);

            if (pos == -1)
            {
                add(temp);
                pos = dfa_count - 1;
            }

            trans[i][j] = pos;
        }
    }

    /* Print DFA */
    printf("\nDFA Transition Table\n");

    printf("State\t");
    for (j = 0; j < m; j++)
        printf("%d\t", j);

    printf("\n");

    for (i = 0; i < dfa_count; i++)
    {
        printf("D%d={", i);

        for (j = 0; j < n; j++)
            if (dfa[i][j])
                printf("q%d ", j);

        printf("}\t");

        for (j = 0; j < m; j++)
            printf("D%d\t", trans[i][j]);

        printf("\n");
    }

    return 0;
}