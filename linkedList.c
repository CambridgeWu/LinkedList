#include "linkedList.h"
#include "malloc.h"
#include<stdio.h>

LNode* CreateNode(int data){
	LNode* newNode=(LNode*)malloc(sizeof(LNode));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L=(LinkedList)malloc(sizeof(LNode));
	(*L)->next=NULL;
	return SUCCESS;
}
 
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList* p;
	while((*L)->next){
		*p=*L;
		*L=(*L)->next;
		free(*p);              //free all the nodes
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(!p){ 
		return ERROR;
	} 
	if(p->next==NULL){
		p->next=q;
		return SUCCESS;
	}
	LNode* pbehind=p->next;
	q->next=pbehind;
	p->next=q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(!p||p->next==NULL){
		return ERROR;
	}
	LNode* p1=p;
	LNode* p2=p->next;
	p1->next=p2->next; 
	*e=p2->data;
	free(p2);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode* pMove=L->next;
	while(pMove){
		visit(pMove->data);
		pMove=pMove->next; 
	}
}

void visit(ElemType e){
	printf("%d\t",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode* pMove=L;
	while(pMove){
		if(pMove->data==e){
			return SUCCESS;
		}
		pMove=pMove->next;
	}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
int add_node_head(LinkedList head,LNode* newNode){
	if(NULL==head||NULL==newNode){
		return -1;
	}
	newNode->next=head->next;
	head->next=newNode;
	return 0;
	
}

Status ReverseList(LinkedList *L) {
	LNode* p1=(*L)->next;
	LNode* p2=NULL;
	while(p2=p1->next){
		p1->next=p2->next;
		add_node_head(*L,p2);
	} 
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode* pfast=L;
	LNode* pslow=L->next;
	int num=0;
	while(1){
		if(num%5==0){
			pslow=pslow->next;
		}
		if(pfast==pslow){
			return SUCCESS;
		}
		if(pfast->next==NULL){
			return ERROR;
		}
		pfast=pfast->next;
		num++;
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */

LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p,q,t;
 	p=(*L)->next;
 	q=p->next;
 	t=q->next;
 	p->next=t;
 	q->next=p;
 	(*L)->next=q;
 	while(t!=NULL&&t->next!=NULL){
  		q=t->next;
  		t=q->next;
  		p->next->next=t;
  		q->next=p->next;
  		p->next=q;
 		p=q->next;
 		}
 	return (*L);
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode* mid=(*L)->next;
	LNode* pMove=(*L)->next;
	
	printf("中间节点数据为：");
	
	while(pMove){
		if(pMove->next==NULL){
			printf("%d",mid->data);       //如果头节点下一个为空，则输出该节点的数据 
			return mid;
		}
		pMove=pMove->next->next;          
		if(pMove==NULL){
			printf("%d,%d",mid->data,mid->next->data);
			return mid;
		}
		mid=mid->next;
	}
}

