#include "second.hpp"
#include <QApplication>

Second::Second(QWidget* parent) : QWidget(parent) {
	this->resize(450, 380);
	this->setWindowTitle(QApplication::translate("title", "Second App"));

	name = new QLabel(QApplication::translate("name", "Name"), this);
	department = new QLabel(QApplication::translate("department", "Department"), this);
	matNo = new QLabel(QApplication::translate("matno", "Matriculation Number"), this);

	//
	nameLE = new QLineEdit(this);
	nameLE->setPlaceholderText(QApplication::translate("hi", "Please enter your name"));
	//
	departmentLE = new QLineEdit(this);
	departmentLE->setPlaceholderText(QApplication::translate("hi", "Please enter your department"));
	//
	matNoLE = new QLineEdit(this);
	matNoLE->setPlaceholderText(QApplication::translate("hi", "Please enter your matric number"));
	
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