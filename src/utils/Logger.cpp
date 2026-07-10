#include "utils/Logger.h"

#include <iostream>
using namespace std;
void Logger::info(const string& message){
    cout << "[INFO] " << message << endl;
}
void Logger::warning(const std::string& message){
    cout << "[WARNING] " << message << endl;
}
void Logger::error(const std::string& message){
    cerr << "[ERROR] " << message << endl;
}