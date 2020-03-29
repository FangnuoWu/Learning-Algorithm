#include <iostream>

using namespace std;

inline short locate(short x,short y){
    if(x<=3){
        if(y<=3)return 1;
        else if(y<=6)return 2;
        else return 3;
    }
    else if(x<=6){
        if(y<=3)return 4;
        else if(y<=6)return 5;
        else return 6;
    }
    else {
        if(y<=3)return 7;
        else if(y<=6)return 8;
        else return 9;
    }
}

int main(){
    int n;
    cin>>n;

    while(n--){
        bool col[10][10]={0},raw[10][10]={0},block[10][10]={0};
        bool flag=1;
        short data;
        for(short i=1;i!=10;++i)
            for(short j=1;j!=10;++j){
                cin>>data;
                if(col[i][data]||raw[j][data]||block[locate(i,j)][data]){
                    flag=0;
                }else{
                    col[i][data]=1;
                    raw[j][data]=1;
                    block[locate(i,j)][data]=1;
                } 
            }
        cout<<(flag?"Right":"Wrong")<<endl;    
    }
    return 0;
}