#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trvl_element.h"


#define MAX_CITYNAME            100
#define MAX_DESTINATIONNAME     100
#define N_COUNTRY               20



typedef enum country {
    Korea,
    Japan,
    USA,
    Canada,
    France,
    Italy,
    England,
    Swiss,
    Germany,
    Spain,
    Netherland,
    Austria,
    Sweden,
    Vietnam,
    Thailand,
    Philippine,
    Singapore,
    Indonesia,
    Malaysia,
    Australia
} country_t;  //enum으로 여행국가 저장  

char countryName[N_COUNTRY+1][100] =
{   "Korea",
    "Japan",
    "USA",
    "Canada",
    "France",
    "Italy",
    "England",
    "Swiss",
    "Germany",
    "Spain",
    "Netherland",
    "Austria",
    "Sweden",
    "Vietnam",
    "Thailand",
    "Philippine",
    "Singapore",
    "Indonesia",
    "Malaysia",
    "Australia",
    "Unrecognized"
}; //country[5] = italy    printf("%s",country[5]) = Italy 출력함. 
    
typedef struct trvl_ele {
	country_t country;
	char city[100];
	int year;
	int month;
	int day;
	int budget;
	int consumed;
    //ToCode : define the members of the travel data
} trvl_ele_t;


void* trvlele_genElement(int country, char* city, int year, int month, int day, int budget, int consumed)
{
    trvl_ele_t* ptr = malloc(sizeof(trvl_ele_t)); //메모리를 잡고 값을 입력하라고 시킴 
	 
    if(country>=N_COUNTRY || country<0)
    {
    	printf("WARNING!! country is wrong!!(%i)",country);
    	return NULL;
    }
	else if(month > 12 || day > 31)
	{
	    printf("WARNING!! month and day are wrong!(%i, %i)",month,day);
	    return NULL; 
	}
	
    if(ptr != NULL)
    {
		ptr->country = country;
        strcpy(ptr->city, city);
        ptr->year = year;
        ptr->month = month;
        ptr->day = day;
        ptr->budget = budget;
        ptr->consumed = consumed;
	}	
    else  
    {
    	printf("WARNING!! ERROR!!");
    }
	 
    return (void*)ptr;

}


//return country name pointer from country number
char* trvlele_getCountryName(int countryNum) //문자열로 알려줘야함 
{
	return countryName[countryNum];
}

//return country number
int trvlele_getCountry(void* obj)
{
    trvl_ele_t *elem = (trvl_ele_t *)obj;
    
    return elem->country; 
}

char* trvlele_getCityName(void* obj)
{
	trvl_ele_t *elem = (trvl_ele_t *)obj;
	
	return elem->city;
}


int trvlele_getDateYear(void* obj)
{
	trvl_ele_t *elem = (trvl_ele_t *)obj;
    
    return elem->year;
}
int trvlele_getDateMonth(void* obj)
{
	trvl_ele_t *elem = (trvl_ele_t *)obj;
    
    return elem->month;
}
int trvlele_getDateDay(void* obj)
{
	trvl_ele_t *elem = (trvl_ele_t *)obj;
    
    return elem->day;
}

int trvlele_getBudget(void* obj)  //obj = trvInfo
{
    trvl_ele_t *elem = (trvl_ele_t *)obj;
    
    return elem->budget;  //get 함수 유사하게 사용하기 
}

int trvlele_getConsumed(void* obj)
{
	trvl_ele_t *elem = (trvl_ele_t *)obj;
    
    return elem->consumed;
}
