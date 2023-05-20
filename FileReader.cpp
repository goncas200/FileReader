#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace filesystem;

void read_file(string file_name) {
    ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }
    else
        cout << "Couldn't open the file\n";
}

int main(int argc, char** argv) {
    if (argc == 1) {
        string filename;
        cout << "What's the filename?: ";
        getline(cin, filename);
        read_file(filename);
    }
    else if (argc == 2) {
        current_path(argv[1]);
        string filename;
        cout << "What's the filename?: ";
        getline(cin, filename);
        read_file(filename);
    }
    else {
        cout << "Error: There are too much arguments";
        return 1;
    }
    return 0;
}

