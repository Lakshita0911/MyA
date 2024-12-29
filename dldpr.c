
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data {
    long long aadhar_no;
    char name[50], add[100], lm[50], dis[50], st[50], nationality[20], dob[20];
    char f_name[50];
    int age, pin;
    long phn;
    char gender;
} d;

void registration();
void login();
void update();
void display();
void remove_record();
void count_records();
void list_all_users();
void search_record();
int validate_aadhar(long long aadhar_no);
long long generate_aadhar();

int main() {
    int ch;

    while (1) {
        printf("\n\t\tWELCOME TO MY AADHAR SERVICE\n");
        printf("1. REGISTRATION\n2. LOGIN\n3. UPDATE\n4. DISPLAY\n5. REMOVE\n6. SEARCH\n7. LIST ALL USERS\n8. COUNT RECORDS\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1:
                registration();
                break;
            case 2:
                login();
                break;
            case 3:
                update();
                break;
            case 4:
                display();
                break;
            case 5:
                remove_record();
                break;
            case 6:
                search_record();
                break;
            case 7:
                list_all_users();
                break;
            case 8:
                count_records();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

long long generate_aadhar() {
    srand(time(0));
    long long aadhar = 100000000000LL + rand() % 900000000000LL;
    return aadhar;
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
    FILE *fp = fopen("user.data", "ab+");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    printf("Enter the user name: ");
    fgets(d.name, sizeof(d.name), stdin);


    printf("Enter the father's name: ");
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
    

    printf("Enter your nationality: ");
    fgets(d.nationality, sizeof(d.nationality), stdin);
    

    printf("Enter your age: ");
    scanf("%d", &d.age);
    getchar();

    printf("Enter your gender (M/F): ");
    scanf(" %c", &d.gender);

    d.aadhar_no = generate_aadhar();
    printf("Aadhar no generated: %lld\n", d.aadhar_no);

    if (fwrite(&d, sizeof(d), 1, fp) == 1) {
        printf("\nRegistration successful!\n");
    } else {
        printf("\nError: Unable to write data to file.\n");
    }

    fclose(fp);
}

void login() {
    FILE *fp = fopen("user.data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    char input_username[50];
    long input_phn;
    int found = 0;

    printf("Enter user name: ");
    fgets(input_username, sizeof(input_username), stdin);
    

    printf("Enter phone no: ");
    scanf("%ld", &input_phn);

    while (fread(&d, sizeof(d), 1, fp)) {
        if (strcmp(input_username, d.name) == 0 && input_phn == d.phn) {
            printf("Login successful\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("User not found or incorrect details\n");
    }

    fclose(fp);
}

void update() {
    FILE *fp = fopen("user.data", "rb+");
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
           

            printf("Enter new father's name: ");
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
            

            printf("Enter new age: ");
            scanf("%d", &d.age);

            printf("Enter new gender (M/F): ");
            scanf(" %c", &d.gender);

            fseek(fp, -sizeof(d), SEEK_CUR);
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
    FILE *fp = fopen("user.data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

   
    while (fread(&d, sizeof(d), 1, fp)) {
   	 printf("\n------------- GOVERNMENT OF INDIA -------------\n");
    printf("\n------- UNIQUE IDENTIFICATION AUTHORITY OF INDIA -------\n\n");
    	
        printf("Name: %s\nFather's Name: %s\nAddress: %s\nLandmark: %s\nDistrict: %s\nState: %s\nPincode: %d\nPhone: %ld\nDOB: %s\nAge: %d\nGender: %c\n  \t\t:YOUR AADHAR NUMBER: \n\t\t   %lld\n\n", 
            d.name, d.f_name, d.add, d.lm, d.dis, d.st, d.pin, d.phn, d.dob, d.age, d.gender, d.aadhar_no);
        printf("\n----------------THANKYOU FOR VISITING---------------\n");
		printf("---------------------------------------------------------------------------------\n");    
    }

    fclose(fp);
}

void remove_record() {
    FILE *fp = fopen("user.data", "rb");
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

    remove("user.data");
    rename("temp.data", "user.data");
}

void count_records() {
    FILE *fp = fopen("user.data", "rb");
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
    FILE *fp = fopen("user.data", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }

    printf("\n------- List of Users -------\n");
    while (fread(&d, sizeof(d), 1, fp)) {
        printf("Name: %s, Aadhar No: %lld\n", d.name, d.aadhar_no);
    }

    fclose(fp);
}

void search_record() {
    FILE *fp = fopen("user.data", "rb");
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
            printf("Name: %s\nFather's Name: %s\nAddress: %s\nLandmark: %s\nDistrict: %s\nState: %s\nPincode: %d\nPhone: %ld\nDOB: %s\nAge: %d\nGender: %c\nAadhar No: %lld\n\n", 
                d.name, d.f_name, d.add, d.lm, d.dis, d.st, d.pin, d.phn, d.dob, d.age, d.gender, d.aadhar_no);
            found = 1;
            break;
        }
    }

    if (found=0) {
        printf("Record not found\n");
    }

    fclose(fp);
}
