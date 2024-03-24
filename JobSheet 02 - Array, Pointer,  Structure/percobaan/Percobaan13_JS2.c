/*
	Nama  : Ridho Hamdani Putra
	Nim   : 23343052
	Prodi : Informatika
*/
#include <stdio.h>
struct person{
	int age;
	float weight;
};

int main(){
	struct person *personPtr, person1;
	
	personPtr = &person1;
	printf("Enter age: ");
	scanf("%d", &personPtr->age);
	printf("Enter weight: ");
	scanf("%f", &personPtr->weight);
	printf("Displaying:\n");
	printf("Age: %d Tahun\n", personPtr->age);
	printf("weight: %0.f Cm", personPtr->weight);
	
	return 0;
}
