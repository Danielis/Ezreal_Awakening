#include "mysticshot.h"
/** Default constructor */
MysticShot::MysticShot():
	SceneObject()
{}
/** main constructor */
MysticShot::MysticShot(QPixmap& image,int nx,int ny, int health, int mana, int fx, int fy):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;
	damage_=50;
	type=9;
	fx_=fx;
	fy_=fy;
	gone=false;
    	velx = (fx_-nx)/7;
    	vely = (fy_-ny)/7;
}
/** Default destructor */
MysticShot::~MysticShot()
{}
/**get damage_*/
int MysticShot::getDamage()
{
	return damage_;
}
/**return type*/
int MysticShot::getType()
{
	return type;
}
/** returns fx*/
int MysticShot::getfX()
{
	return fx_;
}
/** returns fy*/
int MysticShot::getfY()
{
	return fy_;
}
/** returns gone*/
bool MysticShot::isGone()
{
	return gone;
}
/** used by mainwindow to move the character*/
void MysticShot::movetile()
{
	setX(getX()+velx);
	setY(getY()+vely);
	
	if(getX()+velx<0 || getX()+velx>1155 || getY()+vely<0 | getY()+vely>555)
	{
		gone=true; 	
	}
	setPos(getX(),getY());
}
/** used by mainwindow to move the character*/
void MysticShot::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void MysticShot::movetile(QPoint p){}
