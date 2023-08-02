#include "doctorgui.h"
#include "utils.h"

#include <qmessagebox.h>

DoctorGui::DoctorGui(QWidget* parent) : QWidget(parent), ui(new Ui::DoctorGuiClass), service(nullptr), doctor(nullptr) {
	ui->setupUi(this);
	makeConnections();
}

DoctorGui::~DoctorGui() {
	service->unregisterObserver(this);
	delete ui;
}

void DoctorGui::update() {
	this->ui->patientsList->clear();
	vector<Patient> filteredPatients = service->getPatientsBySpecialization(doctor->getSpecialization());
	sort(filteredPatients.begin(), filteredPatients.end(), [](const Patient& a, const Patient& b) {
		return a.getDate() < b.getDate();
	});

	for (auto patient : filteredPatients) {
		this->ui->patientsList->addItem(QString::fromStdString(patient.toString()));
		if (patient.getDoctor() == doctor->getName())
			this->ui->patientsList->item(this->ui->patientsList->count() - 1)->setBackground(Qt::green);
	}
}

void DoctorGui::init(Service* service, Doctor* doctor) {
	this->service = service;
	this->doctor = doctor;
	this->service->registerObserver(this);
	this->setWindowTitle(QString::fromStdString(this->doctor->getName()));
	this->update();
	this->show();
}

void DoctorGui::makeConnections(){
	QObject::connect(this->ui->checkBox, &QCheckBox::stateChanged, this, &DoctorGui::checkBoxClicked);
	QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &DoctorGui::addPatient);
	QObject::connect(this->ui->updateButton, &QPushButton::clicked, this, &DoctorGui::updatePatient);
}

void DoctorGui::checkBoxClicked() {
	if (this->ui->checkBox->checkState()) {
		vector<Patient> filteredPatients = service->getPatientsByDoctor(doctor->getName());
		this->ui->patientsList->clear();
		for (auto patient : filteredPatients)
			this->ui->patientsList->addItem(QString::fromStdString(patient.toString()));
	}
	else
		this->update();
}

void DoctorGui::addPatient() {
	string name = this->ui->nameLineEdit->text().toStdString();
	string diagnosis = this->ui->diagnosisLineEdit->text().toStdString();
	string specialization = this->ui->specializationLineEdit->text().toStdString();
	string doctor = this->ui->doctorLineEdit->text().toStdString();
	string date = this->ui->dateLineEdit->text().toStdString();
	this->ui->nameLineEdit->setText("");
	this->ui->diagnosisLineEdit->setText("");
	this->ui->specializationLineEdit->setText("");
	this->ui->doctorLineEdit->setText("");
	this->ui->dateLineEdit->setText("");
	try {
		service->addPatient(name, diagnosis, specialization, doctor, date);
	}
	catch (const exception& e) {
		QMessageBox::critical(this, "Error", e.what());
	}
}

void DoctorGui::updatePatient() {
	string str = this->ui->patientsList->selectedItems()[0]->text().toStdString();
	vector<string> tokens = tokenize(trim(str), ';');
	if (trim(tokens[1]) != "undiagnosed" && trim(tokens[3]) != doctor->getName()) {
		QMessageBox::critical(this, "Error", "The patient to be updated needs to be ungiagnosed or to be assign to the current doctor!");
		return;
	}
	string newDiagnosis = this->ui->diagnosisLineEdit->text().toStdString();
	if (newDiagnosis == "undiagnosed") {
		QMessageBox::critical(this, "Error", "The diagnosis needs to be valid!");
		return;
	}
	string newSpecialization = this->ui->specializationLineEdit->text().toStdString();
	string newDoctor = this->ui->doctorLineEdit->text().toStdString();
	if (newSpecialization != "" && newSpecialization != doctor->getSpecialization() && newDoctor == "") {
		QMessageBox::critical(this, "Error", "The patient needs a new doctor for the selected specialization!");
		return;
	}
	string name = trim(tokens[0]);
	string diagnosis = trim(tokens[1]);
	string specialization = trim(tokens[2]);
	string patientDoctor = trim(tokens[3]);
	string date = trim(tokens[4]);
	if (newSpecialization != doctor->getSpecialization() && newSpecialization != "") {
		try {
			service->updatePatient(name, diagnosis, specialization, patientDoctor, date, newDiagnosis, newSpecialization, newDoctor);
		}
		catch (const exception& e) {
			QMessageBox::critical(this, "Error", e.what());
		}
	}
	else {
		try {
			service->updatePatient(name, diagnosis, specialization, patientDoctor, date, newDiagnosis, doctor->getSpecialization(), doctor->getName());
		}
		catch (const exception& e) {
			QMessageBox::critical(this, "Error", e.what());
		}
	}
}
