
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void registration();

// Struct to hold user data
struct data {
    long long aadhar_no,mob_no;
    char name[10], add[20],  lm[20], dis[20], st[20], nationality[20], dob[20];
    char f_name[10];
    int age;
    int pin;
    char gender;
    
    
} d;


int main() {
    int ch;

    while(1) {
        printf("\n");
        printf("\n\t\tWELCOME TO MY AADHAR SERVICE\n");
        printf("\n   --------------------------------------------------             \n");
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
            case 2: login();
			     break;
			case 3: update();
			     break;
			//case 4: print();
			//      break;
		//	case 5: search();
		//	      break;
		//	case 6: exit(0);
		//	break;
             
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
    printf("Enter the user name: ");
    scanf("%s ", d.name);
    getchar(); // To consume the newline character

    printf("Enter the father's name: ");
    scanf("%s ", d.f_name);
    getchar(); 

    printf("Enter your Address: ");
    fgets(d.add, sizeof(d.add), stdin);//scanf("%s ", d.address);
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
    scanf("%ld",&d.aadhar_no);
    getchar();


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
		fseek(fp,sizeof(struct data),1);
		 while(fread(&d,-sizeof(struct data),1,fp)>0 && x==0){
        if(aadhar==d.aadhar_no){
            x=1;
            printf("\tRECOURD found successfully Now Doing update .... !\n");
            printf("\taadharno\tName\tfathername\tmob_no\tAddress\tDistrict\tstate\tlandmark\tpincode\tdob\tnationality\tage\tgender\n");
            printf("\t%ld\t%s\t%s\t%ld\t%s\t%s\t%s\t%s\t%d\t%s\t%s\t%d\t%c\n",&d.aadhar_no,d.name,d.f_name,&d.mob_no,d.add,d.dis,d.st,d.lm,&d.pin,d.dob,d.nationality,&d.age,&d.gender);
            printf("\n\t---update recored-----");
             printf("\t\nupdate name ");
    scanf("%s",d.name);
    getchar();
    printf("\t\nupdate father name: ");
    scanf("%s",d.f_name);
    
    printf("\t\nupdate mobile number: ");
    scanf("%ld",&d.mob_no);
    
    printf("\t\nupdate address: ");
    scanf("%s",d.add);
    
    printf("\t\nupdate district : ");
    scanf("%s",d.dis);
    
    printf("\t\nupdate state: ");
    scanf("%s",d.st);
    
     printf("\t\nupdate landmark: ");
     scanf("%s",d.lm);
     
     printf("\t\nupdate pincode: ");
     scanf("%d",&d.pin);
     
     printf("\t\nupdate date of birth: ");
     scanf("%s",d.dob);
     
     printf("\t\nupdate nationality: ");
     scanf("%s",d.nationality);
     
     printf("\t\nupdate age: ");
     scanf("%d",&d.age);
     
     printf("\t\nupdate gender: ");
     scanf("%d",&d.gender);
    
    fwrite(&d,sizeof(struct data),1,fp);
    printf("\t\nupdate recorded successfully...!\n");
        }

    }}
    if(x==0){
        printf("\trecord not found :) ..!\n");
    }
    fclose(fp);
     
}


