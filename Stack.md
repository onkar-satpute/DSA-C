# Static Stack
### initialize-push-pop-isEmpty-isFull-Display
``` c
#include <stdio.h>
#define MAXSIZE 20
typedef struct
{
int data [MAXSIZE];
int top;
}STACK;

void initstack(STACK *ps);
int isEmpty(STACK *ps);
int isFull(STACK *ps);
void push(STACK *ps, int num);
int pop(STACK *ps);
int peek(STACK *ps);
void display(STACK *ps);
int main()
{
printf("Hello World");
int n,choice;
STACK s;
initstack(&s);
do
{
printf("\n 1: PUSH");
printf("\n 2: POP");
printf("\n 3: PEEK");
printf("\n 4: Display");
printf("\n 5: EXIT");
printf("\n Enter your choice");
scanf("%d",&choice);
switch(choice)

{
case 1: // PUSH
if(isFull(&s))
printf("\n Stack Overflow");
else
{
printf("\n Enter the element to be pushed");
scanf("%d",&n);
push(&s,n);
}
break;
case 2: //pop
if(isEmpty(&s))
printf("\n Stack Underflow");
else
printf("\n The popped element is : %d",pop(&s));
break;
case 3: // peek
if(isEmpty(&s))
printf("\n Stack Underflow");
else
printf("\n The topmost element is : %d", peek(&s));
break;
case 4: //Display
display(&s);
break;
}
}while(choice != 5);
return 0;
}
void initstack(STACK *ps)
{
ps->top = -1;
}
int isEmpty(STACK *ps)
{

if(ps->top == -1)
return 1;
return 0;
}
int isFull(STACK *ps)
{
return (ps->top == MAXSIZE-1);
}
void push(STACK *ps, int num)
{
++ps->top;
ps->data[ps->top] = num;
}
int pop(STACK *ps)
{
int num;
num = ps->data[ps->top];
ps->top--;
return num;
}
int peek(STACK *ps)
{
int num;
num = ps->data[ps->top];
return num;
}
void display(STACK *ps)
{
int i;
for(i=ps->top;i>-1;i--)
{
printf("|%d|\n",ps->data[i]);
}
}
```
# Dynamic Stack 
### initialize-push-pop-isEmpty-isFull-Display
``` c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Function prototypes
void push(); // Push element to the top of the stack
int pop(); // Remove and return the top most element of the stack
int peek(); // Return the top most element of the stack
bool isEmpty(); // Check if the stack is in Underflow state or not
struct node{
int data;
struct node *next;
};
struct node *top;
int main (){
int choice=0;
printf("DYNAMIC STACK");
while(1){
printf("\n\nChose any of the following options:\n");
printf("\n 0: Exit 1: Push 2: Pop 3: Peek\n 4: Check if stack is empty\n");
scanf("%d",&choice);
switch(choice){
case 0: exit(0);
case 1: push(); break;
case 2: pop(); break;
case 3: peek(); break;
case 4: isEmpty(); break;
default: printf("Please choose a correct option!");
}
}
}
void push (){

int val;
struct node *newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter the value to be pushed: ");
scanf("%d", &val);
if(top == NULL){
newnode->data = val;
newnode->next = NULL;
top= newnode;
}
else{
newnode->data = val;
newnode->next = top;
top=newnode;
}
}
int pop(){
int item;
struct node *temp;
if (top == NULL)
printf("Underflow State: can't remove any item");
else{
item = top->data;
temp = top;
top = top->next;
free(temp);
printf("%d is popped out of the stack", item);
return item;
}
return -1;
}
int peek(){
int x = top->data;
printf("%d is the top most element of the stack\n", x);
return x;
}
bool isEmpty(){

if(top == NULL){
printf("Stack is empty: Underflow State\n");
return true;
}
printf("Stack is not empty\n");
return false;
}
```
