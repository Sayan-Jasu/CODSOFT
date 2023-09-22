#include <bits/stdc++.h>
using namespace std;

map<string, int> students;

void addOrUpdateStudent() 
{
    string name;
    int grade;

    cout << "\033[34mEnter student's name: ";
    cin >> name;

    if (students.find(name) != students.end()) {
        cout << "\033[33mStudent '" << name << "' already exists with grade " << students[name] << ".\n";
        char updateChoice;
        cout << "Do you want to update the grade? (y/n): ";
        cin >> updateChoice;
        if (updateChoice == 'y' || updateChoice == 'Y') {
            cout << "\033[34mEnter the new grade for " << name << ": ";
            cin >> grade;
            students[name] = grade;
        }
    } else {
        cout << "Enter student's grade: ";
        cin >> grade;
        students[name] = grade;
    }cout<<"\033[0m\n";
}

void displayStudents() 
{
    if (students.empty()) {
        cout << "\033[3;31mNo students added yet.\n\033[0m";
    } else {
        cout << "\033[33mList of Students:\n\033[0m";
        for (const auto& student : students) {
            cout << "\033[34mName: " << student.first << ", Grade: \033[3m" << student.second << "\033[0m\n";
        }
    }
}

void calculateAverageGrade() 
{
    if (students.empty()) {
        cout << "\033[3;31mNo students added yet.\033[0m\n";
    } else {
        int total = 0;
        for (const auto& student : students) {
            total += student.second;
        }
        double average = static_cast<double>(total) / students.size();
        cout << "\033[33mAverage Grade: " << average << "\033[0m\n";
    }
}

void findHighestAndLowestGrades() 
{
    if (students.empty()) {
        cout << "\033[3;31mNo students added yet.\033[0m\n";
    } else {
        int highest = (*students.begin()).second;
        int lowest = (*students.begin()).second;
        for (const auto& student : students) {
            highest = max(highest, student.second);
            lowest = min(lowest, student.second);
        }
        cout << "\033[36mHighest Grade: " << highest << "\033[0m\n";
        cout << "\033[35mLowest Grade: " << lowest << "\033[0m\n";
    }
}

int main() 
{
    int choice;
    do {
        cout << "\033[1;35mStudent Grading System\033[0m\n";
        cout << "1. Add Student-grade or Update Grade\n";
        cout << "2. Display Students-Grades\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Find Highest and Lowest Grades\n";
        cout << "5. Quit\n";
        cout << "\033[3;32mEnter your choice: \033[0m";
        cin >> choice;

        switch (choice) {
            case 1:
                addOrUpdateStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                calculateAverageGrade();
                break;
            case 4:
                findHighestAndLowestGrades();
                break;
            case 5:
                char quitChoice;
                cout << "\033[31mAre you sure you want to quit? (y/n): ";
                cin >> quitChoice;
                if (toupper(quitChoice) == 'Y') {
                    cout << "\033[1;3mGoodbye!\n\033[0m";
                    return 0;
                }
                break;
            default:
                cout << "\033[3;37mInvalid choice. Please try again.\033[0m\n";
        }
    } while (true);

    return 0;
}
