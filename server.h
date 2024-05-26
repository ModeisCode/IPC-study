#include "common.h"

class Server {

private:
    Admin admin;
    ServerInfo sInfo;
    SecurityPolicy sPolicy;
    ServerHealth sHealth;

    // helper print functions
    void printServerInfo();
    void printSecurityPolicyInfo();
    void printAdminInfo();

    // checkers functions
    void checkSecurityManager();
    void checkPasswordManager();
    void checkServer();
    void checkLoadBalancer();
    void checkTime();
    bool checkAdmin();

    // load from file
    int loadAdmin();

    // signup constraints checker functions


    

public:
    Server() {


    }
    int initInfo();
    int start();

    ~Server() {}
};