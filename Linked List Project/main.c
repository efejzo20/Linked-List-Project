#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THESIS_CON 2.8
#define REPEAT(n) int i; for(i=0;i<n;i++)
#define CALCAVG(S)  ((float)(S.GPA[0]+S.GPA[1]+S.GPA[2])/3.0);
#define PRINTCOND(M) (M==1 ?  "are" : "are NOT" )

struct Student
{
    char name[25];
    char surname[25];
    char dep[5];
    float GPA[3];
    float CGPA;
    int status;
    struct Student *next;
};

typedef struct Student stdNode;
typedef struct Student *stdNodePtr;
typedef struct Student **stdNodePtrPtr; /// This type can be used in readFromTheFile method.

void addNode(stdNodePtr *first, stdNodePtr *last, stdNode S);

void readFromTheFile(const char inputFileName[], stdNodePtr *first, stdNodePtr *last);
void writeToFile(const char outputFileName[], stdNodePtr first, const char dep[], int mode);

void printList(stdNodePtr first);
void printListWithCond(stdNodePtr first, const char dep[], int mode);

int getSize(stdNodePtr first);

int main(int argc, char *argv[])
{
    /*
    DO NOT CHANGE THE MAIN METHOD
    ENABLE ONLY ONE SECTION AT A TIME
    */


/// ================= SECTION 1 =================
#if 0

    stdNodePtr first=NULL, last=NULL;
    stdNode S; /// Temporary Node
    char inputFileName[] = "input.txt";
    int n;

    FILE *infile;
    infile=fopen(inputFileName,"r");

    if(infile==NULL)
    {
        printf("The file: %s was not opened!",inputFileName);
        exit(-1);
    }

    fscanf(infile,"%d",&n);

    REPEAT(n)
    {
        fscanf(infile,"%s%s%s%f%f%f",S.name,S.surname,S.dep,
               &S.GPA[0],&S.GPA[1],&S.GPA[2]);
        S.CGPA=CALCAVG(S);
        if(S.CGPA >= THESIS_CON)
            S.status=1;
        else
            S.status=0;
        addNode(&first,&last,S);
    }

    fclose(infile);

    printList(first);


#endif // 1



/// ================= SECTION 2 =================
#if 0
    stdNodePtr first=NULL, last=NULL;
    char inputFileName[]="input.txt";

    readFromTheFile(inputFileName,&first,&last);
    printList(first);


#endif // 0


/// ================= SECTION 3 =================
#if 1

    stdNodePtr first=NULL, last=NULL;
    char inputFileName[]="input.txt";
    char dep[10] = "CEN";
    int mode = 1;

    readFromTheFile(inputFileName,&first,&last);
    printListWithCond(first,dep,mode);


#endif // 0


/// ================= SECTION 4 =================
#if 0

    stdNodePtr first=NULL, last=NULL;
    char inputFileName[]="input.txt";
    char outputFileName[]="output.txt";
    char dep[10] = "BINF";
    int mode = 1;

    readFromTheFile(inputFileName,&first,&last);
    printListWithCond(first,dep,mode);
    writeToFile(outputFileName,first,dep,mode);


#endif // 0



/// ================= SECTION 5 =================
#if 0

    stdNodePtr first=NULL, last=NULL;

    if(argc<5)
    {
        printf("\nMissing input arguments.\n");
        printf("Please provide the arguments as follows:\n");
        printf("FinalProject.exe input.txt output.txt CEN 1\n");
        return 0;
    }

    char inputFileName[50];
    char outputFileName [50] ;
    char dep[10] ;
    int mode = 0;

    strcpy(inputFileName,argv[1]);
    strcpy(outputFileName,argv[2]);
    strcpy(dep,argv[3]);
    mode = atoi(argv[4]);

    readFromTheFile(inputFileName,&first,&last);
    //printList(first);
    printListWithCond(first,dep,mode);
    writeToFile(outputFileName,first,dep,mode);



#endif // 1

    return 0;
}


void printList(stdNodePtr first)
{
    stdNodePtr temp=first;
    if(temp==NULL)
    {
        printf("The list is empty!\n");
        return ;
    }
    while(temp!=NULL)
    {
        //if((strcmp(temp->dep,dep)==0)&& (temp->status==mode))
        printf("%s %s %s %d %.2f\n",temp->name,temp->surname,temp->dep,temp->status,temp->CGPA);
        temp=temp->next;
    }
}

void printListWithCond(stdNodePtr first, const char dep[], int mode)
{
    stdNodePtr temp=first;
    if(temp==NULL)
    {
        printf("The list is empty!\n");
        return ;
    }
    printf("\nThe list of students from %s department that %s able to take the thesis:\n",dep,PRINTCOND(mode));
    while(temp!=NULL)
    {
        if((strcmp(temp->dep,dep)==0)&& (temp->status==mode))
            printf("%s %s %s %d %.2f\n",temp->name,temp->surname,temp->dep,temp->status,temp->CGPA);
        temp=temp->next;
    }
}

void writeToFile(const char outputFileName[], stdNodePtr first, const char dep[], int mode)
{
    FILE *fout=fopen(outputFileName,"w");
    if(fout==NULL)
    {
        printf("Unable to open the %s file.",outputFileName);
        exit(2);
    }
    stdNodePtr temp=first;
    while(temp!=NULL)
    {
        if((strcmp(temp->dep,dep)==0)&& (temp->status==mode))
            fprintf(fout,"%s %s %s %d %.2f\n",temp->name,temp->surname,temp->dep,temp->status,temp->CGPA);
        temp=temp->next;
    }
    fclose(fout);
}


void readFromTheFile(const char inputFileName[], stdNodePtr *first, stdNodePtr *last)
{
    int n;
    stdNode S;  //temporary Node
    FILE *infile=NULL;

    infile=fopen(inputFileName,"r");
    if(infile==NULL)
    {
        printf("The file: %s was not opened!",inputFileName);
        exit(-1);
    }

    fscanf(infile,"%d",&n);

    REPEAT(n)
    {
        fscanf(infile,"%s%s%s%f%f%f",S.name,S.surname,S.dep,
               &S.GPA[0],&S.GPA[1],&S.GPA[2]);
        S.CGPA=CALCAVG(S);
        if(S.CGPA >= THESIS_CON)
            S.status=1;
        else
            S.status=0;
        addNode(&(*first),&(*last),S);
    }

    fclose(infile);

}



void addNode(stdNodePtr *first, stdNodePtr *last,stdNode S)
{
    stdNodePtr new ;
    stdNodePtr curr, prev;
    new=(stdNodePtr)malloc(sizeof(stdNode));

    strcpy(new->name,S.name);
    strcpy(new->surname,S.surname);
    strcpy(new->dep,S.dep);

    new->GPA[0]=S.GPA[0];
    new->GPA[1]=S.GPA[1];
    new->GPA[2]=S.GPA[2];
    new->CGPA=S.CGPA;

    new->status=S.status;
    new->next=NULL;

    if((*first)==NULL)
    {
        (*first)=new;
        (*last)=new;
    }
    else if(S.CGPA >= (*first)->CGPA) /// At the from
    {
        new->next=(*first);
        (*first)=new;
    }
    else if(S.CGPA <= (*last)->CGPA) /// At the end
    {
        (*last)->next=new;
        (*last)=new;
    }
    else /// Middle
    {
        curr = *first;

        while( curr-> CGPA > S.CGPA)
        {
            prev=curr;
            curr=curr->next;
        }

        {
            prev->next=new;
            new->next=curr;
        }
    }
}

int getSize(stdNodePtr first)
{
    int size=0;
    stdNodePtr tmp=first;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        ++size;
    }
    return size;
}
