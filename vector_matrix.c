#define MAX 100

void print_vector(double vector[] , int n);
void print_matrix(double matrix[][MAX] , int m);
void input_vector(double vector[] , int n);
void input_matrix(double vector[][MAX] , int m);

double dot_product(double left[], double right[], int n);
void matrix_product(double left[][MAX] , double right[][MAX],
		    double result[][MAX], int n);

#include<stdio.h>
int main()
{
  int n, m;
  double vector1[MAX];
  double vector2[MAX];
  double result1;

  double matrix1[MAX][MAX];
  double matrix2[MAX][MAX];
  double result2[MAX][MAX];
  printf("ベクトルの要素数を入力\n");
  scanf("%d",&n);
  input_vector(vector1,n);
  input_vector(vector2,n);
  printf("ベクトル\n");
  print_vector(vector1,n);
  printf("と　ベクトル\n");
  print_vector(vector2,n);
  printf("の内積の計算をします。\n");
  result1=dot_product(vector1,vector2,n);
  printf("内積の値は%6.2fです。\n",result1);
  
  printf("正方行列の次数を入力\n");
  scanf("%d",&m);
  input_matrix(matrix1,m);
  input_matrix(matrix2,m);
  printf("行列\n");
  print_matrix(matrix1,m);
  printf("と　行列\n");
  print_matrix(matrix2,m);
  printf("の積の計算をします。\n");
  printf("積は\n");
  matrix_product(matrix1,matrix2,result2,m);
  printf("です。\n");
  return 0;
}
void print_vector(double vector[],int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      printf("%6.2f\n",vector[i]);
    }
}

void input_vector(double vector[], int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      scanf("%lf",&vector[i]);
    }
}

void print_matrix(double matrix[][MAX],int m)
{
  int i,j;
  for(i=0;i<m;i++)
    {
      for(j=0;j<m;j++)
	{
	  printf("%6.2f",matrix[i][j]);
	}
       printf("\n");
    }
}

void input_matrix(double matrix[][MAX],int m)
{
  int i,j;
   for(i=0;i<m;i++)
    {
      for(j=0;j<m;j++)
	{
	  scanf("%lf",&matrix[i][j]);
	}
    }
}

double dot_product(double left[], double right[], int n)
{
  double result=0.0;
  int i;
  for(i=0;i<n;i++)
    {
      result=result+left[i]*right[i];
    }
  return result;
}

void matrix_product(double left[][MAX], double right[][MAX], double result[][MAX], int m){
  int i,j,k;
  for(i=0;i<m;i++){
    for(j=0;j<m;j++){
      result[i][j]=0;
      for(k=0;k<m;k++){
	result[i][j]+=left[i][k]*right[k][j];
      }
      printf("%6.2f",result[i][j]);
    }
    printf("\n");
  }
}
