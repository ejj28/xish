#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    string inputline;
    string word = "";
    string path = "/home/erik";

    while (true)
    {
        inputline = "";
        printf("bish#%s>", path.c_str());
        getline(cin, inputline);
        vector<char*> args;

        char *inputcstr = new char[inputline.length() + 1];
        strcpy(inputcstr, inputline.c_str());

        char *i = strtok(inputcstr, " ");

        while (i != 0)
        {
            args.push_back(i);
            i = strtok(NULL, " ");
        }

        for (string x: args) {
            std::cout << x << std::endl;
        }
        //cout << args[0] << endl;

        if (args[0] == "cd")
        {

            path = args[1];
        }

        args.clear();
    };
    return 0;
}