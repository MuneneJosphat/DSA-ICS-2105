//Part A and B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>c

#define MAX_NAME 50
#define MAX_REG 20
#define MAX_COURSE 30
#define MAX_GRADE 3


typedef struct {
    float marks;
    char grade_letter[MAX_GRADE];
} Grade;

void set_marks(Grade* g, float m) {
    g->marks = m;
}

float get_marks(Grade* g) {
    return g->marks;
}

void calculate_grade(Grade* g) {
    float m = g->marks;
    if (m >= 70) strcpy(g->grade_letter, "A");
    else if (m >= 60) strcpy(g->grade_letter, "B");
    else if (m >= 50) strcpy(g->grade_letter, "C");
    else if (m >= 40) strcpy(g->grade_letter, "D");
    else strcpy(g->grade_letter, "F");
}

Grade get_grade(Grade* g) {
    return *g;
}


typedef struct {
    char course_code[MAX_COURSE];
} Course;

void set_course(Course* c, const char* code) {
    strcpy(c->course_code, code);
}

Course get_course(Course* c) {
    return *c;
}


typedef struct {
    char name[MAX_NAME];
    char reg_no[MAX_REG];
    int age;
    Course course;
    Grade grade;
} Student;

void set_name(Student* s, const char* name) {
    strcpy(s->name, name);
}

char* get_name(Student* s) {
    return s->name;
}

void set_regNo(Student* s, const char* reg) {
    strcpy(s->reg_no, reg);
}

char* get_regNo(Student* s) {
    return s->reg_no;
}

void set_age(Student* s, int age) {
    s->age = age;
}

int get_age(Student* s) {
    return s->age;
}

void set_course_for_student(Student* s, Course c) {
    s->course = c;
}

Course get_course_from_student(Student* s) {
    return s->course;
}

void set_grade_for_student(Student* s, Grade g) {
    s->grade = g;
}

Grade get_grade_from_student(Student* s) {
    return s->grade;
}

void calculate_grade_for_student(Student* s) {
    calculate_grade(&s->grade);
}


typedef struct Node {
    Student data;
    struct Node* next;
} Node;


typedef struct {
    Node* head;
    int size;
} List;

// Constructor: Empty List
List createEmptyList() {
    List l;
    l.head = NULL;
    l.size = 0;
    return l;
}

// Add to end
void addStudent(List* list, Student s) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = s;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    list->size++;
}

// Add at position
void addStudentAt(List* list, Student s, int pos) {
    if (pos < 0 || pos > list->size) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = s;

    if (pos == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (int i = 0; i < pos - 1; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// Remove by reg_no
void removeStudentByReg(List* list, const char* reg) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && strcmp(current->data.reg_no, reg) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return;

    if (prev == NULL)
        list->head = current->next;
    else
        prev->next = current->next;

    free(current);
    list->size--;
}

// Remove at position
void removeStudentAt(List* list, int pos) {
    if (pos < 0 || pos >= list->size) return;

    Node* current = list->head;
    Node* prev = NULL;

    for (int i = 0; i < pos; i++) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
        list->head = current->next;
    else
        prev->next = current->next;

    free(current);
    list->size--;
}

// Return size
int getSize(List* list) {
    return list->size;
}

// Destroy List
void destroyList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}


int main() {
    List students = createEmptyList();

    for (int i = 0; i < 15; i++) {
        Student s;
        Grade g;
        Course c;
        char name[MAX_NAME];
        char reg[MAX_REG];
        char course_code[MAX_COURSE];

        sprintf(name, "Student%d", i + 1);
        sprintf(reg, "CT%d/2025", 1000 + i);
        sprintf(course_code, "COURSE%d", i % 3 + 1);

        set_name(&s, name);
        set_regNo(&s, reg);
        set_age(&s, 18 + i % 4);
        set_course(&c, course_code);
        set_course_for_student(&s, c);

        float marks = 35 + (i * 4) % 70;
        set_marks(&g, marks);
        calculate_grade(&g);
        set_grade_for_student(&s, g);

        addStudent(&students, s);
    }

    // Print All Students
    Node* current = students.head;
    while (current != NULL) {
        Student s = current->data;
        printf("Name: %s | Reg: %s | Age: %d | Course: %s | Marks: %.1f | Grade: %s\n",
               get_name(&s),
               get_regNo(&s),
               get_age(&s),
               get_course_from_student(&s).course_code,
               get_marks(&s.grade),
               s.grade.grade_letter);
        current = current->next;
    }

    destroyList(&students);
    return 0;
}
