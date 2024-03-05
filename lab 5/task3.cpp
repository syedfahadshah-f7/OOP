#include<iostream>
using namespace std;
class validate_string{
    string str;
    public:
    validate_string(){}
   validate_string(string str){
        this->str = str;
   }
    bool check_string()const{
        for(int i =0;str[i] != '\0';i++){
            if(str[i]>=65 && str[i]<=90 || str[i]>=97 && str[i]<=122){
                continue;
            }
            return false;
        }
        return true;
    }
};
int main(){
    validate_string v1,v2;
    v1 = validate_string("FAHAD");
    v2 =  validate_string("FAHAD123");
    cout<<(v1.check_string()? "valid": "invalid")<<endl;
    cout<<(v2.check_string() ? "valid" : "invalid")<<endl;
    return 0;
}
