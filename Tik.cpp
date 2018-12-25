#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void display(int Board[][3]) //To display Board
{
  cout<<"\n\n";
  for (int i=0;i<3;i++)
    {
      cout<<"\t";
      for (int j=0;j<3;j++)
      {
        if (Board[i][j]==0)
          cout<<i*3+j+1;
        else if (Board[i][j]==1)
          cout<<"*";
        else if (Board[i][j]==(-1))
          cout<<"&";
        if (j!=2)
        cout<<" | ";
      }
      cout<<endl;
      if (i!=2)
        cout<<"\t--+---+---"<<endl;
    }
   cout<<"\n\n\t0. To switch or Undo\n\n";
}
bool VMove(int n,int Board[][3]) // To check valid move
{
  if (Board[(n-1)/3][(n-1)%3]!=0)
    return false;
  return true;
}
void Move(int n,int Board[][3],int t) //To make Move
{
  Board[(n-1)/3][(n-1)%3]=t;
}
void BMove(int n,int Board[][3]) //To backtrack Move
{
  Board[(n-1)/3][(n-1)%3]=0;
}
bool CheckW(int Board[][3]) //To check win
{
  for (int i=0;i<3;i++)
     if (Board[i][0]==Board[i][1]&&Board[i][1]==Board[i][2]&&Board[i][0]!=0)
        return true;
  for (int i=0;i<3;i++)
     if (Board[0][i]==Board[1][i]&&Board[1][i]==Board[2][i]&&Board[1][i]!=0)
        return true;
  if (Board[0][0]==Board[1][1]&&Board[1][1]==Board[2][2]&&Board[1][1]!=0)
    return true;
  if (Board[0][2]==Board[1][1]&&Board[1][1]==Board[2][0]&&Board[1][1]!=0)
    return true;
  return false;
}
bool CheckB(int Board[][3]) //To check Board Full
{
  for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
      if (Board[i][j]==0)
        return false;
  return true;
}
int Player1(int Board[][3],string s)
{
  int n;
  cout<<s<<" enter your move : ";
  cin>>n;
  if (n==0)
  {
    if (!::s.empty())
    {BMove(::s.top(),Board);
     ::s.pop();}
    return 2;
  }
  while(!VMove(n,Board))
  {
    cout<<s<<" entered wrong move!!\n\nEnter again : ";
    cin>>n;
  }
  ::s.push(n);
  Move(n,Board,1);
  if (CheckW(Board))
    return 1;
  if (CheckB(Board))
    return 0;
  return -1;
}
int Player2(int Board[][3],string s)
{
  int n;
  cout<<s<<" enter your move : ";
  cin>>n;
  if (n==0)
  {
    if (!::s.empty())
    {BMove(::s.top(),Board);
     ::s.pop();}
    return 2;
  }
  while(!VMove(n,Board))
  {
    cout<<s<<" entered wrong move!!\n\nEnter again : ";
    cin>>n;
  }
  ::s.push(n);
  Move(n,Board,-1);
  if (CheckW(Board))
    return 1;
  if (CheckB(Board))
    return 0;
  return -1;
}
int main()
{
  int Board[3][3]={0};
  int flag=0,n,conti=0;
  string s1,s2;
  system("clear");
  cout<<"Enter player1 name : ";
  cin>>s1;
  cout<<"Enter player2 name : ";
  cin>>s2;
  while(1)
  {
    system("clear");
    display(Board);
    if (flag==0)
    {
      cout<<"\n\n\tPlayer 1 ( * )\n\n";
      n=Player1(Board,s1);
      if (n==1)
        {  system("clear");
           display(Board);
           cout<<s1<<" Won\n";conti=1;}
      if (n==0)
        {cout<<"Match Draw\n";conti=1;}
      flag=1;
    }
    else if (flag==1)
    {
      cout<<"\n\n\tPlayer 2 ( & )\n\n";
      n=Player2(Board,s2);
      if (n==1)
        {  system("clear");
           display(Board);
           cout<<s2<<" Won\n";conti=1;}
      if (n==0)
        {cout<<"Match Draw\n";conti=1;}
      flag=0;
    }
    if (conti==1)
    {
      cout<<"Do you want to countinue (y/n): ";
      char ch;
      cin>>ch;
      if (ch=='n'||ch=='N')
        break;
      conti=0;
      for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
          Board[i][j]=0;
    }
  }
  system("clear");
}
