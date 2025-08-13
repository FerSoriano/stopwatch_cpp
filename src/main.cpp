// #include "../include/stopwatch.h"
#include "../include/utils.h"
#include "../include/menu.h"

#include <iostream>

using namespace std;

int main(){
    int _menu;
    bool running = true;
    while(running){    
        _menu = menu();
        if(_menu < 1 || _menu > 2){
            cout << "\n\t*** Invalid option ***\n";
            continue;
        }

        if(_menu == 2){ 
            std::cout<<"\n\n";    
            break; 
        }
        
        if(_menu == 1) { // start
            start_stopwatch();
            running = false;
            std::cout<<"\n\n";
        }
    }
    return 0;
}
