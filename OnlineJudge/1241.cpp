#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    int n,score;cin>>n;
    double gpa;
    for(int i=0;i<n;++i){
        cin>>score;
        switch(score/5){
            case 20:case 19:gpa+=4.3;break;
            case 18:gpa+=4.0;break;
            case 17:gpa+=3.7;break;
            case 16:gpa+=3.3;break;
            case 15:gpa+=3.0;break;
            case 14:gpa+=2.7;break;
            case 13:if(score>=67)gpa+=2.3;
                    else gpa+=2.0;break;
            case 12:if(score>=62)gpa+=1.7;
                    else gpa+=1.0;break;
        }     
    }
    gpa/=n;

    cout << fixed << setprecision(2) << gpa;

    return 0;
}

