/*
Title: Inventory-Records
Description: This will store records of the stocks you are holding.
Authors: Lesther Porras, Evenesir Reso, Eldrich Valencerina
Date: August 19, 2014
*/

#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

void viewStock();
void Delete();
void inputStock();
void aboutUs();

int main(){
    char c;
	while(1){
    system("cls");
    printf("INVENTORY (v.1.0)");
	printf("\n\nPlease choose an option.\n");
	printf("[I]nput data\n[D]elete the existing list to make a new one\n[V]iew the Stocks\n[T]he Creators\n[E]xit\n");
	scanf("%c", &c);

	switch(c){
		case 'I':
		case 'i':
				inputStock();
				break;

		case 'D':
		case 'd':
				Delete();
				break;

        case 'v':
		case 'V':
				viewStock();
				break;

        case 't':
		case 'T':
				aboutUs();
				break;

        case 'E':
		case 'e':
			break;

		default:
            system("cls");
            printf("INVALID INPUT!\n");
			system("pause");
            break;
		}
    getchar();
    printf("\n");
	//main();

    if (c == 'E' || c == 'e'){
		break;
		}
    }
	system("cls");
    printf("\n Bye! Thanks for working with us. See you next time!\n");
    system("pause");
}

void viewStock(){
    system("cls");
	string data;
	ifstream file ("Stock.txt");
	if (file.is_open())
	{
		while (file.good() )
		{
			getline (file, data);
			cout<<data<<endl;
		}
		file.close();
	}
	system("pause");
}

void inputStock(){
    system("cls");
    char name[50][100], type[50][100], company[50][100];
    int i=0, quantity[50];
    printf("How many data would you like to input? \n");
	scanf("%d", &i);
    for(int x=0; x!=i; x++)
			{
				printf("\n\nName: ");
				scanf("%s", &name[x]);
				printf("Type: ");
				scanf("%s", &type[x]);
				printf("Quantity: ");
				scanf("%d", &quantity[x]);
				printf("Company: ");
				scanf("%s", &company[x]);

				ofstream file;
				file.open("Stock.txt",ios::app);
				if (file.is_open())
				{
				file<<"\n\nName: ";
				file<<name[x];
				file<<"\nType: ";
				file<<type[x];
				file<<"\nQuantity: ";
				file<<quantity[x];
				file<<"\nCompany: ";
				file<<company[x];
				file.close();
				system("pause");
				}
			}
}

void Delete(){
	system("cls");
	string comb;
	char choice;
	comb = "stock.txt";
	printf("\nAre you sure you want to delete stock list? ([Y]es or [N]o)\n");
	scanf("%c", &choice);
	switch(choice)
	{
	case 'Y':
	case 'y':
			remove(comb.c_str());
			printf("Inventory list has been deleted. \n");
			system("pause");
			break;

	case 'N':
	case 'n':
			break;

	default:
			printf("Invalid input! \n");
			Delete();
	}
}

void aboutUs(){
    system("cls");
	printf("This program was made by:");
	printf("\n\nEldrich Valencerina (BS-ECE2, DLSU)");
	printf("\nLesther Porras (BS-ECE2, DLSU)");
	printf("\nEvenesir Reso (BS-ECE2, DLSU)");
	printf("\n\n\n\nCopyright ©2014");
	printf("\nAll Rights Reserved\n");
	system("pause");
}
