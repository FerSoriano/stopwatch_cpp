#include "../include/stopwatch.h"

Stopwatch::Stopwatch(){
    running = false;
    elapsed = 0;
}

void Stopwatch::start(){
    if (!running) {
        running = true;
        start_time = std::chrono::steady_clock::now();
    }
}

void Stopwatch::stop(){
    if (running) {
        auto now = std::chrono::steady_clock::now();
        elapsed += std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
        running = false;
    }
}

void Stopwatch::reset(){
    running = false;
    elapsed = 0;
}

long Stopwatch::get_elapsed_time(){
    if (running) {
        auto now = std::chrono::steady_clock::now();
        return elapsed + std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
    }
    return elapsed;
}