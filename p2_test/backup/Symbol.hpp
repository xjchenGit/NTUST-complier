#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct DataItem{
    string IdName = " ";
    string type = " ";
    string value = " ";
    string entries = " ";
};

class SymbolTable{
public:
    void lookup(string s);
    bool insert(string s,DataItem value);
    int Dump();
private:
    map<string,DataItem> IdSymbols;
};

void SymbolTable::lookup(string s){
    if (IdSymbols.count(s))
    {
        cout << "find it!"<< endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }
        
}

bool SymbolTable::insert(string s,DataItem value)
{
    if (!IdSymbols.count(s))
    {
        IdSymbols[s]=value;
        return true;
    }else
    {
        return false;
    }
}

int SymbolTable::Dump(){
    cout << ("\n--------------------------------------------\n\t\tSymbol Table");
    cout << ("\n--------------------------------------------\n");
    
    cout << ("Name\tType\tValue\t\tentries\n");
    for(auto it = IdSymbols.begin();it != IdSymbols.end();++it)
    {
        cout
        << it->second.IdName <<"\t"
        << it->second.type <<"\t"
        << it->second.value <<"\t\t"
        << it->second.entries <<"\t"
        << endl;
    }
    cout<<("\n--------------------------------------------\n");
    return IdSymbols.size();
}
