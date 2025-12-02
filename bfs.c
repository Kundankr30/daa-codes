#include<stdio.h>
#include<stdlib.h>

#define white 0
#define gray 1
#define black 2
#define inf 9999

int queue[100],rear = -1, front = -1;

void enqueue(int v){
    if(rear == 99){
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = v;
}
int dqueue(){
    if(front == -1 || front > rear){
        return -1;
    }
    return queue[front++];
}
int isEmpty(){
    if(front == -1 || front > rear){
        return 1;
    } else {
        return 0;
    }
}
void BFS(int G[100][100], int n, int s){
    int color[100],d[100],pi[100];
    for(int u = 0; u < n; u++){   //all vertex colour white except root
        if(u != s){
            color[u] = white;
            d[u] = inf;
            pi[u] = -1;
        }
    }
    color[s] = gray;
    d[s] = 0;
    pi[s] = -1;

    front = rear = -1;
    enqueue(s);
    while(!isEmpty()){
        int u = dqueue();

        for(int v = 0; v < n; v++){
            if(G[u][v] == 1 && color[v] == white){
                color[v] = gray;
                d[v] = d[u] + 1;
                pi[v] = u;
                enqueue(v);
            }
        }
        color[u] = black;
    }
    printf("Vertex\tColor\tDistance\tParent\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\n",i,color[i],d[i],pi[i]);
    }
}
int main(){
    int n,G[100][100],s;
    printf("Enter the no. of vertices : \n");
    scanf("%d",&n);

    printf("Enter the adjacency matrix : \n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("Enter the source vertex : \n");
    scanf("%d",&s);
    BFS(G,n,s);
    return 0;
}