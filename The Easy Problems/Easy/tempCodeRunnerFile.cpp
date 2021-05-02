#include <bits/stdc++.h>


using namespace std;


int main(){

    int people, budget, hotels, weeks;
    
    while(scanf("%d %d %d %d", &people, &budget, &hotels, &weeks) == 4){
        vector<pair<int, int>> availability(hotels);
        for(int i = 0; i < hotels; ++i){
            int pr;
            scanf("%d", &pr);
            int maxAvail = INT_MIN;
            for(int j = 0; j < weeks; ++j){
                int temp;
                scanf("%d", &temp);
                maxAvail = max(maxAvail, temp);
            }
            availability[i] = {pr, maxAvail};
        }

        int cost = INT_MAX ;
        for(int j = 0; j < hotels; ++j){
            int c = availability[j].first * people;
            if(c <= budget && availability[j].second >= people){
                cost = min(cost, c);
            }
        }
        if(cost == INT_MAX){
            printf("stay home\n");
            return 0;
        }
        printf("%d\n", cost);
    }
    return 0;
}
