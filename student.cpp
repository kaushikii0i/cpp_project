#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    string course;
    float marks;

    void input() {
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore(); // To consume leftover newline
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter course: ";
        getline(cin, course);
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll No: " << rollNumber << ", Name: " << name
             << ", Course: " << course << ", Marks: " << marks << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << "✅ Student added successfully!\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "⚠️ No student records available.\n";
            return;
        }
        cout << "\n--- All Students ---\n";
        for (const auto &s : students) {
            s.display();
        }
    }

    void searchStudent(int roll) const {
        for (const auto &s : students) {
            if (s.rollNumber == roll) {
                cout << "🎯 Student found:\n";
                s.display();
                return;
            }
        }
        cout << "❌ Student with roll number " << roll << " not found.\n";
    }

    void updateStudent(int roll) {
        for (auto &s : students) {
            if (s.rollNumber == roll) {
                cout << "🛠️ Enter new details for the student:\n";
                s.input();
                cout << "✅ Student updated successfully!\n";
                return;
            }
        }
        cout << "❌ Student not found.\n";
    }

    void deleteStudent(int roll) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->rollNumber == roll) {
                students.erase(it);
                cout << "🗑️ Student deleted successfully!\n";
                return;
            }
        }
        cout << "❌ Student not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice, roll;

    do {
        cout << "\n===== Student Management Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> roll;
                manager.searchStudent(roll);
                break;
            case 4:
                cout << "Enter roll number to update: ";
                cin >> roll;
                manager.updateStudent(roll);
                break;
            case 5:
                cout << "Enter roll number to delete: ";
                cin >> roll;
                manager.deleteStudent(roll);
                break;
            case 6:
                cout << "👋 Exiting program. Goodbye!\n";
                break;
            default:
                cout << "⚠️ Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
