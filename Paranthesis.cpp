#include <bits/stdc++.h>
using namespace std;

int main()
{
    string code;
    string s;
    bool multicomment = false;
    
    while (1)
    {
        getline(cin, s);
        if (s == "x")
            break;
        int n = s.size();
        string s1;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && s[i] == '/' && s[i + 1] == '*')
            {
                multicomment = true;
                i++;
                continue;
            }
            if (i < n - 1 && s[i] == '*' && s[i + 1] == '/')
            {
                multicomment = false;
                i++;
                continue;
            }

            if (multicomment)
                continue;

            if (i < n - 1 && s[i] == '/' && s[i + 1] == '/')
            {
                break;
            }

            s1.push_back(s[i]);
        }

        code.append(s1);
        code.append("\n");
    }
    
    int n = code.size();

    if (n > 0 && (code[0] == ')' || code[0] == '}' || code[0] == ']'))
    {
        cout << "NOT Balance" << endl;
        return 0;
    }

    stack<char> stk;
    bool in_string = false;
    bool in_char = false;

    for (int i = 0; i < n; i++)
    {
        if ((in_string || in_char) && code[i] == '\\' && i + 1 < n)
        {
            i++; 
            continue;
        }

        
        if (code[i] == '"' && !in_char)
        {
            in_string = !in_string;
            continue;
        }

        
        if (code[i] == '\'' && !in_string)
        {
            in_char = !in_char;
            continue;
        }

        
        if (in_string || in_char)
            continue;

       
        if (code[i] == '(' || code[i] == '{' || code[i] == '[')
        {
            stk.push(code[i]);
        }
        else if (code[i] == ')' || code[i] == '}' || code[i] == ']')
        {
            if (stk.empty())
            {
                cout << "NOT Balance" << endl;
                return 0;
            }

            char top = stk.top();

            if ((code[i] == ')' && top == '(') ||
                (code[i] == '}' && top == '{') ||
                (code[i] == ']' && top == '['))
            {
                stk.pop();
            }
            else
            {
                cout << "NOT Balance" << endl;
                return 0;
            }
        }
    }

    if (stk.empty())
    {
        cout << "Balance" << endl;
    }
    else
    {
        cout << "NOT Balance" << endl;
    }

    return 0;
}