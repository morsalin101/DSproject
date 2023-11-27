#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define FULL 50
#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"

/*all structure*/
typedef struct student
{
    char name[20];
    int id;
    char fname[20];
    char mname[20];
} student;
typedef struct node
{
    int count;
    char date[15];
    int  roomid;
    student studentDetails;
    struct node *next;
} node;

typedef struct Node
{
    char name[20];
    int stuid;
    struct Node *next;
} laundry;

typedef struct Queue
{
    int count;
    laundry *front;
    laundry *rear;
} queue;
/*---------*/

/*For color*/
void red ()
{
    printf("\033[1;31m");
}

void reset ()
{
    printf("\033[0m");
}
/*--------------*/

int i=1;

/*function prototype*/
int interface();
void roomAllocation();
void showAllRecords();
void updateRoom();
void searchRoom();
void saveToFile();
void readAndWrite();
void del();

/*void interface2();
void initialize();
void isempty();
void enqueue();
void dequeue();
void display();
*/
/*---------------*/
node *head;


int main()
{
    int l=1;
    if(i==1)
    {
        readAndWrite(head);
        i--;
    }
    while(1)
    {
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
            printf("\t\t\t\tEnter RoomID:");
            int id;
            scanf("%d",&id);
            searchRoom(head,id);
            fflush(stdin);
            getchar();

        }
        else if (choice == 3)
        {
            int id;
            system("cls");
            printf("\t\t\t\tEnter RoomID:");
            scanf("%d",&id);
            updateRoom(head,id);
            fflush(stdin);
            getchar();
        }
        /* else if (choice == 5)
         {
           system("cls");
           saveToFile(head);
           fflush(stdin);
           getchar();
         }*/
        else if(choice==4)
        {

            showAllRecords(head);
        }
        /*else if(choice == 6){
           readAndWrite(head);
           fflush(stdin);
           getchar();
         }*/
        else if(choice == 5)
        {
            system("cls");
            printf("\n\n\t\t\t\tEnter RoomID:");
            int id;
            scanf("%d",&id);
            del(head,id);
            getchar();
        }
        else if(choice == 6)
        {
            system("cls");
            queue *q;
            q = malloc(sizeof(queue));
            initialize(q);
            if(l==1)
            {
                ReadAndWriteForQueue(q);
                l--;
            }
            while(1)
            {
                int choose = interface2();
                if (choose == 1)
                {
                    system("cls");
                    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
                    red();
                    printf("\t\t\t\t|          Enter Details                      |\n");
                    reset();
                    printf("\t\t\t\t|---------------------------------------------|\n");
                    laundry st;
                    char name[20];
                    printf("\t\t\t\tEnter Name:");
                    scanf("%s",name);
                    strcpy(st.name,name);
                    printf("\t\t\t\tEnter Student ID:");
                    scanf("%d",&st.stuid);
                    enqueue(q,st);
                    getchar();
                }
                else if(choose == 2)
                {
                    system("cls");
                    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
                    printf("\t\t\t\t|          ALL SERIALS                        |\n");
                    printf("\t\t\t\t|---------------------------------------------|\n\n");
                    printf("\t\t\t\tName\tStudentId\n\n");
                    printf("\t\t\t\t----\t-------\n\n");
                    display(q->front);
                    printf("\n\t\t\t\tPress Enter to get back.....");
                    fflush(stdin);
                    getchar();

                }
                else if(choose == 3)
                {
                    system("cls");
                    int s = dequeue(q);
                    printf("\n\n\t\t\t\t%d No Id serial  has released...",s);
                    fflush(stdin);
                    getchar();
                }
                else if(choose == 0)
                {
                    saveToFileForQueue(q->front);
                    main();
                }
                else
                {
                    printf("\n\n\t\t\t\tWrong input\n");
                    printf("\n\n\t\t\t\tpress any key to go main menu..\n");
                    fflush(stdin);
                    getchar();
                    return;
                }
            }
            getchar();
        }
        else if(choice==0)
        {
            saveToFile(head);
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
    red();
    printf("\t\t\t\t|          Hostel Management System           |\n");
    reset();
    printf("\t\t\t\t|---------------------------------------------|\n");
    printf("\n\t\t\t\t1.Room Allocation\n");
    printf("\n\t\t\t\t2.Search Room\n");
    printf("\n\t\t\t\t3.Update Room Record\n\n");
    printf("\n\t\t\t\t4.Show All Room Records\n\n");
// printf("\n\t\t\t\t5.Save to File\n\n");
    //printf("\n\t\t\t\t6.Read from file and write into linked List\n\n");
    printf("\n\t\t\t\t5.Delete Room Details\n\n");
    printf("\n\t\t\t\t6.Laundry System\n\n");
    printf("\n\t\t\t\t0.Exit\n\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\tEnter to access:");
    scanf("%d", &choice1);
    return choice1;
}
void roomAllocation(node *nd,student info)
{
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
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        while(nd->next!=NULL)
            nd=nd->next;
        nd->next = temp;
    }
    printf("\t\t\t\tRoom  %d is booked now..",temp->roomid);
    fflush(stdin);
    getchar();
}

void showAllRecords(node *nd)
{
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|          ALL ROOM RECORDS             |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\tName\tId\tFathers Name\tMothers Name\tRoodID\tDate\n\n");
    printf("\t----\t--\t------------\t------------\t------\t----\n\n");
    node *t = nd;


    while( t != NULL )
    {
        printf("\t%s\t%d\t%s\t%s\t\t%d\t%s\n",t->studentDetails.name,t->studentDetails.id,t->studentDetails.fname,t->studentDetails.mname,t->roomid,t->date);
        t = t->next;
    }
    fflush(stdin);
    getchar();
}
void searchRoom(node *nd,int id)
{
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|              ROOM RECORDS             |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\tName\tId\tFathers Name\tMothers Name\tRoodID\tDate\n\n");
    node *t = nd;
    int flag=0;
    while( t!=NULL)
    {
        if(t->roomid == id)
        {
            flag=1;
            break;
        }
        t = t->next;
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tWrong RoomID...");
        return;
    }
    else
    {
        node *temp;
        temp = t;
        printf("\t%s\t%d\t%s\t\t%s\t\t%d\t%s\n",temp->studentDetails.name,temp->studentDetails.id,temp->studentDetails.fname,temp->studentDetails.mname,temp->roomid,temp->date);
//fflush(stdin);
        getchar();
    }
}
void updateRoom(node *nd,int id)
{
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|              ROOM RECORDS             |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\t\tName\t\tId\t\tFathers Name\t\tMothers Name\t\tRoodID\t\tDate\n\n");
    node *t = nd;
    int flag=0;
    while(t!= NULL)
    {
        if(t->roomid==id)
        {
            flag=1;
            break;
        }
        t=t->next;
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tRoom Id is not valid");
        printf("\n\n\n\t\t\t\tplease enter to get  back");
        getchar();
        return;
    }
    else
    {
        printf("\t%s\t%d\t%s\t\t%s\t\t%d\t%s\n",t->studentDetails.name,t->studentDetails.id,t->studentDetails.fname,t->studentDetails.mname,t->roomid,t->date);
    }

    printf("\n\n\t\t\t\t.....Update Student Details.....");

    char name[20];
    printf("\n\t\t\t\tEnter Name:");
    scanf("%s",name);
    strcpy(t->studentDetails.name,name);
    printf("\n\t\t\t\tEnter Student ID:");
    scanf("%d",&t->studentDetails.id);
    fflush(stdin);
    printf("\n\t\t\t\tEnter Fathers Name:");
    scanf("%s",name);
    strcpy(t->studentDetails.fname,name);
    fflush(stdin);
    printf("\n\t\t\t\tEnter Mothers Name:");
    scanf("%s",name);
    strcpy(t->studentDetails.mname,name);
    fflush(stdin);
    printf("\n\t\t\t\tEnter date:");
    char date[10];
    scanf("%s",date);
    strcpy(t->date,date);
    printf("\n\t\t\t\tRoom Updated....");
    getchar();
}


void saveToFile(node *nd)
{
    FILE *fp = fopen("student.doc","w");

    while(nd != NULL)
    {
        fwrite(nd,sizeof(node),1,fp);
        nd = nd -> next;
    }
    fclose(fp);
    printf("\t\t\t\tALL DATA SAVED....\n");
    printf("\t\t\t\tPlease Enter to go back....\n");
    getchar();
}
void readAndWrite(node *nd)
{
    system("cls");
    node n1;
    FILE *fp = fopen("student.doc","r");
    while(fread(&n1,sizeof(node),1,fp))
    {
        if(nd == NULL)
        {
            nd = (node*)malloc(sizeof(node));
            nd->count = n1.count;
            strcpy(nd->date,n1.date);
            nd->roomid = n1.roomid;
            nd->studentDetails = n1.studentDetails;
            nd->next = NULL;
            head = nd;
        }
        else
        {
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
    printf("\t\t\t\tLINKED LIST CREATED...\n");
}

void del(node *nd,int id)
{

    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    printf("\t\t\t\t|              ROOM RECORDS             |\n");
    printf("\t\t\t\t|---------------------------------------------|\n\n");
    printf("\tName\tId\tFathers Name\tMothers Name\tRoodID\tDate\n\n");
    node *t = nd;
    int flag=0;
    int count=0;
    while(t!= NULL)
    {
        if(t->roomid==id)
        {

            flag=1;
            break;
        }
        count++;
        t=t->next;
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tRoom Id is not valid");
        printf("\n\n\n\t\t\t\tplease enter to get  back");
        getchar();
        return;
    }
    else
    {
        printf("\t%s\t%d\t%s\t\t%s\t\t%d\t%s\n",t->studentDetails.name,t->studentDetails.id,t->studentDetails.fname,t->studentDetails.mname,t->roomid,t->date);
    }


    printf("\n\n\t\t\t\t.....Are you sure to delete this room  details(Y/N)?");
    printf("\n\t\t\t\tEnter Choice:");
    char ch;
//printf("\n\n\ncount %d",count);
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='Y' || ch=='y')
    {
        if(count==0)
        {

            node *temp = nd;
            head = nd->next;
            free(temp);
            printf("\n\t\t\t\tRoom Details Deleted successfull..");
            getchar();
        }
        else
        {
            node *t = nd;
            while(t->next->roomid!=id)
            {
                t=t->next;
            }
            node *temp = t;
            temp = t->next;
            t->next = temp->next;
            free(temp);
            printf("\n\t\t\t\tRoom Details Deleted successfull..");
            getchar();
        }
    }
    else if(ch=='N' || ch=='n')
    {
        return;
    }
    else
    {
        printf("\n\t\t\t\tWrong input...");
        getchar();
    }

}


/*implementing Queue process*/
int interface2()
{

    int choice2;
    system("cls");
    printf("\n\n\t\t\t\t|---------------------------------------------|\n");
    red();
    printf("\t\t\t\t|          Laundry System                     |\n");
    reset();
    printf("\t\t\t\t|---------------------------------------------|\n");
    printf("\n\t\t\t\t1.Add Student serial\n");
    printf("\n\t\t\t\t2.Show All Serial\n");
    printf("\n\t\t\t\t3.Released \n\n");
    printf("\n\t\t\t\t0.Back to main menu\n\n");
    printf("\t\t\t\t-----------------------------------------------\n");
    printf("\t\t\t\tEnter to access:");
    scanf("%d", &choice2);
    return choice2;
}
void initialize(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q)
{
    return (q->rear == NULL);
}

void enqueue(queue *q,laundry stu)
{
    if (q->count < FULL)
    {
        laundry *tmp;
        tmp = malloc(sizeof(laundry));
        tmp->stuid = stu.stuid;
        strcpy(tmp->name,stu.name);
        tmp->next = NULL;
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
        printf("\t\t\t\tAdded.....");
        getchar();
    }
    else
    {
        printf("Laundry is full\n");
    }
}


int dequeue(queue *q)
{
    laundry *tmp;
    int n = q->front->stuid;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void display(laundry *head)
{

    if(head == NULL)
    {
        printf("\t\t\t\t----------------\n");
    }
    else
    {

        printf("\t\t\t\t%s \t%d\n",head -> name,head->stuid);
        display(head->next);

    }

    //getchar();
}

void saveToFileForQueue(laundry *nd)
{

    FILE *fp = fopen("laundry.doc","w");
    laundry *t=nd;
    while(t != NULL)
    {
        fwrite(t,sizeof(laundry),1,fp);
        t = t -> next;
    }
    fclose(fp);
    printf("\t\t\t\tALL DATA SAVED....\n");
    printf("\t\t\t\tPlease Enter to go back....\n");
//getchar();

}

void ReadAndWriteForQueue(queue *nd)
{
    laundry n1;
    queue *t = nd;
    FILE *fp = fopen("laundry.doc","r");
    while(fread(&n1,sizeof(laundry),1,fp))
    {
        if (nd->count < FULL)
        {
            laundry *tmp;
            tmp = malloc(sizeof(laundry));
            tmp->stuid = n1.stuid;
            strcpy(tmp->name,n1.name);
            tmp->next = NULL;
            if(!isempty(t))
            {
                t->rear->next = tmp;
                t->rear = tmp;
            }
            else
            {
                t->front = nd->rear = tmp;
            }
            t->count++;
            //printf("\t\t\t\tAdded.....");
            //getchar();
        }
    }
    fclose(fp);
//getchar();
}


/*------------*/

