#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;
};

// Function to add student
void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Marks: ";
    cin >> s.marks;

    file << s.id << " " << s.name << " " << s.marks << endl;
    file.close();

    cout << "Student added successfully!\n";
}

// Function to display students
void viewStudents() {
    ifstream file("students.txt");
    Student s;

    cout << "\n--- Student Records ---\n";
    while (file >> s.id >> s.name >> s.marks) {
        cout << "ID: " << s.id 
             << " Name: " << s.name 
             << " Marks: " << s.marks << endl;
    }
    file.close();
}

// Function to update student
void updateStudent() {
    ifstream file("students.txt");
    vector<Student> students;
    Student s;
    int id, found = 0;

    while (file >> s.id >> s.name >> s.marks) {
        students.push_back(s);
    }
    file.close();

    cout << "Enter ID to update: ";
    cin >> id;

    for (auto &st : students) {
        if (st.id == id) {
            cout << "Enter new name: ";
            cin >> st.name;
            cout << "Enter new marks: ";
            cin >> st.marks;
            found = 1;
        }
    }

    ofstream outFile("students.txt");
    for (auto st : students) {
        outFile << st.id << " " << st.name << " " << st.marks << endl;
    }
    outFile.close();

    if (found) cout << "Student updated!\n";
    else cout << "Student not found!\n";
}

// Function to delete student
void deleteStudent() {
    ifstream file("students.txt");
    vector<Student> students;
    Student s;
    int id;

    while (file >> s.id >> s.name >> s.marks) {
        students.push_back(s);
    }
    file.close();

    cout << "Enter ID to delete: ";
    cin >> id;

    ofstream outFile("students.txt");
    for (auto st : students) {
        if (st.id != id) {
            outFile << st.id << " " << st.name << " " << st.marks << endl;
        }
    }
    outFile.close();

    cout << "Student deleted (if existed).\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}