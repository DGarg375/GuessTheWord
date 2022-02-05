// Header files
#include <bits/stdc++.h>
#include <stdlib.h>

#include "../header/existCheck.h"
#include "../header/guessCheck.h"
#include "../header/randomGenerate.h"
#include "../header/logWrite.h"
#include "../header/showLog.h"

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
  string name;
  cout << "Enter your name: ";
  cin >> name;
  cout << endl;
  char choice;
  cout << "Do you want to open log of completed words?(y/n): ";
  cin >> choice;
  if (choice == 'y')
  {
    string name2;
    cout << "Enter your name: ";
    cin >> name2;
    showLog(name2);
    cout << endl
         << endl;
    char choice2;
    cout << "Do you want to play the game?(y/n): ";
    cin >> choice2;
    if (choice2 == 'n')
    {
      return 0;
    }
    cout << endl;
  }

  while (remainingTries > 0 && guessedWord != targetWord)
  {
    cout << "  ";
    for (int x = 0; x < remainingLetters.length(); ++x)
    {
      if (remainingLetters[x] == ' ')
      {
        cout << "    ";
      }
      else
      {
        cout << "_   ";
      }
    }
    cout << endl;
    cout << "| ";
    for (int x = 0; x < remainingLetters.length(); ++x)
    {
      cout << remainingLetters[x] << " | ";
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
  string log = name;
  if (guessedWord == targetWord)
  {
    log = log + " guessed the word " + "\"" + targetWord + "\"" + " in " + to_string(6 - remainingTries) + " tries.";
  }
  else
  {
    log = log + " could not guess the word " + "\"" + targetWord + "\"";
  }

  string logFilename = "../resources/log.txt";
  logWrite(logFilename, log);

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
