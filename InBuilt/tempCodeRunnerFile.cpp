#include <iostream>

using namespace std;


int main(){

    cin.tie(0);
    int n;
    int A[3001];
    while(cin >> n){ 
        for(int i = 0; i < 3001; ++i){
            A[i] = 0;
        }
        int previous;
        int current;
        cin >> previous;
        for(int i = 1; i < n; ++i){
            cin >> current;
            A[ abs(previous - current)]++;
            previous = current;
        }
        bool flag = false;
        for(int i = 1; i < n && !flag; ++i){
            if(A[i] == 0){
                cout << "Not jolly" << "\n";
                flag = true;
            }
        }
        if(!flag)
            cout << "Jolly" << "\n";

    }
    return 0;
}
