#include "ezreal.h"
/** Default constructor */
Ezreal::Ezreal():
	SceneObject()
{}
/** main constructor */
Ezreal::Ezreal(QPixmap& image,int nx,int ny, int health, int mana):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=true;damage_=1;type=5;
	setOffset(-75/2,-75/2);
}
/** Default destructor */
Ezreal::~Ezreal()
{}
/**get damage_*/
int Ezreal::getDamage()
{
	return damage_;
}
/**return type*/
int Ezreal::getType()
{
	return type;
}
/** used by mainwindow to move the character
  *Ezreal will instantly move to the coordinates passed in*/
void Ezreal::movetile(int windowMaxX,int windowMaxY)
{
  	int x,y;
  	if(windowMaxX+75/2>1155)
  		x=1155-75/2;
  	else if(windowMaxX-75/2<0)
  		x=75/2;
  	else
  		x=windowMaxX;
  		
  	if(windowMaxY+75/2>555)
  		y=555-75/2;
  	else if(windowMaxY-75/2<0)
  		y=75/2;
  	else
  		y=windowMaxY;
	setX(x);
	setY(y);
  	setPos(x,y);
}
/** used by mainwindow to move the character
  *Ezreal will instantly move to the coordinates passed in*/
void Ezreal::movetile(){}
/** used by mainwindow to move the character
  *Ezreal will instantly move to the coordinates passed in*/
void Ezreal::movetile(QPoint p)
{
	int x,y;
  	if(p.rx()+75/2>1155)
  		x=1155-75/2;
  	else if(p.rx()-75/2<0)
  		x=75/2;
  	else
  		x=p.rx();
  		
  	if(p.ry()+75/2>555)
  		y=555-75/2;
  	else if(p.ry()-75/2<0)
  		y=75/2;
  	else
  		y=p.ry();
	setX(x);
	setY(y);
	setPos(x,y);
}
