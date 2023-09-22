#include <bits/stdc++.h>
using namespace std;

bool isTxtFile(const string& filename) {
    size_t dotPosition = filename.find_last_of('.');
    if (dotPosition != string::npos) {
        string extension = filename.substr(dotPosition + 1);
        return extension == "txt";
    }
    return false;
}

int main() 
{
    cout<<"\033[34m";
    cout << "                                     _______    _______    ______               _______    _______               _         _________" << endl;
    cout << "                         |\\     /|  (  ___  )  (  ____ )  (  __  \\             (  ____ \\  (  ___  )  |\\     /|  ( (    /|  \\__   __/" << endl;
    cout << "                         | )   ( |  | (   ) |  | (    )|  | (  \\  )            | (    \\/  | (   ) |  | )   ( |  |  \\  ( |     ) (   " << endl;
    cout << "                         | | _ | |  | |   | |  | (____)|  | |   ) |            | |        | |   | |  | | _ | |  |   \\ | |     | |   " << endl;
    cout << "                         | |( )| |  | |   | |  |     __)  | |   | |            | |        | |   | |  | |( )| |  | (\\ \\) |     | |   " << endl;
    cout << "                         | || || |  | |   | |  | ( \\ \\__  | |   ) |            | |        | |   | |  | || || |  | | \\   |     | |   " << endl;
    cout << "                         | () () |  | (___) |  | ) \\ \\__  | (__/  )            | (____/\\  | (___) |  | () () |  | )  \\  |     | |   " << endl;
    cout << "                         (_______)  (_______)  |/   \\__/  (______/             (_______/  (_______)  (_______)  |/    )_)     )_(   " << endl;
    cout<<"\033[0m\n\n";
    cout << "\033[1;3;36m!!!Please ensure your text file is saved as a text file in the same folder as this program.\n\n";
    cout << "\033[23;33mEnter the file name (e.g., 'input.txt' or provide the full file path): \033[0m\n";
    
    string fileName,name;
    cin >> fileName;
    name = fileName;

    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "\033[1;31m File not found. Please use a valid existing (\033[33m.txt\033[31m) file.\033[0m" << endl;
        return 1;
    }

    if (!isTxtFile(name)) {
        cout << "\033[1;31m\n\n\nInvalid file type:use .txt file only. Please follow these steps:" << endl;
        cout << "1. Go to the same folder as this C++ program." << endl;
        cout << "2. Create a new file named 'input.txt'." << endl;
        cout << "3. Copy and paste the text contents from your file into 'input.txt'." << endl;
        cout << "4. Enter 'input.txt' as the file name.\033[0m" << endl;
        return 1;
    }

    string word;
    int wordCount = 0;

    while (inputFile >> word) {
        wordCount++;
    }

    cout << "\033[1;3;32m\n\nTotal word count: \033[21;35m" << wordCount << "\033[0m\n";

    inputFile.close();
    return 0;
}
