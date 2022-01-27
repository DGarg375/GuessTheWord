#include<bits/stdc++.h>
using namespace std;
int main() {
  fstream file;
  string word, filename;
  filename = "wordList.txt";
  vector<string> wordList;
  file.open(filename.c_str());
  while(file >> word) {
    wordList.push_back(word);
  }
  for(int i = 0; i < wordList.size(); ++i) {
    cout<<wordList[i]<<endl;
  }
  return 0;
}
