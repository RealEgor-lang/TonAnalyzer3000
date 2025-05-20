#pragma once

#include "frmAbout.h"
#include "ToneAnalysis.h"
#include "vcclr.h"

namespace OSmetod {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Runtime::InteropServices;

    public ref class frmMain : public System::Windows::Forms::Form
    {
    public:
        frmMain(void)
        {
            InitializeComponent();
        }

    protected:
        ~frmMain()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::MenuStrip^ mnsMain;
    private: System::Windows::Forms::ToolStripMenuItem^ tmsiInfo;
    private: System::Windows::Forms::ToolStripMenuItem^ tmsiAbout;
    private: System::Windows::Forms::ToolStrip^ tsMain;
    private: System::Windows::Forms::ToolStripButton^ tsbExecute;
    private: System::Windows::Forms::ToolStripButton^ tsbAbout;
    private: System::Windows::Forms::ToolStripButton^ tsbInfo;
    private: System::Windows::Forms::ImageList^ imageList1;
    private: System::Windows::Forms::StatusStrip^ stMain;
    private: System::Windows::Forms::ToolStripStatusLabel^ tslInfo;
    private: System::Windows::Forms::ToolStripProgressBar^ tspMain;
    private: System::Windows::Forms::SplitContainer^ scMain;
    private: System::Windows::Forms::TextBox^ txtInput;
    private: System::Windows::Forms::TextBox^ txtResult;
    private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
               this->mnsMain = (gcnew System::Windows::Forms::MenuStrip());
               this->tmsiInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->tmsiAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
               this->tsMain = (gcnew System::Windows::Forms::ToolStrip());
               this->tsbExecute = (gcnew System::Windows::Forms::ToolStripButton());
               this->tsbAbout = (gcnew System::Windows::Forms::ToolStripButton());
               this->tsbInfo = (gcnew System::Windows::Forms::ToolStripButton());
               this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
               this->stMain = (gcnew System::Windows::Forms::StatusStrip());
               this->tslInfo = (gcnew System::Windows::Forms::ToolStripStatusLabel());
               this->tspMain = (gcnew System::Windows::Forms::ToolStripProgressBar());
               this->scMain = (gcnew System::Windows::Forms::SplitContainer());
               this->txtInput = (gcnew System::Windows::Forms::TextBox());
               this->txtResult = (gcnew System::Windows::Forms::TextBox());
               this->mnsMain->SuspendLayout();
               this->tsMain->SuspendLayout();
               this->stMain->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scMain))->BeginInit();
               this->scMain->Panel1->SuspendLayout();
               this->scMain->Panel2->SuspendLayout();
               this->scMain->SuspendLayout();
               this->SuspendLayout();
               // 
               // mnsMain
               // 
               this->mnsMain->ImageScalingSize = System::Drawing::Size(20, 20);
               this->mnsMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tmsiInfo });
               this->mnsMain->Location = System::Drawing::Point(0, 0);
               this->mnsMain->Name = L"mnsMain";
               this->mnsMain->Size = System::Drawing::Size(860, 28);
               this->mnsMain->TabIndex = 0;
               this->mnsMain->Text = L"menuStrip1";
               // 
               // tmsiInfo
               // 
               this->tmsiInfo->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tmsiAbout });
               this->tmsiInfo->Name = L"tmsiInfo";
               this->tmsiInfo->Size = System::Drawing::Size(104, 24);
               this->tmsiInfo->Text = L"Інформація";
               // 
               // tmsiAbout
               // 
               this->tmsiAbout->Name = L"tmsiAbout";
               this->tmsiAbout->Size = System::Drawing::Size(193, 26);
               this->tmsiAbout->Text = L"Про програму";
               this->tmsiAbout->Click += gcnew System::EventHandler(this, &frmMain::tmsiAbout_Click);
               // 
               // tsMain
               // 
               this->tsMain->ImageScalingSize = System::Drawing::Size(32, 32);
               this->tsMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) { this->tsbExecute, this->tsbAbout, this->tsbInfo });
               this->tsMain->Location = System::Drawing::Point(0, 28);
               this->tsMain->Name = L"tsMain";
               this->tsMain->Size = System::Drawing::Size(860, 39);
               this->tsMain->TabIndex = 1;
               // 
               // tsbExecute
               // 
               this->tsbExecute->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
               this->tsbExecute->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbExecute.Image")));
               this->tsbExecute->ImageTransparentColor = System::Drawing::Color::Magenta;
               this->tsbExecute->Name = L"tsbExecute";
               this->tsbExecute->Size = System::Drawing::Size(36, 36);
               this->tsbExecute->Text = L"toolStripButton5";
               this->tsbExecute->Click += gcnew System::EventHandler(this, &frmMain::tsbExecute_Click);
               // 
               // tsbAbout
               // 
               this->tsbAbout->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
               this->tsbAbout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbAbout.Image")));
               this->tsbAbout->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
               this->tsbAbout->ImageTransparentColor = System::Drawing::Color::Magenta;
               this->tsbAbout->Name = L"tsbAbout";
               this->tsbAbout->Size = System::Drawing::Size(36, 36);
               this->tsbAbout->Text = L"toolStripButton1";
               this->tsbAbout->Click += gcnew System::EventHandler(this, &frmMain::tmsiAbout_Click);
               // 
               // tsbInfo
               // 
               this->tsbInfo->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
               this->tsbInfo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsbInfo.Image")));
               this->tsbInfo->ImageTransparentColor = System::Drawing::Color::Magenta;
               this->tsbInfo->Name = L"tsbInfo";
               this->tsbInfo->Size = System::Drawing::Size(36, 36);
               this->tsbInfo->Text = L"Info";
               this->tsbInfo->Click += gcnew System::EventHandler(this, &frmMain::tsbInfo_Click);
               // 
               // imageList1
               // 
               this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
               this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
               this->imageList1->Images->SetKeyName(0, L"control_play_blue.png");
               this->imageList1->Images->SetKeyName(1, L"information.png");
               // 
               // stMain
               // 
               this->stMain->ImageScalingSize = System::Drawing::Size(20, 20);
               this->stMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->tslInfo, this->tspMain });
               this->stMain->Location = System::Drawing::Point(0, 593);
               this->stMain->Name = L"stMain";
               this->stMain->Padding = System::Windows::Forms::Padding(1, 0, 19, 0);
               this->stMain->Size = System::Drawing::Size(860, 26);
               this->stMain->TabIndex = 2;
               this->stMain->Text = L"statusStrip1";
               // 
               // tslInfo
               // 
               this->tslInfo->AutoSize = false;
               this->tslInfo->Name = L"tslInfo";
               this->tslInfo->Size = System::Drawing::Size(120, 20);
               this->tslInfo->Text = L"Інформація";
               this->tslInfo->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
               // 
               // tspMain
               // 
               this->tspMain->Name = L"tspMain";
               this->tspMain->Size = System::Drawing::Size(133, 18);
               // 
               // scMain
               // 
               this->scMain->Dock = System::Windows::Forms::DockStyle::Fill;
               this->scMain->Location = System::Drawing::Point(0, 67);
               this->scMain->Margin = System::Windows::Forms::Padding(4);
               this->scMain->Name = L"scMain";
               this->scMain->Panel1->Controls->Add(this->txtInput);
               this->scMain->Panel2->Controls->Add(this->txtResult);
               this->scMain->Size = System::Drawing::Size(860, 526);
               this->scMain->SplitterDistance = 420;
               this->scMain->SplitterWidth = 5;
               this->scMain->TabIndex = 8;
               // 
               // txtInput
               // 
               this->txtInput->Dock = System::Windows::Forms::DockStyle::Fill;
               this->txtInput->Location = System::Drawing::Point(0, 0);
               this->txtInput->Multiline = true;
               this->txtInput->Name = L"txtInput";
               this->txtInput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
               this->txtInput->Size = System::Drawing::Size(420, 526);
               this->txtInput->TabIndex = 0;
               // 
               // txtResult
               // 
               this->txtResult->Dock = System::Windows::Forms::DockStyle::Fill;
               this->txtResult->Location = System::Drawing::Point(0, 0);
               this->txtResult->Multiline = true;
               this->txtResult->Name = L"txtResult";
               this->txtResult->ReadOnly = true;
               this->txtResult->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
               this->txtResult->Size = System::Drawing::Size(435, 526);
               this->txtResult->TabIndex = 1;
               // 
               // frmMain
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(860, 619);
               this->Controls->Add(this->scMain);
               this->Controls->Add(this->stMain);
               this->Controls->Add(this->tsMain);
               this->Controls->Add(this->mnsMain);
               this->MainMenuStrip = this->mnsMain;
               this->Margin = System::Windows::Forms::Padding(4);
               this->Name = L"frmMain";
               this->Text = L"Головна форма";
               this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
               this->mnsMain->ResumeLayout(false);
               this->mnsMain->PerformLayout();
               this->tsMain->ResumeLayout(false);
               this->tsMain->PerformLayout();
               this->stMain->ResumeLayout(false);
               this->stMain->PerformLayout();
               this->scMain->Panel1->ResumeLayout(false);
               this->scMain->Panel1->PerformLayout();
               this->scMain->Panel2->ResumeLayout(false);
               this->scMain->Panel2->PerformLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->scMain))->EndInit();
               this->scMain->ResumeLayout(false);
               this->ResumeLayout(false);
               this->PerformLayout();
           }
#pragma endregion

    private: frmAbout^ frmabout;
    private: ToneAnalysis^ toneAnalyzer;

    private: System::Void UpdateProgress(float progress) {
        tspMain->Value = static_cast<int>(progress);
    }

    private: System::Void tmsiAbout_Click(System::Object^ sender, System::EventArgs^ e) {
        frmabout->ShowDialog();
    }

    private: System::Void tsbExecute_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrEmpty(txtInput->Text)) {
            MessageBox::Show(L"Введіть текст для аналізу!", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        pin_ptr<const wchar_t> wch = PtrToStringChars(txtInput->Text);
        std::wstring wstr(wch);
        std::string inputText(wstr.begin(), wstr.end());
        std::string* textPtr = new std::string(inputText);

        toneAnalyzer = gcnew ToneAnalysis(textPtr);
        toneAnalyzer->onprogress = gcnew OnProgressEvent(this, &frmMain::UpdateProgress);

        if (toneAnalyzer->sort()) {
            String^ result = toneAnalyzer->Result;
            if (result == "Positive") {
                txtResult->Text = L"Позитивний";
            }
            else if (result == "Negative") {
                txtResult->Text = L"Негативний";
            }
            else {
                txtResult->Text = L"Нейтральний";
            }
            MessageBox::Show(L"Аналіз завершено! Час: " + toneAnalyzer->Timer + L" сек.", L"Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            txtResult->Text = L"Помилка";
            MessageBox::Show(L"Помилка аналізу!", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }

        tspMain->Value = 0;
        delete textPtr;
    }

    private: System::Void tsbInfo_Click(System::Object^ sender, System::EventArgs^ e) {
        MessageBox::Show(L"Програма для обробки тексту.", L"Інформація", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    private: System::Void frmMain_Load(System::Object^ sender, System::EventArgs^ e) {
        frmabout = gcnew frmAbout();
        toneAnalyzer = gcnew ToneAnalysis();
    }
    };
}