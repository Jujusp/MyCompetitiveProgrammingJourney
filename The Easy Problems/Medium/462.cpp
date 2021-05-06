#include<bits/stdc++.h>

using namespace std;



string temp;

int main(){
    cin.tie(0);
    vector<string> cards(13);
    while(cin >> temp){
        cards[0] = temp;
        for(int i = 1; i < 13; ++i){
            cin >> cards[i];
        }
        vector<int> cardVal(53);
        for(int i = 0; i <= 52; ++i){
            cardVal[i] = 0;
        }
        // S *1, H =10, D=20, C = 30
        for(int i = 0; i < 13; ++i){
            char num = cards[i][0];
            char type = cards[i][1];
            int j = num == 'A' ? 1: num == 'T'? 10: num == 'J'? 11: num == 'Q' ?  12: num == 'K' ? 13: num - '0';
            j += type == 'H' ? 13: type == 'D'? 26: type == 'C' ? 39: 0;
            cardVal[j]++;
        }


        int puntos = 0;
        int rulesExcept = 0;
        bool stopped[4];
        for(int i = 0; i < 4; ++i){
            stopped[i] = 0;
        }
        vector<int> amount(4);
        for(int j = 0; j < 4; ++j){
            int type = 0;
            for(int i = 1; i <= 13; ++i){
                int curr = i + j*13;
                type += cardVal[curr];
                if(cardVal[curr]  ){
                    if( i == 1){
                        puntos += 4;
                    }else if( i >= 11){
                        puntos += i - 10;
                    }
                }
            }
            if(cardVal[1 + j*13]){
                stopped[j] = true;
            }else if(cardVal[j*13 + 13] && type > 1){
                stopped[j] = true;
            }else if(cardVal[j*13 + 12] && type > 2){
                stopped[j] = true;
            }
            if(cardVal[j*13 + 13] && type <= 1){
                puntos -= 1;
            }
            if(cardVal[j*13 + 12] && type <= 2){
                puntos -= 1;
            }
            if(cardVal[j*13 + 11] && type <= 3){
                puntos -= 1;
            }
            if(type == 2){
                puntos += 1;
                rulesExcept += 1;

            }else if(type <= 1){
                puntos += 2;
                rulesExcept += 2;
            }
            amount[j] = type;
        }
        if(puntos < 14){
            cout << "PASS\n";
        }else if(puntos - rulesExcept >= 16 && stopped[0] && stopped[1] && stopped[2] && stopped[3]){
            cout << "BID NO-TRUMP\n";
        }else{
            map<int, char> t;
            t[0] = 'S';
            t[1] = 'H';
            t[2] = 'D';
            t[3] = 'C';
            char best;
            int m = 0;
            for(int i = 0; i < 4; ++i){
                int curr = amount[i];
                if(curr > m){
                    m = curr;
                    best = t[i];
                }
            }
            cout << "BID " << best << "\n";
        }
    }

    return 0;
}
