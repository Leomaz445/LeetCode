/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/


#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*This solution is using a hash map to put all the values of the array and his indexes - taking O(n)
  Then in the main part we using hash find command to find a value that by adding the both values
  will give as the result - using search is O(1) and moving throw the array is O(n).
  The time complexity is O(n)*/
int main()
{
    //question paramaters
    vector<int> gv={3,2,4};
    int target=6; //the target number we looking for
    //ans paramaters
    map<int,int> result;
    map<int,int> ::iterator rlt;
    int sum=0;
    vector<int> ans;
    for(int i=0;i<gv.size();i++)
    {
        result.insert(pair<int,int>(gv[i],i));
    }
    for(int i=0;i<gv.size();i++)
    {
        sum=target-gv[i];
        rlt=result.find(sum);
        if(rlt!=result.end()&& rlt->first!=gv[i])
        {
            if(rlt->first+gv[i]==target)
            {
                cout<<rlt->first<<" "<<gv[i]<<endl;
                ans.push_back(rlt->second);
                ans.push_back(i);
                break;
            }
        }

    }
    cout<<"The final result is: "<<endl;
    cout<<"First Index: "<< ans[0]<<endl;
    cout<<"Second Index: "<< ans[1]<<endl;

    return 0;
}
