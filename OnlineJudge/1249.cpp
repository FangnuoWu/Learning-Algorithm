//1249. 有序分数序列
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class num{
public:
    int mul,den;
    num(int m=0,int d=0):mul(m),den(d){}
    double value()const{return double(mul)/den;}
};    
inline bool cmp(num n1,num n2){
    return (n1.value()<n2.value());
}

//辗转相除法
bool isrp(int a,int b){
	while(1){          // 求出两个正整数的最大公约数
		int t = a%b;
		if(t == 0) break;
		else{
			a = b;
			b = t;
		}
	}
	if(b>1)	return false;// 如果最大公约数大于1，表示两个正整数不互质
	else return true;
}

int main(){
    vector<num> v;
    int n;cin>>n;
    for(int m=1;m<n;++m)
        for(int d=m+1;d<=n;++d){
            if(isrp(m,d)){
                num now(m,d);
                v.push_back(now);
            }           
    }
    sort(v.begin(),v.end(),cmp);

    cout<<"0/1"<<endl;
    for(num c:v)cout<<c.mul<<"/"<<c.den<<endl;
    cout<<"1/1"<<endl;

    return 0;
}