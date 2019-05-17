#include <iostream>
#include <map>
using namespace std;

struct IdData{
    string IdName = "";
    string type = "";
    string value = "";
    bool func = false;
};


class SymbolTable{
public:
    struct create();
    IdData* lookup(string s);
    void insert(string *s,string *type,string *value);
    int Dump();
    void delete();
private:
    map<string,IdData> IdSymbols;
};
