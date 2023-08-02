#include "map.h"

#include <qpainter.h>
#include <math.h>

Map::Map(Controller* controller, QWidget* parent) : controller(controller), ui(new Ui::MapClass), QWidget(parent) {
	ui->setupUi(this);
	this->controller->registerObserver(this);
	this->setWindowTitle("Map");
	this->update();
}

Map::~Map() {
	this->controller->unregisterObserver(this);
	delete ui;
}

void Map::update() {
	this->setVisible(false);
	this->setVisible(true);
}

void Map::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setBrush(Qt::green);
	int minLatitude = INT_MAX;
	int minLongitude = INT_MAX;
	for (const auto& package : this->controller->getPackages())
		if (!package.getStauts()) {
			if (package.getLocation().first < minLatitude)
				minLatitude = package.getLocation().first;
			if (package.getLocation().second < minLongitude)
				minLongitude = package.getLocation().second;
		}

	for (const auto& package : this->controller->getPackages())
		if (!package.getStauts()) {
			int x = package.getLocation().first + abs(minLatitude) + 2;
			int y = package.getLocation().second + abs(minLongitude) + 2;

			painter.drawEllipse(x * 10, y * 10, 10, 10);
		}
}
