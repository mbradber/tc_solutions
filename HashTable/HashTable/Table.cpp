#include "Table.h"

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