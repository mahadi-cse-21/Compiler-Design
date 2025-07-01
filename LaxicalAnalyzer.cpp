#include <bits/stdc++.h>
using namespace std;

vector<string> Identifier1;
vector<string> Keywords1;
vector<string> StringLiterals1;
vector<string> Constants1;
vector<string> Operators1;
vector<char> Separators1;

set<string> keywords = {
    "auto","break","case","char","const","continue","default","do","double","else",
    "enum","extern","float","for","goto","if","int","long","register","return","short",
    "signed","sizeof","static","struct","switch","typedef","union","unsigned","void",
    "volatile","while"
};

set<string> operators = {
    "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", 
    "&&", "||", "!", "&", "|", "^", "~", "<<", ">>"
};

set<char> separators = {
    ',', ';', '(', ')', '{', '}', '[', ']'
};

bool iskeyword(const string& s) {
    return keywords.find(s) != keywords.end();
}

bool isoperator(const string& s) {
    return operators.find(s) != operators.end();
}

bool isseparator(char c) {
    return separators.find(c) != separators.end();
}

bool isalphabet(char c) {
    return isalpha(c) || c == '_';
}

void lexicalanlyzer(string code) {
    int cnt = 0;
    int n = code.length();
    for (int i = 0; i < n; ) {
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // Try multi-character operator
        if (i + 1 < n) {
            string two = code.substr(i, 2);
            if (isoperator(two)) {
                Operators1.push_back(two);
                cnt++;
                i += 2;
                continue;
            }
        }

        // Try single-character operator
        string one(1, code[i]);
        if (isoperator(one)) {
            Operators1.push_back(one);
            cnt++;
            i++;
            continue;
        }

        if (isseparator(code[i])) {
            Separators1.push_back(code[i]);
            cnt++;
            i++;
            continue;
        }

        if (code[i] == '"') {
            string s;
            s += code[i++];
            while (i < n && code[i] != '"') {
                s += code[i++];
            }
            if (i < n) s += code[i++];
            StringLiterals1.push_back(s);
            cnt++;
            continue;
        }

        if (isalphabet(code[i])) {
            string id;
            while (i < n && (isalphabet(code[i]) || isdigit(code[i]))) {
                id += code[i++];
            }
            if (iskeyword(id)) {
                Keywords1.push_back(id);
            } else {
                Identifier1.push_back(id);
            }
            cnt++;
            continue;
        }

        if (isdigit(code[i])) {
            string num;
            bool hasDot = false;
            while (i < n && (isdigit(code[i]) || (!hasDot && code[i] == '.'))) {
                if (code[i] == '.') hasDot = true;
                num += code[i++];
            }
            Constants1.push_back(num);
            cnt++;
            continue;
        }

        
        i++;
    }

    cout << "Total " << cnt << " token are available in this code." << endl;

    cout << "Keywords :";
    for (const auto& k : Keywords1) cout << k << " ";
    cout << endl;

    cout << "Identifiers :";
    for (const auto& id : Identifier1) cout << id << " ";
    cout << endl;

    cout << "Operator :";
    for (const auto& op : Operators1) cout << op << " ";
    cout << endl;

    cout << "Separators :";
    for (const auto& sp : Separators1) cout << sp << " ";
    cout << endl;

    cout << "Constant :";
    for (const auto& c : Constants1) cout << c << " ";
    cout << endl;

    cout << "String Literals :";
    for (const auto& s : StringLiterals1) cout << s << " ";
    cout << endl;
}

int main() {
    string code, line;
    while (getline(cin, line)) {
        if (line == "x") break;
        code += line + "\n";
    }
    lexicalanlyzer(code);
}
