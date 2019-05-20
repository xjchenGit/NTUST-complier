#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

enum type{
    STRING_type,
    INTEGER_type,
    REAL_type,
    BOOLEAN_type,
    VIOD,
    UNDEFINED
};

struct DataItem{
    string IdName = "None";
    int type = VIOD;
    string entries = "None";

    int val=0;
    bool bval=false;
    double dval=0.0;
    string sval="";
};

class SymbolTable{
public:
    DataItem* lookup(string s);
    bool insert(string s,DataItem value);
    int Dump();
private:
    map<string,DataItem> IdSymbols;
};

DataItem* SymbolTable::lookup(string s){
    if (IdSymbols.count(s))
    {
        return new DataItem(IdSymbols[s]);
    }
    else
    {
        return NULL;
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
    cout << ("\n-----------------------------------------------------------------------\n\t\t\t\tSymbol Table");
    cout << ("\n-----------------------------------------------------------------------\n");
    cout << ("ID\t\tName\t\tType\t\tValue\t\tentries\n");
    string types[] = { "STRING_type", "INTEGER_type", "REAL_type", "BOOLEAN_type", "VIOD" };
    for(auto it = IdSymbols.begin();it != IdSymbols.end();++it)
    {
        
        cout << it->first << "\t\t";
        cout << it->second.IdName <<"\t\t";
        switch (it->second.type)
        {
            case STRING_type:
                cout << "STRING" <<"\t\t";
                break;
            case INTEGER_type:
                cout << "INTEGER" <<"\t\t";
                break;
            case REAL_type:
                cout << "REAL" <<"\t\t";
                break;
            case BOOLEAN_type:
                cout << "BOOLEAN" <<"\t\t";
                break;
            case VIOD:
                cout << "VIOD" <<"\t\t";
                break;
        }
        switch (it->second.type)
        {
            case STRING_type:
                cout << it->second.sval <<"\t\t";
                break;
            case INTEGER_type:
                cout << it->second.val <<"\t\t";
                break;
            case REAL_type:
                cout << it->second.dval <<"\t\t";
                break;
            case BOOLEAN_type:
                cout << it->second.bval <<"\t\t";
                break;
            case VIOD:
                cout << "none" <<"\t\t";
                break;
        }
        cout << it->second.entries <<"\t\t" << endl;
    }
    cout<<("\n-----------------------------------------------------------------------\n");
    return IdSymbols.size();
}


// int main(){
//     vector<SymbolTable> stack;
//     SymbolTable global;
//     SymbolTable local;

//     struct DataItem IdData;
//     struct DataItem IdData2;
//     struct DataItem IdData3;
//     stack.push_back(global);
//     stack.push_back(local);
//     string s="ABC";
//     IdData.IdName="ABC";
//     IdData.type="const";
//     IdData.value="126789";
//     IdData.entries="assginment";

//     string s2="DEF";
//     IdData2.IdName="DEF";
//     IdData2.type="integer";
//     IdData2.value="95645";
//     IdData2.entries="function";

//     string s3="JKL";
//     IdData3.IdName="UIO";
//     IdData3.type="REAL";
//     IdData3.value="131443";
//     IdData3.entries="assgin";

//     bool a=stack[0].insert(s,IdData);
//     bool c=stack[0].insert(s3,IdData3);
//     bool b=stack[1].insert(s2,IdData2);
//     if(a&&b&&c)
//     {
//         cout << "successed!!"<< endl;
//         cout << stack[0].Dump() <<endl;
//         cout << stack[1].Dump() <<endl;
//     }else
//         cout << "failed!!" << endl;
//     // stack.pop_back();
//     // int d=stack.size();
//     // cout << "what is the size of stack" << d << endl;

//     string s4="ABC";
//     stack[0].lookup(s4);

//     return 0;
// }