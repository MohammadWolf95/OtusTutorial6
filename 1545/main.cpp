#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int count = 0;
    multimap<char, string>mm;
    char character;
    cin>>count;

    for(int i=0;i<count;++i){
        string sequence;
        cin>>sequence;
        mm.insert(make_pair(sequence.at(0),sequence));
    }
    cin>>character;
    for(multimap<char, string>::iterator it = mm.equal_range(character).first;
        it!=mm.equal_range(character).second;++it){
        cout<<(*it).second<<endl;
    }
}
