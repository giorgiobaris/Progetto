#include <iostream>

#include <QApplication>

#include <QMainWindow>

using namespace std;

int main(int argc, char* argv[]) {

	// istanzio applicazione Qt
	QApplication a(argc, argv);

	QMainWindow* qb = new QMainWindow();

	qb->show();


	// eseguo applicazione Qt
	return a.exec();
}