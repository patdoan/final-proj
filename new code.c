#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXX 1024
#define SIZE 50

struct origdata {
  // Define a struct for the original data containing 18 columns of data

  int ref_date;
  char geo[SIZE];
  char DGUID[SIZE];
  char age_group[SIZE];
  char sex[SIZE];
  char indicator[SIZE], characteristic[SIZE], UOM[SIZE];
  int UOMid;
  char scalar_factor[SIZE];
  int scalarID;
  char vector[SIZE], coordinate[SIZE];
  double percent;
  char status, symbol, terminate;
  int decimal;
};

struct dataset {
  // Define a struct for the subset of data we will work with containing 5 columns

  int ref_date;
  char geo[SIZE];
  char age_group[SIZE];
  char sex[SIZE];
  double percent;
};

int main(void) { 
// First we BEGIN EXTRACTING data from csv spreadsheet
  FILE *sheet = fopen("statscan_diabetes.csv", "r");
  FILE *sheet2 = fopen("statscan_diabetes.csv", "r");
  
  
  // Declare variables for reading in lines and tokens
  
  
  char line[MAXX];
  char line2[MAXX];
  char *token;
  
  // Declare structs for holding the original data and the subset of data we will work with

  struct origdata alldata;
  struct dataset data;
  
  // Check if the file was opened successfully

  if (sheet == NULL) {
    printf(" error opening file\n");
    return 1;
  }
  
   // Read in the first line, which contains headers for each column, but we do not need to use them

  fgets(line, MAXX,
        sheet); //// declare arrays with how many rows in first sheet
        
  int row = 0;
  
  // Loop through each line in the file

  while (fgets(line, MAXX, sheet)) {
      

    token = strtok(line, "\",\"");
    if (!token || !token[0])
      continue;
      
    // Read in the value of the first column and store it in both structs
    
    
    alldata.ref_date = atoi(token);
    data.ref_date = atoi(token); // relevant column 1

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.geo, token);
    strcpy(data.geo, token); // relevant column 2

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.DGUID, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.age_group, token);
    strcpy(data.age_group, token); // relevant column 4

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.sex, token);
    strcpy(data.sex, token); // relevant column 5

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.indicator, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.characteristic, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.UOM, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.UOMid = atoi(token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.scalar_factor, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.scalarID = atoi(token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.vector, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.coordinate, token);

    token = strtok(NULL, ",\"");
    if (!token || !token[0])
      continue;
    alldata.percent = atof(token);
    data.percent = atof(token); // relevant column 14

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.status = token[0];

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.symbol = token[0];

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.terminate = token[0];

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.decimal = atoi(token);

    row++;
  }

  struct dataset array[row]; // now we work with sheet 2
  int counter = 0;
  fgets(line, MAXX, sheet2);

  while (fgets(line, MAXX, sheet2)) {

    token = strtok(line, "\",\"");
    if (!token || !token[0])
      continue;
    alldata.ref_date = atoi(token);
    data.ref_date = atoi(token); // relevant column 1

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.geo, token);
    strcpy(data.geo, token); // relevant column 2

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.DGUID, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.age_group, token);
    strcpy(data.age_group, token); // relevant column 4

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.sex, token);
    strcpy(data.sex, token); // relevant column 5

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.indicator, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.characteristic, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.UOM, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.UOMid = atoi(token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.scalar_factor, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.scalarID = atoi(token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.vector, token);

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    strcpy(alldata.coordinate, token);

    token = strtok(NULL, ",\"");
    if (!token || !token[0])
      continue;
    alldata.percent = atof(token);
    data.percent = atof(token); // relevant column 14

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.status = token[0];

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.symbol = token[0];

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.terminate = token[0];

    token = strtok(NULL, ",");
    if (!token || !token[0])
      continue;
    alldata.decimal = atoi(token);

    array[counter] = data;

    counter++;
  }


// Here we BEGIN QUESTION 1.
/* In this program segment, the average percentage of people in Canada, Quebec,Ontario, Alberta and British Columbia who have been diagnosed with diabetes for different age groups is calculated (35 to 49, 50 to 64, and 65 years and over). And it also determines the yearly average for each region from 2015 through 2021.

Totavg and totcount, which stand for the total average percentage and the total number of records, respectively, are initialised by the program.It initialises yearavg, yearcount, avg 35, avg 50, and avg 65 for the average proportion of diabetes for each of the three age groups, as well as yearavg, yearcount, and avg 65 for the average percentage of records per year

The program then uses a for loop to get the average proportion of the population in Canada, Quebec, Ontario, Alberta, and Bristish Columbia that has been diagnosed with diabetes for each age group and each year. The appropriate variable receives the percentage value once each entry in the array has been examined. It then tracks the number of records for every year and every age category.

The program prints the results after computing the average percentages. It then prints the annual averages for the seven years from 2015 to 2021 as well as the national average for Canada. F or each age group in Canada, it displays the typical percentage of the population with a diabetes diagnosisThe same details are presented for Ontario, Quebec, British Columbia, and alberta.

line 293 - 541 */

printf("\nQuestion 1: Let's determine what percentage of the population was "
         "diagnosed with diabetes.\n\n");
         
  // general initialization of necessary variables
  
  double totavg = 0;
  int totcount = 0;
  double yearavg[7] = {0}; // 2015 to 2021 is 7 years
  int yearcount[7] = {0}; 

  double avg_35 = 0,  avg_50 = 0, avg_65 = 0; // keeps track of total avg in age group
  int count35 = 0, count50 = 0, count65 = 0; // keeps track of how many in age group

// CANADA AVG
  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Canada (excluding territories)\"")) {
      // Total average
      totavg += array[i].percent;
      totcount++;

      // Yearly average
      int yr = array[i].ref_date - 2015; // year index
      yearavg[yr] += array[i].percent;
      yearcount[yr]++;

      if (!strcmp(array[i].age_group, "\"35 to 49 years\"")){ 
        avg_35 += array[i].percent; 
        count35++; 
      }
      else if (!strcmp(array[i].age_group, "\"50 to 64 years\"")){ 
        avg_50 += array[i].percent; 
        count50++; 
      }
      else if (!strcmp(array[i].age_group, "\"65 years and over\"")){ 
        avg_65 += array[i].percent; 
        count65++; 
      } 
    } 
  } 
  
  
// Print CANADA RESULTS
  double CAavg = totavg / totcount; 
  double CAyearavg[7]; 
  printf("\nb) Canada National average: %.2lf%%\n", CAavg);
  printf("\nc) Canada Yearly averages\n_______________\n");
  for (int i = 0; i < 7; i++) {
    int year = i + 2015;
    CAyearavg[i] = yearavg[i] / yearcount[i];
    printf("%d avg: %.2lf\n", year, CAyearavg[i]);
  }
  double can_35 = avg_35 / count35;
  double can_50 = avg_50 / count50;
  double can_65 = avg_65 / count65;
  
  printf("\n Canada diabetes percentage average for the various age group\n" );
  
  printf("\nd)\t35 to 49 years: %.2lf\n", can_35);
  printf("\t50 to 64 years: %.2lf\n", can_50);
  printf("\t65 years and over: %.2lf\n", can_65);
// end canada 
  
// QUEBEC AVG
  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Quebec\"")) {
      // Total average
      totavg += array[i].percent;
      totcount++;

      // Yearly average
      int yr = array[i].ref_date - 2015; // year index
      yearavg[yr] += array[i].percent;
      yearcount[yr]++;

      if (!strcmp(array[i].age_group, "\"35 to 49 years\"")){ 
        avg_35 += array[i].percent; 
        count35++; 
      }
      else if (!strcmp(array[i].age_group, "\"50 to 64 years\"")){ 
        avg_50 += array[i].percent; 
        count50++; 
      }
      else if (!strcmp(array[i].age_group, "\"65 years and over\"")){ 
        avg_65 += array[i].percent; 
        count65++; 
      } 
    } 
  } 
// Print QUEBEC RESULTS
  double QCavg = totavg / totcount; 
  double QCyearavg[7]; 
  printf("\na) Quebec Provincial average: %.2lf%%\n", QCavg);
  printf("\nc) Quebec Yearly averages\n_______________\n");
  for (int i = 0; i < 7; i++) {
    int year = i + 2015;
    QCyearavg[i] = yearavg[i] / yearcount[i];
    printf("%d avg: %.2lf\n", year, QCyearavg[i]);
  }
  double que_35 = avg_35 / count35;
  double que_50 = avg_50 / count50;
  double que_65 = avg_65 / count65;
  
  
  printf("\n Quebec  diabetes percentage average for the various age group\n" );
  printf("\nd)\t35 to 49 years: %.2lf\n", que_35);
  printf("\t50 to 64 years: %.2lf\n", que_50);
  printf("\t65 years and over: %.2lf\n", que_65);
// end que

// start ONTARIO AVG
   for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Ontario\"")) {
      // Total average
      totavg += array[i].percent;
      totcount++;

      // Yearly average
      int yr = array[i].ref_date - 2015; // year index
      yearavg[yr] += array[i].percent;
      yearcount[yr]++;

      if (!strcmp(array[i].age_group, "\"35 to 49 years\"")){ 
        avg_35 += array[i].percent; 
        count35++; 
      }
      else if (!strcmp(array[i].age_group, "\"50 to 64 years\"")){ 
        avg_50 += array[i].percent; 
        count50++; 
      }
      else if (!strcmp(array[i].age_group, "\"65 years and over\"")){ 
        avg_65 += array[i].percent; 
        count65++; 
      } 
    } 
  } 
// Print ONTARIO RESULTS
  double ONavg = totavg / totcount; 
  double ONyearavg[7]; 
  printf("\na) Ontario Provincial average: %.2lf%%\n", ONavg);
  printf("\nc) Ontario Yearly averages\n_______________\n");
  for (int i = 0; i < 7; i++) {
    int year = i + 2015;
    ONyearavg[i] = yearavg[i] / yearcount[i];
    printf("%d avg: %.2lf\n", year, ONyearavg[i]);
  }
  double ont_35 = avg_35 / count35;
  double ont_50 = avg_50 / count50;
  double ont_65 = avg_65 / count65;
  
  printf("\n Ontario  diabetes percentage average for the various age group\n" );
  printf("\nd)\t35 to 49 years: %.2lf\n", ont_35);
  printf("\t50 to 64 years: %.2lf\n", ont_50);
  printf("\t65 years and over: %.2lf\n", ont_65);
// end ont
  
// start ALBERTA AVG
   for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Alberta\"")) {
      // Total average
      totavg += array[i].percent;
      totcount++;

      // Yearly average
      int yr = array[i].ref_date - 2015; // year index
      yearavg[yr] += array[i].percent;
      yearcount[yr]++;

      if (!strcmp(array[i].age_group, "\"35 to 49 years\"")){ 
        avg_35 += array[i].percent; 
        count35++; 
      }
      else if (!strcmp(array[i].age_group, "\"50 to 64 years\"")){ 
        avg_50 += array[i].percent; 
        count50++; 
      }
      else if (!strcmp(array[i].age_group, "\"65 years and over\"")){ 
        avg_65 += array[i].percent; 
        count65++; 
      } 
    } 
  } 
// Print ALBERTA RESULTS
  double ABavg = totavg / totcount; 
  double AByearavg[7]; 
  printf("\na) Alberta Provincial average: %.2lf%%\n", ABavg);
  printf("\nc) Alberta Yearly averages\n_______________\n");
  for (int i = 0; i < 7; i++) {
    int year = i + 2015;
    AByearavg[i] = yearavg[i] / yearcount[i];
    printf("%d avg: %.2lf\n", year, AByearavg[i]);
  }
  double alb_35 = avg_35 / count35;
  double alb_50 = avg_50 / count50;
  double alb_65 = avg_65 / count65;
  
  printf("\n Alberta  diabetes percentage average for the various age group\n" );
  printf("\nd)\t35 to 49 years: %.2lf\n", alb_35);
  printf("\t50 to 64 years: %.2lf\n", alb_50);
  printf("\t65 years and over: %.2lf\n", alb_65);
// end alb 
  
  // start BRITISH COLUMBIA AVG
for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"British Columbia\"")) {
      // Total average
      totavg += array[i].percent;
      totcount++;
      
      // Yearly average
      int yr = array[i].ref_date - 2015; // year index
      yearavg[yr] += array[i].percent;
      yearcount[yr]++;

      if (!strcmp(array[i].age_group, "\"35 to 49 years\"")){ 
        avg_35 += array[i].percent; 
        count35++; 
      }
      else if (!strcmp(array[i].age_group, "\"50 to 64 years\"")){ 
        avg_50 += array[i].percent; 
        count50++; 
      }
      else if (!strcmp(array[i].age_group, "\"65 years and over\"")){ 
        avg_65 += array[i].percent; 
        count65++; 
      } 
    } 
  } 
// Print BRITISH COLUMBIA RESULTS
  double BCavg = totavg / totcount; 
  double BCyearavg[7]; 
  printf("\na) British Columbia Provincial average: %.2lf%%\n", BCavg);
  printf("\nc) British Colombia Yearly averages\n_______________\n");
  for (int i = 0; i < 7; i++) {
    int year = i + 2015;
    BCyearavg[i] = yearavg[i] / yearcount[i];
    printf("%d avg: %.2lf\n", year, BCyearavg[i]);
  }
  double bc_35 = avg_35 / count35;
  double bc_50 = avg_50 / count50;
  double bc_65 = avg_65 / count65;
  
  printf("\n Bristish Colombia diabetes percentage average for the various age group\n" );

  printf("\nd)\t35 to 49 years: %.2lf\n", bc_35);
  printf("\t50 to 64 years: %.2lf\n", bc_50);
  printf("\t65 years and over: %.2lf\n", bc_65);
//end bc

/* For each of the four Canadian provinces (Quebec, Ontario, Alberta, and British Columbia), this code provides two arrays, provAvg and provNames, which include data on the average percentages of an unnamed commodity.

The index of the greatest and lowest values in the provAvg array are then determined by iterating over the array's contents in a for loop.

line  549 - 568 */
  
  printf("\n\nQuestion 2. \n"); // Find province with highest and lowest percent

double provAvg[4] = {QCavg, ONavg, ABavg, BCavg}; //array containing all province averages
char* provNames[4] = {"Quebec", "Ontario", "Alberta", "British Columbia"}; // array containing province names to correspond with the above average array. 

int highest = 0, lowest = 0;
for (int i = 1; i < 4; i++) {
  if (provAvg[i] > provAvg[highest]) { highest = i; } 
  if (provAvg[i] < provAvg[lowest]) { lowest = i; }
}
// Check and Print highest and lowest percent
printf("\n2)\t The province with the highest percentage is %s with %.2lf%%\n", provNames[highest], provAvg[highest]);

printf("\t The province with the lowest percentage is %s with %.2lf%%\n", provNames[lowest], provAvg[lowest]);


/* The provinces with percentages above and below the national average are listed in this code block. It first prints "Over Canada's Average:" and then iterates through the array of province averages, determining if each one's average % is higher than the country's overall average percentage (stored in the variable CAavg). The name of the province is printed if its average percentage is higher than the national average.

The code then outputs "Below Canada's Average:" before iterating once more over the array of provincial averages to see whether each one's average percentage is lower than the national average. The name of the province is printed if its average percentage is lower than the national average.
 
line 569 - 587 */

  printf("\n\nQuestion 3. \n"); // Find all provinces above and below canada avg





printf("\n3)\tAbove Canada's Average:\t");
for (int i = 0; i < 4; i++) {
  if (provAvg[i] > CAavg) {
    printf("%s\t", provNames[i]);
  }
}
printf("\n\tBelow Canada's Average:\t");
for (int i = 0; i < 4; i++) {
  if (provAvg[i] < CAavg) {
    printf("%s\t", provNames[i]);
  }
}

/* Each row in the 2D array provYearly defined by this code represents a province, and each column represents a year, and it contains the yearly averages for each province (starting from 2015).

The next step is to iterate over each province and year to determine which year had the highest and lowest percentage for each province. This is done using nested loops. The variables bigprov, bigyear, lowprov, and lowyear hold the index of the largest and lowest values.

The provinces with the highest and lowest percentages are then stored in the arrays high and low, and the provYearly array is iterated over one more to print out the highest and lowest percentages for each province for each year. The function finally returns 0.
 
 */
 
  printf("\n\nQuestion 4.\n\n");

double provYearly[4][7] = { 
    {QCyearavg[0], QCyearavg[1], QCyearavg[2], QCyearavg[3], QCyearavg[4], QCyearavg[5], QCyearavg[6]},
    {ONyearavg[0], ONyearavg[1], ONyearavg[2], ONyearavg[3], ONyearavg[4], ONyearavg[5], ONyearavg[6]},
    {AByearavg[0], AByearavg[1], AByearavg[2], AByearavg[3], AByearavg[4], AByearavg[5], AByearavg[6]},
    {BCyearavg[0], BCyearavg[1], BCyearavg[2], BCyearavg[3], BCyearavg[4], BCyearavg[5], BCyearavg[6]}
}; 
  

int bigprov = 0, bigyear = 0; //index
int lowprov = 0, lowyear = 0; //index


for (int i = 0; i < 4; i++) { // do for each of 4 provinces
    for (int j = 0; j < 7; j++) { // do for each of 7 ref_date years 
        if (provYearly[i][j] > provYearly[bigprov][bigyear]) {
          bigprov = i; 
          bigyear = j; 
        }
        if (provYearly[i][j] < provYearly[lowprov][lowyear]) {
          lowprov = i;
          lowyear = j;
        }
    }
}

//* high and low arrays
bool high[4] = {false};
bool low[4] = {false};
/////
// Print results
for (int j = 0; j < 7; j++) {
  for (int i = 0; i < 4; i++) {
    if (provYearly[i][j] == provYearly[bigprov][bigyear]) {
      printf("\tThe province with the highest percentage is %s in the year %d\n", provNames[i], bigyear + 2015);
      high[i] = true;
    }
    if (provYearly[i][j] == provYearly[lowprov][lowyear]) {
      printf("\tThe province with the lowest percentage is %s in the year %d\n", provNames[i], lowyear + 2015);
      low[i] = true;
    }
  }
}
  return 0;
}