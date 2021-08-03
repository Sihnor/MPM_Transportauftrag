#pragma once
#include <string>
#include "Admin.h"

namespace Transportauftrag {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Haupt : public System::Windows::Forms::Form
	{
	public:
		Haupt(void)	{
			InitializeComponent();
		}
	protected:
		~Haupt() {
			if (components)	{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ lbx_Auftraggeber;

	private: System::Windows::Forms::CheckBox^ cbx_betriebsstoerung;
	private: System::Windows::Forms::NumericUpDown^ nud_klasse;
	private: System::Windows::Forms::ComboBox^ combobx_Klasse;
	private: System::Windows::Forms::CheckBox^ cbx_sicherheit;
	private: System::Windows::Forms::TextBox^ tbx_Sicherheit;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btn_admin;
	private: System::Windows::Forms::ListBox^ lbx_Auftragnehmer;

	private:
		System::ComponentModel::Container ^components;
		std::string to_string(System::String^ s_);
		System::String^ to_String(std::string s_);

#pragma region
		void InitializeComponent(void) {
			this->lbx_Auftraggeber = (gcnew System::Windows::Forms::ListBox());
			this->cbx_betriebsstoerung = (gcnew System::Windows::Forms::CheckBox());
			this->nud_klasse = (gcnew System::Windows::Forms::NumericUpDown());
			this->combobx_Klasse = (gcnew System::Windows::Forms::ComboBox());
			this->cbx_sicherheit = (gcnew System::Windows::Forms::CheckBox());
			this->tbx_Sicherheit = (gcnew System::Windows::Forms::TextBox());
			this->btn_admin = (gcnew System::Windows::Forms::Button());
			this->lbx_Auftragnehmer = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_klasse))->BeginInit();
			this->SuspendLayout();
			// 
			// lbx_Auftraggeber
			// 
			this->lbx_Auftraggeber->FormattingEnabled = true;
			this->lbx_Auftraggeber->ItemHeight = 16;
			this->lbx_Auftraggeber->Location = System::Drawing::Point(12, 12);
			this->lbx_Auftraggeber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lbx_Auftraggeber->Name = L"lbx_Auftraggeber";
			this->lbx_Auftraggeber->Size = System::Drawing::Size(136, 180);
			this->lbx_Auftraggeber->TabIndex = 0;
			// 
			// cbx_betriebsstoerung
			// 
			this->cbx_betriebsstoerung->AutoSize = true;
			this->cbx_betriebsstoerung->Location = System::Drawing::Point(12, 198);
			this->cbx_betriebsstoerung->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cbx_betriebsstoerung->Name = L"cbx_betriebsstoerung";
			this->cbx_betriebsstoerung->Size = System::Drawing::Size(130, 21);
			this->cbx_betriebsstoerung->TabIndex = 2;
			this->cbx_betriebsstoerung->Text = L"Betriebsstörung";
			this->cbx_betriebsstoerung->UseVisualStyleBackColor = true;
			// 
			// nud_klasse
			// 
			this->nud_klasse->Location = System::Drawing::Point(183, 363);
			this->nud_klasse->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->nud_klasse->Name = L"nud_klasse";
			this->nud_klasse->Size = System::Drawing::Size(136, 22);
			this->nud_klasse->TabIndex = 3;
			// 
			// combobx_Klasse
			// 
			this->combobx_Klasse->FormattingEnabled = true;
			this->combobx_Klasse->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Klasse 0", L"Klasse 1", L"Klasse 2", L"Klasse 3",
					L"Klasse 4"
			});
			this->combobx_Klasse->Location = System::Drawing::Point(12, 362);
			this->combobx_Klasse->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->combobx_Klasse->Name = L"combobx_Klasse";
			this->combobx_Klasse->Size = System::Drawing::Size(136, 24);
			this->combobx_Klasse->TabIndex = 4;
			this->combobx_Klasse->Text = L"Klasse 0";
			// 
			// cbx_sicherheit
			// 
			this->cbx_sicherheit->AutoSize = true;
			this->cbx_sicherheit->Location = System::Drawing::Point(12, 414);
			this->cbx_sicherheit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cbx_sicherheit->Name = L"cbx_sicherheit";
			this->cbx_sicherheit->Size = System::Drawing::Size(129, 21);
			this->cbx_sicherheit->TabIndex = 5;
			this->cbx_sicherheit->Text = L"Sicherheitsfahrt";
			this->cbx_sicherheit->UseVisualStyleBackColor = true;
			// 
			// tbx_Sicherheit
			// 
			this->tbx_Sicherheit->Location = System::Drawing::Point(147, 411);
			this->tbx_Sicherheit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tbx_Sicherheit->Name = L"tbx_Sicherheit";
			this->tbx_Sicherheit->Size = System::Drawing::Size(376, 22);
			this->tbx_Sicherheit->TabIndex = 6;
			this->tbx_Sicherheit->Visible = false;
			// 
			// btn_admin
			// 
			this->btn_admin->Location = System::Drawing::Point(232, 165);
			this->btn_admin->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btn_admin->Name = L"btn_admin";
			this->btn_admin->Size = System::Drawing::Size(100, 28);
			this->btn_admin->TabIndex = 7;
			this->btn_admin->Text = L"ADMIN";
			this->btn_admin->UseVisualStyleBackColor = true;
			this->btn_admin->Click += gcnew System::EventHandler(this, &Haupt::btn_admin_Click);
			// 
			// lbx_Auftragnehmer
			// 
			this->lbx_Auftragnehmer->FormattingEnabled = true;
			this->lbx_Auftragnehmer->ItemHeight = 16;
			this->lbx_Auftragnehmer->Location = System::Drawing::Point(387, 12);
			this->lbx_Auftragnehmer->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lbx_Auftragnehmer->Name = L"lbx_Auftragnehmer";
			this->lbx_Auftragnehmer->Size = System::Drawing::Size(136, 180);
			this->lbx_Auftragnehmer->TabIndex = 1;
			// 
			// Haupt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 446);
			this->Controls->Add(this->btn_admin);
			this->Controls->Add(this->tbx_Sicherheit);
			this->Controls->Add(this->cbx_sicherheit);
			this->Controls->Add(this->combobx_Klasse);
			this->Controls->Add(this->nud_klasse);
			this->Controls->Add(this->cbx_betriebsstoerung);
			this->Controls->Add(this->lbx_Auftragnehmer);
			this->Controls->Add(this->lbx_Auftraggeber);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Haupt";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_klasse))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ admin = gcnew Transportauftrag_Admin::Admin();
		admin->Show();
	}
	private: System::Void btn_admin_Click(System::Object^ sender, System::EventArgs^ e);
};

}
