/* Maximum Number of Words You Can Type-quesion 1935 - easy level
There is a malfunctioning keyboard where some letter keys do not work.
All other keys on the keyboard work properly.
Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, 
return the number of words in text you can fully type using this keyboard.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


void splitText(string *text,vector<string>*wordArray)
{
	istringstream my_string(*text);  
    string word; 
    //split every word in the string
    while (my_string >> word) 
    {
        wordArray->push_back(word);
    }
}


int main()
{
	string text="hello world";
	string brokenLetters="ad";
	int cnt=0;
	int cnt2=0;
	vector<string>wordArray;
	splitText(&text,&wordArray);
       
   for(int i=0;i<wordArray.size();i++)
    {
        for(int j=0;j<brokenLetters.size();j++)
        {
            size_t found = wordArray[i].find(brokenLetters[j]);
            if (found != string::npos)
                cnt++;

        }
     if(cnt!=0)
     {
         cnt2++;
         cnt=0;
     }
    }
    cout<< (wordArray.size()-cnt2)<<endl;
    }


