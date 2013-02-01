#include "Poker.h"


Poker::Poker()
{
  for(int i=0;i<10;i++)
  m_oringal[i] = i + 1;
  A.num=0;
  B.num=0;
}

void Poker::Deal()
{

int random,i,j,temp;

srand(time(NULL));

i=0;

while(1)
{
 random = rand()%10 + 1;
 //cout<<random<<endl;
  for(j=0;j<10;j++)
  {
	if(m_oringal[j]==random)
	{
		A.a[i]=random;
		//cout<<A.a[i]<<endl;
	    A.num++;
		m_oringal[j]=0;
		i++;
		break;
	}
  }

  if(i==5)
  break;
}

i=0;

while(1)
{
  random = rand()%10 + 1;
  for(j=0;j<10;j++)
  {
	if(m_oringal[j]==random)
	{
		B.a[i]=random;
	    B.num++;
		m_oringal[j]=0;
		i++;
		break;
	}
  }

  if(i==5)
  break;
}

for(i=0;i<5;i++)
   for(j=1;j<5-i;j++)
   {
	   if(B.a[j-1]>B.a[j])
	   {
       temp=B.a[j-1];
	   B.a[j-1]=B.a[j];
	   B.a[j]=temp;
	   }
   }

}

void Poker::Play()
{
 int buffer_A,buffer_B=0,j,i;
 int signal=0;

 cout<<"�������ǣ�"<<endl;
 for(i=0;i<5;i++)
 cout<<A.a[i]<<" ";
 cout<<endl;
while(1)
{

if(A.num==0||B.num==0)
{
    cout<<"��Ϸ����!"<<endl;
    break;
}

 cout<<"����ƣ�Ҫ������������������0��"<<endl;
 cin>>buffer_A;

 for(j=0;j<A.num;j++)
  {
   if(A.a[j]==buffer_A&&buffer_A>buffer_B)
	{
      for(i=j+1;i<A.num;i++)
		  A.a[i-1]=A.a[i];

	      A.num--;

	      cout<<"�����ƻ��У�"<<endl;
          for(i=0;i<A.num;i++)
          cout<<A.a[i]<<" ";
          cout<<endl;

	      if(A.num==0)
	      cout<<"��Ӯ��!"<<endl;
	      break;
	}
  }

 if(j==5)
 {
	   signal=1;
	   buffer_A=0;
	  // cout<<"������Ҫ�������ƴ���! "<<endl; 
 }

 if(signal==1)
 {
 for(j=0;j<5;j++)
  {
	if(B.a[j]!=0)
	{
	   cout<<"���������Ϊ��"<<endl;
	   cout<<B.a[j]<<endl;
	   buffer_B=B.a[j];
	   B.a[j]=0;
	   B.num--;
	   if(B.num==0)
	   cout<<"�����Ӯ��!"<<endl;
	   signal=0;
	   break;
	}
  }
 }
else
{
  for(j=0;j<5;j++)
  {
	if(buffer_A<B.a[j])
	{
	   cout<<"���������Ϊ��"<<endl;
	   cout<<B.a[j]<<endl;
	   buffer_B=B.a[j];
	   B.a[j]=0;
	   B.num--;
	   if(B.num==0)
	   cout<<"�����Ӯ��!"<<endl;
	   break;
	}
  }
}

	 if(j==5)
	{
    cout<<"�����Ҫ����!"<<endl;
	buffer_B=0;
	}
  
}
}