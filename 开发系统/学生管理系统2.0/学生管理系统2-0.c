#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 1000
struct Date
{
	int year;   //��
	int month;  //��
	int day;    //�� 
};
struct Major
{
	float math;   //���� 
	float Eglish; //Ӣ�� 
	float C;      //C���� 
};
struct Student
{
	char num[20];             //ѧ�� 
	char name[20];       //���� 
	char ID[18];         //���֤�� 
	int sex;            //�Ա�
	int age;             //����
	struct Date birth;   //�ꡢ�¡��� 
	struct Major score;  //���ſη��� 
	float sum;           //�ܷ� 
	float aver;          //ƽ���� 
}stu[N];

struct Data       //�û����ݽṹ�� 
{
	char names[20];
	char password[20];
}user[100];

char file[20];   //ȫ�ֱ������򿪵��ļ��� 
float sum=0,math_sum=0,Eglish_sum=0,C_sum=0;  //ȫ�ֱ������ܷ�
int S=0,Y=0;  //ȫ�ֱ�����ѧ������
char NAME[20];

void data_open()
{
	FILE *f;
	int i;
	if((f=fopen("data.dat","rb"))==NULL)
	{
		printf("�������ļ�ʧ�ܣ�");
		return; 
	 } 
	if(fread(&Y,sizeof(int),1,f)!=1)  //���� �û����� Y 
		{
			if(feof(f))
			{
				fclose(f);
				return ;
			}
			printf("�����ļ�����\n"); 
		}
		for(i=0;i<Y;i++)
			if(fread(&user[i],sizeof(struct Data),1,f)!=1)  //����ѧ����Ϣ��Student�ṹ�� 
			{
				if(feof(f))
				{
					fclose(f);
					return ;
				}
			printf("�����ļ�����\n");
			}
		fclose(f);   //�ر� file�ļ���fָ��file 
		printf("......"); 
}

void data_save()
{
	FILE *f;
	int i;
	if((f=fopen("data.dat","wb"))==NULL)
	{
		printf("�޷��򿪴��ļ���\n");
		return;
	}
	if (fwrite(&Y,sizeof(int),1,f)!=1)   //�����û�����Y 
	printf("�ļ��������!\n");
	for(i=0;i<Y;i++)
	   if(fwrite(&user[i],sizeof(struct Data),1,f)!=1)   //����ѧ����Ϣ��Student�ṹ�� 
	      printf("�ļ��������\n");
	fclose(f);
	printf("\t\t\tע��ɹ���\n");
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
	printf("\n\n\t\t\t\t    ��ӭ��½ѧ������ϵͳ\n");
	printf("\t\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t*          1����½          *\n");
	printf("\t\t\t\t*          2��ע��          *\n");
	printf("\t\t\t\t*          0���˳�          *\n");
	printf("\t\t\t\t* * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t    ��ѡ��");
	scanf("%d",&a);
	if(a==1)
	{
		system("cls");
		while(1)
		{
			printf("\n\t\t\t\t�û�����");
			scanf("%s",t.names);
			strcpy(NAME,t.names);
			printf("\t\t\t\t���룺");
			scanf("%s",t.password);
			for(i=0;i<Y;i++)
			{
				if(strcmp(t.names,user[i].names)==0) j=i;
			 } 
			if(strcmp(t.password,user[j].password)==0) break;
			else printf("\n\t\t\t    �û��������벻��ȷ��\n"); 
	    }
	    if(strcmp(t.password,user[j].password)==0) break;
	}
	else if(a==2)
	     {
	     	
	        k=Y;
	     	++Y;
	     	 while(f)
	     	 {
			  
	        printf("\n\t\t\t\t�������û�����");
	     	scanf("%s",t.names);
	     	
	        for(i=0;i<Y;i++)
	        {
	        	 if(strcmp(t.names,user[i].names)==0) j=i;
			}
	        if(strcmp(t.names,user[j].names)==0)
	                            printf("\n\t\t\t\t  �û����ظ���\n");
			else  {
			      strcpy(user[k].names,t.names);
			      break;
			      }
	    }
			printf("\t\t\t\t���������룺");
			scanf("%s",user[k].password); 
			data_save();
			printf("\n���س������أ�");
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
		sum=sum+stu[i].aver;       //�༶����ƽ�����ܷ� 
		math_sum=math_sum+stu[i].score.math; //ȫ����ѧ�ܷ�
		Eglish_sum=Eglish_sum+stu[i].score.Eglish; //ȫ��Ӣ���ܷ�
		C_sum=C_sum+stu[i].score.C;  //ȫ��C�����ܷ� 
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
		printf("     ѧ��%d. \n",++S);
		printf("ѧ �ţ�"); 
		scanf("%s",stu[i].num);
		if(stu[i].num==0) break;
		printf("�� ����"); 
		scanf("%s",stu[i].name);
		printf("���֤�ţ�");
		scanf("%s",stu[i].ID);
		printf("�����ɼ���");
		scanf("%f",&stu[i].score.math);
		printf("Ӣ��ɼ���");
		scanf("%f",&stu[i].score.Eglish);
		printf("C���Գɼ���");
		scanf("%f",&stu[i].score.C);
		stu_ID(i);
		stu[i].sum=stu[i].score.math+stu[i].score.Eglish+stu[i].score.C;  //�����ܷ� 
		stu[i].aver=stu[i].sum/3.0;     //����ƽ����
		i++;
		printf("�Ƿ����(Y/N):");
		scanf(" %c",&c);           //�����ַ�
		if(c=='n'||c=='N') break;  //�ж��Ƿ���� 
	}
}

void stu_print(int i)
{
	printf("������Ϣ����:\n\n");
	printf("\tѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
	printf("��������������������������������������������������������������");
	printf("����������������������������������������������������������\n"); 
	printf("\t%s\t%s",stu[i].num,stu[i].name);
	if(stu[i].sex==0) printf("\tŮ");
	else printf("\t��");
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
		printf("\n��ѡ����ҷ�ʽ��\n\n");
		printf("\tA����ѧ�Ų���\n\tB������������\n\tC�������֤����\n\tD������\n");
		printf("\n��ѡ��");
		scanf(" %c",&c);
		if(c=='d'||c=='D') break;
		if(c=='a'||c=='A')
		{
			printf("��������Ҫ���ҵ�ѧ�ţ�");
		    scanf("%s",_num);
			for(i=0;i<S;i++)
			  if(strcmp(_num,stu[i].num)==0) f=1,j=i;   //���ѧ����Ϣ	   	
			if(f==1) stu_print(j);
			else printf("�����޹���\n");
			printf("�Ƿ��������(Y/N):");
		    scanf(" %c",&a);
		    if(a=='n'||a=='N') break;
		}
		else if(c=='b'||c=='B')
		{
			printf("��������Ҫ���ҵ�������");
			scanf("%s",_name);
			for(i=0;i<S;i++)
			   if(strcmp(_name,stu[i].name)==0) f=1,j=i;  //���ѧ����Ϣ 
			if(f==1) stu_print(j);
			else printf("�����޹���\n");
			printf("�Ƿ��������(Y/N):");
		    scanf(" %c",&a);
		    if(a=='n'||a=='N') break;
		}
		
    }
}

void _show()
{
	int i;
	system("cls");
	printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
	for(i=0;i<S;i++)
	{
	    printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
        if(stu[i].sex==0) printf("\tŮ");
         else printf("\t��");
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
		printf("\nȫ��ƽ���֣�%.2f\n",sum);
		printf("ȫ�����ƽ���֣�%.2f\n",math_sum);
		printf("ȫ��Ӣ��ƽ���֣�%.2f\n",Eglish_sum);
		printf("ȫ��C����ƽ���֣�%.2f\n",C_sum);
		printf("\n���س������أ�");
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
		printf("\t����ѧ��%d\n",++S);
		printf("ѧ �ţ�");
		scanf("%s",stu[i].num);
		if(stu[i].num==0) break;
		printf("�� ����"); 
		scanf("%s",stu[i].name);
		printf("���֤�ţ�");
		scanf("%s",stu[i].ID);
		printf("�����ɼ���");
		scanf("%f",&stu[i].score.math);
		printf("Ӣ��ɼ���");
		scanf("%f",&stu[i].score.Eglish);
		printf("C���Գɼ���");
		scanf("%f",&stu[i].score.C);
		stu_ID(i);
		stu[i].sum=stu[i].score.math+stu[i].score.Eglish+stu[i].score.C;  //�����ܷ� 
		stu[i].aver=stu[i].sum/3.0;     //����ƽ����
		i++;
		printf("�Ƿ�������(Y/N):");
		scanf(" %c",&c);           //�����ַ�
		if(c=='n'||c=='N') break;  //�ж��Ƿ���� 
		
	}
}

void amendment()
{
	int i,a,b;
	char c;
	while(1)
	{
		_show();
		printf("\n�������޸�ѧ������ţ�");
		scanf("%d",&b);
		if(b==0) break;
		i=b-1;          //i��������ű�ѧ�����Сһ 
		system("cls");
		printf("\tѧ��%d\n",b);
		printf("��ѡ���޸ĵ���Ϣ��\n");
		printf("1��ѧ��\n2������\n3�����֤��\n4�������ɼ�\n5��Ӣ��ɼ�\n6��C���Գɼ�\n\n");
		printf("��ѡ��");
		scanf("%d",&a);
		if(a==1)
		{
			printf("�������µ�ѧ�ţ�");
			scanf("%s",stu[i].num); 
		}
		else if(a==2)
		{
			printf("�������µ�������"); 
			scanf("%s",stu[i].name); 
		}
		else if(a==3)
		{
			printf("�������µ����֤�ţ�");
			scanf("%s",stu[i].ID);
			stu_ID(i);
		}
		else if(a==4)
		{
			printf("�������µĸ����ɼ���");
			scanf("%d",&stu[i].score.math);
		}
		else if(a==5)
		{
			printf("�������µ�Ӣ��ɼ���");
			scanf("%d",&stu[i].score.Eglish); 
		}
		else if(a==6)
		{
			printf("�������µ�C���Գɼ���");
			scanf("%d",&stu[i].score.C);
		}
		printf("�Ƿ����(Y/N):");
		scanf(" %c",&c);       //�����ַ�
		if(c=='n'||c=='N') break;  //�ж��Ƿ����  
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
		printf("\t��ѡ������ʽ��\n");
		printf("  1����ѧ������\n  2������������\n  3���������ɼ�����\n  4����Ӣ��ɼ�����\n");
		printf("  5����C���Գɼ�����\n  6����ƽ��������\n  7�����ܷ�����\n  0������\n\n");
		printf("��ѡ��");
		scanf("%d",&a);
		if(a==0) break;
		system("cls");
		printf("\n1������\n2������\n0������\n\n");
		printf("��ѡ��");
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
			printf("\n������ɣ�\n\n");
			printf("�Ƿ�鿴������(Y/N):");
			scanf(" %c",&c);
			if(c=='n'||c=='N') break;
			else _show();
			printf("\n�Ƿ��������(Y/N):");
			scanf(" %c",&d);           //�����ַ�
			if(d=='n'||d=='N') break;  //�ж��Ƿ���� 
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
		printf("  1�������ɼ�\n  2��Ӣ��ɼ�\n  3��C���Գɼ�\n  4��ƽ����\n  0������\n\n");
		printf("��ѡ��");
		scanf("%d",&a);
		if(a==0) break;
		system("cls");
		printf("\n1������\n2��������\n0������\n\n");
		printf("��ѡ��");
		scanf("%d",&b);
		if(b==0) break;
		switch(a)
		{
			case 1: if(b==1)
			        system("cls");
					printf("\t�������������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].score.math>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\t���������������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].score.math<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
		    case 2: if(b==1)
		            system("cls");
					printf("\tӢ�Ｐ�������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].score.Eglish>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\tӢ�ﲻ���������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].score.Eglish<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
			case 3: if(b==1)
		            system("cls");
					printf("\tC���Լ��������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].score.C>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\tC���Բ����������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].score.C<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
			case 4: if(b==1)
		            system("cls");
					printf("\tƽ���ּ��������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].aver>60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					  else if(b==2)
					system("cls");
					printf("\tƽ���ֲ����������£�\n"); 
					printf("���   ѧ��\t����\t�Ա�\t����\t��������\t   ���֤��\t\t����\tӢ��\tC����\tƽ����\t�ܷ�\n");
					for(i=0;i<S;i++)
					if(stu[i].aver<60) 
					{
						printf("%4d   %s\t%s",i+1,stu[i].num,stu[i].name);
				        if(stu[i].sex==0) printf("\tŮ");
				         else printf("\t��");
				        printf("\t%d\t%d/%d/%d\t%s\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",stu[i].age,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day,
				               stu[i].ID,stu[i].score.math,stu[i].score.Eglish,stu[i].score.C,stu[i].aver,stu[i].sum);
					}
					break;
			case 0: break; 
		}
		if(b==0) break;
	    else 
	    {
	    	printf("\n�Ƿ����ɸѡ(Y/N):");
			scanf(" %c",&c);           //�����ַ�
			if(c=='n'||c=='N') break;  //�ж��Ƿ����
		}
	}
}

void open()
{
	int i;
	char c;   // �򿪵��ļ���         
	FILE *f;        //�ļ�ָ�� 
	while(1)
	{
		system("cls");  //���� 
		printf("������Ҫ�򿪵��ļ�����\n");
		scanf("%s",file);
		if((f=fopen(file,"rb"))==NULL)   //�򿪡�file���ļ� ��fָ��file 
		  {
		  	printf("�޷��򿪴��ļ���\n");
		  	return;
		  }
		if(fread(&S,sizeof(int),1,f)!=1)  //����ѧ������ S 
		{
			if(feof(f))
			{
				fclose(f);
				return ;
			}
			printf("�����ļ�����\n"); 
		}
		for(i=0;i<S;i++)
			if(fread(&stu[i],sizeof(struct Student),1,f)!=1)  //����ѧ����Ϣ��Student�ṹ�� 
			{
				if(feof(f))
				{
					fclose(f);
					return ;
				}
			printf("�����ļ�����\n");
			}
		fclose(f);   //�ر� file�ļ���fָ��file 
		printf("�򿪳ɹ���"); 
		printf("\n���س������أ�");
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
		printf("��ѡ�񱣴淽ʽ��\n");
		printf("\n  1������\n  2�����Ϊ\n  0������\n");
		printf("\n��ѡ��");
		scanf("%d",&a);
		if(a==0) break;
		if(a==1)
		{
			if((f1=fopen(file,"wb"))==NULL)  //��pָ����ļ�����open�����򿪵��ļ� 
			{
				printf("�޷��򿪴��ļ���\n"); 
				return;
			}
			if (fwrite(&S,sizeof(int),1,f1)!=1)  //����ѧ������ S 
			printf("�ļ��������!\n");
			for(i=0;i<S;i++)
			   if(fwrite(&stu[i],sizeof(struct Student),1,f1)!=1)   //����ѧ����Ϣ��Student�ṹ�� 
			      printf("�ļ��������\n");
			fclose(f1);
			printf("����ɹ���\n");
		}
		else if(a==2)
		{
			printf("�ļ�����");
			scanf("%s",file1);
			if((f2=fopen(file1,"wb"))==NULL)
			{
				printf("�޷��򿪴��ļ���\n");
				return;
			}
			if (fwrite(&S,sizeof(int),1,f2)!=1)   //����ѧ������ S 
			printf("�ļ��������!\n");
			for(i=0;i<S;i++)
			   if(fwrite(&stu[i],sizeof(struct Student),1,f2)!=1)   //����ѧ����Ϣ��Student�ṹ�� 
			      printf("�ļ��������\n");
			fclose(f2);
			printf("����ɹ���\n");
		}
	printf("\n���س������أ�");
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
		printf("��ӭ%s!\n",NAME);
		printf("\t\t\t\t  ѧ������ϵͳ\n");
		printf("\t\t\t* * * * * * * * * * * * * * * *\n"); 
		printf("\t\t\t* ___________________________ *\n");
		printf("\t\t\t* |                         | *\n"); 
		printf("\t\t\t* |        1����          | *          �� �� ��  Ϊ ��  �� �� �� \n");
		printf("\t\t\t* |        2������          | *          �� Ȼ ��  �� ��  �� �� ҹ  �� \n");
		printf("\t\t\t* |        3����ʾ          | *          ȴ �� Ѱ  �� ��  �� �� ��  ��\n");
		printf("\t\t\t* |        4������          | *          �� �� ��  �� ��  �� ¥ ��  ��\n"); 
		printf("\t\t\t* |        5��ɸѡ          | *          �� �� ǧ  �� ��  · �� ��  ��\n"); 
		printf("\t\t\t* |        6������          | *          ��    ��  � ��  ��    ��  ��\n"); 
		printf("\t\t\t* |        7�����          | *          ��    ��  � ��        ��\n");
		printf("\t\t\t* |        8���޸�          | *          ɺ    ��  �� ��        ��\n"); 
		printf("\t\t\t* |        9������          | *          ��\n");
		printf("\t\t\t* |       10��ע��          | *          ��\n");
		printf("\t\t\t* |        0���˳�          | *\n");
		printf("\t\t\t* |_________________________| *\n");
		printf("\t\t\t*                             *\n");
		printf("\t\t\t* * * * * * * * * * * * * * * *\n");
		printf("��ѡ��");
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
			case 0: printf("\n     ����������");
			      	exit(0);
			      	break;
		}
    }
	return 0;
 } 
 
