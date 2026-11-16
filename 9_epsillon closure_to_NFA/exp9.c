#include <stdio.h>
int n;
int e[20][20],visited[20];

void eclosure(int s){
    if(visited[s]){
        return;
    }
    visited[s]=1;
    printf("q%d ",s);
    for(int i=0; i<n; i++){
        if(e[s][i] == 1){
            eclosure(i);
        }
    }
}
int main(){
    printf("Enter the number of states:\n");
    scanf("%d",&n);
    printf("Enter transition matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&e[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[j]=0;
        }
        printf("e closure(q%d)={ ",i);
        eclosure(i);
        printf("}\n");
    }
    return 0;
}

/*
Find the epsilon-closure  of all states in a
 Non-deterministic Finite Automaton (NFA) using recursion (Depth-First Search).
OUTPUT
Enter the number of states:
4
Enter transition matrix:
0 1 1 0
0 0 0 1
0 0 0 1
0 0 0 0
e closure(q0)={ q0 q1 q3 q2 }
e closure(q1)={ q1 q3 }
e closure(q2)={ q2 q3 }
e closure(q3)={ q3 }
*/