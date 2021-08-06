/*------------------792. Number of Matching Subsequences(Medium)-----------------
Given a string s and an array of strings words, 
return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from
the original string with some characters (can be none) deleted without changing the 
relative order of the remaining characters.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t) {
    int j=0;
    size_t found=-1;
    for(int i=0;i<s.size();i++)
    {
        
        found = t.find(s[i],found+1);
        if (found == string::npos)
            return false;
    }
        
    return true;
        
}
int numMatchingSubseq(string s, vector<string>& words) {
    int cnt=0;
    for(int i=0;i<words.size();i++)
    {
        if(isSubsequence(words[i],s))
            cnt++;
    }
    return cnt;
        
}
int main()
{
    string s="abcde";
    vector<string>words={"a","bb","acd","ace"};
    cout<<numMatchingSubseq(s,words)<<endl;
}