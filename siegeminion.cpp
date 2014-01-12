#include "siegeminion.h"
#include <cmath>
#include <iostream>
/** Default constructor */
SiegeMinion::SiegeMinion():
	SceneObject()
{}
/** main constructor */
SiegeMinion::SiegeMinion(QPixmap& image,int nx,int ny, int health, int mana):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=true;damage_=10;type=10;
}
/** Default destructor */
SiegeMinion::~SiegeMinion()
{}
/**get damage_*/
int SiegeMinion::getDamage()
{
	return damage_;
}
/**return type*/
int SiegeMinion::getType()
{
	return type;
}
/** used by mainwindow to move the character*/
void SiegeMinion::movetile(){}
/** used by mainwindow to move the character*/
void SiegeMinion::movetile(int windowMaxX,int windowMaxY)
{
	if(windowMaxX<getX())
	{
		setX(getX()-5);
	}
	else if(windowMaxX>getX())
	{
		setX(getX()+5);
	}
	if(windowMaxY<getY())
	{
		setY(getY()-5);
	}
	else if(windowMaxY>getY())
	{
		setY(getY()+5);
	}
	if(getX()+75>1155)
  		setX(1155-75);
  	else if(getX()<0)
  		setX(0);
  		
  	if(getY()+75>555)
  		setY(555-75);
  	else if(getY()<0)
  		setY(0);
	setPos(getX(),getY());
}
/** used by mainwindow to move the character*/
void SiegeMinion::movetile(QPoint p){}
