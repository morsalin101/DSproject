#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char name[20];
    int id;
    char fname[20];
    char mname[20];
}student;
typedef struct node
{
    int count;
    char date[15];
    int  roomid;
    student studentDetails;
    struct node *next;
}node;

int interface();
void roomAllocation();
void showAllRecords();
void searchRoom();
void saveToFile();
void readAndWrite();

node *head;



int main(){
   while(1){
   int choice = interface();
   if (choice == 1)
   {
    system("cls");
    student st;
    char name[20];
    printf("\t\t\t\tEnter Name:");
    scanf("%s",name);
    strcpy(st.name,name);
    printf("\t\t\t\tEnter Student ID:");
    scanf("%d",&st.id);
    fflush(stdin);
    printf("\t\t\t\tEnter Fathers Name:");
    scanf("%s",name);
    strcpy(st.fname,name);
    fflush(stdin);
    printf("\t\t\t\tEnter Mothers Name:");
    scanf("%s",name);
    strcpy(st.mname,name);
    roomAllocation(head,st);
    printf("\n\n\t\tPress enter to go Menu.....");
    getchar();
   }
  else if (choice == 2)
  {
    system("cls");
    printf("\t\t\t\tEnter ID:");
    int id;scanf("%d",&id);
    searchRoom(head,id);
    fflush(stdin);
    getchar();

  }
  else if (choice == 0)
  {
    system("cls");
    saveToFile(head);
    fflush(stdin);
    getchar();
  }
  else if(choice==4){

    showAllRecords(head);
  }
 else if(choice == 9){
    readAndWrite(head);
    fflush(stdin);
    getchar();
  }
   else if(choice==5){

    exit(0);
  }
  else
  {
    printf("\n\n\t\t\t\tWrong input\n");
    printf("\n\n\t\t\t\tpress any key to go main menu..\n");
    fflush(stdin);
    getchar();
  }
   }
}

int interface()
{

  int choice1;
  system("cls");
  printf("\n\n\t\t\t\t|---------------------------------------------|\n");
  printf("\t\t\t\t|          Hostel Management System          |\n");
  printf("\t\t\t\t|---------------------------------------------|\n");
  printf("\n\n\t\t\t\t1.Room Allocation\n");
  printf("\n\n\t\t\t\t2.Search Room\n");
  printf("\n\n\t\t\t\t3.Update Room Record\n\n");
  printf("\n\n\t\t\t\t4.Show All Room Records\n\n");
  printf("\n\n\t\t\t\t0.Save to File\n\n");
  printf("\n\n\t\t\t\t9.Read from file and write into linked List\n\n");
  printf("\n\n\t\t\t\t5.Exit\n\n");
  printf("\t\t\t\t-----------------------------------------------\n");
  printf("\t\t\t\tEnter to access:");
  scanf("%d", &choice1);
  return choice1;
}
void roomAllocation(node *nd,student info){
    printf("hello\n");
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->studentDetails = info;
    temp->next = NULL;
    printf("\t\t\t\tEnter Room ID:");
    scanf("%d",&temp->roomid);
    printf("\t\t\t\tEnter date:");
    char date[10];
    scanf("%s",date);
    strcpy(temp->date,date);
    if(head==NULL){
        head = temp;
    }
    else{
    while(nd->next!=NULL)
        nd=nd->next;
    nd->next = temp;
    }
   printf("\t\t\t\tRoom  %d is booked now ",temp->roomid);
   fflush(stdin);
   getchar();
}

void showAllRecords(node *nd){
      system("cls");
      printf("\n\n\t\t\t\t|---------------------------------------------|\n");
      printf("\t\t\t\t|          ALL ROOM RECORDS             |\n");
      printf("\t\t\t\t|---------------------------------------------|\n\n");
  printf("\tName\tId\tFathers Name\tMothers Name\tRoodID\tDate\n\n");
    printf("\t----\t--\t------------\t------------\t------\t----\n\n");
  node *t = nd;


  while( t != NULL ){
    printf("\t%s\t%d\t%s\t\t%s\t\t%d\t%s\n",t->studentDetails.name,t->studentDetails.id,t->studentDetails.fname,t->studentDetails.mname,t->roomid,t->date);
    t = t->next;
  }
 fflush(stdin);
 getchar();
}
void searchRoom(node *nd,int id){
      system("cls");
      printf("\n\n\t\t\t\t|---------------------------------------------|\n");
      printf("\t\t\t\t|              ROOM RECORDS             |\n");
      printf("\t\t\t\t|---------------------------------------------|\n\n");
  printf("\tName\tId\tFathers Name\tMothers Name\tRoodID\tDate\n\n");
  node *t = nd;
  while( t->next!=NULL){
    if(t->roomid == id){
      break;
    }
    t = t->next;
  }
  node *temp;
  temp = t;
  printf("\t%s\t%d\t%s\t\t%s\t\t%d\t%s\n",temp->studentDetails.name,temp->studentDetails.id,temp->studentDetails.fname,temp->studentDetails.mname,temp->roomid,temp->date);
 fflush(stdin);
 getchar();
}
void saveToFile(node *nd){
  FILE *fp = fopen("student.doc","w");

  while(nd != NULL){
    fwrite(nd,sizeof(node),1,fp);
    nd = nd -> next;
  }
fclose(fp);
printf("ALL DATA SAVED....\n");
getchar();
}
void readAndWrite(node *nd){
  system("cls");
   node n1;
   FILE *fp = fopen("student.doc","r");
while(fread(&n1,sizeof(node),1,fp)){
    if(nd == NULL){
    nd = (node*)malloc(sizeof(node));
    nd->count = n1.count;
    strcpy(nd->date,n1.date);
    nd->roomid = n1.roomid;
    nd->studentDetails = n1.studentDetails;
    nd->next = NULL;
    head = nd;
    }
    else{
    while(nd->next !=NULL) nd=nd->next;
     nd->next = (node*)malloc(sizeof(node));
     nd->next->count = n1.count;
     strcpy(nd->next->date,n1.date);
     nd->next->roomid = n1.roomid;
     nd->next->studentDetails = n1.studentDetails;
     nd->next->next = NULL;
    }
}
fclose(fp);
printf("LINKED LIST CREATED..\n");
getchar();
}

