#ifndef ACC_FUNC_H_
#define ACC_FUNC_H_

#include "mainLogic.h" 

#define USER_DB_PATH "./db_user/name_pass.csv"
#define TEMP_USER_DB_PATH "./db_user/temp.csv"

int login();  
void addAcc();
void delAcc();
void accPassword();
void viewAcc();


#endif //LOGIN_FUNC_H_