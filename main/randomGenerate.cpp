#include <vector>
#include <string>

int randomGenerate(std::vector<std::string> wordList)
{
    srand(time(NULL));
    int wordIndex = rand() % wordList.size();
    return wordIndex;
}