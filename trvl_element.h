#ifndef trvl_element_h
#define trvl_element_h

#define N_COUNTRY               20

char* trvlele_getCountryName(int);
int trvlele_getCountry(void* obj);
char* trvlele_getCityName(void* obj);
int trvlele_getDateYear(void* obj);
int trvlele_getDateMonth(void* obj);
int trvlele_getDateDay(void* obj);
int trvlele_getBudget(void* obj);
int trvlele_getConsumed(void* obj);
void* trvlele_genElement(int country, char* city, int year, int month, int day, int budget, int consumed);

#endif /* trvl_element_h */
