/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
*/


#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <stack>
using namespace std;


struct pren{
	int type;
	bool value;
};

pren findTn(pren *tn,char ch)
{
	switch (ch)
		{
			case '(':
			        tn->type=1;
			        tn->value=true;
			         break;
			case ')':
			        tn->type=1;
			        tn->value=false;
			         break;
			case '[':
			        tn->type=2;
			        tn->value=true;
			         break;
			case ']':
			        tn->type=2;
			        tn->value=false;
			         break;
			case '{':
			        tn->type=3;
			        tn->value=true;
			         break;
			case '}':
			        tn->type=3;
			        tn->value=false;
			        break;
		}
	return *tn;

}


int main()
{
	string s="(){}}{";
    stack<pren> res;
	int i=0;

	  while(i<s.size())
       {
        pren tn;
        tn=findTn(&tn,s[i]);
        if(res.empty())
        {
            if(!tn.value)
            {
                cout<<"NOT EMPTY"<<endl;
                return false;
            }
            else
                res.push(tn);

        }
        else
        {
             if(res.top().type==tn.type && res.top().value && res.top().value != tn.value)
                res.pop();
            else
                res.push(tn);
        }
        i++;
	}

	if(!res.empty())
		cout<<"NOT EMPTY"<<endl;
	else
	     cout<<"EMPTY"<<endl;
        
}