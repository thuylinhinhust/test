#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
	int ID;
	char name[100];
	double grade;
	struct Student *next;
};

typedef struct Student *StudentList;

StudentList init(StudentList &H){
	H=NULL;
	return H;
}

void addStudent(StudentList &H){
	int ID;
	char name[100];
	double grade;
	
	printf("Enter Student ID: ");
	scanf("%d",&ID);
	
	printf("Enter Student name: ");
	scanf("%s",name);
	
	printf("Enter Student grade: ");
	scanf("%lf",&grade);
	
	StudentList p = (StudentList) malloc(sizeof(struct Student));
	p->ID=ID;
	strcpy(p->name,name);
	p->grade=grade;
	p->next=NULL;
	
	if(H==NULL){
		H=p;
	}	
	else{
		StudentList q = H;
		while(q->next != NULL){
			q=q->next;
		}
		q->next=p;
	}
}

void insert(StudentList &H){
	int ID;
	char name[100];
	double grade;
	
	printf("Enter Student ID: ");
	scanf("%d",&ID);
	
	printf("Enter Student name: ");
	scanf("%s",name);
	
	printf("Enter Student grade: ");
	scanf("%lf",&grade);

	StudentList p = (StudentList) malloc(sizeof(struct Student));
	p->ID=ID;
	strcpy(p->name,name);
	p->grade=grade;
	p->next=H;
	H=p;	
}

int count(StudentList H){
	int count=0;
	while(H != NULL){
		H=H->next;
		count++;
	}
	return count;
}
void insert2(StudentList &H){
	int position;
	int n=count(H);
	int i;
	printf("Enter Position you want Insert: ");
	scanf("%d",&position);
	
	if(position==1){
		insert(H);
	}
	else if(position==n+1){
		addStudent(H);
	}
	else if(position>n+1){
		printf("Index Out Of Bounds");
	}
	else if(position>1){
		int ID;
		char name[100];
		double grade;
		
		printf("Enter Student ID: ");
		scanf("%d",&ID);
		
		printf("Enter Student name: ");
		scanf("%s",name);
		
		printf("Enter Student grade: ");
		scanf("%lf",&grade);
		
		for(i=1; i<position-1; i++){
			H=H->next;
		}
	
		StudentList p = (StudentList) malloc(sizeof(struct Student));
		p->ID=ID;
		strcpy(p->name,name);
		p->grade=grade;
		p->next=H->next;
		H->next=p;	
	}
}

void update(StudentList &H){
	int position, i;
	int n=count(H);
	printf("Enter Position you want Update grade: ");
	scanf("%d",&position);
	
	if(position>n){
		printf("Index Out Of Bounds");
	}
	else if(position>0){
		double grade;
		
		for(i=1; i<position; i++){
			H=H->next;
		}
		printf("Enter New grade: ");
		scanf("%lf",&(H->grade));
		
		printf("Update Successfully");
	}	
}

void deletebyPos (StudentList &H){
	int position, i;
	int n=count(H);
	
	printf("Enter Position you want Delete: ");
	scanf("%d",&position);
	
	if(position>n){
		printf("Index Out Of Bounds");
	}
	else if(position==1){
		StudentList p=H;
		H=H->next;
		free(p);
	}
	else if(position>0){
		for(i=1; i<position-1; i++){
			H=H->next;
		}
		StudentList p=H->next;
		H->next=p->next;
		free(p);
	}	
}

void search (StudentList &H){
	int position, i;
	int n=count(H);
	
	printf("Enter Position you want Search: ");
	scanf("%d",&position);
	
	if(position>n){
		printf("Index Out Of Bounds");
	}
	else if(position>0){
		for(i=1; i<position; i++){
			H=H->next;
		}
		printf("%-10d%-20s%.2lf\n", H->ID, H->name, H->grade);
	}	
}

void write(StudentList H) {
    FILE *fp = fopen("Student.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    StudentList temp = H;
    while (temp != NULL) {
        fprintf(fp, "%d %s %.2lf\n", temp->ID, temp->name, temp->grade);
        temp = temp->next;
    }
    fclose(fp);
    printf("Write to file successfully\n");
}

void read(StudentList &H) {
    FILE *fp = fopen("Student.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int ID;
    char name[100];
    double grade;
    while (fscanf(fp, "%d %s %lf", &ID, name, &grade) == 3) {
        StudentList p = (StudentList)malloc(sizeof(Student));
        p->ID = ID;
        strcpy(p->name, name);
        p->grade = grade;
        p->next = NULL;
        
        if (H == NULL) {
            H = p;
        } else {
            StudentList q = H;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
    }
    fclose(fp);
    printf("Read from file successfully\n");
}

void sort(StudentList &H){
	StudentList i,j;
	int temp_ID;
	char temp_name[100];
	double temp_grade;
	
	for(i=H; i->next != NULL; i=i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if(i->grade<j->grade){
				temp_ID=i->ID;
				i->ID=j->ID;
				j->ID=temp_ID;
				
				strcpy(temp_name, i->name);
				strcpy(i->name, j->name);
				strcpy(j->name, temp_name);
				
				temp_grade=i->grade;
				i->grade=j->grade;
				j->grade=temp_grade;
			}
		}
	}
}

void display(StudentList H) {
    printf("%-10s%-20s%-10s\n", "ID", "Name", "Grade");
    while (H != NULL) {
        printf("%-10d%-20s%.2lf\n", H->ID, H->name, H->grade);
        H = H->next;
    }
}


/*void display(StudentList H){
	printf("%-20s%-20s%s\n","Student ID", "Name", "Grade");
	//int count =1;
	while(H != NULL){
		//if (count == n){
			printf("%-20d%-20s%.2lf\n",H->ID, H->name, H->grade);
			//break;
		//}
		H=H->next;
		//count++;
	}                                    
}*/

int main(){
	StudentList H;
	init(H);
	
	int choice;
	do{
		system("cls");
		printf("1. ADD STUDENT\n");
		printf("2. DISPLAY\n");
		printf("3. INSERT AT FIRST\n");
		printf("4. INSERT AT ANY POSITION\n");
		printf("5. UPDATE GRADE\n");
		printf("6. DELETE\n");
		printf("7. WRITE LIST TO FILE\n");
		printf("8. READ FROM FILE TO LIST\n");
		printf("9. SEARCH BY POSITION\n");
		printf("10. SELECTION SORTING\n");
		printf("0. EXIT\n");
		printf("Enter Your Choice: ");
		scanf("%d",&choice);
		switch (choice){
			case 1: addStudent(H); break;
			case 2: display(H); break;
			case 3: insert(H); break;
			case 4: insert2(H); break;
			case 5: update(H); break;
			case 6: deletebyPos(H); break;
			case 7: write(H); break;
			case 8: read(H); break;
			case 9: search(H); break;
			case 10: sort(H); break;
			case 0: printf("Thank You");
		}
		printf("\n\n");
		system("pause");
	}
	while(choice!=0);
}









