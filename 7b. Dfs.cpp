#include<iostream>
using namespace std;

int visit[10],n,adj[10][10],s,nodecount=0;

void dfs(int u){
    int i;
    visit[u]=1;
    nodecount++;
    for(i=1;i<=n;i++){
        if((adj[u][i]==1)&&(visit[i]==0)){
            dfs(i);
        }
    }
}

int main(){
    int i,j;
    cout<<"Enter number of vertices: "<<endl;
    cin>>n;
    printf("Enter the adjacency matrix:\n");
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&adj[i][j]);

  for(i=1;i<=n;i++)
      visit[i]=0;

    dfs(1);

  if(nodecount==n)
   printf("\nThe graph is connected");
  else
   printf("The graph is not connected");
}
