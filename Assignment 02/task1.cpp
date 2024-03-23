#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Security_Tool {
protected:
    string security_level;
    float cost;
    int no_devices;

public:
    Security_Tool(float cost, int devices, string level) {
        this->no_devices = devices;
        // Checking if the user enters correct cost
        if (cost > 0) {
            this->cost = cost;
        }
        else {
            cout << "Inappropriate Cost" << endl;
        }
        // Checking if the user enters the right security level
        string str[3] = { "High","Medium","Low" };
        bool check = false;
        for (int i = 0; i < 3; i++) {
            if (str[i] == level) {
                check = true;
                break;
            }
        }

        if (check) {
            this->security_level = level;
        }
        else {
            cout << "Inappropriate Security Level" << endl;
        }
    }

    virtual void perform_scan() {
        cout << "Indicating a generic Security Scan" << endl;
    }
};

class Firewall_tool : public Security_Tool {
    vector <int> ports;
    vector<string> protocols;

public:
    Firewall_tool(float cost, int devices, string level, vector<string>& protocols) : Security_Tool(cost, devices, level) {
        // Checking if the set of rules is valid
        string protocol_list[6] = { "HTTPS","FTP","UDP","ICMP","SSH","SNMP" };
        bool flag = true;
        for (int i = 0; i < protocols.size(); i++) {
            flag = false;
            for (int j = 0; j < 6 ; j++) {
                if (protocol_list[j] == protocols[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            this->protocols = protocols;
        }
        else {
            cout << "Inappropriate Set of traffic rules" << endl;
        }
    }

    void generate_list(int id) {
        // Checking if the id number is greater than 0
        if (id <= 0) {
            cout << "Id number should be greater than 0" << endl;
        }
        else {
            for (int i = id; i <id+23; i++) {
               ports.push_back(i);
            }
        }
    }

    void perform_scan() {
        if (security_level == "High") {
            cout << "Allowing only traffic from the port and protocol list" << endl<<"PORTS"<<endl;
            for (int i = 0; i < ports.size(); i++)
            {
               cout<<ports[i]<<endl;
            }
            cout<<"Protocol List"<<endl;
            for (int i = 0; i < protocols.size(); i++)
            {
               cout<<protocols[i]<<endl;
            }
            
        }
        else if (security_level == "Medium") {
            cout << "Allowing all traffic from the port and protocol list along with the next two ports" << endl;
            for(int i = ports.size(),j=1;j<=2;j++){
                ports.push_back(i+j);
            }
             for (int i = 0; i < ports.size(); i++)
            {
                
               cout<<ports[i]<<endl;
            }
            cout<<"Protocol List"<<endl;
            for (int i = 0; i < protocols.size(); i++)
            {
               cout<<protocols[i]<<endl;
            }
        }
        else {
            cout << "Allowing all traffic from the port and protocol list along with the next five ports" << endl;
            for(int i = ports.size(),j=1;j<=5;j++){
                ports.push_back(i+j);
            }
             for (int i = 0; i < ports.size(); i++)
            {
               cout<<ports[i]<<endl;
            }
            cout<<"Protocol List"<<endl;
            for (int i = 0; i < protocols.size(); i++)
            {
               cout<<protocols[i]<<endl;
            }
            cout<<"TCP"<<endl<<"DNS"<<endl;
        }
    }
};

int main() {
    vector<string> protocols = { "FTP", "UDP", "ICMP","SSH" };
    Firewall_tool obj(1500.65, 8, "Medium", protocols);
    obj.generate_list(3);
    obj.perform_scan();
    return 0;
}
