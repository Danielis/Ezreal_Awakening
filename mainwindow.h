#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QColor>
#include <QString>
#include <QList>
#include <QPainter>
#include <fstream> 
#include <cmath>
#include <sstream>
#include "gamewindow.h"
#include "iconobject.h"
#include "sceneobject.h"
#include "ezreal.h"
#include "meleeminion.h"
#include "casterminion.h"
#include "siegeminion.h"
#include "basicattack.h"
#include "mysticshot.h"
#include "trueshot.h"
#include "energybolt.h"
#include "cannonshot.h"
#include "heal.h"
#include "clarity.h"
#include "ignite.h"


using namespace std;
/** MainWindow holds all widgets and contains needed signals and members*/

class MainWindow : public QWidget{
	Q_OBJECT
public:
	/** Default constructor */
	MainWindow();
	/** Default destructor */
	~MainWindow();
	void show();

public slots:
	/** clickedStart() will begin the game and reset it after it has started if clicked again*/
	void clickedStart();
	/** clickedPause() will pause the game or continue gameplay */
	void clickedPause();
	/** clickedQuit() will quit the game */
	void clickedQuit();
	/** leftClick() will fire certain player abilities */
	void rightClick();
	/** leftClick() will fire certain player abilities */
	void leftClick();
	/** lefthold() will fire the ult attack */
	void leftHoldstart();
	/** lefthold() will fire the ult attack */
	void leftHoldcancel();
	/** handleTimer() reacts to the signal sent off by the timer*/
	void handleTimer();
	/** Handles a key press event */
	void moveup();
	/** Handles a key press event */
	void movedown();
	/** Handles a key press event */
	void moveleft();
	/** Handles a key press event */
	void moveright();
private:
/* Data Members */
	/** Level identifies which level the game is at */
	int levelff;
	/** Leftclickcounter determines how many times left click is pressed */
	int leftclickcounter;
	/** Leftclickholdcounter determines how long left click is pressed */
	int leftclickholdcounter;
	/** Spawn counter for a meleeminoin */
	int spawnmelee;
	/** Spawn counter for a Siegeminion*/
	int spawnsiege;	
	/** Spawn counter for a Siegeminion*/
	int spawncaster;
	/** Counter for Ezreal giving player time to move*/
	int ezhurt;
	/** Counter for caster monsters shooting*/
	int countbolt;
	/** Counter for siege monsters shooting*/
	int countcannon;
	/** Score counter*/
	int points;
	/** Stores the name */
	QString enteredName;
	/* Spawn an Icon*/
	int iconspawn;
	
	bool trueshotfiring;
	bool inGame;
	bool gamePaused;
	bool playerAlive;
	bool up;
	bool down;
	bool left;
	bool right;
	bool grabbedignite;
	bool lostgame;
	
	/*displays for mana and health*/
	QString dispmana;
	QString disphealth;
	
/* Private functions*/
	/** died() will remove 
	item from scene and objects */
	void died(SceneObject* dead);
	//qstring from integer
	QString numtostr(int num);
/*Window Members*/
	/** MainWidget which holds everything */
	QWidget* mainwidget;
	/** Main Layout for MainWindow */
	QVBoxLayout* mainLayout;
	  /** TITLE above row1*/
	  QHBoxLayout* row0;
	  	/** IconObject used to display QPixmap */
	    	IconObject* hold_spacer0;
	  	/** Used to hold a space */
	  	QPixmap* spacer0;
	  	/** IconObject used to display QPixmap */
	    	IconObject* hold_title;
	    	/** Ability display icon */
	  	QPixmap* title;
	  	/** IconObject used to display QPixmap */
	    	IconObject* hold_spacer01;
	  	/** Used to hold a space */
	  	QPixmap* spacer01;
	  /** Horizontal box for row 1*/
	  QHBoxLayout* row1;
	  	/** Button which initiates/restarts game*/
		QPushButton* start;
		/** Button which pauses/continues game*/
		QPushButton* pause;
		/** quit*/
		QPushButton* quit;
		/** Score display*/
		QTextEdit* name;
		/** Level display*/
		QLabel* level;
		/** Score Display*/
		QLabel* score;
		
	  /** Horizontal box for row 2*/
	  QHBoxLayout* row2;
	  	/** View which holds gameplay*/
	  	GameWindow* view;
	  	/** Scene which holds monsters, player and powerups*/
	  	QGraphicsScene* scene;
	  /** Horizontal box for row 3*/
	  QHBoxLayout* row3;
	    //left
	    	/** IconObject used to display QPixmap */
	    	IconObject* hold_basicattackicon;
	    	/** Ability display icon */
	  	QPixmap* basicattackicon;
	  	/** IconObject used to display QPixmap */
	    	IconObject* hold_mysticshoticon;
	  	/** Ability display icon */
	  	QPixmap* mysticshoticon;
	  	/** IconObject used to display QPixmap */
	    	IconObject* hold_trueshoticon;
	  	/** Ability display icon */
	  	QPixmap* trueshoticon;
	  	/** IconObject used to display QPixmap */
	    	IconObject* hold_spacer1;
	  	/** Used to hold a space */
	  	QPixmap* spacer1;
	    //midleft
	    	/** IconObject used to display QPixmap */
	    	IconObject* hold_heart;
	    	/** Heart Icon */
	    	QPixmap* heart;
	    	/** Health display */
	    	QLabel* health;
	    	/** IconObject used to display QPixmap */
	    	IconObject* hold_spacer2;
	    	/** Used to hold a space */
	  	QPixmap* spacer2;
	    //midright
	    	/** IconObject used to display QPixmap */
	    	IconObject* hold_potion;
	    	/** Mana Icon */
	    	QPixmap* potion;
	    	/** Mana display */
	    	QLabel* mana;
	QTimer* timer;
/* QGraphicsPixmapItem items */
	  QList<SceneObject*> objects; 
	  vector<string> scorenames;
	  vector<int> scores;
/* Used to color background*/	
	QColor color;
/* Used to create the Pixmaps*/
	QPixmap* ez;
	QPixmap* melee;
	QPixmap* caster;
	QPixmap* siege;
	QPixmap* basic;
	QPixmap* mystic;
	QPixmap* trueshot;
	QPixmap* heal;
	QPixmap* clarity;
	QPixmap* ignite;
	QPixmap* energy;
	QPixmap* cannon;
		
};
