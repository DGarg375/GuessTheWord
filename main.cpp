// Header files
#include<bits/stdc++.h>

// namespaces
using namespace std;

// Function headers
int randomGenerate(vector<string>);
string guessCheck(string , string );

int main() {
  vector<char> absentLetters;
  fstream file;
  string word, filename;
  filename = "wordList.txt";
  vector<string> wordList;
  file.open(filename.c_str());
  while(file >> word) {
    wordList.push_back(word);
  }
  string targetWord = wordList[randomGenerate(wordList)];
  int remainingTries = 6;
  string guessedWord = "";

  while(remainingTries > 0 && guessedWord != targetWord) {
      cout<<"Enter your guess: "<<"(guesses left = "<<remainingTries<<"): ";
      cin>>guessedWord;
      cout<<"Guess Entered: "<<endl;
      for(int i = 0; i < guessedWord.length(); ++i) {
          cout<<guessedWord[i]<<" ";
      }
      cout<<endl;
      string hint = guessCheck(targetWord, guessedWord);
      cout<<hint<<endl;
      --remainingTries;

  }
  if(remainingTries == 0) {
      cout<<"You ran out of guesses!"<<endl;
  }
  else {
      cout<<"You guessed the right word in "<<6-remainingTries<<" tries."<<endl;
  }
  cout<<"The target word was "<<targetWord<<"."<<endl;
  return 0;
}

//Generates a random index number in the range [0,wordList.size()]
int randomGenerate(vector<string> wordList) {
  srand(time(NULL));
  int wordIndex = rand() % wordList.size();
  return wordIndex;
}

//Checks similarities between the target word and attempted guess word.
string guessCheck(string targetWord, string guessedWord) {
   string s1 = targetWord;
   string s2 = guessedWord;
   string result = "";
   for(int i = 0; i < s1.length(); ++i) {
       if(s1[i] == s2[i]) {
           s1[i] = '*';
       }
   }
   for(int i = 0; i < s2.length(); ++i) {
       if(s1[i] == '*') {
           result = result + s2[i] + ' ';
       }
       else {
           bool track = false;
           for(int j=0; j < s1.length(); ++j) {
               if(s2[i] == s1[j]) {
                   result = result + "$ ";
                   s1[j] = '$';
                   track = true;
                   break;
               }
           }
            if(track == false) {
                result = result + "_ ";
            }
       }
   }
   return result;
}
