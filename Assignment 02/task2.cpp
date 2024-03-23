#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
class Enemy;
class Character;
class Player {
protected:
    int player_id, health;
    string player_name;
public:
    Player(int player_id, string name) : player_id(player_id), player_name(name) {
        this->health = 100;
    }
    void displayInfo() {
        cout << "Player ID: " << player_id << endl;
        cout << "Player Name: " << player_name << endl;
        cout << "Health: " << health << endl;
    }
};

class Weapon {
    vector<string> weapon_list;
    string weapon_used;
public:
    
    Weapon() {
        weapon_list = {"M416", "AKM", "Groza", "AUG", "MG-3"};
    }
    void Use() {
        for (const auto& weapons : weapon_list) {
            cout << weapons << " , ";
        }
        cout << endl <<endl<< "Which weapon you want to use from the list: ";
        cin >> weapon_used;
    }
    string get_weapon(){
        return weapon_used;
    }
};

class Character : public Player {
    int level, points;
    string experience;
    Weapon weapon;
    bool attack;
public:
    Character(int id, string name) : Player(id, name), level(0), points(0), experience("Beginner") {}
    void level_up(int points) {
        this->points += points;
        level++;
        if (experience == "Beginner") {
            experience = "Intermediate";
        } else if (experience == "Intermediate") {
            experience = "Advanced";
        } else if (experience == "Advanced") {
            experience = "Expert";
        }
    }
    void damage_taken(int damage) {
        health -= damage;
    }
    void PlayGame() {
        cout << "Choose weapon to attack the enemy:" << endl<<endl;
        weapon.Use();
        attack = true;
        level_up(10);
    }
    bool attack_enemy(){
        attack = false;
        return true;
    }
    void display_character_details(){
        cout<<"Character Weapon: "<<weapon.get_weapon()<<endl
        <<"Points: "<<points<<endl<<"Level: "<<level<<endl
        <<"Experience: "<<experience<<endl;
        Player ::displayInfo();
    }
};

class Enemy : public Player {
    int damage;
    Weapon weapon;
public:
    Enemy(int id, string name, int damage) : Player(id, name), damage(damage) { }
    void attack(Character &character) {
        cout << "Choose weapon to attack the character:" << endl<<endl;
        weapon.Use();
        character.damage_taken(damage);
    }
     void display_enemy_details(){
        cout<<"Enemy Weapon: "<<weapon.get_weapon()<<endl;
        Player ::displayInfo();
    }
    void damage_taken(int damage) {
        health -= damage;
    }
};

int main() {
   srand(time(0));
    Character player1(73,"Ramboo");
    Enemy enemy1(2,"LIGER",rand() % 10 + 1);

    for(int i=0;i<3;i++){
    player1.PlayGame();
    enemy1.attack(player1);
    if(player1.attack_enemy()){
        enemy1.damage_taken(5);
    }  
    cout<<"Displaying Character Details:"<<endl<<endl;
    player1.display_character_details();
    cout<<"Displaying Enemy Details:"<<endl<<endl;
    enemy1.display_enemy_details();
    cout<<"----------------------------------------------------------"<<endl;
    }
    

    return 0;
}
