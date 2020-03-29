//4028. 久子的图章

#include <iostream>
#include <cstdio>
using namespace std;

struct Point{
    int x, y;
}seal[1000000];

bool gra[1005][1005] = {0};

void solve(){
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    
    int cntg = 0;
    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= n; ++j){
    		scanf("%d", &gra[i][j]);
    		if (gra[i][j]) ++cntg;
    	}
    int t = 0, cnts = 0;
    for (int i = 1; i <= p; ++i)
    	for (int j = 1; j <= q; ++j){
    		scanf("%d", &t);
    		if (t == 1){
    			++cnts;
    			seal[cnts].x = i;
    			seal[cnts].y = j;
    		}
    	}
    for (int i = 1; i <= m; ++i){
    	for (int j = 1; j <= n; ++j){
    		if (gra[i][j]){
    			for (int l = 2; l <= cnts; ++l){
    				int nx = i + seal[l].x - seal[1].x, ny = j + seal[l].y - seal[1].y;
    				if (nx <= 0 || ny <= 0 || nx > m || ny > n){
    					printf("No\n");
    					return;
    				}
    				if (gra[nx][ny]) gra[nx][ny] = 0;
    				else{
    					printf("No\n");
    					return;
    				}
    			}
    		}
    	}
    }
    printf("Yes\n");
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i != t; ++i)
        solve();
    return 0;
}

