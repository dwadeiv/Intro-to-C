#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "bank.h"
#include "array.h"

struct _user {
  char name[50];
  char address[50];
  int age;
  long int phone_num;
  double balance;
  char username[50];
  int password;
  double account_num;
};

int newUser(array *a) {
  if (!a) return -1;
  int err, age, phone_num, password;
  struct _user * newUser = malloc(sizeof(struct _user));
  printf("Please enter your name.  ");
  fgets((newUser->name),50,stdin);
  printf("Please enter your address.  ");
  fgets(newUser->address,50,stdin) ;
  printf("Please enter your age.  ");
  char *p, s[100];
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    age = strtol(s, &p, 10);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  newUser->age = age;
  printf("Please enter your phone number.  ");
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    phone_num = strtoll(s, &p, 25);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  newUser->phone_num = phone_num;
  printf("Please enter your username.  ");
  fgets(newUser->username,50,stdin);
  printf("Please enter your password.  ");
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    password = strtol(s, &p, 10);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  newUser->password = password;
  newUser->balance = 0;
  newUser->account_num = (newUser->phone_num*7)/6;
  err = arrayPushBack(a,newUser);
  if (err == -1){
    return -1;
  }
  return 0;
}


int printUserInfo(array *a, size_t indexUser){
  if (!a) return -1;
  void * e;
  int err;
  struct _user * newUser;
  err = arrayGet(a,indexUser,&e);
  if(err == -1) return -1;
  newUser = (struct _user *)e;
  printf("Name: %s \n",  newUser-> name);
  printf("Address: %s \n", newUser-> address);
  printf("Age: %d \n",newUser-> age);
  printf("\nPhone Number: %ld \n",newUser-> phone_num);
  printf("\nBalance: $%f \n",newUser-> balance);
  printf("\nUsername: %s \n",newUser-> username);
  printf("\nAccount Number: %f \n",newUser-> account_num);
  return 0;
}

int checkPassword(array *a, int password, size_t indexUser) {
  if (!a) return -1;
  int err;
  void * e;
  int succ = -1;
  struct _user * newUser;
  err = arrayGet(a,indexUser,&e);
  if(err == -1) return -1;
  newUser = (struct _user *)e;
  if(password == newUser->password){
    succ = 1;
    return succ;
  }
  else {
    succ = 0;
    return 0;
  }
}
int checkUsername(array *a, char *usernameIn, size_t *indexUser) {
  if(!a || ! usernameIn || !indexUser) return -1;
  size_t max = 0;
  int err;
  int succ = -1;
  size_t i;
  err = arrayNum(a, &max);
  if (err == -1){
    return -1;
  }
  for(i= 0; i< max; i++ ){
    void * e;
    struct _user * cUser;
    err = arrayGet(a,i,&e);
    if (err == -1){
      return -1;
    }
    cUser = (struct _user *)e;
    if(strcmp(usernameIn, cUser->username) == 0){
      succ = 1;
      *indexUser = i;
      break;
    }
  }
  if(succ == 1) return 1;
  else{
    return 0;
  }
}

int userBalanceGet(array *a, size_t indexUser) {
  if (!a) return -1;
  void * e;
  int err;
  double withdrawl = 0;
  struct _user * cUser;
  err = arrayGet(a,indexUser,&e);
  if (err == -1){
    return -1;
  }
  cUser = (struct _user *)e;
  printf("Your current balance is $ %lf",cUser->balance);
  printf("\nEnter the amount that you would like to withdrawl: $");
  char *p, s[100];
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    withdrawl = strtod(s, &p);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  cUser->balance = cUser->balance - withdrawl;
  printf("Your new balance is $ %lf", cUser->balance);
  err = arrayPut(a,indexUser,(void *)cUser);
  if (err == -1){
    return -1;
  }
  return 0;
}

int userBalancePut(array *a, size_t indexUser, double amount) {
  if (!a) return -1;
  int err;
  void * e;
  struct _user * cUser;
  err = arrayGet(a,indexUser,&e);
  if (err == -1){
    return -1;
  }
  cUser = (struct _user *)e;
  cUser->balance = cUser->balance + amount;
  err = arrayPut(a,indexUser,(void *)cUser);
  if (err == -1){
    return -1;
  }
  return 0;
}

int editUser(array *a, size_t indexUser) {
  if (!a) return -1;
  void * e;
  int err, age, phone_num, password;
  struct _user * newUser;
  err = arrayGet(a,indexUser,&e);
  if (err == -1){
    return -1;
  }
  newUser = (struct _user *)e;
  printf("Please enter your name.  ");
  fgets(newUser->name,50,stdin);
  printf("Please enter your address.  ");
  fgets(newUser->address,50,stdin);
  printf("Please enter your age.  ");
  char *p, s[100];
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    age = strtol(s, &p, 10);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  newUser->age =  age;
  printf("Please enter your phone number.  ");
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    phone_num = strtoll(s, &p, 25);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  newUser->phone_num = phone_num;
  printf("Please enter your username.  ");
  fgets(newUser->username,50,stdin);
  printf("Please enter your password.  ");
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
		//testttttt			  I found that I can use a similar format for all of the code. */
    password = strtol(s, &p, 10);
    //double_choice = strold(s, &p);
    //lonng_int choice = stroll(s,&p,25);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  newUser->password = password;
  err = arrayPut(a,indexUser,(void *)newUser);
  if (err == -1){
    return -1;
  }
  return 0;
}

int cashTransfer(array *a, size_t indexUser1, size_t indexUser2 , double amount) {
  if (!a){     /*verify that point to array a exists*/
    return -1;
  }
  int err;
  void * e1;  /*create the pointer to edit the first useres info*/
  struct _user * cUser1;
  err = arrayGet(a,indexUser1,&e1); /*gets the struct from the array and stores it in e*/
  if (err == -1){
    return -1;
  }
  cUser1 = (struct _user *)e1;
  cUser1->balance = cUser1->balance - amount; /*remove the desired amount from user 1*/
  err = arrayPut(a,indexUser1,(void *)cUser1);
  if (err == -1){
    return -1;
  }
  void * e2;
  struct _user * cUser2;
  err = arrayGet(a,indexUser2,&e2); /* gets the seconds users account*/
  if (err == -1){
    return -1;
  }
  cUser2 = (struct _user *)e2;
  cUser2->balance = cUser2->balance + amount;/*adds the amount taken from user 1 to user 2*/
  err = arrayPut(a,indexUser2,(void *)cUser2);
  if (err == -1){
    return -1;
  }
  return 0;
}

int userDelete(array *a, size_t indexUser) {
  size_t cnt = 0;
  size_t i;
  int err;
  if(!a) return -1;
  arrayNum(a,&cnt);
  for(i = indexUser; i<cnt; i++){
    void * e1;
    struct _user * user1;
    err = arrayGet(a,i,&e1);
    if(err == -1) return -1;
    user1 = (struct _user *)e1;
    void * e2;
    struct _user * user2;
    err = arrayGet(a,i+1,&e2);
    if(err == -1) return -1;
    user2 = (struct _user *)e2;
    strcpy(user1->name,user2->name);
    strcpy(user1->address,user2->address);
    user1->age = user2 -> age;
    user1->phone_num = user2->phone_num;
    user1->balance = user2->balance;
    strcpy(user1->username,user2->username);
    user1->password = user2->password;
    user1->account_num = user2->account_num;
  }
  resizeArray(a, cnt-1);
  return 0;
}


