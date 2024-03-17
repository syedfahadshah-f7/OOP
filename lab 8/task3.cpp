#include <iostream>
using namespace std;
class Position
{
    int x, y, z;

public:
    Position(int x, int y, int z) : x(x), y(y), z(z) {}
    void display()
    {
        cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
    }
};
class Health
{
    int health;

public:
    Health(int health) : health(health) {}
    void damage(int damage)
    {
        health -= damage;
    }
    void display()
    {
        cout << "Health: " << health;
    }
};
class Characters : public Position, public Health
{
    string action;

public:
    Characters(int health, int x, int y, int z, string action)
        : Position(x, y, z), Health(health)
    {
        this->action = action;
    }
    void display_coordinates()
    {
        Position ::display();
    }
    void display_action()
    {
        cout << "Actoion: " << action << endl;
    }
    void display_damage(int damage)
    {
        Health::damage(damage);
        Health ::display();
    }
};
int main()
{
    Characters obj(100, 45, 54, 2, "Spawn Giants");
    obj.display_coordinates();
    obj.display_action();
    obj.display_damage(78);

    return 0;
}
