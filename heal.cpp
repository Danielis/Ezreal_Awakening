#include "heal.h"
/** Default constructor */
Heal::Heal():
	SceneObject()
{}
/** main constructor */
Heal::Heal(QPixmap& image,int nx,int ny, int health, int mana):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;damage_=25;type=6;
}
/** Default destructor */
Heal::~Heal()
{}
/**get damage_*/
int Heal::getDamage()
{
	return damage_;
}
/**return type*/
int Heal::getType()
{
	return type;
}
/** used by mainwindow to move the character*/
void Heal::movetile(){}
/** used by mainwindow to move the character*/
void Heal::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void Heal::movetile(QPoint p){}
