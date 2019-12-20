//1074. LSZ的雪地脚印

#include <iostream>
using namespace std;

int map[1235][1235],sum[1235][1235],ans[1235][1235];
int maxk=0;
int N,M;

int main(){
    cin>>N>>M;
    char ch;
    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j){
            cin>>ch;
            map[i][j]=(ch=='X'?1:0);
            sum[i][j]=map[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    for(int i=1;i<= N;++i)
        for(int j=2;j<=M;++j){
            if (map[i][j]) continue;
            for(int k=ans[i-1][j]+1;k>=1;--k){
                if (i-k+1<=0||j-2*k+1<=0) continue;
                if (sum[i][j] - sum[i - k][j] - sum[i][j - 2 * k] + sum[i - k][j - 2 * k] == 0){
                    ans[i][j] = k;
                    if (k > maxk) maxk = k;
                    break;
                }
            }
        }
    printf("%d", 2 * maxk * maxk);
    return 0;    
}