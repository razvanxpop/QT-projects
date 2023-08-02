#include "couriercompanygui.h"
#include <qmessagebox.h>
#include <qpushbutton.h>

CourierCompanyGui::CourierCompanyGui(Controller* controller, QWidget* parent) : controller(controller), QWidget(parent), ui(new Ui::CourierCompanyGuiClass) {
	ui->setupUi(this);
	this->makeConnections();
	this->setWindowTitle("Courier Company");
	this->controller->registerObserver(this);
	this->update();
}

CourierCompanyGui::~CourierCompanyGui() {
	this->controller->unregisterObserver(this);
	delete ui;
}

void CourierCompanyGui::update() {
	this->ui->packagesList->clear();
	for (auto& package : this->controller->getPackages()) {
		this->ui->packagesList->addItem(QString::fromStdString(package.toString()));
		if (package.getStauts())
			this->ui->packagesList->item(this->ui->packagesList->count() - 1)->setBackground(QColor(0, 255, 0));
	}
}

void CourierCompanyGui::makeConnections() {
	QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &CourierCompanyGui::addPackage);
}

void CourierCompanyGui::addPackage() {
	string recipient = this->ui->recipientLineEdit->text().toStdString();
	string adress = this->ui->adressLineEdit->text().toStdString();
	string location = this->ui->locationLineEdit->text().toStdString();
	try {
		this->controller->addPackage(recipient, adress, location);
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
}
