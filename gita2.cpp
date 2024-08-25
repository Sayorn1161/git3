#include <iostream>
#include <cstring>

class Person {
private:
    char* name;
    int age;

public:
    Person() : name(nullptr), age(0) {}
    Person(const char* name, int age) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Person(const Person& other) : age(other.age) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    Person& operator=(const Person& other) {
        if (this == &other) return *this;

        delete[] name;
        this->age = other.age;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        return *this;
    }
    ~Person() {
        delete[] name;
    }
    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Apartment {
private:
    Person* people;
    int numPeople;

public:
    Apartment() : people(nullptr), numPeople(0) {}

    Apartment(int numPeople, Person* people) : numPeople(numPeople) {
        this->people = new Person[numPeople];
        for (int i = 0; i < numPeople; ++i) {
            this->people[i] = people[i];
        }
    }

    Apartment(const Apartment& other) : numPeople(other.numPeople) {
        this->people = new Person[other.numPeople];
        for (int i = 0; i < other.numPeople; ++i) {
            this->people[i] = other.people[i];
        }
    }

    Apartment& operator=(const Apartment& other) {
        if (this == &other) return *this;

        delete[] people;
        this->numPeople = other.numPeople;
        this->people = new Person[other.numPeople];
        for (int i = 0; i < other.numPeople; ++i) {
            this->people[i] = other.people[i];
        }

        return *this;
    }

    ~Apartment() {
        delete[] people;
    }

    void print() const {
        std::cout << "Apartment with " << numPeople << " people:" << std::endl;
        for (int i = 0; i < numPeople; ++i) {
            people[i].print();
        }
    }
};
class House {
private:
    Apartment* apartments;
    int numApartments;

public:
    House() : apartments(nullptr), numApartments(0) {}

    House(int numApartments, Apartment* apartments) : numApartments(numApartments) {
        this->apartments = new Apartment[numApartments];
        for (int i = 0; i < numApartments; ++i) {
            this->apartments[i] = apartments[i];
        }
    }

    House(const House& other) : numApartments(other.numApartments) {
        this->apartments = new Apartment[other.numApartments];
        for (int i = 0; i < other.numApartments; ++i) {
            this->apartments[i] = other.apartments[i];
        }
    }

    House& operator=(const House& other) {
        if (this == &other) return *this;

        delete[] apartments;
        this->numApartments = other.numApartments;
        this->apartments = new Apartment[other.numApartments];
        for (int i = 0; i < other.numApartments; ++i) {
            this->apartments[i] = other.apartments[i];
        }

        return *this;
    }

    ~House() {
        delete[] apartments;
    }
    void print() const {
        std::cout << "House with " << numApartments << " apartments:" << std::endl;
        for (int i = 0; i < numApartments; ++i) {
            apartments[i].print();
        }
    }
};

int main() {
    Person p1("John Doe", 30);
    Person p2("Jane Smith", 28);
    Person p3("Alice Johnson", 25);
    Person people1[] = { p1, p2 };
    Person people2[] = { p3 };
    Apartment apt1(2, people1);
    Apartment apt2(1, people2);
    Apartment apartments[] = { apt1, apt2 };
    House house(2, apartments);
    house.print();
     return 0;
}
