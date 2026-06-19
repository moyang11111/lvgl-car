#ifndef ACCOUNT_H
#define ACCOUNT_H

#ifdef __cplusplus
extern "C" {
#endif

int account_register(const char *username, const char *password);
int account_login(const char *username, const char *password);

#ifdef __cplusplus
}
#endif

#endif
