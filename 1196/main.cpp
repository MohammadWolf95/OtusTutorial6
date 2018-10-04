#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    multiset<size_t>ss;
    set<size_t>s;
    set<size_t>s1;
    size_t N, M, result=0;
    int date;
    cin>>N;
    for(auto i = 0;i<N;++i){
        //cin>>date;
        cin>>date;
        s.insert(date);
    }

    cin>>M;
    for(auto i = 0;i<M;++i){
        cin>>date;
        ss.insert(date);
    }

    for(auto i:s){
        result+=ss.count(i);
    }

    cout<<result<<endl;
}
