#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct Date
{
    int dd;
    int mm;
    int yy;
};

struct Date date;

struct Remainder
{
    int dd;
    int mm;
    char note[50];
};

struct Remainder R;

COORD xy = {0, 0};

void gotoxy (int x, int y)
{
        xy.X = x; xy.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

int check_leapYear(int year)
{
    //checks whether the year passed is leap year or not
    if(year % 400 == 0 || (year % 100!=0 && year % 4 ==0))
       return 1;
    return 0;
}

int day1(int mm)
{
    switch(mm)
    {
        case 1:
            return 6;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 6;
            break;
        case 5:
            return 1;
            break;
        case 6:
            return 4;
            break;
        case 7:
            return 6;
            break;
        case 8:
            return 2;
            break;
        case 9:
            return 5;
            break;
        case 10:
            return 7;
            break;
        case 11:
            return 3;
            break;
        case 12:
            return 5;
            break;
    }
}


void print_date(int mm, int yy){ //prints the name of month and year
    printf("---------------------------\n");
    gotoxy(26,6);
    switch(mm){
        case 1: printf("January"); break;
        case 2: printf("February"); break;
        case 3: printf("March"); break;
        case 4: printf("April"); break;
        case 5: printf("May"); break;
        case 6: printf("June"); break;
        case 7: printf("July"); break;
        case 8: printf("August"); break;
        case 9: printf("September"); break;
        case 10: printf("October"); break;
        case 11: printf("November"); break;
        case 12: printf("December"); break;
    }
    printf(" , %d", yy);
    gotoxy(20,7);
    printf("---------------------------");
}

int getNumberOfDays(int month,int year)
{
    //returns the number of days in given month
    switch(month)
    {                          //and year
      case 1 : return(31);
      case 2 : if(check_leapYear(year)==1)
                    return(29);
               else
                    return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}


int week_day(int mm, int year)
{
    int day=day1(mm);
    int y=1600;
    while(y<year)
    {
        if(mm>2)
        {
            y++;
            if(check_leapYear(y))
            {
                day+=2;
            }
            else
            {
                day+=1;
            }
            if(day>7)
                day=day%7;
        }
        else
        {
            y++;
            if(check_leapYear(y-1))
            {
                day=day+2;
            }
            else
            {
                day=day+1;
            }
            if(day>7)
                day=day%7;
        }

    }
    return day;
}

void full_month(int mm,int year,int x, int y )
{
    system("COLOR B5");
    int wday = week_day(mm,year);
    if(!(mm>=1 && mm<=12))
        {
            printf("INVALID MONTH");
            getch();
            return;
        }
    if(!(year>=1600))
        {
            printf("INVALID YEAR");
            getch();
            return;
        }
    gotoxy(20,y);
    print_date(mm,year);
    y+=3;
    gotoxy(x,y);
    int n; int c=0;
    printf("M   T   W   T   F   S   Sun\n");
    y++;
    int x1,y1;
    x1=x;
    y1=y;
    for(n=1;n<=getNumberOfDays(mm,year);n++)
    {
        gotoxy(28,4);
        printf("|CALENDER|\n\n");
        gotoxy(28,5);
        printf("----------\n\n");
        switch(wday)
        {
            //locates the starting day in calender
            case 1 :
                x=x;
                break;
            case 2 :
                x=x+4;
                break;
            case 3 :
                x=x+8;
                break;
            case 4 :
                x=x+12;
                break;
            case 5 :
                x=x+16;
                break;
            case 6 :
                x=x+20;
                break;
            case 7 :
                x=x+24;
                break;
            default :
                printf("INVALID DATA FROM THE getOddNumber()MODULE");
            return;
    }
        gotoxy(x,y);
        x=x1;
        if(wday==7)
        {
            y++;
        }
        printf("%d ",n);
        wday++;
        if(wday>7)
        {
            printf("\n");
            wday=1;
        }
    }

}

int getDaynumber(int dd, int mm, int yy)
{
    int wday = week_day(mm,yy);
    int i,c=1;
    if(dd==1)
    {
        return wday;
    }
    else
    {
        for (i=2;i<=dd;i++)
        {
            wday++;
            if(wday>7)
            {
                wday=1;
            }
        }
        return wday;
    }
}

int getDay(int dd,int mm,int yy)
{
    system("COLOR F4");
    int day;
    if(!(mm>=1 && mm<=12))
        {
            printf("Invalid month value");
        }
    else if(!(dd>=1 && dd<=getNumberOfDays(mm,yy)))
        {
            printf("Invalid date");
        }
    else if(yy>=1600)
        {
            day = getDaynumber(dd,mm,yy);
            switch(day)
            {
            case 1:
                printf("Monday");
                break;
            case 2:
                printf("Tuesday");
                break;
            case 3:
                printf("Wednesday");
                break;
            case 4:
                printf("Thursday");
                break;
            case 5:
                printf("Friday");
                break;
            case 6:
                printf("Saturday");
                break;
            case 7:
                printf("Sunday");
                break;
            }
            full_month(mm,yy,20,5);
    }
    else
        {
            printf("\nPlease give year more than 1600");
        }
}
void Addnote()
{
    system("COLOR A1");
    FILE *fp;
    fp = fopen("note.txt","a");
    system("cls");
    gotoxy(5,7);
    printf("Enter the date(DD MM): ");
    scanf("%d%d",&R.dd, &R.mm);
    gotoxy(5,8);
    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    gets(R.note);
    fprintf(fp,"%d %d %s",R.dd, R.mm, R.note);
    fprintf(fp,"~\n");
    gotoxy(5,15);
    printf("Press any key............");
    getch();
    fclose(fp);
}

void showNote(int mm)
{
    system("COLOR E4");
    int i=0;
    char f[50];
    FILE *fp;
    fp = fopen("note.txt","r");
    system("cls");
    if(fp == NULL)
    {
        printf("Error!!!!");
    }
    char ch,ch1;
    fscanf(fp,"%d %d",&R.dd,&R.mm);
    ch1='a';
    int j=0;
    while(fscanf(fp,"%d %d",&R.dd,&R.mm)!=EOF)
    {
        if(R.mm==mm)
        {
            j=1;
            i=0;
            while((ch=getc(fp))!='~')
            {
                R.note[i]=ch;
                i++;
            }
            R.note[i]='\0';
            printf("\n");
            printf("%d:\t%s",R.dd,R.note);
        }
        else
        {
            i=0;
            while((ch=getc(fp))!='~')
            {
                f[i]=ch;
                i++;
            }
        }
    }
    if(j==0)
    {
        printf("\nThis Month contains no Reminders");
    }
    gotoxy(0,5);
    printf("\nPress q to quit:");
    fclose(fp);
}

void main()
{

    int choice;
    char ch = 'a';
    while(1)
        {
            system("COLOR E9");
            system("cls");
            gotoxy(30,0);
            printf("----------\n\n");
            gotoxy(30,1);
            printf("|CALENDER|\n\n");
            gotoxy(30,2);
            printf("----------\n\n");
            printf("1. Find Out the Day\n");
            printf("2. Print all the day of month\n");
            printf("3. Add Reminders\n");
            printf("4. EXIT\n\n");
            printf("ENTER YOUR CHOICE : \t");
            scanf("%d",&choice);
            system("cls");
            char ch='a';
            switch(choice)
            {
                case 1:
                    system("COLOR A5");
                    printf("Enter date (DD MM YYYY): ");
                    scanf("%d %d %d",&date.dd,&date.mm,&date.yy);
                    printf("\nDay is: ");
                    getDay(date.dd,date.mm,date.yy);
                    printf("\n\nPress any key to continue......");
                    getch();
                    break;
                case 2:
                    system("COLOR F4");
                    printf("Enter month and year (MM YYYY) : ");
                    scanf("%d %d",&date.mm,&date.yy);
                    int a= date.mm;
                    int b= date.yy;
                    full_month(date.mm,date.yy,20,5);
                    printf("\n\nenter \'n\' for next month, or \'p\' for previous month, or \'s\' for Reminders else \'q\' to quit");
                    while(ch!='q')
                    {
                        ch=getch();
                        if(ch == 'n')
                            {
                                a++;
                            if(a>12)
                            {
                                b++;
                                a=1;
                            }
                                system("cls");
                                full_month(a,b,20,5);
                                printf("\n\nenter n for next month,p for previous month or q to quit");

                            }
                        else if(ch == 'p')
                            {
                                a--;
                                if(a<1)
                                {
                                    b--;
                                    a=12;
                                }
                                if(b<1600)
                                    printf("Year Out of range");
                                else
                                {
                                    system("cls");
                                    full_month(a,b,20,5);
                                    printf("\nenter n for next month,p for previous month or q to quit");

                                }

                            }
                            else if(ch == 's')
                            {
                                showNote(a);
                                ch=getch();
                            }
                    }
                    printf("\nPress any key to continue......");
                    getch();
                    break;
                case 3:
                    Addnote();
                    break;
                case 4:
                    exit(0);
                    break;
                }
        }
}
