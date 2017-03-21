#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int INF = 1e9;
int dis[N][N];
int t , n , x , y , xx , yy;
bool flag;
int dx[]={-2,-2,2,2,-1,-1,1,1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
bool valid(int a , int b){
    if(a < 0 || b < 0 || a >= n || b >=n )return 0;
    return 1;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                dis[i][j] = INF;

        scanf("%d%d",&x,&y);
        scanf("%d%d",&xx,&yy);
        queue<pair<int,int> > q;
        dis[x][y] = 0;
        flag = true;
        q.push(make_pair(x,y));
        while(!q.empty() && flag){
            x = q.front().first;
            y = q.front().second;
            if(x == xx && y == yy)
                break;
            q.pop();
            for(int i = 0 ; i < 8 && flag; i++){
                int nx = x + dx[i] , ny = y + dy[i];
                if(valid(nx , ny) && dis[nx][ny] == INF){
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(make_pair(nx,ny));
                    if(nx == xx && ny == yy)
                        flag = false;

                }
            }
        }

        printf("%d\n",dis[xx][yy]);

    }

    return 0;
}
