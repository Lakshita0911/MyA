#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    long long aadhar_no;
    char name[50], add[100], lm[50], dis[50], st[50], nationality[20], dob[20],cd[20],ud[20];
    char f_name[50];
    int age, pin;
    long long int phn;
    char gender;
} d;


void registration();
void login();
void operatormenu();
void update();
void display();
void remove_record();
void count_records();
void list_all_users();
void search_record();
int validate_aadhar(long long aadhar_no);
void print_card();
int main(){
	int c,usertype;
	main:
	while(1){
		printf("\n-----ADHAR CARD MANAGEMENT SYSTEM------\n");
		printf("1.operator view\n2.user view\n3.exit\n");
		printf("select user type:\n");
		scanf("%d",&usertype);
        
        switch(usertype){
        	case 1:login();
        	break;
        	case 2:
        		while(1){
				printf("\n-----user menu-----\n");
				printf("1.search record\n2.view details\n3.back to menu\n");
				printf("select  your choice:");
				scanf("%d",&c);
				 switch(c){
				 	case 1: search_record();
				 	break;
				 	case 2: print_card();
				 	break;
				 	case 3:goto main;
				 	default:
				 		printf("invalid input! try again\n");
				 }
				}
				case 3: printf("exiting\n");
				       exit(0);
				default:printf("invalid input! try again\n");       
					}
	}
	
	mainmenu:
		return 0;
}
 
 void login(){
 	char username[50],password[50];
 	printf("\nenter operator username: ");
 	scanf("%s",username);
 	printf("\nenter operator password:");
 	scanf("%s",password);
 	
 	if((strcmp(username,"lakshita")==0 && (strcmp(password,"november9")==0))||(strcmp(username,"deepshikha")==0 && (strcmp(password,"june3")==0))||(strcmp(username,"divya")==0 && (strcmp(password,"jan6")==0)))
 	   {
 	   	 printf("login successfully\n");
 	   	 operatormenu();
		}
		else{
			printf("invalid !try again\n");
		}
 }
 
 void operatormenu(){
 	int c;
	 char n;
 	
 	while(1){
 		printf("\n-----operator menu------\n");
 		printf("1. REGISTRATION\n2. UPDATE\n3. DISPLAY\n4. REMOVE\n5. SEARCH\n6. LIST ALL USERS\n7. COUNT RECORDS\n8. log out\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        getchar();

        switch (c) {
            case 1: 
                    registration();
                    break;
           
            case 2:
               update();
                break;
            case 3:
                display();
                break;
            case 4:
               remove_record();
                break;
            case 5:
               search_record();
                break;
            case 6:
                list_all_users();
                break;
            case 7:
                count_records();
                break;
            case 8:
                printf("logging out..\n");
                return;
            case 9:
                  print_card();
                 return;
                
            default:
                printf("Invalid choice\n");
                break;
	 }
 }
}



int validate_aadhar(long long aadhar_no) {
    int digits = 0;
    while (aadhar_no > 0) {
        aadhar_no /= 10;
        digits++;
    }
    return (digits == 12);
}

void registration() {

	
    FILE *fp = fopen("data", "ab+");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }
    
    printf("Enter the user name: ");
    fgets(d.name, sizeof(d.name), stdin);

    printf("Enter the father's name/husband name: ");
    fgets(d.f_name, sizeof(d.f_name), stdin);

    printf("Enter your Address: ");
    fgets(d.add, sizeof(d.add), stdin);
    
    printf("Enter any landmark: ");
    fgets(d.lm, sizeof(d.lm), stdin);

    printf("Enter district: ");
    fgets(d.dis, sizeof(d.dis), stdin);
    
    printf("Enter the state: ");
    fgets(d.st, sizeof(d.st), stdin);
    

    printf("Enter pincode: ");
    scanf("%d", &d.pin);
    getchar();

    printf("Enter phone no.: ");
    scanf("%ld", &d.phn);
    getchar();

    printf("Enter your date of birth (dd/mm/yyyy): ");
    fgets(d.dob, sizeof(d.dob), stdin);
    
     printf("Enter current date(dd/mm/yyyy): ");
    fgets(d.cd, sizeof(d.cd), stdin);
    
	printf("Enter your nationality: ");
    fgets(d.nationality, sizeof(d.nationality), stdin);
 	
    printf("Enter your age: ");
    scanf("%d", &d.age);
    getchar();

    printf("Enter your gender (M/F): ");
    scanf(" %c", &d.gender);

   printf("enter adhar number:");
   scanf("%lld",&d.aadhar_no);

    if (fwrite(&d, sizeof(d), 1, fp) == 1) {
        printf("\nRegistration successful!\n");
    } else {
        printf("\nError: Unable to write data to file.\n");
    }

    fclose(fp);
}



void update() {
    FILE *fp = fopen("data", "rb+");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    long long aadhar_no;
    int found = 0;

    printf("Enter Aadhar no to update: ");
    scanf("%lld", &aadhar_no);

    if (!validate_aadhar(aadhar_no)) {
        printf("Invalid Aadhar Number. Please enter a valid 12-digit number.\n");
        fclose(fp);
        return;
    }

    while (fread(&d, sizeof(d), 1, fp)) {
        if (d.aadhar_no == aadhar_no) {
            found = 1;
            printf("Record found. Update the details:\n");

            printf("Enter new user name: ");
            getchar();
            fgets(d.name, sizeof(d.name), stdin);
           

            printf("Enter new father's/husband name: ");
            fgets(d.f_name, sizeof(d.f_name), stdin);
           

            printf("Enter new Address: ");
            fgets(d.add, sizeof(d.add), stdin);
            

            printf("Enter new landmark: ");
            fgets(d.lm, sizeof(d.lm), stdin);
            

            printf("Enter new district: ");
            fgets(d.dis, sizeof(d.dis), stdin);
            

            printf("Enter new state: ");
            fgets(d.st, sizeof(d.st), stdin);
            

            printf("Enter new pincode: ");
            scanf("%d", &d.pin);

            printf("Enter new phone no.: ");
            scanf("%ld", &d.phn);

            printf("Enter new date of birth (dd/mm/yyyy): ");
            getchar();
            fgets(d.dob, sizeof(d.dob), stdin);
            
             printf("Enter new current date(dd/mm/yyyy): ");
            fgets(d.ud, sizeof(d.ud), stdin);
    
            

            printf("Enter new age: ");
            scanf("%d", &d.age);

            printf("Enter new gender (M/F): ");
            scanf(" %c", &d.gender);

            fseek(fp,-sizeof(d), SEEK_CUR);
            fwrite(&d, sizeof(d), 1, fp);

            printf("Record updated successfully\n");
            break;
        }
    }

    if (!found) {
        printf("Record not found\n");
    }

    fclose(fp);
}

void display() {
    FILE *fp = fopen("data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }
    while (fread(&d, sizeof(d), 1, fp)) {	
        printf("Name: %s\nFather's Name: %s\nAddress: %s\nLandmark: %s\nDistrict: %s\nState: %s\nPincode: %d\nPhone: %ld\nDOB: %s\nREGISTRATION DATE:  %supdation date: %s\nAge: %d\nGender: %c\n :YOUR AADHAR NUMBER: \n\t\t   %lld\n\n", 
            d.name, d.f_name, d.add, d.lm, d.dis, d.st, d.pin, d.phn, d.dob,d.cd,d.ud, d.age, d.gender, d.aadhar_no);
           
    }

    fclose(fp);
}
void print_card() {
    FILE *fp = fopen("data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

   
    while (fread(&d, sizeof(d), 1, fp)) {
   	 printf("\n------------- GOVERNMENT OF INDIA -------------\n");
    printf("\n------- UNIQUE IDENTIFICATION AUTHORITY OF INDIA -------\n\n");
    	
        printf("Name: %s\nFather's Name: %s\nAddress: %s\nLandmark: %s\nDistrict: %s\nState: %s\nPincode: %d\nPhone: %ld\nDOB: %s\nREGISTRATION DATE:  %s\nAge: %d\nGender: %c\n  \t\t:YOUR AADHAR NUMBER: \n\t\t   %lld\n\n", 
            d.name, d.f_name, d.add, d.lm, d.dis, d.st, d.pin, d.phn, d.dob,d.cd, d.age, d.gender, d.aadhar_no);
        printf("\n----------------MERA ADHAR MERI PEHCHAN---------------\n");
		printf("---------------------------------------------------------------------------------\n");    
    }

    fclose(fp);
}

void remove_record() {
    FILE *fp = fopen("data", "rb");
    FILE *temp_fp = fopen("temp.data", "wb");

    if (fp == NULL || temp_fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    long long aadhar_no;
    int found = 0;

    printf("Enter Aadhar no to delete: ");
    scanf("%lld", &aadhar_no);

    while (fread(&d, sizeof(d), 1, fp)) {
        if (d.aadhar_no == aadhar_no) {
            found = 1;
            printf("Record with Aadhar no %lld deleted successfully\n", aadhar_no);
        } else {
            fwrite(&d, sizeof(d), 1, temp_fp);
        }
    }

    if (found=0) {
        printf("Record not found\n");
    }

    fclose(fp);
    fclose(temp_fp);

    remove("data");
    rename("temp.data", "data");
}

void count_records() {
    FILE *fp = fopen("data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    int count = 0;
    while (fread(&d, sizeof(d), 1, fp)) {
        count++;
    }

    printf("Total records: %d\n", count);

    fclose(fp);
}

void list_all_users() {
    FILE *fp = fopen("data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    printf("\n\t\t\t----------------LIST OF USERS------------------\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
     printf("NAME\t\t\t\tAADHAR NUMBER\t\t\tREGISTRATION DATE\n");
	printf("------------------------------------------------------------------------------------------------------\n");
    while (fread(&d, sizeof(d), 1, fp)) {
        printf("%s\t\t\t\t%lld\t\t\t\t%s\n---------------------------------------------------------------------------------------------------------", d.name, d.aadhar_no,d.cd);
    }

    fclose(fp);
}

void search_record() {
    FILE *fp = fopen("data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    long long aadhar_no;
    int found = 0;

    printf("Enter Aadhar no to search: ");
    scanf("%lld", &aadhar_no);

    while (fread(&d, sizeof(d), 1, fp)) {
        if (d.aadhar_no == aadhar_no) {
            printf("Record Found:\n");
            
            found = 1;
            break;
        }
    }

    if (found=0) {
        printf("Record not found\n");
    }

    fclose(fp);
}
