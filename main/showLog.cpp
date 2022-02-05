#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

void showLog(std::string name)
{
    std::cout << std::endl;
    std::fstream Filename;
    std::string log;
    std::string logFile = "../resources/log.txt";
    Filename.open(logFile.c_str());
    while (getline(Filename, log))
    {
        if (strstr(log.c_str(), name.c_str()))
        {
            std::cout << log << std::endl;
        }
    }
}