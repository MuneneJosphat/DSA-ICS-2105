// part c

#include <iostream>
#include <cstring>
using namespace std;

class Grade {
    float marks;
    char grade_letter[3];

public:
    Grade() {
        marks = 0;
        strcpy(grade_letter, "F");
    }

    void setMarks(float m) {
        marks = m;
    }

    float getMarks() {
        return marks;
    }

    void calculateGrade() {
        if (marks >= 70) strcpy(grade_letter, "A");
        else if (marks >= 60) strcpy(grade_letter, "B");
        else if (marks >= 50) strcpy(grade_letter, "C");
        else if (marks >= 40) strcpy(grade_letter, "D");
        else strcpy(grade_letter, "F");
    }

    const char* getGrade() {
        return grade_letter;
    }
};

class Course {
    char course_code[30];

public:
    Course() {
        strcpy(course_code, "UNSET");
    }

    void setCourseCode(const char* code) {
        strcpy(course_code, code);
    }

    const char* getCourseCode() {
        return course_code;
    }
};

class Student {
    char name[50];
    char regNo[20];
    int age;
    Course course;
    Grade grade;

public:
    Student() {
        strcpy(name, "Unknown");
        strcpy(regNo, "N/A");
        age = 0;
    }

    void setName(const char* n) {
        strcpy(name, n);
    }

    void setRegNo(const char* r) {
        strcpy(regNo, r);
    }

    void setAge(int a) {
        age = a;
    }

    void setCourse(Course c) {
        course = c;
    }

    void setGrade(Grade g) {
        grade = g;
    }

    Course getCourse() {
        return course;
    }

    Grade getGrade() {
        return grade;
    }

    const char* getName() {
        return name;
    }

    const char* getRegNo() {
        return regNo;
    }

    int getAge() {
        return age;
    }

    void calculateGrade() {
        grade.calculateGrade();
    }

    void printInfo() {
        cout << "Name: " << name
             << " | RegNo: " << regNo
             << " | Age: " << age
             << " | Course: " << course.getCourseCode()
             << " | Marks: " << grade.getMarks()
             << " | Grade: " << grade.getGrade() << endl;
    }
};

class Node {
public:
    Student data;
    Node* next;

    Node(Student s) {
        data = s;
        next = nullptr;
    }
};

class LinkedList {
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void addStudent(Student s) {
        Node* newNode = new Node(s);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next)
                current = current->next;
            current->next = newNode;
        }
        size++;
    }

    void addStudentAt(Student s, int pos) {
        if (pos < 0 || pos > size) return;
        Node* newNode = new Node(s);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < pos - 1; i++)
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void removeStudentByReg(const char* reg) {
        Node* current = head;
        Node* prev = nullptr;

        while (current && strcmp(current->data.getRegNo(), reg) != 0) {
            prev = current;
            current = current->next;
        }

        if (!current) return;

        if (!prev)
            head = current->next;
        else
            prev->next = current->next;

        delete current;
        size--;
    }

    void removeStudentAt(int pos) {
        if (pos < 0 || pos >= size) return;
        Node* current = head;
        Node* prev = nullptr;

        for (int i = 0; i < pos; i++) {
            prev = current;
            current = current->next;
        }

        if (!prev)
            head = current->next;
        else
            prev->next = current->next;

        delete current;
        size--;
    }

    int getSize() {
        return size;
    }

    void printAll() {
        Node* current = head;
        while (current) {
            current->data.printInfo();
            current = current->next;
        }
    }

    void destroy() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }
};


int main() {
    LinkedList list;

    for (int i = 0; i < 15; i++) {
        Student s;
        Grade g;
        Course c;

        char name[50], reg[20], course_code[30];
        sprintf(name, "Student%d", i + 1);
        sprintf(reg, "CT%d/2025", 1000 + i);
        sprintf(course_code, "COURSE%d", i % 3 + 1);

        s.setName(name);
        s.setRegNo(reg);
        s.setAge(18 + i % 4);
        c.setCourseCode(course_code);
        s.setCourse(c);

        float marks = 35 + (i * 4) % 70;
        g.setMarks(marks);
        s.setGrade(g);
        s.calculateGrade();

        list.addStudent(s);
    }

    cout << "\nAll students in list:\n";
    list.printAll();

    list.destroy();
    return 0;
}
