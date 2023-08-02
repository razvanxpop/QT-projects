#include "drivergui.h"

#include "cmath"
#include <qmessagebox.h>

DriverGui::DriverGui(QWidget* parent) : QWidget(parent), ui(new Ui::DriverGuiClass), service(nullptr), driver(nullptr)
{
	ui->setupUi(this);
	makeConnections();
}

DriverGui::~DriverGui() {
	service->unregisterObserver(this);
	delete ui;
}

void DriverGui::init(Service * service, Driver * driver) {
	this->service = service;
	this->driver = driver;
	this->service->registerObserver(this);
	this->setWindowTitle(QString::fromStdString(this->driver->getName()));
	ui->driverLocationLabel->setText(QString::fromStdString(to_string(this->driver->getLocation().first) + "," + to_string(this->driver->getLocation().second)));
	ui->driverScoreLabel->setText(QString::fromStdString(to_string(this->driver->getScore())));
	this->update();
	this->show();
}

void DriverGui::update() {
	ui->reportsList->clear();
	QFont font;
	font.setBold(true);
	for (auto report : service->getReports()) {
		if (sqrt(pow(driver->getLocation().first - report.getLocation().first, 2) + pow(driver->getLocation().second - report.getLocation().second, 2)) <= 10) {
			ui->reportsList->addItem(QString::fromStdString(report.toString()));
			if (report.getStatus())
				ui->reportsList->item(ui->reportsList->count() - 1)->setFont(font);
		}
	}
	ui->chat->clear();
	for (string message : service->getMessages())
		ui->chat->addItem(QString::fromStdString(message));
}

void DriverGui::makeConnections() {
	QObject::connect(ui->addButton, &QPushButton::clicked, this, &DriverGui::addReport);
	QObject::connect(ui->sendButton, &QPushButton::clicked, this, &DriverGui::addMessage);
	QObject::connect(ui->validateButton, &QPushButton::clicked, this, &DriverGui::validateReport);
}

void DriverGui::addReport() {
	string description = ui->descriptionLineEdit->text().toStdString();
	if (description == "") {
		QMessageBox::critical(this, "Error", "Invalid input!");
		return;
	}
	string location = ui->locationLineEdit->text().toStdString();
	try {
		service->addReport(description, driver->getName(), location, ui->driverLocationLabel->text().toStdString());
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
}

void DriverGui::addMessage() {
	string message = ui->messageLineEdit->text().toStdString();
	ui->messageLineEdit->setText("");
	service->addMessage(driver->getName() + ": " + message);
}

void DriverGui::validateReport() {
	if (ui->reportsList->selectedItems().count() == 0) {
		QMessageBox::critical(this, "Error", "No report selected!");
		return;
	}
	try {
		string report = ui->reportsList->selectedItems()[0]->text().toStdString();
		service->validateReport(report, driver->getName());
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
}
