// #include "../include/stopwatch.h"
#include "../include/utils.h"
#include "../include/menu.h"

#include <iostream>

using namespace std;

int main(){
    int _menu;
    while(true){    
        _menu = menu();
        if(_menu < 1 || _menu > 2){
            cout << "\n\t*** Invalid option ***\n";
            continue;
        }

        if(_menu == 2){ break; }
        
        if(_menu == 1) { // start
            start_stopwatch();
        }
    }
    return 0;
}
