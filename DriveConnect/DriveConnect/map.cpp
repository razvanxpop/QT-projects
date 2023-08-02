#include "map.h"

#include <qpainter.h>

Map::Map(Service* service, QWidget* parent) : QWidget(parent), service(service), ui(new Ui::MapClass) {
	ui->setupUi(this);
	this->service->registerObserver(this);
	this->setWindowTitle("Map");
	this->update();
}

Map::~Map() {
	service->unregisterObserver(this);
	delete ui;
}

void Map::update() {
	this->setVisible(false);
	this->setVisible(true);
}

void Map::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setBrush(Qt::blue);

	int minLatitude = INT_MAX;
	int minLongitude = INT_MAX;
	for (auto report : service->getReports()) {
		int latitude = report.getLocation().first;
		if (minLatitude > latitude)
			minLatitude = latitude;
		int longitude = report.getLocation().second;
		if (minLongitude > longitude)
			minLongitude = longitude;
	}
	for (auto report : service->getReports())
		if (report.getStatus()) {
			int latitude = report.getLocation().first + abs(minLatitude) + 2;
			int longitude = report.getLocation().second + abs(minLongitude) + 2;
			painter.drawEllipse(latitude * 10, longitude * 10, 10, 10);
			painter.drawText(latitude * 10 , longitude * 10, report.getDescription().c_str());
		}

}
