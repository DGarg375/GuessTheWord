#include<bits/stdc++.h>
using namespace std;

int randomGenerate(vector<string>);

int main() {
  fstream file;
  string word, filename;
  filename = "wordList.txt";
  vector<string> wordList;
  file.open(filename.c_str());
  while(file >> word) {
    wordList.push_back(word);
  }
  string targetWord = wordList[randomGenerate(wordList)];
  return 0;
}
int randomGenerate(vector<string> wordList) {
  srand(time(NULL));
  int wordIndex = rand() % wordList.size();
  return wordIndex;
}
