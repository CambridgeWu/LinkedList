#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//define element type
typedef int ElemType;

// define struct of linked list
typedef struct _Node{
	ElemType data;
	struct _Node* next;
}Node;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


//Create Node and puts Data in it
Node* CreateNode(ElemType data){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

//Initial List / Create a new List
Node* CreateList(){
	Node* headNode=(Node*)malloc(sizeof(Node));
	headNode->next=NULL;
	return headNode;
} 

//�������� 
Node* List=CreateList();

//�������� 
void DestroyList(Node* headNode){
	Node* p1=headNode;
	
}

//��������(ͷ�巨)
void InsertByHead(Node* headNode,int data){
	Node* p=CreateNode(data);
	p->next=headNode->next;
	headNode->next=p;
} 



//ɾ��ָ���ڵ� 
void DeleteNode(Node* headNode,int data){
	Node* p1=headNode;
	Node* p2=headNode->next;
	while(p2){
		if(p2->data==data){
			p1->next=p2->next;
			free(p2);
			break;
		}
		p1=p2;
		p2=p2->next;
	}
	printf("���������Ϣ����");
}

//��������==�����Ӧ��Ϣ 
void printList(Node* headNode){
	Node* pMove=headNode->next;
	while(pMove->next!=NULL){
		printf("%d->",pMove->data);
		pMove=pMove->next;
	}
	printf("%d",pMove->data);
} 

//�ҳ�������м�ڵ㲢��ӡ�������� 
void FindMidNode(Node* headNode){
	Node* mid=headNode->next;
	Node* pMove=headNode->next;
	
	while(pMove){
		if(pMove->next==NULL){
			printf("%d",mid->data);
			break;
		}
		pMove=pMove->next->next;
		if(pMove==NULL){
			printf("%d,%d",mid->data,mid->next->data);
			break;
		}
		mid=mid->next;
	}
}

Node* ReverseEvenList(Node* headNode){
	
}

void keyBoard(){
	printf("                  *������*                  \n");
	printf("---------------1.����ڵ�-------------------\n");
	printf("---------------2.�������-------------------\n");
	printf("---------------3.���������б�---------------\n");
	printf("---------------4.������ż˳��---------------\n");
	printf("---------------5.�ҵ��м�ڵ�---------------\n");
	printf("---------------6.ɾ���ڵ�-------------------\n");
	printf("---------------7.��ѯ�ڵ��Ƿ����-----------\n");
	printf("---------------8.�ж������Ƿ�ɻ�-----------\n");
	printf("---------------9.����������������--------\n");
	char ch=getch();
	switch(ch){
		case '1':
			printf("---------------1.����ڵ�-------------------\n");
			int data;
			printf("������һ��������");
			scanf("%d",data);
			InsertByHead(List,data);
			break;
		case '2':
			printf("---------------2.�������-------------------\n");
			printList(List);
			break;
		case '3':
			printf("---------------3.���������б�---------------\n");
			
			break;
		case '4':
			printf("---------------4.������ż˳��---------------\n");
			break;
		case '5':
			printf("---------------5.�ҵ��м�ڵ�---------------\n");
			FindMidNode(List);
			break;
		case '6':
			printf("---------------6.ɾ���ڵ�-------------------\n");
			printList(List);
			printf("��������Ҫɾ���Ľڵ����ݣ�������"); 
			int Data;
			scanf("%d",Data);
			DeleteNode(List,Data);
			break;
		case '7':
			printf("---------------7.��ѯ�ڵ��Ƿ����-----------\n");
			break;
		case '8':
			printf("---------------8.�ж������Ƿ�ɻ�-----------\n");
			break;
		case '9':
			printf("---------------9.����������������--------\n");
			break;
		default:
			printf("�����������");
		break;			
	}
}



int main(){
	while(1){
		keyBoard();
	}
	
	
	return 0;
} 
