#include<iostream>
#include <vector>

using namespace std;

int main()
{
    int nums=7;
    int arr[7]={1,2,2,1,1,2,1};
   

    for(int val=0;val<nums;val++)
    {
        int count=0;
        for(int ele=val+1; ele<nums;ele++)
        {
            
            if(ele==val)
            {
                count++;
            }
            
        }
        if(count>=nums/2)
        {
            cout<<val;
        }
    }
   
}

//SORTING APPROACH

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int val:nums)
        {
            int freq=0;
            for(int el:nums)
            {
                if(el==val)
                {
                    freq++;
                }
            }
            if(freq>n/2)
            {
                return val;
            }
        }
         return -1;
    }
   
};*/




//MOORE'S VOTING ALGO



/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(freq==0)
            {
                ans=nums[i];
            }
            if(ans==nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    } 
};
*/