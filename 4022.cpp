#include <iostream>
#include <string>
using namespace std;
/*
int main(){
    long long n,valid;int x,mod;
    cin>>x>>n;
    valid=(n+x-8)/7;
        mod=(n+x-8)%7;
    }
    else {
        valid=(n+x-1)/7+1;
        mod=(n+x-1)%7;
    }
    if(mod==6||mod==7)valid+=5-mod;
    cout<<1250*valid<<endl;
    return 0;
}*/
int main(){
	int x, n;
	cin >> x >> n;
	int p = n / 7 * 5;
	n %= 7;
	for (int i = x; i <= x + n - 1; ++i){
		if ((i % 6 == 0) || (i % 7 == 0)) continue;
		++p;
	}
	cout << p * 250 << endl;
	return 0;
}