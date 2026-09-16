#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    string ans = "";

    while(getline(cin, line))
    {
        if(line.empty())
            continue;

        int num = stoi(line, nullptr, 16);

        if(num == 0)
            break;

        string data;
        getline(cin, data);

        for(int i = 0; i < num && i < data.size(); i++)
        {
            ans += data[i];
        }
    }

    cout << ans << endl;

    return 0;
}