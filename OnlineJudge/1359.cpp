#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int maxtime, section, u, f, d;
    cin >> maxtime >> section >> u >> f >> d;

    int sum = 0, res = 0;
    bool flag = true;
    char c;
    vector<char> v;
    for(int i = 0; i < section ;i++){
        cin >> c; 
        v.push_back(c);
    }
    for(int i = 0; i < section ;i++){
        if (v[i] == 'f') sum+= 2*f;
        else sum+=(u+d);

        if( sum < maxtime) res++;
        else break;
    }
    cout << res <<endl;
    return 0;
}