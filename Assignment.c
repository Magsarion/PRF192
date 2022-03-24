#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int menu();
void add(int a[],int *n);
void display(int a[],int n);
int search(int a[],int n,int value);
void delValue(int a[],int *n,int value);
int delIndex(int a[],int *n,int index);
void delInRange(int a[],int *n,int min,int max);
void sort(int a[],int n,int type);
void insert(int a[],int *n,int index,int value);
int main(){
	int a[100];
	int n = 0,value,index,min,max,type;
	while(1){
		int choice = menu();
		system("cls");
		switch(choice){
		case 1 : 
		add(a,&n);
		break;
		case 2 :
		display(a,n);
		break;
		case 3 :
		printf("\n Value = ");
		scanf("%d",&value);
		printf("\n%d",search(a,n,value));
		break;
		case 4 :
		printf("\n Value = ");
		scanf("%d",&value);
		delValue(a,&n,value);
		break;
		case 5 :
		printf("\n Index = ");
		scanf("%d",&index);
		printf("%d\n",delIndex(a,&n,index));
		break;
		case 6 :
		printf("\n Min = ");
		scanf("%d",&min);
		printf("\n Max = ");
		scanf("%d",&max);
		delInRange(a,&n,min,max);
		break;
		case 7 :
		printf("\n Type = ");
		scanf("%d",&type);
		sort(a,n,type);
		break;
		case 8 :
		printf("\n Index = ");
		scanf("%d",&index);
		printf("\n Value = ");
		scanf("%d",&value);
		insert(a,&n,index,value);
		break;
		case 9 :
		return;
	   }
	   fflush(stdin);
	   printf("\nPress any key for back to main menu");
	   getchar();
	   system("cls");
	}
}

int menu(){
	int choice;
	printf("\n1.Add new element");
	printf("\n2.Display Array");
	printf("\n3.Searching element in array");
	printf("\n4.Delete value in array");
	printf("\n5.Delete element at index");
	printf("\n6.Delete some elements in range");
	printf("\n7.Sort element in array");
	printf("\n8.Insert an element to array");
	printf("\n9.Quit");
	while(1){
		printf("\nYour choice : ");
		scanf("%d",&choice);
		if(choice < 1 || choice > 9){
			printf("Please input integer number from 1 to 9");
		}
		else return choice;
	}
}

void add(int a[],int *n){
   if((*n) == 100){
		printf("List Full! Can't add more");
		return;
	}
   int elelement;
   printf("\nInput value : ");
   scanf("%d",&elelement);
   a[(*n)] = elelement;
   (*n)++;
}
void display(int a[],int n){
	int i;
	for(i = 0;i < n;i++){
		printf("%d ",a[i]);
	}
}
int search(int a[],int n,int value){
    int i;
	for(i = 0;i < n;i++){
		if(a[i] == value){
			return i;
		}
	}
	return -1;	
}
void delValue(int a[],int *n,int value){
	int pos = search(a,*n,value);
	if(pos == - 1){
		return;
	}
	int i;
	for(i = pos;i < (*n);i++){
		a[i] = a[i+1];
	}
	(*n)--;
}
int delIndex(int a[],int *n,int index){
	if(index < 0 || index >= (*n)){
		return INT_MIN;
	}
	int i;
	int value;
	value = a[index];
	for(i = index;i < (*n);i++){
		a[i] = a[i+1];
	}
	(*n)--;
	return value;
} 
void delInRange(int a[],int *n,int min,int max){
	int i;
	for(i = 0;i < (*n);i++){
		if(a[i] >= min && a[i] <= max){
			delIndex(a,n,i);
			i--;
		}
	}
}
void sort(int a[],int n,int type){
	int i,j;
	if(type == 0){
		for(i = 0;i < n;i++){
			for(j = i + 1;j < n;j++){
				if(a[j] < a[i]){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	else {
	for(i = 0;i < n;i++){
			for(j = i + 1;j < n;j++){
				if(a[j] > a[i]){
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}	
	}
}
void insert(int a[],int *n,int index,int value){
	int i;
	if(index < 0 || index >= (*n)){
		return;
	}
	if((*n) == 100){
		return;
	}
	for(i = (*n);i > index;i--){
		a[i] = a[i-1];
	}
	a[index] = value;
	(*n)++;
}

