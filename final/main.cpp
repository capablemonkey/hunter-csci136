// Gordon Zheng
// 12/11/2014
//
// to compile: g++ main.cpp -o grades

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
  string fullName;
  int grade;
};

double getAverageGrade(Student students[], int studentsCount) {
  int sum = 0;
  for (int i=0; i < studentsCount; i++) {
    sum += students[i].grade;
  }

  return (sum * 1.0) / studentsCount;
}

Student getBestStudent(Student students[], int studentsCount) {
  int highestGrade = 0;
  Student *highestStudent;

  for (int i=0; i < studentsCount; i++) {
    if (students[i].grade > highestGrade) {
      highestGrade = students[i].grade;
      highestStudent = &students[i];
    }
  }

  return *highestStudent;
}

int main(int argc, char *argv[]) {
  // make sure arg is provided
  if (argc < 2) { 
    cerr << "Usage: ./grades <input_file>" << endl;
    return 1;
  }

  // read file
  ifstream inputFile;
  inputFile.open(argv[1], ios_base::in);

  // collect students:
  Student students[30];
  int studentsCount = 0;

  // buffers:
  string firstName;
  string lastName;
  int grade;

  // parse file:
  while(inputFile) {
    inputFile >> firstName >> lastName >> grade;
    Student newStudent;
    newStudent.fullName = firstName + " " + lastName;
    newStudent.grade = grade;

    students[studentsCount] = newStudent;
    studentsCount++;
  }

  double averageGrade = getAverageGrade(students, studentsCount);
  Student bestStudent = getBestStudent(students, studentsCount);

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "In a class of " << studentsCount
       << " students, the average grade was: " << averageGrade << endl
       << "and the best student was " << bestStudent.fullName
       << ", who scored " << bestStudent.grade
       << "." << endl;
  
  return 0;
}