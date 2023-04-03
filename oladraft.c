#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
struct statscan{
    int date;
    char geo[50];
    char dguid[50];
    char agegroup[50];
    char sex[50];
    char indicators[50];
    char characteristics[50];
    char UOM[50];
    int decimals;
    char terminate;
    char symbol;
    char status;
    double value;
    char corrdinate[50];
    char vector[50];
    int scalarID;
    char scarlarfactor[50];
    int UOM_ID;
};

struct data{
    int date;
    double value;
    char sex[50];
    char geo[50];
    char agegroup[50];
    
};

int main(void)
{
    FILE *fp = fopen("statscan_diabetes.csv", "r");
    FILE *fp2 = fopen("statscan_diabetes.csv", "r");
    char line [MAX_LINE_LENGTH];
    char line2 [MAX_LINE_LENGTH];
    char *token;
    struct statscan stats;
    struct data dataform;
    
    if(fp == NULL){
        printf(" error opening file\n");
        return 1;
    }
    
    fgets(line, MAX_LINE_LENGTH, fp);
    int row = 0;
    
    while(fgets(line, MAX_LINE_LENGTH, fp)){
        
        token = strtok(line, ",\"");
        if (token == NULL || token[0] == '\0') continue;
        stats.date = atoi(token);
        dataform.date = atoi(token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.geo, token);
        strcpy(dataform.geo, token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.dguid, token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.agegroup, token);
        strcpy(dataform.agegroup, token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.sex, token);
        strcpy(dataform.sex, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.indicators, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.characteristics, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.UOM, token);
        
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.UOM_ID = atoi(token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.scarlarfactor, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.scalarID = atoi(token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.vector, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.corrdinate, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.value = atof(token);
        dataform.value = atof(token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.status = token[0];
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.symbol = token[0];
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.terminate = token[0];
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.decimals = atoi(token);
        
        row++;
        
    }
    
    
    struct data datalist[row];
    /* int datelist[rows];
    char geolist[rows][MAX_LINE_LENGTH];
    char agegrouplist[rows][MAX_LINE_LENGTH];
    char sexlist[rows][MAX_LINE_LENGTH];
    double valuelist[rows];*/
    
    int counter = 0;
    
    while(fgets(line, MAX_LINE_LENGTH, fp2)){
        
        token = strtok(line, ",\"");
        if (token == NULL || token[0] == '\0') continue;
        stats.date = atoi(token);
        dataform.date = atoi(token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.geo, token);
        strcpy(dataform.geo, token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.dguid, token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.agegroup, token);
        strcpy(dataform.agegroup, token);
        
        token = strtok(NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.sex, token);
        strcpy(dataform.sex, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.indicators, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.characteristics, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.UOM, token);
        
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.UOM_ID = atoi(token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.scarlarfactor, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.scalarID = atoi(token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.vector, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        strcpy(stats.corrdinate, token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.value = atof(token);
        dataform.value = atof(token);
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.status = token[0];
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.symbol = token[0];
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.terminate = token[0];
        
        token = strtok (NULL, ",");
        if (token == NULL || token[0] == '\0') continue;
        stats.decimals = atoi(token);
        
        datalist[counter]= dataform;
        
        counter++;
        
    }
    
    /*for(int i = 0; i < row+1; i++){
        printf("%d" | %d | %s | %s | %.2lf\n", i+1, datalist[i].date, datalist[i].geo, datalist[i].agegroup, datalist[i].value)
    }*/
    
    double sumavg = 0, numofinstances = 0;
    double sum2015avg = 0, num2015instances = 0;
    double sum2016avg = 0, num2016instances = 0;
    double sum2017avg = 0, num2017instances = 0;
    double sum2018avg = 0, num2018instances = 0;
    double sum2019avg = 0, num2019instances = 0;
    double sum2020avg = 0, num2020instances = 0;
    double sum2021avg = 0, num2021instances = 0;
    
    
    printf("The average percentage of the population that is diagonsed with diabetes (for all years and age groups):\n");
    
    for (int i = 0; i < row + 1; i++){
        
        if(!strcmp(datalist[i].geo), "\"canada (excluding territories)\"")){
            numofinstances++;
            sumavg += datalist[i].value;
        }
        
    }
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo, "\"canada (excluding territories)\"")){
            
            if((datalist[i].date == 2015)){
                
                num2015instances++;
                sum2015avg += datalist[i].value;
                
                
        }else if ((datalist[i].date == 2016)){
            
                num2016instances++;
                sum2016avg += datalist[i].value;
                
               
            }else if ((datalist[i].date == 2017)){
                
                num2017instances++;
                sum2017avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2018)){
                
                num2018instances++;
                sum2018avg += datalist[i].value;
            
            }else if ((datalist[i].date == 2019)){
                
                num2019instances++;
                sum2019avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2020)){
                
                num2020instances++;
                sum2020avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2021)){
                
                num2021instances++;
                sum2021avg += datalist[i].value;
                
            }
        }
        
        
        
        
    }
    
    double canavg = sumavg/numofinstances;
    printf("canada ( excluding territories) Total average: %.2lf\n", canavg);
    printf("canada ( excluding territories) Yearly average\n");
    printf("2015 average: %.2lf\n", sum2015avg/num2015instances);
    printf("2016 average: %.2lf\n", sum2016avg/num2016instances);
    printf("2017 average: %.2lf\n", sum2017avg/num2017instances);
    printf("2018 average: %.2lf\n", sum2018avg/num2018instances);
    printf("2019 average: %.2lf\n", sum2015avg/num2019instances);
    printf("2020 average: %.2lf\n", sum2020avg/num2020instances);
    printf("2021 average: %.2lf\n", sum2021avg/num2021instances);
    
    
    sumavg = 0; numofinstances = 0;
    sum2015avg = 0; num2015instances = 0;
    sum2016avg = 0; num2016instances = 0;
    sum2017avg = 0; num2017instances = 0;
    sum2018avg = 0; num2018instances = 0;
    sum2019avg = 0; num2019instances = 0;
    sum2020avg = 0; num2020instances = 0;
    sum2021avg = 0; num2021instances = 0;
    
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo), "\"Quebec\"")){
            
            numofinstances++;
            sumavg += datalist[i].value;
        }
    }
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo, "\"Quebec\"")){
            
            if((datalist[i].date == 2015)){
                
                num2015instances++;
                sum2015avg += datalist[i].value;
                
                
        }else if ((datalist[i].date == 2016)){
            
                num2016instances++;
                sum2016avg += datalist[i].value;
                
               
            }else if (datalist[i].date == 2017){
                
                num2017instances++;
                sum2017avg += datalist[i].value;
                
            }else if (datalist[i].date == 2018){
                
                num2018instances++;
                sum2018avg += datalist[i].value;
            
            }else if (datalist[i].date == 2019){
                
                num2019instances++;
                sum2019avg += datalist[i].value;
                
            }else if (datalist[i].date == 2020){
                
                num2020instances++;
                sum2020avg += datalist[i].value;
                
            }else if (datalist[i].date == 2021){
                
                num2021instances++;
                sum2021avg += datalist[i].value;
                
            }
        }
        
        
    }
    
    double queavg = sumavg/numofinstances;
    printf("\n quebec Total average: %.2lf\n", queavg);
    printf("\n quebec Yearly average\n---------------\n");
    printf("2015 average: %.2lf\n", sum2015avg/num2015instances);
    printf("2016 average: %.2lf\n", sum2016avg/num2016instances);
    printf("2017 average: %.2lf\n", sum2017avg/num2017instances);
    printf("2018 average: %.2lf\n", sum2018avg/num2018instances);
    printf("2019 average: %.2lf\n", sum2015avg/num2019instances);
    printf("2020 average: %.2lf\n", sum2020avg/num2020instances);
    printf("2021 average: %.2lf\n", sum2021avg/num2021instances);
    
    sumavg = 0; numofinstances = 0;
    sum2015avg = 0; num2015instances = 0;
    sum2016avg = 0; num2016instances = 0;
    sum2017avg = 0; num2017instances = 0;
    sum2018avg = 0; num2018instances = 0;
    sum2019avg = 0; num2019instances = 0;
    sum2020avg = 0; num2020instances = 0;
    sum2021avg = 0; num2021instances = 0;
    
    
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo), "\"Ontario\"")){
            
            numofinstances++;
            sumavg += datalist[i].value;
        }
    }
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo, "\"Ontario\"")){
            
            if((datalist[i].date == 2015)){
                
                num2015instances++;
                sum2015avg += datalist[i].value;
                
                
        }else if ((datalist[i].date == 2016)){
            
                num2016instances++;
                sum2016avg += datalist[i].value;
                
               
            }else if ((datalist[i].date == 2017)){
                
                num2017instances++;
                sum2017avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2018)){
                
                num2018instances++;
                sum2018avg += datalist[i].value;
            
            }else if ((datalist[i].date == 2019)){
                
                num2019instances++;
                sum2019avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2020)){
                
                num2020instances++;
                sum2020avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2021)){
                
                num2021instances++;
                sum2021avg += datalist[i].value;
                
            }
        }
        
        
    }
    
    
    
    double ontavg = sumavg/numofinstances;
    printf("\n ontario Total average: %.2lf\n", ontavg);
    printf("\n ontario Yearly average\n----------------\n");
    printf("2015 average: %.2lf\n", sum2015avg/num2015instances);
    printf("2016 average: %.2lf\n", sum2016avg/num2016instances);
    printf("2017 average: %.2lf\n", sum2017avg/num2017instances);
    printf("2018 average: %.2lf\n", sum2018avg/num2018instances);
    printf("2019 average: %.2lf\n", sum2015avg/num2019instances);
    printf("2020 average: %.2lf\n", sum2020avg/num2020instances);
    printf("2021 average: %.2lf\n", sum2021avg/num2021instances);
    
    sumavg = 0; numofinstances = 0;
    sum2015avg = 0; num2015instances = 0;
    sum2016avg = 0; num2016instances = 0;
    sum2017avg = 0; num2017instances = 0;
    sum2018avg = 0; num2018instances = 0;
    sum2019avg = 0; num2019instances = 0;
    sum2020avg = 0; num2020instances = 0;
    sum2021avg = 0; num2021instances = 0;
    
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo), "\"Alberta\"")){
            
            numofinstances++;
            sumavg += datalist[i].value;
        }
    }
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo, "\"Alberta\"")){
            
            if((datalist[i].date == 2015)){
                
                num2015instances++;
                sum2015avg += datalist[i].value;
                
                
        }else if ((datalist[i].date == 2016)){
            
                num2016instances++;
                sum2016avg += datalist[i].value;
                
               
            }else if ((datalist[i].date == 2017)){
                
                num2017instances++;
                sum2017avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2018)){
                
                num2018instances++;
                sum2018avg += datalist[i].value;
            
            }else if ((datalist[i].date == 2019)){
                
                num2019instances++;
                sum2019avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2020)){
                
                num2020instances++;
                sum2020avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2021)){
                
                num2021instances++;
                sum2021avg += datalist[i].value;
                
            }
        }
        
        
    }
    
    double albavg = sumavg/numofinstances;
    printf("\n Alberta Total average: %.2lf\n", albavg);
    printf("\n Alberta Yearly average\n----------------\n");
    printf("2015 average: %.2lf\n", sum2015avg/num2015instances);
    printf("2016 average: %.2lf\n", sum2016avg/num2016instances);
    printf("2017 average: %.2lf\n", sum2017avg/num2017instances);
    printf("2018 average: %.2lf\n", sum2018avg/num2018instances);
    printf("2019 average: %.2lf\n", sum2015avg/num2019instances);
    printf("2020 average: %.2lf\n", sum2020avg/num2020instances);
    printf("2021 average: %.2lf\n", sum2021avg/num2021instances);
    
    sumavg = 0; numofinstances = 0;
    sum2015avg = 0; num2015instances = 0;
    sum2016avg = 0; num2016instances = 0;
    sum2017avg = 0; num2017instances = 0;
    sum2018avg = 0; num2018instances = 0;
    sum2019avg = 0; num2019instances = 0;
    sum2020avg = 0; num2020instances = 0;
    sum2021avg = 0; num2021instances = 0;
    
    
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo), "\"British Columbia\"")){
            
            numofinstances++;
            sumavg += datalist[i].value;
        }
    }
    
    for (int i = 0; i < row+1; i++){
        if(!strcmp(datalist[i].geo, "\"British Columbia\"")){
            
            if((datalist[i].date == 2015)){
                
                num2015instances++;
                sum2015avg += datalist[i].value;
                
                
        }else if ((datalist[i].date == 2016)){
            
                num2016instances++;
                sum2016avg += datalist[i].value;
                
               
            }else if ((datalist[i].date == 2017)){
                
                num2017instances++;
                sum2017avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2018)){
                
                num2018instances++;
                sum2018avg += datalist[i].value;
            
            }else if ((datalist[i].date == 2019)){
                
                num2019instances++;
                sum2019avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2020)){
                
                num2020instances++;
                sum2020avg += datalist[i].value;
                
            }else if ((datalist[i].date == 2021)){
                
                num2021instances++;
                sum2021avg += datalist[i].value;
                
            }
        }
        
        
    }
    
    double bcavg = sumavg/numofinstances;
    printf("\n ontario Total average: %.2lf\n", bcavg);
    printf("\n British Columbia Yearly average\n----------------\n");
    printf("2015 average: %.2lf\n", sum2015avg/num2015instances);
    printf("2016 average: %.2lf\n", sum2016avg/num2016instances);
    printf("2017 average: %.2lf\n", sum2017avg/num2017instances);
    printf("2018 average: %.2lf\n", sum2018avg/num2018instances);
    printf("2019 average: %.2lf\n", sum2015avg/num2019instances);
    printf("2020 average: %.2lf\n", sum2020avg/num2020instances);
    printf("2021 average: %.2lf\n", sum2021avg/num2021instances);
    
    sumavg = 0; numofinstances = 0;
    sum2015avg = 0; num2015instances = 0;
    sum2016avg = 0; num2016instances = 0;
    sum2017avg = 0; num2017instances = 0;
    sum2018avg = 0; num2018instances = 0;
    sum2019avg = 0; num2019instances = 0;
    sum2020avg = 0; num2020instances = 0;
    sum2021avg = 0; num2021instances = 0;
    
    
    return 0;
}
