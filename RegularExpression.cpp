#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i=0;
    bool valid = true;
    if(s[i]=='a')
    {
        while(s[i]=='a') i++;
    }

    if(s[i]=='b')
    {
        while(s[i]=='b') i++;
    }
    else 
    {
        valid = false;
    }
    if(s.size()!=i or valid!=true)  cout<<"Not Valid"<<endl;
    else cout<<"Valid"<<endl;
    
    return 0;
}