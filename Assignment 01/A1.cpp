#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class PET{
    string health_status;
    int hunger_level;
    int happiness_level;
    string special_skills[2];

    public:
    PET(string health, int hunger, int happy, string skill1,string skill2):happiness_level(happy),hunger_level(hunger)
    ,health_status(health) {
        special_skills[0]= skill1;
        special_skills[1]= skill2;
    }
    void display_pet_details(){
        if(hunger_level <5){
            happiness_level--;
        }else{
            happiness_level += hunger_level-5;
        }
        cout<<"Happiness Level: "<<happiness_level<<endl
        << "Hunger level: "<<hunger_level<<endl
        <<"Health Staus: "<<health_status<<endl
        <<"Special Skills: "<< special_skills[0]<<" , "<<special_skills[1];

    }
    void update_happiness(int update){
        happiness_level = update;
    }
    void update_health(string update){
        health_status = update;
    }
    void update_hunger(int update){
        hunger_level = update;
    }
};
class ADOBT{
    string adopter_name;
    int adopter_num;
     vector<PET> adopt_pet_records;
    vector<string> adopter_list;
     int pet_count = 0;
    public:
    ADOBT(string name,int num):adopter_name (name),adopter_num (num){}
    void adopt_pet(PET pet, string name){
        if(pet_count >5){
            cout<<"ALL PETS ARE ADOPTED!!!! "<<endl;
        }else{
            adopt_pet_records.push_back(pet);
            adopter_list.push_back(name);
            pet_count++;
            
            cout<<"PET IS ADOPTED"<<endl;
        }
    }
    void return_pet(string name) {
        int index;
        for(int i=0;i<pet_count;i++){
            if(name == adopter_list[i]){
                index =i;
            }
        }
        adopt_pet_records.erase(adopt_pet_records.begin() + index);
        pet_count--;
        cout<<"PET SUCCEFULLY RETURNED!!!! "<<endl;
    }
    void display_adopted_pets(string adopter){
        for(int i=0;i<=pet_count;i++){
            if(adopter == adopter_list[i]){
                adopt_pet_records[i].display_pet_details();
            }
        }
    }
    
};
int main(){
    PET pet1("Healthy",6,7,"Fight","JUmp"),
    pet2("Sick",2,4,"swim","bark");
    ADOBT adopter1("FAHAD",31639), adopter2("HAMMAD",28802);
    adopter1.adopt_pet(pet1,"FAHAD");
    adopter2.adopt_pet(pet2,"HAMMAD");
    adopter1.return_pet("HAMMAD");
    adopter1.display_adopted_pets("FAHAD");

    return 0;
}
