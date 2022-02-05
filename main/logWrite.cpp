#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
void logWrite(std::string logFilename, std::string log)
{
    std::fstream File;
    File.open(logFilename.c_str(), std::ios::app);
    File << log << std::endl;
}