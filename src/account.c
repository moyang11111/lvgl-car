#include "account.h"
#include <string.h>
#include <stdio.h>

#define ACCOUNT_MAX_LEN  32

static char saved_username[ACCOUNT_MAX_LEN] = {0};
static char saved_password[ACCOUNT_MAX_LEN] = {0};

int account_register(const char *username, const char *password)
{
    if (!username || !password || strlen(username) == 0 || strlen(password) == 0) {
        return -1;
    }

    strncpy(saved_username, username, ACCOUNT_MAX_LEN - 1);
    strncpy(saved_password, password, ACCOUNT_MAX_LEN - 1);
    saved_username[ACCOUNT_MAX_LEN - 1] = '\0';
    saved_password[ACCOUNT_MAX_LEN - 1] = '\0';

    return 0;
}

int account_login(const char *username, const char *password)
{
    if (!username || !password) {
        return -1;
    }

    if (strlen(saved_username) == 0) {
        return -1;  // 还没注册
    }

    if (strcmp(username, saved_username) == 0 &&
        strcmp(password, saved_password) == 0) {
        return 0;
    }

    return -1;
}
