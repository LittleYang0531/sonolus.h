#ifndef FUNCNODE_H
#define FUNCNODE_H

using namespace std;

class FuncNode {
    public:
    bool isValue;
    double value;
    EngineDataFunctionName func;
    vector<FuncNode> args;

    FuncNode(){};
    FuncNode(double value): isValue(true), value(value){};
    FuncNode(EngineDataFunctionName func, vector<FuncNode> args): isValue(false), func(func), args(args){};

    string stringify(int tabSize = 2, int maxSize = 100, int tabDepth = 0) {
        string result = "", tab = "", singleTab = "";
        for (int i = 1; i <= tabDepth * tabSize; i++) tab.push_back(' ');
        for (int i = 1; i <= tabSize; i++) singleTab.push_back(' ');
        if (isValue) return tab + "ValueNode { value: " + to_string(value) + " }";
        result += tab + "FuncNode {\n";
        result += tab + singleTab + "func: '" + EngineDataFunctionNameString[func] + "',\n";
        result += tab + singleTab + "args: [\n";
        for (int i = 0; i < min((int)args.size(), maxSize); i++)
            result += args[i].stringify(tabSize, maxSize, tabDepth + 2) + (i == args.size() - 1 ? "" : ",") + "\n";
        if (args.size() > maxSize)
            result += tab + singleTab + singleTab + "... " + to_string(args.size() - maxSize) + " more items\n";
        result += tab + singleTab + "]\n";
        result += tab + "}";
        return result;
    }
};

ostream& operator << (ostream& out, FuncNode x) {
    out << x.stringify();
    return out;
}

#endif