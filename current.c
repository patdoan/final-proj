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

int main(void) {
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

  /*//Print the values as separate columns
      printf("Ref Date, Geo, Age Group, Sex, Value\n");
        for (int i = 0; i< row; i++){
      printf("%d %s %s %s %.3lf\n", array[i].ref_date, array[i].geo,
     array[i].sex, array[i].age_group, array[i].percent/100);
     }
     */

  double sumavg = 0, numofinstances = 0;
  double sum2015avg = 0, num2015instances = 0;
  double sum2016avg = 0, num2016instances = 0;
  double sum2017avg = 0, num2017instances = 0;
  double sum2018avg = 0, num2018instances = 0;
  double sum2019avg = 0, num2019instances = 0;
  double sum2020avg = 0, num2020instances = 0;
  double sum2021avg = 0, num2021instances = 0;

  printf("The average percentage of the population that is diagonsed with "
         "diabetes (for all years and age groups):\n");

  for (int i = 0; i < row + 1; i++) {

    if (!strcmp(array[i].geo, "\"Canada (excluding territories)\"")) {
      numofinstances++;
      sumavg += array[i].percent;
    }
  }
  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Canada (excluding territories)\"")) {
      numofinstances++;
      sumavg += array[i].percent;

      if (array[i].ref_date == 2015) {

        num2015instances++;
        sum2015avg += array[i].percent;

      } else if (array[i].ref_date == 2016) {

        num2016instances++;
        sum2016avg += array[i].percent;

      } else if (array[i].ref_date == 2017) {

        num2017instances++;
        sum2017avg += array[i].percent;

      } else if (array[i].ref_date == 2018) {

        num2018instances++;
        sum2018avg += array[i].percent;

      } else if (array[i].ref_date == 2019) {

        num2019instances++;
        sum2019avg += array[i].percent;

      } else if (array[i].ref_date == 2020) {

        num2020instances++;
        sum2020avg += array[i].percent;

      } else if (array[i].ref_date == 2021) {

        num2021instances++;
        sum2021avg += array[i].percent;
      }
    }
  }

  double canavg = sumavg / numofinstances;
  printf("canada ( excluding territories) Total average: %.2lf\n", canavg);
  printf("canada ( excluding territories) Yearly average\n");
  printf("2015 average: %.2lf\n", sum2015avg / num2015instances);
  printf("2016 average: %.2lf\n", sum2016avg / num2016instances);
  printf("2017 average: %.2lf\n", sum2017avg / num2017instances);
  printf("2018 average: %.2lf\n", sum2018avg / num2018instances);
  printf("2019 average: %.2lf\n", sum2015avg / num2019instances);
  printf("2020 average: %.2lf\n", sum2020avg / num2020instances);
  printf("2021 average: %.2lf\n", sum2021avg / num2021instances);

  // end
  sumavg = 0;
  numofinstances = 0;
  sum2015avg = 0;
  num2015instances = 0;
  sum2016avg = 0;
  num2016instances = 0;
  sum2017avg = 0;
  num2017instances = 0;
  sum2018avg = 0;
  num2018instances = 0;
  sum2019avg = 0;
  num2019instances = 0;
  sum2020avg = 0;
  num2020instances = 0;
  sum2021avg = 0;
  num2021instances = 0;

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Quebec\"")) {

      numofinstances++;
      sumavg += array[i].percent;
    }
  }

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Quebec\"")) {

      if (array[i].ref_date == 2015) {

        num2015instances++;
        sum2015avg += array[i].percent;

      } else if (array[i].ref_date == 2016) {

        num2016instances++;
        sum2016avg += array[i].percent;

      } else if (array[i].ref_date == 2017) {

        num2017instances++;
        sum2017avg += array[i].percent;

      } else if (array[i].ref_date == 2018) {

        num2018instances++;
        sum2018avg += array[i].percent;

      } else if (array[i].ref_date == 2019) {

        num2019instances++;
        sum2019avg += array[i].percent;

      } else if (array[i].ref_date == 2020) {

        num2020instances++;
        sum2020avg += array[i].percent;

      } else if (array[i].ref_date == 2021) {

        num2021instances++;
        sum2021avg += array[i].percent;
      }
    }
  }

  double queavg = sumavg / numofinstances;
  printf("\n quebec Total average: %.2lf\n", queavg);
  printf("\n quebec Yearly average\n---------------\n");
  printf("2015 average: %.2lf\n", sum2015avg / num2015instances);
  printf("2016 average: %.2lf\n", sum2016avg / num2016instances);
  printf("2017 average: %.2lf\n", sum2017avg / num2017instances);
  printf("2018 average: %.2lf\n", sum2018avg / num2018instances);
  printf("2019 average: %.2lf\n", sum2015avg / num2019instances);
  printf("2020 average: %.2lf\n", sum2020avg / num2020instances);
  printf("2021 average: %.2lf\n", sum2021avg / num2021instances);

  // end2

  sumavg = 0;
  numofinstances = 0;
  sum2015avg = 0;
  num2015instances = 0;
  sum2016avg = 0;
  num2016instances = 0;
  sum2017avg = 0;
  num2017instances = 0;
  sum2018avg = 0;
  num2018instances = 0;
  sum2019avg = 0;
  num2019instances = 0;
  sum2020avg = 0;
  num2020instances = 0;
  sum2021avg = 0;
  num2021instances = 0;

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Ontario\"")) {

      numofinstances++;
      sumavg += array[i].percent;
    }
  }

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Ontario\"")) {

      if (array[i].ref_date == 2015) {

        num2015instances++;
        sum2015avg += array[i].percent;

      } else if (array[i].ref_date == 2016) {

        num2016instances++;
        sum2016avg += array[i].percent;

      } else if (array[i].ref_date == 2017) {

        num2017instances++;
        sum2017avg += array[i].percent;

      } else if (array[i].ref_date == 2018) {

        num2018instances++;
        sum2018avg += array[i].percent;

      } else if (array[i].ref_date == 2019) {

        num2019instances++;
        sum2019avg += array[i].percent;

      } else if (array[i].ref_date == 2020) {

        num2020instances++;
        sum2020avg += array[i].percent;

      } else if (array[i].ref_date == 2021) {

        num2021instances++;
        sum2021avg += array[i].percent;
      }
    }
  }

  double ontavg = sumavg / numofinstances;
  printf("\n ontario Total average: %.2lf\n", ontavg);
  printf("\n ontario Yearly average\n----------------\n");
  printf("2015 average: %.2lf\n", sum2015avg / num2015instances);
  printf("2016 average: %.2lf\n", sum2016avg / num2016instances);
  printf("2017 average: %.2lf\n", sum2017avg / num2017instances);
  printf("2018 average: %.2lf\n", sum2018avg / num2018instances);
  printf("2019 average: %.2lf\n", sum2015avg / num2019instances);
  printf("2020 average: %.2lf\n", sum2020avg / num2020instances);
  printf("2021 average: %.2lf\n", sum2021avg / num2021instances);

  // end3
  sumavg = 0;
  numofinstances = 0;
  sum2015avg = 0;
  num2015instances = 0;
  sum2016avg = 0;
  num2016instances = 0;
  sum2017avg = 0;
  num2017instances = 0;
  sum2018avg = 0;
  num2018instances = 0;
  sum2019avg = 0;
  num2019instances = 0;
  sum2020avg = 0;
  num2020instances = 0;
  sum2021avg = 0;
  num2021instances = 0;

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Alberta\"")) {

      numofinstances++;
      sumavg += array[i].percent;
    }
  }

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"Alberta\"")) {

      if (array[i].ref_date == 2015) {

        num2015instances++;
        sum2015avg += array[i].percent;

      } else if (array[i].ref_date == 2016) {

        num2016instances++;
        sum2016avg += array[i].percent;

      } else if (array[i].ref_date == 2017) {

        num2017instances++;
        sum2017avg += array[i].percent;

      } else if (array[i].ref_date == 2018) {

        num2018instances++;
        sum2018avg += array[i].percent;

      } else if (array[i].ref_date == 2019) {

        num2019instances++;
        sum2019avg += array[i].percent;

      } else if (array[i].ref_date == 2020) {

        num2020instances++;
        sum2020avg += array[i].percent;

      } else if (array[i].ref_date == 2021) {

        num2021instances++;
        sum2021avg += array[i].percent;
      }
    }
  }

  double albavg = sumavg / numofinstances;
  printf("\n Alberta Total average: %.2lf\n", albavg);
  printf("\n Alberta Yearly average\n----------------\n");
  printf("2015 average: %.2lf\n", sum2015avg / num2015instances);
  printf("2016 average: %.2lf\n", sum2016avg / num2016instances);
  printf("2017 average: %.2lf\n", sum2017avg / num2017instances);
  printf("2018 average: %.2lf\n", sum2018avg / num2018instances);
  printf("2019 average: %.2lf\n", sum2015avg / num2019instances);
  printf("2020 average: %.2lf\n", sum2020avg / num2020instances);
  printf("2021 average: %.2lf\n", sum2021avg / num2021instances);

  // end4
  sumavg = 0;
  numofinstances = 0;
  sum2015avg = 0;
  num2015instances = 0;
  sum2016avg = 0;
  num2016instances = 0;
  sum2017avg = 0;
  num2017instances = 0;
  sum2018avg = 0;
  num2018instances = 0;
  sum2019avg = 0;
  num2019instances = 0;
  sum2020avg = 0;
  num2020instances = 0;
  sum2021avg = 0;
  num2021instances = 0;

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"British Columbia\"")) {

      numofinstances++;
      sumavg += array[i].percent;
    }
  }

  for (int i = 0; i < row + 1; i++) {
    if (!strcmp(array[i].geo, "\"British Columbia\"")) {

      if (array[i].ref_date == 2015) {

        num2015instances++;
        sum2015avg += array[i].percent;

      } else if (array[i].ref_date == 2016) {

        num2016instances++;
        sum2016avg += array[i].percent;

      } else if (array[i].ref_date == 2017) {

        num2017instances++;
        sum2017avg += array[i].percent;

      } else if (array[i].ref_date == 2018) {

        num2018instances++;
        sum2018avg += array[i].percent;

      } else if (array[i].ref_date == 2019) {

        num2019instances++;
        sum2019avg += array[i].percent;

      } else if (array[i].ref_date == 2020) {

        num2020instances++;
        sum2020avg += array[i].percent;

      } else if (array[i].ref_date == 2021) {

        num2021instances++;
        sum2021avg += array[i].percent;
      }
    }
  }

  double bcavg = sumavg / numofinstances;
  printf("\n ontario Total average: %.2lf\n", bcavg);
  printf("\n British Columbia Yearly average\n----------------\n");
  printf("2015 average: %.2lf\n", sum2015avg / num2015instances);
  printf("2016 average: %.2lf\n", sum2016avg / num2016instances);
  printf("2017 average: %.2lf\n", sum2017avg / num2017instances);
  printf("2018 average: %.2lf\n", sum2018avg / num2018instances);
  printf("2019 average: %.2lf\n", sum2015avg / num2019instances);
  printf("2020 average: %.2lf\n", sum2020avg / num2020instances);
  printf("2021 average: %.2lf\n", sum2021avg / num2021instances);

  sumavg = 0;
  numofinstances = 0;
  sum2015avg = 0;
  num2015instances = 0;
  sum2016avg = 0;
  num2016instances = 0;
  sum2017avg = 0;
  num2017instances = 0;
  sum2018avg = 0;
  num2018instances = 0;
  sum2019avg = 0;
  num2019instances = 0;
  sum2020avg = 0;
  num2020instances = 0;
  sum2021avg = 0;
  num2021instances = 0;

  return 0;
}
