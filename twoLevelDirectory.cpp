#include <iostream>
#include <set>
#include <string>
using namespace std;

void create(string& fname, set<string>& files, set<string>& users)
{
    string uname; 
    auto pos = fname.find("/");
    auto it = fname.begin() + pos;

    if (pos == string::npos)
    {
        cerr << "Either user or file name not specified." << endl;
        return;
    }
    else // extracting username from `fname`
    {
        uname = string(fname.begin(), it);
    }

    if(fname.length() == uname.length() + 1) // in case fname = "uname\" ie no actual file name provided
    {
        cerr << "No file name provided." << endl;
        return;
    }

    if (users.find(uname) == users.end()) // find `uname` in the `users` set
    {
        cerr << "User doesn't exist" << endl;
        return;
    }

    auto it2 = files.find(fname); // find `fname` from `files` set to check if it exists
    if (it2 != files.end())
    {
        cerr << "File already exists."<<endl;
    }
    else
    {
        files.insert(fname); // inserting new `fname` to `files` set
    }
}
// display list of files and users in ordered manner
void display(set<string>& files, set<string>& users)
{
    set<string> instances = files;
    instances.insert(users.begin(), users.end());
    for (auto instance: instances)
    {
        cout << instance << endl;
    }
}
// remove a file given file path `fname` and the two sets
void remove(string& fname, set<string>& files, set<string>& users)
{   
    auto pos = fname.find("/"); // find the slash that separates user name and actual file name.
    auto it = fname.begin() + pos;

    if (pos == string::npos)
    {       
        cerr << "User not specified." << endl;
        return;
    }

    auto it2 = files.find(fname);
    if (it2 != files.end())
    {
        files.erase(it2); // removing the element pointed to by iterator `it2`
    }
    else
    {
        cerr << "File not found." << endl;
    }
}
// create or "make" a user 
void mkusr(string& uname, set<string>& users)
{
    if (users.find(uname) == users.end())
    {
        users.insert(uname);
    }
    else
    {
        cerr << "User already exists."<<endl;
    }
}
// does a substring string given the substring `fname`
void search(string& fname, set<string>& files)
{   
    bool flag = 0;
    for (auto file: files)
    {
        if (file.find(fname) != string::npos) 
        {
            cout << file << endl;
            flag = 1;
        }
    }
    if (not flag) cerr << "No matches found." << endl;  
}

int main()
{
    string fname, uname, command;
    set<string> files, users; // used an std::set because no duplicates allowed

    while(true) // looping until users types in "exit"
    {
        cout << ">> "; // chevron prompt
        cin >> command;

        if (command == "create" or command == "insert" or command == "touch")
        {
            cin >> fname;
            create(fname, files, users);
        }
        else if (command == "display" or command == "show" or command == "ls")
        {
            display(files, users);
        }
        else if (command == "delete" or command == "remove" or command == "rm")
        {
            cin >> fname;
            remove(fname, files, users);
        }
        else if (command == "mkusr")
        {
            cin >> uname;
            mkusr(uname, users);
        }
        else if (command == "find" or command == "search")
        {
            cin >> fname;
            search(fname, files);
        }
        else if (command == "exit" or command == "quit" or command == "q")
        {
            break;
        }
        else
        {
            cout << "Invalid command." << endl;
        }
    }
}