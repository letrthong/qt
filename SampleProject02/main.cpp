#include <QApplication>
#include <QLabel>
#include <QWidget>

#include "Hello.h"

int main(int argc, char *argv[ ])
{
	QApplication app(argc, argv);

	std::string text = "<center>" + Hello::getText()  +  "</center>";
	QLabel hello(text.c_str());
	hello.setWindowTitle( "My First Qt Program" );
	hello.resize(400, 400);

	 
	hello.show();
return app.exec();

}
