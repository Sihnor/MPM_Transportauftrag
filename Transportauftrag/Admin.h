#pragma once
#include <string>

namespace Transportauftrag_Admin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(void)	{
			InitializeComponent();
		}
	protected:
		~Admin() {
			if (components)	{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Button^		btn_createPerson;
		System::Windows::Forms::Button^		btn_editPerson;
		System::Windows::Forms::Button^		btn_save_edit_delete;
		System::Windows::Forms::Button^		btn_cancel;
		System::Windows::Forms::TextBox^	tbx_firstname;
		System::Windows::Forms::TextBox^	tbx_lastname;
		System::Windows::Forms::TextBox^	tbx_department;
		System::Windows::Forms::TextBox^	tbx_email;
		System::Windows::Forms::TextBox^	tbx_company;
		System::Windows::Forms::TextBox^	tbx_phone;
		System::Windows::Forms::Label^		lbl_firstname;
		System::Windows::Forms::Label^		lbl_lastname;
		System::Windows::Forms::Label^		lbl_department;
		System::Windows::Forms::Label^		lbl_email;
		System::Windows::Forms::Label^		lbl_company;
		System::Windows::Forms::Label^		lbl_telephone;
		System::Windows::Forms::Button^		btn_deletePerson;
		System::Windows::Forms::ListBox^	lbx_Persons;

		System::ComponentModel::Container ^components;
		std::string		String_to_string					(System::String^ text_);
		System::String^ string_to_String					(std::string text_);

#pragma region 
		void			InitializeComponent					(void) {
			this->btn_createPerson = (gcnew System::Windows::Forms::Button());
			this->btn_editPerson = (gcnew System::Windows::Forms::Button());
			this->btn_save_edit_delete = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->tbx_firstname = (gcnew System::Windows::Forms::TextBox());
			this->tbx_lastname = (gcnew System::Windows::Forms::TextBox());
			this->tbx_department = (gcnew System::Windows::Forms::TextBox());
			this->tbx_email = (gcnew System::Windows::Forms::TextBox());
			this->tbx_company = (gcnew System::Windows::Forms::TextBox());
			this->tbx_phone = (gcnew System::Windows::Forms::TextBox());
			this->lbl_firstname = (gcnew System::Windows::Forms::Label());
			this->lbl_lastname = (gcnew System::Windows::Forms::Label());
			this->lbl_department = (gcnew System::Windows::Forms::Label());
			this->lbl_email = (gcnew System::Windows::Forms::Label());
			this->lbl_company = (gcnew System::Windows::Forms::Label());
			this->lbl_telephone = (gcnew System::Windows::Forms::Label());
			this->btn_deletePerson = (gcnew System::Windows::Forms::Button());
			this->lbx_Persons = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btn_createPerson
			// 
			this->btn_createPerson->Location = System::Drawing::Point(12, 12);
			this->btn_createPerson->Name = L"btn_createPerson";
			this->btn_createPerson->Size = System::Drawing::Size(101, 46);
			this->btn_createPerson->TabIndex = 1;
			this->btn_createPerson->Text = L"Create New Person";
			this->btn_createPerson->UseVisualStyleBackColor = true;
			this->btn_createPerson->Click += gcnew System::EventHandler(this, &Admin::btn_createPerson_Click);
			// 
			// btn_editPerson
			// 
			this->btn_editPerson->Location = System::Drawing::Point(12, 64);
			this->btn_editPerson->Name = L"btn_editPerson";
			this->btn_editPerson->Size = System::Drawing::Size(101, 46);
			this->btn_editPerson->TabIndex = 2;
			this->btn_editPerson->Text = L"Edit Existing Person";
			this->btn_editPerson->UseVisualStyleBackColor = true;
			this->btn_editPerson->Click += gcnew System::EventHandler(this, &Admin::btn_editPerson_Click);
			// 
			// btn_save_edit_delete
			// 
			this->btn_save_edit_delete->Location = System::Drawing::Point(432, 190);
			this->btn_save_edit_delete->Name = L"btn_save_edit_delete";
			this->btn_save_edit_delete->Size = System::Drawing::Size(75, 23);
			this->btn_save_edit_delete->TabIndex = 3;
			this->btn_save_edit_delete->Text = L"Save";
			this->btn_save_edit_delete->UseVisualStyleBackColor = true;
			this->btn_save_edit_delete->Visible = false;
			this->btn_save_edit_delete->Click += gcnew System::EventHandler(this, &Admin::btn_save_edit_delete_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->Location = System::Drawing::Point(322, 190);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 4;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Visible = false;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &Admin::btn_cancel_Click);
			// 
			// tbx_firstname
			// 
			this->tbx_firstname->Location = System::Drawing::Point(322, 24);
			this->tbx_firstname->Name = L"tbx_firstname";
			this->tbx_firstname->Size = System::Drawing::Size(185, 20);
			this->tbx_firstname->TabIndex = 5;
			this->tbx_firstname->Visible = false;
			// 
			// tbx_lastname
			// 
			this->tbx_lastname->Location = System::Drawing::Point(322, 52);
			this->tbx_lastname->Name = L"tbx_lastname";
			this->tbx_lastname->Size = System::Drawing::Size(185, 20);
			this->tbx_lastname->TabIndex = 6;
			this->tbx_lastname->Visible = false;
			// 
			// tbx_department
			// 
			this->tbx_department->Location = System::Drawing::Point(322, 80);
			this->tbx_department->Name = L"tbx_department";
			this->tbx_department->Size = System::Drawing::Size(185, 20);
			this->tbx_department->TabIndex = 7;
			this->tbx_department->Visible = false;
			// 
			// tbx_email
			// 
			this->tbx_email->Location = System::Drawing::Point(322, 108);
			this->tbx_email->Name = L"tbx_email";
			this->tbx_email->Size = System::Drawing::Size(185, 20);
			this->tbx_email->TabIndex = 8;
			this->tbx_email->Visible = false;
			// 
			// tbx_company
			// 
			this->tbx_company->Location = System::Drawing::Point(322, 136);
			this->tbx_company->Name = L"tbx_company";
			this->tbx_company->Size = System::Drawing::Size(185, 20);
			this->tbx_company->TabIndex = 9;
			this->tbx_company->Visible = false;
			// 
			// tbx_phone
			// 
			this->tbx_phone->Location = System::Drawing::Point(322, 164);
			this->tbx_phone->Name = L"tbx_phone";
			this->tbx_phone->Size = System::Drawing::Size(185, 20);
			this->tbx_phone->TabIndex = 10;
			this->tbx_phone->Visible = false;
			// 
			// lbl_firstname
			// 
			this->lbl_firstname->AutoSize = true;
			this->lbl_firstname->Location = System::Drawing::Point(228, 29);
			this->lbl_firstname->Name = L"lbl_firstname";
			this->lbl_firstname->Size = System::Drawing::Size(49, 13);
			this->lbl_firstname->TabIndex = 11;
			this->lbl_firstname->Text = L"Vorname";
			this->lbl_firstname->Visible = false;
			// 
			// lbl_lastname
			// 
			this->lbl_lastname->AutoSize = true;
			this->lbl_lastname->Location = System::Drawing::Point(228, 55);
			this->lbl_lastname->Name = L"lbl_lastname";
			this->lbl_lastname->Size = System::Drawing::Size(59, 13);
			this->lbl_lastname->TabIndex = 12;
			this->lbl_lastname->Text = L"Nachname";
			this->lbl_lastname->Visible = false;
			// 
			// lbl_department
			// 
			this->lbl_department->AutoSize = true;
			this->lbl_department->Location = System::Drawing::Point(228, 83);
			this->lbl_department->Name = L"lbl_department";
			this->lbl_department->Size = System::Drawing::Size(51, 13);
			this->lbl_department->TabIndex = 13;
			this->lbl_department->Text = L"Abteilung";
			this->lbl_department->Visible = false;
			// 
			// lbl_email
			// 
			this->lbl_email->AutoSize = true;
			this->lbl_email->Location = System::Drawing::Point(228, 111);
			this->lbl_email->Name = L"lbl_email";
			this->lbl_email->Size = System::Drawing::Size(36, 13);
			this->lbl_email->TabIndex = 14;
			this->lbl_email->Text = L"E-Mail";
			this->lbl_email->Visible = false;
			// 
			// lbl_company
			// 
			this->lbl_company->AutoSize = true;
			this->lbl_company->Location = System::Drawing::Point(228, 139);
			this->lbl_company->Name = L"lbl_company";
			this->lbl_company->Size = System::Drawing::Size(32, 13);
			this->lbl_company->TabIndex = 15;
			this->lbl_company->Text = L"Firma";
			this->lbl_company->Visible = false;
			// 
			// lbl_telephone
			// 
			this->lbl_telephone->AutoSize = true;
			this->lbl_telephone->Location = System::Drawing::Point(228, 167);
			this->lbl_telephone->Name = L"lbl_telephone";
			this->lbl_telephone->Size = System::Drawing::Size(43, 13);
			this->lbl_telephone->TabIndex = 16;
			this->lbl_telephone->Text = L"Telefon";
			this->lbl_telephone->Visible = false;
			// 
			// btn_deletePerson
			// 
			this->btn_deletePerson->Location = System::Drawing::Point(12, 116);
			this->btn_deletePerson->Name = L"btn_deletePerson";
			this->btn_deletePerson->Size = System::Drawing::Size(101, 46);
			this->btn_deletePerson->TabIndex = 17;
			this->btn_deletePerson->Text = L"Delete Person";
			this->btn_deletePerson->UseVisualStyleBackColor = true;
			this->btn_deletePerson->Click += gcnew System::EventHandler(this, &Admin::btn_deletePerson_Click);
			// 
			// lbx_Persons
			// 
			this->lbx_Persons->FormattingEnabled = true;
			this->lbx_Persons->Location = System::Drawing::Point(12, 221);
			this->lbx_Persons->Name = L"lbx_Persons";
			this->lbx_Persons->Size = System::Drawing::Size(495, 199);
			this->lbx_Persons->TabIndex = 18;
			this->lbx_Persons->Visible = false;
			this->lbx_Persons->SelectedValueChanged += gcnew System::EventHandler(this, &Admin::lbx_Persons_SelectedValueChanged);
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(522, 443);
			this->Controls->Add(this->lbx_Persons);
			this->Controls->Add(this->btn_deletePerson);
			this->Controls->Add(this->lbl_telephone);
			this->Controls->Add(this->lbl_company);
			this->Controls->Add(this->lbl_email);
			this->Controls->Add(this->lbl_department);
			this->Controls->Add(this->lbl_lastname);
			this->Controls->Add(this->lbl_firstname);
			this->Controls->Add(this->tbx_phone);
			this->Controls->Add(this->tbx_company);
			this->Controls->Add(this->tbx_email);
			this->Controls->Add(this->tbx_department);
			this->Controls->Add(this->tbx_lastname);
			this->Controls->Add(this->tbx_firstname);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->btn_save_edit_delete);
			this->Controls->Add(this->btn_editPerson);
			this->Controls->Add(this->btn_createPerson);
			this->Name = L"Admin";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::Void	showItems							(System::Object^ sender);
		System::Void	hideItems							(System::Void);
		System::Void	clearItems							(System::Void);
		System::Void	addPerson							(System::Void);
		System::Void	editPerson							(System::Void);
		System::Void	deletePerson						(System::Void);
		System::Void	writeInPersonClass					(System::Void);
		System::Void	loadPersonsIntoListBox				(System::Void);
#pragma endregion
		System::Void	btn_editPerson_Click				(System::Object^ sender, System::EventArgs^ e);
		System::Void	btn_createPerson_Click				(System::Object^ sender, System::EventArgs^ e);
		System::Void	btn_deletePerson_Click				(System::Object^ sender, System::EventArgs^ e);
		System::Void	btn_cancel_Click					(System::Object^ sender, System::EventArgs^ e);
		System::Void	btn_save_edit_delete_Click			(System::Object^ sender, System::EventArgs^ e);
		System::Void	lbx_Persons_SelectedValueChanged	(System::Object^ sender, System::EventArgs^ e);
};
}
