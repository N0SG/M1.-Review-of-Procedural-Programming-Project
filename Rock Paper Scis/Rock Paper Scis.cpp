// Rock Paper Scis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int numoftests = 5;
const int maxstudents = 20;

int readDataFromFile(ifstream& file, string names[], int grades[][numoftests]);
void calculateAverages(int numStudents, int grades[][numoftests], double averages[]);
string getLetterGrade(double average);
void gradereport(int numStudents, string names[], double averages[]);

int main() {
    string studentNames[maxstudents];
    int studentScores[maxstudents][numoftests];
    double studentAverages[maxstudents];

    //Open da file
    ifstream inputFile("StudentGrades.txt");

    if (!inputFile) {
        cout << "Error with opening the file! Please make sure its in the same folder." << endl;
        return 1;
    }

    //Reads the data and sets variables
    int numStudents = readDataFromFile(inputFile, studentNames, studentScores);
    calculateAverages(numStudents, studentScores, studentAverages);
    gradereport(numStudents, studentNames, studentAverages);

    inputFile.close();

    return 0;
}

int readDataFromFile(ifstream& file, string names[], int grades[][numoftests]) {
    int numofstudent = 0;
    while (numofstudent < maxstudents && file >> names[numofstudent]) {
        for (int i = 0; i < numoftests; ++i) {
            file >> grades[numofstudent][i];
        }
        numofstudent++;
    }
    return numofstudent;
}

void calculateAverages(int numStudents, int grades[][numoftests], double averages[]) {
    for (int i = 0; i < numStudents; ++i) {
        int sum = 0;
        for (int j = 0; j < numoftests; ++j) {
            sum += grades[i][j];
        }
        averages[i] = static_cast<double>(sum) / numoftests;
    }
}

string getLetterGrade(double average) {
    if (average >= 90) {
        return "A";
    }
    else if (average >= 80) {
        return "B";
    }
    else if (average >= 70) {
        return "C";
    }
    else if (average >= 60) {
        return "D";
    }
    else {
        return "F";
    }
}

//Spits out the report
void gradereport(int numStudents, string names[], double averages[]) {
    cout << "------------------------------------------" << endl;
    cout << "|             STUDENT GRADES             |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << left << setw(20) << "|Student Name" << setw(10) << "Average" << "Grade" << "      |" << endl;
    cout << "|----------------------------------------|" << endl;

    for (int i = 0; i < numStudents; ++i) {
        string grade = getLetterGrade(averages[i]);
        cout << "|" << setw(20) << names[i]
            << fixed << setprecision(2) << setw(10) << averages[i]
            << grade << setw(20) << "         |" << endl;
    }

    cout << "------------------------------------------" << endl;
}
//Formatting the ascii table was a pain
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
