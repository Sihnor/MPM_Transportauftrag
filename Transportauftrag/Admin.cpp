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
	tbx_firstname->Clear();
	tbx_lastname->Visible = false;
	tbx_lastname->Clear();
	tbx_department->Visible = false;
	tbx_department->Clear();
	tbx_email->Visible = false;
	tbx_email->Clear();
	tbx_company->Visible = false;
	tbx_company->Clear();
	tbx_phone->Visible = false;
	tbx_phone->Clear();

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
	savePerson.open("Person.txt", std::ios::app);
	
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
		MessageBox::Show("The Data for the person was created successfully.");
	}
	savePerson.close();
	return System::Void();
}
System::Void	Admin::editPerson						(System::Void){
	std::fstream editPerson;

	std::string lineText;
	std::string replaceText;

	int personIndexFormListBox = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 7;
	int currentDataFromPerson = 1;

	editPerson.open("Person.txt", std::ios::in);
	if (!editPerson)
	{
		MessageBox::Show("An Error has appeared.");
	}
	else {
		//get the first line without changes
		for (int i = 0; i <= personIndexFormListBox; i++)
		{
			if (std::getline(editPerson, lineText))
			{
				replaceText += lineText + "\n";
			}
		}
		//change the persons details
		while (std::getline(editPerson, lineText))
		{
			if (lineText == "####################")
			{
				replaceText += lineText + "\n";
				break;
			}
			else {
				switch (currentDataFromPerson)
				{
				case 1:
					replaceText += this->String_to_string(tbx_firstname->Text) + "\n";
					break;
				case 2:
					replaceText += this->String_to_string(tbx_lastname->Text) + "\n";
					break;
				case 3:
					replaceText += this->String_to_string(tbx_department->Text) + "\n";
					break;
				case 4:
					replaceText += this->String_to_string(tbx_email->Text) + "\n";
					break;
				case 5:
					replaceText += this->String_to_string(tbx_company->Text) + "\n";
					break;
				case 6:
					replaceText += this->String_to_string(tbx_phone->Text) + "\n";
					break;
				default:
					break;
				}
				currentDataFromPerson++;
			}
		}
		//get the remaining details
		while (std::getline(editPerson, lineText))
		{
			replaceText += lineText + "\n";
		}
	}
	editPerson.close();
	editPerson.open("Person.txt", std::ios::out);
	editPerson << replaceText;
	editPerson.close();
	return System::Void();
}
System::Void	Admin::deletePerson						(System::Void){
	std::fstream deletePerson;

	std::string lineText;
	std::string replaceText;

	int personIndexFormListBox = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 7;
	int skipPersonData = 7;

	this->loadPersonsIntoListBox();
	deletePerson.open("Person.txt", std::ios::in);
	if (!deletePerson)
	{
		MessageBox::Show("An Error has appeared.");
	}
	else {
		//get the first line without changes
		for (int i = 0; i <= personIndexFormListBox; i++)
		{
			if (std::getline(deletePerson, lineText))
			{
				replaceText += lineText + "\n";
			}
		}
		//change the persons details
		while (skipPersonData != 0)
		{
			skipPersonData--;
			std::getline(deletePerson, lineText);
		}
		//get the remaining details
		while (std::getline(deletePerson, lineText))
		{
			replaceText += lineText + "\n";
		}
	}
	deletePerson.close();
	deletePerson.open("Person.txt", std::ios::out);
	deletePerson << replaceText;
	deletePerson.close();
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
	hideItems();
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
	std::string lineText;
	int personIndexFormListBox = lbx_Persons->Items->IndexOf(lbx_Persons->SelectedItem) * 7;
	int currentDataFromPerson = 1;

	loadPersonInformations.open("Person.txt", std::ios::in);
	if (!loadPersonInformations)
	{
		MessageBox::Show("An Error has appeared.");
	}
	else {
		for (int i = 0; i <= personIndexFormListBox; i++)
		{
			if (!std::getline(loadPersonInformations, lineText)) {
				//The first Person will be skipped
			}
		}
		while (std::getline(loadPersonInformations, lineText))
		{
			if (lineText == "####################")
			{
				break;
			}
			else {
				switch (currentDataFromPerson)
				{
				case 1:
					tbx_firstname->Text = this->string_to_String(lineText);
					break;
				case 2:
					tbx_lastname->Text = this->string_to_String(lineText);
					break;
				case 3:
					tbx_department->Text = this->string_to_String(lineText);
					break;
				case 4:
					tbx_email->Text = this->string_to_String(lineText);
					break;
				case 5:
					tbx_company->Text = this->string_to_String(lineText);
					break;
				case 6:
					tbx_phone->Text = this->string_to_String(lineText);
					break;
				default:
					break;
				}
				currentDataFromPerson++;
			}
		}
	}
	return System::Void();
}
