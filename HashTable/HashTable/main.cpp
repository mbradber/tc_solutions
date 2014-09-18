#include <iostream>
#include "Table.h"
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, string> tablepair;

class OAT{
public:
    
    OAT():
    mTableLoad(0),
    mTableSize(1)
    {
        Init();
    }
    
    string& Add(int key, const string& value){
        float loadFactor = mTableLoad / mTableSize;
        if(loadFactor > MAX_LOAD){
            RebuildTable();
        }
        
        int probe = 0;
        size_t h;
        while(true){
            h = DH(key, probe++);
            if(mTable[h].first == EMPTY || mTable[h].first == DELETE){
                mTable[h] = make_pair(key, value);
                ++mTableLoad;
                break;
            }
        }
        
        return mTable[h].second;
    }

    string Get(int key) const{
        int probe = 0;
        size_t h;
        while(probe < mTableSize){
            h = DH(key, probe++);
            if(mTable[h].first == key){
                return mTable[h].second;
            }else if(mTable[h].first == EMPTY){
                return "";
            }
        }
        
        return "";
    }
    
    ~OAT(){
        delete[] mTable;
    }
    
    void PrintTable(){
        for(int i = 0; i < mTableSize; ++i){
            cout << mTable[i].first << "," << mTable[i].second << endl;
        }
        cout << endl;
    }
    
private:
    
    void Init(){
        mTable = new tablepair[mTableSize];
        fill_n(mTable, mTableSize, make_pair(EMPTY, ""));
    }
    
    void RebuildTable(){
        // save old stuff
        size_t oldsize = mTableSize;
        tablepair* oldTable = mTable;
        
        // build new table twice as big
        mTableSize *= 2;
        mTableLoad = 0;
        Init();
        
        // rehash old stuff
        for(int i = 0; i < oldsize; ++i){
            Add(oldTable[i].first, oldTable[i].second);
        }
        
        // clean up old stuff
        delete[] oldTable;
        oldTable = NULL;
    }
    
    size_t H(int key, int i) const{
        return H1(key) + i;
    }
    
    size_t DH(int key, int i) const{
        return (H1(key) + i*H2(key)) % mTableSize;
    }
    
    size_t H1(int key) const{
        return key;
    }
    
    size_t H2(int key) const{
        int v = 31 * key;
        if(v & 1) return v;
        else return v - 1;
    }
    
private:
    
    tablepair* mTable;
    size_t mTableSize;
    size_t mTableLoad;
    
    const size_t EMPTY = INT_MAX;
    const size_t DELETE = EMPTY-1;
    const float MAX_LOAD = 0.7f;
};

int main(int argc, const char * argv[])
{
    OAT oat;
    
//    for(int i = 0; i < 100; ++i){
//        char c = 'a' + i;
//        string s = "";
//        s += c;
//        oat.Add(i % 10, s);
//    }
//    
//    oat.PrintTable();
    
    oat.Add(3, "cat");
    oat.Add(2, "bee");
    oat.Add(16, "rhino");
    oat.PrintTable();
    
    cout << oat.Get(2) << endl;
    
    
//    Table t;
//    t.Add(1, "ant") = "aardvark";
//    t.Add(2, "bee");
//    t.Add(5, "elephant");
//    t[6] = "frog";
//    t[6] = "fly";
//    
//    cout << t[1] << endl;
//    cout << t[2] << endl;
//    cout << t[5] << endl;
//    cout << t[6] << endl;

    return 0;
}

