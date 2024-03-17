#include <iostream>
using namespace std;
class Characters
{
    int health, damage;

public:
    Characters(int health, int damage) : health(health), damage(damage) {}
    void display()
    {
        cout << "Health: " << health << endl
             << "Damage: " << damage << endl;
    }
};
class Enemy : public Characters
{
public:
    Enemy(int health, int damage) : Characters(health, damage) {}
    void display()
    {
        Characters ::display();
    }
};
class Player : public Characters
{
public:
    Player(int health, int damage) : Characters(health, damage) {}
    void display()
    {
        Characters ::display();
    }
};
class Wizard : public Player
{
    int magic_power;
    string spells;

public:
    Wizard(int magic_power, string spells, int health, int damage) : Player(health, damage)
    {
        this->magic_power = magic_power;
        this->spells = spells;
    }
    void display()
    {
        Player::display();
        cout << "Magic Power: " << magic_power << endl
             << "Spells: " << spells << endl;
    }
};
int main()
{
    Wizard wizard(7, "Poison", 10, 9);
    wizard.display();
    return 0;
}
