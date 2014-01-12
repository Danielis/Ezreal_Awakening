#include "clarity.h"
/** Default constructor */
Clarity::Clarity():
	SceneObject()
{}
/** main constructor */
Clarity::Clarity(QPixmap& image,int nx,int ny, int health, int mana):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;damage_=200;type=3;
}
/** Default destructor */
Clarity::~Clarity()
{}
/**get damage_*/
int Clarity::getDamage()
{
	return damage_;
}
/**return type*/
int Clarity::getType()
{
	return type;
}
/** used by mainwindow to move the character*/
void Clarity::movetile(){}
/** used by mainwindow to move the character*/
void Clarity::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void Clarity::movetile(QPoint p){}
