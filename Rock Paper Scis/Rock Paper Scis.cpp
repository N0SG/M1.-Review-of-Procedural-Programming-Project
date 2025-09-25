// Rock Paper Scis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <random>

using namespace std;

string getplayerchoice();
string determineroundwinner(string computerchoice, string playerchoice);
int updateplayerscore(string roundwinner, int playerscore);
int updatecomputerscore(string roundwinner, int computerscore);
void declarewinner(int playerscore, int computerscore);

int main() {
    random_device myEngine;
    uniform_int_distribution<int> diceValue(1, 3);

    int playerscore = 0;
    int computerscore = 0;
    string playerchoice;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "You will be facing off against Gizmo!" << endl;
    cout << "Please enter 'rock', 'paper', or 'scissors' to play!" << endl;
    cout << "If you want to stop please enter 'quit' at any time to end the game." << endl;

	//What the choices are aka what do the numbers mean MASON
    while (true) {
        int computerNumber = diceValue(myEngine);
        string computerchoice;

        if (computerNumber == 1) {
            computerchoice = "rock";
        }
        else if (computerNumber == 2) {
            computerchoice = "paper";
        }
        else {
            computerchoice = "scissors";
        }

        playerchoice = getplayerchoice();

        if (playerchoice == "quit") {
            cout << endl;
            break;
        }

        cout << "Gizmo chose: " << computerchoice << endl;

        string roundwinner = determineroundwinner(computerchoice, playerchoice);

	// I couldn't think of a name for the computer so I named it Gizmo
        playerscore = updateplayerscore(roundwinner, playerscore);
        computerscore = updatecomputerscore(roundwinner, computerscore);

        cout << "Your current score is: " << playerscore << endl;
		cout << "Gizmo's score is: " << computerscore << endl;
        cout << endl;
    }

    declarewinner(playerscore, computerscore);

    return 0;
}
// Player's choice input and validation
string getplayerchoice() {
    string choice;
    while (true) {
        cout << "Please enter your choice: ";
        cin >> choice;

        for (char& c : choice) {
            c = tolower(c);
        }

        if (choice == "rock" || choice == "paper" || choice == "scissors" || choice == "quit") {
            return choice;
        }
        else {
            cout << "Invalid input please enter rock, paper, scissors, or quit." << endl;
// Clear the errors I had to call my friend to help me with this part I completely forgot about it
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}
//Draw! 
string determineroundwinner(string computerchoice, string playerchoice) {
    if (computerchoice == playerchoice) {
        cout << "It's a draw!" << endl;
        return "draw";
    }

    if ((playerchoice == "rock" && computerchoice == "scissors") ||
        (playerchoice == "scissors" && computerchoice == "paper") ||
        (playerchoice == "paper" && computerchoice == "rock")) {
        cout << "You win the round!" << endl;
        return "human";
    }
    else {
        cout << "Gizo wins this round!" << endl;
        return "computer";
    }
}

// player's score tracker
int updateplayerscore(string roundwinner, int playerscore) {
    if (roundwinner == "human") {
        return playerscore + 1;
    }
    return playerscore;
}

// Gizmo's score tracker
int updatecomputerscore(string roundwinner, int computerscore) {
    if (roundwinner == "computer") {
        return computerscore + 1;
    }
    return computerscore;
}

void declarewinner(int playerscore, int computerscore) {
    cout << "Its over!" << endl;
    cout << "The final scores are" << playerscore << " - " << computerscore << endl;


    if (playerscore > computerscore) {
        cout << "Congratulations! You won!" << endl;
    }
    else if (computerscore > playerscore) {
        cout << "Gizmo wins this battle but not the war!" << endl;
    }
    else {
        cout << "Draw!" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
