#ifndef CLARITY_H
#define CLARITY_H
#include "sceneobject.h"
/** Clarity*/
class Clarity : public SceneObject
{
public:
	/** Default constructor */
	Clarity();
	/** main constructor */
	Clarity(QPixmap& image,int nx,int ny, int health, int mana);
	/** Default destructor */
	~Clarity();
	/**get damage_*/
	int getDamage();
	/**return type*/
	int getType();
	/** redefined but not implemented 
	  * used in range attacks*/
	int getfX(){return 0;}
	/** redefined but not implemented 
	  * used in range attacks*/
	int getfY(){return 0;}
	/** returns gone*/
	bool isGone(){return false;}
	/** used by mainwindow to move the character*/
	void movetile();
	/** used by mainwindow to move the character*/
	void movetile(int windowMaxX,int windowMaxY);
	/** used by mainwindow to move the character*/
	void movetile(QPoint p);
private:
	/** Can the character fire something*/
    	bool hasRange_;
    	/** Damage done*/
    	int damage_; // not in constructor since passed in class
	/** Tells which object type it is*/
    	int type;
};
#endif
