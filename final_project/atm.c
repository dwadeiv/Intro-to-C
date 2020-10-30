#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array.h"  
#include "bank.h"      

int admin_menu(array *a) {
  printf("\nWelcome Please Select an Option with the corresponding number. \n");
  printf("1. Add Customer \n2. Delete Customer \n3. Logout\n");
  printf("Enter your selection: ");
  int choice;
  size_t indexUser = -1;
  char *p, s[100];
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uese fgets along with strol. 
					  I found that I can use a similar format for all of the code. */
        choice = strtol(s, &p, 10);
	//double_choice = strold(s, &p);
	//lonng_int choice = stroll(s,&p,25);
        if (p == s || *p != '\n') {
            printf("\nPlease enter an integer: ");
        } else break;
    }
 
    if(choice < 1 || 3 < choice) return -1;
    else {
      if(choice == 1) {
	newUser(a);
	return 1;
      }
      else if(choice == 2) {
	char userName[50];
	int rv;
	printf("Enter the Username of the user you would like to delete: ");
        fgets(userName,50,stdin);
	rv  = checkUsername(a, userName, &indexUser);
	if(rv != 1){
	  printf("The username you entered does not exist in the system\n");
	  return 1;
	}
	else if(rv == 1){
	  userDelete(a, indexUser);
	  return 1;
	}
      }
      else if(choice == 3) {
	return 0;
      }
    }
  
  return -2;
}

int customer_menu(array *a, size_t indexUser) {
  printf("\nWelcome Please Select an Option with the corresponding number. \n");
  printf("1. Cash Deposit \n2. Cash Withdrawal \n3. View customer information \n4. Edit customer information \n5. Cash Transfer \n6. Log out\n");
  printf("Enter your selection: ");
  int err, choice;
  char *p, s[100];
  while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					  userKeine Lust on stack overflow. It uses fgets along with strol. 
					  I found that I can use a similar format for all of the code. */
    choice = strtol(s, &p, 10);
    if (p == s || *p != '\n') {
      printf("\nPlease enter an integer: ");
    } else break;
  }
  

  if(choice < 1 || 6 < choice) return -1;
  else {
    if(choice == 1) {
      double amount;
      printf("Please enter the amount of money you would like to deposit: $ ");
      err = scanf("%lf", &amount);
      if(err == -1) return -1;
      userBalancePut(a,indexUser,amount);
      return 1;
    }
    else if(choice == 2) {
      userBalanceGet(a, indexUser);
      return 1;
    }
    else if(choice == 3) {
      printUserInfo(a, indexUser);
      return 1;
    }
    else if(choice == 4) {
      editUser(a,indexUser);
      return 1;
    }
    else if(choice == 5) {
      size_t indexUser2 = -1;
      char userName[50];
      int rv;
      printf("Enter the username of the account you want to transfer the money to\n");
      printf("Enter the username: ");
      fgets(userName,50,stdin);
      rv = checkUsername(a, userName, &indexUser2);
      if(rv != 1){
	printf("Invalid user name\n");
	return 1;
      }
      else if(rv == 1){
	int rv2;
	printf("Enter the account password you want to transfer to: ");
	int password;
	char *p, s[100];
	while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
						userKeine Lust on stack overflow. It uese fgets along with strol. 
						I found that I can use a similar format for all of the code. */
	  password = strtol(s, &p, 10);
	  if (p == s || *p != '\n') {
	    printf("\nPlease enter an integer: ");
	  } else break;
	}
	rv2 = checkPassword(a, password,indexUser2);
	if(rv2 != 1){
	  printf("The password you entered was not correct\n");
	  return 1;
	}
	else if(rv2 == 1){
	  printf("Enter the amount of money you would like to transfer to account 2\n");
	  printf("$ ");
	  }	    
	double amount;
	while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
						userKeine Lust on stack overflow. It uese fgets along with strol. 
						I found that I can use a similar format for all of the code. */
	  amount = strtod(s, &p);
	  if (p == s || *p != '\n') {
	    printf("\nPlease enter an integer: ");
	  } else break;
	}
	cashTransfer(a, indexUser, indexUser2, amount);
	return 1;
	      
      }
    }
    else if(choice == 6) {
      return 0;
    }
  }

  return -1;
}

int adminPass(void){
  
  int password = 8;
  
  printf("Please enter the admin password or enter 0 to go back to the menu\n");
  char *p, s[100];
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
  if(password == 0) return 0;
  else if(password == 1234) return 1;
  else{
    adminPass();
  }
  return -2;
}

int logInUser(array * a, size_t *indexUser){
  char username[50];
  int err;
  printf("Hi! Please Enter your user name: ");
  fgets(username,50,stdin);
  err = checkUsername(a, username, indexUser);
  return err;
}

int StartUp(array *users){
  int mode = 8;
  int err, succ, password, choice, user;
  size_t indexUser;
  while(mode != 1 || mode != 2 || mode != 3){
    printf("\n\n\nWelcome to the ATM Terminal Program \n\n");
    printf("Choose an option by selecting the correspondinng nnumber from the following list:\n");
    printf("1. Admin Mode \n");
    printf("2. User Mode\n");
    printf("3. Shutdown ATM\n\n");
    printf("Enter your selection: ");
    char *p, s[100];
    while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
					    userKeine Lust on stack overflow. It uese fgets along with strol. 
					    I found that I can use a similar format for all of the code. */
      mode = strtol(s, &p, 10);
      //double_choice = strold(s, &p);
      //lonng_int choice = stroll(s,&p,25);
      if (p == s || *p != '\n') {
	printf("\nPlease enter an integer: ");
      } else break;
    }
    if(mode == 1) {
      err = adminPass();
      if(err == 0) {
	StartUp(users);
	return 0;
      }
      else if(err == 1){
	choice = admin_menu(users);
	if(choice == 1){
	  while(choice == 1) {
	    choice = admin_menu(users);
	  }
	}
	if(choice == 0) {
	  StartUp(users);
	  return 0;
	}
      }
    }
    else if(mode == 2) {
      user = logInUser(users, &indexUser);
      if(user == 0) {
	StartUp(users);
	return -1;
      }
      else if(user == 1) {
	printf("Please enter your password: ");
	char *p, s[100];
	while (fgets(s, sizeof(s), stdin)) {  /*This is a solution to only scan integers found from 
						userKeine Lust on stack overflow. It uese fgets along with strol. 
						I found that I can use a similar format for all of the code. */
	  password  = strtol(s, &p, 10);
	  //double_choice = strold(s, &p);
	  //lonng_int choice = stroll(s,&p,25);
	  if (p == s || *p != '\n') {
	    printf("\nPassword must be strictly numbers");
	    printf("\nPlease enter an integer: ");
	  } else break;
	}
	succ = checkPassword(users, password, indexUser);
	if(succ == 1) {
	  choice = customer_menu(users, indexUser);
	  if(choice == 1){
	    while(choice == 1) {
	      choice = customer_menu(users, indexUser);
	    }
	  }
	  if(choice == 0) {
	    StartUp(users);
	    return 0;
	  }
	}
      }
    }
    if(mode == 3) {
      return 0;
    }
  }
  printf("Congrats you've entered the 5th dimension");
  return -1;
}

int main(void){
  array * users = newArray();
  //File *file_pointer;
  //file_pointer = fopen
  StartUp(users);
  deleteArray(users);
  return 0; 
}

 
  
      
    
    
  
   
          
  
      
  
  
  
