#include <iostream>
#include <string>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    
    string line;

    while(getline(cin, line))
    {
        if(!line.empty() && line.back() == '\r')
        line.pop_back();

        if(line.empty())
            continue;

        if(line.find(':') == string::npos)
        {
            cout << "ERR malformed: " << line << '\n';
            continue;
        }

        int pos = line.find(':');

        string name = line.substr(0, pos);

        transform(name.begin(), name.end(), name.begin(),
                  [](unsigned char c) { return tolower(c); });

        string val = line.substr(pos + 1);

        int i = 0;

        while(i < val.size() && val[i] == ' ')
            i++;

        string actual = val.substr(i);

        cout << name << ": " << actual << '\n';
    }
}