#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#define	PI	3.1415926
#define	iRadius 160
#define FRAME_COUNT 49
IMAGE frames[FRAME_COUNT];
int main()
{
	srand((unsigned)time(NULL));
	initgraph(1706,1279);
	IMAGE img;
	MOUSEMSG m;
	setbkmode(TRANSPARENT);//文字透明底
	
	//主界面
	BeginBatchDraw();//双缓冲，批量绘图
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\吧台.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);

	settextcolor(WHITE);
	settextstyle(100, 0, _T("行楷"), 0, 0, 700, false, false, false);
	outtextxy(425, 120, _T("今天要喝点什么吗？"));

	float hue=0.0f;
	bool  visible=true;
	int   flashTimer=0;

	while (true)
  	{
      putimage(0, 0, 1706, 1279, &img, 0, 0);
      settextcolor(WHITE);
      settextstyle(100, 0, _T("行楷"), 0, 0, 700, false, false, false);
      outtextxy(400, 120, _T("今天要喝点什么吗？"));

      flashTimer++;
      if (flashTimer >= 24)
      {
          visible = !visible;
          flashTimer = 0;
      }
      if (visible)
      {
          COLORREF color = HSVtoRGB(hue, 1.0f, 1.0f);
          settextcolor(color);
          settextstyle(80, 0, NULL, 0, 0, 600, true, false, false);
          outtextxy(480, 820, _T("鼠标左击进入游戏"));
          hue += 2.0f;
          if (hue >= 360.0f)
              hue -= 360.0f;
      }
      FlushBatchDraw();
      Sleep(15);
      if (MouseHit()) {
          m = GetMouseMsg();
          if (m.uMsg == WM_LBUTTONDOWN)
              break;
      }
  	}
  	EndBatchDraw();

	//第二幕
	cleardevice();
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\泡芙说话.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setfillcolor(BLACK);
	fillrectangle(350,110,1500,260);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,400,false,false,false);
	outtextxy(410,150,_T("欢迎光临，看看菜单想点些什么吗"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();

	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\泡芙展示餐品02.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	Sleep(1500);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(410,150,_T("(猫老板打开了菜单展示菜品)"));
	settextstyle(60,0,_T("行楷"),0,0,500,false,false,false);
	outtextxy(540,240,_T("---点击菜单查看菜品---"));

	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if (m.x >= 568 && m.x <= 1137 && m.y >= 426 && m.y <= 1279)
			break;
		}
	}

	//菜单展示
	cleardevice();
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\泡芙菜单调整版.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setfillcolor(WHITE);
	fillrectangle(100,400,1100,1020);
	settextcolor(BLACK);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(530,420,_T("菜单"));
	settextstyle(55,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(160,530,_T("·酱煮壁虎尾     ·麻雀刺身拼盘"));
	outtextxy(160,630,_T("·飞蛾刺身寿司   ·老鼠碎肉盖饭"));
	outtextxy(160,730,_T("·蟑螂刺身寿司   ·马陆卷刺身卷"));
	outtextxy(160,830,_T("·苍蝇刺身拉面   ·蚯蚓炒乌冬面"));
	outtextxy(160,930,_T("·蜘蛛细丝拉面   ·烧酒"));
	
	setfillcolor(BLACK);
	fillrectangle(400,90,1510,380);
	settextcolor(WHITE);
	settextstyle(60,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(410,110,_T("我们店的食材都是新鲜现杀的哦，有超级"));
	outtextxy(410,175,_T("无敌爆炸美味的飞蛾刺身寿司和蟑螂刺身"));
	outtextxy(410,240,_T("寿司、好吃到连盘子都想啃一口的麻雀刺"));
	outtextxy(410,305,_T("身拼盘......"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	//泡芙嘴馋
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\嘴馋泡芙菜单02调整版.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setfillcolor(WHITE);
	fillrectangle(100,400,1100,1020);
	settextcolor(BLACK);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(530,420,_T("菜单"));
	settextstyle(55,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(160,530,_T("·酱煮壁虎尾     ·麻雀刺身拼盘"));
	outtextxy(160,630,_T("·飞蛾刺身寿司   ·老鼠碎肉盖饭"));
	outtextxy(160,730,_T("·蟑螂刺身寿司   ·马陆卷刺身卷"));
	outtextxy(160,830,_T("·苍蝇刺身拉面   ·蚯蚓炒乌冬面"));
	outtextxy(160,930,_T("·蜘蛛细丝拉面   ·烧酒"));
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(410,10,_T("(你清楚地看到猫老板馋得咽口水)"));
	
	setfillcolor(BLACK);
	fillrectangle(400,90,1510,380);
	settextcolor(WHITE);
	settextstyle(60,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(410,110,_T("我们店的食材都是新鲜现杀的哦，有超级"));
	outtextxy(410,175,_T("无敌爆炸美味的飞蛾刺身寿司和蟑螂刺身"));
	outtextxy(410,240,_T("寿司、好吃到连盘子都想啃一口的麻雀刺"));
	outtextxy(410,305,_T("身拼盘......"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	//
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\泡芙菜单调整版.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setfillcolor(WHITE);
	fillrectangle(100,400,1100,1020);
	settextcolor(BLACK);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(530,420,_T("菜单"));
	settextstyle(55,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(160,530,_T("·酱煮壁虎尾     ·蜈蚣刺身卷"));
	outtextxy(160,630,_T("·飞蛾刺身寿司   ·老鼠碎肉盖饭"));
	outtextxy(160,730,_T("·蟑螂刺身寿司   ·麻雀刺身拼盘"));
	outtextxy(160,830,_T("·苍蝇刺身拉面   ·蚯蚓炒乌冬面"));
	outtextxy(160,930,_T("·蜘蛛细丝拉面   ·烧酒"));
	setfillcolor(BLACK);
	fillrectangle(400,210,1510,300);
	settextcolor(WHITE);
	settextstyle(60,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(410,230,_T("......哦，当然还有平平无奇的烧酒。"));
	Sleep(1500);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(380,20,_T("(看了一圈猫老板极力推荐的菜品)"));
	outtextxy(410,110,_T("(你决定要一壶平平无奇的烧酒)"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\泡芙做饭.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(570,150,_T("---美味制作中---"));
	Sleep(3000);
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\烧酒.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	outtextxy(570,150,_T("(你的烧酒做好了)"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();

	//喝酒闲聊
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\烧酒.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
//outtextxy(450,30,_T("(你举起酒杯品尝了一口)"));
	outtextxy(430,150,_T("(你举起酒杯品尝了一口)"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();

	//时间大法
	BeginBatchDraw();
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\吧台.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(200,60,_T("(一口下去，恍惚中你感觉时间好像过了很久)"));
	outtextxy(250,150,_T("(可是定睛一看发现时钟才转过去一分钟)"));

	int i=0,iColor=BLUE,iBkColor=WHITE,x0,y0,x,y,iTime=500;
	int iSecongLength=iRadius*0.85,iMinuteLength=iRadius*0.75,iHourLength=iRadius*0.6;
	int T_Second,T_Minute,T_Hour;      //读取: 时、分、秒
	double a_Hour, a_Minute, a_Second; // 时、分、秒针的弧度值
	int x_Hour, y_Hour, x_Minute, y_Minute, x_Second, y_Second;	// 时、分、秒针的位置
	SYSTEMTIME sTime;
	setcolor(iColor);
	x0=getwidth()/2;y0=getheight()/2-100;
	int h,t,s;
    bool speed_mode = true;
    int speed_step = 300;
    int total_add = 0;
    const int twelve_hour_sec = 12*3600;

    GetLocalTime(&sTime);
    h = sTime.wHour;
    t = sTime.wMinute;
    s = sTime.wSecond;

    while(true)
    {
        if(MouseHit())
        {
            m = GetMouseMsg();
            if(m.uMsg == WM_LBUTTONDOWN) break;
        }

        putimage(0, 0, 1706, 1279, &img, 0, 0);
        settextcolor(WHITE);
		settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
		outtextxy(200,60,_T("(一口下去，恍惚中你感觉时间好像过了很久)"));
		outtextxy(250,150,_T("(可是定睛一看发现时钟才转过去一分钟)"));


        setfillcolor(WHITE);
        solidcircle(x0,y0,iRadius);

        setcolor(BLUE);
        circle(x0, y0, iRadius);
        iColor=GREEN;
        setfillcolor(iColor);
        for (i=0; i<60; i++){
            x = x0 + int(iRadius*0.9*sin(PI*2*i/60));
            y = y0 + int(iRadius*0.9*cos(PI*2*i/60));
            if (i%15==0)		rectangle(x-3,y-3,x+3,y+3);
            else if (i%5==0)	circle(x,y,2);
            else				solidcircle(x,y,1);
        }
        setlinestyle(PS_SOLID,3);

        if(speed_mode && total_add < twelve_hour_sec)
        {
            s += speed_step;
            total_add += speed_step;
            while(s >= 60) { s -= 60; t++; }
            while(t >= 60) { t -= 60; h++; }
            h %= 24;
            iTime = 10;
        }
        else
        {
            speed_mode = false;
            GetLocalTime(&sTime);
            h = sTime.wHour;
            t = sTime.wMinute;
            s = sTime.wSecond;
            iTime = 500;
        }
        T_Hour = h;
        T_Minute = t;
        T_Second = s;

        a_Second=T_Second*2*PI/60;
        a_Minute=T_Minute*2*PI/60 + a_Second/60;
        a_Hour=T_Hour*2*PI/12 + a_Minute/12;
        x_Second=int(iSecongLength*sin(a_Second));
        y_Second=int(iSecongLength*cos(a_Second));
        x_Minute=int(iMinuteLength*sin(a_Minute));
        y_Minute=int(iMinuteLength*cos(a_Minute));
        x_Hour=int(iHourLength*sin(a_Hour));
        y_Hour=int(iHourLength*cos(a_Hour));
        setlinecolor(RED);
        line(x0 + x_Second, y0 -y_Second,x0 - x_Second/5, y0+y_Second/5 );
        setlinecolor(BLUE);
        line(x0 + x_Minute, y0 -y_Minute,x0 - x_Minute/5, y0+y_Minute/5 );
        setlinecolor(GREEN);
        line(x0 + x_Hour, y0 -y_Hour,x0 - x_Hour/5, y0+y_Hour/5 );
        setfillcolor(RED);
        solidcircle(x0, y0, 5);
        
        FlushBatchDraw();
        Sleep(iTime);
	}
	EndBatchDraw();
	
	//发现异常
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\烧酒.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(375,0,_T("(你在不经意间将视线转向窗外)"));
	Sleep(2000);
	outtextxy(220,75,_T("(现在是晚上，可外面的光线却异常明亮)"));
	Sleep(2000);
	outtextxy(500,150,_T("(你开始隐隐感到奇怪)"));
	Sleep(2000);
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();

	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\喝酒泡芙说话.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(350,110,1500,260);
	settextcolor(WHITE);
	settextstyle(60,0,_T("行楷"),0,0,400,false,false,false);
	outtextxy(380,150,_T("味道不错吧！这可是我的手艺..."));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(410,20,_T("(猫老板还在絮絮叨叨说着什么)"));
	
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	//海盗泡芙
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\喝酒泡芙说话.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setlinecolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(350,110,1500,260);
	settextcolor(WHITE);
	settextstyle(60,0,_T("行楷"),0,0,400,false,false,false);
	outtextxy(380,150,_T("味道不错吧！这可是我的手艺..."));
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(350,20,_T("(你在恍惚和不安中已经无心去听了)"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\烧酒.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(365,75,_T("(一阵轻微的磕碰感从脚尖传来)"));
	Sleep(2000);
	outtextxy(330,150,_T("(你意识到刚才不小心踢到了什么)"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\地板上相框调整版.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	Sleep(2000);
	outtextxy(350,75,_T("(低头一看发现是一个倒扣着的相框)"));
	Sleep(2000);
	outtextxy(490,170,_T("(你好奇地把相框拾了起来)"));
	settextstyle(70,0,_T("行楷"),0,0,500,false,false,false);
	outtextxy(545,280,_T("---点击相框拾取---"));

	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			if (m.x >= 568 && m.x <= 1137 && m.y >= 426 && m.y <= 1279)
			break;
		}
	}
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\海盗泡芙04.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	
	//发现异常
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\烧酒相框.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	setfillcolor(BLACK);
	fillrectangle(130,10,1520,110);
	settextcolor(RED);
	settextstyle(70,0,_T("行楷"),0,0,700,false,false,false);
	outtextxy(180,30,_T("猫老板的真实身份竟然是臭名昭著的海盗！"));
	settextcolor(WHITE);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(120,130,_T("(你想到刚才喝了猫老板做的酒更是无比害怕)"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\惊恐泡芙02.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(100,20,_T("(猫老板发现了你手里拿着的相框，表情变得惊恐)"));
	setfillcolor(BLACK);
	fillrectangle(350,110,1500,260);
	settextstyle(60,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(380,150,_T("......"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\阴沉泡芙02.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(480,20,_T("(猫老板脸色阴沉了下来)"));
	setfillcolor(BLACK);
	fillrectangle(350,110,1550,260);
	settextstyle(60,0,_T("行楷"),0,0,600,false,false,false);
	outtextxy(360,150,_T("......既然你都看到了...那便留不得你了！"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	

	//被打晕了
	BeginBatchDraw();
	
	IMAGE img_bg;
    IMAGE img_puff;
    loadimage(&img_bg, _T("E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\吧台.jpg"), 1706, 1279, true);

    int ibKcolor = BLACK,iAdd = 6;
	iTime = 80;
	x0 = getwidth() / 2;
    y0 = getheight() / 2;
    setbkcolor(ibKcolor);

    for (i = 1; i <= 100; i++)
    {
        cleardevice();
        putimage(0, 0, &img_bg);
        loadimage(&img_puff, _T("E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\泡芙拿锤子.png"), iAdd * i, iAdd * i, true);
        putimage(x0 - (iAdd * i)/2, y0 - (iAdd * i)/2-110, &img_puff);
        settextcolor(WHITE);
		settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
		outtextxy(370,150,_T("(猫老板拿着锤子向你冲了过来)"));

        FlushBatchDraw();
        Sleep(iTime);
    }
    EndBatchDraw();
    
	//
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\打晕02调整版.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	loadimage(&img,"E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\打晕01.jpg");
	putimage(0, 0, 1706, 1279, &img, 0, 0);
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	
	//眨眼
	char filename[128];
  	for (int i = 0; i < FRAME_COUNT; i++)
  	{
      	snprintf(filename, sizeof(filename),
        "E:\\SchoolCourseCode\\EasyXCourseDesign\\PictureMaterial\\Blink\\%02d.jpg", i+1);
      	loadimage(&frames[i], filename, 1706, 1279);
  	}

  	for (int i = 0; i < FRAME_COUNT; i++)
  	{
      	cleardevice();
      	putimage(0, 0, &frames[i]);
      	settextcolor(WHITE);
		settextstyle(70,0,_T("行楷"),0,0,600,false,false,false);
		outtextxy(50,150,_T("(你最后一眼朦朦胧胧看到猫老板狞笑着收起了菜单)"));
      	Sleep(100);
  	}
	
	setbkcolor(BLACK);
	cleardevice();
	settextcolor(RED);
	settextstyle(150,0,_T("行楷"),0,0,700,false,false,false);
	outtextxy(480,400,_T("你被打晕了"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	
	cleardevice();
	settextcolor(WHITE);
	settextstyle(60,0,_T("行楷"),0,0,600,false,false,false);
	/*
	outtextxy(180,130,_T("......"));
	outtextxy(180,280,_T("你醒来时发现自己躺在一个偏僻的巷子里"));
	outtextxy(180,430,_T("身上的所有值钱东西都被搜刮走了"));
	outtextxy(180,580,_T("海盗猫老板自然是跑得无影无踪"));
	outtextxy(180,730,_T("奇怪的是那间居酒屋也像是凭空消失了一般"));
	*/
	outtextxy(730,130,_T("......"));
	outtextxy(320,280,_T("你醒来时发现自己躺在一个偏僻的巷子里"));
	outtextxy(400,430,_T("身上的所有值钱东西都被搜刮走了"));
	outtextxy(400,580,_T("海盗猫老板自然是跑得无影无踪"));
	outtextxy(280,730,_T("奇怪的是那间居酒屋也像是凭空消失了一般"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	cleardevice();
	
	settextcolor(WHITE);
	settextstyle(90,0,_T("行楷"),0,0,700,false,false,false);
	outtextxy(450,360,_T("—— THE END ——"));
	outtextxy(640,560,_T("感谢游玩！"));
	while(true)
	{
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
			break;
	}
	closegraph();
	return 0;
}