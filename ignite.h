#ifndef IGNITE_H
#define IGNITE_H
#include "sceneobject.h"
/** Ignite*/
class Ignite : public SceneObject
{
public:
	/** Default constructor */
	Ignite();
	/** main constructor */
	Ignite(QPixmap& image,int nx,int ny, int health, int mana);
	/** Default destructor */
	~Ignite();
	/**get damage_*/
	int getDamage();
	/**return type*/
	int getType();
	/** used by mainwindow to move the character*/
	void movetile();
	/** redefined but not implemented 
	  * used in range attacks*/
	int getfX(){return 0;}
	/** redefined but not implemented 
	  * used in range attacks*/
	int getfY(){return 0;}
	/** returns gone*/
	bool isGone(){return false;}
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
