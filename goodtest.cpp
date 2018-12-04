#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include "func.h"
using namespace std;

//game test 
int main(){
 string pn;

 pn=sayhi();

 //测试用户名赋值
 //cout<<pn<<endl;
 player p(pn,1,1,0.3,10);
 monster m("弱小的怪物",1,1,0,7);
 m.monsterprint();
 playerdo(p,m);



 return 0;
}
