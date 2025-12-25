#include "second.hpp"
#include <QApplication>

Second::Second(QWidget* parent) : QWidget(parent) {
    this->resize(800, 640);
    this->setWindowTitle(QApplication::translate("title", "Brumax2026"));

    ///
    myFace = new QLabel(this);
    myFace->setGeometry(0, 0, 100, 100);
    myFace->setPixmap(QPixmap(":/images/myFace.png"));
    myFace->setScaledContents(true);
    ///

    ///
	name = new QLabel(QApplication::translate("name", "Name"), this);
	department = new QLabel(QApplication::translate("department", "Department"), this);
	matNo = new QLabel(QApplication::translate("matno", "Matriculation Number"), this);

	//
	nameLE = new QLineEdit(this);
	nameLE->setPlaceholderText(QApplication::translate("hi", "Please enter your name"));
    nameLE->setFont(QFont("Times", 16));
    nameLE->setStyleSheet("color:red");
	//
	departmentLE = new QLineEdit(this);
	departmentLE->setPlaceholderText(QApplication::translate("hi", "Please enter your department"));
    departmentLE->setFont(QFont("Times", 16));
    departmentLE->setStyleSheet("color:red");
	//
	matNoLE = new QLineEdit(this);
	matNoLE->setPlaceholderText(QApplication::translate("hi", "Please enter your matric number"));
    matNoLE->setFont(QFont("Times", 16));
    matNoLE->setStyleSheet("color:red");
	
	////
	namePB = new QPushButton("Submit", this);
	departmentPB = new QPushButton("Submit", this);
	matNoPB = new QPushButton("Submit", this);

	layoutOneH = new QHBoxLayout();
	layoutOneH->addWidget(name);
	layoutOneH->addWidget(nameLE);
	layoutOneH->addWidget(namePB);

	layoutTwoH = new QHBoxLayout();
	layoutTwoH->addWidget(department);
	layoutTwoH->addWidget(departmentLE);
	layoutTwoH->addWidget(departmentPB);

	layoutThreeH = new QHBoxLayout();
	layoutThreeH->addWidget(matNo);
	layoutThreeH->addWidget(matNoLE);
	layoutThreeH->addWidget(matNoPB);

	layoutV = new QVBoxLayout();
	layoutV->addLayout(layoutOneH);
	layoutV->addLayout(layoutTwoH);
	layoutV->addLayout(layoutThreeH);

	this->setLayout(layoutV);
}

Second::~Second() {

}

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	Second window;
	window.show();
	return app.exec();
}
