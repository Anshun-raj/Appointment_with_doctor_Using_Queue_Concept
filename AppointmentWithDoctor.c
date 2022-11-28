#include<stdio.h>
#include<conio.h>
#include<string.h>
#define LINE 50

int a[LINE],front=-1,rear=-1,voter;
int count=0;
int cmp=0;
int arr[];

void enter();
void leave();
void show();

int main()
{
    printf("----DOCTOR CLINIC----\n");
    printf("Doctor's assistant gives a sheet of paper having some code on it for identification purpose to a patient\n who want to fix their appointment with the doctor:\n");
    printf("The code is of three digits\n");
    printf("press 1. to add or enter\n");
    printf("press 2. to remove or leave\n");
    printf("press 3. to show or display\n");
    printf("press 4. to exit\n");

    int ch;
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
          case 1:
              {
                enter();
                break;
              }

          case 2:
              {
                  leave();
                  break;
              }

          case 3:
              {
                  show();
                  break;
              }

          case 4:
              {
                  exit(0);
                  break;
              }

          default:
              printf("Wrong choice");
              break;

        }
    }
    return 0;
}


void enter()
{
    if(rear==LINE-1)
    {
        printf("Line is about to exceed the meeting room width");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("There is some space in the room so you can allow more patients to be in the line\n please enter a three digit no. between 101 to 150:");
        scanf("%d",&voter);
        if(voter==a[rear])
        {
            printf("This no. is already asigned");
            exit(0);
        }
        rear++;
        a[rear]=voter;
    }
}


void leave()
{

    if(front==-1 || front>rear)
    {
        printf("No meeting has not done yet or the waiting room is empty");
    }
    else
    {

        printf("patient meeting with the doctor is over so patient can leave the room\n",a[front]);
        front++;
        cmp=cmp+1;
    }
}


void show()
{
    int i;
    if(front==-1)
    {
        printf("No meeting has not done yet or the waiting room is empty");
    }
    else
    {
        printf("The patients who are about to meet the doctor are:-\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",a[i]);
            count=count+1;
        }
        printf("Total no. of patient who are about to meet the doctor are:-%d\n",count);
        printf("Total no. of patient who met the doctor are:-%d\n",cmp);
    }
}
