#include <string>

std::string guessCheck(std::string targetWord, std::string guessedWord, std::string &remainingLetters)
{
    std::string s1 = targetWord;
    std::string s2 = guessedWord;
    std::string result = "";
    for (int i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == s2[i])
        {
            s1[i] = '*';
        }
    }
    for (int i = 0; i < s2.length(); ++i)
    {
        if (s1[i] == '*')
        {
            result = result + s2[i] + ' ';
        }
        else
        {
            bool track = false;
            for (int j = 0; j < s1.length(); ++j)
            {
                if (s2[i] == s1[j])
                {
                    result = result + "$ ";
                    s1[j] = '$';
                    track = true;
                    break;
                }
            }
            if (track == false)
            {
                result = result + "_ ";
                for (int k = 0; k < remainingLetters.length(); ++k)
                {
                    if (s2[i] == remainingLetters[k])
                    {
                        remainingLetters.erase(k, 1);
                        break;
                    }
                }
            }
        }
    }
    return result;
}