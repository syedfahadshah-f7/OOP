#include <iostream>
using namespace std;

template<class T>
class Pet {
    T name;
    T age;
public:
    Pet(T name, T age): name(name), age(age) { }
    virtual void makeSound() = 0;
    void information() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

template <class T>
class Cat: public Pet<T> {
public:
    Cat(T name, T age): Pet<T>(name, age) { }
    void makeSound() {
        cout << "Meow" << endl;
    }
};

template <class T>
class Dog: public Pet<T> {
public:
    Dog(T name, T age): Pet<T>(name, age) { }
    void makeSound() {
        cout << "Woof" << endl;
    }
};

template <class T>
class Bird: public Pet<T> {
public:
    Bird(T name, T age): Pet<T>(name, age) { }
    void makeSound() {
        cout << "Chirp" << endl;
    }
};

int main() {
    Pet<string> *pet;
    Dog<string> dog("Babloo", "2");
    Cat<string> cat("Maoo", "3");
    Bird<string> bird("Kako", "1");
    pet = &dog;
    pet->makeSound();
    pet->information();
    cout<<endl<<endl;
    pet = &cat;
    pet->makeSound();
    pet->information();
    cout<<endl<<endl;
    pet = &bird;
    pet->makeSound();
    pet->information();
    return 0;
}
