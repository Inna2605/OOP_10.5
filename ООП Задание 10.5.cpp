// Добавить в код на слайде 5 презентации по Интерфейсам (выслана в Тимс) классы Пингвин, Слон, Утка.

#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int kg;
public:
    Animal() = default;
    Animal(string n, int k)
    {
        name = n;
        kg = k;
    }
    virtual void Print() = 0;
};

struct IAnimal//интерфейс в стиле С++
{
    virtual void Eat() = 0;
    virtual void Move() = 0;
};

struct IBird
{
    virtual void Fly() = 0;
};

struct ISwim
{
    virtual void Swim() = 0;
};

class Cat :public Animal, public IAnimal
{
    string color;
public:
    Cat(string n, int k, string c) :Animal(n, k)
    {
        color = c;
    }
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
        cout << "Color: " << color << endl;
    }
    //реализация интерфейса
    void Eat()
    {
        cout << "Cat eats\n";
    }
    void Move()
    {
        cout << "Cat moves\n";
    }
};

class Parrot :public Animal, public IAnimal, public IBird
{
public:
    Parrot(string n, int k):Animal(n,k){}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    //реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Parrot eats\n";
    }
    void Move() 
    {
        cout << "Parrot moves\n";
    }
    //реализация интерфейса IBird
    void Fly()
    {
        cout << "Parrot flies\n";
    }
};

class Penguin :public Animal, public IAnimal, public ISwim
{
public:
    Penguin(string n, int k):Animal(n,k){}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    //реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Penguin eats\n";
    }
    void Move()
    {
        cout << "Penguin moves\n";
    }
    //реализация интерфейса ISwim
    void Swim()
    {
        cout << "Penguin swim\n";
    }
};

class Elephant :public Animal, public IAnimal
{
public:
    Elephant(string n, int k):Animal(n,k){}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    //реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Elephant eats\n";
    }
    void Move()
    {
        cout << "Elephant moves\n";
    }
};

class Duck :public Animal, public IAnimal, public IBird, public ISwim
{
public:
    Duck(string n, int k):Animal(n,k){}
    void Print()
    {
        cout << "Name: " << name << endl;
        cout << "Kg: " << kg << endl;
    }
    //реализация интерфейса IAnimal
    void Eat()
    {
        cout << "Duck eats\n";
    }
    void Move()
    {
        cout << "Duck moves\n";
    }
    //реализация интерфейса IBird
    void Fly()
    {
        cout << "Duck flies\n";
    }
    //реализация интерфейса ISwim
    void Swim()
    {
        cout << "Duck swim\n";
    }
};

int main()
{
    cout << "Cat\n";
    IAnimal* ref = new Cat("Cat", 3, "white");
    ref->Eat();
    ref->Move();

    cout << "\nParrot\n";
    Parrot* parrot = new Parrot("Ara", 2);
    ref = parrot;
    ref->Eat();
    ref->Move();

    IBird* fly = parrot;
    fly->Fly();
    
    cout << "\nPenguin\n";
    Penguin* penguin = new Penguin("Ryko", 100);
    ref = penguin;
    ref->Eat();
    ref->Move();
    
    ISwim* swim = penguin;
    swim->Swim();

    cout << "\nElephant\n";
    Elephant* elephant = new Elephant("Dambo", 7000);
    ref = elephant;
    ref->Eat();
    ref->Move();

    cout << "\nDuck\n";
    Duck* duck = new Duck("Donald", 3);
    ref = duck;
    ref->Eat();
    ref->Move();
    fly = duck;
    fly->Fly();
    swim = duck;
    swim->Swim();
    cout << endl;

}
