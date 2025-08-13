#ifndef UTILS_H
#define UTILS_H

#include <stack>

void valid_input();
void clear_console();
void show_elapsed_time(long total_time, long lap_time);
void start_stopwatch();
void clear_stacks();
void show_stopwatch(const long& milisec, std::stack<int> lap, std::stack<long>split, std::stack<long>total);
std::string format_time(const long& milisec);

#endif