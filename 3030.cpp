//mushroom
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t[101]={0};
    int v[101]={0};
    int f[1001]={0};

    int time,m;
    cin>>time>>m;

    for(int i=1;i<=m;++i)
        cin>>t[i]>>v[i];
    
    for(int i=1;i<=m;++i)
        for(int j=time;j>t[i];j-=t[i])
            f[j]=max(f[j],f[j-t[i]]+v[i]);

    cout<<f[time]<<endl;

    return 0;
}