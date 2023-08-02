#include "statisticsgui.h"
#include <qpainter.h>
#include <algorithm>
#include <iterator>

StatisticsGui::StatisticsGui(Service* service, QWidget *parent) : service(service), QWidget(parent), ui(new Ui::StatisticsGuiClass)
{
	ui->setupUi(this);
	service->registerObserver(this);
	this->setWindowTitle("Visual Statistics");
	this->update();
}

StatisticsGui::~StatisticsGui() {
	service->unregisterObserver(this);
	delete ui;
}

void StatisticsGui::update() {
	this->setVisible(false);
	this->setVisible(true);
}

void StatisticsGui::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setBrush(Qt::blue);
	vector<string> specializations;
	for (auto patient : service->getPatients())
		if (std::find(specializations.begin(), specializations.end(), patient.getSpecialization()) == specializations.end())
			specializations.push_back(patient.getSpecialization());
	int x = 50;
	int y = 50;
	int index = 0;
	for (string specialization: specializations) {
		QRect rect(x, y, 100, 100);
		painter.drawRect(rect);
		painter.drawText(x, y, specialization.c_str());
		int textX = rect.x() + rect.width() / 2;
		int textY = rect.y() + rect.height() / 2;
		painter.drawText(textX, textY, to_string(service->getPatientsBySpecialization(specialization).size()).c_str());
		x += 105;
		index++;
		if (index % 3 == 0) {
			y += 115;
			x = 50;
		}
	}
}
