#include <iostream>
#include <algorithm>

using namespace std;

class Interval{
public:
    int l,r;
    Interval()=default;
    Interval(int x,int y):l(x),r(y) {}
    Interval(const Interval &i) : l(i.l), r(i.r) {}
};
inline bool cmp(Interval &a, Interval &b){
    return (a.l<b.l||(a.l==b.l&&a.r<b.r));
}

int main(){
    int n;
    cin>>n;
    Interval a[10001];
    for(int i=1;i<=n;++i)
        cin>>a[i].l>>a[i].r;

    sort(a+1,a+1+n,cmp);

    long long cur_l=a[1].l,cur_r=a[1].r,res=0;
    for(int i=2;i<=n;i++){
        if(a[i].l<=cur_r){
            if(cur_r<a[i].r)cur_r=a[i].r;
        }
        else{
            res+=(cur_r-cur_l);
            cur_l=a[i].l;cur_r=a[i].r;
        }
    }    
    res+=(cur_r-cur_l);
    cout<<res<<endl;
    return 0;
}