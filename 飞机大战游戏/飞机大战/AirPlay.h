#pragma once
#include <easyx.h>
#include <time.h>
#include "list.h"
#include "tools.h"
#include <time.h>

//窗口大小
#define BGWEIGHT 400 //宽
#define BGHEIGHT 600 //高
//我方飞机大小
#define myAirWEIGHT 80
#define myAirHEIGHT 90
//飞碟大小
#define enemyPlaneWEIGHT 50
#define enemyPlaneHEIGHT 50
//子弹大小
#define BulletWEIGHT 10
#define BulletHEIGHT 10
//子弹数量
#define BULLET_NUM 30
//敌机数量
#define ENEMY_NUM 10

IMAGE img[4];//图片数组
IMAGE img_bullet[2];
IMAGE img_enemy[2];
IMAGE Boom[2];
IMAGE End[2];

struct Plane {
	int x; 
	int y;
	bool isDie;
	int frame;
}gamer;

Plane enemy[ENEMY_NUM];
                                   
struct BUllet {
	int x;
	int y;
	bool isDie;
	/*int frame;*/
}bullet[BULLET_NUM];

bool Timer(int ms, int id) {
	static int start[5];
	int end = clock();
	if (end - start[id] >= ms) {
		start[id] = end;
		return true;
	}
	return false;
}

void createBullet() {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].isDie) {
			bullet[i].x = gamer.x + img[1].getwidth() / 2;
			bullet[i].y = gamer.y;
			bullet[i].isDie = false;
			break;
		}
	}
}

void moveBullet() {
	for (int i = 0; i < BULLET_NUM; i++) {
		if (!bullet[i].isDie) {
			bullet[i].y -= 10;

			if (bullet[i].y < 0) {
				bullet[i].isDie = true;
			}
		}
		
		
	}
}

void boomEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (enemy[i].isDie) continue;
		for (int j = 0; j < BULLET_NUM; j++) {
			if (bullet[j].isDie) continue;

			if (bullet[j].y<enemy[i].y && bullet[j].x > enemy[i].x && bullet[j].x < enemy[i].x + img_enemy->getwidth()) {
				putimagePNG(enemy[i].x, enemy[i].y, &Boom[0]);
				Sleep(10);
				putimagePNG(enemy[i].x, enemy[i].y, &Boom[1]);
				Sleep(10);
				bullet[j].isDie = true;
				enemy[i].isDie = true;
			}
		}
	}
}

void plane_draw(Plane* p) {
	putimagePNG(p->x, p->y, &img[1 + p->frame]);
	p->frame++;
	if (p->frame > 2) {
		p->frame = 0;
	}
}

void draw() {
	//输出背景图片
	putimage(0, 0, &img[0]);
	//绘制飞机
	plane_draw(&gamer);
	//绘制子弹
	for (int i = 0; i < BULLET_NUM; i++) {
		if (!bullet[i].isDie)
			putimagePNG(bullet[i].x, bullet[i].y, &img_bullet[0]);
	}

	for (int i = 0; i < ENEMY_NUM; i++) {
		if (!enemy[i].isDie)
			putimagePNG(enemy[i].x, enemy[i].y, &img_enemy[0]);
	}

}

void endPlane() {
	int offset = 20; // 碰撞内缩像素，数值越大判定越宽松（越不容易死）
	for (int i = 0; i < ENEMY_NUM; i++) {
		// 只有在屏幕内且未死亡的敌机才检测
		if (enemy[i].isDie || enemy[i].y < 0) continue;

		// 缩减判定区域，让玩家感受更公平
		if (gamer.y + offset < enemy[i].y + img_enemy[0].getheight() - offset &&
			gamer.y + img[1].getheight() - offset > enemy[i].y + offset &&
			gamer.x + offset < enemy[i].x + img_enemy[0].getwidth() - offset &&
			gamer.x + img[1].getwidth() - offset > enemy[i].x + offset) {

			draw(); // 解决黑屏：死前先画最后一帧
			putimagePNG(BGWEIGHT / 2 - 50, BGHEIGHT / 2 - 50, &End[0]);
			putimagePNG(gamer.x, gamer.y, &End[1]);

			FlushBatchDraw(); // 强制刷新画面到屏幕
			EndBatchDraw();

			MessageBox(GetHWnd(), _T("游戏结束！"), _T("提示"), MB_OK);
			exit(0);
		}
	}
}


void plane_init(Plane* p,int x,int y) {
	p->x = x;
	p->y = y;
	p->isDie = false;
	p->frame = 0;
}




//创建敌机
void createEnemy() {
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].isDie) {
			enemy[i].x = rand() % getwidth();
			enemy[i].y = -img_enemy[0].getheight();
			enemy[i].isDie = false;
			break;
		}
	}
}

void plane_move(Plane* p) {
	int speed = 12;
	if(GetAsyncKeyState(VK_UP)&& p->y>0){
		p->y-=speed;
	}
	if (GetAsyncKeyState(VK_DOWN)&& p->y+ img[1].getheight()<getheight()-10){
		p->y+= speed;
	}
	if (GetAsyncKeyState(VK_LEFT)&& p->x+img[1].getwidth() / 2>0) {
		p->x-= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT)&& p->x+img[1].getwidth()/2<getwidth()){
		p->x+= speed;
	}
	if (GetAsyncKeyState(VK_SPACE)&& Timer(100,0) ){
		createBullet();
	}
	if (Timer(1000, 1)) {  // 敌机生成
		createEnemy();
	}
}	

void moveEnemy(){
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].isDie) {
			enemy[i].y += 3;
			if (enemy[i].y>getheight())
			{
				enemy[i].isDie = true;
			}
		}
	}
}

//初始化函数
void init(){
	//加载图片
	loadimage(&img[0], "res\\beijing.png",BGWEIGHT,BGHEIGHT);
	loadimage(&img[1], "res\\plane.png", myAirWEIGHT, myAirHEIGHT);
	loadimage(&img[2], "res\\plane2.png", myAirWEIGHT, myAirHEIGHT);
	loadimage(&img[3], "res\\plane3.png", myAirWEIGHT, myAirHEIGHT);
	loadimage(&img_bullet[0], "res\\daodan.png", BulletWEIGHT, BulletHEIGHT);
	loadimage(&img_bullet[1], "res\\daodan2.png", BulletWEIGHT, BulletHEIGHT);
	loadimage(&img_enemy[0], "res\\feidie.png", enemyPlaneWEIGHT, enemyPlaneHEIGHT);
	loadimage(&img_enemy[1], "res\\feidie2.png", enemyPlaneWEIGHT, enemyPlaneHEIGHT);
	loadimage(&Boom[0], "res\\boom.png", enemyPlaneWEIGHT, enemyPlaneHEIGHT);
	loadimage(&Boom[1], "res\\boom2.png", enemyPlaneWEIGHT, enemyPlaneHEIGHT);
	loadimage(&End[0], "res\\gameover.png", 100, 100);
	loadimage(&End[1], "res\\planeboom.png", myAirWEIGHT,myAirHEIGHT);

	//初始化飞机
	plane_init(&gamer,160,500);
	//初始化子弹
	for (int i = 0; i < BULLET_NUM; i++) {
		bullet[i].isDie = 1;
	}
	//初始化敌机
	for (int i = 0; i < ENEMY_NUM; i++) {
		enemy[i].isDie = true;
	}


}



void start() {

	initgraph(BGWEIGHT, BGHEIGHT);
	init();
	

	BeginBatchDraw();
	while (1) {
		int startTime = clock();
		draw();
		plane_move(&gamer);
		int frameTime = clock() - startTime;
		if (1000 / 10 - frameTime > 0) {
			Sleep(1000 / 10 - frameTime);
		}
		moveBullet();
		if (Timer(1000,0))
		{
			createEnemy();
		}
		/*createEnemy();*/
		moveEnemy();
		boomEnemy();
		endPlane();
		FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	
}





