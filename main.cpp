#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <list>
using namespace std;

int main() {
    int x;
    string y;
    int count;
    while (true) {
        cout << "==== Console diary ====" << endl;
        cout << "Choose what you want to do:" << endl;
        cout << "1. About" << endl;
        cout << "2. Display existing diaries" << endl;
        cout << "3. Edit existing diary" << endl;
        cout << "4. Delete existing diary" << endl;
        cout << "5. Make new diary" << endl;
        cout << "6. Exit" << endl;


        cin >> x;
        switch (x) {
            case 1:
                cout << "=== About ===" << endl;
                cout << "This app allows you to write notes using console, the notes get saved to .txt files" << endl;
                break;
            case 2: {
                cout << "=== Display existing diary ===" << endl;
                if (!filesystem::is_directory("saved_diaries")) {
                    cout << "You have no saved diaries" << endl;
                    break;
                }


                for (auto &file : filesystem::directory_iterator{"saved_diaries"}) {
                    cout << file.path().filename().string() << endl;
                }

                cout << "Which diary do you want to display?" << endl;
                cin >> y;

                fstream file(y);

                getline(file, y);

                cout << y << endl;
                file.close();


                break;
            }
            case 3:
                cout << "=== Edit existing diary ===" << endl;
                break;
            case 4:
                cout << "=== Delete existing diary ===" << endl;
                break;
            case 5: {

                cout << "=== Make new diary ===" << endl;
                cout << "Name: ";

                string name;
                string writing;

                cin >> name;
                cout << endl;

                cout << "Make a writing: " << endl;
                cin >> writing;
                cout << endl;

                if (!filesystem::is_directory("saved_diaries")) {
                    filesystem::create_directory("saved_diaries");
                }

                ofstream WritingFile("saved_diaries/" + name + ".txt");
                WritingFile << writing;

                WritingFile.close();
                break;
            }
            case 6:
                return 0;

            default:
                cout << "Invalid choice" << endl;
                break;
        }

    }

}