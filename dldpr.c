#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

void registration();

// Struct to hold user data
struct data {
    long long aadhar_no;
	long long  mob_no;
    char name[10], address[20],  lm[20], dis[20], st[20], email[30], nationality[20], dob[20];
    char fatherN[10];
    int age;
    int pin;
    char gender;
    
    
} d;


int main() {
    int ch;

    while(1) {
        printf("\n\t-------------------------------------------\n");
        printf("\n\t\tWELCOME TO MY AADHAR SERVICE\n");
        printf("                                          \n");
        printf("1. REGISTRATION\n2. LOGIN\n3. UPDATE\n4. PRINT\n5. SEARCH\n6. Exit");
        //printf("\n%d\n",rand());
        printf("\nEnter your choice: ");   
        scanf("%d", &ch);
        getchar();  // To consume any leftover newline character from the input buffer

        switch(ch) {
            case 1: 
                registration(); 
                break;
            case 6: 
                exit(0);
                break;
            default: 
                printf("Invalid choice\n");
                break;
        }
    }
}

void registration() 
{
	
    FILE *fp;
    fp = fopen("user.data", "ab+");  // Open the file in append-binary mode

    if (fp == NULL) {
        printf("Error: Cannot open the file\n");
        return;
    }
    //srand(time(0000000000000));
    //printf("\nAadhar generated = %d\n",rand());// Get user details
    printf("Enter the user name: ");
    scanf("%s ", d.name);
    getchar(); // To consume the newline character

    printf("Enter the father's name: ");
    scanf("%s ", d.fatherN);
    getchar(); 

    printf("Enter your Address: ");
    fgets(d.address, sizeof(d.address), stdin);//scanf("%s ", d.address);
    getchar();

    printf("Enter any landmark: ");
    fgets(d.lm, sizeof(d.lm), stdin);//scanf("%c ", d.lm); 
    getchar();

    printf("Enter district: ");
    fgets(d.dis, sizeof(d.dis), stdin);//scanf("%s ", d.dis);
    getchar();

    printf("Enter the state: ");
    fgets(d.st, sizeof(d.st), stdin);//scanf("%s", d.st);
    getchar(); 

    printf("Enter pincode: ");
    fgets(d.st, sizeof(d.st), stdin);//scanf("%d", &d.pin);
    getchar(); // To consume the newline character

    printf("Enter phone no.: ");
    scanf("%ld", &d.mob_no);
    getchar(); // To consume the newline character

    printf("Enter your date of birth (dd/mm/yyyy): ");
    fgets(d.dob, sizeof(d.dob), stdin);//scanf("%s", d.dob);
    getchar(); // To consume the newline character

    printf("Enter your nationality: ");
    fgets(d.nationality, sizeof(d.nationality), stdin);//scanf("%s", d.nationality);
    getchar(); // To consume the newline character

    printf("Enter your age: ");
    scanf("%d", &d.age);
    getchar(); // To consume the newline character

    printf("Enter your gender (M/F): ");
    scanf("%c", &d.gender);  // Gender input
    printf("enter adhar number:");
    scanf("%d",&d.adhar_no);
    getchar();
    
    //srand(time(0000000000000));
    //printf("\nAadhar generated = %d\n",rand()); 
    //scanf("%d",&adhar_no);

    // Save user details to the file
    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);  // Close the file after writing

    printf("\nRegistration successful!\n");
}

void update()
{
	FILE *fp;
	int aadhar,x=0;
	fp = fopen("user.data","rb+");
	printf("\n\t Enter aadhar num you want to search:");
	scanf("%d",&aadhar);
	if (fp==NULL)
	{
		printf("\n file not found\n");
	}
	else
	{
		fseek(fp,-sizeof(struct data),1);
		 while(fread(&s,sizeof(struct data),1,fp)>0 && x==0){
        if(aadhar==d.adhar_no){
            x=1;
            printf("\tRECOURD found successfully Now Doing update .... !\n");
            printf("\taadharno\tName\tfathername\tmob_no\tAddress\tDistrict\tstate\tlandmark\tpincode\tdob\tnationality\tage\tgender\n");
            printf("\t%ld\t%s\t%ld\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%d\t%c\n",d.aadhar_no,d.name,d.f_name,d.aadhar_no,&mob_no,d.address,,s.marks,s.grade);
            printf("\n\t---update recored-----");
             printf("\t\nupdate Roll Number: ");
    scanf("%d",&aadhar_no);
    getchar();
    printf("\t\nupdate Class Section: ");
    scanf("%c",&s.sec);
    printf("\t\nupdate Name: ");
    scanf("%s",s.name);
    printf("\t\nupdate Markes: ");
    scanf("%d",&s.marks);
    printf("\t\nupdate Grades: ");
    scanf("%f",&s.grade);
    
    fwrite(&s,sizeof(struct student),1,fp);
    printf("\t\nupdate recored successfully...!\n");
        }

    }}
    if(x==0){
        printf("\trecord not found :) ..!\n");
    }
    fclose(fp);
     
}
}
