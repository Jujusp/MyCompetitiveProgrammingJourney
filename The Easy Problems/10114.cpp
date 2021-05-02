#include <bits/stdc++.h>

using namespace std;


void printVector(vector<pair<int, float>> v){
    for(int i = 0; i < v.size(); ++i){
        printf ("%d %f \n", v[i].first, v[i].second);
    }

}

void printAnswer(int i){
    if(i == 1){
        printf("1 month\n");
        return;
    }
    printf("%d months\n", i);
}

void processLoan(vector<pair<int, float>> &deprec, int duration, float downPayment, float loan, int records){

    int d = 0;
    float currDep = deprec[d].second;
    float carPrice = loan + downPayment;
    float monthlyPayment = loan / duration;
    for(int i = 0; i < duration; ++i){
        if(d + 1 < records && deprec[d + 1].first == i)  currDep = deprec[++d].second;
        carPrice = (carPrice) * ( 1 - currDep);
        //printf("%f %f %d %f %d\n", loan, carPrice, i, currDep, d);
        if(loan < carPrice){ 
            printAnswer(i);
            return;
        }
        loan -= monthlyPayment;
    }
    printAnswer(duration);

}
int main(){
    int duration, records;
    float downPayment, loan;
    while (scanf("%d %f %f %d", &duration, &downPayment, &loan, &records), duration > 0){
        vector<pair<int, float>> deprecation(records);
        int i = 0;
        int rec = records;
        while(records--){
            int a;
            float b;
            scanf("%d %f", &a, &b);
            deprecation[i++] = {a, b};
        }
/*         for(int i = 0; i < deprecation.size(); ++i){
            printf("%d %f\n", deprecation[i].first, deprecation[i].second);
        } */
        processLoan(deprecation, duration, downPayment, loan, rec);
        deprecation.clear();
    }

    return 0;
}
