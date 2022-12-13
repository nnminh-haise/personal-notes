#include <bits/stdc++.h>

using namespace std;

const int MAX_ARRAY_SIZE = 100000;

class Student {
private:
    string name;
    string studentID;
    string classID;
    double mathGrade;
    double physicGrade;
    double englishGrade;

public:
    Student (string _name = "", 
            string _studentID = "",
            string _classID = "",
            double _mathGrade = 0,
            double _physicGrade = 0,
            double _englishGrade = 0) {

        this->name = _name;
        this->studentID = _studentID;
        this->classID = _classID;
        this->mathGrade = _mathGrade;
        this->physicGrade = _physicGrade;
        this->englishGrade = _englishGrade;
    }

    void setName(string _name) {
        this->name = _name;
    }

    string getName() {
        return this->name;
    }

    void setStudentID(string _studentID) {
        this->studentID = _studentID;
    }

    string getStudentID() {
        return this->studentID;
    }

    void setClassID(string _classID) {
        this->classID = _classID;
    }

    string getClassID() {
        return this->classID;
    }

    void setMathGrade(double _mathGrade) {
        this->mathGrade = _mathGrade;
    }

    double getMathGrade() {
        return this->mathGrade;
    }

    void setPhysicGrade(double _physicGrade) {
        this->physicGrade = _physicGrade;
    }

    double getPhysicGrade() {
        return this->physicGrade;
    }

    void setEnglishGrade(double _englishGrade) {
        this->englishGrade = _englishGrade;
    }

    double getEnglishGrade() {
        return this->englishGrade;
    }

    /*
    * Gets Student's information from user.
    */
    void inputInformation() {
        cout << "Getting student's information!\n\n";
        cout << "Student's name   : ";
        getline(cin, this->name);
        cout << "Student's ID     : ";
        getline(cin, this->studentID);
        cout << "Student's classID: ";
        getline(cin, this->classID);
        cout << "Student's math grade   : ";
        cin >> this->mathGrade;
        cout << "Student's physic grade : ";
        cin >> this->physicGrade;
        cout << "Student's english grade: ";
        cin >> this->englishGrade;
    }

    /*
    *   Puts Student's information.
    */
    void outputInformation() {
        cout << "Student's information:\n\n";
        cout << "Name         : " << this->getName() << endl;
        cout << "Class        : " << this->getClassID() << endl;
        cout << "Student's ID : " << this->getStudentID() << endl;
        cout << "Math grade   : " << this->getMathGrade() << endl;
        cout << "Physic grade : " << this->getPhysicGrade() << endl;
        cout << "English grade: " << this->getEnglishGrade() << endl;
    }

    /*
    *   Overload operator >> for Student object.
    */
    friend istream& operator >> (istream& cin, Student& obj) {
        string name, studentID, classID;
        double mathGrade, physicGrade, englishGrade;
        
        cout << "Getting student's information!\n";
        cout << "Student's name   : ";
        getline(cin, name);
        cout << "Student's ID     : ";
        getline(cin, studentID);
        cout << "Student's classID: ";
        getline(cin, classID);
        cout << "Student's math grade   : ";
        cin >> mathGrade;
        cout << "Student's physic grade : ";
        cin >> physicGrade;
        cout << "Student's english grade: ";
        cin >> englishGrade;

        obj.setName(name);
        obj.setStudentID(studentID);
        obj.setClassID(classID);
        obj.setMathGrade(mathGrade);
        obj.setPhysicGrade(physicGrade);
        obj.setEnglishGrade(englishGrade);

        return cin;
    }

    /*
    *   Overloading operator << for Student object.
    */
    friend ostream& operator << (ostream& cout, Student obj) {
        cout << "Student's information:\n";
        cout << "Name         : " << obj.getName() << endl;
        cout << "Class        : " << obj.getClassID() << endl;
        cout << "Student's ID : " << obj.getStudentID() << endl;
        cout << "Math grade   : " << obj.getMathGrade() << endl;
        cout << "Physic grade : " << obj.getPhysicGrade() << endl;
        cout << "English grade: " << obj.getEnglishGrade() << endl;
        return cout;
    }
};

/*
*   Construct a row for the database.
*/
struct StudentDB {
    int ID;
    Student student;
};

StudentDB* studentList;
int studentCount = 0;
int studentListLastIndex = -1;

/*
*   Initialized the database.
*/
void initStudentList(int arrraySize = MAX_ARRAY_SIZE) {
    studentList = new StudentDB [arrraySize];
    studentCount = 0;
    studentListLastIndex = -1;
    for (int i = 0; i < arrraySize; ++i) {
        studentList[i].ID = -1;
        studentList[i].student = Student();
    }
    return;
}

/*
*   Insert student object to database
*/
bool insertStudent(Student obj) {
    if (studentCount >= MAX_ARRAY_SIZE) {
        return false;
    }

    ++studentListLastIndex;
    studentList[studentListLastIndex].ID = studentListLastIndex;
    studentList[studentListLastIndex].student = obj;
    ++studentCount;
    return true;
}

/*
*   Remove student object out of database
*/
bool removeStudent(int position = studentListLastIndex) {
    if (studentCount == 0) {
        return false;
    }

    --studentCount;
    studentList[position].ID = -1;
    studentList[position].student = Student();
    return true;
}

/*
*   Print the database to the console.
*/
void showStudentDB() {
    for (int i = 0; i <= studentListLastIndex; ++i) {
        if (studentList[i].ID != -1) {
            cout << "ID (primary key): " << studentList[i].ID << endl;
            cout << studentList[i].student << endl;
        }
    }
    return;
}

/*
*   Read student's data from a file
*/
void readStudentListFromFile(string filename = "student-database-input.txt") {
    ifstream cin (filename);

    if (cin.fail()) {
        cerr << "Error while openning " << filename << " to read!\n";
        return;
    }

    initStudentList();

    int dataSize;
    cin >> dataSize;
    cin.ignore();

    for (int i = 0; i < dataSize; ++i) {
        string name, studentID, classID;
        double mathGrade, physicGrade, englishGrade;
        getline(cin, name);
        getline(cin, studentID);
        getline(cin, classID);
        cin >> mathGrade;
        cin >> physicGrade;
        cin >> englishGrade;
        cin.ignore();

        insertStudent(Student(
            name,
            studentID,
            classID,
            mathGrade,
            physicGrade,
            englishGrade
        ));
    }

    cin.close();
    return;
}

/*
*   Print database to a file.
*/
void printStudentDB(string filename = "student-database.txt") {
    ofstream cout (filename, ios_base::out);

    if (cout.fail()) {
        cerr << "Error while openning " << filename << " to write!\n";
        return;
    }

    cout << "Database's size: " << studentCount << "\n\n";

    for (int i = 0; i <= studentListLastIndex; ++i) {
        if (studentList[i].ID != -1) {
            cout << "ID (primary key): " << studentList[i].ID << endl;
            cout << studentList[i].student << endl;
        }
    }

    cout.close();
    return;
}

int main() {

    return 0;
}

