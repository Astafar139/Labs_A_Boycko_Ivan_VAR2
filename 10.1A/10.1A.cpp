#include <iostream>
#include <string>

using namespace std;

class Subject {
protected:
    int availability;
public:
    Subject() {
        availability = 3;
    }
    Subject(int a) {
        if (a >= 0 && a <= 3) {
            availability = a;
        }
        else {
            availability = 3;
        }
    }

    void set_availability(int a) {
        if (a >= 0 && a <= 3) {
            availability = a;
        }
        else {
            availability = 3;
        }
    }
    int get_availability() {
        return availability;
    }
    void print_availability() {
        cout << availability;
    }
};

class Math : public Subject {
private:
    string section_of_math;
public:
    Math() : Subject() {
        section_of_math = "theory of numbers";
    }
    Math(int a, string s) : Subject(a) {
        section_of_math = s;
    }
    string get_math_section() {
        return section_of_math;
    }
    void print_math_section() {
        cout << section_of_math;
    }
};


class Programming : public Subject {
private:
    string section_of_programming;
public:
    Programming() : Subject() {
        section_of_programming = "theory of algorithms";
    }
    Programming(int a, string s) : Subject(a) {
        section_of_programming = s;
    }
    string get_programming_section() {
        return section_of_programming;
    }
    void print_programming_section() {
        cout << section_of_programming;
    }
};

class Physics : public Subject {
private:
    string section_of_physics;
public:
    Physics() : Subject() {
        section_of_physics = "quantum physics";
    }
    Physics(int a, string s) : Subject(a) {
        section_of_physics = s;
    }
    string get_physics_section() {
        return section_of_physics;
    }
    void print_physics_section() {
        cout << section_of_physics;
    }
};

int main() {
    Math n = Math();
    Physics p = Physics(2, "nuclear physics");
    cout << p.get_physics_section();

    return 0;
}
