//Strict Yan涂色
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool a[2000][2000]={0};
int m,n,res;

bool isKPrime[1001];

//return the number to change
int change(int k){
    res=0;
    int diff=0;
    for(int x=1;x<=m;x+=k)
        for(int y=1;y<=n;y+=k){
            diff=0;
            for(int i=0;i<k;++i)
            for(int j=0;j<k;++j){
                if(a[x+i][y+j])++diff;
            }
            diff=min(diff,k*k-diff); 
            res+=diff;               
        }            
    return res;
}

int main(){
    //set the array isKPrime
    for(int i=1;i<=1000;i++)isKPrime[i]=true;
    for (int j=2;j<=1000;j++)
        if(isKPrime[j]){
            for(int i=2;i*j<=1000;i++)
                isKPrime[i*j] = false;
        }

    cin>>m>>n;
    string tmp;
    for(int i=1;i<=m;++i){
        cin>>tmp;
        for(int j=1;j<=n;++j)
            a[i][j]=tmp[j-1]-'0';
    }
        
    int k=2,maxk=max(m,n),ans=100000000;
    for(k;k<=maxk;++k){
        if(isKPrime[k])ans=min(change(k),ans);
    }
    cout<<ans<<endl;
    return 0;
}