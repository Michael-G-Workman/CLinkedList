// CLinkedList.c
//
// By Michael G. Workman
//
// A simple C program demonstrating a Linked List using a Struct for a Zoo Animal
// In the first part, we demonstrate a singly linked list with zoo animals as the nodes
//
// This example freely distributable under terms of MIT open source license

#include<stdio.h>
#include<stdlib.h>

// our animal types
enum AnimalType {
	Lion,
	Giraffe,
	Zebra,
	Pangolin
};

// our animal sex
enum AnimalSex {
	Male,
	Female
};

// data type to be used for each animal (node) in the linked list
struct zooAnimal {
	enum AnimalType type;
	int weight;
	int age;
	enum AnimalSex sex;
	struct zooAnimal *next;
};

// function to return the string name of Animal Type Enum
const char* getEnumNameAnimalType(enum AnimalType animalType) {
	switch (animalType)
	{
		case Lion: return "Lion";
		case Giraffe: return "Giraffe";
		case Zebra: return "Zebra";
		case Pangolin: return "Pangolin";
	}
}

// function to return the string name of Animal Sex Enum
const char* getEnumNameAnimalSex(enum AnimalSex animalSex) {
	switch (animalSex)
	{
		case Male: return "Male";
		case Female: return "Female";
	}
}

int main()
{
	struct zooAnimal *zooKeeper = NULL;
	
	// create a 3 year old 300 pound male lion, make start node of list
	struct zooAnimal *lion1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == lion1)
	{
		printf("\n Lion creation failed \n");
		return 0;
	}
	lion1->type = Lion;
	lion1->sex = Male;
	lion1->age = 3;
	lion1->weight = 300;
	lion1->next = NULL;

	// the zoo keeper starts with this lion before going through the list of animals
	zooKeeper = lion1;

	// create a 1 year old 50 pound female lion cub then make next node in the list
	struct zooAnimal *lion2 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == lion2)
	{
		printf("\n Lion creation failed \n");
		return 0;
	}
	lion2->type = Lion;
	lion2->sex = Female;
	lion2->age = 1;
	lion2->weight = 50;
	lion2->next = NULL;

	// add this lion to be the next animal (node) in the list
	lion1->next = lion2;

	// create a 3 year old 10 pound adult male pangolin then make next node in the list
	struct zooAnimal* pangolin1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == pangolin1)
	{
		printf("\n Pangolin creation failed \n");
		return 0;
	}
	pangolin1->type = Pangolin;
	pangolin1->sex = Male;
	pangolin1->age = 3;
	pangolin1->weight = 10;
	pangolin1->next = NULL;

	// add this pangolin to be the next animal (node) in the list
	lion2->next = pangolin1;

	// create a 5 year old 400 pound adult male giraffe then make next node in the list
	struct zooAnimal* giraffe1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == giraffe1)
	{
		printf("\n Giraffe creation failed \n");
		return 0;
	}
	giraffe1->type = Giraffe;
	giraffe1->sex = Male;
	giraffe1->age = 5;
	giraffe1->weight = 400;
	giraffe1->next = NULL;

	// add this giraffe to be the next animal (node) in the list
	pangolin1->next = giraffe1;

	// create a 2 year old 250 pound adult female zebra then make next node in the list
	struct zooAnimal* zebra1 = (struct zooAnimal*)malloc(sizeof(struct zooAnimal));
	if (NULL == zebra1)
	{
		printf("\n Zebra creation failed \n");
		return 0;
	}
	zebra1->type = Zebra;
	zebra1->sex = Female;
	zebra1->age = 2;
	zebra1->weight = 250;
	zebra1->next = NULL;

	// add this zebra to be the next animal (node) in the list
	giraffe1->next = zebra1;

	// the zoo keeper will now traverse the list of zoo animals (nodes) until reaching the end
	while (zooKeeper != 0) {

		// print out info on the current zoo animal (node) the zoo keeper is dealing with
		printf("%d year old, %d pound %s %s\n\n", 
			zooKeeper->age, 
			zooKeeper->weight, 
			getEnumNameAnimalSex(zooKeeper->sex), 
			getEnumNameAnimalType(zooKeeper->type));

		// move to the next zoo animal (node) in the list
		zooKeeper = zooKeeper->next;
	}

	// deallocate memory for zoo animals
	free(lion1);
	free(lion2);
	free(pangolin1);
	free(giraffe1);
	free(zebra1);
	free(zooKeeper);

	return 1;
}

