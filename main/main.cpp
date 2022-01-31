// Header files
#include <bits/stdc++.h>

#include "../header/existCheck.h"
#include "../header/guessCheck.h"
#include "../header/randomGenerate.h"
// namespaces
using namespace std;

//header files

int main()
{
  fstream file;
  string remainingLetters = "abcdefghijklmnopqrstuvwxyz";
  string word;
  string filename = "../resources/wordList.txt";
  vector<string> wordList;
  file.open(filename.c_str());
  while (file >> word)
  {
    wordList.push_back(word);
  }
  string targetWord = wordList[randomGenerate(wordList)];
  int remainingTries = 6;
  int totalPoints = 60;
  string guessedWord = "";

  while (remainingTries > 0 && guessedWord != targetWord)
  {
    cout << "Remaining Letters: ";
    for (int x = 0; x < remainingLetters.length(); ++x)
    {
      cout << remainingLetters[x] << " ";
    }
    cout << endl
         << endl;
    cout << "Enter your guess: "
         << "(guesses left = " << remainingTries << "): ";
    cin >> guessedWord;
    cout << endl;
    bool integCheck = existCheck(filename, guessedWord);
    if (guessedWord.length() == 5 && integCheck == true)
    {
      cout << "Guess Entered: " << endl;
      for (int i = 0; i < guessedWord.length(); ++i)
      {
        cout << guessedWord[i] << " ";
      }
      cout << endl;
      string hint = guessCheck(targetWord, guessedWord, remainingLetters);
      totalPoints -= 5;
      cout << hint << "               POINTS: " << totalPoints << endl
           << endl;
      --remainingTries;
    }
    else
    {
      if (guessedWord.length() != 5)
      {
        cout << "You have not entered a five letter word! Please enter again." << endl
             << endl;
      }
      else if (integCheck == false)
      {
        cout << "The word you entered does not exist! Please enter again." << endl
             << endl;
        totalPoints -= 1;
        cout << endl
             << "               POINTS: " << totalPoints << endl
             << endl;
      }
    }
  }
  if (remainingTries > 0)
  {
    cout << "You guessed the right word in " << 6 - remainingTries << " tries." << endl;
  }
  else if (remainingTries == 0 && targetWord == guessedWord)
  {
    cout << "You guessed the right word in 6 tries." << endl;
  }
  else
  {
    cout << "You ran out of guesses!" << endl;
    cout << "The target word to be guessed was: " << targetWord << endl;
    totalPoints = 0;
  }
  cout << "Your total points for this game: " << totalPoints << endl
       << endl;
  return 0;
}
