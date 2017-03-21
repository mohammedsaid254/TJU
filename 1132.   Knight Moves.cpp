#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int INF = 1e9;
int dis[N][N];
char x , y , xx , yy;
int dx[]={-2,-2,2,2,-1,-1,1,1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
bool valid(char a , char b){
    if(a < 'a' || b < '1' || a > 'h' || b > '8' )return 0;
    return 1;
}

int main()
{

    while(scanf(" %c %c %c %c",&x,&y,&xx,&yy) == 4){
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                dis[i][j] = INF;

        queue<pair<char,char> > q;
        dis[x-'a'][y-'0'] = 0;
        q.push(make_pair(x,y));
        while(!q.empty()){
            char a = q.front().first;
            char b = q.front().second;
            q.pop();
            for(int i = 0 ; i < 8; i++){
                char nx = a + dx[i] , ny = b + dy[i];
                if(valid(nx , ny) && dis[nx-'a'][ny-'0'] == INF){
                    dis[nx-'a'][ny-'0'] = dis[a-'a'][b-'0'] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }

        printf("To get from %c%c to %c%c takes %d knight moves.\n",x,y,xx,yy,dis[xx-'a'][yy-'0']);

    }

    return 0;
}
