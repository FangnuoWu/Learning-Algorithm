#include <iostream>
#include <string>

using namespace std;

int main(){
    string s,t;
    cin>>s>>t;

    int len=s.size();
    bool flag=0;

    if(s==t){cout<<1<<endl;return 0;}
    
    for(int a=1;a<=len/2;++a){//对每一个公因数,flag记录是否可以
        if(len%a==0){
            string tmp;
            for(int i=0;i<a;++i)
                for(int j=0;j<len/a;++j)
                tmp+=s[i+a*j];
            flag=(tmp==t);
            if(flag){
                cout<<a<<endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}