#include "../include/utils.h"
#include "../include/stopwatch.h"
#include "../include/menu.h"

#include <iostream>
#include <limits>
#include <utility> // swap
#include <iomanip>
#include <stack>
#include <sstream>

int laps = 0;
std::stack<int> lap_stack;
std::stack<long> split_stack;
std::stack<long> total_stack;

void valid_input(){
    if (!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void clear_console(){
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // macOS/Linux
    #endif
};

// TODO: separate into a new module?
void start_stopwatch(){
    int _start_menu, _stop_menu;
    bool running = true;
    Stopwatch main_sw;
    Stopwatch lap_sw;
    while(running){
        main_sw.start(); // start
        lap_sw.start();
        
        clear_console();
        std::cout<<"Running..."<<std::endl;
        show_stopwatch(main_sw.get_elapsed_time(), lap_stack, split_stack, total_stack);
        _start_menu = start_menu();

        if(_start_menu < 1 || _start_menu > 3){
            continue;
        }

        if(_start_menu == 1){ // stop
            main_sw.stop();
            lap_sw.stop();
            while(true){
                clear_console();
                std::cout<<"On hold..."<<std::endl;
                show_stopwatch(main_sw.get_elapsed_time(), lap_stack, split_stack, total_stack);
                _stop_menu = stop_menu();
                if(_stop_menu < 1 || _stop_menu > 3){
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
            laps++;
            lap_stack.push(laps);
            split_stack.push(lap_sw.get_elapsed_time());
            total_stack.push(main_sw.get_elapsed_time());
            lap_sw.reset();
        }
    }
    clear_console();
    std::cout<<"Reset..."<<std::endl;
    show_stopwatch(main_sw.get_elapsed_time(), lap_stack, split_stack, total_stack);

}

void show_elapsed_time(long total_time, long lap_time){
    std::cout << "Total elapsed time: " << total_time << " ms\n";
    std::cout << "Lap elapsed time: " << lap_time << " ms\n";
}

void clear_stacks(){
    std::stack<int> empty_lap_stack;
    std::stack<long> empty_split_stack;
    std::stack<long> empty_total_stack;
    std::swap(lap_stack, empty_lap_stack); 
    std::swap(split_stack, empty_split_stack);
    std::swap(total_stack, empty_total_stack);
}

void show_stopwatch(const long& milisec, std::stack<int> lap, std::stack<long>split, std::stack<long>total){
    // TODO: Identify the max and min
    std::string time_str = format_time(milisec);
    std::string lines = "-----------------------------------------------------";
    
    std::cout << "\n\n";
    std::cout << lines << std::endl;
    std::cout << "\t\t\t" << time_str << std::endl;
    std::cout << lines << std::endl;
    std::cout << std::left << std::setw(23) << "Lap No." << std::setw(23) << "Split" << std::setw(23) << "Total" << std::endl;
    while (!lap.empty()) {
        std::cout << std::left << std::setw(23) << lap.top() << std::setw(23) << format_time(split.top()) << std::setw(23) << format_time(total.top()) << std::endl;
        lap.pop();
        split.pop();
        total.pop();
    }
}

std::string format_time(const long& milisec) {
    long hours = milisec / 3600000;
    long remaining_hours = milisec % 3600000;
    long mins = remaining_hours / 60000;
    long remaining_mins = remaining_hours % 60000;
    int segs = remaining_mins / 1000;

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hours << ":"
       << std::setw(2) << std::setfill('0') << mins << ":"
       << std::setw(2) << std::setfill('0') << segs;

    return ss.str();
}