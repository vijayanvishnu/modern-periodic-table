#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "elements.h"
int i;
struct element_node *head=NULL;
struct element_node *tail=NULL;
void search();
struct element_node {
	struct element node;
	struct element_node *next;
};
void clrscr() {
    system("@cls||clear");
}
void newScreen() {
	clrscr();
	int width = 132;
	char str[] = "\033[31;1;51;4mPERIODIC TABLE\033[0m\n";
	int length = sizeof(str) - 1;
	int pad = (length >= width) ? 0 : (width - length) / 2;
	printf("%*.*s%s\n", pad, pad, " ", str);
	int i;
	for(i=0; i<10; i++){
		printf("\n");
	}
}
void add(){
	newScreen();
	struct element_node *n = (struct element_node *)malloc(sizeof(struct element_node));
	n->next=NULL;
	if(head==NULL){
		head=tail=n;
	}
	else {
		tail->next=n;
		tail=n;
	}
	int anum;
	float weight;
	char name[20];
	char sym[4];
	printf("\n\n\033[33mENTER ELEMENT NAME : \033[0m");
	scanf("%s",name);
	for (i=0; i<118; i++) {
		if (strcmp(atom[i].name,name)==0){
			printf("\033[33mELEMENT ALREADY EXIST.\n\nADD ANOTHER : \033[0m");
			char ch;
			scanf("%*c%c",&ch);
			if(ch=='y' || ch=='Y'){
				add();
			}
			else {
				main();
			}	
		}
	}
	 strcpy(n->node.name,name);
	printf("\n\n\033[33mENTER SYMBOLS : \033[0m");
	scanf("%s",sym);
	for (i=0; i<118; i++) {
		if (strcmp(atom[i].symbol,sym)==0){
			printf("\033[33mELEMENT ALREADY EXIST.\n\nADD ANOTHER : \033[0m");
			char ch;
			scanf("%*c%c",&ch);
			if(ch=='y' || ch=='Y'){
				add();
			}
			else {
				main();
			}	
		}
	}
	 strcpy(n->node.symbol,sym);
	printf("\n\n\033[33mENTER ATOMIC NUMBER  : \033[0m");
	scanf("%d",&anum);
	for (i=0; i<118; i++) {
		if (anum==atom[i].atomicnum){
			printf("\n\n\033[33mELEMENT ALREADY EXIST.\n\nADD ANOTHER : \033[0m");
			char ch;
			scanf("%*c%c",&ch);
			if(ch=='y' || ch=='Y'){
				add();
			}
			else {
				main();
			}	
		}
	}
	n->node.atomicnum=anum;
	printf("\n\n\033[33mENTER ELEMENT WEIGHT : \033[0m");
	scanf("%f",&weight);
	n->node.atomicwt=weight;
	main();
}
void quit() {
	newScreen();
	char ans[5];
	printf("\033[31mARE YOU SURE YOU WANT TO QUIT?\033[0m");
	scanf("%s",ans);
	if (tolower(ans[0])=='y'){
		printf("\n\n\n\n\033[35mTHANK YOU\033[0m\n\n");
	} else {
		main();
	}
}

void again() {
	char ans1[5];
	printf("\n\n\n\n\033[32mSEARCH FOR A DIFFERENT ELEMENT? : \033[0m");
	scanf("%s",ans1);
	if (tolower(ans1[0])=='y'){
		search();
	} else {
		quit();
	}
	printf("\n\n\n\n\n\n\n\n\n\n");
}

void info1() {
	newScreen();
	char ele[20];
	printf("\033[32mENTER THE ELEMENT'S NAME : \033[0m");
	scanf("%s",ele);
	for (i=0; i<118; i++) {
		if (strcmp(atom[i].name,ele)==0){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",atom[i].name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",atom[i].symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",atom[i].atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",atom[i].atomicwt);
			break;
		}
	}
	struct element_node *thead=head;
	while(thead!=NULL){
		if(strcmp(thead->node.name,ele)==0){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",thead->node.name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",thead->node.symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",thead->node.atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",thead->node.atomicwt);
			break;
		}
		thead=thead->next;
	}
	again();
}
void info2() {
	newScreen();
	char sym[1];
	printf("\033[32mENTER THE ELEMENT'S SYMBOL : \033[0m");
	scanf("%s",sym);
	for (i=0; i<118; i++) {
		if (strcmp(atom[i].symbol,sym)==0){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",atom[i].name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",atom[i].symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",atom[i].atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",atom[i].atomicwt);
			break;
		}
	}
	struct element_node *thead=head;
	while(thead!=NULL){
		if(strcmp(thead->node.symbol,sym)==0){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",thead->node.name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",thead->node.symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",thead->node.atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",thead->node.atomicwt);
			break;
		}
		thead=thead->next;
	}
	again();
}

void info3() {
	newScreen();
	int atn;
	printf("\033[32mENTER THE ELEMENT'S ATOMIC NUMBER : \033[0m");
	scanf("%d",&atn);
	if(atn<118){
	for (i=0; i<118; i++) {
		if (atom[i].atomicnum==atn){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",atom[i].name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",atom[i].symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",atom[i].atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",atom[i].atomicwt);
			break;
		}
	} }
	struct element_node *thead=head;
	while(thead!=NULL){
		if(thead->node.atomicnum==atn){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",thead->node.name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",thead->node.symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",thead->node.atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",thead->node.atomicwt);
			break;
		}
		thead=thead->next;
	}
	again();
}

void info4() {
	newScreen();
	float atwt;
	printf("\033[32mENTER THE ELEMENT'S ATOMIC WEIGHT : \033[0m");
	scanf("%f",&atwt);
	for (i=0; i<118; i++) {
		if (atom[i].atomicwt==atwt){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",atom[i].name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",atom[i].symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",atom[i].atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",atom[i].atomicwt);
			break;
		}
	}
	struct element_node *thead=head;
	while(thead!=NULL){
		if(thead->node.atomicwt==atwt){
			printf("\033[34m\n\n\tELEMENT : %s\033[0m\n",thead->node.name);
			printf("\033[34m\n\n\tSYMBOL : %s\033[0m\n",thead->node.symbol);
			printf("\033[34m\n\n\tATOMIC NUMBER : %d\033[0m\n",thead->node.atomicnum);
			printf("\033[34m\n\n\tATOMIC WEIGHT : %f\033[0m\n",thead->node.atomicwt);
			break;
		}
		thead=thead->next;
	}
	again();
}

void search() {
	newScreen();
	printf("\033[33mSREACH BY :- \033[0m\n\n");
	printf("\033[34m\t1 -> ELEMENT\033[0m\n");
	printf("\033[34m\t2 -> SYMBOL\033[0m\n");
	printf("\033[34m\t3 -> ATOMIC NUMBER\033[0m\n");
	printf("\033[34m\t4 -> ATOMIC WEIGHT\033[0m\n\n\n\n");
	int choice2;
	printf("\033[32mYOUR CHOICE : \033[0m");
	scanf("%d",&choice2);
	if (choice2==1){
		info1();
	} else if (choice2==2){
		info2();
	} else if (choice2==3){
		info3();
	} else if (choice2==4){
		info4();
	} else {
		search();
	}
}

int main() {
	newScreen();
	printf("\033[34m1 -> ADD NEW ELEMENT \033[0m\n\n");
	printf("\033[34m2 -> EXPLORE\033[0m\n\n");
	printf("\033[34m3 -> QUIT\033[0m\n\n\n\n");
	int choice1;
	printf("\033[32mYOUR CHOICE : \033[0m");
	scanf("%d",&choice1);
	table();
	if (choice1==1){
		 add();
	} else if(choice1==2){
		search();
	} else if (choice1==3){
		quit();
	} else {
		main();
	}
}
