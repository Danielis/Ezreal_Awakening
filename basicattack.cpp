#include "basicattack.h"
/** Default constructor */
BasicAttack::BasicAttack():
	SceneObject()
{}
/** main constructor */
BasicAttack::BasicAttack(QPixmap& image,int nx,int ny, int health, int mana, int fx, int fy):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;
	damage_=25;
	type=0;
	fx_=fx;
	fy_=fy;
	gone=false;
    	velx = (fx_-nx)/7;
    	vely = (fy_-ny)/7;
}
/** Default destructor */
BasicAttack::~BasicAttack()
{}
/**get damage_*/
int BasicAttack::getDamage()
{
	return damage_;
}
/**return type*/
int BasicAttack::getType()
{
	return type;
}
/** returns fx*/
int BasicAttack::getfX()
{
	return fx_;
}
/** returns fy*/
int BasicAttack::getfY()
{
	return fy_;
}
/** returns gone*/
bool BasicAttack::isGone()
{
	return gone;
}
/** used by mainwindow to move the character*/
void BasicAttack::movetile()
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
void BasicAttack::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void BasicAttack::movetile(QPoint p){}
