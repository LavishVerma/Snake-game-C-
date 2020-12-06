
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;

struct list
{
 int y;
 list* next;	
};
struct array
{
	list* Start=NULL;
	list* End=NULL;
	int count=0;
};

struct Waste
{
	int x;
	int y;
	char Value;
	Waste *next;
};

struct Food
{
int x;
int y;
char Value;
};

struct Snake
{
int x;
int y;
char Value;
Snake *next;
}s1,s2,s3,s4;

Snake *SnakeInitializer(Snake *);
Food FoodInitializer(char *,Snake *,Waste *);
void ArrayFiller(Snake *,char *,Waste *);
void Display(char *);
void Delete(char *);
Waste* Shift(Snake *,char,Waste *,array *);
void AlterHead(Snake *);
int FoodChecker(Food , Snake *);
Snake * Reverse(Snake *);
Snake *IncreaseSize(Snake *,char);
int CheckGameOver(Snake *);
int AddToHashTable(array* ,int,int);
void DeleteFromHash(array*,int ,int);
void InitialHashArrayFiller(array *,Snake *); 

int main()
{
array hashArray[20];	
char direction='W',input='W';
Waste *shit=NULL;
static	Snake *START=NULL;
int flag=1,revFlag=1;
static char arr[20][20]={0};
START=SnakeInitializer(START);        //     SNAKE INITIALIZER
InitialHashArrayFiller(hashArray,START);
Food food=FoodInitializer(&arr[0][0],START,shit);                           //        FOOD INITIALIZER
ArrayFiller(START,&arr[0][0],shit);//
Display(&arr[0][0]);
Snake *temp=START;
cout<<"Enter W or A or S or D::";
while(true)
{   

 while(true)
     {
     input=getch();
     if(input=='W'||input=='A'||input=='S'||input=='D'||input=='R')
     break;
     }
	Snake *second=START->next;
	if(revFlag++>0)
    
    temp=START;
  if(input=='W'&&START->x-1!=second->x&&direction!='S')
   {
   
   	direction='W';
	START->Value='A';

	shit=Shift(START,direction,shit,hashArray);
	START->x=START->x-1;
	if(START->x<0)
	START->x=20+START->x;
	
	if(AddToHashTable(hashArray,START->x,START->y))
	{
		cout<<"GAME OVER";
		break;
	}
	
	
	 if(START->x==food.x&&START->y==food.y)
	 {
	  START=IncreaseSize(START,direction);
	   AddToHashTable(hashArray,START->x,START->y);
	  food=FoodInitializer(&arr[0][0],START,shit);    
     }
    Sleep(200);
   Delete(&arr[0][0]);
   ArrayFiller(START,&arr[0][0],shit);
   
   system("CLS");
    Display(&arr[0][0]);
   
    
}
else if(input=='A'&&START->y-1!=second->y&&direction!='D')
{
	

	direction='A';
	START->Value='A';

	shit=Shift(START,direction,shit,hashArray);
	START->y=START->y-1;
	 if(START->y<0)
	 START->y=20+START->y;
	 if(AddToHashTable(hashArray,START->x,START->y))
	{
		cout<<"GAME OVER";
		break;
	}
     if(START->x==food.x&&START->y==food.y)
	 {
	  START=IncreaseSize(START,direction);
	  AddToHashTable(hashArray,START->x,START->y);
	  food=FoodInitializer(&arr[0][0],START,shit);    
     }
    Sleep(200);
   Delete(&arr[0][0]);
   ArrayFiller(START,&arr[0][0],shit);
   
   system("CLS");
    Display(&arr[0][0]);	 
   }

else if(input=='S'&&START->x+1!=second->x&&direction!='W')
{


	direction='S';
	START->Value='A';
	
	shit=Shift(START,direction,shit,hashArray);
	START->x=START->x+1;
	if(START->x>19)
	START->x=START->x-20;
	if(AddToHashTable(hashArray,START->x,START->y))
	{
		cout<<"GAME OVER";
		break;
	}
     if(START->x==food.x&&START->y==food.y)
	 {
	  START=IncreaseSize(START,direction);
	  AddToHashTable(hashArray,START->x,START->y);
	  food=FoodInitializer(&arr[0][0],START,shit);    
     }
    Sleep(200);
   Delete(&arr[0][0]);
   ArrayFiller(START,&arr[0][0],shit);
   
   system("CLS");
    Display(&arr[0][0]);

}

    else if(input=='D'&&START->y+1!=second->y&&direction!='A')
	{

		
	direction='D';
	START->Value='A';

	shit=Shift(START,direction,shit,hashArray);
	
	START->y=START->y+1;
	if(START->y>19)
	START->y=START->y-20;
	if(AddToHashTable(hashArray,START->x,START->y))
	{
		cout<<"GAME OVER";
		break;
	}
     if(START->x==food.x&&START->y==food.y)
	 {
	  START=IncreaseSize(START,direction);
	  	AddToHashTable(hashArray,START->x,START->y);
	  food=FoodInitializer(&arr[0][0],START,shit);    
     }
    Sleep(200);
   Delete(&arr[0][0]);
   ArrayFiller(START,&arr[0][0],shit);
   
   system("CLS");
    Display(&arr[0][0]);
   

   }
   else
   {
   	
   	if(input=='R')
   	START=Reverse(START);
   	
    Sleep(150);
   Delete(&arr[0][0]);
   ArrayFiller(START,&arr[0][0],shit);
   
   system("CLS");
    Display(&arr[0][0]);
    if(direction=='W')
    input='S';
    else if(direction=='A')
    input='D';
    else if(direction=='S')
    input='W';
 else
     input='A';	
     
     revFlag=-1;
   } 
   
} 
}
////////////////////////////////////////////////////////////////////////////////////////////////
int CheckGameOver(Snake *temp)
{
	int tempx=temp->x,tempy=temp->y;
	temp=temp->next;
	while(temp!=NULL)
	{
		if(tempx==temp->x&&tempy==temp->y)
		return 1;
		temp=temp->next;
	}
	return 0;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////
Snake *SnakeInitializer(Snake *temp)
{
   //           HEAD POINTER
//  Snake s1,s2,s3,s4;
  temp=&s1;

  s1.x=1;
  s1.y=2;
  s1.Value='A';
  s1.next=&s2;

  s2.x=2;
  s2.y=2;
  s2.Value='#';
  s2.next=&s3;

  s3.x=3;
  s3.y=2;
  s3.Value='#';
  s3.next=&s4;

  s4.x=4;
  s4.y=2;
  s4.Value='T';
   s4.next=NULL;
   
  // cout<<&START<<endl;
      return temp;

}
//////////////////////////////////////////////////////////////////////////////////////////////////

void Delete(char *arr)
{
	for(int i=0;i<20;i++)
   {
    for(int j=0;j<20;j++)
    {
    	if(*((arr+20*i)+j)=='F'||*((arr+20*i)+j)=='S')
    	continue;
    *((arr+20*i)+j)=' ';
    }
    
   }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
int FoodChecker(Food f, Snake *temp,Waste *shit)
{
	while(shit!=NULL)
	{    
		if(f.x==shit->x&&f.y==shit->y)
		{
			return 0;
		}
		shit=shit->next;
	}
	do
	{
		if(f.x==temp->x&&f.y==temp->y)
		{
			return 0;
		}
		temp=temp->next;
	}while(temp!=NULL);
	return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
Food FoodInitializer(char *arr,Snake *START,Waste *shit)
{
   srand(time(0));
   static Food f;
   while(true)
   {
   f.x=rand()%20;
   f.y=rand()%20;
   
   if(FoodChecker(f,START,shit))
   break;
  }
   f.Value='F';
   *((arr+20*f.x)+f.y)=f.Value;
  // cout<<f.x<<f.y;
   //arr[f.x][f.y]=f.Value;
   return f;	
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void ArrayFiller(Snake *temp,char *arr,Waste *shit)
{
	 while(shit!=NULL)
     {
    // cout<<"ARRAYFILLER"<<shit->x<<" "<<shit->y<<endl; 
      *((arr+20*shit->x)+shit->y)=shit->Value;
      shit=shit->next;
    }
  
    do
     {
     // cout<<temp->x<<" "<<temp->y<<endl; 
      *((arr+20*temp->x)+temp->y)=temp->Value;
      temp=temp->next;
     }while(temp!=NULL);	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(char *arr)
{
  
  for(int i=0;i<20;i++)
   {
   	cout<<"|";
    for(int j=0;j<20;j++)
    { 
    cout<<*((arr+20*i)+j)<<" ";
    }
    
   cout<<"|";
    
    cout<<endl;
   }	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
Snake* IncreaseSize(Snake *Start,char direction)
{

	Snake *temp=Start;
	int tempx=Start->x,tempy=Start->y;
	Start->Value='F';
	Start=(Snake*)malloc(sizeof(Snake));
	Start->Value='A';
	Start->next=temp;
	if(direction=='W')
     {
     	Start->x=tempx-1;
     	Start->y=tempy;
	 }
	 else if(direction=='A')
	 {
	 	Start->x=tempx;
     	Start->y=tempy-1;
	 }
	 else if(direction=='S')
	 {
	 	Start->x=tempx+1;
     	Start->y=tempy;
	 }
	 else//D
	 {
	 	Start->x=tempx;
     	Start->y=tempy+1;
	 }
	
   return Start;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
Snake* Reverse(Snake *temp)
{
	Snake *Start=NULL;
	static Snake *TEMP=NULL;
	if(temp->next==NULL)
	{
		temp->Value='A';
		TEMP=temp;
		return temp;
	}
	Start=Reverse(temp->next);
	Start->next=temp;
	if(temp->Value=='A')
	{
		temp->Value='T';
		temp->next=NULL;
		return TEMP;
	}
	return temp;
}
	

/////////////////////////////////////////////////////////////////////////////////////////////////////
Waste* Shift(Snake *temp,char direction,Waste *shit,array *ptr)
{
	int flag=0,tempx,tempy,check=0,wasteflag=0;
	Waste *wasteTemp=shit;
	char value='@';
	do
	{
		if(flag==0)
		{
			tempx=temp->x;
			tempy=temp->y;
			flag=1;
		}
		
		if(value=='F'&&temp->Value!='T')// THIS CONDITION
		{
			temp->Value='F';
			value='#';        //OTHER THAN F, SO THAT IT DOES REPEAT TO THIS IF CONDITION.
		}
			
		if(temp->Value=='F'&&value=='@')//   FIRST THIS
		{
				if(temp->next->Value=='T')//      LIFE SAVER
		           check=1;
	     	value='F';
		    temp->Value='#';		
		}
		
	
		
		temp->x=2*tempx-temp->x;
		  tempx=2*tempx-temp->x;//                      SWAPPING
		temp->x=(temp->x+tempx)/2;
		
		temp->y=2*tempy-temp->y;
		  tempy=2*tempy-temp->y;//                      SWAPPING
		temp->y=(temp->y+tempy)/2;
		
		temp=temp->next;
	}while(temp!=NULL);
	//cout<<tempx<<" "<<tempy<<endl;
	if(check==1)
	{  cout<<"INSIDE";
		if(wasteTemp==NULL)
		{
			wasteTemp=(Waste*)malloc(sizeof(Waste));
			shit=wasteTemp;
			wasteTemp->next=NULL;
		    wasteflag=1;
		    
		}
	    else
		{
	        while(wasteTemp->next!=NULL&&wasteflag==0)
		    {
		    	wasteTemp=wasteTemp->next;
	    	}
	    	wasteTemp->next=(Waste*)malloc(sizeof(Waste));
	    	wasteTemp=wasteTemp->next;
	    	wasteTemp->next=NULL;
	    }
	    wasteTemp->x=tempx;
	    wasteTemp->Value='S'; 
	    wasteTemp->y=tempy;
		//
		AddToHashTable(ptr,tempx,tempy);
	}
//	cout<<tempx<<" "<<tempy;
    if(check!=1)
	DeleteFromHash(ptr,tempx,tempy);

	return shit;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
int  AddToHashTable(array *ptr,int x,int y)
{
	list *temp=ptr[x].Start;
	if(ptr[x].Start==NULL)
	{
	//	cout<<"HELLO "<<endl;
		list *ls=(list*)malloc(sizeof(list));
		ls->next=NULL;
		ls->y=y;
		ptr[x].Start=ls;
		ptr[x].End=ls;
		ptr[x].count=1;
	//	cout<<"IFADDED:"<<x<<" "<<ptr[x].End->y<<endl;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->y==y)
			return 1;
	//		cout<<temp->y<<endl;
			temp=temp->next;
		}
	//	cout<<endl;
		list *newlist=(list*)malloc(sizeof(list));
		newlist->next=NULL;
		newlist->y=y;
		ptr[x].End->next=newlist;
		ptr[x].End=newlist;
		ptr[x].count=ptr[x].count+1;
	//	cout<<"ELSEADDED:"<<x<<" "<<ptr[x].End->y<<endl;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFromHash(array *ptr,int x,int y)
{
	list *temp1=ptr[x].Start,*temp2=ptr[x].Start;
	if(ptr[x].Start->y==y)
	{
		ptr[x].Start=ptr[x].Start->next;
		ptr[x].count=ptr[x].count-1;
	//	cout<<"IFDELETED:"<<x<<" "<<y<<endl;
	}
	else
	{
		while(temp2!=NULL)
		{
			if(temp2->y==y)
			{
				temp1->next=temp2->next;
				ptr[x].count=ptr[x].count-1;
				//cout<<"ELSEDELETED:"<<x<<" "<<y<<endl;
				break;
			}
			temp1=temp2;
			temp2=temp2->next;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitialHashArrayFiller(array *ptr,Snake * snake)
{
	int c;
	while(snake!=NULL)
	{
	   c=AddToHashTable(ptr,snake->x,snake->y);
		snake=snake->next;
	}
	
}

