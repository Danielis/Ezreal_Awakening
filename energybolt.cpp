#include "energybolt.h"
/** Default constructor */
EnergyBolt::EnergyBolt():
	SceneObject()
{}
/** main constructor */
EnergyBolt::EnergyBolt(QPixmap& image,int nx,int ny, int health, int mana, int fx, int fy):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;
	damage_=15;
	type=4;
	fx_=fx;
	fy_=fy;
	gone=false;
    	velx = (fx_-nx)/7;
    	vely = (fy_-ny)/7;
}
/** Default destructor */
EnergyBolt::~EnergyBolt()
{}
/**get damage_*/
int EnergyBolt::getDamage()
{
	return damage_;
}
/**return type*/
int EnergyBolt::getType()
{
	return type;
}
/** returns fx*/
int EnergyBolt::getfX()
{
	return fx_;
}
/** returns fy*/
int EnergyBolt::getfY()
{
	return fy_;
}
/** returns gone*/
bool EnergyBolt::isGone()
{
	return gone;
}
/** used by mainwindow to move the character*/
void EnergyBolt::movetile()
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
void EnergyBolt::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void EnergyBolt::movetile(QPoint p){}
