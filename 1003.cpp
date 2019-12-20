#include <iostream>
#include <deque>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int a[102][102];
    for (int i = 0; i < 102; ++i)
        for (int j = 0; j < 102; ++j)
            a[i][j] = 2;

    int l,res=0;
    cin>>l;
    for(int i=1;i<=l;++i)
        for(int j=1;j<=l;j++)
            cin>>a[i][j];

    //x，y存放有细菌的坐标点
    deque<int> x,y;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            if (a[i][j] == 1){
                x.push_back(i);
                y.push_back(j);
            }
    
    //当还有细菌时
    while(!x.empty()){
        res++;
        int len = x.size();
        for (int nowc = 0; nowc < len; ++nowc){
            for (int d = 0; d < 4; ++d){
                int ix = x[nowc] + dx[d];
                int iy = y[nowc] + dy[d];
                if (a[ix][iy] == 0){
                    a[ix][iy] = 1;
                    x.push_back(ix);
                    y.push_back(iy);
                }
            }
        }
        //将上一轮的所有细菌清除
        while(len--){
            x.pop_front();
            y.pop_front();
        }
    } 
    cout<<res-1<<endl;
    int z=3;
    switch(z){
        case 5:break;
        case 3:break;
    }
    return 0;
}