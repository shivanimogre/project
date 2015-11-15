/*****************************************************************************
 * "Medical Store Management System" 
 *
 * This code performs various operations mainly used in medical store.
 *
 * Copyright (C) 2015 Shivani S. Mogre
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>
 *****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int i;
int bill_ret;
//function for auto increment customer & supplier Id.
int getcust_id();
int getsupp_id();
//function for welcome & main menu
void welcome();
void main_menu();
//function for supplier menu
void supplier();
void supp_entry();
void supp_list();
void sup_update();
void search();
void search_id();
void search_name();
//function for customer menu
void customer();
void cust_search();
void search_cid();
void search_cname();
void cust_entry();
void cust_list();
void cust_update();

//function for medicine menu
void medicine();
void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();

int bill();
void sale_rpt();
void profit_rpt();
void pur_rpt();
//===================================structures =========================
//Structure for supplier
struct supplier
{
	int supp_id;
	char supp_name[25];
	char city[20];
	char mob_no[11];
        char email[50];
};
struct supplier temp1;
FILE *ptr1;

//Structure for customer
struct customer
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};
struct customer temp_c;
FILE *ptr1;

//Structure for medical
struct medical
{
	char id[20];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
};
struct medical temp;
struct medical x[20];
FILE *ptr;
char a[10];

//Structure for bill
struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE *ptrbill;

//Structure for sales
struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE *ptrs_r;

//Structure for purchase
struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE *ptrp_r;

//Structure for profit
struct profit_report
{
	char medi_id[6];
	char medir_name[20];
	int sDay,sMonth,sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;
//=========================Time & Date ====================
int t(void)
{
	
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

	printf("\nDate: %d-%d-%d ",now->tm_mday,now->tm_mon,now->tm_year);
	printf("\nTime: %d:%d:%d",now->tm_hour, now->tm_min,now->tm_sec);
	return 0;
}
//=========================getsupp_id =======================
int getsupp_id()
{
FILE *fp;
	 fp=fopen("supplier.dat","a");

	 if(fp==NULL)
	 {
		printf("Data not Found.....");
		return 0;
	 }
	 else
	 {	rewind(fp);
		while(fscanf(fp,"%d %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.city, temp1.mob_no)!=EOF)
		{
			
		}
	 }
         temp1.supp_id=temp1.supp_id+1;
	 fclose(fp);
	 return temp1.supp_id;
}
//=========================getcust_id =======================
int getcust_id()
{
 FILE *fp;
	 fp=fopen("customer.dat","a");
	 if(fp==NULL)
	 {
		printf("Data not Found.....");
		return 0;
	 }
	 else
	 {	rewind(fp);
		while(fscanf(fp,"%d %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city)!=EOF)
		{
		}
	 }
	 temp_c.cust_id=temp_c.cust_id+1;
	 fclose(fp);
	 return temp_c.cust_id;
}
//===========================main ===================
int main()
{
	char name[15];
	char pass[15];
	int count=0,i;
        main_menu();

}
void main_menu()
{
  char ch;

	do
	{
		system("clear");
printf(" \n");
		printf("\n\t====================MENU====================");
		printf("\n\n\t (S) Supplier Info");
		printf("\n\t (C) Customer Info");
		printf("\n\t (M) Medicine");
		printf("\n\t (B) Bill");
		printf("\n\t (E) Exit\n");
		t();   
		printf("\n");
		printf("\n\t**************** Welcome To Medical Store ****************");
		printf("\n\nPress First Character for further Menu:  ");
		ch=toupper(getchar());
		
		switch(ch)
		{
			case 'S':supplier();
				 break;
			case 'C':customer();
				 break;
			case 'M':medicine();
				 break;
			case 'B':bill_ret = bill();
				 break;
                        case 'E':exit(1);
                        	 break;
			default:
			printf("\nPlese Enter right character ONLY (S,C,M,B).");
			
		}
	
	}while(ch!='E' && bill_ret != 10);
}
//=========================For supplier ==========================
void supplier()
{
  char ch;
	do
	{ 
	  //system("clear");
	  printf("\n\n\t********** Supplier MENU **********");
	  printf("\n\n\t=======================================");
	  printf("\n\t(A) Add New Supplier");
          printf("\n\t(U) Update Supplier");
	  printf("\n\t(L) List of Existing Supplier");
	  printf("\n\t(S) Search Supplier ");
          printf("\n\t(M) Main Menu\n");
	  printf("\n\tPress First Character for further Operation: ");
	  ch=toupper(getchar());
          system("clear");
	  switch(ch)
	  {
		case 'A':
			 supp_entry();
			 break;
		case 'U':
			 sup_update();
			 break;
		case 'L':
			 supp_list();
			 break;
		case 'S':search();
			 break;
		case 'M':main_menu();
			 break;
		default: break;
			//printf("\nPlese Enter right character ONLY (A,L,U,S,M).");
			
	  }
	}while(ch!='M');

}
//========FOR SUPPLIERS ENTRY=================
void supp_entry()
{
 char ch;
 int id;
 FILE *fp;
 system("clear");
	   fp=fopen("supplier.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		return;
	   }
	   system("clear");
	   ch='y';
	   while(ch=='y')
	   {
		printf("\n\t=================SUPPLIER ENTRY=================\n");
		temp1.supp_id=getsupp_id();
		printf("\n\n\tSupplier ID :");		
		printf("%d",temp1.supp_id);
		printf("\n\n\tSupplier NAME : ");
		scanf("%s",temp1.supp_name);
		printf("\n\n\tCITY: ");
		scanf("%s",temp1.city);	
		printf("\n\n\tCONTACT NO: ");
		scanf("%s",temp1.mob_no);
		printf("\n\n\tEMAIL ID: ");
		scanf("%s",temp1.email);               
		gets(temp1.email);
		printf("\n\t(S) Save");
		printf("\n\t(C) Cancel");
		printf("\n\tPress First character for the operation : ");
		scanf("%c",&ch);
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n",temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city,temp1.email);
			fprintf(fp,"\n");
			printf("\n Added Successfully!!!!!");
		
		}
	   }
	   fclose(fp);
}
//========SUPPLIERS UPDATE=================
void sup_update()
{
	FILE *fp1, *fp2;
	char filename[40],s1[40];
	char c;
	int line,len,i, temp = 1;
	printf("\t=================UPDATE=================");
	printf("\n\n\tEnter file name: "); //(supplier.dat)
	scanf("%s", filename);
	fp1 = fopen(filename, "r");  //supplier.dat
	c = getc(fp1);
	fp2 = fopen("updatesupp", "w");
	printf("\n\tEnter line no. to be updated:");
	scanf("\t%d",&line);
	while (c != EOF) {
				printf("\t%c", c);
				if (c =='\n') 
				{
 	          		 	temp++;
					printf("\t%d",temp);
				}
				if (temp != line)
				{
        				putc(c, fp2);

				}
				else 
        			{
                               while ((c = getc(fp1)) != '\n') {
            							}
            			printf("\n\tEnter new text:");
				scanf("%s",s1);
             			fprintf(fp2,"\n");
            			fputs(s1, fp2);  
           		        temp++;
            		}
        	c = getc(fp1);
    	}
        fclose(fp1);
	fclose(fp2);	
}
//=========FOR SUPPLIER DISPLAY LIST ==========
void supp_list()
{
 char ch;
 int j;
 FILE *ptr1;
 system("clear");
	   ptr1=fopen("supplier.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File..! ");exit(0);
		
	   }
	ch=fgetc(ptr1);
	printf("\t================= Supplier List =================\n");
	printf("\n\tID\tSUPPLIER NAME\tPH.NO\tCITY");
	printf("\n===================================================");
	printf("\n");
	while(ch!=EOF)
			{
			printf("%c",ch);
			ch=fgetc(ptr1);
			}
	fclose(ptr1);
        getchar();
}
//======================Search Supplier==================
void search()
{
  int ch;

	do
	 { 
	   printf("\n\n\tTwo options Available for searching ");
	   printf("\n\tSearch by");
	   printf("\n\n\t(I) ID number");
	   printf("\n\t(N) Name");
	   printf("\n\t(R) Return");
	   printf("\n\n\tPress First charecter for the operation : ");
	   ch=toupper(getchar());
           system("clear");
	   switch(ch)
	   {
		case 'I':
			search_id();
			break;
		case 'N':
			search_name();
			break;
		case 'R':
			supplier();
			break;
		default:break;
	   }
	   }while(ch!='R');

}
//=============================== Search by id =============================
void search_id()
{
  int id;
  FILE *fp;

	   fp=fopen("supplier.dat","r");
	   if(fp==NULL)
	   {
	     printf("file can't open!!!!");

	   }
	   system("clear");
	   printf("\t================= Search By ID================= ");
	   printf("\n\tEnter id to be searched:");
	   scanf("%d",&id);
	   printf("\n\tID.\tSUPPLIER NAME.\tCITY.\tPH.NO");
	   printf("\n\t===============================================");
	   while(fscanf(fp,"%d %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city)!=EOF)
	   {
		if(temp1.supp_id==id)
		{
			printf("\n\t%d",temp1.supp_id);
			printf("\t%s",temp1.supp_name);
			printf("\t\t%s",temp1.city);
			printf("\t%s",temp1.mob_no);
			break;
		}
	   }
	   if(temp1.supp_id!=id)
	   {
		printf("\n Record not found!");
	   }
	   fclose(fp);
	   getchar();
}
//============================ Search by name =============================
void search_name()
{
  char name[20];
  FILE *fp;

	   fp=fopen("supplier.dat","r");
	   if(fp==NULL)
	   {
	     printf("file can't open!!!!");

	   }
	   system("clear");
	   printf("\t================= Search By Name================= ");
	   printf("\n\tEnter Supplier Name to be searched : ");
	   scanf("%s",name);
	   printf("\n\tID.\tSUPPLIER NAME.\tCITY.\tPH.NO.");
	   printf("\n\t===============================================");
	   while(fscanf(fp,"%d %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no, temp1.city)!=EOF)
	   {
		if(strcmp(temp1.supp_name,name)==0)
		{
			printf("\n\t%d",temp1.supp_id);
			printf("\t %s",temp1.supp_name);
			printf("\t%s",temp1.city);
			printf("\t%s",temp1.mob_no);
			break;
		}
	   }
	   if(strcmp(temp1.supp_name,name)!=0)
	   {
		printf("\n Record not found!!!");
	   }
	   fclose(fp);
	   getchar();
}
//=========================For customer ===========================
void customer()
{
	char ch;
	do
	{
	  printf("\n\n\t********** Customer MENU **********");
	  printf("\n\n\t=======================================");
	  printf("\n\t(A) Add New Customer");
	  printf("\n\t(U) Update Customer");
	  printf("\n\t(L) List of Existing Customer ");
	  printf("\n\t(S) Search Customer");
	  printf("\n\t(M) Main Menu");
	  printf("\n\n\tPress First Character for further Operations  ");
	  ch=toupper(getchar());
          system("clear");
	  switch(ch)
	  {
		case 'A':
			 cust_entry();
			 break;
		case 'U':
			 cust_update();
			 break;
		case 'L':
			 cust_list();
			 break;
		case 'S':cust_search();
			 break;
		case 'M':main_menu();
			 break;
		default: break;			
	  }
	}while(ch!='M');

}
//========FOR CUSTOMER ENTRY=================
void cust_entry()
{
 char ch;
 int id;
 FILE *fp;
 system("clear");
	   fp=fopen("customer.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Can not open file!!");
		return;
	   }
	   system("clear");
	   ch='y';
	   while(ch=='y')
	   {
		printf("\n\t=================CUSTOMER ENTRY=================\n");
		temp_c.cust_id=getcust_id();
		printf("\n\n\tCUSTOMER ID :");		
		printf("%d",temp_c.cust_id);
		printf("\n\n\tCUSTOMER NAME : ");
		scanf("%s",temp_c.cust_name);
		printf("\n\n\tCITY: ");
		scanf("%s",temp_c.city);	
		printf("\n\n\tCONTACT NO: ");
		scanf("%s",temp_c.mob_no);
		printf("\n\n\tEMAIL ID: ");
		scanf("%s",temp_c.email);               
		gets(temp_c.email);
		printf("\n\t(S) Save");
		printf("\n\t(C) Cancel");
		printf("\n\tPress First character for the operation : ");
		scanf("%c",&ch);
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
			fprintf(fp,"\n");
			printf("\nCustomer Added Successfully!!!!!");
		}
	   }
	   fclose(fp);
}
//============CUSTOMER Update=================
void cust_update()
{
	FILE *fp1, *fp2;
	char filename[40],s1[40];
	char c;
	int line,len,i, temp = 1;
	printf("\t=================UPDATE=================");
	printf("\n\n\tEnter file name: ");  //(customer.dat)
	scanf("%s", filename);
	fp1 = fopen(filename, "r");  //customer.dat
	c = getc(fp1);
	fp2 = fopen("updatedcust", "w");
	printf("\n\tEnter line no. to be updated:");
	scanf("%d",&line);
	while (c != EOF) {
        			printf("\t%c", c);
				if (c =='\n') 
				{
 	          		 	temp++;
					printf("%d",temp);
				}
				if (temp != line)
				{
        				putc(c, fp2);

				}
				else 
        			{
                               while ((c = getc(fp1)) != '\n') {
            							}
            			printf("\n\tEnter new text:");
				scanf("%s",s1);
             			fprintf(fp2,"\n");
            			fputs(s1, fp2);  
           		        temp++;
            		}
        	c = getc(fp1);
    	}
        fclose(fp1);
	fclose(fp2);	
}
//=========FOR CUSTOMER DISPLAY LIST ==========
void cust_list()
{
 char ch;
 int j;
 FILE *ptr1;
 system("clear");
	   ptr1=fopen("customer.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File..! ");exit(0);
		
	   }
	ch=fgetc(ptr1);
	printf("\t================= Customer List =================\n");
	printf("\n\tID\tSUPPLIER NAME\tPH.NO\tCITY");
	printf("\n===================================================");
	printf("\n");
	while(ch!=EOF)
		{
			printf("%c",ch);
			ch=fgetc(ptr1);
		}
	fclose(ptr1);
	getchar();
}
//======================Search CUSTOMER==================
void cust_search()
{
  int chr;
	do
	 {
	   printf("\n\n\tTwo options Available for searching ");
	   printf("\n\tSearch by");
	   printf("\n\n\t(I) ID number");
	   printf("\n\t(N) Name");
	   printf("\n\t(R) Return");
	   printf("\n\n\tPress First character for the operation : ");
	   chr=toupper(getchar());
           system("clear");
	   switch(chr)
	   {
		case 'I':
			search_cid();
			break;
		case 'N':
			search_cname();
			break;
		case 'R':
			customer();
			break;
		default:break;
	    }		
	   }while(chr!='R');
       getchar();
}

//===========================Search by Customer Id=========================
void search_cid()
{
  int id;
  FILE *fp;
	   fp=fopen("customer.dat","rb");
	   printf("\t================= Search By ID================= ");
	   printf("\n\tEnter id to be searched:");
	   scanf("%d",&id);
	   printf("\n\tID.\tCUSTOMER NAME.\tCITY.\tMOBILE.NO.");
	   while(fscanf(fp,"%d %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city)!=EOF)
	   {
		if(temp_c.cust_id==id)
		{
			
			printf("\n\t%d",temp_c.cust_id);
			printf("\t%s",temp_c.cust_name);
			printf("\t\t%s",temp_c.city);
			printf("\t%s",temp_c.mob_no);
			break;
		}
	   }
	   if(temp_c.cust_id!=id)
	   {
		printf("\nRecord not found!");
	   }
	   fclose(fp);
       getchar();
}
//===========================Search by Customer name=========================
void search_cname()
{
  char name[20];
  FILE *fp;
	   fp=fopen("customer.dat","rb");
	   printf("\t================= Search By Name================= ");
	   printf("\n\tEnter Customer Name to be searched:");
	   scanf("%s",name);
	   printf("\n\tID.\tCUSTOMER NAME.\tCITY.\tMOBILE.NO.");
	   while(fscanf(fp,"%d %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city)!=EOF)
	   {
		if(strcmp(temp_c.cust_name,name)==0)
		{
			printf("\n\t%d",temp_c.cust_id);
			printf("\t%s",temp_c.cust_name);
			printf("\t%s",temp_c.city);
			printf("\t%s",temp_c.mob_no);
			break;
		}
	   }
	   if(strcmp(temp_c.cust_name,name)!=0)
	   {
		printf("\nRecord not found!");
	   }
	   fclose(fp);
	getchar();
}

//=========================For Medicine ===========================
void medicine()
{
	char ch;
	do
	{
	  system("clear");
	  printf("\n\n\t********** Medicine Menu **********");
	  printf("\n\n\t=======================================");
	  printf("\n\t(P) Purchase New Medicine");
	  printf("\n\t(S) Sale Medicine");
	  printf("\n\t(C) Stock of Medicine");
	  printf("\n\t(A) Search Medicine");
	  printf("\n\t(M) Main Menu");
	  printf("\n\n\tPress First Character for further Operations:");
          ch=toupper(getchar());
	  switch(ch)
	  {
		case 'P':medi_entry();
			 break;
		case 'S':medi_sale();
			 break;
		case 'C':stock();
			 break;
		case 'A':medi_search();
			break;
		case 'M':main_menu();
			 break;
		default:break;
	  }
	}while(ch!='M');

}
//============================ FOR MEDICINE PURCHASE    ===================
void medi_entry()
{

  char ch,id[20];
    time_t t = time(0);   
    struct tm * now = localtime( & t );
  int f;
  FILE *fp;
	   ptrp_r=fopen("purreport.dat","a");
	  ch='Y';
	  while(ch=='Y')
	  {
		printf("\n\t================= MEDICINE PURSHASE =================\n");
		{
			printf("\n\tMEDICINE ID: ");
			scanf("%s",temp.id);
			strcpy(id,temp.id);
			fp=fopen("medical.dat","a");
			while((fread(&temp,sizeof(temp),1,fp))==1)
			{
			if(strcmp(id,temp.id)==0)
			{
				f=1;
				break;
			}
			}
			fclose(fp);
			if(f==1)
			{
		
				printf("\n\tID Allready Exists");
				getchar();
				medi_entry();
			}
			else
			{
			ptr=fopen("medical.dat","a+b");
			strcpy(temp.id,id);
			strcpy(p_r.medi_id,temp.id);
			}
			
			printf("\n\tMEDICINE NAME: ");
                        scanf("%s",temp.medi_name);
			strcpy(p_r.medir_name,temp.medi_name);

			printf("\n\tENTER RACK NO: ");
			scanf("%d",&temp.rack);

			printf("\n\tCABINIT NO: ");
			scanf("%s",temp.cabnit);

			printf("\n\tCOMPANY NAME: ");
                        scanf("%s",temp.comp_name);
			
			printf("\n\tSUPPLIER NAME: ");
                        scanf("%s",temp.supp_name);
			strcpy(p_r.supp_name,temp.supp_name);

			printf("\n\tUNIT COST   Rs:  ");
			scanf("%f",&temp.unit);
			p_r.rate=temp.unit;

			printf("\n\tSALE COST   Rs: ");
			scanf("%f",&temp.sale);
			
			printf("\n\tQUANTITY      :  ");
			scanf("%d",&temp.quantity);
			p_r.qty=temp.quantity;

			printf("\n\tMFG.DATE(dd-mm-yyyy): ");
			scanf("%s",temp.manu_date);
			
			printf("\n\tEXP.DATE(dd-mm-yyyy): ");
			scanf("%s",temp.exp_date);
			
			printf("\n\t==========================================================");
			temp.total=temp.quantity*temp.sale;

			printf("\n\tTOTAL SALE COST = Rs. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);
			printf("\n\tTOTAL UNIT COST = Rs. %.2f",temp.cost);
			p_r.total=temp.cost;
			p_r.sDay=now->tm_mday;
			p_r.sMonth=now->tm_mon;
			p_r.sYear=now->tm_year;
		 }
		printf("\n\n\t(S) Save");
		printf("\n\t(C) Cancel");
		printf("\n\tPress First charecter for the operation : ");
		ch=toupper(getchar());
                scanf("%c",&ch);
		if(ch=='s' || ch=='S')
		{
			fwrite(&temp,sizeof(temp),1,fp);
                   fprintf(ptrp_r,"%s %s %s %d %.2f %.2f %d %d %d \n",p_r.medi_id,p_r.medir_name,p_r.supp_name,p_r.qty,p_r.rate,p_r.total,p_r.sDay,p_r.sMonth,p_r.sYear);
                    fprintf(ptrp_r,"\n");
			printf("\nMedicine Added sucessfully!!!!!!");
		}

	   }
	   fclose(ptr);
	   fclose(ptrp_r);

}
//===========FOR MEDICINE SALE=========================
void medi_sale()
{
  struct bill bil;
 
  time_t t = time(0);   // get time now
  struct tm * now = localtime( & t );
  int j,n,i,a,billno;
  int d1,m,y;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;
  d1=now->tm_mday;
  m=now->tm_mon;
  y=now->tm_year;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.dat","a");
		ptr1 = fopen("customer.dat","rb");
		ptr = fopen("medical.dat","r");
		ptrs_r=fopen("saleRpt.dat","a");
		ptrpr_r=fopen("profitRpt.dat","a");
		system("clear");
		
		printf("\n\tCust_ID\tCust_Name\tCust_mob\tCust_city ");
		while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
		{
			
			printf("\n\t%d",temp_c.cust_id);
		        printf("\t%s",temp_c.cust_name);
			printf("\t\t%s",temp_c.mob_no);
			printf("\t\t%s",temp_c.city);
		        break;	
		}
                printf("\n\n\tENTER MEDICINE ID TO BE SOLD  : ");
		scanf("%s",tar);
		j=0;
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
			{
				x[j] = temp;
				j++;
			}
			else if((strcmp(temp.id,tar)==0))
			{
				printf("\n\n\tMedicine Name	: %s",temp.medi_name);
				
				printf("\n\n\tQuantity in stock	: %d",temp.quantity);
					
				printf("\n\n\tSales price	: %.2f",temp.sale);
				
				printf("\n\n\tEnter bill number	: ");
				scanf("%s",bil.billno);
			
				printf("\n\n\tEnter customer Name   : ");
				scanf("%s",c_name);
				
				printf("\n\n\tQuantity want to sale : ");
				scanf("%d",&a);

				pr_r.profit=(temp.sale-temp.unit)*a;
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sale);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sale*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.cname,c_name);
				strcpy(s_r.cust_name,c_name);
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sale;
				bil.total=temp.sale*a;

				bil.day=d1;
				bil.month=m;
				bil.year=y;

				fprintf(fp,"%s %s %s %d %.2f %.2f %d %d %d\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total,bil.day,bil.month,bil.year);

				fclose(fp);

				s_r.sDay=d1;
				s_r.sMonth=m;
				s_r.sYear=y;
				strcpy(s_r.medi_id,tar);
				strcpy(s_r.medir_name,temp.medi_name);
				s_r.qty=a;
				s_r.rate=temp.sale;
				s_r.total=temp.sale*a;

				fprintf(ptrs_r,"%s %s %s %d %.2f %.2f %d %d %d\n",s_r.medi_id,s_r.medir_name,s_r.cust_name,s_r.qty,s_r.rate,s_r.total,s_r.sDay,s_r.sMonth,s_r.sYear);
				fclose(ptrs_r);

				pr_r.sDay=d1;
				pr_r.sMonth=m;
				pr_r.sYear=y;
				strcpy(pr_r.medi_id,tar);
				strcpy(pr_r.medir_name,temp.medi_name);
				pr_r.qty=a;
				pr_r.rate=temp.sale;
				pr_r.unit=temp.unit;
				fprintf(ptrpr_r,"%s %s %d %d %d %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,d1,pr_r.sMonth,pr_r.sYear,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
				fclose(ptrpr_r);

			}
		}
		if (count==0)
		{
			system("clear");
			printf("\nNot in stock!!!!!");
			getchar();
			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("clear");
		ptr=fopen("medical.dat","wb");
		for(i=0; i<n; i++)
		fwrite(&x[i],sizeof(x[i]),1,ptr);
		fclose(ptr);
		system("clear");
		printf("\n\t*** Price paid by customer = %.2f",b);
		printf("\n\t*** Quantity sold          = %d",a);
		getchar();
		printf("\n\tMore enteries=(y/n) :");
		ch=getchar();
	   }

}
//===========================MEDICINE STOCK=====================================
void stock()
{
  char ch;
  int i,c;
	   do
	   {
		system("clear");
		ptr1=fopen("medical.dat","r");
		if(ptr1==NULL)
		{
			printf("\n\t Can not open File! ");
			//exit(1);
		}
		system("clear");
		
		printf(" \nSTOCK OF MEDICINE ");
		
		printf("\nID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
		
		printf("\n==================================================================\n");

		while((fread(&temp,sizeof(temp),1,ptr1))==1)
		{
			
			printf("\n%s",temp.id);
			
			printf("\t%s",temp.medi_name);
			
			printf("\t\t%d",temp.quantity);
			
			printf("\t%s",temp.supp_name);
			
			printf("\t\t%s",temp.exp_date);
			
		}
		
		printf("\nPress [1] for Update Medicine Stock  & [0] for main menu ");
		c = (getchar());
		switch (c)
		{
			case '0':
				 main_menu();
				 break;
			case '1':update_stock();
				 break;
		}

	   }while(c != '1');
	   //getchar();
}
//=============================== FOR MEDICINE SEARCH ====================
void medi_search()
{
  char mid[6];
  int i,c;
	   ptr1=fopen("medical.dat","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
	   }
	   printf("\n\tEnter Medicine Id to be searched : ");
	   scanf("%s",mid);
	   printf(" \n MEDICINE ");
	   printf("\nID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
	   printf("\n==================================================================\n");
	   while((fread(&temp,sizeof(temp),1,ptr1))==1)
	   {
		if(strcmp(mid,temp.id)==0)
		{
			printf("\b%s",temp.id);
			printf(" %s",temp.medi_name);
			printf(" %d",temp.quantity);
			printf(" %s",temp.supp_name);
			printf(" %s",temp.exp_date);
			break;
		}

	   }
	   if(strcmp(mid,temp.id)!=0)
	   {
		
		printf("Not in Stock.....");
	   }
	   getchar();

}
//============================ FOR MEDICINE UPDATE =====================
void update_stock()
{
  char mid[6];
  int j,a,count=0,n;
  system("clear");
	   ptr=fopen("medical.dat","rb");
	   if(ptr==NULL)
	   {
		printf("\n\t Can not open File! ");
	   }
	   system("clear");
	   printf("\n\tUPDATE MEDICINE QUANTITY ");
	  
	   printf("\n\tEnter medicine id to be update qty: ");
	   scanf("%s",mid);
	   j=0;

	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
		{
			x[j] = temp;
			j++;
		}
		else
		{
			
			printf("\n\tMedicine Name     : %s",temp.medi_name);
			
			printf("\n\tQuantity in stock : %d",temp.quantity);
			
			printf("\n\tQuantity want to update : ");
			scanf("\t%d",&a);
			x[j]=temp;
			x[j].quantity=(x[j].quantity+a);
			x[j].total=(x[j].quantity*temp.sale);
			x[j].cost=(x[j].quantity*temp.unit);
			x[j].bye=(x[j].sale*a);
			x[j].qty=a;
			j++;
			count++;
		}
	   }
	   if (count==0)
	   {
		 system("clear");
		
		 printf("\n\tNot in stock!!!!!!");
		 return;
	   }
	   fclose(ptr);
	   n = j;
	   system("clear");
	   ptr=fopen("medical.dat","wb");
	   for(i=0; i<n; i++)
	   fwrite(&x[i],sizeof(x[i]),1,ptr);
	   fclose(ptr);
}
void pur_rpt_daily()
{
  char ch;
  int j,d,m,y;
  float total=0.00;

	   ptrp_r=fopen("purreport.dat","r");
	   if(ptrp_r==NULL)
	   {
		printf("\n\t Can not open File! ");
	   }
	   system("clear");
	   
	   printf("Enter Date(dd-mm-yyyy):  ");
	   scanf("%d-%d-%d",&d,&m,&y);
	   system("clear");
	  
	   printf("\nPress Enter to go to REPORT MENU ...........");

	   printf("\nPurchase Report");

	   printf("\nID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
	   
	   printf("\n===================================================================");
	   j=14;
	   while(fscanf(ptrp_r,"%s %s %s %d %f %f %d %d %d\n",p_r.medi_id,p_r.medir_name,p_r.supp_name,&p_r.qty,&p_r.rate,&p_r.total,&p_r.sDay,&p_r.sMonth,&p_r.sYear)!=EOF)
	   {
		if(d==p_r.sDay &&m== p_r.sMonth && y==p_r.sYear)
		{
		
		printf("%s",p_r.medi_id);
		printf("%s",p_r.medir_name);
		printf("%s",p_r.supp_name);
		printf("%d",p_r.qty);
		printf("%.2f",p_r.rate);
		printf("%.2f",p_r.total);
		printf("%d-%d-%d",p_r.sDay,p_r.sMonth,p_r.sYear);
		j+=2;
		total=total+p_r.total;
		}
	   }
	   printf("-------------------------------------------------------------------");
	   printf("Total:        %.2f",total);
	   getchar();
}
int bill()  /*Bill Calculate*/
{
int ret;
    time_t td = time(0);   // get time now
    struct tm * now = localtime( & td );

	   FILE *ptrbill;
	   char id[6];
	   int j=1,d1,m,y,k;
	   float netamt=0.0;
	   d1=now->tm_mday;
	   m=now->tm_mon;
	   y=now->tm_year;
	   ptrbill=fopen("dbbill.dat","r");
	   printf("Enter bill no: ");
	   scanf("%s",id);
	   printf("Bill No: ");
	   printf(" %s",id);
	   printf("\nDate : ");
	   printf("%d-%d-%d",d1,m,y);
	   printf("\nMedicine_Name\tCustomer_Name\tQty\tRate\tTotal\n");
	   printf("\n---------------------------------------------------------------------");
           printf("\n---------------------------------------------------------------------");     
	   while(fscanf(ptrbill,"%s %s %s %d %f %f %d %d %d",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total,&bil.day,&bil.month,&bil.year)!=EOF)
	   {
		       do
		       {
			if(strcmp(id,bil.billno)==0)
			{       
				printf("\n%s",bil.mediname);
				printf("\t\t%s",bil.cname);
				printf("\t\t%d",bil.medi_qty);
				printf("\t%.2f",bil.medi_rate);
				printf("\t%.2f",bil.total);
				netamt=netamt+bil.total;
			}  
		}while(feof(ptrbill));
	   }
	   printf("\n---------------------------------------------------------------------");
	   printf("\nNet Amount : ");
	   printf("%.2f",netamt);
	   fclose(ptrbill);
	   printf("\n Do you want to continue press 1 otherwise press 2\t");
	   scanf("%d", &ret);
	   if(ret == 1)
		main_menu();
	   else
	   	return(10);

}


