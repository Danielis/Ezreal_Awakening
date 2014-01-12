#include "trueshot.h"
/** Default constructor */
TrueShot::TrueShot():
	SceneObject()
{}
/** main constructor */
TrueShot::TrueShot(QPixmap& image,int nx,int ny, int health, int mana, int fx, int fy):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;
	damage_=100;
	type=11;
	fx_=fx;
	fy_=fy;
	gone=false;
    	velx = (fx_-nx)/7;
    	vely = (fy_-ny)/7;
}
/** Default destructor */
TrueShot::~TrueShot()
{}
/**get damage_*/
int TrueShot::getDamage()
{
	return damage_;
}
/**return type*/
int TrueShot::getType()
{
	return type;
}
/** returns fx*/
int TrueShot::getfX()
{
	return fx_;
}
/** returns fy*/
int TrueShot::getfY()
{
	return fy_;
}
/** returns gone*/
bool TrueShot::isGone()
{
	return gone;
}
/** used by mainwindow to move the character*/
void TrueShot::movetile()
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
void TrueShot::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void TrueShot::movetile(QPoint p){}
