#include "pch.h"
#include "Admin.h"
#include <fstream>

#include <iostream>
#include <Windows.h>
#include <lmcons.h>

std::string Transportauftrag_Admin::Admin::to_string(System::String^ s_) {
	std::string s;
	for (int i = 0; i < s_->Length; i++)
		s += s_[i];
	return s;
}

System::String^ Transportauftrag_Admin::Admin::to_String(std::string s_)
{
	throw gcnew System::NotImplementedException();
	return gcnew System::String(s_.c_str());
}

const char* Transportauftrag_Admin::Admin::String_to_file(System::String^ text_) {
	const char* Text[7];
	for (int i = 0; i < text_->Length; i++)
	{
		Text += text_[i];
		MessageBox::Show(Convert::ToString(Text));
	}
	return Text;
}

System::String^ Transportauftrag_Admin::Admin::file_to_String(const char* text_)
{
	return gcnew System::String(text_);
}

System::Void Transportauftrag_Admin::Admin::showItems(System::Void)
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
	btn_save->Visible = true;
}

System::Void Transportauftrag_Admin::Admin::hideItems(System::Void)
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
	btn_save->Visible = false;
}

System::Void Transportauftrag_Admin::Admin::tbn_editPerson_Click(System::Object^ sender, System::EventArgs^ e)
{
}

System::Void Transportauftrag_Admin::Admin::btn_createPerson_Click(System::Object^ sender, System::EventArgs^ e)
{
	showItems();
}

System::Void Transportauftrag_Admin::Admin::btn_deletePerson_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show(System::Environment::UserName);
	return System::Void();
}

System::Void Transportauftrag_Admin::Admin::btn_cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	hideItems();
}

System::Void Transportauftrag_Admin::Admin::btn_save_Click(System::Object^ sender, System::EventArgs^ e) {
	std::fstream savePerson(R"(C:\Users\Marcel\source\repos\Transportauftrag\Dokumente\Person.txt)", std::ios::out);
	

	//savePerson.open(R"(C:\Users\Marcel\source\repos\Transportauftrag\Dokumente\Person.txt)");
	if (!savePerson)
	{
		MessageBox::Show("Fehler beim Öffnen");
		savePerson.close();
	}
	else
	{//std::ios::binary | 
		//savePerson.write(to_string(tbx_firstname->Text).c_str(), tbx_firstname->Text->Length);
		//MessageBox::Show(Convert::ToString(tbx_firstname->Text->Length));
		savePerson.write(String_to_file(tbx_firstname->Text), tbx_firstname->Text->Length);
		savePerson.write("\r\n", sizeof(bool));
		savePerson.write(to_string(tbx_lastname->Text).c_str(), tbx_lastname->Text->Length);
		savePerson.write("\r\n", sizeof(bool));
		savePerson.write(to_string(tbx_department->Text).c_str(), tbx_department->Text->Length);
		savePerson.write("\r\n", sizeof(bool));
		savePerson.write(to_string(tbx_email->Text).c_str(), tbx_email->Text->Length);
		savePerson.write("\r\n", sizeof(bool));
		savePerson.write(to_string(tbx_company->Text).c_str(), tbx_company->Text->Length);
		savePerson.write("\r\n", sizeof(bool));
		savePerson.write(to_string(tbx_phone->Text).c_str(), tbx_phone->Text->Length);
		savePerson.write("\n---------------------------------------", 40);
	}
	savePerson.close();
	
}
