#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    string ans = "";

    getline(cin, line);

    int pos = line.find(' ');
    int statusCode = stoi(line.substr(0, pos));
    int headerCount = stoi(line.substr(pos + 1));

    ans += "HTTP/1.1 ";

    if(statusCode == 200)
        ans += "200 OK\r\n";
    else if(statusCode == 201)
        ans += "201 Created\r\n";
    else if(statusCode == 204)
        ans += "204 No Content\r\n";
    else if(statusCode == 400)
        ans += "400 Bad Request\r\n";
    else if(statusCode == 404)
        ans += "404 Not Found\r\n";
    else if(statusCode == 401)
        ans += "401 Unauthorized\r\n";
    else if(statusCode == 500)
        ans += "500 Internal Server Error\r\n";
    else if(statusCode == 301)
        ans += "301 Moved Permanently\r\n";

    bool hasContentLength = false;

    for(int i = 0; i < headerCount; i++)
    {
        getline(cin, line);

        if(!line.empty() && line.back() == '\r')
            line.pop_back();

        ans += line + "\r\n";

        int colon = line.find(':');

        string name = line.substr(0, colon);

        if(name == "Content-Length" ||
           name == "content-length")
        {
            hasContentLength = true;
        }
    }

    string body = "";

    while(getline(cin, line))
    {
        if(!line.empty() && line.back() == '\r')
            line.pop_back();

        if(!body.empty())
            body += "\n";

        body += line;
    }

    if(!hasContentLength)
    {
        ans += "Content-Length: ";
        ans += to_string(body.size());
        ans += "\r\n";
    }

    ans += "\r\n";
    ans += body;

    cout << ans;

    return 0;
}