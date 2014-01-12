#include "sceneobject.h"

/** Default constructor */
SceneObject::SceneObject():
	QGraphicsPixmapItem()
{}
/** main constructor */
SceneObject::SceneObject(QPixmap& image,int nx,int ny, int health, int mana):
	QGraphicsPixmapItem(image)
{
	x_=nx;y_=ny;health_=health;mana_=mana;
}
/** Default destructor */
SceneObject::~SceneObject()
{}
/**sets x*/
void SceneObject::setX( int num )
{
	x_=num;
}
/**sets y*/
void SceneObject::setY( int num )
{
	y_=num;
}
/**get x*/
int SceneObject::SceneObject::getX()
{
		return x_;
}
/**get y*/
int SceneObject::getY()
{
	return y_;
}
/** set health_*/
void SceneObject::setHealth( int num )
{
	health_=num;
}
/** set mana_*/
void SceneObject::setMana( int num )
{
	mana_=num;
}
/**get health_*/
int SceneObject::getHealth()
{
	return health_;
}
/**get mana_*/
int SceneObject::getMana()
{
	return mana_;
}

