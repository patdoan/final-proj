#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXX 1024
#define SIZE 40

// MAXX # of lines, SIZE of characters allowed in arrays 

struct data {
// define variables for the 5 columns of data we will work with

    char ref_date[SIZE];
    char geo[SIZE];
    char age_group[SIZE];
    char sex[SIZE];
    char value[SIZE]; 
    double percent, date;
};

int main() {
    FILE *sheet;
    char line[MAXX];
    char *token;
    struct data data;

  // open the spreadsheet csv files
  sheet = fopen("statscan_diabetes.csv", "r");
    if(sheet == NULL){
        printf("Something's missing.. Where's your file, homes?\n");
        return 1;
    }

    // Print title row
    printf("Ref Date, Geo, Age Group, Sex, Value\n");

double percent, date; 

    // Read each line of the file
    while (fgets(line, MAXX, sheet) != NULL) {
        // Split the line into tokens using comma as the delimiter
        token = strtok(line, "\",\""); //
        int i = 1;
        while (token != NULL) {
            // Store the values in the appropriate struct members
            switch (i) {
                case 1:
                    strcpy(data.ref_date, token);
                    data.date = atoi(token); // change from character array to integer array
                    break;
                case 2:
                    strcpy(data.geo, token);
                    break;
                case 4:
                    strcpy(data.age_group, token);
                    break;
                case 5:
                    strcpy(data.sex, token);
                    break;
                case 13:        // data from relevant column 14 
                  
                    token = strtok(NULL, "\",\""); 
                    strcpy(data.value, token);
                    data.percent = atof(token)/100; //change value char-> percent float
                    break;
            }
            token = strtok(NULL, ","); 
            i++;
        }

        //Print the values as separate columns
        printf("%s (%.lf),%s,%s,%s,%s (%.3lf)\n", data.ref_date, data.date, data.geo, data.age_group, data.sex, data.value, data.percent);
    } 
  
  // Done collecting data from file!
    fclose(sheet);

    return 0;
}