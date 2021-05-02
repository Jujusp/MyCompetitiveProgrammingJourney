#include <bits/stdc++.h>


using namespace std;


int main(){

    cin.tie(0);
    int people, budget, hotels, weeks;

    while(cin >> people >> budget >> hotels >> weeks){
        vector<pair<int, int>> availability(hotels);
        for(int i = 0; i < hotels; ++i){
            int pr;
            cin >> pr;
            int maxAvail = INT_MIN;
            for(int j = 0; j < weeks; ++j){
                int temp;
                cin >> temp;
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
            cout << "stay home\n";
        }else{
            cout << cost << "\n";
        }
        availability.clear();

    }
    return 0;
}
