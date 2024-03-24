/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>

struct Distance{
	int feet;
	float inch;
}dist1, dist2, sum;

int main(){
	printf("1st distance\n");
	printf("Enter feet: ");
	scanf("%d", &dist1.feet);
	printf("Enter inch: ");
	scanf("%f", &dist1.inch);
	printf("2nd distance\n");
	printf("Enter feet: ");
	scanf("%d", &dist2.feet);
	printf("Enter inch: ");
	scanf("%f", &dist2.inch);
	//adding feet
	sum.feet = dist1.feet + dist2.feet;
	//adding inch
	sum.inch = dist1.inch + dist1.inch;
	//changing to feet if inch is greater than 12
	while (sum.inch >= 12){
		++sum.feet;
		sum.inch = sum.inch - 12;
	}
	printf("Sum of distances = %d\ '-%1.f\'", sum.feet, sum.inch);
	return 0;
}
