#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;

int main(int argc, char *argv[])
{
    string inputline;
    string word = "";

    while (true)
    {
        inputline = "";
        printf("bish#%s>", filesystem::current_path().string().c_str());
        getline(cin, inputline);
        vector<string> args;

        char *inputcstr = new char[inputline.length() + 1];
        strcpy(inputcstr, inputline.c_str());

        char *i = strtok(inputcstr, " ");

        while (i != 0)
        {
            args.push_back(i);
            i = strtok(NULL, " ");
        }

        /*for (string x: args) {
            std::cout << x << std::endl;
        }*/
        
        //cout << args[0] << endl;
        /*for (int z = 0; z < args.at(0).size(); z++) {

        }*/
        if (args.at(0) == "cd")
        {
            if (args.size() != 2) {
                cout << "Error: Incorrect number of arguments." << endl << "Usage: cd <directory>" << endl;
            } else {
                filesystem::path inputtedPath(args[1]);
                if (!exists(inputtedPath)) {
                    cout << "Error: Path does not exist" << endl;
                } else {
                    if (!is_directory(inputtedPath)) {
                        cout << "Error: Not a directory" << endl;
                    } else {
                        current_path(inputtedPath);
                    }
                }
                
            }
            
        }

        args.clear();
    };
    return 0;
}