#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <set>

# define INF 0x3f3f3f3f

using namespace std;

void Adj(string name1, string name2, string name3);
void recourse_func(map<string, int>&_m, size_t n);

map<string, map<string, int>>m;
map<string, string>result_m;
map<string,long long> dist;

void shortestPath(string src)
{
    // Create a set to store vertices that are being
    // prerocessed
    set< pair<int, string> > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)


    // Insert source itself in Set and initialize its
    // distance as 0.
    setds.insert(make_pair(0, src));
    dist[src]=0;

    /* Looping till all shortest distance are finalized
       then setds will become empty */
    while (!setds.empty())
    {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<int, string> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        string u = tmp.second;

        // 'i' is used to get all adjacent vertices of a vertex
        map<string, int>::iterator i;
        for (i = m[u].begin(); i != m[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            string v = (*i).first;
            int weight = (*i).second;

            //  If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                /*  If distance of v is not INF then it must be in
                    our set, so removing it and inserting again
                    with updated less distance.
                    Note : We extract only those vertices from Set
                    for which distance is finalized. So for them,
                    we would never reach here.  */
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    for (auto i:dist){
        if(i.second==INF)
            cout<<i.first<<' '<<"undefined"<<endl;
        else
            cout<<i.first<<' '<<i.second<<endl;
    }
}

int main(int argc, char *argv[])
{
    map<string,long long>d;
    d.insert(make_pair("s",INF));
    int b = d["s"];
    int n = 0;

    cin>>n;

    for(int i=0;i<n;++i){
        string name1, name2, name3;
        cin>>name1>>name2>>name3;
        Adj(name1, name2, name3);
    }
    if(dist.find("Isenbaev")!=dist.end())
        shortestPath("Isenbaev");
    else{
        for (auto i:dist){
            cout<<i.first<<' '<<"undefined"<<endl;
        }
    }
}

void Adj(string name1, string name2, string name3){
    dist.insert(make_pair(name1,INF));
    dist.insert(make_pair(name2,INF));
    dist.insert(make_pair(name3,INF));
    map<string, map<string, int>>::iterator it = m.find(name1);
    if(it==m.end()){
        map<string, int>new_m;
        new_m.insert(make_pair(name2, 1));
        new_m.insert(make_pair(name3, 1));
        m.insert(make_pair(name1, new_m));
    }
    else{
        (*it).second.insert(make_pair(name2,1));
        (*it).second.insert(make_pair(name3,1));
    }

    it = m.find(name2);
    if(it==m.end()){
        map<string, int>new_m;
        new_m.insert(make_pair(name1, 1));
        new_m.insert(make_pair(name3, 1));
        m.insert(make_pair(name2, new_m));
    }
    else{
        (*it).second.insert(make_pair(name1,1));
        (*it).second.insert(make_pair(name3,1));
    }

    it = m.find(name3);
    if(it==m.end()){
        map<string, int>new_m;
        new_m.insert(make_pair(name1, 1));
        new_m.insert(make_pair(name2, 1));
        m.insert(make_pair(name3, new_m));
    }
    else{
        (*it).second.insert(make_pair(name1,1));
        (*it).second.insert(make_pair(name2,1));
    }
}
