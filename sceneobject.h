#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>

class SceneObject: public QGraphicsPixmapItem
{
public:
	/** Default constructor */
	SceneObject();
	/** main constructor */
	SceneObject(QPixmap& image,int nx,int ny, int health, int mana);
	/** Default destructor */
	~SceneObject();
	/**sets x*/
	void setX( int num );
	/**sets y*/
	void setY( int num );
	/**get x*/
	int getX();
	/**get y*/
	int getY();
	/** set health_*/
	void setHealth( int num );
	/** set mana_*/
	void setMana( int num );
	/**get health_*/
	int getHealth();
	/**get mana_*/
	int getMana();
	/** returns true if is out of screen */
	virtual bool isGone()=0;
	/** get finalX for shots*/
	virtual int getfX()=0;
	/** get finalY for shots*/
	virtual int getfY()=0;
	/**get damage_*/
	virtual int getDamage()=0;
	/**return type*/
	virtual int getType()=0;
	/** used by mainwindow to move the character*/
	virtual void movetile()=0;
	/** used by mainwindow to move the character*/
	virtual void movetile(int windowMaxX,int windowMaxY)=0;
	/** used by mainwindow to move the character*/
	virtual void movetile(QPoint p)=0;
private:
	/** Health*/
	int health_;
	/** Mana */
	int mana_;
	/** stored x-coordinate*/
    	int x_;
    	/** stored y-coordinate*/
    	int y_;
};
#endif
