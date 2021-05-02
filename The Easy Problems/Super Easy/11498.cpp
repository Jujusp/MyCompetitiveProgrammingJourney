
#include <bits/stdc++.h>

using namespace std;


int main(){


    int n;
    while(scanf("%d", &n), n){
        int x, y;
        scanf("%d %d", &x, &y);
        vector<string> v{"NO", "NE", "SE", "SO", "divisa"};
        while(n--){
            int x1, y1;
            scanf("%d %d", &x1, &y1);
            if(x == x1 || y == y1)
                cout << v[4] <<  "\n";
            else if(x1 > x && y1 > y)
                cout << v[1] << "\n";
            else if(x1 > x)
                cout << v[2] << "\n";
            else if(x1 < x && y1 < y)
                cout << v[3] <<  "\n";
            else
                cout << v[0] << "\n";

        }

    }

    return 0;
}
