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
        printf("xish#%s>", filesystem::current_path().string().c_str());
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
        if (args.size() != 0)
        {
            if (args.at(0) == "cd")
            {
                if (args.size() != 2)
                {
                    cout << "Error: Incorrect number of arguments." << endl
                         << "Usage: cd <directory>" << endl;
                }
                else
                {
                    if (args.at(1) == "..")
                    {
                        filesystem::current_path(filesystem::current_path().parent_path());
                    }
                    else
                    {
                        filesystem::path inputtedPath(args.at(1));
                        if (!exists(inputtedPath))
                        {
                            cout << "Error: Path does not exist" << endl;
                        }
                        else
                        {
                            if (!is_directory(inputtedPath))
                            {
                                cout << "Error: Not a directory" << endl;
                            }
                            else
                            {
                                current_path(inputtedPath);
                            }
                        }
                    }
                }
            }
            else if (args.at(0) == "ls")
            {
                for (filesystem::directory_entry d : filesystem::directory_iterator(filesystem::current_path()))
                {
                    cout << d.path().string() << '\n';
                }
            }
        }

        args.clear();
    };
    return 0;
}