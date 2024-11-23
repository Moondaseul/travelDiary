#ifndef trvl_database_h
#define trvl_database_h


int trvldb_addTail(void* obj);          //add data to tail (database에 넣는다) , 구조체 메모리가 들어감(매개변수) 
int trvldb_deleteData(int index);       //delete data (정보를 삭제한다)
int trvldb_len(void);                   //get database length (database에 몇개의 정보가 있는지)
void* trvldb_getData(int index);        //get index'th data (정보를 가져옴)

#endif /* trvl_database_h */
