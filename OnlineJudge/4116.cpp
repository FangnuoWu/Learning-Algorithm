#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int a[100000]={0};

//check welther the distance can be  int dis
bool check(int dis){
    int i=0,j=1,remain=k-1;//the first sword is a[0];t swords remained;    
    //travel through the array;
    while(j<n){
        if(a[j]-a[i]>=dis){
            i=j;
            remain--;
        }
        if(remain==0)return true;//once remian=0
        ++j;
    }
    return false;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)scanf("%d", &a[i]);

    sort(a,a+n);

    int max_dis=(a[n-1]-a[0])/(k-1),min_dis=1;
    //use binary search
    while(min_dis<max_dis){
        int mid=(max_dis+min_dis+1)/2;
        if(check(mid))min_dis=mid;
        else max_dis=mid-1;      
    }    
    cout<<min_dis<<endl;

    return 0;
}