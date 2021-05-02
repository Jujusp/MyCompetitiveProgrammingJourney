
#include <bits/stdc++.h>

using namespace std;


int main(){
    int T;
    scanf("%d", &T);
    int i = 1;
    while(T--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("Case %d: %d\n", i++, a + b+ c -(max(a, max(b, c)) + min(a, min(b, c))) );
    }
    return 0;
}
