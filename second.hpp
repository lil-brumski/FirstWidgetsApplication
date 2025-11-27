#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QList>

class Second : public QWidget {
	Q_OBJECT
public:
	Second(QWidget* parent = nullptr);
	~Second();
private:
	QLabel* name;
	QLabel* department;
	QLabel* matNo;

	QLineEdit* nameLE;
	QLineEdit* departmentLE;
	QLineEdit* matNoLE;

	QPushButton* namePB;
	QPushButton* departmentPB;
	QPushButton* matNoPB;

	QHBoxLayout* layoutOneH;
	QHBoxLayout* layoutTwoH;
	QHBoxLayout* layoutThreeH;

	QVBoxLayout* layoutV;
};