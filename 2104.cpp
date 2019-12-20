//2104. 大脸上课
#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];//map[500][500]对应原点
int dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};

class Point{
public:
    int x,y;
    Point(int px=0,int py=0):x(px),y(py){}
}; 

queue<Point> q;

int main(){
    int targetx,targety,n,i,j;
    cin>>targetx>>targety>>n;
    while(n--){
        cin>>i>>j;
        map[500+i][500+j]=-1;
    }
    q.push(Point(500,500));
    map[500][500]=1;

    int curx,cury,nextx,nexty;
    //当没有到达目标点
    while(map[500+targetx][500+targety]==0){
        curx=q.front().x;
        cury=q.front().y;
        q.pop();
        
        for(int i=0;i<4;++i){
            nextx=dx[i]+curx;
            if(nextx>1000||nextx<0)continue;
            nexty=dy[i]+cury;
            if(nexty>1000||nexty<0)continue;

            //不是障碍也没有被访问过时
            if(map[nextx][nexty]==0){
                q.push(Point(nextx,nexty));
                map[nextx][nexty]=map[curx][cury]+1;//变为访问过
            }
        }
    }
    cout<<map[500+targetx][500+targety]-1<<endl;

    return 0;
}