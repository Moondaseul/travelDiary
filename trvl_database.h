#ifndef trvl_database_h
#define trvl_database_h


int trvldb_addTail(void* obj);          //add data to tail (database�� �ִ´�) , ����ü �޸𸮰� ��(�Ű�����) 
int trvldb_deleteData(int index);       //delete data (������ �����Ѵ�)
int trvldb_len(void);                   //get database length (database�� ��� ������ �ִ���)
void* trvldb_getData(int index);        //get index'th data (������ ������)

#endif /* trvl_database_h */
