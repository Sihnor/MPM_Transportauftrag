#include "pch.h"
#include "Admin.h"
#include "Klasse.h"
#include <fstream>

#include <Windows.h>
#include <lmcons.h>

using namespace Transportauftrag_Admin;

std::string		Admin::String_to_string				(System::String^ text_) {	
	std::string s;

	for (int i = 0; i < text_->Length; i++)
		s += text_[i];
	return s;
}

System::String^ Admin::string_to_String				(std::string text_)
{
	return gcnew String(text_.c_str());
}

System::Void	Admin::showItems					(System::Object^ sender)
{
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

System::Void	Admin::hideItems					(System::Void)
{
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

System::Void	Admin::saveToFile					(System::Void){
	std::fstream savePerson;
	savePerson.open("Person.txt", std::ios::app);
	
	if (!savePerson)
	{
		MessageBox::Show("Fehler beim Öffnen");
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
		MessageBox::Show("Es wurde die Person ERFOLGREICH erstellt.");
	}
	savePerson.close();
	return System::Void();
}

System::Void	Admin::editFromFile(System::Void)
{
	return System::Void();
}

System::Void	Admin::deleteFromFile				(System::Void)
{
	return System::Void();
}

System::Void	Admin::writeInPersonClass			(System::Void)
{
	return System::Void();
}

System::Void	Admin::btn_createPerson_Click		(System::Object^ sender, System::EventArgs^ e)
{
	btn_save_edit_delete->Text = "Create";
	showItems(sender);
}

System::Void	Admin::tbn_editPerson_Click			(System::Object^ sender, System::EventArgs^ e)
{
	btn_save_edit_delete->Text = "Edit";
	showItems(sender);
}

System::Void	Admin::btn_deletePerson_Click		(System::Object^ sender, System::EventArgs^ e)
{
	//Zeigt den derzeitigen Benutzer an
	//MessageBox::Show(System::Environment::UserName);
	btn_save_edit_delete->Text = "Delete";
	showItems(sender);
	return System::Void();
}

System::Void	Admin::btn_cancel_Click				(System::Object^ sender, System::EventArgs^ e)
{
	hideItems();
}

System::Void	Admin::btn_save_edit_delete_Click	(System::Object^ sender, System::EventArgs^ e) {
	if (btn_save_edit_delete->Text == "Create")
	{
		this->saveToFile();
	}
	else if (btn_save_edit_delete->Text == "Edit")
	{
		this->editFromFile();
	}
	else if (btn_save_edit_delete->Text == "Delete")
	{
		this->deleteFromFile();
	}
}
