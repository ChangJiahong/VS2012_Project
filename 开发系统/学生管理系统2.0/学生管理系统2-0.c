#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 1000
struct Date
{
	int year;   //年
	int month;  //月
	int day;    //日 
};
struct Major
{
	float math;   //高数 
	float Eglish; //英语 
	float C;      //C语言 
};
struct Student
{
	char num[20];             //学号 
	char name[20];       //姓名 
	char ID[18];         //身份证号 
	int sex;            //性别
	int age;             //年龄
	struct Date birth;   //年、月、日 
	struct Major score;  //三门课分数 
	float sum;           //总分 
	float aver;          //平均分 
}stu[N];

struct Data       //用户数据结构体 
{
	char names[20];
	char password[20];
}user[100];

char file[20];   //全局变量，打开的文件名 
float sum=0,math_sum=0,Eglish_sum=0,C_sum=0;  //全局变量，总分
int S=0,Y=0;  //全局变量，学生总数
char NAME[20];

void data_open()
{
	FILE *f;
	int i;
	if((f=fopen("data.dat","rb"))==NULL)
	{
		printf("打开数据文件失败！");
		return; 
	 } 
	if(fread(&Y,sizeof(int),1,f)!=1)  //读入 用户总数 Y 
		{
			if(feof(f))
			{
				fclose(f);
				return ;
			}
			printf("读入文件出错！\n"); 
		}
		for(i=0;i<Y;i++)
			if(fread(&user[i],sizeof(struct Data),1,f)!=1)  //读入学生信息，Student结构体 
			{
				if(feof(f))
				{
					fclose(f);
					return ;
				}
			printf("读入文件出错！\n");
			}
		fclose(f);   //关闭 file文件，f指向file 
		printf("......"); 
}

void data_save()
{
	FILE *f;
	int i;
	if((f=fopen("data.dat","wb"))==NULL)
	{
		printf("无法打开此文件！\n");
		return;
	}
	if (fwrite(&Y,sizeof(int),1,f)!=1)   //保存用户总数Y 
	printf("文件保存出错!\n");
	for(i=0;i<Y;i++)
	   if(fwrite(&user[i],sizeof(struct Data),1,f)!=1)   //保存学生信息，Student结构体 
	      printf("文件保存出错！\n");
	fclose(f);
	printf("\t\t\t注册成功！\n");
}

void login()
{
	int a,i,j=0,k,f=1;
	char c;
	struct Data t;
	data_open();
	while(1)
	{
	system("cls");
	printf("\n\n\t\t\t\t    欢迎登陆学生管理系统\n");
	printf("\t\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t*          1、登陆          *\n");
	printf("\t\t\t\t*          2、注册          *\n");
	printf("\t\t\t\t*          0、退出          *\n");
	printf("\t\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t    请选择：");
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		while(1)
		{
			printf("\n\t\t\t\t用户名：");
			scanf("%s",t.names);
			strcpy(NAME,t.names);
			printf("\t\t\t\t密码：");
			scanf("%s",t.password);
			for(i=0;i<Y;i++)
			{
				if(strcmp(t.names,user[i].names)==0) j=i;
			 } 
			if(strcmp(t.password,user[j].password)==0) break;
			else printf("\n\t\t\t    用户名或密码不正确！\n"); 
	    }
	    if(strcmp(t.password,user[j].password)==0) break;
	}
	else if(a==2)
	     {
	     	
	        k=Y;
	     	++Y;
	     	 while(f)
	     	 {
			  
	        printf("\n\t\t\t\t请输入用户名：");
	     	scanf("%s",t.names);
	     	
	        for(i=0;i<Y;i++)
	        {
	        	 if(strcmp(t.names,user[i].names)==0) j=i;
			}
	        if(strcmp(t.names,user[j].names)==0)
	                            printf("\n\t\t\t\t  用户名重复！\n");
			else  {
			      strcpy(user[k].names,t.names);
			      break;
			      }
	    }
			printf("\t\t\t\t请设置密码：");
			scanf("%s",user[k].password); 
			data_save();
			printf("\n按回车键返回！");
			c=getchar();
			c=getchar();
		 }
	else if(a==0) exit(0); 
    }	
}
void averger()
{
	int i;
	for(i=0;i<S;i++)
	{
		sum=sum+stu[i].aver;       //班级个人平均分总分 
		math_sum=math_sum+stu[i].score.math; //全班数学总分
		Eglish_sum=Eglish_sum+stu[i].score.Eglish; //全班英语总分
		C_sum=C_sum+stu[i].score.C;  //全班C语言总分 
	}
	sum/=S*1.0;
	math_sum/=S*1.0;
	Eglish_sum/=S*1.0;
	C_sum/=S*1.0;
}

void stu_ID(int i)
{
	if((stu[i].ID[16]-48)%2==0)
	  stu[i].sex=0;
	else stu[i].sex=1;
	stu[i].age=2016-((stu[i].ID[6]-48)*1000+(stu[i].ID[7]-48)*100+(stu[i].ID[8]-48)*10+stu[i].ID[9]-48);
	stu[i].birth.year=(stu[i].ID[6]-48)*1000+(stu[i].ID[7]-48)*100+(stu[i].ID[8]-48)*10+stu[i].ID[9]-48;
	stu[i].birth.month=(stu[i].ID[10]-48)*10+stu[i].ID[11]-48;
	stu[i].birth.day=(stu[i].ID[12]-48)*10+stu[i].ID[13]-48; 
}

void input()
{
	int i=0;
	char c;
	while(1)
	{
		system("cls");
		printf("     学生%d. \n",++S);
		printf("学 号："); 
		scanf("%s",stu[i].num);
		if(stu[i].num==0) break;
		printf("姓 名："); 
		scanf("%s",stu[i].name);
		printf("身份证号：");
		scanf("%s",stu[i].ID);
		printf("高数成绩：");
		scanf("%f",&stu[i].score.math);
		printf("英语成绩：");
		scanf("%f",&stu[i].score.Eglish);
		printf("C语言成绩：");
		scanf("%f",&stu[i].score.C);
		stu_ID(i);
		stu[i].sum=stu[i].score.math+stu[i].score.Eglish+stu[i].score.C;  //个人总分 
		stu[i].aver=stu[i].sum/3.0;     //个人平均分
		i++;
		printf("是否继续(Y/N):");
		scanf(" %c",&c);           //输入字符
		if(c=='n'||c=='N') break;  //判断是否继续 
	}
}

void stu_print(int i)
{
	printf("查找信息如下:\n\n");
	printf("\t学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
	printf("———————————————————————————————");
	printf("—————————————————————————————\n"); 
	printf("\t%s\t%s",stu[i].num,stu[i].name);
	if(stu[i].sex==0) printf("\t女");
	else printf("\t男");
	printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
	       stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
}

void search()
{
	int i,j,f=0;
	char c,_name[20],_num[20],a;
	while(1)
    {   
	    system("cls");
		printf("\n请选择查找方式：\n\n");
		printf("\tA、按学号查找\n\tB、按姓名查找\n\tC、按身份证查找\n\tD、返回\n");
		printf("\n请选择：");
		scanf(" %c",&c);
		if(c=='d'||c=='D') break;
		if(c=='a'||c=='A')
		{
			printf("请输入需要查找的学号：");
		    scanf("%s",_num);
			for(i=0;i<S;i++)
			  if(strcmp(_num,stu[i].num)==0) f=1,j=i;   //输出学生信息	   	
			if(f==1) stu_print(j);
			else printf("查找无果！\n");
			printf("是否继续查找(Y/N):");
		    scanf(" %c",&a);
		    if(a=='n'||a=='N') break;
		}
		else if(c=='b'||c=='B')
		{
			printf("请输入需要查找的姓名：");
			scanf("%s",_name);
			for(i=0;i<S;i++)
			   if(strcmp(_name,stu[i].name)==0) f=1,j=i;  //输出学生信息 
			if(f==1) stu_print(j);
			else printf("查找无果！\n");
			printf("是否继续查找(Y/N):");
		    scanf(" %c",&a);
		    if(a=='n'||a=='N') break;
		}
		
    }
}

void _show()
{
	int i;
	system("cls");
	printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
	for(i=0;i<S;i++)
	{
	    printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
        if(stu[i].sex==0) printf("\t女");
         else printf("\t男");
        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
        stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
	} 
}
void show()
{
	char c;
	while(1)
	{
		_show();
		averger();
		printf("\n全班平均分：%.2f\n",sum);
		printf("全班高数平均分：%.2f\n",math_sum);
		printf("全班英语平均分：%.2f\n",Eglish_sum);
		printf("全班C语言平均分：%.2f\n",C_sum);
		printf("\n按回车键返回！");
		c=getchar();
		if(getchar()) break;
    }
 } 

void add()
{
	int i;
	char c; 
	while(1)
	{
		system("cls");
		i=S;
		printf("\t增加学生%d\n",++S);
		printf("学 号：");
		scanf("%s",stu[i].num);
		if(stu[i].num==0) break;
		printf("姓 名："); 
		scanf("%s",stu[i].name);
		printf("身份证号：");
		scanf("%s",stu[i].ID);
		printf("高数成绩：");
		scanf("%f",&stu[i].score.math);
		printf("英语成绩：");
		scanf("%f",&stu[i].score.Eglish);
		printf("C语言成绩：");
		scanf("%f",&stu[i].score.C);
		stu_ID(i);
		stu[i].sum=stu[i].score.math+stu[i].score.Eglish+stu[i].score.C;  //个人总分 
		stu[i].aver=stu[i].sum/3.0;     //个人平均分
		i++;
		printf("是否继续添加(Y/N):");
		scanf(" %c",&c);           //输入字符
		if(c=='n'||c=='N') break;  //判断是否继续 
		
	}
}

void amendment()
{
	int i,a,b;
	char c;
	while(1)
	{
		_show();
		printf("\n请输入修改学生的序号：");
		scanf("%d",&b);
		if(b==0) break;
		i=b-1;          //i是数组序号比学生序号小一 
		system("cls");
		printf("\t学生%d\n",b);
		printf("请选择修改的信息：\n");
		printf("1、学号\n2、姓名\n3、身份证号\n4、高数成绩\n5、英语成绩\n6、C语言成绩\n\n");
		printf("请选择：");
		scanf("%d",&a);
		if(a==1)
		{
			printf("请输入新的学号：");
			scanf("%s",stu[i].num); 
		}
		else if(a==2)
		{
			printf("请输入新的姓名："); 
			scanf("%s",stu[i].name); 
		}
		else if(a==3)
		{
			printf("请输入新的身份证号：");
			scanf("%s",stu[i].ID);
			stu_ID(i);
		}
		else if(a==4)
		{
			printf("请输入新的高数成绩：");
			scanf("%d",&stu[i].score.math);
		}
		else if(a==5)
		{
			printf("请输入新的英语成绩：");
			scanf("%d",&stu[i].score.Eglish); 
		}
		else if(a==6)
		{
			printf("请输入新的C语言成绩：");
			scanf("%d",&stu[i].score.C);
		}
		printf("是否继续(Y/N):");
		scanf(" %c",&c);       //输入字符
		if(c=='n'||c=='N') break;  //判断是否继续  
	}
}

void sort()
{
	int i,a,b,j,k;
	struct Student t; 
	char _name[20],c,d;
	while(1)
	{
		system("cls");
		printf("\t请选择排序方式：\n");
		printf("  1、按学号排序\n  2、按姓名排序\n  3、按高数成绩排序\n  4、按英语成绩排序\n");
		printf("  5、按C语言成绩排序\n  6、按平均分排序\n  7、按总分排序\n  0、返回\n\n");
		printf("请选择：");
		scanf("%d",&a);
		if(a==0) break;
		system("cls");
		printf("\n1、升序\n2、降序\n0、返回\n\n");
		printf("请选择：");
		scanf("%d",&b);
		switch(a)
		{
			case 1: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(strcmp(stu[j].num,stu[k].num)<0) k=j;
			                 	t=stu[i];
			                 	stu[i]=stu[k];
			                 	stu[k]=t;
			                 }
			        else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(strcmp(stu[j].num,stu[k].num)>0) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
				                 }
			        break;
			case 2: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(strcmp(stu[j].name,stu[k].name)<0) k=j;
			                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
							 }
				    else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(strcmp(stu[j].name,stu[k].name)>0) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
								 }
					break;
			case 3: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(stu[j].score.math<stu[k].score.math) k=j;
			                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
			                 }
			        else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(stu[j].score.math>stu[k].score.math) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
				                 }
				    break;
			case 4: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(stu[j].score.Eglish<stu[k].score.Eglish) k=j;
			                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
			                 }
			        else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(stu[j].score.Eglish>stu[k].score.Eglish) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
				                 }
				    break;
			case 5: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(stu[j].score.C<stu[k].score.C) k=j;
			                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
			                 }
			        else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(stu[j].score.C>stu[k].score.C) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
				                 }
				    break;
			case 6: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(stu[j].aver<stu[k].aver) k=j;
			                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
			                 }
			        else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(stu[j].aver>stu[k].aver) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
				                 }
			        break;
			case 7: if(b==1) for(i=0;i<S-1;i++)
			                 {
			                 	k=i;
			                 	for(j=i+1;j<S;j++)
			                 	if(stu[j].sum<stu[k].sum) k=j;
			                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
			                 }
			        else if(b==2) for(i=0;i<S-1;i++)
				                 {
				                 	k=i;
				                 	for(j=i+1;j<S;j++)
				                 	if(stu[j].sum>stu[k].sum) k=j;
				                 	t=stu[i];
				                 	stu[i]=stu[k];
				                 	stu[k]=t;
				                 }
				    break;
			case 0: break;
			 } 
		if(b==0) break;
		else
		{
			printf("\n排序完成！\n\n");
			printf("是否查看排序结果(Y/N):");
			scanf(" %c",&c);
			if(c=='n'||c=='N') break;
			else _show();
			printf("\n是否继续排序(Y/N):");
			scanf(" %c",&d);           //输入字符
			if(d=='n'||d=='N') break;  //判断是否继续 
		}
		
	}
}

void screen()
{
	int i,a,b;
	char c;
	while(1)
	{
		system("cls");
		printf("  1、高数成绩\n  2、英语成绩\n  3、C语言成绩\n  4、平均分\n  0、返回\n\n");
		printf("请选择：");
		scanf("%d",&a);
		if(a==0) break;
		system("cls");
		printf("\n1、及格\n2、不及格\n0、返回\n\n");
		printf("请选择：");
		scanf("%d",&b);
		if(b==0) break;
		switch(a)
		{
			case 1: if(b==1)
			        system("cls");
					printf("\t高数及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].score.math>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\t高数不及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].score.math<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
		    case 2: if(b==1)
		            system("cls");
					printf("\t英语及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].score.Eglish>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\t英语不及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].score.Eglish<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
			case 3: if(b==1)
		            system("cls");
					printf("\tC语言及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].score.C>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\tC语言不及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].score.C<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
			case 4: if(b==1)
		            system("cls");
					printf("\t平均分及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].aver>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\t平均分不及格人如下：\n"); 
					printf("序号   学号\t姓名\t性别\t年龄\t出生日期\t   身份证号\t\t高数\t英语\tC语言\t平均分\t总分\n");
					for(i=0;i<S;i++)
					if(stu[i].aver<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\t女");
				         else printf("\t男");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
			case 0: break; 
		}
		if(b==0) break;
	    else 
	    {
	    	printf("\n是否继续筛选(Y/N):");
			scanf(" %c",&c);           //输入字符
			if(c=='n'||c=='N') break;  //判断是否继续
		}
	}
}

void open()
{
	int i;
	char c;   // 打开的文件名         
	FILE *f;        //文件指针 
	while(1)
	{
		system("cls");  //清屏 
		printf("请输入要打开的文件名：\n");
		scanf("%s",file);
		if((f=fopen(file,"rb"))==NULL)   //打开“file”文件 ，f指向file 
		  {
		  	printf("无法打开此文件！\n");
		  	return;
		  }
		if(fread(&S,sizeof(int),1,f)!=1)  //读入学生总数 S 
		{
			if(feof(f))
			{
				fclose(f);
				return ;
			}
			printf("读入文件出错！\n"); 
		}
		for(i=0;i<S;i++)
			if(fread(&stu[i],sizeof(struct Student),1,f)!=1)  //读入学生信息，Student结构体 
			{
				if(feof(f))
				{
					fclose(f);
					return ;
				}
			printf("读入文件出错！\n");
			}
		fclose(f);   //关闭 file文件，f指向file 
		printf("打开成功！"); 
		printf("\n按回车键返回！");
		c=getchar();
		if(getchar()) break;
	}
 } 
 
void save()
{
	int a,i;
	char file1[20],file2[20],c;
	FILE *f1,*f2;
	while(1)
	{
		system("cls");
		printf("请选择保存方式：\n");
		printf("\n  1、保存\n  2、另存为\n  0、返回\n");
		printf("\n请选择：");
		scanf("%d",&a);
		if(a==0) break;
		if(a==1)
		{
			if((f1=fopen(file,"wb"))==NULL)  //打开p指向的文件，即open函数打开的文件 
			{
				printf("无法打开此文件！\n"); 
				return;
			}
			if (fwrite(&S,sizeof(int),1,f1)!=1)  //保存学生总数 S 
			printf("文件保存出错!\n");
			for(i=0;i<S;i++)
			   if(fwrite(&stu[i],sizeof(struct Student),1,f1)!=1)   //保存学生信息，Student结构体 
			      printf("文件保存出错！\n");
			fclose(f1);
			printf("保存成功！\n");
		}
		else if(a==2)
		{
			printf("文件名：");
			scanf("%s",file1);
			if((f2=fopen(file1,"wb"))==NULL)
			{
				printf("无法打开此文件！\n");
				return;
			}
			if (fwrite(&S,sizeof(int),1,f2)!=1)   //保存学生总数 S 
			printf("文件保存出错!\n");
			for(i=0;i<S;i++)
			   if(fwrite(&stu[i],sizeof(struct Student),1,f2)!=1)   //保存学生信息，Student结构体 
			      printf("文件保存出错！\n");
			fclose(f2);
			printf("保存成功！\n");
		}
	printf("\n按回车键返回！");
	c=getchar();
	if(getchar()) break;
    }
}                 

int main()
{
	int n;
	login();
	while(1)
	{
		system("cls");
		printf("欢迎%s!\n",NAME);
		printf("\t\t\t\t  学生管理系统\n");
		printf("\t\t\t* * * * * * * * * * * * * * * *\n"); 
		printf("\t\t\t* ___________________________ *\n");
		printf("\t\t\t* |                         | *\n"); 
		printf("\t\t\t* |        1、打开          | *          那 蓦 众  为 衣  望 独 昨 \n");
		printf("\t\t\t* |        2、输入          | *          人 然 里  伊 带  尽 上 夜  人 \n");
		printf("\t\t\t* |        3、显示          | *          却 回 寻  消 渐  天 高 西  生\n");
		printf("\t\t\t* |        4、查找          | *          在 首 他  得 宽  涯 楼 风  三\n"); 
		printf("\t\t\t* |        5、筛选          | *          灯 ， 千  人 终  路 ， 凋  境\n"); 
		printf("\t\t\t* |        6、排序          | *          火    百  憔 不  。    碧  界\n"); 
		printf("\t\t\t* |        7、添加          | *          阑    度  悴 悔        树\n");
		printf("\t\t\t* |        8、修改          | *          珊    ，  。 ，        ，\n"); 
		printf("\t\t\t* |        9、保存          | *          处\n");
		printf("\t\t\t* |       10、注销          | *          。\n");
		printf("\t\t\t* |        0、退出          | *\n");
		printf("\t\t\t* |_________________________| *\n");
		printf("\t\t\t*                             *\n");
		printf("\t\t\t* * * * * * * * * * * * * * * *\n");
		printf("请选择：");
		scanf("%d",&n); 
		switch(n)
		{
			case 1: open();break;
			case 2: input();break;
			case 3: show();break;
			case 4: search();break;
			case 5: screen();break;
			case 6: sort();break; 
			case 7: add();break;
			case 8: amendment();break;
			case 9: save();break;
			case 10: login();break;
			case 0: printf("\n     操作结束！");
			      	exit(0);
			      	break;
		}
    }
	return 0;
 } 
 
