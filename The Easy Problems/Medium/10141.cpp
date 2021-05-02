#include <iostream>
#include <string> 
#include <stdio.h>
#include <limits.h>

using namespace std;


int main(){

    cin.tie(0);
    int n, p;
    int currRFP = 1;
    string a;
    while(cin >> n >> p, (n || p)){
        for(int i = 0; i < n; ++i){
            cin.ignore();
            getline(cin, a);
        }

        float bestPrice = INT_MAX;
        float bestCompliance = -1;
        string bestCompany;
        for(int i = 0; i < p; ++i){
            string company;
            getline(cin, company);
            float currPrice;
            int compliance;
            cin >> currPrice >> compliance;
            cin.ignore();
            for(int j = 0; j < compliance ; ++j){
                getline(cin, a);
            }
            if(compliance > bestCompliance || (compliance == bestCompliance && currPrice < bestPrice)){
                bestCompliance = compliance;
                bestCompany = company;
                bestPrice = currPrice;
            }
        }
        if(currRFP > 1){
            cout << "\n";
        }
        cout << "RFP #" << currRFP++ << "\n";
        cout << bestCompany << "\n";
    }
    return 0;
}
