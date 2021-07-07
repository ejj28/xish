#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    string inputline;
    string word = "";
    string path = "C:\\Users\\Erik";
    while (true)
    {
        printf("bish#%s>",path);
        getline(cin, inputline);
        vector<string> args;

        for (char c : inputline)
        {
            if (c == ' ')
            {

                args.push_back(word);

                word = "";
            }
            else
            {
                word = word + c;
            }
        }

        args.push_back(word);

        /*for (string x: args) {
            std::cout << x << std::endl;
        }*/
        cout << args[0] << endl;
        
        if (args[0] == "cd") {

            path = args[1];
            
        }

        args.clear();
    };
    return 0;
}