#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

typedef list< pair<int, string> > Chain;

class Table{
public:
    Table();
    string& Add(const int& key, const string& value);
    string& Get(int key);
    string& operator[](const int& key);
    
private:
    int Hash(const int& key);
    
    vector<Chain> mTable;
    const int mBucketCount = 4;
};

Table::Table(){
    mTable.resize(mBucketCount);
}

string& Table::Add(const int& key, const string& value){
    int idx = Hash(key);
    mTable[idx].push_back(make_pair(key, value));
    
    return mTable[idx].back().second;
}

string& Table::Get(int key){
    int idx = Hash(key);
    
    for(Chain::iterator itr = mTable[idx].begin(); itr != mTable[idx].end(); ++itr){
        if(itr->first == key){
            return itr->second;
        }
    }
    
    return Add(key, "Default");
}

string& Table::operator[](const int& key){
    return Get(key);
}

int Table::Hash(const int& key){
    return key % mBucketCount;
}

int main(int argc, const char * argv[])
{
    Table t;
    t.Add(1, "ant") = "aardvark";
    t.Add(2, "bee");
    t.Add(5, "elephant");
    t[6] = "frog";
    t[6] = "fly";
    
    cout << t[1] << endl;
    cout << t[2] << endl;
    cout << t[5] << endl;
    cout << t[6] << endl;

    return 0;
}

