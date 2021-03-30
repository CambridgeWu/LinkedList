#include<stdio.h>
#include "linkedList.h"
#include<stdlib.h>
#include<conio.h>

LinkedList L;

//寻找节点位置并返回该节点
LNode* FindNode(LinkedList* L,ElemType site){
	LNode* pMove=*L;
	if((*L)==NULL){
		printf("链表为空！");
		return NULL;
	}
	int i=0;
	while(i<site){
		pMove=pMove->next;
		i++;
	}
	return pMove;
} 

void FillDataByEnd(LinkedList L){
	printf("请输入你要存储的数据(整数)：");
	int data;
	scanf("%d",&data);
	LNode* newNode=CreateNode(data);
	LNode* pMove=L;
	while(pMove->next!=NULL){
		pMove=pMove->next;
	}
	pMove->next=newNode;
}


//用户操作界面 
void keyBoard(){
	printf("                  *单链表*                  \n");
	printf("---------------a.链表数据存储---------------\n");
	printf("---------------b.插入节点-------------------\n");
	printf("---------------c.输出链表-------------------\n");
	printf("---------------d.反向链接列表---------------\n");
	printf("---------------e.调换奇偶顺序---------------\n");
	printf("---------------f.找到中间节点---------------\n");
	printf("---------------g.删除节点-------------------\n");
	printf("---------------h.查询节点是否存在-----------\n");
	printf("---------------i.判断链表是否成环-----------\n");
	printf("---------------j.销毁链表，结束进程---------\n\n\n");
	char ch=getch();
	switch(ch){
		case 'a':
			printf("---------------a.链表数据存储---------------\n\n");
			FillDataByEnd(L);
			printf("存储成功！\n");
			printf("按任意键继续...");
			getch();
			break;
		case 'b':
			printf("---------------b.插入节点-------------------\n");
			TraverseList(L,visit);             //展示当前的链表信息 
			printf("\n\n\n");
			printf("请输入你要在第几个后面进行插入处理(整数):");
			int site;
			scanf("%d",&site);
			printf("请输入插入节点数据(整数)：");
			int data;
			scanf("%d",&data);
			if(InsertList(FindNode(&L,site),CreateNode(data))){
				printf("插入成功！\n");
			}
			else{
				printf("插入失败！\n");
			}
			printf("按任意键继续...");
			getch();
			break;
		case 'c':
			printf("---------------c.输出链表-------------------\n");
			TraverseList(L,visit);
			printf("\n按任意键继续...");
			getch();
			break;
		case 'd':
			printf("---------------d.反向链接列表---------------\n");
			ReverseList(&L);
			printf("按任意键继续...");
			getch();
			break;
		case 'e':
			printf("---------------e.调换奇偶顺序---------------\n");
			ReverseEvenList(&L);
			printf("按任意键继续...");
			getch();
			break;
		case 'f':
			printf("---------------f.找到中间节点---------------\n");
			FindMidNode(&L);
			printf("\n按任意键继续...");
			getch();
			break;
		case 'g':
			printf("---------------g.删除节点-------------------\n"); 
			//delete the first node after the node p and assign its value to e
			TraverseList(L,visit);
			printf("\n\n");
			printf("请输入你要删除节点的位置(整数):\n");
			int Site;
			scanf("%d",&Site);
			int e;
			DeleteList(FindNode(&L,Site-1),&e);
			printf("该删除节点的数据为%d\n",e);
			printf("按任意键继续...");
			getch();
			break;
		case 'h':
			printf("---------------h.查询节点是否存在-----------\n");
			printf("请输入你要查询的节点数据(如果数据相同则存在):\n");
			int E;
			scanf("%d",&E);
			if(SearchList(L,E))
			{
				printf("该节点存在！\n");
			}
			else{
				printf("该节点不存在！\n");
			}
			printf("按任意键继续...");
			getch();
			break;
		case 'i':
			printf("---------------i.判断链表是否成环-----------\n");
			if(IsLoopList(L)){
				printf("链表成环\n");
			}
			else{
				printf("链表不成环\n"); 
			}
			printf("按任意键继续...");
			getch();
			break;
		case 'j':
			printf("---------------j.销毁链表，结束进程--------\n");
			DestroyList(&L);
			printf("\n按任意键继续...");
			getch();
			break;
		default:
			printf("你的输入有误！");
			printf("按任意键继续...");
			getch();
		break;			
	}
}

int main(){
	InitList(&L);  //先初始化链表 
	while(1){
		system("cls");
		keyBoard();
	}
	return 0;
}
