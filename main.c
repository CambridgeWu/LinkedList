#include<stdio.h>
#include "linkedList.h"
#include<stdlib.h>
#include<conio.h>

LinkedList L;

//Ѱ�ҽڵ�λ�ò����ظýڵ�
LNode* FindNode(LinkedList* L,ElemType site){
	LNode* pMove=*L;
	if((*L)==NULL){
		printf("����Ϊ�գ�");
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
	printf("��������Ҫ�洢������(����)��");
	int data;
	scanf("%d",&data);
	LNode* newNode=CreateNode(data);
	LNode* pMove=L;
	while(pMove->next!=NULL){
		pMove=pMove->next;
	}
	pMove->next=newNode;
}


//�û��������� 
void keyBoard(){
	printf("                  *������*                  \n");
	printf("---------------a.�������ݴ洢---------------\n");
	printf("---------------b.����ڵ�-------------------\n");
	printf("---------------c.�������-------------------\n");
	printf("---------------d.���������б�---------------\n");
	printf("---------------e.������ż˳��---------------\n");
	printf("---------------f.�ҵ��м�ڵ�---------------\n");
	printf("---------------g.ɾ���ڵ�-------------------\n");
	printf("---------------h.��ѯ�ڵ��Ƿ����-----------\n");
	printf("---------------i.�ж������Ƿ�ɻ�-----------\n");
	printf("---------------j.����������������---------\n\n\n");
	char ch=getch();
	switch(ch){
		case 'a':
			printf("---------------a.�������ݴ洢---------------\n\n");
			FillDataByEnd(L);
			printf("�洢�ɹ���\n");
			printf("�����������...");
			getch();
			break;
		case 'b':
			printf("---------------b.����ڵ�-------------------\n");
			TraverseList(L,visit);             //չʾ��ǰ��������Ϣ 
			printf("\n\n\n");
			printf("��������Ҫ�ڵڼ���������в��봦��(����):");
			int site;
			scanf("%d",&site);
			printf("���������ڵ�����(����)��");
			int data;
			scanf("%d",&data);
			if(InsertList(FindNode(&L,site),CreateNode(data))){
				printf("����ɹ���\n");
			}
			else{
				printf("����ʧ�ܣ�\n");
			}
			printf("�����������...");
			getch();
			break;
		case 'c':
			printf("---------------c.�������-------------------\n");
			TraverseList(L,visit);
			printf("\n�����������...");
			getch();
			break;
		case 'd':
			printf("---------------d.���������б�---------------\n");
			ReverseList(&L);
			printf("�����������...");
			getch();
			break;
		case 'e':
			printf("---------------e.������ż˳��---------------\n");
			ReverseEvenList(&L);
			printf("�����������...");
			getch();
			break;
		case 'f':
			printf("---------------f.�ҵ��м�ڵ�---------------\n");
			FindMidNode(&L);
			printf("\n�����������...");
			getch();
			break;
		case 'g':
			printf("---------------g.ɾ���ڵ�-------------------\n"); 
			//delete the first node after the node p and assign its value to e
			TraverseList(L,visit);
			printf("\n\n");
			printf("��������Ҫɾ���ڵ��λ��(����):\n");
			int Site;
			scanf("%d",&Site);
			int e;
			DeleteList(FindNode(&L,Site-1),&e);
			printf("��ɾ���ڵ������Ϊ%d\n",e);
			printf("�����������...");
			getch();
			break;
		case 'h':
			printf("---------------h.��ѯ�ڵ��Ƿ����-----------\n");
			printf("��������Ҫ��ѯ�Ľڵ�����(���������ͬ�����):\n");
			int E;
			scanf("%d",&E);
			if(SearchList(L,E))
			{
				printf("�ýڵ���ڣ�\n");
			}
			else{
				printf("�ýڵ㲻���ڣ�\n");
			}
			printf("�����������...");
			getch();
			break;
		case 'i':
			printf("---------------i.�ж������Ƿ�ɻ�-----------\n");
			if(IsLoopList(L)){
				printf("����ɻ�\n");
			}
			else{
				printf("�����ɻ�\n"); 
			}
			printf("�����������...");
			getch();
			break;
		case 'j':
			printf("---------------j.����������������--------\n");
			DestroyList(&L);
			printf("\n�����������...");
			getch();
			break;
		default:
			printf("�����������");
			printf("�����������...");
			getch();
		break;			
	}
}

int main(){
	InitList(&L);  //�ȳ�ʼ������ 
	while(1){
		system("cls");
		keyBoard();
	}
	return 0;
}
