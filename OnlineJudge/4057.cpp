#include <iostream>
#include <string>
using namespace std;
string s;
int expand(int left,int right){
    while(left>=0&&right<s.size()&&s[left]==s[right]){
        left--;right++;
    }
    return right-left-1;
}
 
int main(){
    cin>>s;
 
    int start=2,end=0,m=1;
    for(int i=0;i<s.size()-1;++i){
        m=max(expand(i,i),expand(i,i+1));
        if(m>end-start+1){
            start=i-(m-1)/2;
            end=i+m/2;
        }
    }
    string sub=s.substr(start,end-start+1);
    if(sub.size()==1)cout<<0;
    else 
    cout<<sub.size()<<'\n'<<sub;
    
    return 0;
}