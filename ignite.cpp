#include "ignite.h"
/** Default constructor */
Ignite::Ignite():
	SceneObject()
{}
/** main constructor */
Ignite::Ignite(QPixmap& image,int nx,int ny, int health, int mana):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;damage_=0;type=7;
}
/** Default destructor */
Ignite::~Ignite()
{}
/**get damage_*/
int Ignite::getDamage()
{
	return damage_;
}
/**return type*/
int Ignite::getType()
{
	return type;
}
/** used by mainwindow to move the character*/
void Ignite::movetile(){}
/** used by mainwindow to move the character*/
void Ignite::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void Ignite::movetile(QPoint p){}
