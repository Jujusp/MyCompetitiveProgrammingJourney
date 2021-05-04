//Numero 2 sin tanta mkda
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main(){

    cin.tie(0);
    vector<string> cards(13);

    for(int i = 0; i < 13; ++i){
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
        int j = num == 'A' ? 1: num == 'T'? 10: num == 'J'? 11: num == 'Q' ?  12: num == 'K' ? 13: (int) num;
        j += type == 'H' ? 13: type == 'D'? 26: type == 'C' ? 39: 0;
        cardVal[j]++;
    }

    int puntos = 0;
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
        if(cardVal[j*13 + 13] && type > 1){
            puntos -= 1;
        }
        if(cardVal[j*13 + 12] && type > 2){
            puntos -= 1;
        }
        if(cardVal[j*13 + 11] && type > 3){
            puntos -= 1;
        }
        if(type == 2){
            puntos += 1;
        }else if(type <= 1){
            puntos += 2;
        }
    }


    return 0;
}
