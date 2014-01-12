#include <QtGui/QApplication>
#include "mainwindow.h"
//include all other classes in mainwindow

/** Main function call, it runs the executable*/
int main(int argc, char *argv[])
{
/** @mainpage CSCI 102 Final Project Game
@section purpose Purpose/Overview
This implements a Qt interface for the game created
@section requirements Requirements
User hits start and begins game play. Play can be paused, restarted or continued. Scores are tracked and stored in a file.
*/
	/** Qapp call*/
    QApplication a(argc, argv);
    /** makes the main window*/
    MainWindow w;
	/** show the mainwindow*/
    w.show();

    return a.exec();
}

/*
//Optional
>give the mainwidget a desert background?

//Need to do
>Fix the displays for health mana and top
*/
