#include "pch.h"
#include "Transportauftrag.h"

std::string Transportauftrag::Haupt::to_string(System::String^ s_) {
    std::string s;
    for (int i = 0; i < s_->Length; i++)
        s += s_[i];
    return s;
}

System::String^ Transportauftrag::Haupt::to_String(std::string s_) {
    return gcnew System::String(s_.c_str());
}

System::Void Transportauftrag::Haupt::btn_admin_Click(System::Object^ sender, System::EventArgs^ e)
{
    Form^ admin = gcnew Transportauftrag_Admin::Admin();;
    admin->Show();
    return System::Void();
}
