#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void enter();
void login();
void signup();
void buy(int,char [],int,int);
int calculate(char []);
void kitchen(int);
void mobiles(int);
void see_ratings(int,int);
void laptops(int);
void homet(int);
void ac(int);
void dslr(int);
void disp(int);
void rate(int);
void welcome();
int checkstr(char s[],char t[])
{
	int i,j=0;
	for(i=0;s[i]!='\0';i++)
	if(s[i]!=t[i]){
			j++;break;
	}
	if(j!=0)
		return 1;
	return 0;
}
void welcome()
{
		printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\t     WELCOME TO \t |\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t|PRODUCT REVIEW SYSTEM\t |\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t\t|\n");

	printf("---------------------------------------------------------------------------------------------------------\n");
	 
getch();
system("cls");
}
int main()
{
	welcome();
	enter();
	return 0;
}
void enter()
{
	int c;
	printf("enter 1 to login 2 to signup:");
	scanf("%d",&c);
	if(c==1)
		login();
	if(c==2)
		signup();
}
void signup()
{
	char name[20],id[50],password[15],rpassword[15];
	printf("NAME:");
	scanf("%s",name);
	printf("enter your id:");
	scanf("%s",id);
	printf("PASSWORD:");
	scanf("%s",password);
	printf("RE-ENTER PASSWORD:");
	scanf("%s",rpassword);
	while(strcmp(password,rpassword))
	{
		printf("please enter the same password:");
		scanf("%s",rpassword);
	}
	FILE *f1;
	int i=0;
	f1=fopen("id.txt","r");
	char c[60];
	while(!feof(f1))
	{
		fgets(c,50,f1);
		i++;
	}
	fclose(f1);
	f1=fopen("id.txt","a");
	FILE *f3=fopen("pass.txt","a");
	fprintf(f1,"%d.",i);
	fprintf(f1,"%s\n",id);
	fprintf(f3,"%d.%s\n",i,password);
	FILE *f2;
	f2=fopen("name.txt","a");
	fprintf(f2,"%d.%s\n",i,name);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	printf("plsese login again:");
	login();
}
void login()
{
	char id[50];
	printf("ID:");
	scanf("%s",id);
	FILE *f1;
	char tid[50],c[50];
	int i=0,j=0,k;
	int b;
	while((j=strcmp(tid,id)))
	{
		f1=fopen("id.txt","r");
	while((j=strcmp(tid,id))&&!feof(f1))
	{
		fgets(c,50,f1);
		i++;
		for(j=0;c[j+2]!='\0'&&c[j+2]!='\n';j++)
		{	
			tid[j]=c[j+2];
		}
		while(tid[j]!='\0')
		{
			tid[j++]='\0';
		}
		j=0;
		while(c[j]!='\0')
			c[j++]='\0';
	}
	if(feof(f1)&&(j=strcmp(tid,id)))
	{
		printf("enter a valid username");
		printf("enter 1 to retry 2 to create account 3 to go back:");
		scanf("%d",&k);
	if(k==1)
	{
		fclose(f1);
		i=0;
		printf("ID:");
		scanf("%s",id);
	}
	else if(k==2)
	{
		signup();
		break;
	}
	else break;
	}
	}
	fclose(f1);
	char password[15];
	b=0;
	if(!(j=checkstr(id,tid)))
	{
		f1=fopen("name.txt","r");
		while(i+48!=b&&!feof(f1))
		{
			b=fgetc(f1);
			if(i!=b)
			{
				k=0;
				while(c[k]!='\0')
					c[k++]='\0';
			}
				fgets(c,50,f1);
		}
		
		char name[20];
		for(k=0;c[k+1]!='\0'&&c[k+1]!='\n';k++)
			name[k]=c[k+1];
		k=0;
		while(c[k]!='\0')
			c[k++]='\0';
		fclose(f1);
		printf("WELCOME %s",name);
		printf("\nPASSWORD:");
		scanf("%s",password);
		char tp[15];
		f1=fopen("pass.txt","r");
		b=fgetc(f1);
		fgets(c,50,f1);
		while(b!=i+48&&!feof(f1))
		{
			b=fgetc(f1);
			fgets(c,50,f1);
			if(b!=i+48)
			{
				k=0;
				while(c[k]!='\0')
					c[k++]='\0';
			}
		}
		if(c[0]=='\0'&&!feof(f1))
			fgets(c,50,f1);
		for(k=0;c[k+1]!='\0'&&c[k+1]!='\n';k++)
			tp[k]=c[k+1];
		while(j=strcmp(tp,password))
		{
			printf("WRONG PASSWORD \nenter 1 to ENTER AGAIN:\n2 to exit:");
			scanf("%d",&k);
			if(k==1)
			{
				printf("PASSWORD:");
			scanf("%s",password);
			}
			else if(k==2)
				break;
		}
		if(!(j=strcmp(tp,password)))
		{
			int ch;
			printf("WELCOME %s to our website:",name);
			printf("\nenter\n 1.buy a product\n2.rate a product\n3.exit:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:disp(i);
				       break;
				case 2:rate(i);
				       break;
				case 3:break;
			}
		}
		else 
			return;
	}
	return;
}
void rate(int i)
{
	FILE *f,*t;
	int m;
	char v,d[50],rate[50],c,l,e;
	int p;
f=fopen("mobiles.txt","r");
	while(!feof(f))
	{
		v=getc(f);
		//printf("J");
		if(v==i+48)
		{
			c=fgetc(f);
			c=fgetc(f);
			l=fgetc(f);
			l=fgetc(f);
			e=fgetc(f);
			fgets(d,50,f);
			printf("you purchased %s \ndo you want to rate it 1.yes 2.no:",d);
			scanf("%d",&p);
			m=strlen(d);
			d[m-2]='\0';
			if(p==2)
			{}
			else if(p==1)
			{
				printf("enter your review:\n");
				scanf("%s",rate);
				t=fopen("ratings.txt","a");
				fprintf(t,"%c.%c.%s.%d\n",l,c,d,calculate(rate));
			}
		}
		fgets(d,50,f);
		e=fgetc(f);
	}
fclose(f);
f=fopen("ac.txt","r");
	while(!feof(f))
	{
		v=getc(f);
		if(v==i+48)
		{
			c=fgetc(f);
			c=fgetc(f);
			l=fgetc(f);
			l=fgetc(f);
			e=fgetc(f);
			fgets(d,50,f);
			printf("you purchased %s \ndo you want to rate it 1.yes 2.no:",d);
			scanf("%d",&p);
			m=strlen(d);
			d[m-2]='\0';
			if(p==2)
			{}
			else if(p==1)
			{
				printf("enter your review:\n");
				scanf("%s",rate);
				t=fopen("ratings.txt","a");
				fprintf(t,"%c.%c.%s.%d\n",l,c,d,calculate(rate));
			}
		}
		fgets(d,50,f);
		e=fgetc(f);
	}
fclose(f);
f=fopen("dslr.txt","r");
	while(!feof(f))
	{
		v=getc(f);
		if(v==i+48)
		{
			c=fgetc(f);
			c=fgetc(f);
			l=fgetc(f);
			l=fgetc(f);
			e=fgetc(f);
			fgets(d,50,f);
			printf("you purchased %s \ndo you want to rate it 1.yes 2.no:",d);
			scanf("%d",&p);
			m=strlen(d);
			d[m-2]='\0';
			if(p==2)
			{}
			else if(p==1)
			{
				printf("enter your review:\n");
				scanf("%s",rate);
				t=fopen("ratings.txt","a");
				fprintf(t,"%c.%c.%s.%d\n",l,c,d,calculate(rate));
			}
		}
		fgets(d,50,f);
		e=fgetc(f);
	}
fclose(f);
f=fopen("laptops.txt","r");
	while(!feof(f))
	{
		v=getc(f);
		if(v==i+48)
		{
			c=fgetc(f);
			c=fgetc(f);
			l=fgetc(f);
			l=fgetc(f);
			e=fgetc(f);
			fgets(d,50,f);
			printf("you purchased %s \ndo you want to rate it 1.yes 2.no:",d);
			scanf("%d",&p);
			m=strlen(d);
			d[m-2]='\0';
			if(p==2)
			{}
			else if(p==1)
			{
				printf("enter your review:\n");
				scanf("%s",rate);
				t=fopen("ratings.txt","a");
				fprintf(t,"%c.%c.%s.%d\n",l,c,d,calculate(rate));
			}
		}
		fgets(d,50,f);
		e=fgetc(f);
	}
fclose(f);
f=fopen("homet.txt","r");
	while(!feof(f))
	{
		v=getc(f);
		if(v==i+48)
		{
			c=fgetc(f);
			c=fgetc(f);
			l=fgetc(f);
			l=fgetc(f);
			e=fgetc(f);
			fgets(d,50,f);
			printf("you purchased %s \ndo you want to rate it 1.yes 2.no:",d);
			scanf("%d",&p);
			m=strlen(d);
			d[m-2]='\0';
			if(p==2)
			{}
			else if(p==1)
			{
				printf("enter your review:\n");
				scanf("%s",rate);
				t=fopen("ratings.txt","a");
				fprintf(t,"%c.%c.%s.%d\n",l,c,d,calculate(rate));
			}
		}
		fgets(d,50,f);
		e=fgetc(f);
	}
fclose(f);
f=fopen("kitchen.txt","r");
	while(!feof(f))
	{
		v=getc(f);
		if(v==i+48)
		{
			c=fgetc(f);
			c=fgetc(f);
			l=fgetc(f);
			l=fgetc(f);
			e=fgetc(f);
			fgets(d,50,f);
			printf("you purchased %s \ndo you want to rate it 1.yes 2.no:",d);
			scanf("%d",&p);
			m=strlen(d);
			d[m-2]='\0';
			if(p==2)
			{}
			else if(p==1)
			{
				printf("enter your review:\n");
				scanf("%s",rate);
				t=fopen("ratings.txt","a");
				fprintf(t,"%c.%c.%s.%d\n",l,c,d,calculate(rate));
			}
		}
		fgets(d,50,f);
		e=fgetc(f);
	}
fclose(f);
}
void disp(int i)
{
	int c,ch;
	printf("enter \n\n1.electronics\n2.laptops\n3.home appliances\n4.DSLR\n5.exit:");
	scanf("%d",&c);
	if(c==1)
	{
printf("\n\nelectronics\n1.mobiles\n2.laptops\n3.home thetares\n4.DSLR\n5.television\n:");
scanf("%d",&ch);
switch(ch)
{
	case 1:mobiles(i);
	       break;
	case 2:laptops(i);
	       break;
	case 3:homet(i);
	       break;
	case 4:dslr(i);
	       break;
	case 5:break;
}
}
else if(c==2)
{
printf("\n1.ac\n2.kitchen appliances\n3.exit:");
scanf("%d",&ch);
	switch(ch)
	{
		case 1:ac(i);
		       break;
		case 2:kitchen(i);
		       break;
		case 3:break;
	}
}
if(c==3)
{}
}
void dslr(int i)
{
	int c,ch;
	printf("DSLR's\n1.nikon D850 kit(24-120mm VR lens)\n2.canon EOS 5D mark IVkit(EF 24-105IS II USM) 30-4 MP black\n3.Sony A99 II 43.6 MP black\n4.sony alpha A7RM2 42.4 MP black\n5.nikon D750 kit (24-120 mmVR lens):\n6.want to see rating of all products:\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("\nactual price:58299\nprice for u:52499\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"nikon D850",2,1);
		       break;
		case 2:printf("\nactual price 55990\nprice for u:49999\n1 to exit click 2 to buy:");
			scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"canon EOS 5D",2,2);
		       break;
		case 3:printf("\nactual price 137666\nprice for u:124999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"sony A99",2,3);
		       break;
		case 4:printf("\nactual price 299999\nprice for u:256777\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"sony alpha a7rm2" ,2,4);
		       break;
		case 5:printf("\nactual price 69990\nprice for u:48899\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"nikon D750",2,5);
		       break;
		case 6:see_ratings(2,0);
		       break;
		case 7:break;
	}
}

void ac(int i)
{
	int c,ch;
	printf("air conditioners\n1.blue star1.5 ton inverter split air conditioner\n2.toshiba1.5 ton inverter 4star split air conditioner\n3.L.G1.5 ton dual inverter 3star split air conditioner\n4.voltas1 ton 3star inverter split airconditioner:\n5.see ratings");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("\nactual price:20000\nprice for u:17000\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"blue star",5,1);
		       break;
		case 2:printf("\nactual price 25000\nprice for u:22000\n1 to exit click 2 to buy:");
			scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"toshiba",5,2);
		       break;
		case 3:printf("\nactual price 19000\nprice for u:16000\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"LG",5,3);
		       break;
		case 4:printf("\nactual price 17000\nprice for u:13000\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"voltas",5,4);
		       break;
		case 5:see_ratings(5,0);
		       break;
		case 6:break;
	}
}

void homet(int i)
{
	int c,ch;
	printf("home theater\n1.Onkyo SKS-HT870 home thetare speaker\n2.LG X-Boom OK99 1.0 home audio system\n3.JBL CINIMA SB$%) wireless soundbar\n4.panasonic SC-UA7GW-K 2.1 channel home audio system\n5.sony MHC-V81D 8.1 channel high power home audio system with bluetooth\n6.see ratinggs");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("\nactual price:56009\nprice for u:43999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"onkyo HT",4,1);
		       break;
		case 2:printf("\nactual price 34990\nprice for u:24499\n1 to exit click 2 to buy:");
			scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"LG HT",4,2);
		       break;
		case 3:printf("\nactual price 45499\nprice for u:37999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"jbl HT",4,3);
		       break;
		case 4:printf("\nactual price 29999\nprice for u:25999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"panosonic HT",4,4);
		       break;
		case 5:printf("\nactual price 27999\nprice for u:24999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"sony HT",4,5);
		       break;
		case 6:see_ratings(4,0);
		       break;
		case 7:break;
	}
}
int calculate(char str[])
{
        int i=0,j=0,l,n=0;
        char c1[]="okay",c2[]="good",c3[]="nice",c4[]="very good",c5[]="excellent",c0[]="very",c6[]="average",c7[]="bad",c8[
]="not";
        char temp[20],c=str[0];
        l=strlen(str);
        printf("%d\n",l);
        while(c!='\0')
        {
                i=0;
                while(c!=' '&&c!='\0')
                {
                        temp[i]=c;
                        i++;
                        j++;
                        c=str[j];
                }
                temp[i]='\0';
                c=str[++j];
                if(strcmp(c0,temp)==0)
                {
                        temp[i++]=' ';
                        while(c!=' ')
                        {
                                temp[i]=c;
                                i++; j++;
                                c=str[j];
                        }
                        temp[i]='\0';
                        c=str[++j];
                }

                if(strcmp(c1,temp)==0)
                        n=1;
                else if(strcmp(c2,temp)==0)
                        n=2;
                else if(strcmp(c3,temp)==0||strcmp(c6,temp)==0)
                        n=3;
                else if(strcmp(c4,temp)==0)
                        n=4;
                else if(strcmp(c5,temp)==0)
                        n=5;
                else if(strcmp(c7,temp)==0||strcmp(c8,temp)==0)
                        n=n-1;

                else
                {
                        if(n<=0)
                                n=1;

		}      
	}
       return n;
}


void laptops(int i)
{
	int c,ch;
	printf("laptops\n1.hp pavilion i5 core,15.6inch,8th Gen,windows 10\n2.apple MacBook Air Core i5,13.3inch,8 GB ram,256GB\n3.microsoft surface book2(intel core i7,16 GB ram,512 GB)\n4.acer predator triton 15.6inch,i7 core,ultra HD thin gaming laptop\n5.MSI gaming 18.4inch,i7 core,8th Gen,8 GB,1TB:\nsee ratings\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("\nactual price:58299\nprice for u:52499\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"hp laptop",3,1);
		       break;
		case 2:printf("\nactual price 55990\nprice for u:49999\n1 to exit click 2 to buy:");
			scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"macbook",3,2);
		       break;
		case 3:printf("\nactual price 137666\nprice for u:124999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"surface book",3,3);
		       break;
		case 4:printf("\nactual price 299999\nprice for u:256777\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"predater",3,4);
		       break;
		case 5:printf("\nactual price 69990\nprice for u:48899\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"MSI",3,5);
		       break;
		case 6:see_ratings(3,0);
		       break;
		case 7:break;
	}
}
void see_ratings(int i,int j)
{
	FILE *f=fopen("ratings.txt","r");
	char c,d,v,e,b,a[50];
	int m=0;
	while(!feof(f))
	{
		while(a[m]!='\0')
			a[m++]='\0';
		m=0;
		if(j!=0)
		{
			v=fgetc(f);
			b=fgetc(f);
			b=fgetc(f);
			e=fgetc(f);
			if(v==i+48&&j+48==b)
			{
				e=fgetc(f);
				while(e!='.')
				{	a[m++]=e;
					e=fgetc(f);
				}
				a[m]='\0';
				m=0;
				e=fgetc(f);
				printf("\n%s::%c",a,e);
			}
		}
		else
		{
			v=fgetc(f);

			if(v==i+48)
			{
				b=fgetc(f);
				b=fgetc(f);
				b=fgetc(f);
				b=fgetc(f);
				while(b!='.')
				{
					a[m++]=b;
					b=fgetc(f);
				}
				a[m]='\0';
				m=0;e=fgetc(f);
				printf("\n%s::%c",a,e);
			}
		}
		e=fgetc(f);
	}
}
			
void mobiles(int i)
{
	int c,ch;
	printf("\n\t\tMobiles\n1.oppo f9 pro\n2.vivo v11 pro\n3.samsung galaxy J8\n4.redmi note5 pro\n5.google pixel 3 XL:\n6.see ratings\n:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("\nactual price:20000\nprice for u:17000\nclick 2 to buy 1 to exit click 3 to view rating:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"oppo f9 pro",1,1);
		       else if(ch==3)
			       see_ratings(1,1);
		       break;
		case 2:printf("\nactual price 25000\nprice for u:22000\n1 to exit click 2 to buy:");
			scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"vivo v11 pro",1,2);
		       break;
		case 3:printf("\nactual price 19000\nprice for u:16000\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"samsung J8",1,3);
		       break;
		case 4:printf("\nactual price 17000\nprice for u:13000\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"note 5 pro",1,4);
		       break;
		case 5:printf("\n\n\nactual price 79000\nprice for u:30000\nclick 2 to buy 1 to exit\n:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"pixel 3 XL",1,5);
		       break;
		case 6:see_ratings(1,0);
		       break;
		case 7:break;
	}
}
void kitchen(int i)
{
	int c,ch;
	printf("kitchen appliances\n1.refrigerator\n2.microwave oven\n3.water purifier\n4.juicer mixers\n5.induction stove\n6.sandwich maker \n7.see ratings");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("\nactual price:56009\nprice for u:43999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"refrigirator",6,1);
		       break;
		case 2:printf("\nactual price 12999\nprice for u:9999\n1 to exit click 2 to buy:");
			scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"microwoven",6,2);
		       break;
		case 3:printf("\nactual price 7899\nprice for u:6599\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"water purifier",6,3);
		       break;
		case 4:printf("\nactual price 4999\nprice for u:3599\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"juicer",6,4);
		       break;
		case 5:printf("\nactual price 7999\nprice for u:4999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"induction stove",6,5);
		       break;
		case 6:printf("\nactual price 3999\nprice for u:2999\nclick 2 to buy 1 to exit:");
		       scanf("%d",&ch);
		       if(ch==2)
			       buy(i,"sandwitch maker",6,6);
		       break;
		case 7:see_ratings(6,0);
		       break;
		case 8:break;
	}
}

void buy(int i,char s[],int code,int n)
{
	FILE *f;
	switch(code)
	{
		case 1:f=fopen("mobiles.txt","a");
		       break;
		case 2:f=fopen("dslr.txt","a");
		       break;
		case 3:f=fopen("laptops.txt","a");
		       break;
		case 4:f=fopen("homet.txt","a");
		       break;
		case 5:f=fopen("ac.txt","a");
		       break;
		case 6:f=fopen("kitchen.txt","a");
		       break;
	}
	fprintf(f,"%d.%d.%d.%s\n",i,n,code,s);
	fclose(f);
}	



