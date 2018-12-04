#ifndef func_h
#define func_h
#include <string>
#include <iostream>
using namespace std;
///头文件的主要成分：类，结构体定义，函数声明

//问候函数，同时获得用户名称
string sayhi();
//物品类声明
struct eqp{
	char name[20];
	int num;
	int lv;
	int atkp;
	int defp;
};
//怪兽类声明
class monster{
private:
	string mon_name;
	int mon_lv;
public:
	int mon_def;
	int mon_life;
	int mon_atk;
	eqp mon_take;
	friend class player;
	friend void playerdo();

	explicit monster(string name="",int lv=1,int atk=1,int def=0,int life=5);
	~monster();
	monsterprint();//显示怪物信息
	monsteratk(player& );//怪物攻击
};
//玩家类声明
class player{
private:
	string P_name;
	int P_lv;
public:	
	int P_def;
	int P_atk;
	int P_life;
	eqp P_take[5];
	friend class monster;

	explicit player(string name="",int lv=1,int atk=1,int def=0,int life=5);
	~player();
	playerprint();//打印人物状态
	playeratk(monster& );//攻击怪物
};

void playerdo(player&,monster&); //操作模块
void eqpd(player&,eqp&);//装备模块
void printting(player&);//物品菜单模块

#endif 
