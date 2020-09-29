#include<iostream>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT  2
#define RIGHT 3

struct Node
{
    int xy[3][3];  //九宫格
    int dir;  //dir的0 1 2 3分别表示上一步的移动；上下左右
};

Node step[102],end; //最多可走步数
int count = 1;   //搜索总次数

//初始化
void  init()
{
    int i,j;
    cout<<"请输入初始值"<<endl;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
        cin>>step[0].xy[i][j];
    step[0].dir=-1;
    cout<<"请输入目标值"<<endl;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
        cin>>step[102].xy[i][j];
    step[102].dir=-1;
}

//找到0位置
int location(int num)
{
    int i;
    for(i=0;i<9;i++)
      if(step[num].xy[i/3][i%3] == 0) return i;

    cout<<"未能找到0位置"<<endl;
    return -1;
}

//唯一性标记
long long sign(int num){
    long long sum = 0;
    int p = 1,i,j;
    for(i=2;i>=0;i--)
      for(j=2;j>=0;j--)
      {
          sum += step[num].xy[i][j]*p;
          p=p*10;
}
    return sum;
}

//对0进行移动
void move(int num)
{
    int loc;
    loc = location(num);
    int stand = step[num].dir;
    if(loc / 3 != 0 && stand != UP)
    {
        step[count] = step[num];
        step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 - 1][loc % 3];
        step[count].xy[loc / 3 - 1][loc % 3] = 0;
        step[count].dir = DOWN;
        count++;
    }
    if(loc / 3 != 2 && stand != DOWN)
    {
        step[count] = step[num];
        step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 + 1][loc % 3];
        step[count].xy[loc / 3 + 1][loc % 3] = 0;
        step[count].dir = UP;
        count++;
    }
    if(loc % 3 != 0 && stand != LEFT)
    {
        step[count] = step[num];
        step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 ][loc % 3 - 1];
        step[count].xy[loc / 3 ][loc % 3 - 1] = 0;
        step[count].dir = RIGHT;
        count++;
    }
    if(loc % 3 != 2 && stand != RIGHT)
    {
      step[count] = step[num];
      step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 ][loc % 3 + 1];
      step[count].xy[loc / 3 ][loc % 3 + 1] = 0;
      step[count].dir = LEFT;
      count++;
    }
}

void display(int num)
{
  int i,j;
  for(i = 0;i < 3;i++)
  {
    for(j = 0;j < 3;j++)
      cout<<step[num].xy[i][j];
    cout<<endl;
  }
}

int search()
{
  int i = 0;
  while(1)
  {
    display(i);
    if(i == 101)
    {
      cout<<"超出了上限次数n"<<endl;
      return 0;
    }
    if(sign(i) == sign(101))
    {
      cout<<"在第"<<i<<"次找到了";
      display(i);
      return i;
    }
    move(i);
    i++;
  }
}

int main()
{
  init();
  search();
  return 0;
}





