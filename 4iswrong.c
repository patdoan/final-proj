#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXX 1024
#define SIZE 50

struct origdata {
  // define placeholders for 18 columns of data

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
  // define variables for the 5 columns of data we will work with

  int ref_date;
  char geo[SIZE];
  char age_group[SIZE];
  char sex[SIZE];
  double percent;
};

int main(void) { // First we BEGIN EXTRACTING data from csv spreadsheet
  FILE *sheet = fopen("statscan_diabetes.csv", "r");
  FILE *sheet2 = fopen("statscan_diabetes.csv", "r");
  char line[MAXX];
  char line2[MAXX];
  char *token;
  struct origdata alldata;
  struct dataset data;

  if (sheet == NULL) {
    printf(" error opening file\n");
    return 1;
  }

  fgets(line, MAXX,
        sheet); //// declare arrays with how many rows in first sheet
  int row = 0;

  while (fgets(line, MAXX, sheet)) {

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

  /*//Use the following to Check and Print the values as separate columns
      printf("Ref Date, Geo, Age Group, Sex, Value\n");
        for (int i = 0; i< row; i++){
      printf("%d %s %s %s %.3lf\n", array[i].ref_date, array[i].geo,
     array[i].sex, array[i].age_group, array[i].percent/100);
     }*/
     

// Here we BEGIN QUESTION 1.
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

  printf("\nd)\t35 to 49 years: %.2lf\n", bc_35);
  printf("\t50 to 64 years: %.2lf\n", bc_50);
  printf("\t65 years and over: %.2lf\n", bc_65);
//end bc

  
  printf("\n\nQuestion 2. \n"); // Find province with highest and lowest percent

double provAvg[4] = {QCavg, ONavg, ABavg, BCavg}; //array containing all province averages
char* provNames[4] = {"Quebec", "Ontario", "Alberta", "British Columbia"}; // array containing province names to correspond with the above average array. 

int highest = 0, lowest = 0;
for (int i = 1; i < 4; i++) {
  if (provAvg[i] > provAvg[highest]) { highest = i; } 
  if (provAvg[i] < provAvg[lowest]) { lowest = i; }
}
// Check and Print highest and lowest percent
printf("\n2)\tHighest percentage in %s with %.2lf%%\n", provNames[highest], provAvg[highest]);
printf("\tLowest percentage in %s with %.2lf%%\n", provNames[lowest], provAvg[lowest]);

  printf("\n\nQuestion 3. \n"); // Find all provinces above and below canada avg

// compare province averages with national average
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

  printf("\n\nQuestion 4.\n");


  /* double provYearly[4][7];

for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 7; j++) {
        switch (i) {
            case 0:
                provYearly[i][j] = QCyearavg[j];
                break;
            case 1:
                provYearly[i][j] = ONyearavg[j];
                break;
            case 2:
                provYearly[i][j] = AByearavg[j];
                break;
            case 3:
                provYearly[i][j] = BCyearavg[j];
                break;
            default:
                break;
        }
    }
}

  // Print the contents of the provYearly array
    for (int i = 0; i < 4; i++) {
        printf("Array %d: ", i);
        for (int j = 0; j < 7; j++) {
            printf("%f ", provYearly[i][j]);
        }
        printf("\n");
    }

    
    int i, j;
    double low = provYearly[0][0];
    double high = provYearly[0][0];
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 7; j++) {
            if (provYearly[i][j] < lowest) {
                low = provYearly[i][j];
            }
            if (provYearly[i][j] > highest) {
                high = provYearly[i][j];
            }
        }
    }
    
    printf("The lowest value is: %.2f\n", low);
    printf("The highest value is: %.2f\n", high);
    
  */
/*double provYearly[4][7] = {QCyearavg[7], ONyearavg[7], AByearavg[7], BCyearavg[7]}; 
  // Find highest and lowest province and year
double high = 0, low = 100;
int bigprov = 0, bigyear = 0; //index
int lowprov = 0, lowyear = 0; //index

for (int i = 0; i < 7; i++) {
  if (QCyearavg[i] > high) {
    high = QCyearavg[i];
    highestYear = i + 2015;
    highestProv = 0;
  }
  if (QCyearavg[i] < lowest) {
    lowest = QCyearavg[i];
    lowestYear = i + 2015;
    lowestProv = 0;
  }
  if (ONyearavg[i] > highest) {
    highest = ONyearavg[i];
    highestYear = i + 2015;
    highestProv = 1;
  }
  if (ONyearavg[i] < lowest) {
    lowest = ONyearavg[i];
    lowestYear = i + 2015;
    lowestProv = 1;
  }
  if (AByearavg[i] > highest) {
    highest = AByearavg[i];
    highestYear = i + 2015;
    highestProv = 2;
  }
  if (AByearavg[i] < lowest) {
    lowest = AByearavg[i];
    lowestYear = i + 2015;
    lowestProv = 2;
  }
  if (BCyearavg[i] > highest) {
    highest = BCyearavg[i];
    highestYear = i + 2015;
    highestProv = 3;
  }
  if (BCyearavg[i] < lowest) {
    lowest = BCyearavg[i];
    lowestYear = i + 2015;
    lowestProv = 3;
  }
}

// Print results
printf("Highest percentage of diabetes is in province %s in year %d with %.2lf%%\n", provNames[highestProv], highestYear, high);
printf("Lowest percentage of diabetes is in province %s in year %d with %.2lf%%\n", provNames[lowestProv], lowestYear, low); 

double provYearly[4][7] = {QCyearavg[7], ONyearavg[7], AByearavg[7], BCyearavg[7]};

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

/// Print results
bool high[4] = {false}; // has the highest percent been printed? 
bool low[4] = {false}; // has thelowest percent been printed? 
  
for (int j = 0; j < 7; j++) {
  for (int i = 0; i < 4; i++) {
    if (provYearly[i][j] == provYearly[bigprov][bigyear] && !high[i]) {
      printf("High: %s in %d\n", provNames[i], bigyear + 2015);
      high[i] = true;
    }
    if (provYearly[i][j] == provYearly[lowprov][lowyear] && !low[i]) {
      printf("Low: %s in %d\n", provNames[i], lowyear + 2015);
      low[i] = true;
    }
  }
}
*/
//printf("\nProvince with highest diabetes percentage: %s Year: %d\n", provNames[bigprov], bigyear + 2015);
//printf("\nProvince with lowest diabetes percentage: %s, Year: %d\n", provNames[lowyear], lowyear + 2015);


  return 0;
}
