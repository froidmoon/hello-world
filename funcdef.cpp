#include <string>
#include <iostream>
#include "func.h"
using namespace std;

//#ifndef
string sayhi(){
	cout<<"欢迎你，冒险者,能告诉我你的名字吗？"<<endl;
	string PlayerName;
	cin>> PlayerName;
	cout<<"你好，冒险者，现在我们遇到了困难，可能需要你的帮忙。\n"<<endl;
	system("pause");
	system("cls");
	return PlayerName;
}
//物品类的定义
eqp KNIFE={"劣质小刀",1,101,1,2};
//怪兽类的定义
monster::monster(string name,int lv,int atk,int def,int life){
		mon_name=name;
		mon_lv=lv;
		mon_atk=atk;
		mon_def=def;
		mon_life=life;

		cout<<mon_name<<" 出现了！"<<endl;
	}

monster::~monster(){
		cout<<mon_name<<"消失了！"<<endl;
	}
monster::monsterprint(){
		cout<<"\n========怪物信息========"<<endl;
		cout<<"等级："<<mon_lv<<"\t\t攻击力："<<mon_atk;
		cout<<"\n防御力："<<mon_def<<"\t生命值："<<mon_life;
		cout<<"\n========================\n";
	}

monster::monsteratk(player& p){
	p.P_life-=(mon_atk*(1-p.P_def));
	return p.P_life;
	}
//玩家类的定义
player::player(string name,int lv,int atk,int def,int life){
		P_name=name;
		P_lv=lv;
		P_atk=atk;
		P_def=def;
		P_life=life;
		P_take[1]=KNIFE;
		

		
	}
player::~player(){
	cout<<"你倒下了，游戏失败！"<<endl;
	}
player::playerprint(){
	cout<<"\n========玩家信息========"<<endl;
		cout<<"等级："<<P_lv<<"\t\t攻击力："<<P_atk;
		cout<<"\n防御力："<<P_def<<"\t生命值："<<P_life;
		cout<<"\n携带物品："<<P_take[1].name;
		cout<<"\n========================\n";
	}

player::playeratk(monster& m){
	m.mon_life-=(P_atk*(1-m.mon_def));
	cout<<this->P_name<<" 攻击了 "<<m.mon_name<<"!"<<" 造成了"<<(P_atk*(1-m.mon_def))<<"点伤害！"<<endl;	
	return m.mon_life;
	}
//操作模块
void playerdo(player& p,monster& m){
	while(m.mon_life>0){
	int inp;
	cout<<"请输入你要进行的操作！"<<"\n";
	cout<<"1.攻击  2.使用物品  3.逃跑  4.查看玩家状态  5.查看怪物状态"<<"\n========================\n输入操作：";
	cin>>inp;
	switch(inp){
	case 1: {p.playeratk(m);cout<<"\n怪物还击了！\n"<<endl;m.monsteratk(p);break;}
	case 2: {eqpd(p,KNIFE);cout<<"你装备了"<<KNIFE.name<<"!"<<endl;
//		if(!p.take.num) {cout<<"你还未获得任何物品！";}
//		else{} 
		break;}
	case 3: {m.mon_life=0;break;}
	case 4: {p.playerprint();continue;}
	case 5: {m.monsterprint();continue;}
	default: {m.monsteratk(p);break;}
	}
	}
	m.~monster();
	cout<<"要继续前进吗？ Y/N"<<endl;
	system("pause");

	}
void eqpd(player& p,eqp& z){
	p.P_take[1]=z;
}
void printthing(player& p){
	int size=(p.P_take).size();
	for(int i=0;i<size;i++){cout<<p.P_take[i].name<<"  "<<endl;}
}
