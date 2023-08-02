#include "couriergui.h"
#include "utils.h"

#include <qpushbutton.h>
#include <qmessagebox.h>

CourierGui::CourierGui(QWidget* parent) : QWidget(parent), ui(new Ui::CourierGuiClass), controller(nullptr), courier(nullptr)
{
	ui->setupUi(this);
	makeConnections();
}

CourierGui::~CourierGui() {
	controller->unregisterObserver(this);
	delete ui;
}

void CourierGui::init(Controller* controller, Courier* courier) {
	this->controller = controller;
	this->courier = courier;
	this->controller->registerObserver(this);

	this->setWindowTitle(QString::fromStdString(this->courier->getName()));
	this->ui->courierZoneLabel->setText(QString::fromStdString(to_string(this->courier->getZone().first.first) + "," + to_string(this->courier->getZone().first.second) + "," + to_string(this->courier->getZone().second)));
	this->update();
	this->show();
}

void CourierGui::makeConnections() {
	QObject::connect(this->ui->comboBox, &QComboBox::currentIndexChanged, this, &CourierGui::getPackagesOnSelectedStreet);
	QObject::connect(this->ui->deliverButton, &QPushButton::clicked, this, &CourierGui::deliverPackage);
}

void CourierGui::update() {
	this->ui->undeliveredPackagesList->clear();
	vector<Package> filteredPackages = this->controller->getUndeliverdPackages(this->courier);
	for (auto package : filteredPackages)
		this->ui->undeliveredPackagesList->addItem(QString::fromStdString(package.toString()));
	this->ui->comboBox->clear();
	this->ui->comboBox->addItem(QString("No street selected"));
	for (string street : this->courier->getStreets())
		this->ui->comboBox->addItem(QString::fromStdString(street));
}

void CourierGui::getPackagesOnSelectedStreet() {
	this->ui->undeliveredPackagesList->clear();
	if (this->ui->comboBox->currentText() == "No street selected") {
		vector<Package> filteredPackages = this->controller->getUndeliverdPackages(this->courier);
		for (auto package : filteredPackages)
			this->ui->undeliveredPackagesList->addItem(QString::fromStdString(package.toString()));
	}
	else {
		vector<Package> filteredPackages = this->controller->getPackagesOnTheSelectedStreet(this->ui->comboBox->currentText().toStdString());
		for (auto package : filteredPackages)
			this->ui->undeliveredPackagesList->addItem(QString::fromStdString(package.toString()));
	}
}

void CourierGui::deliverPackage() {
	if (this->ui->undeliveredPackagesList->selectedItems().empty()) {
		QMessageBox::critical(this, "Error", "No items selected!");
		return;
	}
	string str = this->ui->undeliveredPackagesList->selectedItems()[0]->text().toStdString();
	vector<string> tokens = tokenize(trim(str), ';');
	string recipient = trim(tokens[0]);
	vector<string> adressTokens = tokenize(trim(tokens[1]), ',');
	pair<string, int> adress = make_pair(trim(adressTokens[0]), stoi(trim(adressTokens[1])));
	vector<string> locationTokens = tokenize(trim(tokens[2]), ',');
	pair<int, int> location = make_pair(stoi(trim(locationTokens[0])), stoi(trim(locationTokens[1])));
	bool status = stoi(trim(tokens[3]));
	try {
		this->controller->deliverPackage(recipient, adress, location, status);
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
	this->update();
}