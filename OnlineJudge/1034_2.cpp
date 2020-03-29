#include <deque>
#include <iostream>
#include <cmath>

using namespace std;

int a[200000];

int main(){
    int n,k;
    scanf("%d%d", n,k);
    for(int i=0;i<n;++i)scanf("%d", &a[i]);

    deque<int>d;
    for
    int min_max=2147483647;
    for(int i=0;i<n;++i){
        int ma=0;
        for(int j=0;j<k;j++){       
        ma=max(ma,a[(i+j+1)%n]);
        }
        min_max=min(min_max,ma);
    }
    cout<<min_max<<endl;

    return 0;
}