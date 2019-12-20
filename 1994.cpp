#include <iostream>
using namespace std;

int dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};
int map[502][502];
int n,m,num=0;

bool check(int x, int y){
    if(x<1||x>n||y<1||y>m||map[x][y]!=0)return false;
    else return true;
}

void change(int x, int y){   
    map[x][y]=-1;
    for(int i=0;i<4;++i)
    if(check(x+dx[i],y+dy[i]))change(x+dx[i],y+dy[i]);
}

int main(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        cin>>map[i][j];
    for(int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (check(i,j)){
                change(i,j);++num;
            }
    cout<<num<<endl;
    return 0;
}