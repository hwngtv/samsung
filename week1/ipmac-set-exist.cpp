#include <bits/stdc++.h>
using namespace std;
int main()
{
        int n;
        cin>>n;
        set<int> s;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(s.find(temp)==s.end())cout<<0<<endl;
            else cout<<1<<endl;
            s.insert(temp);
        }
    return 0;
}
