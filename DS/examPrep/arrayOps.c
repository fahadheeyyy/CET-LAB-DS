#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX] ;
int size=-1;

void delete(){
    int pos=0;
    int i=0;

    printf("Enter the position :");
    scanf("%d",&pos);



    if(pos>MAX || pos<0){
        printf("cannot delete");
        return;
    }
    else{
        pos=pos--;
        for(i=pos;i<size;i++){
            arr[i]=arr[i+1];
        }

        size=size-1;
        printf("\ndeleted");
    }
}
void insert()
{
    int pos=0;
    int value;
    int i=0;

    printf("Enter the position :");
        scanf("%d",&pos);



    if(pos<0 || pos>MAX || size>MAX){
        printf("cannot insert");
        return;
    }
    else{
        printf("Enter the value to be inserted :");
        scanf("%d",&value);
        


        pos=pos--;
        for(i=size;i>=pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=value;
        size=size+1;
        printf("\ninserted");

    }
}
void display(){
    int i=0;
    if(size<0){
        printf("empty");
    }
    else{
        printf("data is :\n");
        for(i=0;i<=size;i++){
            printf("%d\n",arr[i]);
        }
    }
}
void search(){
    int value;
    int i=0;
    
    printf("Enter the value to be searched :");
    scanf("%d",&value);

    for(i=0;i<=size;i++){
        if(arr[i]==value){
            printf("found at %d" , i);
        }
    }
    
}

int main(){
    int n;
    
    int c=1;
   while(c==1){
    printf("1.ins\n2.del\n3.dis\n4.ser\n");
    scanf("%d",&n);
    switch(n){
        case 1:
         insert();
         break;
        case 2:
         delete();
         break;
        case 3:
         display();
         break;
        case 4:
         search();
         break;
        default:
          break;
    }
    printf("\ndo you wanna continue ?\n 1.yes \n 2.no\n");
    scanf("%d",&c);
}
return 0;
}
