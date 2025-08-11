#include "../include/stopwatch.h"
#include "../include/utils.h"
#include <iostream>
#include <stack>
#include <utility> // for swap
#include <iomanip>


using namespace std;


int menu();
int start_menu();
int stop_menu();

void show_elapsed_time(long total_time, long lap_time);
void start_stopwatch();
void clear_stacks();
void show_stopwatch(const long& total_time, stack<int> lap, stack<long>time);

long current_elapsed_ime;

stack<long> time_stack;
stack<int> lap_stack;
int laps = 0;

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
            clear_console();
            start_stopwatch();
        }
    }
    return 0;
}

void start_stopwatch(){
    int _start_menu, _stop_menu;
    bool running = true;
    Stopwatch main_sw;
    Stopwatch lap_sw;
    while(running){
        main_sw.start(); // start
        lap_sw.start();
        show_stopwatch(main_sw.get_elapsed_time(), lap_stack, time_stack);

        _start_menu = start_menu();

        if(_start_menu < 1 || _start_menu > 3){
            cout << "\n\t*** Invalid option ***\n";
            continue;
        }

        if(_start_menu == 1){ // stop
            clear_console();
            main_sw.stop();
            lap_sw.stop();
            // show_elapsed_time(main_sw.get_elapsed_time(),lap_sw.get_elapsed_time());
            show_stopwatch(main_sw.get_elapsed_time(), lap_stack, time_stack);
            while(true){
                _stop_menu = stop_menu();
                if(_stop_menu < 1 || _stop_menu > 2){
                    cout << "\n\t*** Invalid option ***\n";
                    continue;
                }
                
                if(_stop_menu == 1){ // start
                    main_sw.start();
                    lap_sw.start();
                    break;
                }
                
                if(_stop_menu ==  2){ // reset
                    main_sw.reset();
                    lap_sw.reset();
                    clear_stacks();
                    running = false;
                    laps = 0;
                    break;
                }
            }
        }

        if(_start_menu == 2){ // lap
            lap_sw.stop();
            long split = lap_sw.get_elapsed_time();
            laps++;
            lap_stack.push(laps);
            time_stack.push(split);
            lap_sw.reset();
        }
    }
}


int menu(){
    int option;
    cout << "\n\n";
    cout << "1) Start" << endl;
    cout << "2) Exit" << endl;
    cout << "Option: ";
    cin >> option; valid_input();
    return option;
}

int start_menu(){
    int option;
    cout << "\n\n";
    cout << "1) Stop" << endl;
    cout << "2) Lap" << endl;
    cout << "Option: ";
    cin >> option; valid_input();
    return option;
}

int stop_menu(){
    int option;
    cout << "\n\n";
    cout << "1) Start" << endl;
    cout << "2) Reset" << endl;
    cout << "Option: ";
    cin >> option; valid_input();
    return option;
}

void show_elapsed_time(long total_time, long lap_time){
    cout << "Total elapsed time: " << total_time << " ms\n";
    cout << "Lap elapsed time: " << lap_time << " ms\n";
}

void clear_stacks(){
    stack<long> empty_time_stack;
    stack<int> empty_lap_stack;
    swap(lap_stack, empty_lap_stack); 
    swap(time_stack, empty_time_stack);
}

void show_stopwatch(const long& total_time, stack<int> lap, stack<long>time){
    clear_console();
    cout << "\n-----------------\n";
    cout << "\t" << total_time << " s.";
    cout << "\n-----------------\n";
    cout << left << setw(10) << "Lap No." << setw(10) << "Split" << endl;
    while (!lap.empty()) {
        cout << left << setw(10) << lap.top() << setw(10) << time.top() << endl;
        lap.pop();
        time.pop();
    }
}