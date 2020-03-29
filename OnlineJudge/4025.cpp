#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int m,n;
    long long v=0,cur=0;
    int h[250000]={0};

    cin>>m>>n;
    for(int i=0;i<m*n;++i)scanf("%d",&h[i]);
    cin>>v;    

    sort(h,h+m*n);

    int i=0;
    double ave,per;
    if(v!=0){
        while(cur<v){
            ++i;
            if(i==m*n){
                ave=double(h[i-1])+(v-cur+0.00)/i;
                per=100;
                cout<<fixed<<setprecision(2)<<ave<<endl<<per<<endl;
                return 0;
            }
            cur+=(h[i]-h[i-1])*i;       
        }//now ave<=h[i],>h[i-1]
        ave=h[i]-double(cur-v)/i;
        per=100*double(i)/(m*n);
    }else{
        per=0;
        ave=h[0];
    } 
    cout<<fixed<<setprecision(2)<<ave<<endl<<per<<endl;

    return 0;
}