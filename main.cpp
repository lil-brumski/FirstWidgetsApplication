#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>

int main(int argc, char** argv) {
	QApplication app(argc, argv);

	QWidget window;

	QList<QPushButton*> buttons = {
		new QPushButton(QApplication::translate("hi", "Submit"), &window),
		new QPushButton(QApplication::translate("hi", "Submit"), &window),
		new QPushButton(QApplication::translate("hi", "Submit"), &window)
	};
	
	QList<QLabel*> listOfLabels = {
		new QLabel("Name", &window),
		new QLabel("Department", &window),
		new QLabel("Matriculation Number", &window)
	};
	
	QList<QLineEdit*> LElists = {
		new QLineEdit(&window),
		new QLineEdit(&window),
		new QLineEdit(&window)
	}; 

	LElists[0]->setPlaceholderText(QApplication::translate("hi", "Enter your name"));
	LElists[1]->setPlaceholderText(QApplication::translate("hi", "Enter your department"));
	LElists[2]->setPlaceholderText(QApplication::translate("hi", "Enter your matric number"));

	QHBoxLayout* LO1 = new QHBoxLayout();
	LO1->addWidget(listOfLabels[0]);
	LO1->addWidget(LElists[0]);
	LO1->addWidget(buttons[0]);

	QHBoxLayout* LO2 = new QHBoxLayout();
	LO2->addWidget(listOfLabels[1]);
	LO2->addWidget(LElists[1]);
	LO2->addWidget(buttons[1]);

	QHBoxLayout* LO3 = new QHBoxLayout();
	LO3->addWidget(listOfLabels[2]);
	LO3->addWidget(LElists[2]);
	LO3->addWidget(buttons[2]);

	QVBoxLayout* LOMAIN = new QVBoxLayout();
	LOMAIN->addLayout(LO1);
	LOMAIN->addLayout(LO2);
	LOMAIN->addLayout(LO3);
	
	window.setLayout(LOMAIN);
	window.resize(1024, 600);
	window.setWindowTitle(QApplication::translate("hi", "Brumski's First Qt6 Application"));
	window.show();

	return app.exec();
}