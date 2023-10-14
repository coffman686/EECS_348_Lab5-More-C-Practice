#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *sales;
	float sale;
	sales = fopen("sales.txt", "r");
	char *months[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int totalMonths = 12;
	float *saleValues = NULL;
	int count = 12;
	saleValues = (float *)malloc(count * sizeof(float));
	
	for (int i = 0; i < count; i++) {
		fscanf(sales, "%f", &saleValues[i]);
	}
	
	fclose(sales);

	salesReport(saleValues, months);
	salesSummary(saleValues, months);
	movingAverage(saleValues, months);
	sortedSales(saleValues, months);

	return 0;

}

void salesReport(float *saleValues, char *months[]) {
	int totalMonths = 12;
	printf("Monthly sales report for 2022:\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < totalMonths; i++) {
		printf("%s\t\t$%.2f\n", months[i], saleValues[i]);
	}
	printf("\n");
}

void salesSummary(float *saleValues, char *months[]) {
	float min = saleValues[0];
	float max = saleValues[0];
	char *minMonth = months[0];
	char *maxMonth;
	float count = 0.0;
	float avg;
	for (int i = 0; i < 12; i++) {
		if (saleValues[i] < min) {
			min = saleValues[i];
			minMonth = months[i];
		}
	
	}
	for (int i = 0; i < 12; i++) {
		if (saleValues[i] > max) {
			max = saleValues[i];
			maxMonth = months[i];
		}
	}
	
	
	for (int i = 0; i < 12; i++) {
		count += saleValues[i];
	}
	avg = count / 12;
	printf("Sales Summary:\n");
	printf("Minumum sales:   $%.2f   (%s)\n", min, minMonth);
	printf("Maximum sales:   $%.2f   (%s)\n", max, maxMonth);
	printf("Average sales:   $%.2f\n", avg);
}

void movingAverage(float *saleValues, char *months[]) {
	printf("\nSix-Month Moving Average Report:\n");
	int monthIndex = 0;
	float avg;
	while(monthIndex <= 6){
		avg = 0;
		for (int i = monthIndex; i < 6+monthIndex; i++){
			avg += saleValues[i];
		}
		avg = avg/6;
		printf("%s\t-\t%s\t$%.2f\n", months[monthIndex], months[monthIndex+5], avg);
		monthIndex+=1;
	}
}

void sortedSales(float *saleValues, char *months[]) {
	float sortValue;
	char *sortmonth;

	for(int i=0; i < 12; i++){
		for(int j= i+1; j <12; j++){
			if (saleValues[i] < saleValues[j]){
				sortValue = saleValues[j];
				saleValues[j] = saleValues[i];
				saleValues[i] = sortValue;
				sortmonth = months[j];
				months[j] = months[i];
				months[i] = sortmonth;
			}
		}
	}

	printf("\nSales Report (Highest to Lowest):\n");
	printf("Month\t\tSales\n");
	for (int i=0; i<12; i++){
		printf("%s\t\t$%.2f\n", months[i], saleValues[i]);
	}




}