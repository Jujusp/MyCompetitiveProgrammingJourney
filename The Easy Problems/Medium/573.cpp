//Numero 2 sin tanta mkda
#include <iostream>

using namespace std;


int main(){

    cin.tie(0);
    float H, U, D;
    int F;
    while(cin >> H >> U >> D >> F, H != 0){
        int day = 0;
        float height = 0;
        float fatigue = U * ((float)F/100);
        while(height >= 0 && height <= H){
            day++;
            U = (day > 1 ? max(U - fatigue, 0.0f): U);
            height += U;
            if(height > H)
                break;
            height -= D;
           // cout << day << " " << height << " " << U  << " " << fatigue << "\n";
        }
        if(height < 0){
            cout << "failure on day ";
        }else{
            cout << "success on day ";
        }
        cout << day << "\n";

    }
    return 0;
}
