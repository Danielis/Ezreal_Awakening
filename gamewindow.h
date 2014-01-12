#ifndef GameWindow_H
#define GameWindow_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QKeyEvent>

/** Class defines a new QGraphicsView */
class GameWindow: public QGraphicsView{	
	Q_OBJECT
public:
	/** Default Constructor */
	GameWindow();
	/** Accepts a scene and adds it to the view*/
	GameWindow(QGraphicsScene* scene);
	/** Default Destructor*/
	~GameWindow();
	/**reacts to the mouse being clicked*/
	void mousePressEvent(QMouseEvent * e );
	/**if the mouse was not dragged this emits a signal */
	void mouseReleaseEvent(QMouseEvent * e);
	/* reacts to the keyboard and will emit a signal that will start moving Ez*/
	void keyPressEvent(QKeyEvent *e);
	/* reacts to the keyboard and will emit a signal that will stop moving Ez*/
	void keyReleaseEvent(QKeyEvent *e);
	/**returns the point stored when signal is emmited*/
	QPoint& getpoint(){return point;}
signals:
	/**clicked button is the signal that was being emmited once released*/
	void leftButtonClicked();
	void rightButtonClicked();
	void leftButtonHoldStart();
	void leftButtonHoldCancel();
	void leftarrow();
	void uparrow();
	void rightarrow();
	void downarrow();
	
		
private:
	/**member point storage*/
	QPoint point;
	/**if press is true then it was pressed and not released*/
	bool press;
};
#endif
