LINKED_SYMBOLTABLE 

2);
getch ();/* C Program to implement SYMBOL TABLE */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#define null 0
int size = 0;
void insert ();
void display ();
int search(char lab[]);
struct symbtab
{
char label[10];
char info[10];
struct symbtab *next;
};
struct symbtab *first, *last;
void main ()
{
int op;
int y;
char la[10];
do
{
printf ("0.INSERT\n");
printf ("1.DISPLAY\n");
printf ("\nEnter your option: ");
scanf ("%d", &op);
switch (op){
case 0:
insert ();
break;
case 1:
display ();
break;
}
}
while (op <
}
void insert () {
int n;
char l[10];
printf ("Enter the Identifier: \n");
scanf ("%s", l);
n = search (l);
if (n == 1)
printf("The label is already in the symbol table. Duplicate cant be
inserted\n");
else{
struct symbtab *p;
p = malloc (sizeof (struct symbtab));
strcpy (p->label, l);
printf ("Enter the info:\n ");
scanf ("%s", &p->info);
p->next = null;
if (size == 0){
first = p;
last = p;
}
else{
last->next = p;
last = p;
}
size++;
}
}
void display (){
int i;
struct symbtab *p;
p = first;
printf ("Id\t\t\tInfo\n");
for (i = 0; i < size; i++){
printf ("%s\t\t\t%s\n", p->label, p->info);
p = p->next;
}
}
int search (char lab[]){
int i, flag = 0;
struct symbtab *p;
p = first;
for (i = 0; i < size; i++){
if (strcmp (p->label, lab) == 0)
flag = 1;
p = p->next;
}
return flag;
}

       
HASTABLE_SYMBOLTABLE
       
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20
struct symtab
{
char *data;
int key;
};
struct symtab* hashArray[SIZE];
struct symtab* dummyItem;
struct symtab* item;
int hashCode(int key) {
return key % SIZE;
}
struct symtab *search(char* key) {
//get the hash
int hashIndex = 1;
//move in array until an empty
while(hashArray[hashIndex] != NULL) {
if(hashArray[hashIndex]->data == key)
return hashArray[hashIndex];
//go to next cell
++hashIndex;
//wrap around the table
hashIndex %= SIZE;
}
return 0;
}
void insert(int key,char* data) {
struct symtab *item = (struct symtab*) malloc(sizeof(struct symtab));
item->data = data;
item->key = key;
struct symtab *temp = (struct symtab*) malloc(sizeof(struct symtab));
temp = search(data);
if (temp == NULL){
//get the hash
int hashIndex = key;
//move in array until an empty or deleted cell
while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key
!= -1) {
//go to next cell
++hashIndex;
//wrap around the table
hashIndex %= SIZE;
}
hashArray[hashIndex] = item;
}
}
void display() {
int i = 0;
printf("\n\n");
printf("info id");
for(i = 0; i<SIZE; i++) {
if(hashArray[i] != NULL)
printf("\n %d %s",hashArray[i]->key,hashArray[i]->data);
}
printf("\n");
}
int main() {
char id[20][20];
int i = 0;
printf("enter 0 to stop inputing identifiers\n\n");
while (i < 20){
scanf("%s",&id[i]);
if (!strcmp(id[i],"0")){
break;
}
insert(i,id[i]);
i++;
}
display();
}       
       
       
       
       
