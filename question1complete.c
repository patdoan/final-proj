#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
     }
     */

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
  printf("\nb) Canada National average: %.2lf\n", CAavg);
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
  printf("\na) Quebec Provincial average: %.2lf\n", QCavg);
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
  printf("\na) Ontario Provincial average: %.2lf\n", ONavg);
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
  printf("\na) British Columbia Provincial average: %.2lf\n", ABavg);
  printf("\nc) British Colombia Yearly averages\n_______________\n");
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
  printf("\na) British Columbia Provincial average: %.2lf\n", BCavg);
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

  

  printf("\nMissing: 2) Province with lowest and highest percentage.\n");

  printf("\nMissing: 3) Province with above and below Canada's Average.\n");

  printf("\nMissing: 4) Year+Province with lowest and highest percentage.\n");

  return 0;
}
