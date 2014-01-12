#ifndef ICONOBJECT_H
#define ICONOBJECT_H
#include <QLabel>

using namespace std;
class IconObject : public QLabel
{
public:
	/** Default constructor */
	IconObject();
	/** Default destructor */
	~IconObject();
private:
	/** use to convert between const strings and Qstring*/
	QString file;
};
#endif
