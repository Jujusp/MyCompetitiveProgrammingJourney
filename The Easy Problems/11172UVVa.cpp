#include <bits/stdc++.h>

using namespace std;


int main(){

    long long a, b;
    int n;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        if(a > b){
            printf(">\n");
        }else if(a < b){
            printf("<\n");
        }else{
            printf("=\n");
        }
    }
    return 0;

}
