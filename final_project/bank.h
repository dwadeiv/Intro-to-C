#ifndef BANK_H_
#define BANK_H_

#include "array.h"

typedef struct _user user;

/* This function asks the user to type all the information and then
 * and then call the function arrayPushBack to add to add this information
 * in the array. */
int newUser(array *a);
/* This function has to print all the information related to the user
 * with index indexUser. */
int printUserInfo(array *a, size_t indexUser);
/* This function has to set the value of *indexUser by the index of the
 * the user in the array whose information matches the given username
 * and password. */
int checkPassword(array *a, int password, size_t indexUser);
/* This function has to set the value of *indexUser by the index of the
 * user in the array whose information matches the guven username.
 * This function will be useful when you want to make a cash transfer */
int checkUsername(array *a, char *usernameIn, size_t *indexUser) ;
/* Get the balance of the user with index indexUser and put it where
 * balance is pointing to. */
int userBalanceGet(array *a, size_t indexUser);
/* Add to the balance of the user  with index indexUser the amount.
 * Note that amount can be positive or negative value. Hence, this
 * function can be used to add or deposit money. */
int userBalancePut(array *a, size_t indexUser, double amount);
/* This function will ask the user with index indexUser in the array
 * to re-input all the information. */
int editUser(array *a, size_t indexUser);
/* This function has to reduce the balance of the user with index indexUser1
 * by amount and add to the balance of the user with index indexUser2 the 
 * amount. */
int cashTransfer(array *a, size_t indexUser1, size_t indexUser2 , double amount);
/* This function has to delete the user with index indexUser from the array. */
int userDelete(array *a, size_t indexUser);

#endif



