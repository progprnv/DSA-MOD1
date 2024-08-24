#include<stdio.h>
#include<stdlib.h>
int a[10][10],b[10][10],spar[10][10],spar2[10][10],t[10][10],sum[10][10],row,col,count,n,r,c,x,co;
void disp(){
int i,j;
printf("the sparse matrix is\n");
for(i=0;i<=count;i++){
	for(j=0;j<3;j++){
		printf("%d\t",spar[i][j]);
		}
		printf("\n");
	}
}
void disp2(){
printf("the transpose of sparse matrix is\n");
int i,j;
for(i=0;i<=count;i++){
	for(j=0;j<3;j++){
		printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
}
void disp3(){
int i,j;
printf("the sparse matrix is\n");
for(i=0;i<=co;i++){
	for(j=0;j<3;j++){
		printf("%d\t",spar2[i][j]);
		}
		printf("\n");
	}
}
void spars(){
    int i,j;
	spar[0][0]=row;
	spar[0][1]=col;
	count=0;
	n=1;
	for(i=0;i<=row;i++){
		for(j=0;j<=col;j++){
			if(a[i][j]!=0){
			spar[n][0]=i;
			spar[n][1]=j;
			spar[n][2]=a[i][j];
			n++;
			count++;
			}
		}
	}
	spar[0][2]=count;
	disp();
}
void spars2(){
    int i,j;
	spar2[0][0]=row;
	spar2[0][1]=col;
	co=0;
	x=1;
	for(i=0;i<=r;i++){
		for(j=0;j<=c;j++){
			if(b[i][j]!=0){
			spar2[x][0]=i;
			spar2[x][1]=j;
			spar2[x][2]=b[i][j];
			x++;
			co++;
			}
		}
	}
	spar2[0][2]=co;
	disp3();
}
void trans(){
	int i,j, k=1;
	t[0][0]=spar[0][1];
	t[0][1]=spar[0][0];
	t[0][2]=spar[0][2];
	for(i=0;i<=spar[0][1];i++){
		for(j=0;j<=spar[0][2];j++){
			if(spar[j][1]==i){
			t[k][0]=spar[j][1];
			t[k][1]=spar[j][0];
			t[k][2]=spar[j][2];
			k++;
			}
		}
	}
	disp2();
}
void add(){
    int i=1,j=1,s=1,non=0;
    sum[0][0] = spar[0][0];
    sum[0][1] = spar[0][1];
    while((i<=spar[0][2])&&(j<=spar2[0][2])) {
    if(spar[i][0] == spar2[j][0]) {
        if(spar[i][1] == spar2[j][1]) {
             sum[s][0] = spar[i][0];
             sum[s][1] = spar[i][1];
             sum[s][2] = spar[i][2] + spar2[j][2];
             s++;
             i++;
             j++;
            }
        }
    else if (spar[i][1]<spar2[j][1]) 
         {
          sum[s][0] = spar[i][0];
          sum[s][1] = spar[i][1];
          sum[s][2] = spar[i][2];
          s++;
          i++;
        }
    else if(spar[i][1]>spar2[j][1]) 
       {
         sum[s][0] = spar2[j][0];
         sum[s][1] = spar2[j][1];
         sum[s][2] = spar2[j][2];
         s++;
         j++;
       }
    else if (spar[i][0]<spar2[j][0]) 
      {
        sum[s][0] = spar[i][0];
        sum[s][1] = spar[i][1];
        sum[s][2] = spar[i][2];
        s++;
      i++;
    }
    else if(spar[i][0]>spar2[j][0]) {
          sum[s][0] = spar2[j][0];
          sum[s][1] = spar2[j][1];
          sum[s][2] = spar2[j][2];
          s++;
          j++;
       }

    }
    while(i<=spar[0][2]) 
  {
       sum[s][0] = spar[i][0];
       sum[s][1] = spar[i][1];
       sum[s][2] = spar[i][2];
       s++;
       i++;
    }
   while(j<=spar2[0][2]) 
   {
     sum[s][0] = spar2[j][0];
     sum[s][1] = spar2[j][1];
     sum[s][2] = spar2[j][2];
     s++;
     j++;
   }
sum[0][2] = s-1;
non = sum[0][2];
printf("Sum of two Sparse Matrix is:\n");
for(i=0; i<=non; i++)
   {
      for(j=0; j<3; j++)
        {
           printf("%d\t",sum[i][j]);
        }
      printf("\n");
   }
}
void main(){
int i,j;
printf("enter the row");
scanf("%d",&row);
printf("enter the col");
scanf("%d",&col);
printf("enter the elements");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		scanf("%d",&a[i][j]);
		}
	}
printf("the first matrix is\n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
printf("enter the row");
scanf("%d",&r);
printf("enter the col");
scanf("%d",&c);
printf("enter the elements");
for(i=0;i<r;i++){
	for(j=0;j<c;j++){
		scanf("%d",&b[i][j]);
		}
	}
printf("the second matrix is\n");
for(i=0;i<r;i++){
	for(j=0;j<c;j++){
		printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	while(1){
		int ch;
		printf("\n1.sparse\n2.trans\n3.add\n4.exit");
		printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				spars();
                spars2();
				break;
			case 2:
                disp();
				trans();
				break;
			case 3:
				add();
				break;
			case 4:
				exit(0);
		}
	}
}
