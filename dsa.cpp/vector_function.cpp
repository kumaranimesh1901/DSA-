#include <iostream>
#include <vector>
using namespace std;

int main()
{
vector<int>vec={1,2,3};
vector<int>vec1(5,6);
vec.push_back(30);
vec.push_back(40);
cout<<"before pop back  "<<vec.size()<<"\n";
vec.pop_back();
cout<<"after pop back  "<<vec.size()<<"\n";

  for(int val:vec)
  {
    cout<<val<<"\n";
  }

return 0;
}