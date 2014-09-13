#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

typedef list< pair<int, string> > Chain;

class Table{
public:
    
    Table(){
        mTable.resize(mBucketCount);
    }
    
    void Add(int key, string value){
        int idx = Hash(key);
        mTable[idx].push_back(make_pair(key, value));
    }
    
    string Get(int key){
        int idx = Hash(key);
        for(Chain::iterator itr = mTable[idx].begin(); itr != mTable[idx].end(); ++itr){
            if(itr->first == key){
                return itr->second;
            }
        }
        
        return "";
    }
    
private:
    
    int Hash(int key){
        return key % mBucketCount;
    }
    
    vector<Chain> mTable;
    const int mBucketCount = 4;
};

#include <iostream>

int main(int argc, const char * argv[])
{
    Table t;
    t.Add(1, "ant");
    t.Add(2, "bee");
    t.Add(5, "elephant");
    
    cout << t.Get(1) << endl;
    cout << t.Get(2) << endl;
    cout << t.Get(5) << endl;

    return 0;
}

