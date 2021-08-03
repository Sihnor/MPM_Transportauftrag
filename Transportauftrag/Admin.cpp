#include "pch.h"
#include "Admin.h"
#include "Klasse.h"
#include <fstream>
//Zeigt den derzeitigen Benutzer an
//MessageBox::Show(System::Environment::UserName);

using namespace Transportauftrag_Admin;

//To Convert the Data Types that allows writing and reading from the txt-files.
std::string		Admin::String_to_string					(System::String^ text_) {	
	std::string s;

	for (int i = 0; i < text_->Length; i++)
		s += text_[i];
	return s;
}
System::String^ Admin::string_to_String					(std::string text_){
	return gcnew String(text_.c_str());
}

//Hide, show and clear textboxes, labels, buttons and listboxes that are not in use.
System::Void	Admin::showItems						(System::Object^ sender){
	this->clearItems();

	lbl_firstname->Visible = true;
	lbl_lastname->Visible = true;
	lbl_department->Visible = true;
	lbl_email->Visible = true;
	lbl_company->Visible = true;
	lbl_telephone->Visible = true;

	tbx_firstname->Visible = true;
	tbx_lastname->Visible = true;
	tbx_department->Visible = true;
	tbx_email->Visible = true;
	tbx_company->Visible = true;
	tbx_phone->Visible = true;

	lbl_werk->Visible = true;
	lbl_ort->Visible = true;
	lbl_street->Visible = true;
	lbl_building->Visible = true;
	lbl_door->Visible = true;

	tbx_werk->Visible = true;
	tbx_ort->Visible = true;
	tbx_street->Visible = true;
	tbx_building->Visible = true;
	tbx_door->Visible = true;

	btn_cancel->Visible = true;
	btn_save_edit_delete->Visible = true;

	if ((sender == btn_editPerson) || (sender == btn_deletePerson))
	{
		lbx_Persons->Visible = true;
	}
	else
	{
		lbx_Persons->Visible = false;
	}
}
System::Void	Admin::hideItems						(System::Void){
	lbl_firstname->Visible = false;
	lbl_lastname->Visible = false;
	lbl_department->Visible = false;
	lbl_email->Visible = false;
	lbl_company->Visible = false;
	lbl_telephone->Visible = false;

	tbx_firstname->Visible = false;
	tbx_lastname->Visible = false;
	tbx_department->Visible = false;
	tbx_email->Visible = false;
	tbx_company->Visible = false;
	tbx_phone->Visible = false;

	lbl_werk->Visible = false;
	lbl_ort->Visible = false;
	lbl_street->Visible = false;
	lbl_building->Visible = false;
	lbl_door->Visible = false;

	tbx_werk->Visible = false;
	tbx_ort->Visible = false;
	tbx_street->Visible = false;
	tbx_building->Visible = false;
	tbx_door->Visible = false;

	btn_cancel->Visible = false;
	btn_save_edit_delete->Visible = false;

	lbx_Persons->Visible = false;
}
System::Void	Admin::clearItems						(System::Void) {
	tbx_firstname->Clear();
	tbx_lastname->Clear();
	tbx_department->Clear();
	tbx_email->Clear();
	tbx_company->Clear();
	tbx_phone->Clear();

	tbx_werk->Clear();
	tbx_ort->Clear();
	tbx_street->Clear();
	tbx_building->Clear();
	tbx_door->Clear();

	lbx_Persons->Items->Clear();
}

System::Void	Admin::loadPersonsIntoListBox			(System::Void) {
	std::fstream loadPerson;
	std::string lineText;
	std::string onePerson;
	bool nextPerson = false;
	int personIsDone = 0;

	loadPerson.open("Person.txt", std::ios::in);
	lbx_Persons->Items->Clear();
	if (!loadPerson) {
		MessageBox::Show("An Error has appeared.");
	}
	else
	{
		while (std::getline(loadPerson, lineText)) {
			if (nextPerson && personIsDone == 0) {
				onePerson += lineText + " ";
				personIsDone++;
			}
			else if (nextPerson && personIsDone == 1)
			{
				onePerson += lineText;
				personIsDone++;
			}
			if (personIsDone == 2) {
				lbx_Persons->Items->Add(this->string_to_String(onePerson));
				nextPerson = false;
				personIsDone = 0;
				onePerson.clear();
			}
			if (lineText == "####################") {
				nextPerson = true;
			}
		}
	}
	loadPerson.close();
	return System::Void();
}

//Edit the txt-files to add, edit, save and delete the addes persons
System::Void	Admin::addPerson						(System::Void){
	std::fstream savePerson;
	std::fstream saveStelle;

	savePerson.open("Person.txt", std::ios::app);
	saveStelle.open("Stelle.txt", std::ios::app);
	if (!savePerson)
	{
		MessageBox::Show("An Error has appeared.");
		savePerson.close();
	}
	else
	{
		savePerson << "####################\n";
		savePerson << this->String_to_string(tbx_firstname->Text) + "\n";
		savePerson << this->String_to_string(tbx_lastname->Text) + "\n";
		savePerson << this->String_to_string(tbx_department->Text) + "\n";
		savePerson << this->String_to_string(tbx_email->Text) + "\n";
		savePerson << this->String_to_string(tbx_company->Text) + "\n";
		savePerson << this->String_to_string(tbx_phone->Text) + "\n";
		saveStelle << "####################\n";
		saveStelle << this->String_to_string(tbx_werk->Text) + "\n";
		saveStelle << this->String_to_string(tbx_ort->Text) + "\n";
		saveStelle << this->String_to_string(tbx_street->Text) + "\n";
		saveStelle << this->String_to_string(tbx_building->Text) + "\n";
		saveStelle << this->String_to_string(tbx_door->Text) + "\n";
		MessageBox::Show("The Data for the person was created successfully.");
	}
	savePerson.close();
	saveStelle.close();
	return System::Void();
}
System::Void	Admin::editPerson						(System::Void){
	std::fstream editPerson;
	std::fstream editStelle;

	std::string lineTextPerson;
	std::string replaceTextPerson;
	std::string lineTextStelle;
	std::string replaceTextStelle;

	int personIndexFormListBox_Person = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 7;
	int personindexFormListBox_Stelle = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 6;
	int currentDataFromPerson = 1;

	editStelle.open("Stelle.txt", std::ios::in);
	editPerson.open("Person.txt", std::ios::in);
	if (!editPerson || !editStelle)
	{
		MessageBox::Show("An Error has appeared.");
	}
	else {
		//get the first line without changes
		for (int i = 0; i <= personIndexFormListBox_Person; i++)
		{
			if (std::getline(editPerson, lineTextPerson))
			{
				replaceTextPerson += lineTextPerson + "\n";
			}
		}

		for (int i = 0; i < personIndexFormListBox_Person; i++)
		{
			if (std::getline(editStelle, lineTextStelle))
			{
				replaceTextStelle += lineTextStelle + "\n";
			}
		}
		//change the persons details
		while (std::getline(editPerson, lineTextPerson))
		{
			if (lineTextPerson == "####################")
			{
				replaceTextPerson += lineTextPerson + "\n";
				break;
			}
			else {
				switch (currentDataFromPerson)
				{
				case 1:
					replaceTextPerson += this->String_to_string(tbx_firstname->Text) + "\n";
					break;
				case 2:
					replaceTextPerson += this->String_to_string(tbx_lastname->Text) + "\n";
					break;
				case 3:
					replaceTextPerson += this->String_to_string(tbx_department->Text) + "\n";
					break;
				case 4:
					replaceTextPerson += this->String_to_string(tbx_email->Text) + "\n";
					break;
				case 5:
					replaceTextPerson += this->String_to_string(tbx_company->Text) + "\n";
					break;
				case 6:
					replaceTextPerson += this->String_to_string(tbx_phone->Text) + "\n";
					break;
				default:
					break;
				}
				currentDataFromPerson++;
			}
		}

		currentDataFromPerson = 1;
		while (std::getline(editStelle, lineTextStelle))
		{
			if (lineTextStelle== "####################")
			{
				replaceTextStelle+= lineTextStelle+ "\n";
				break;
			}
			else {
				switch (currentDataFromPerson)
				{
				case 1:
					replaceTextStelle += this->String_to_string(tbx_werk->Text) + "\n";
					break;
				case 2:
					replaceTextStelle += this->String_to_string(tbx_ort->Text) + "\n";
					break;
				case 3:
					replaceTextStelle += this->String_to_string(tbx_street->Text) + "\n";
					break;
				case 4:
					replaceTextStelle += this->String_to_string(tbx_building->Text) + "\n";
					break;
				case 5:
					replaceTextStelle += this->String_to_string(tbx_door->Text) + "\n";
					break;
				default:
					break;
				}
				currentDataFromPerson++;
			}
		}
		//get the remaining details
		while (std::getline(editPerson, lineTextPerson))
		{
			replaceTextPerson += lineTextPerson + "\n";
		}

		while (std::getline(editStelle, lineTextStelle))
		{
			replaceTextStelle += lineTextStelle + "\n";
		}
	}
	editPerson.close();
	editStelle.close();

	editPerson.open("Person.txt", std::ios::out);
	editPerson << replaceTextPerson;
	editPerson.close();
	editStelle.open("Stelle.txt", std::ios::out);
	editStelle<< replaceTextStelle;
	editStelle.close();

	return System::Void();
}
System::Void	Admin::deletePerson						(System::Void){
	std::fstream deletePerson;
	std::fstream deleteStelle;

	std::string lineTextPerson;
	std::string replaceTextPerson;
	std::string lineTextStelle;
	std::string replaceTextStelle;

	int personIndexFormListBox_Person = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 7;
	int personIndexFormListBox_Stelle = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 6;
	int skipPersonData = 7;

	this->loadPersonsIntoListBox();
	deletePerson.open("Person.txt", std::ios::in);
	deleteStelle.open("Stelle.txt", std::ios::in);
	if (!deletePerson || !deleteStelle)
	{
		MessageBox::Show("An Error has appeared.");
	}
	else {
		//get the first line without changes
		for (int i = 0; i <= personIndexFormListBox_Person; i++)
		{
			if (std::getline(deletePerson, lineTextPerson))
			{
				replaceTextPerson += lineTextPerson + "\n";
			}
		}
		for (int i = 0; i <= personIndexFormListBox_Stelle; i++)
		{
			if (std::getline(deleteStelle, lineTextStelle))
			{
				replaceTextStelle += lineTextStelle + "\n";
			}
		}
		//change the persons details
		while (skipPersonData != 0)
		{
			skipPersonData--;
			std::getline(deletePerson, lineTextPerson);
		}
		skipPersonData = 7;
		while (skipPersonData != 0)
		{
			skipPersonData--;
			std::getline(deleteStelle, lineTextStelle);
		}
		//get the remaining details
		while (std::getline(deletePerson, lineTextPerson))
		{
			replaceTextPerson += lineTextPerson + "\n";
		}
		while (std::getline(deleteStelle, lineTextStelle))
		{
			replaceTextStelle+= lineTextStelle+ "\n";
		}
	}
	deletePerson.close();
	deleteStelle.close();

	deletePerson.open("Person.txt", std::ios::out);
	deletePerson << replaceTextPerson;
	deletePerson.close();

	deleteStelle.open("Stelle.txt", std::ios::out);
	deleteStelle << replaceTextStelle;
	deleteStelle.close();

	return System::Void();
}

System::Void	Admin::writeInPersonClass				(System::Void){
	return System::Void();
}

//Form functions
System::Void	Admin::btn_createPerson_Click			(System::Object^ sender, System::EventArgs^ e){
	btn_save_edit_delete->Text = "Create";
	showItems(sender);
}
System::Void	Admin::btn_editPerson_Click				(System::Object^ sender, System::EventArgs^ e){
	showItems(sender);
	btn_save_edit_delete->Text = "Edit";
	this->loadPersonsIntoListBox();
}
System::Void	Admin::btn_deletePerson_Click			(System::Object^ sender, System::EventArgs^ e){
	showItems(sender);
	btn_save_edit_delete->Text = "Delete";
	this->loadPersonsIntoListBox();
}

//To cancel or to save/edit/delete the persons data
System::Void	Admin::btn_cancel_Click					(System::Object^ sender, System::EventArgs^ e){
	this->clearItems();
	this->hideItems();
}
System::Void	Admin::btn_save_edit_delete_Click		(System::Object^ sender, System::EventArgs^ e) {
	if (btn_save_edit_delete->Text == "Create")
	{
		this->addPerson();
	}
	else if (btn_save_edit_delete->Text == "Edit")
	{
		this->editPerson();
		this->loadPersonsIntoListBox();
	}
	else if (btn_save_edit_delete->Text == "Delete")
	{
		this->deletePerson();
		this->loadPersonsIntoListBox();
	}
}

//Show the Data in the textboxes
System::Void	Admin::lbx_Persons_SelectedIndexChanged	(System::Object^ sender, System::EventArgs^ e)
{
	std::fstream loadPersonInformations;
	std::fstream loadStelleInformations;

	std::string lineTextPerson;
	std::string lineTextStelle;

	int personIndexFormListBox_Person = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 7;
	int personIndexFormListBox_Stelle = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 6;
	int currentDataFromPerson = 1;

	loadPersonInformations.open("Person.txt", std::ios::in);
	loadStelleInformations.open("Stelle.txt", std::ios::in);
	if (!loadPersonInformations || !loadStelleInformations)
	{
		MessageBox::Show("An Error has appeared.");
	}
	else {
		for (int i = 0; i <= personIndexFormListBox_Person; i++)
		{
			if (!std::getline(loadPersonInformations, lineTextPerson)) {
				//The first Person will be skipped
			}
		}
		for (int i = 0; i <= personIndexFormListBox_Stelle; i++)
		{
			if (!std::getline(loadStelleInformations, lineTextStelle)) {
				//The first Persons will be skipped
			}
		}
		while (std::getline(loadPersonInformations, lineTextPerson))
		{
			if (lineTextPerson == "####################")
			{
				break;
			}
			else {
				switch (currentDataFromPerson)
				{
				case 1:
					tbx_firstname->Text = this->string_to_String(lineTextPerson);
					break;
				case 2:
					tbx_lastname->Text = this->string_to_String(lineTextPerson);
					break;
				case 3:
					tbx_department->Text = this->string_to_String(lineTextPerson);
					break;
				case 4:
					tbx_email->Text = this->string_to_String(lineTextPerson);
					break;
				case 5:
					tbx_company->Text = this->string_to_String(lineTextPerson);
					break;
				case 6:
					tbx_phone->Text = this->string_to_String(lineTextPerson);
					break;
				default:
					break;
				}
				currentDataFromPerson++;
			}
		}
		currentDataFromPerson = 1;
		while (std::getline(loadStelleInformations, lineTextStelle))
		{
			if (lineTextStelle == "####################")
			{
				break;
			}
			else {
				switch (currentDataFromPerson)
				{
				case 1:
					tbx_werk->Text = this->string_to_String(lineTextStelle);
					break;
				case 2:
					tbx_ort->Text = this->string_to_String(lineTextStelle);
					break;
				case 3:
					tbx_street->Text = this->string_to_String(lineTextStelle);
					break;
				case 4:
					tbx_building->Text = this->string_to_String(lineTextStelle);
					break;
				case 5:
					tbx_door->Text = this->string_to_String(lineTextStelle);
					break;
				default:
					break;
				}
				currentDataFromPerson++;
			}
		}
	}
	loadPersonInformations.close();
	loadStelleInformations.close();
	return System::Void();
}
