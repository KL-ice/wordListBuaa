#include "dialog.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	try {
		QApplication a(argc, argv);
		Dialog w;
		w.show();

		return a.exec();
	}
	catch (...)
	{
		qDebug() << "Error!";
	}
}
