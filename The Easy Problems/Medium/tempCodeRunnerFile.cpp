#include <iostream>
#include <string> 
#include <stdio.h>
#include <limits.h>

using namespace std;


int main(){

    cin.tie(0);
    int n, p;
    int currRFP = 1;
    while(cin >> n >> p, (n || p)){
        for(int i = 0; i < n; ++i){
            string a;
            getline(cin, a);
            cout << a << "\n";
        }

        float bestPrice = INT_MAX;
        float bestCompliance = 0;
        string bestCompany;
        for(int i = 0; i < p; ++i){
            string company;
            getline(cin, company);
            cout << company << "\n";
            float currPrice;
            int compliance;
            cin >> currPrice >> compliance;
            for(int j = 0; j < compliance ; ++j){
                string x;
                getline(cin, x);
            }
            if(compliance > bestCompliance || (compliance == bestCompliance && currPrice < bestPrice)){
                bestCompliance = compliance;
                bestCompany = company;
            }
        }
        cout << "RFP #" << currRFP++ << "\n";
        cout << bestCompany << "\n";
        break;
    }
    return 0;
}
