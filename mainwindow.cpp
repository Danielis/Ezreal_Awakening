#include "mainwindow.h"
#include <iostream>
/** Default constructor */
MainWindow::MainWindow() : QWidget()
{
	/** constructor() that has in input file for scores */
	ifstream fin;
	fin.open("scores.txt");
	if(fin.fail())
	{
		cout << "Could not find the scores file" << endl;
	}
	else
	{
	  string temp;
	  int temp2;
	  getline(fin,temp,'|');
	  fin >> temp2;
		while(fin.good())
		{
			scorenames.push_back(temp);
			scores.push_back(temp2);
			getline(fin,temp,'|');
			fin >> temp2;
		}
	}
	  
	/** Set the Pixmaps */
	ez=new QPixmap("ezreal.png");
		*ez=ez->scaled(75,75,Qt::KeepAspectRatioByExpanding);
	melee=new QPixmap("meleeminion.png");
		*melee=melee->scaled(50,50,Qt::KeepAspectRatioByExpanding);
	caster=new QPixmap("casterminion.png");
		*caster=caster->scaled(45,45,Qt::KeepAspectRatioByExpanding);
	siege=new QPixmap("siegeminion.png");
		*siege=siege->scaled(65,65,Qt::KeepAspectRatioByExpanding);
	basic=new QPixmap("basicattack.gif");
		*basic=basic->scaled(10,10,Qt::KeepAspectRatioByExpanding);
	mystic=new QPixmap("basicattack.gif");
		*mystic=mystic->scaled(30,30,Qt::KeepAspectRatioByExpanding);
	trueshot=new QPixmap("trueshot.png");
		*trueshot=trueshot->scaled(75,75,Qt::KeepAspectRatioByExpanding);
	heal=new QPixmap("heal.png");
		*heal=heal->scaled(50,50,Qt::KeepAspectRatioByExpanding);
	clarity=new QPixmap("clarity.png");
		*clarity=clarity->scaled(50,50,Qt::KeepAspectRatioByExpanding);
	ignite=new QPixmap("ignite.png");
		*ignite=ignite->scaled(50,50,Qt::KeepAspectRatioByExpanding);
	energy=new QPixmap("energybolt.gif");
		*energy=energy->scaled(50,50,Qt::KeepAspectRatioByExpanding);
	cannon=new QPixmap("cannonshot.png");
		*cannon=cannon->scaled(55,55,Qt::KeepAspectRatioByExpanding);
	/** color is the default color set for spacers and background of widgets*/
	color.setRgb(240,240,240,255);
	/** MainWidget which holds everything */
	mainwidget= new QWidget;
	mainwidget->setFixedSize(1200,800);
	/** Main Layout for MainWindow */
	mainLayout = new QVBoxLayout;
	mainwidget->setLayout(mainLayout);
	  /** TITLE above row1*/
	  row0 = new QHBoxLayout;
	  	/** IconObject used to display QPixmap */
	    	hold_spacer0 = new IconObject;
	  	/** Used to hold a space */
	  	spacer0 = new QPixmap(100,64);
	  	spacer0->fill(color);
	  	/** IconObject used to display QPixmap */
	    	hold_title = new IconObject;
	    	/** Ability display icon */
	  	title = new QPixmap("title.png");
	  	/** IconObject used to display QPixmap */
	    	hold_spacer01 = new IconObject;
	  	/** Used to hold a space */
	  	spacer01 = new QPixmap(100,64);
	  	spacer01->fill(color);
	  	// set pixmaps
	  	hold_spacer0->setPixmap(*spacer0);
	  	hold_title->setPixmap(title->scaled(700,40,Qt::KeepAspectRatioByExpanding));
	  	hold_spacer0->setPixmap(*spacer01);
	  	//add to layout row0
	  	row0->addWidget(hold_spacer0);
	  	row0->addWidget(hold_title);
	  	row0->addWidget(hold_spacer01);
	  	mainLayout->addLayout(row0);
	  /** Horizontal box for row 1*/
	  row1= new QHBoxLayout;
	  	/** Button which initiates/restarts game*/
		start= new QPushButton("Start");
		/** Button which pauses/continues game*/
		pause = new QPushButton("Pause");
		/** quits the game*/
		quit = new QPushButton("Quit");
		/** Score display*/
		name = new QTextEdit("Name");
		name->setMaximumHeight(30);
		name->setMaximumWidth(200);
		/** level display*/
		level = new QLabel("LEVEL: 00");
		/** score display*/
		score = new QLabel("SCORE: 00");
	    row1->addWidget(start);
	    row1->addWidget(pause);
	    row1->addWidget(quit);
	    row1->addWidget(name);
	    row1->addWidget(level);
	    row1->addWidget(score);
	    mainLayout->addLayout(row1);
	  /** Horizontal box for row 2*/
	  row2 = new QHBoxLayout;
	  	/** Scene which holds monsters, player and powerups*/
	  	scene = new QGraphicsScene;
	  	/** View which holds gameplay*/
	  	view = new GameWindow(scene);
	    row2->addWidget(view);
	    mainLayout->addLayout(row2);
	  /** Horizontal box for row 3*/
	  row3 = new QHBoxLayout;
	    //left
	    	/** IconObject used to display QPixmap */
	    	hold_basicattackicon = new IconObject;
	    	/** Ability display icon */
	  	basicattackicon = new QPixmap("basicattack.gif");
	  	/** IconObject used to display QPixmap */
	    	hold_mysticshoticon = new IconObject;
	  	/** Ability display icon */
	  	mysticshoticon = new QPixmap("basicattack.gif");
	  	//mysticshoticon->scaledToHeight(64,Qt::FastTransformation);
	  	/** IconObject used to display QPixmap */
	    	hold_trueshoticon = new IconObject;
	  	/** Ability display icon */
	  	trueshoticon = new QPixmap("trueshot.png");
	  	/** IconObject used to display QPixmap */
	    	hold_spacer1 = new IconObject;
	  	/** Used to hold a space */
	  	spacer1 = new QPixmap(400,64);
	  	spacer1->fill(color);
	    //midleft
	    	/** IconObject used to display QPixmap */
	    	hold_heart = new IconObject;
	    	/** Heart Icon */
	    	heart = new QPixmap("heart.gif");
	    	/** Health display */
	    	health = new QLabel("200");
	    	health->setMaximumHeight(25);
	    	/** IconObject used to display QPixmap */
	    	hold_spacer2 = new IconObject;
	    	/** Used to hold a space */
	  	spacer2 = new QPixmap(64,64);
	  	spacer2->fill(color);
	    //midright
	    	/** IconObject used to display QPixmap */
	    	hold_potion = new IconObject;
	    	/** Mana Icon */
	    	potion = new QPixmap("mana.gif");
	    	/** Mana display */
	    	mana= new QLabel("50");
	    	mana->setMaximumHeight(25);
	    	
	    /*Add the Pixmaps to the IconObjects*/
	    hold_basicattackicon->setPixmap(basicattackicon->scaledToHeight(10));
	    hold_mysticshoticon->setPixmap(mysticshoticon->scaledToHeight(20));
	    hold_trueshoticon->setPixmap(trueshoticon->scaled(40,60,Qt::KeepAspectRatioByExpanding));
	    hold_spacer1->setPixmap(*spacer1);
	    hold_heart->setPixmap(*heart);
	    hold_spacer2->setPixmap(*spacer2);
	    hold_potion->setPixmap(*potion);
	    /* Add IconObjects to row3 */
	    row3->addWidget(hold_basicattackicon);
	    row3->addWidget(hold_mysticshoticon);
	    row3->addWidget(hold_trueshoticon);
	    row3->addWidget(hold_spacer1);
	    row3->addWidget(hold_heart);
	    row3->addWidget(health);
	    row3->addWidget(hold_spacer2);
	    row3->addWidget(hold_potion);
	    row3->addWidget(mana);
	    /* Add layout to main widget*/
	    mainLayout->addLayout(row3);
	    
	// set player
	  //objects.push_back(
	//set bool variables
	trueshotfiring = false;
	inGame = false;
	gamePaused = false;
	playerAlive = false;
	up = false;
	down = false;
	left = false;
	right = false;
	grabbedignite=false;
	lostgame=false;
	//set counters
	/** Level identifies which level the game is at */
	levelff=1;
	/** Leftclickcounter determines how many times left click is pressed */
	leftclickcounter=0;
	/** Leftclickholdcounter determines how long left click is pressed */
	leftclickholdcounter=0;
	/** Spawn counter for a meleeminoin */
	spawnmelee=0;
	/** Spawn counter for a Siegeminion*/
	spawnsiege=0;	
	/** Spawn counter for a Casterminion*/
	spawncaster=0;
	/** Ez can not be hurt immediately at next clock 
	  *giving the player time to move out of the way*/
	ezhurt=0;
	/** Points scored*/
	points=0;
	/** Icon spawning at 200*/
	iconspawn=0;
	
	// set timer
	timer = new QTimer(this);// timer->start(val) later on in show()
	//connections
	connect(start,SIGNAL(clicked()),this,SLOT(clickedStart()));
	connect(pause,SIGNAL(clicked()),this,SLOT(clickedPause()));
	connect(view,SIGNAL(leftButtonClicked()),this,SLOT(leftClick()));
	connect(view,SIGNAL(rightButtonClicked()),this,SLOT(rightClick()));
	connect(view,SIGNAL(leftButtonHoldStart()),this,SLOT(leftHoldstart()));
	connect(view,SIGNAL(leftButtonHoldCancel()),this,SLOT(leftHoldcancel()));
	connect(view,SIGNAL(uparrow()),this,SLOT(moveup()));
	connect(view,SIGNAL(downarrow()),this,SLOT(movedown()));
	connect(view,SIGNAL(leftarrow()),this,SLOT(moveleft()));
	connect(view,SIGNAL(rightarrow()),this,SLOT(moveright()));
	connect(timer,SIGNAL(timeout()),this,SLOT(handleTimer()));
	connect(quit,SIGNAL(clicked()),this,SLOT(clickedQuit()));
}

/** Default destructor */
MainWindow::~MainWindow()
{
	/** MainWidget which holds everything */
	delete mainwidget;
	/** Main Layout for MainWindow */
	delete mainLayout;
	  /** TITLE above row1*/
	  delete row0;
	  	/** IconObject used to display QPixmap */
	    	delete hold_spacer0;
	  	/** Used to hold a space */
	  	delete spacer0;
	  	/** IconObject used to display QPixmap */
	    	delete hold_title;
	    	/** Ability display icon */
	  	delete title;
	  	/** IconObject used to display QPixmap */
	    	delete hold_spacer01;
	  	/** Used to hold a space */
	  	delete spacer01;
	  /** Horizontal box for row 1*/
	  delete row1;
	  	/** Button which initiates/restarts game*/
		delete start;
		/** Button which pauses/continues game*/
		delete pause;
		/** Score display*/
		delete score;
	  /** Horizontal box for row 2*/
	  delete row2;
	  	/** View which holds gameplay*/
	  	delete view;
	  	/** Scene which holds monsters, player and powerups*/
	  	delete scene;
	  /** Horizontal box for row 3*/
	  delete row3;
	    //left
	    	/** IconObject used to display QPixmap */
	    	delete hold_basicattackicon;
	    	/** Ability display icon */
	  	delete basicattackicon;
	  	/** IconObject used to display QPixmap */
	    	delete hold_mysticshoticon;
	  	/** Ability display icon */
	  	delete mysticshoticon;
	  	/** IconObject used to display QPixmap */
	    	delete hold_trueshoticon;
	  	/** Ability display icon */
	  	delete trueshoticon;
	  	/** IconObject used to display QPixmap */
	    	delete hold_spacer1;
	  	/** Used to hold a space */
	  	delete spacer1;
	    //midleft
	    	/** IconObject used to display QPixmap */
	    	delete hold_heart;
	    	/** Heart Icon */
	    	delete heart;
	    	/** Health display */
	    	delete health;
	    	/** IconObject used to display QPixmap */
	    	delete hold_spacer2;
	    	/** Used to hold a space */
	  	delete spacer2;
	    //midright
	    	/** IconObject used to display QPixmap */
	    	delete hold_potion;
	    	/** Mana Icon */
	    	delete potion;
	    	/** Mana display */
	    	delete mana;
	delete timer;
}
void MainWindow::show()
{
	mainwidget->show();
}
//SLOTS//////////////////////////////////////////////////////////////////////////////////
/** clickedStart() will begin the game and reset it after it has started if clicked again*/
void MainWindow::clickedStart()
{
  /*if(lostgame)
  {
   	if(!(scene->items().empty()))
  	{
  		for(int i=0;i<objects.size();i++)
		{
			died(objects[i]);
		}
	}
	timer->stop();
	timer->start(50);
	int ezx,ezy;
	ezx=1155-75;ezy=555-75;
	objects.push_back(new Ezreal(*ez,ezx,ezy,200,50));
	objects.last()->setPos(ezx,ezy);
	scene->addItem(objects.last());
	playerAlive=true;
	inGame=true;
 	
  }*/	
  if(!inGame && name->toPlainText()!= "Name")
  {
  	enteredName=name->toPlainText();
	timer->start(75);
	// Scene and View dimensions
	view->setBackgroundBrush(Qt::green);
	view->setFixedSize(1155,555);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setFocus();
	scene->setSceneRect(0,0,1155,555);
	
	int ezx,ezy;
	ezx=75/2;//1155-75; changed starting position
	ezy=75/2;//555-75; changed starting position
	objects.push_back(new Ezreal(*ez,ezx,ezy,200,50));
	objects.last()->setPos(ezx,ezy);
	scene->addItem(objects.last());
	playerAlive=true;
	inGame=true;
  }
}
/** clickedPause() will pause the game or continue gameplay */
void MainWindow::clickedPause()
{
	gamePaused=!gamePaused;
	view->setFocus();
}
/** clickedquit() that will quit the game */
void MainWindow::clickedQuit()
{
	//cout << "Clicked QUIT" << endl;
	exit(1);
}
/** rightClick() will flash the player to the correct place */
void MainWindow::rightClick()
{
  if(inGame && !gamePaused && playerAlive)
  {
	//cout << view->getpoint().rx() << "  " << view->getpoint().ry() << endl;
	objects.first()->movetile(view->getpoint());
	//cout << objects.first()->getX() << "  " <<objects.first()->getY() << endl;
  }
}
/** leftClick() will fire certain player abilities */
void MainWindow::leftClick()
{
	leftclickcounter++;
	if(leftclickcounter%5==0)
	{
		leftclickcounter=0;
		objects.push_back(new MysticShot(*mystic,objects.first()->getX(),objects.first()->getY(),1,0,view->getpoint().rx(),view->getpoint().ry()));
			objects.last()->setPos(objects.first()->getX(),objects.first()->getY());
			scene->addItem(objects.last());
		dispmana=numtostr(objects.first()->getMana());
		mana->setText(dispmana);
	}
	else
	{
		objects.push_back(new BasicAttack(*basic,objects.first()->getX(),objects.first()->getY(),1,0,view->getpoint().rx(),view->getpoint().ry()));
			objects.last()->setPos(objects.first()->getX(),objects.first()->getY());
			scene->addItem(objects.last());
		dispmana=numtostr(objects.first()->getMana());
		mana->setText(dispmana);
	}
}
/** lefthold() will fire the ult attack */
void MainWindow::leftHoldstart()
{
	//std::cout << "Held left start" << std::endl;
	trueshotfiring=true;
}
/** lefthold() will fire the ult attack */
void MainWindow::leftHoldcancel()
{
	//std::cout << "Held left cancel" << std::endl;
	trueshotfiring=false;
	leftclickholdcounter=0;
}
/** handleTimer() reacts to the signal sent off by the timer*/
void MainWindow::handleTimer()
{
  if(inGame && !gamePaused && playerAlive)
  {
/*TRUESHOT*/
	if(trueshotfiring)
	{
		leftclickholdcounter++;
		if(leftclickholdcounter%25==0){
			objects.push_back(new TrueShot(*trueshot,objects.first()->getX(),objects.first()->getY(),1000,0,view->getpoint().rx(),view->getpoint().ry()));
			objects.last()->setPos(objects.first()->getX(),objects.first()->getY());
			scene->addItem(objects.last());
			dispmana=numtostr(objects.first()->getMana());
			mana->setText(dispmana);
			trueshotfiring=false;
			leftclickholdcounter=0;
		}
	}
/* MOVING EZ*/
	if(up)
	{
		objects.first()->movetile(objects.first()->getX(),objects.first()->getY()-20);
	}
	else if(down)
	{
		objects.first()->movetile(objects.first()->getX(),objects.first()->getY()+20);
	}
	if(left)
	{
		objects.first()->movetile(objects.first()->getX()-20,objects.first()->getY());
	}
	else if(right)
	{
		objects.first()->movetile(objects.first()->getX()+20,objects.first()->getY());
	}
/* Spawn Icon*/
	iconspawn++;
	if(iconspawn%200==0)
	{
		int temp=rand()%3;
		if(temp==0)
		{
			int objectx,objecty;
			objectx=rand()%1175;objecty=rand()%575;
			objects.push_back(new Heal(*heal,objectx,objecty,1,0));
			objects.last()->setPos(objectx,objecty);
			scene->addItem(objects.last());
			iconspawn=0;
		}
		else if(temp==1)
		{
			int objectx,objecty;
			objectx=rand()%1175;objecty=rand()%575;
			objects.push_back(new Clarity(*clarity,objectx,objecty,1,0));
			objects.last()->setPos(objectx,objecty);
			scene->addItem(objects.last());
			iconspawn=0;
		}
		else if(temp==2)
		{
			int objectx,objecty;
			objectx=rand()%1175;objecty=rand()%575;
			objects.push_back(new Ignite(*ignite,objectx,objecty,1,0));
			objects.last()->setPos(objectx,objecty);
			scene->addItem(objects.last());
			iconspawn=0;
		}
	}
/* Spawning melee*/
	spawnmelee++;
	if(spawnmelee%50==0)
	{
		int objectx,objecty;
		objectx=rand()%1175;objecty=rand()%575;
		objects.push_back(new MeleeMinion(*melee,objectx,objecty,75,50));
		objects.last()->setPos(objectx,objecty);
		scene->addItem(objects.last());
		spawnmelee=0;
	}
	for( int i=0;i<objects.size();i++)
	{
		if(objects[i]->getType()==8)
			objects[i]->movetile();
	}
/* Spawning Siege*/
	spawnsiege++;
	if(spawnsiege%700==0)
	{
		int objectx,objecty;
		objectx=rand()%1175;objecty=rand()%575;
		objects.push_back(new SiegeMinion(*siege,objectx,objecty,150,0));
		objects.last()->setPos(objectx,objecty);
		scene->addItem(objects.last());
		spawnsiege=0;
	}
	for( int i=0;i<objects.size();i++)
	{
		if(objects[i]->getType()==10)
		{
			objects[i]->movetile(objects.first()->getX(),objects.first()->getY());
		/*Can he shoot*/
			int curplayx=sqrt(pow(objects.first()->getX()+75/2,2));
			int curplayy=sqrt(pow(objects.first()->getY()+75/2+25,2));
			int curx=sqrt(pow(objects[i]->getX()+65/2,2));
			int cury=sqrt(pow(objects[i]->getY()+65/2,2));
			if(120 >= sqrt(pow((curplayx-curx),2) + pow((curplayy-cury),2)))
			{
				countcannon++;
				if(countcannon%10==0)
				{
				objects.push_back(new CannonShot(*cannon,objects[i]->getX(),objects[i]->getY(),1,0,objects.first()->getX(),objects.first()->getY()));
				objects.last()->setPos(objects.first()->getX(),objects.first()->getY());
				scene->addItem(objects.last());
				}
			}
		}
	}
/* Spawning caster*/
	spawncaster++;
	if(spawncaster%500==0)
	{
		int objectx,objecty;
		objectx=rand()%1175;objecty=rand()%575;
		objects.push_back(new CasterMinion(*caster,objectx,objecty,50,0));
		objects.last()->setPos(objectx,objecty);
		scene->addItem(objects.last());
		spawncaster=0;
	}
	for( int i=0;i<objects.size();i++)
	{
		if(objects[i]->getType()==2)
		{
			objects[i]->movetile(objects.first()->getX(),objects.first()->getY());
		/*Can he shoot*/
			int curplayx=sqrt(pow(objects.first()->getX()+75/2,2));
			int curplayy=sqrt(pow(objects.first()->getY()+75/2+25,2));
			int curx=sqrt(pow(objects[i]->getX()+65/2,2));
			int cury=sqrt(pow(objects[i]->getY()+65/2,2));
			if(120 >= sqrt(pow((curplayx-curx),2) + pow((curplayy-cury),2)))
			{
				countbolt++;
				if(countbolt%10==0)
				{
				objects.push_back(new EnergyBolt(*energy,objects[i]->getX(),objects[i]->getY(),1,0,objects.first()->getX(),objects.first()->getY()));
				objects.last()->setPos(objects.last()->getX(),objects.last()->getY());
				scene->addItem(objects.last());
				}
			}
		}
	}
/* Move all shots */
	for( int i=0;i<objects.size();i++)
	{
		if(objects[i]->getType()== 0 || objects[i]->getType()== 1 ||objects[i]->getType()== 4 ||objects[i]->getType()== 9 ||objects[i]->getType()== 11)
		{
				objects[i]->movetile();
		}
	}
/* Removes cases for the shots*/
	for( int i=0;i<objects.size();i++)
	{
		if(objects[i]->getType()== 0 || objects[i]->getType()== 1 ||objects[i]->getType()== 4 ||objects[i]->getType()== 9 ||objects[i]->getType()== 11)
		{
			if(objects[i]->getHealth()<=0 || objects[i]->isGone())
				died(objects[i]);
		}
	}
/* Check for collision and do damage*/
	for( int i=0;i<objects.size();i++)
	{
		SceneObject* itemA=objects[i];
		for(int j=0;j<objects.size();j++)
		{
			SceneObject* itemB=objects[j];
			if(i==j)
				continue;
			if(itemA->collidesWithItem(itemB))
			{
				// ezreal hits a monster or attack
				if(itemA->getType()==5 && (itemB->getType()== 1 || itemB->getType()== 2 || itemB->getType()==4 || itemB->getType()== 8 || itemB->getType()==10))
				{
					ezhurt++;
					if(ezhurt%4==0)
					{
						itemA->setHealth(itemA->getHealth()-itemB->getDamage());
						itemB->setHealth(itemB->getHealth()-itemA->getDamage());
						//cout << "Ez was hurt: " <<objects.first()->getHealth()<< endl;
						//cout << "Monster was hurt: " << itemB->getHealth() << endl;
						disphealth=numtostr(objects.first()->getHealth());
						health->setText(disphealth);
						cout << "HEALTH: " << objects.first()->getHealth() << "  MANA: " << objects.first()->getMana() << "  LEVEL: " << levelff << "  SCORE: " << points*50 << endl;
						ezhurt=0;
					}
				}
				// monsters are hit by an attack
				if((itemA->getType()==2 || itemA->getType()==8 || itemA->getType()==10) && (itemB->getType()== 0 || itemB->getType()== 9 || itemB->getType()== 11))
				{
					itemA->setHealth(itemA->getHealth()-itemB->getDamage());
				}
				// Ez's attack's hit a monster
				if((itemA->getType()==0 || itemA->getType()==9 || itemA->getType()==11) && (itemB->getType()== 2 || itemB->getType()== 8 || itemB->getType()== 10))
				{
					itemA->setHealth(itemA->getHealth()-itemB->getDamage());
				}
				// monster attack's hit ez
				if((itemA->getType()==1 || itemA->getType()==4) && (itemB->getType()== 5))
				{
					ezhurt++;
					if(ezhurt%10==0)
					{
						itemA->setHealth(itemA->getHealth()-itemB->getDamage());
						//cout << "Ez was hurt: " << objects.first()->getHealth() << endl;
						disphealth=numtostr(objects.first()->getHealth());
						health->setText(disphealth);
						cout << "HEALTH: " << objects.first()->getHealth() << "  MANA: " << objects.first()->getMana() << "  LEVEL: " << levelff << "  SCORE: " << points*50 << endl;
						ezhurt=0;
					}
				}
				// powerups touched by Ez
				if((itemA->getType()==3 || itemA->getType()==6 || itemA->getType()==7) && (itemB->getType()== 5))
				{
					itemA->setHealth(itemA->getHealth()-itemB->getDamage());
				}
				// Ez touched Heal
				if( itemA->getType()== 5 && itemB->getType()==6 )
				{
					itemA->setHealth(itemA->getHealth()+itemB->getDamage());
					itemB->setHealth(itemB->getHealth()-itemA->getDamage());
				}
				// Ez touched Clarity
				if( itemA->getType()== 5 && itemB->getType()==3 )
				{
					itemA->setMana(itemA->getMana()+itemB->getDamage());
					itemB->setHealth(itemB->getHealth()-itemA->getDamage());
				}
				// Ez touched Ignite
				if( itemA->getType()== 5 && itemB->getType()==7 )
				{
					grabbedignite=true;
				}
			}
		}
	}  
	// for loop checking if ignite was grabbed
	if(grabbedignite)
	{
		for(int i=1;i<objects.size()/4;i++)
		{
			died(objects[i]);
		}
		grabbedignite=false;
	}
	// for loop checking if anythings health is 0 or below
	for(int i=0;i<objects.size();i++)
	{
		if(objects[i]->getHealth()<=0)
		{
			if(objects[i]->getType()==5)
			{
				playerAlive=false;
				inGame=false;
				lostgame=true;
				// write out to file for score
				ofstream fout;
				fout.open("scores.txt");
				bool printscore=false;
				if(scorenames.empty())
				{
				    fout << (name->toPlainText()).toStdString() << "|" << points*50<< endl;
				}
				else
				{
					for(int i=0; i<scorenames.size();i++){
						if(scores[i]<points*50 && !printscore)
						{
							fout << (name->toPlainText()).toStdString() << "|" << points*50<< endl;
							cout << (name->toPlainText()).toStdString() << "|" << points*50<< endl;
							printscore=true;
						}
						fout << scorenames[i] << "|" << scores[i] << endl;
						cout << scorenames[i] << "|" << scores[i] << endl;
					}
				}
				fout.close();
			}
			//cout << "Someone DIED!" << endl;
			if((objects[i]->getType()==2 || objects[i]->getType()==8 || objects[i]->getType()==10) && objects[i]->getHealth()<=0)
				points++;
			if(points>20)
			{
				view->setBackgroundBrush(Qt::red);
				timer->stop();
				timer->start(20);
				levelff=4;
				level->setText("LEVEL: 0"+numtostr(levelff));
				cout << "HEALTH: " << objects.first()->getHealth() << "  MANA: " << objects.first()->getMana() << "  LEVEL: " << levelff << "  SCORE: " << points*50 << endl;
			}
			else if(points>15)
			{
				view->setBackgroundBrush(Qt::yellow);
				timer->stop();
				timer->start(30);
				levelff=3;
				level->setText("LEVEL: 0"+numtostr(levelff));
				cout << "HEALTH: " << objects.first()->getHealth() << "  MANA: " << objects.first()->getMana() << "  LEVEL: " << levelff << "  SCORE: " << points*50 << endl;
			}
			else if(points>10)
			{
				view->setBackgroundBrush(Qt::blue);
				timer->stop();
				timer->start(50);
				levelff=2;
				level->setText("LEVEL: 0"+numtostr(levelff));
				cout << "HEALTH: " << objects.first()->getHealth() << "  MANA: " << objects.first()->getMana() << "  LEVEL: " << levelff << "  SCORE: " << points*50 << endl;
			}
			QString temp("SCORE: "+numtostr(points*50));
			score->setText(temp);
			score->show();
			cout << "HEALTH: " << objects.first()->getHealth() << "  MANA: " << objects.first()->getMana() << "  LEVEL: " << levelff << "  SCORE: " << points*50 << endl;
			died(objects[i]);
		}
	}
	update();
  }
}
/** Handles a key press event */
void MainWindow::moveup()
{
 	up=!up;
}
/** Handles a key press event */
void MainWindow::movedown()
{
 	down=!down;
}
/** Handles a key press event */
void MainWindow::moveleft()
{
  	left=!left;
}
/** Handles a key press event */
void MainWindow::moveright()
{
  	right=!right;
}
/** Removes Item from list and scene */
void MainWindow::died(SceneObject* dead)
{
  	scene->removeItem(dead);
  	if((objects.removeOne(dead)))
  		//cout << "Removed: " << dead << endl;
  	delete dead;
  	
}
/** Converts number of type int to string*/
QString MainWindow::numtostr(int num){
	std::stringstream ss; // convert into q string
    	ss << num;
    	std::string temp;
    	temp = ss.str();
    	QString qtemp;
    	qtemp.fromStdString(temp);
    	return qtemp;
}




