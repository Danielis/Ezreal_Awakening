#include "meleeminion.h"
/** Default constructor */
MeleeMinion::MeleeMinion():
	SceneObject()
{}
/** main constructor */
MeleeMinion::MeleeMinion(QPixmap& image,int nx,int ny, int health, int mana):
	SceneObject(image,nx,ny,health,mana)
{
	hasRange_=false;damage_=10;type=8;
}
/** Default destructor */
MeleeMinion::~MeleeMinion()
{}
/**get damage_*/
int MeleeMinion::getDamage()
{
	return damage_;
}
/**return type*/
int MeleeMinion::getType()
{
	return type;
}
/** used by mainwindow to move the character*/
void MeleeMinion::movetile()
{
	movement++;
	if(movement%20==0)
		movecase=rand()%8;
	if(movement%30==0)
		movecase=(rand()*rand())%8;
	switch (movecase)
	{
		case 0:
			setX(getX()-10);
			break;
		case 1:
			setX(getX()+10);
			setY(getY()-10);
			break;
		case 2:
			setY(getY()-10);
			break;
		case 3:
			setX(getX()+10);
			setY(getY()-10);
			break;
		case 4:
			setX(getX()+10);
			break;
		case 5:
			setX(getX()+10);
			setY(getY()+10);
			break;
		case 6:
			setY(getY()+10);
			break;
		case 7:
			setX(getX()-10);
			setY(getY()+10);
			break;
	}
	if(getX()+50>1155)
  		setX(1155-50);
  	else if(getX()<0)
  		setX(0);
  	if(getY()+50+50/2>555)
  		setY(555-50-50/2);
  	else if(getY()<0)
  		setY(0);
  	setPos(getX(),getY());
}
/** used by mainwindow to move the character*/
void MeleeMinion::movetile(int windowMaxX,int windowMaxY){}
/** used by mainwindow to move the character*/
void MeleeMinion::movetile(QPoint p){}
