#include "cannonshot.h"
/** Default constructor */
CannonShot::CannonShot():
	SceneObject()
{}
/** main constructor */
CannonShot::CannonShot(QPixmap& image,int nx,int ny, int health, int mana, int fx, int fy):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;
	damage_=20;
	type=1;
	fx_=fx;
	fy_=fy;
	gone=false;
    	velx = (fx_-nx)/7;
    	vely = (fy_-ny)/7;
}
/** Default destructor */
CannonShot::~CannonShot()
{}
/**get damage_*/
int CannonShot::getDamage()
{
	return damage_;
}
/**return type*/
int CannonShot::getType()
{
	return type;
}
/** returns fx*/
int CannonShot::getfX()
{
	return fx_;
}
/** returns fy*/
int CannonShot::getfY()
{
	return fy_;
}
/** returns gone*/
bool CannonShot::isGone()
{
	return gone;
}
/** used by mainwindow to move the character*/
void CannonShot::movetile()
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
void CannonShot::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void CannonShot::movetile(QPoint p){}
