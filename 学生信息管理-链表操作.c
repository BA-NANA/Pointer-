#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <windows.h> 
#include <time.h> 
#define LEN sizeof(struct Student)
/* 
	author-BA_NANA 天津理工大学 
*/ 
 struct Student{
 	long int id;
 	char name[100];
 	char sex[10];
 	int age;
 	struct Student*next;
 };
 int n;
 
 struct Student *creat() //初始化学生链表 
 {
 	struct Student *head;
 	struct Student *p1,*p2;
 	head = NULL;
	n = 0;
	p1 = p2 = (struct student*)malloc(LEN);
	scanf("%ld %s %s %d",&p1->id,&p1->name,&p1->sex,&p1->age);
	while(1){
		n = n + 1;
		if(n==1) head = p1;
		else{
			p2->next = p1;
			p2 = p1;
			p1 = (struct student*)malloc(LEN);
			scanf("%ld %s %s %d",&p1->id,&p1->name,&p1->sex,&p1->age);
			if(p1->id==0){
				p1=NULL;
				break;
			} 
		}
	}
	p2->next=NULL;
	printf("初始化完成！\n"); 
	return head;
 } 
 
 void showALL(struct Student*head) //输出当前所有同学信息
 {
 	struct Student*p;
 	p = head;
 	
 	if(p!=NULL){
 		printf("现在有%d名学生，信息如下\n",n-1);
 		
		 while(p!=NULL){
 			printf("%ld %s %s %d\n",p->id,p->name,p->sex,p->age);
 			p=p->next;
		 }
	 }
	 else{
	 	printf("数据为空\n");
	 } 
	 
  } 
  
int clearStudentLink(struct Student *head) //清空当前链表 
  {
  	struct Student*p;
  	struct student*q;
  
  	p=head->next;
  	printf("正在清除当前链表...\n");
  	if(p==NULL){
  		return -1;
	  }
	while(p){
		q=p->next;
		free(p);
		p=q;
		n--;
	}
	//if(p!=NULL){        //清空最后一个节点 
	//	free(p);
	//	free(tem);
	//} 
	head->next=NULL;
	head=NULL;
	printf("清空完成!\n");
}

int isExist(struct Student*head,long int id) //判断学生信息是否存在 
{
	struct Student*p;
	p = head;
	long int num = id;
	while(p!=NULL){
		if(p->id==num){
			printf("找到了!\n");
			return 0;
		}
		p=p->next;
	}
	printf("没找到...\n");
	return 0; 
}

//添加新同学信息到链表尾端 
void Add(struct Student *head,long int id,char name[],char sex[],int age)
{
	struct Student*p;
	struct Student*tem;
	p=head;
	
	while(1){
		if(p==NULL){
			p=(struct Student*)malloc(LEN);
			p->id = id;
			strcpy(p->name,name);
			strcpy(p->sex,sex);
			p->age = age;
			n++;
			p->next=NULL;
			tem->next=p;
			break; 
		}
		else{
			tem=p;
		}
		p=p->next;
	}
	printf("添加完成!\n"); 
}

//修改学生信息 
void Modify(struct Student *head,long int id,char name[],char sex[],int age)
{
	struct Student*p;
	p=head;
	
	while(p!=NULL){
		if(p->id == id){
			strcpy(p->name,name);
			strcpy(p->sex,sex);
			p->age = age;
			break;
		}
		p=p->next;
	}
	printf("修改完成!\n");
}

//删除学生信息 
struct Student* Delete(struct Student*head,long int id)
{
	struct Student*pb;
	struct Student*pf;
	pb=head;
	if(head==NULL){
		printf("链表为空！\n");
		return ; 
	} 
	
	while(pb->id!=id&&pb->next!=NULL){
		pf=pb;
		pb=pb->next;
	}
	if(pb->id==id)
	{
		if(pb==head){
			head=head->next;
			n--;
			printf("删除%ld学生完成!\n",id);
		} 
	
		else
		{
			pf->next=pb->next;
			n--;
			printf("删除%ld学生完成!\n",id);
		}
		free(pb);
		return head;
	}
	else printf("没找到该学生...\n"); 
}

//输出显示该同学信息 
void Search(struct Student*head,long int id)
{
	struct Student*p;
	p=head;
	while(1){
		if(p->id == id){
			printf("该学生信息为 学号:%ld 姓名:%s 性别:%s 年龄%d\n",p->id,p->name,p->sex,p->age);
			break;
		}
		if(p==NULL){
			printf("没有该学生，请重新输入\n"); 
			break;
		}
		p=p->next;	
	}
}

void start()
{
	system("color FD"); 
	
	printf("欢迎来到史上最强大的BA_NANA学生管理系统V1.0，请输入数字选择你要进行的操作\n"
	"1.学生信息初始化(链表)\n2.判断学生信息是否存在\n3.添加新同学至表尾\n4.修改学生信息\n"
	"5.删除某个同学信息\n6.显示某个同学信息\n7.输出所有同学信息\n8.清空链表\n9.清空屏幕\n10.退出程序\n"); 
	struct Student *head;
	head = NULL;
	int num,age,ret; 
	long int id;
	char name[20],sex[20];
	
	while(scanf("%d",&num)!=EOF){
		if(num==1) {
			printf("请依次输入学生id 名字 性别 年龄以添加信息,id为0时结束\n");
			head=creat();
		}
		if(num==2){
			printf("请输入学生id进行下一步操作\n");
			scanf("%ld",&id);
			isExist(head,id);
		}
		if(num==3){
			printf("请输入学生id 名字 性别 年龄以添加信息至表尾\n");
			scanf("%ld %s %s %d",&id,&name,&sex,&age); 
			Add(head,id,name,sex,age);
		}
		if(num==4){
			printf("请输入学生id 要修改的名字 要修改的性别 要修改的年龄\n");
			scanf("%ld %s %s %d",&id,&name,&sex,&age); 
			Modify(head,id,name,sex,age);
		}
		if(num==5){
			printf("请输入要删除的学生id\n");
			scanf("%ld",&id);
			head=Delete(head,id);
		}
		if(num==6){
			printf("请输入要显示信息的学生id\n");
			scanf("%ld",&id);
			Search(head,id);
		}
		if(num==7){
			showALL(head);
		}
		if(num==8){
			ret=clearStudentLink(head);
		}
		if(num==9){
			system("cls");
			printf("欢迎来到史上最强大的BA_NANA学生管理系统V1.0，请输入数字选择你要进行的操作\n"
	"1.学生信息初始化(链表)\n2.判断学生信息是否存在\n3.添加新同学至表尾\n4.修改学生信息\n"
	"5.删除某个同学信息\n6.显示某个同学信息\n7.输出所有同学信息\n8.清空链表\n9.清空屏幕\n10.退出程序\n"); 
		}
		if(num==10){
			break;
		}
		printf("----------------请输入下一次操作指令------------------\n") ; 
	}
}

int main()
{
	start();
	return 0;
}
  
  
  
  
  
  
  
