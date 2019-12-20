//4207. 大主教带队
//question:为什么可以按顺序分组？？

#include <iostream>
#include <algorithm>
using namespace std;

int ability[5000];
int number[5000];

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)scanf("%d",&ability[i]);
    sort(ability,ability+n);

    int team=1,res=1;
    int min_ability=ability[0],max_ability=ability[0];
    for(int i=1;i<n;++i){
        if(ability[i]-min_ability>5){
            number[team]=res;
            min_ability=max_ability=ability[i];
            ++team;
            res=1;
        }
        else{
            max_ability=ability[i];
            ++res;
        }
    }number[team]=res;

    sort(number+1,number+team+1);
    int ans=0;
    for(int i=team;k--&&i;--i)ans+=number[i];
    printf("%d", ans);
    return 0;
}