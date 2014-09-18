#include <string>
#include <list>
#include <vector>

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