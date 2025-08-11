#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

class Stopwatch{
private:
    bool running;
    long elapsed;
    std::chrono::steady_clock::time_point start_time;

public:
    Stopwatch();
    void start();
    void stop();
    void reset();
    long get_elapsed_time();
};

#endif