#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 212

typedef struct {
    double date;
    char ref_date[MAX];
    char geo[MAX];
    char age_group[MAX];
    char sex[MAX];
    char value[MAX]; 
    double percent;
} Data;

int main() {
    FILE *fp;
    char line[MAX];
    char *token;
    Data data;

    // Open the file
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Print header row
    printf("Ref Date,Geo,Age Group,Sex,Value\n");

    // Read each line of the file
    while (fgets(line, MAX, fp) != NULL) {
        // Split the line into tokens using comma as the delimiter
        token = strtok(line, ",");
        int i = 1;
        while (token != NULL) {
            // Store the values in the appropriate struct members
            switch (i) {
                case 1:
                    strcpy(data.ref_date, token);
                    data.date = atof(token);
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
                case 14:
                    strcpy(data.value, token);
                    data.percent = atof(token);
                    break;
            }
            token = strtok(NULL, ",");
            i++;
        }

        // Print the values as separate columns
        //printf("%s (%.2lf),%s,%s,%s,%s (%.2lf)\n", data.ref_date, data.date, data.geo, data.age_group, data.sex, data.value, data.percent);
    

        // Initialize variables
    double total_percent;
    double province[4];         // # of provinces 
    int numprov[4];
    double yearly_percent[7][5]; // yrs inbetween & # of calculations 
    int numyears[7][5]; 
    
    // Calculate averages
    if (strcmp(data.geo, "Canada (excluding territories)") == 0) {
        
        printf("%s", data.geo);
        
        total_percent += data.percent;
        int year_index = data.date - 2015;      // 2015 is the last date
        
        if (year_index >= 0 && year_index < 7) {
            yearly_percent[year_index][4] += data.percent;
            numyears[year_index][4]++;
        }
    } else if (strcmp(data.geo, "Ontario") == 0) {
        province[0] += data.percent;        //this doesn't make sense 
        numprov[0]++; 
        
    } else if (strcmp(data.geo, "Quebec") == 0) {
        province[1] += data.percent;
        numprov[1]++;
        
    } else if (strcmp(data.geo, "British Columbia") == 0) {
        province[2] += data.percent;
        numprov[2]++;
        
    } else if (strcmp(data.geo, "Alberta") == 0) {
        province[3] += data.percent;
        numprov[3]++;
        
        // line to conclude avg calculations. for all i, province[i]/ numprov[i] = avg[] 
        //double ang []; 
    }
    // printf("%s (%.2lf),%s,%s,%s,%s (%.2lf),%.2lf,%.2lf,%.2lf,%.2lf,%.2lf\n", 
    // data.ref_date, data.date, data.geo, data.age_group, data.sex, data.value, data.percent,
    // province[0], province[1], province[2], province[3], total_percent);

} 

    // Close the file
    fclose(fp);

    return 0;
}
