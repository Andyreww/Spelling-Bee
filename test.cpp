// Project 2: Spelling Bee
// Authors: Allyson Schaaf and Andrew Angulo

#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>
using namespace std;

// This is the type returned by checkWord function.
enum ResultType {NOT_SB_WORD,  // word is not a valid Spelling Bee word
                 SB_WORD,      // word is a valid Spelling Bee word, but not a pangram
                 PANGRAM};     // word is a pangram

/* Check whether a word is a valid Spelling Bee word with the given letters.

   Parameters:
      word:    a candidate word
      letters: a string of 7 letters, with the middle letter first

   Return value: a value of ResultType indicating whether word is valid      */

ResultType checkWord(string word, string letters)
{
  //word can't be too short
  if (word.length() < 3) //good
  {
    return NOT_SB_WORD;
  }

  //word must contain first character in string letter
  char middle_letter = letters[0];
  if (word.find(middle_letter) == string::npos)
  {
    return NOT_SB_WORD;
  }


  bool check_letters = true;
  for (int i = 0; i < word.length(); i++)
  {
    char character = word[i];
    if (letters.find(character) == string::npos)
    {
      check_letters = false;
      return NOT_SB_WORD;
    }
  }

  //test between pangram and normal word
  if (check_letters = true)
  {
    int count = 0;
    for (int i = 0; i <= letters.length(); i++)
    {
      if (word.find(letters[i]) != string::npos)
      count++;
      else
      count;
    }
    if (count >= letters.length())
    {
      return PANGRAM;
    }
    else
    {
      return SB_WORD;
    }
  }

  //just in case
  cout << "not";
  return NOT_SB_WORD;
}


int spellingBee(string dictFileName, string letters, int& score)
{
  fstream myFile;
  myFile.open(dictFileName);
  int wordCount = 0;

  if(!myFile.good())
  {
    cout << "ERROR: File not found" << endl;
    exit(1);
  }
  while(myFile.good()) //Checks to see if the file is good
  {
    string word;
    getline(myFile, word);
    //------//
    if(checkWord(word, letters) == SB_WORD)
    {
      wordCount++;
      score += 1;
    }
    else if(checkWord(word, letters) == SB_WORD && word.length() > 4)
    {
      wordCount++;
      score += word.length();
    }
    else if(checkWord(word, letters) == PANGRAM)
    {
      wordCount++;
      score += word.length() + 7;
    }
    else
    {
      score;
    }
  }
  myFile.close();
  return wordCount++;
}

int main(int argc, char* argv[])
{
    if ((argc != 2) || (strlen(argv[1]) != 7))
    {
        cout << "Usage: " << argv[0] << " <7 letters, middle letter first>" << endl;
        exit(1);
    }

    string letters = argv[1];  // the spelling bee letters, middle letter first
    int score;                 // the score assigned to the solution
    int count;                 // the number of words found

    count = spellingBee("spelling_bee_lexicon.txt", letters, score);

    cout << "Number of words found: " << count << endl;
    cout << "Total score: " << score << endl;

    return 0;
}
