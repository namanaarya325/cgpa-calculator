#include <iostream>
#include <iomanip>   // for std::setprecision and std::setw
#include <vector>
#include <string>
#include <map>

using namespace std;

// Function to convert grade letter to grade point
float gradeToPoint(string grade) {
    map<string, float> gradeMap = {
        {"A+", 10.0}, {"A", 9.0}, {"B+", 8.0},
        {"B", 7.0}, {"C+", 6.0}, {"C", 5.0},
        {"D", 4.0}, {"F", 0.0}
    };

    if (gradeMap.find(grade) != gradeMap.end()) {
        return gradeMap[grade];
    } else {
        return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    float totalCredits = 0.0, totalGradePoints = 0.0;

    // Vectors to store course-wise details
    vector<string> courseNames;
    vector<string> grades;
    vector<int> credits;

    cout << "📘 CGPA Calculator\n";
    cout << "-------------------------\n";
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Input validation
    while (numCourses <= 0) {
        cout << "❌ Number of courses must be positive. Try again: ";
        cin >> numCourses;
    }

    // Loop to take details for each course
    for (int i = 0; i < numCourses; ++i) {
        string courseName, grade;
        int credit;

        cout << "\n📚 Enter details for Course " << (i + 1) << ":\n";
        cout << "Course Name: ";
        cin.ignore(); // To clear newline character from buffer
        getline(cin, courseName);

        cout << "Grade (A+, A, B+, B, C+, C, D, F): ";
        cin >> grade;

        // Grade validation
        while (gradeToPoint(grade) == -1.0) {
            cout << "❌ Invalid grade. Enter again: ";
            cin >> grade;
        }

        cout << "Credit Hours: ";
        cin >> credit;

        // Credit validation
        while (credit <= 0) {
            cout << "❌ Credit must be a positive number. Try again: ";
            cin >> credit;
        }

        courseNames.push_back(courseName);
        grades.push_back(grade);
        credits.push_back(credit);

        totalCredits += credit;
        totalGradePoints += gradeToPoint(grade) * credit;
    }

    // Calculate GPA
    float cgpa = totalGradePoints / totalCredits;

    // Output Results
    cout << "\n📋 Course-wise Grade Summary:\n";
    cout << "-----------------------------------------\n";
    cout << setw(5) << "No." << setw(20) << "Course Name"
         << setw(10) << "Grade" << setw(10) << "Credits" << "\n";

    for (int i = 0; i < numCourses; ++i) {
        cout << setw(5) << (i + 1)
             << setw(20) << courseNames[i]
             << setw(10) << grades[i]
             << setw(10) << credits[i] << "\n";
    }

    cout << "-----------------------------------------\n";
    cout << fixed << setprecision(2);
    cout << "🎯 Total Credits: " << totalCredits << "\n";
    cout << "🌟 Total Grade Points: " << totalGradePoints << "\n";
    cout << "📈 Final CGPA: " << cgpa << "\n";

    return 0;
}