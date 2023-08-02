#include "usergui.h"

#include "qmessagebox.h"

UserGui::UserGui(QWidget* parent) : QWidget(parent), ui(new Ui::UserGuiClass), service(nullptr), user(nullptr) {
	ui->setupUi(this);
	makeConnections();
}

UserGui::~UserGui() {
	service->unregisterObserver(this);
	delete ui;
}

void UserGui::init(Service * service, User * user) {
	this->service = service;
	this->user = user;
	this->service->registerObserver(this);
	this->setWindowTitle(QString::fromStdString(this->user->getName()));
	update();
	this->show();
}

void UserGui::update() {
	ui->itemsList->clear();
	vector<Item> items = service->getItems();
	sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
		return a.getPrice() < b.getPrice();
	});
	ui->comboBox->clear();
	for (auto item : items) {
		ui->itemsList->addItem(QString::fromStdString(item.toString()));
		ui->comboBox->addItem(QString::fromStdString(item.getCategory()));
	}
	ui->offersList->clear();
}

void UserGui::makeConnections() {
	QObject::connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &UserGui::filterByCategory);
	QObject::connect(ui->itemsList, &QListWidget::itemSelectionChanged, this, &UserGui::viewItemOffers);
	QObject::connect(ui->addButton, &QPushButton::clicked, this, &UserGui::addButton);
	QObject::connect(ui->bidButton, &QPushButton::clicked, this, &UserGui::bidForSelectedItem);
}

void UserGui::filterByCategory() {
	string category = ui->comboBox->currentText().toStdString();
	vector<Item> filteredItems = service->getItemsByCategory(category);
	ui->itemsList->clear();
	for (auto item : filteredItems)
		ui->itemsList->addItem(QString::fromStdString(item.toString()));
}

void UserGui::viewItemOffers() {
	ui->offersList->clear();
	if (ui->itemsList->selectedItems().count() == 0) {
		return;
	}
	string itemString = ui->itemsList->selectedItems()[0]->text().toStdString();
	Item item = service->findItem(itemString);
	ui->offersList->addItem(QString::fromStdString(item.toStringOffers()));
}

void UserGui::addButton() {
	string name = ui->nameLineEdit->text().toStdString();
	string category = ui->categoryLineEdit->text().toStdString();
	int price;
	try {
		price = stoi(ui->priceLineEdit->text().toStdString());
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", "The price must be a natural number");
		return;
	}

	if (name == "" && price <= 0) {
		QMessageBox::critical(this, "Error", "The name must not be empty and the price must greater than 0!");
		return;
	}
	if (name == "") {
		QMessageBox::critical(this, "Error", "The name must not be empty!");
		return;
	}
	if (price <= 0) {
		QMessageBox::critical(this, "Error", "The price must be greater than 0!");
		return;
	}

	try {
		service->addItem(name, category, price);
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
}

void UserGui::bidForSelectedItem() {
	int bidPrice;
	try {
		bidPrice = stoi(ui->bidPriceLineEdit->text().toStdString());
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
	if (ui->itemsList->selectedItems().count() == 0) {
		QMessageBox::critical(this, "Error", "No item selected!");
		return;
	}
	string itemString = ui->itemsList->selectedItems()[0]->text().toStdString();
	try {
		service->bidItem(itemString, bidPrice, user->getId());
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
		return;
	}
}
