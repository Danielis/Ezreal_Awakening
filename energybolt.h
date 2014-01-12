#ifndef ENERGYBOLT_H
#define ENERGYBOLT_H
#include "sceneobject.h"
/** Energy Bolt*/
class EnergyBolt : public SceneObject
{
public:
	/** Default constructor */
	EnergyBolt();
	/** main constructor */
	EnergyBolt(QPixmap& image,int nx,int ny, int health, int mana, int fx, int fy);
	/** Default destructor */
	~EnergyBolt();
	/**get damage_*/
	int getDamage();
	/**return type*/
	int getType();
	/** returns fx*/
	int getfX();
	/** returns fy*/
	int getfY();
	/** returns gone*/
	bool isGone();
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
    	/** final X coordinate */
    	int fx_;
    	/** final Y coordinate */
    	int fy_;
    	/** Has it finished */
    	bool gone;
    	/** x direction true if pos*/
    	int velx;
    	/** y direction true if pos*/
    	int vely;
};
#endif
