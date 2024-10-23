   #include<stdio.h>
   #include<string.h>
   #include<stdlib.h>
   void remove_cmd(char *);
   void header_inclusion(void);
   void macro_replacement(char *);
   int main(int argc,char **argv)
   {
   if(argc!=2)
  {
  printf("usage message\n");
  return 0;
  }
  int i;
  char b[20];
  strcpy(b,argv[1]);
 for(i=0;b[i]!='.';i++);
  b[i+1]='i';
  b[i+2]='\0';
  printf("%s\n",b);
  macro_replacement(argv[1]);
  header_inclusion();
  remove_cmd(b);
  }
////**************COMMENTS REMOVAL**********//////////////////
  void remove_cmd(char *s)
  {
  FILE *fp1,*fp2;
  fp1=fopen("abc.c","r");
  if(fp1==0)
  {
  printf("file is not present\n");
  return;
  }
  fp2=fopen("data","w");
  char ch,ch1;
  while((ch=fgetc(fp1))!=-1)
  {
  if(ch=='/')
  {
  ch1=ch;
  ch=fgetc(fp1);
  if(ch=='/')
  {
  while((ch=fgetc(fp1))!='\n');
  fputc(ch,fp2);
  }
  else if(ch=='*')
  {
  while((ch=fgetc(fp1))!='*');
  if((ch=fgetc(fp1))=='/')
  fputc('\n',fp2);
  }
  else
  {
  fputc(ch1,fp2);
  fputc(ch,fp2);
  }
  }
  else
  fputc(ch,fp2);
  }
  fclose(fp1);
  fclose(fp2);
  }
///************MACRO REPLACEMENT*************///////////////// 
 void macro_replacement(char *s)
  {
  FILE *fp6,*fp7;
  char k[50]="#define",**p,*p1,f[100],macro_name[50],macro_body[50];
  int i,c=0,x,n,l,y,j,l1,l2,l3,l4,v;
  fp6=fopen("abc.c","r");
  if(fp6==0)
  {
  printf("file is not present\n");
  return;
  }
  while(fgets(f,100,fp6))
  c++;
  rewind(fp6);
  p=malloc(sizeof(char)*c);
  for(i=0;i<c;i++)
  p[i]=malloc(sizeof(char)*100);
  i=0;
  while(fgets(p[i++],100,fp6));
  i=0;
  while(i<c)
  {
  if(p1=strstr(p[i],k))
  {
  p1=p1+8;
  for(x=0;p1[x]!=' ';x++)
  macro_name[x]=p1[x];
  macro_name[x]='\0';
  
  y=strlen(macro_name);
  for(l=y,x=0;p1[l]!='\n';l++)
  {
  if(p1[l]!=' ')
  macro_body[x++]=p1[l];
  }
 macro_body[x]='\0';
 l1=strlen(macro_name);
 l2=strlen(macro_body);
 j=0;
 if(l1==l2)
 {
 while(j<c)
 {
 if(p1=strstr(p[j],macro_name))
 {
 for(v=0;macro_name[v];v++)
 p1[v]=macro_body[v];
 }
 j++;
 }
 }
 else if(l1>l2)
 {
 j=0;
 while(j<c)
 {
 if(p1=strstr(p[j],macro_name))
 {
 l3=l1-l2;
 while(l3)
 {
 for(n=0;p1[n];n++)
 p1[n]=p1[n+1];
 l3--;
 }
 for(v=0;macro_body[v];v++)
 p1[v]=macro_body[v];
 j--;
 }
 j++;
 }
 }
 else if(l1<l2)
 {
 j=0;
 while(j<c)
 {
 if(p1=strstr(p[j],macro_name))
 {
 l3=l2-l1;
 while(l3)
 {
 l4=strlen(p1);
 for(;l4>=0;l4--)
 p1[l4+1]=p1[l4];
 l3--;
 }
 for(v=0;macro_body[v];v++)
 p1[v]=macro_body[v];
 j--;
 }
 j++;
 }
 }
 }
 i++;
 }
 for(j=0;j<c;j++)
 {
 if(p1=strstr(p[j],k))
 {
 p1[0]='\0';
 }
 }
 fp7=fopen("result","w");
 for(j=0;j<c;j++)
 fputs(p[j],fp7);
 fclose(fp7);
 }
 //**************HEADER FILE INCLUSION********///////////////
 void header_inclusion(void)
 {
 FILE *fp3,*fp4,*fp5;
 char a[50]="/usr/include/",p[200],p1[20]="#include",q[100],q2[100];
 int i,j,l,m;
 fp5=fopen("result","w");
 fp3=fopen("abc.c","r");
 while(fgets(p,200,fp3))
 {
 if(strstr(p,p1))
 {
 l=strlen(p);
 for(i=0;i<l;i++)
 {
 if(p[i]=='<')
 {
 j=0;
 for(i=i+1;p[i]!='>';i++)
 q[j++]=p[i];
 q[j]=0;
 }
 }
 strcat(a,q);
 printf("%s",a);
 fp4=fopen(a,"r");
 while(fgets(q2,100,fp4))
 fputs(q2,fp5);
 fclose(fp4);
 strcpy(a,m);
 }
 else
 fputs(p,fp5);
 }
 fclose(fp3);
 fclose(fp5);
 }
 Top;
