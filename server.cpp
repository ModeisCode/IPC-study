#include "server.h"

int Server::initInfo(PasswordManager*** pManager) {
    printf("Welcome to IPC server world.\n");
    printf("----------------------------\n");
    
    Password p;

    printf("IpAddress:");
    scanf("%s" , sInfo.address);
    br
    printf("Port:");
    scanf("%d" , sInfo.PORT);
    br

    if (!checkAdmin()) {
        printf("AdminName:");
        scanf("%s" , admin.name);
        br
        printf("Password:");
        scanf("%s" , p.password);
        br
        printf("SecurityLevel:");
        scanf("%d" , sInfo.securityLevel);
    }
    else {
        loadAdmin();
    }

    sPolicy.maxClientAmountPerIpAddress = 2;
    sPolicy.maxClientCount = 5;
    sPolicy.maxMessageSize = 128;
    sPolicy.pManager = (PasswordManager*) pManager;
    sPolicy.securityLevel = high;



}

bool Server::checkAdmin() {
    return true;
}