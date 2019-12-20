#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    long int N,a, b, v;
    cin >> N;
    while(N-->0){
        cin>>v>>a>>b;
        if(2*a>b) cout<<(v/2)*b+v%2*a<<endl;
        else cout<<v*a<<endl;
    }
    return 0;
}