#include "../include/menu.h"
#include "../include/utils.h"

#include <iostream>
#include <string>
#include <iomanip>


std::string lines = "-----------------------------------------------------";

int menu(){
    int option;
    std::cout << "\n\n";
    std::cout << lines << std::endl;
    std::cout << std::left << std::setw(23) << "1) Start" << std::setw(23) << "2) Exit" << std::setw(23) << "Option:" << std::endl;
    std::cout << lines;
    std::cout << "\033[A\033[0C";  // move cursor one line up
    std::cin >> option; valid_input();
    return option;
}

int start_menu(){
    int option;
    std::cout << "\n\n";
    std::cout << lines << std::endl;
    std::cout << std::setw(15) << "1) Stop" << std::setw(15) << "2) Lap" << std::setw(15) << "3) Refresh" << std::setw(15) << "Option:" << std::endl;
    std::cout << lines;
    std::cout << "\033[A\033[0C"; // move cursor one line up
    std::cin >> option; valid_input();
    return option;
}

int stop_menu(){
    int option;
    std::cout << "\n\n";
    std::cout << lines << std::endl;
    std::cout << std::setw(15) << "1) Start" << std::setw(15) << "2) Reset" << std::setw(15) << "3) Refresh" << std::setw(15) << "Option:" << std::endl;
    std::cout << lines;
    std::cout << "\033[A\033[0C"; // move cursor one line up
    std::cin >> option; valid_input();
    return option;
}