#include <stdio.h>
#include "trvl_element.h"
#include "trvl_database.h"

#define FILEPATH    "travelData.txt"
#define N_COUNTRY   20

void printAllData(void)
{
    int i;
    void *trvlInfo;
    
    printf("Printing all the information.....\n\n");  // 잘 보기  
    for (i=0;i<trvldb_len();i++) //trvldb_len은 저장된 정보의 개수  
    {
        trvlInfo = trvldb_getData(i); //구조체를 가르킴  
        printf("--------------------------------------------------\n");
        printf("%i:\tDate : %i.%i.%i, Country : %s, City : %s\n", i,
                                                                trvlele_getDateYear(trvlInfo),
                                                                trvlele_getDateMonth(trvlInfo),
                                                                trvlele_getDateDay(trvlInfo),
                                                                trvlele_getCountryName(trvlele_getCountry(trvlInfo)),
                                                                trvlele_getCityName(trvlInfo));
        
        printf("\tBudget : %i, Consumed : %i\n",                trvlele_getBudget(trvlInfo),
                                                                trvlele_getConsumed(trvlInfo));
    }
    printf("--------------------------------------------------\n");
}

void saveData(void)
{
    FILE* fp;
    void *trvlInfo;
    int i;
    
    fp = fopen(FILEPATH, "w");
    if (fp == NULL)
    {
        printf("WARNING! failed to open data file!!\n");
        return;
    }
    else
    {   
        if(trvldb_len() <= 0)
        return;
        
        else
        {
        	i = trvldb_len() - 1;
    	    trvlInfo = trvldb_getData(i);
    	
    	    fprintf(fp,"%i %s %i %i %i %i %i\n",trvlele_getCountry(trvlInfo),
			                                    trvlele_getCityName(trvlInfo),
												trvlele_getDateYear(trvlInfo),
												trvlele_getDateMonth(trvlInfo),
												trvlele_getDateDay(trvlInfo),
												trvlele_getBudget(trvlInfo),
												trvlele_getConsumed(trvlInfo));
		}
    	
		//fprintf를 사용하여 만든 데이터 집어넣기  
	}
    //ToCode : export information to the file pointer fp  

    fclose(fp);
}

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    int rd_country, rd_year, rd_month, rd_day, rd_budget, rd_consumed;
    char rd_city[100];
    void *trvlInfo;
    void *textInfo;
    int exit_flag = 0;
    int i;
    int select;
    int item;
    int accum;
    void *addInfo;
    int choose; // 각 나라의 부여된 특정한 정수를 고를때
	int sumcons; //총 소비  
	int balance; //총 예산 - 총 소비 
    int wt_cityname, wt_year, wt_month, wt_day, wt_budget, wt_consumed; 
    
    fp = fopen(FILEPATH, "r");
    if (fp == NULL)
    {
        printf("WARNING! failed to open data file. start with empty data...\n");
    }
    else
    {
        printf("Reading the travel data from the file... \n");
        
        //ToCode : read from file pointer and add to database(Hint : use return value of the fscanf function
        while (fscanf(fp, "%i", &rd_consumed)!=EOF)
        {
        	fscanf(fp,"%i %s %i %i %i %i %i", &rd_country,
			                                  &rd_city,
											  &rd_year,
											  &rd_month,
											  &rd_day,
											  &rd_budget,
											  &rd_consumed);
			
        	textInfo = trvlele_genElement(rd_country, rd_city, rd_year, rd_month, rd_day, rd_budget, rd_consumed);
            //make an element (structure instance)
            trvldb_addTail(textInfo);
            
            break;
            //add to the database  
        }
        
        fclose(fp);
    }
    
    
    do {
        printf("=============================\n");
        printf("0.Print all travel data\n");
        printf("1.Add a travel data\n");
        printf("2.Delete a travel data\n");
        printf("3.Print travel plan at a glance\n");
        printf("4.Calculate total budget\n");
        printf("5.Calculate total balancing\n");
        printf("6.Exit\n");
        printf("=============================\nSelect A Menu:");
        scanf("%d",&select);
        fflush(stdin); //always use this after scanf for flushing out garbage
        
        switch(select)
        {
            case 0:
                printAllData();
                
                break;
            case 1:
                printf("Adding a travel data....\n");
                
                for(i=0;i<N_COUNTRY;i++) //0-19까지의 숫자와 나라를 출력 
				{
					printf("%i. %s\n",i,trvlele_getCountryName(i)); 
				} 
                
                printf("Choose the number of county to input:");
                scanf("%i",&choose);
                fflush(stdin);
                
                printf("City:");
                scanf("%s",&wt_cityname); 
                fflush(stdin);
                
				printf("Year:");
				scanf("%i",&wt_year);
				fflush(stdin);
				
				printf("Month:");
				scanf("%i",&wt_month);
				fflush(stdin);
				
				printf("Day:");
				scanf("%i",&wt_day);
				fflush(stdin);
				
				printf("Budget:");
				scanf("%i",&wt_budget);
				fflush(stdin);
				
				printf("Consumed:");
				scanf("%i",&wt_consumed);
				fflush(stdin);
				//추가할 내용 scanf로 받아오기 
            
                addInfo = trvlele_genElement(choose, wt_cityname, wt_year, wt_month, wt_day, wt_budget, wt_consumed);
                
                //ToCode : make an element (structure instance)
                if (addInfo != NULL)
                {
                	trvldb_addTail(addInfo); //database에 정보 넣기  
                    printf("Correctly saved!!\n");
                }
                else
                {
                    printf("Failed to save!\n");
                }
                break;
                
            case 2:
                if (trvldb_len() > 0)
                {
                    printAllData();
                    printf("Choose one to delete:");
                    scanf("%d",&item);
                    fflush(stdin);
                    
                    if(item<0 || item>trvldb_len())
                    {
                    	 printf("index is wrong!!"); //선택 숫자가 잘못되었을 때  
                    	 break;
					}
                   
                    else
                    {
                    	if (trvldb_deleteData(item) == 0)
                        {
                    	   trvldb_deleteData(item);
                           printf("Succeeded to delete %i!!\n", item);
                        }
                        else
                        {
                           printf("Failed to delete %i!!\n", item);
                        }
					}
                }
                else
                {
                    printf("There is no data to delete!!!\n");
                }
                
                break;
                
            case 3:
                printf("\n--------------------------------------------------\n");
                for (i=0;i<trvldb_len();i++)
                {
                	trvlInfo = trvldb_getData(i);
                	printf("%i.%i.%i|%s(%s) -> ",
					                            trvlele_getDateYear(trvlInfo),
					                            trvlele_getDateMonth(trvlInfo),
					                            trvlele_getDateDay(trvlInfo),
					                            trvlele_getCityName(trvlInfo),
					                            trvlele_getCountryName(trvlele_getCountry(trvlInfo))); 
                    //ToCode : print i'th travel data in abstract ( date|city(country)-> )
                    
                }
                printf("\n--------------------------------------------------\n\n");
                break;
                
            case 4:
                printf("\n Calculating the total budget....\n");
                for (i=0;i<trvldb_len();i++)
                {
                	trvlInfo = trvldb_getData(i);
                	accum = accum + trvlele_getBudget(trvlInfo);
				}
                
                //ToCode : calculate sum of budget


                printf("Total budget is %i!\n\n", accum);
                break;
                
            case 5:
                printf("\nCalculating the total balance....\n");
                for(i=0;i<trvldb_len();i++)
                {
                	trvlInfo = trvldb_getData(i);
                	accum = accum + trvlele_getBudget(trvlInfo);
                	sumcons = sumcons + trvlele_getConsumed(trvlInfo);
				}
				
				balance = accum - sumcons;
                //ToCode : calculate sum of budget - consumed
                printf("Total balance is %i! ^-^\n\n",balance);
                //print
                break;
            
            case 6:
                printf("\exiting.. bye bye.\n");
                exit_flag = 1;
                
                break;
            default:
                printf("wrong selection! (%i), select again...\n", select);
                break;
        }
        
        saveData(); //받은 데이터들을 여행일지에 저장  
    } while(exit_flag == 0);
    
    return 0;
}
