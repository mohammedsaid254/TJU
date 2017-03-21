#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int adj[N][N];
int vis[N];
int t , n , m;
bool flag;

void dfs(int u){
    vis[u] = 1;
    for(int nxt = 1 ; nxt <= n ; nxt++)
        if(adj[u][nxt]){
            if(vis[nxt] == 0){
                dfs(nxt);
            }else if(vis[nxt] == 1){
                flag = false;
            }
        }
    vis[u] = 2;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        flag = true;
        for(int i = 0 ; i < N ; i++){
          vis[i] = 0;
          for(int j = 0 ; j < N ; j++)
            adj[i][j] = 0;
        }



        scanf("%d%d",&n,&m);
        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b);
            adj[a][b] = 1;
        }

        for(int i = 1 ; i <= n ; i++)
            if(vis[i] == 0)
                dfs(i);

        if(flag)printf("1\n");
        else printf("0\n");

    }


    return 0;
}
