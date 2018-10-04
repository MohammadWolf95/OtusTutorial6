#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    size_t count;
    cin>>count;
    multimap<string, int>mm;
    vector<string>debAcc;

    for(int i = 0;i<count;++i){
        string str;
        cin>>str;
        mm.insert(make_pair(str,0));
    }
    multimap<string, int>::iterator it = mm.begin();
    while(it!=mm.end()){
        auto nx = next(it,1);
        if((*it).first==(*nx).first)
            debAcc.emplace_back((*it).first);
        it=mm.upper_bound(it->first);
    }
    for(auto i:debAcc)
        cout<<i<<endl;
}
