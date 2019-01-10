#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    
    double testScoreSum, maxTestPoints, programAverage, testAverage;
    int quizzesTaken, quizScoreSum, lowQuizSum;
    
    //Prompts user for various scores, assigns each answer to a seperate variable
    cout << "Enter the program average: ";
    cin >> programAverage;
    
    cout << "\nEnter the sum of the testScores: ";
    cin >> testScoreSum;
    
    cout << "Enter the maximum test points available: ";
    cin >> maxTestPoints;
    
    cout << "\nEnter the number of quizzes that have been taken: ";
    cin >> quizzesTaken;
    
    cout << "Enter the sum of all of the quizzes that have been taken: ";
    cin >> quizScoreSum;
    
    cout << "Enter the sum of the two lowest quiz scores: ";
    cin >> lowQuizSum;
    
    //Calculates test average and then the course average
    testAverage = ((testScoreSum + quizScoreSum - lowQuizSum) / (maxTestPoints + (10 * (quizzesTaken - 2))) * 100);
    double courseAverage = ((programAverage * 0.3) + (testAverage * 0.7));
    
    // Displays Results
    cout << fixed << setprecision(2);
    
    cout << "\n***********************************" << endl;
    cout << "Grade Calculator" << endl;
    
    cout << "\nProgram Average        " << setw(12) << programAverage;
    cout << "\nTest Average           " << setw(12) << testAverage << endl;
    
    cout << "\nCourse Average         " << setw(12) <<courseAverage << endl;
    
    cout << "***********************************" << endl;
    
}
