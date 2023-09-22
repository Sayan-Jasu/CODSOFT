//Task 1 for CodSoft C++ developer Internship  

#include <bits/stdc++.h>

using namespace std;

int main() 
{    
    srand(static_cast<unsigned int>(time(nullptr))); //to choose a new random number everytime, we add the real-time from clock

    int secretNumber = rand() % 100 + 1; //generate the secret number

    int tries = 0; //count the tries the player took to guess
    int guess; // input the player's guess
    
    cout<<"\n\n\n";
    cout << "\033[1;3;31m                                          -x-x-x-x-x-x-x-      Welcome to the Number Guessing Game!      -x-x-x-x-x-x-x-      " << endl;
    cout<<"\n\n\n";
    cout << "\033[21;33m          !!!!      I'm thinking of a number between 1 and 100.                   !!!!" << endl;
    cout << "          !!!!      You have to guess my number with as few tries as possible.    !!!!" << endl;
    cout << "          !!!!      Just start guessing and typing until you get it right!        !!!!\033[0m" << endl;
    cout<<"\n\n";

    do {
        cout << "\033[5;36m   !Enter your guess: \033[0m\t";
        cin >> guess;
        ++tries;
        cout<<"\n\n";

        int difference = abs(guess - secretNumber);

        if (difference == 0) {
            cout << "                            \033[1;3;32m-x-x-x-x-x-x-x-     \033[4mCongratulations! You guessed the number in " << tries << " tries\033[24m     -x-x-x-x-x-x-x-\033[0m" << endl;
        } else if (difference <= 10) {
            if (guess < secretNumber) {
                cout << "\033[1;35mVery close, but try little higher.\033[0m" << endl;
            } else {
                cout << "\033[1;35mVery close, but try little lower.\033[0m" << endl;
            }
        } else if (difference <= 50) {
            if (guess < secretNumber) {
                cout << "\033[35mVery low! Try higher.\033[0m" << endl;
            } else {
                cout << "\033[35mVery high! Try lower.\033[0m" << endl;
            }
        } else {
            if (guess < secretNumber) {
                cout << "\033[2;35mWay too low! Try much higher!\033[0m" << endl;
            } else {
                cout << "\033[2;35mWay too high! Try much lower!\033[0m" << endl;
            }
        }
        cout<<"\n\n";
    } while (guess != secretNumber);

    cout<<"\n\n\n";

    return 0;
}

