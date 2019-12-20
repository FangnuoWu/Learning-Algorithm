#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n,x1,x2,now=2147483647;
    bool flag=true;
    
    cin>>n;
    while(n-->0){
        cin>>x1>>x2;
        if(flag){
            int ma=max(x1,x2);
            int mi=min(x1,x2);
            if (ma<=now) now=ma;
            else if (mi>now) flag=false;
            else now=mi;
        }
    }
    flag?cout<<"YES":cout<<"NO";
    return 0;
}