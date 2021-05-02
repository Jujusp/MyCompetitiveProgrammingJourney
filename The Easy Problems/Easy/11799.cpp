#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;


int main(){

    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        int n;
        cin >> n;
        int ans = INT_MIN;
        int temp;
        while(n--){
            cin >> temp;
            ans = max(ans, temp);
        }
        cout << "Case " << i <<": " << ans << "\n";
    }
    return 0;
}
