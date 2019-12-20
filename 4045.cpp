#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int len,time,l,r,target;
    scanf("%d%d", &len, &time);

    vector<int> v;
    v.push_back(0);
    int x;
    for(int i=0;i<len;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    vector<int> tmp(v.begin(),v.end()); 
    
    while(time--){
        tmp=v;

        scanf("%d%d%d",&l,&r,&target);
        sort(tmp.begin()+l,tmp.begin()+r+1);

        auto t=find(tmp.begin()+1,tmp.end(),v[target]);
        
        if(distance(tmp.begin(),t)==target) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}