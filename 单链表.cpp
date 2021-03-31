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

//创建链表 
Node* List=CreateList();

//销毁链表 
void DestroyList(Node* headNode){
	Node* p1=headNode;
	
}

//插入链表(头插法)
void InsertByHead(Node* headNode,int data){
	Node* p=CreateNode(data);
	p->next=headNode->next;
	headNode->next=p;
} 



//删除指定节点 
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
	printf("你输入的信息有误！");
}

//遍历链表==输出对应信息 
void printList(Node* headNode){
	Node* pMove=headNode->next;
	while(pMove->next!=NULL){
		printf("%d->",pMove->data);
		pMove=pMove->next;
	}
	printf("%d",pMove->data);
} 

//找出链表的中间节点并打印出其数据 
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
	printf("                  *单链表*                  \n");
	printf("---------------1.插入节点-------------------\n");
	printf("---------------2.输出链表-------------------\n");
	printf("---------------3.反向链接列表---------------\n");
	printf("---------------4.调换奇偶顺序---------------\n");
	printf("---------------5.找到中间节点---------------\n");
	printf("---------------6.删除节点-------------------\n");
	printf("---------------7.查询节点是否存在-----------\n");
	printf("---------------8.判断链表是否成环-----------\n");
	printf("---------------9.销毁链表，结束进程--------\n");
	char ch=getch();
	switch(ch){
		case '1':
			printf("---------------1.插入节点-------------------\n");
			int data;
			printf("请输入一个整数：");
			scanf("%d",data);
			InsertByHead(List,data);
			break;
		case '2':
			printf("---------------2.输出链表-------------------\n");
			printList(List);
			break;
		case '3':
			printf("---------------3.反向链接列表---------------\n");
			
			break;
		case '4':
			printf("---------------4.调换奇偶顺序---------------\n");
			break;
		case '5':
			printf("---------------5.找到中间节点---------------\n");
			FindMidNode(List);
			break;
		case '6':
			printf("---------------6.删除节点-------------------\n");
			printList(List);
			printf("请输入你要删除的节点数据（整数）"); 
			int Data;
			scanf("%d",Data);
			DeleteNode(List,Data);
			break;
		case '7':
			printf("---------------7.查询节点是否存在-----------\n");
			break;
		case '8':
			printf("---------------8.判断链表是否成环-----------\n");
			break;
		case '9':
			printf("---------------9.销毁链表，结束进程--------\n");
			break;
		default:
			printf("你的输入有误！");
		break;			
	}
}



int main(){
	while(1){
		keyBoard();
	}
	
	
	return 0;
} 
