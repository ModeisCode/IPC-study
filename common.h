#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <queue>
#include <sys/shm.h>
#include <pthread.h>
#include <queue>
#include <ctime>
#include <string.h>
#include <utility>
#include <sys/socket.h>
#include <netinet/in.h>

#define br printf("\n");

enum Role {
    user = 1,
    logManager = 2,
    securityManager = 3,
    admin = 4,
    nonUser = 5,
};

enum State {
    active = 1,
    ready = 2,
    close = 3,
    fail = -1,
    terminated = -2
};

enum SecurityLevel {
    test = 10,
    medium = 20,
    high = 30
};

typedef struct Password {
    char* password;
    int passwordPower;
}Password;

typedef struct PasswordManager {
    Password** password;
} PasswordManager;

typedef struct SecurityPolicy {
    SecurityLevel securityLevel;
    short maxClientCount;
    int maxMessageSize;
    short maxClientAmountPerIpAddress;
    PasswordManager* pManager;
}SecurityPolicy;

typedef struct Message {
    int queueID;
    int messagePriority;
    char* msg;
}Message;

typedef struct Address {
    char* IpAddress;
    char* macAddress;
} Address;

typedef struct User {
    char* name;
    Role role;
}User;

typedef User Admin;

typedef struct ServerInfo {
    int PORT;
    SecurityLevel securityLevel;
    Address address;
} ServerInfo;

typedef struct ClientInfo {
    int clientID;
    char* name;
    Address address;
} ClientInfo ;

typedef struct ServerHealth {
    State server;
    State sPolicyState;
    State pManagerState;
    State lBalancer;
    State time;
} ServerHealth;