#include "gamewindow.h"
/** Default Constructor */
GameWindow::GameWindow():
	QGraphicsView()
{
	press=false;
}
/** Accepts a scene and adds it to the view*/
GameWindow::GameWindow(QGraphicsScene* scene):
	QGraphicsView(scene)
{
	press=false;
}
/** Default Destructor*/
GameWindow::~GameWindow()
{}
/**reacts to the mouse being clicked*/
void GameWindow::mousePressEvent(QMouseEvent * e ){
	point=e->pos();
	press=true;
	if(e->button() == Qt::LeftButton)
		emit leftButtonHoldStart();
	if(e->button() == Qt::RightButton)
			emit rightButtonClicked();
	if(e->button() == Qt::LeftButton)
			emit leftButtonClicked();
}
/**if the mouse was not dragged this emits a signal */
void GameWindow::mouseReleaseEvent(QMouseEvent * e)
{
	emit leftButtonHoldCancel();
	if(press && point==e->pos())
	{
		// This can check if it was a click or merely a hold
	}
	press=false;
}
/* reacts to the keyboard and will emit a signal that will move Ez*/
void GameWindow::keyPressEvent(QKeyEvent *e)
{
	if(e->key()==Qt::Key_A)
		emit leftarrow();
	if(e->key()==Qt::Key_W)
		emit uparrow();
	if(e->key()==Qt::Key_D)
		emit rightarrow();
	if(e->key()==Qt::Key_S)
		emit downarrow();
}
void GameWindow::keyReleaseEvent(QKeyEvent *e)
{
	if(e->key()==Qt::Key_A)
		emit leftarrow();
	if(e->key()==Qt::Key_W)
		emit uparrow();
	if(e->key()==Qt::Key_D)
		emit rightarrow();
	if(e->key()==Qt::Key_S)
		emit downarrow();
}



