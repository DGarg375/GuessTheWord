// Header files
#include <bits/stdc++.h>

// namespaces
using namespace std;

// Function headers
int randomGenerate(vector<string>);
string guessCheck(string, string);
bool existCheck(string, string);

int main()
{
  vector<char> absentLetters;
  fstream file;
  string word, filename;
  filename = "wordList.txt";
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
      string hint = guessCheck(targetWord, guessedWord);
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

//Checks whether word exists in the english dictionary
bool existCheck(string filename, string guessedWord)
{
  fstream file1;
  string word1;
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

//Generates a random index number in the range [0,wordList.size()]
int randomGenerate(vector<string> wordList)
{
  srand(time(NULL));
  int wordIndex = rand() % wordList.size();
  return wordIndex;
}

//Checks similarities between the target word and attempted guess word.
string guessCheck(string targetWord, string guessedWord)
{
  string s1 = targetWord;
  string s2 = guessedWord;
  string result = "";
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
      }
    }
  }
  return result;
}