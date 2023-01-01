#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>
using namespace std;

// This is the type returned by checkWord function.
enum ResultType {NOT_SB_WORD,  // word is not a valid Spelling Bee word
                 SB_WORD,      // word is a valid Spelling Bee word, but not a pangram
                 PANGRAM};     // word is a pangram

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
      cout << character;
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



int main()
{
  checkWord("HOLL", "HELLO");
  return 0;
}
