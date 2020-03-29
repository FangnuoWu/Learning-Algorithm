//4053. Prime Ring
#include <iostream>

using namespace std;

int n;
int a[17]={0},visit[17]={0};

bool isPrime[32]={0,0,1,1,0,1,0,1,0,0,0,
                    1,0,1,0,0,0,1,0,1,0,
                    0,0,1,0,0,0,0,0,1,0,1};

void dfs(int c){
    if(c==(n+1)&&isPrime[a[n]+a[1]]){
        for(int i=1;i<=n;++i)printf("%d ", a[i]);
		printf("\n"); return;
    }
    for(int i=2;i<=n;++i){
        if(!visit[i]&&isPrime[i+a[c-1]]){
            a[c]=i;visit[i]=1;               
            dfs(c+1);
            visit[i]=0;
        }           
    }
}

int main(){
    cin>>n;
    a[1]=1;
    if(n%2!=0)cout<<"None"<<endl;
    else dfs(2);
    return 0;
}