#include "Guess_Start.h"

Guess::Guess()
{
  m_Max = MAX;
  Target = -1;
  m_Min = 0;
}

void Guess::Set_Max()
{
  int Max;
  cout<<"�����뱻����ֵ������: ";
  cin>>Max;
  m_Max = Max;
}

int Guess::Judge(int Guess_Num)
{
 if(Guess_Num==Target)
 {

	 return 1;
 }
 else if(Guess_Num>Target) 
 {
	 m_Max = Guess_Num;
	 MessageBox("������",m_Min,"��",m_Max,"֮��","��ʾ",MB_ICONASTERISK|MB_OK);
	 //cout<<"������"<<m_Min<<"��"<<m_Max<<"֮��"<<endl;
	 return 0;    
 }
 else if(Guess_Num<Target)
 {
     m_Min = Guess_Num;
	 MessageBox("������",m_Min,"��",m_Max,"֮��","��ʾ",MB_ICONASTERISK|MB_OK);
	// cout<<"������"<<m_Min<<"��"<<m_Max<<"֮��"<<endl;
	 return 0;
 }
 return 0;
}

void Guess::Play()
{
srand(time(NULL));
Target = rand()%m_Max + 1;

//cout<<Target<<endl;

 while(1)
 {

 // cout<<"������Ҫ�µ���: ";

  if(Judge(Person)==1)  
  {
  MessageBox("�����������֣����Ի�ʤ!","��ʾ",MB_ICONWARNING|MB_OK);
  //cout<<"�����������֣����Ի�ʤ!"<<endl;
  break;
  }
  //srand(time(NULL));
  Computer = m_Min+rand()%(m_Max-m_Min-1)+1;

 // cout<<"���Բµ���: "<<Computer<<endl;

  if(Judge(Computer)==1)  
  {
  MessageBox("�����������֣����Ի�ʤ!","��ʾ",MB_ICONWARNING|MB_OK);
  //cout<<"�����������֣�����ʤ��!"<<endl;
  break;
  }
 }
}