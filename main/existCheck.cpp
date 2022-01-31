#include <string>
#include <fstream>
bool existCheck(std::string filename, std::string guessedWord)
{
    std::fstream file1;
    std::string word1;
    file1.open(filename.c_str());
    while (file1 >> word1)
    {
        if (guessedWord == word1)
        {
            return true;
        }
    }
    return false;
}