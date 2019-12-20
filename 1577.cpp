#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n,res=0;  
    cin>>n;

    string s,t;
    cin>>s;
    s.erase(s.begin());
    s.erase(s.end()-1);
    while(n--){
        cin>>t;
        t.erase(t.begin());
        t.erase(t.end()-1);
        if(s.size()!=t.size()) continue;
        t+=t;
        if(t.find(s)!=string::npos)res++;
        else{
            string p(t.rbegin(), t.rend());
            if (p.find(s) != string::npos) ++res;
        }
    }
    cout<<res<<endl;
    return 0;
}