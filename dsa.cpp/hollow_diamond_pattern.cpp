 #include<iostream>
 using namespace std;

 int main()
 {
    int n;
    cout<<"enter the vale of n";
    cin>>n;
    //top stars
    for(int i=0;i<n;i++)
    {
        //outer space
        for(int j=0;j<n-1-i;j++)
        {
            cout<<" ";
        }
        cout<<"*";
        if(i!=0)
        {
            //inner space
            for(int j=0;j<2*i-1;j++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<"\n";
    }
    // bottom stars
    for (int i = 0; i < n-1; i++)
    {
        //for outer  space
       for(int j=0;j<i+1;j++)
       {
        cout<<" ";
       }
       cout<<"*";
       if(i!=n-2)
       {
        //for inner space
        for(int j=0;j<2*(n-i)-5;j++)
        {
            cout<<" ";
        }
        cout<<"*";
       }
        cout<<"\n";
    }
    
 }