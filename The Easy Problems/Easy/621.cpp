#include <iostream>

using namespace std;


int main(){

    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string a;
        cin >> a;
        if(a == "1" || a == "4" || a == "78"){
            cout << "+\n";
        }else if(a.substr(a.size() - 2, 2).compare("35") == 0){
            cout << "-\n";
        }else if(a[0] == '9' && a[a.size() - 1] == '4'){
            cout << "*\n";
        }else{
            cout << "?\n";
        }
    }
    return 0;
}