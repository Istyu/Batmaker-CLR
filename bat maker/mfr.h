#pragma once
#include"dirent.h"

char* selected_color = "";
bool lang_ger = false;
bool lang_rus = false;
bool animtrees = false;
bool shock = false;
bool rumble = false;
bool ui = false;
bool vehicles = false;

namespace maker
{
	void makebat()
	{
    	FILE *fp;
    	errno_t err;

    	// open the file for writing
    	err = fopen_s( &fp, "makeMod.bat", "w" );

    	if( fp == NULL )
    	    return;

    	fprintf( fp, "@echo off\n" );
    	fprintf( fp, "set COMPILEDIR=%%CD%%\n" );
    	fprintf( fp, "set %s\n", selected_color );
    	fprintf( fp, "color %%color%%\n" );
		fprintf( fp, "\n" );
    	fprintf( fp, ":START\n" );
    	fprintf( fp, "cls\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo. ^================================================================\n" );
    	fprintf( fp, "echo. 		Author: \n" );
    	fprintf( fp, "echo.		project: \n" );
    	fprintf( fp, "echo. ^================================================================\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":MAKEOPTIONS\n" );
    	fprintf( fp, "echo _________________________________________________________________\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo  Please select an option:\n" );
    	fprintf( fp, "echo    1. Build mod.ff\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo    0. Exit\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "set /p make_option=:\n" );
    	fprintf( fp, "set make_option=%%make_option:~0,1%%\n" );
    	fprintf( fp, "if \"%%make_option%%\"==\"1\" goto CHOOSE_LANG\n" );
    	fprintf( fp, "if \"%%make_option%%\"==\"0\" goto FINAL\n" );
    	fprintf( fp, "goto START\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":CHOOSE_LANG\n" );
    	fprintf( fp, "echo _________________________________________________________________\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo  Please choose the language you would like to compile:\n" );
    	fprintf( fp, "echo    1. English\n" );
    	if( lang_ger )
    		fprintf( fp, "echo    2. German\n" );
    	if( lang_rus )
    		fprintf( fp, "echo    3. Russian\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo    0. Back\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "set /p lang_chosen=:\n" );
    	fprintf( fp, "set lang_chosen=%%lang_chosen:~0,1%%\n" );
    	fprintf( fp, "if \"%%lang_chosen%%\"==\"1\" goto LANGEN\n" );
    	if( lang_ger )
    		fprintf( fp, "if \"%%lang_chosen%%\"==\"2\" goto LANGDE\n" );
    	if( lang_rus )
    		fprintf( fp, "if \"%%lang_chosen%%\"==\"3\" goto LANGRU\n" );
    	fprintf( fp, "goto CHOOSE_LANG\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":LANGEN\n" );
    	fprintf( fp, "set CLANGUAGE=English\n" );
    	fprintf( fp, "set LANG=english\n" );
    	fprintf( fp, "set LTARGET=english\n" );
    	fprintf( fp, "goto COMPILE\n" );
    	fprintf( fp, "\n" );
    	if( lang_ger )
    	{
    		fprintf( fp, ":LANGDE\n" );
    		fprintf( fp, "set CLANGUAGE=German\n" );
    		fprintf( fp, "set LANG=german\n" );
    		fprintf( fp, "set LTARGET=german\n" );
    		fprintf( fp, "goto COMPILE\n" );
    		fprintf( fp, "\n" );
    	}
    	if( lang_rus )
    	{
    		fprintf( fp, ":LANGRU\n" );
    		fprintf( fp, "set CLANGUAGE=Russian\n" );
    		fprintf( fp, "set LANG=russian\n" );
    		fprintf( fp, "set LTARGET=russian\n" );
    		fprintf( fp, "goto COMPILE\n" );
    		fprintf( fp, "\n" );
    	}
    	fprintf( fp, "\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":COMPILE\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "echo  Checking language directories...\n" );
    	fprintf( fp, "if not exist ..\\..\\zone\\%%LTARGET%% mkdir ..\\..\\zone\\%%LTARGET%%\n" );
    	fprintf( fp, "if not exist ..\\..\\zone_source\\%%LTARGET%% xcopy ..\\..\\zone_source\\english ..\\..\\zone_source\\%%LTARGET%% /SYI > NUL\n" );
    	fprintf( fp, "echo  This mod will be created in %%CLANGUAGE%%!\n" );
    	fprintf( fp, "if \"%%make_option%%\"==\"1\" goto MAKE_MOD_FF\n" );
    	fprintf( fp, "goto END\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":MAKE_MOD_FF\n" );
    	fprintf( fp, "echo _________________________________________________________________\n" );
    	fprintf( fp, "echo.\n" );
    	fprintf( fp, "echo  Building mod.ff:\n" );
    	fprintf( fp, "echo    Deleting old mod.ff file...\n" );
    	fprintf( fp, "del mod.ff\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "echo    Copying localized strings...\n" );
    	fprintf( fp, "xcopy %%LANG%% ..\\..\\raw\\%%LTARGET%% /SYI > NUL\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "echo    Copying game resources...\n" );
    	if( animtrees )
    		fprintf( fp, "xcopy animtrees ..\\..\\raw\\animtrees /SYI > NUL\n" );
    	fprintf( fp, "xcopy images ..\\..\\raw\\images /SYI > NUL\n" );
    	fprintf( fp, "xcopy fx ..\\..\\raw\\fx /SYI > NUL\n" );
    	fprintf( fp, "xcopy maps ..\\..\\raw\\maps /SYI > NUL\n" );
    	fprintf( fp, "xcopy maps ..\\..\\raw\\maps /SYI > NUL\n" );
    	fprintf( fp, "xcopy material_properties ..\\..\\raw\\material_properties /SYI > NUL\n" );
    	fprintf( fp, "xcopy materials ..\\..\\raw\\materials /SYI > NUL\n" );
    	fprintf( fp, "xcopy mp ..\\..\\raw\\mp /SYI > NUL\n" );
    	if( shock )
    		fprintf( fp, "xcopy shock ..\\..\\raw\\shock /SYI > NUL\n" );
    	if( rumble )
    		fprintf( fp, "xcopy rumble ..\\..\\raw\\rumble /SYI > NUL\n" );
    	fprintf( fp, "xcopy sound ..\\..\\raw\\sound /SYI > NUL\n" );
    	fprintf( fp, "xcopy soundaliases ..\\..\\raw\\soundaliases /SYI > NUL\n" );
    	if( ui )
    		fprintf( fp, "xcopy ui ..\\..\\raw\\ui /SYI > NUL\n" );
    	fprintf( fp, "xcopy ui_mp ..\\..\\raw\\ui_mp /SYI > NUL\n" );
    	if( vehicles )
    		fprintf( fp, "xcopy vehicles ..\\..\\raw\\vehicles /SYI > NUL\n" );
    	fprintf( fp, "xcopy vision ..\\..\\raw\\vision /SYI > NUL\n" );
    	fprintf( fp, "xcopy weapons\\mp ..\\..\\raw\\weapons\\mp /SYI > NUL\n" );
    	fprintf( fp, "xcopy xanim ..\\..\\raw\\xanim /SYI > NUL\n" );
    	fprintf( fp, "xcopy xmodel ..\\..\\raw\\xmodel /SYI > NUL\n" );
    	fprintf( fp, "xcopy xmodelparts ..\\..\\raw\\xmodelparts /SYI > NUL\n" );
    	fprintf( fp, "xcopy xmodelsurfs ..\\..\\raw\\xmodelsurfs /SYI > NUL\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "echo    Copying mod source code...\n" );
    //	fprintf( fp, "xcopy mod ..\\..\\raw\\mod /SYI > NUL\n" );
    	fprintf( fp, "copy /Y mod.csv ..\\..\\zone_source > NUL\n" );
    	fprintf( fp, "copy /Y mod_ignore.csv ..\\..\\zone_source\\%%LTARGET%%\\assetlist > NUL\n" );
    	fprintf( fp, "cd ..\\..\\bin > NUL\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, "echo    Compiling mod...\n" );
    	fprintf( fp, "linker_pc.exe -language %%LTARGET%% -compress -cleanup mod \n" );
    	fprintf( fp, "cd %%COMPILEDIR%% > NUL\n" );
    	fprintf( fp, "copy ..\\..\\zone\\%%LTARGET%%\\mod.ff > NUL\n" );
    	fprintf( fp, "echo  New mod.ff file successfully built!\n" );
    	fprintf( fp, "goto END\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":END\n" );
    	fprintf( fp, "pause\n" );
    	fprintf( fp, "goto FINAL\n" );
    	fprintf( fp, "\n" );
    	fprintf( fp, ":FINAL" );

    	fclose( fp );
	}
}

namespace batmaker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace maker;

	/// <summary>
	/// Summary for mfr
	/// </summary>
	public ref class mfr : public System::Windows::Forms::Form
	{
	public:
		mfr(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mfr()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ colorlb;

	private: System::Windows::Forms::Button^ genbtn;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::Button^ clearbtn;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->colorlb = (gcnew System::Windows::Forms::Label());
			this->genbtn = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->clearbtn = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// colorlb
			// 
			this->colorlb->AutoSize = true;
			this->colorlb->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colorlb->Location = System::Drawing::Point(13, 13);
			this->colorlb->Name = L"colorlb";
			this->colorlb->Size = System::Drawing::Size(44, 19);
			this->colorlb->TabIndex = 0;
			this->colorlb->Text = L"Color";
			this->colorlb->Click += gcnew System::EventHandler(this, &mfr::colorlb_Click);
			// 
			// genbtn
			// 
			this->genbtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->genbtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->genbtn->Location = System::Drawing::Point(3, 3);
			this->genbtn->Name = L"genbtn";
			this->genbtn->Size = System::Drawing::Size(343, 29);
			this->genbtn->TabIndex = 2;
			this->genbtn->Text = L"generate";
			this->genbtn->UseVisualStyleBackColor = true;
			this->genbtn->Click += gcnew System::EventHandler(this, &mfr::genbtn_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(17, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(349, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &mfr::comboBox1_SelectedIndexChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				206)));
			this->tableLayoutPanel1->Controls->Add(this->genbtn, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->clearbtn, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(17, 537);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(555, 41);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// clearbtn
			// 
			this->clearbtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->clearbtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearbtn->Location = System::Drawing::Point(352, 3);
			this->clearbtn->Name = L"clearbtn";
			this->clearbtn->Size = System::Drawing::Size(200, 29);
			this->clearbtn->TabIndex = 3;
			this->clearbtn->Text = L"clear";
			this->clearbtn->UseVisualStyleBackColor = true;
			this->clearbtn->Click += gcnew System::EventHandler(this, &mfr::clearbtn_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(20, 92);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(63, 17);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"German";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(20, 115);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(64, 17);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Russian";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox2_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 19);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Languages";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(14, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 19);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Resources";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(20, 171);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(72, 17);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"Animtrees";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(20, 195);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(57, 17);
			this->checkBox4->TabIndex = 10;
			this->checkBox4->Text = L"Shock";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(20, 218);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(62, 17);
			this->checkBox5->TabIndex = 11;
			this->checkBox5->Text = L"Rumble";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(20, 241);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(34, 17);
			this->checkBox6->TabIndex = 12;
			this->checkBox6->Text = L"ui";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox6_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(20, 265);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(66, 17);
			this->checkBox7->TabIndex = 13;
			this->checkBox7->Text = L"Vehicles";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &mfr::checkBox7_CheckedChanged);
			// 
			// mfr
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 581);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->colorlb);
			this->MaximumSize = System::Drawing::Size(600, 620);
			this->MinimumSize = System::Drawing::Size(440, 480);
			this->Name = L"mfr";
			this->Text = L"bat maker";
			this->Load += gcnew System::EventHandler(this, &mfr::mfr_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	String^ color0 = "";
	private: System::Void colorlb_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		
	}
	private: System::Void clearbtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		checkBox1->Checked = false;
		checkBox2->Checked = false;
		checkBox3->Checked = false;
		checkBox4->Checked = false;
		checkBox5->Checked = false;
		checkBox6->Checked = false;
		checkBox7->Checked = false;
		comboBox1->SelectedItem = color0;
		selected_color = "";
		lang_ger = false;
		lang_rus = false;
		animtrees = false;
		shock = false;
		rumble = false;
		ui = false;
		vehicles = false;
	}
	private: System::Void genbtn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if( comboBox1->SelectedItem == "black, green" )
			selected_color = "color=0a";
		else if( comboBox1->SelectedItem == "black, aqua" )
			selected_color = "color=0b";
		else if( comboBox1->SelectedItem == "black, red" )
			selected_color = "color=0c";
		else if( comboBox1->SelectedItem == "black, purple" )
			selected_color = "color=0d";
		else if( comboBox1->SelectedItem == "black, yellow" )
			selected_color = "color=0e";
		else if( comboBox1->SelectedItem == "black, white" )
			selected_color = "color=0f";
		else if( comboBox1->SelectedItem == "blue, green" )
			selected_color = "color=1a";
		else if( comboBox1->SelectedItem == "blue, aqua" )
			selected_color = "color=1b";
		else if( comboBox1->SelectedItem == "blue, red" )
			selected_color = "color=1c";
		else if( comboBox1->SelectedItem == "blue, purple" )
			selected_color = "color=1d";
		else if( comboBox1->SelectedItem == "blue, yellow" )
			selected_color = "color=1e";
		else if( comboBox1->SelectedItem == "blue, white" )
			selected_color = "color=1f";
		else if( comboBox1->SelectedItem == "green, green" )
			selected_color = "color=2a";
		else if( comboBox1->SelectedItem == "green, aqua" )
			selected_color = "color=2b";
		else if( comboBox1->SelectedItem == "green, red" )
			selected_color = "color=2c";
		else if( comboBox1->SelectedItem == "green, purple" )
			selected_color = "color=2d";
		else if( comboBox1->SelectedItem == "green, yellow" )
			selected_color = "color=2e";
		else if( comboBox1->SelectedItem == "green, white" )
			selected_color = "color=2f";
		else if( comboBox1->SelectedItem == "aqua, green" )
			selected_color = "color=3a";
		else if( comboBox1->SelectedItem == "aqua, aqua" )
			selected_color = "color=3b";
		else if( comboBox1->SelectedItem == "aqua, red" )
			selected_color = "color=3c";
		else if( comboBox1->SelectedItem == "aqua, purple" )
			selected_color = "color=3d";
		else if( comboBox1->SelectedItem == "aqua, yellow" )
			selected_color = "color=3e";
		else if( comboBox1->SelectedItem == "aqua, white" )
			selected_color = "color=3f";
		else if( comboBox1->SelectedItem == "red, green" )
			selected_color = "color=4a";
		else if( comboBox1->SelectedItem == "red, aqua" )
			selected_color = "color=4b";
		else if( comboBox1->SelectedItem == "red, red" )
			selected_color = "color=4c";
		else if( comboBox1->SelectedItem == "red, purple" )
			selected_color = "color=4d";
		else if( comboBox1->SelectedItem == "red, yellow" )
			selected_color = "color=4e";
		else if( comboBox1->SelectedItem == "red, white" )
			selected_color = "color=4f";
		else if( comboBox1->SelectedItem == "purple, green" )
			selected_color = "color=5a";
		else if( comboBox1->SelectedItem == "purple, aqua" )
			selected_color = "color=5b";
		else if( comboBox1->SelectedItem == "purple, red" )
			selected_color = "color=5c";
		else if( comboBox1->SelectedItem == "purple, purple" )
			selected_color = "color=5d";
		else if( comboBox1->SelectedItem == "purple, yellow" )
			selected_color = "color=5e";
		else if( comboBox1->SelectedItem == "purple, white" )
			selected_color = "color=5f";
		else if( comboBox1->SelectedItem == "olive, green" )
			selected_color = "color=6a";
		else if( comboBox1->SelectedItem == "olive, aqua" )
			selected_color = "color=6b";
		else if( comboBox1->SelectedItem == "olive, red" )
			selected_color = "color=6c";
		else if( comboBox1->SelectedItem == "olive, purple" )
			selected_color = "color=6d";
		else if( comboBox1->SelectedItem == "olive, yellow" )
			selected_color = "color=6e";
		else if( comboBox1->SelectedItem == "olive, white" )
			selected_color = "color=6f";
		else if( comboBox1->SelectedItem == "silver, green" )
			selected_color = "color=6a";
		else if( comboBox1->SelectedItem == "silver, aqua" )
			selected_color = "color=6b";
		else if( comboBox1->SelectedItem == "silver, red" )
			selected_color = "color=6c";
		else if( comboBox1->SelectedItem == "silver, purple" )
			selected_color = "color=6d";
		else if( comboBox1->SelectedItem == "silver, yellow" )
			selected_color = "color=6e";
		else if( comboBox1->SelectedItem == "silver, white" )
			selected_color = "color=6f";

		maker::makebat();
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	}
	private: System::Void mfr_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ color = "black, green"; // black, green
		String^ color2 = "black, aqua"; // black, aqua
		String^ color3 = "black, red"; // black, red
		String^ color4 = "black, purple"; // black, purple
		String^ color5 = "black, yellow"; // black, yellow
		String^ color6 = "black, white"; // black, white
		String^ color7 = "blue, green"; // blue, green
		String^ color8 = "blue, aqua"; // blue, aqua
		String^ color9 = "blue, red"; // blue, red
		String^ color10 = "blue, purple"; // blue, purple
		String^ color11 = "blue, yellow"; // blue, yellow
		String^ color12 = "blue, white"; // blue, white
		String^ color13 = "green, green"; // green, green
		String^ color14 = "green, aqua"; // green, aqua
		String^ color15 = "green, red"; // green, red
		String^ color16 = "green, purple"; // green, purple
		String^ color17 = "green, yellow"; // green, yellow
		String^ color18 = "green, white"; // green, white
		String^ color19 = "aqua, green"; // aqua, green
		String^ color20 = "aqua, aqua"; // aqua, aqua
		String^ color21 = "aqua, red"; // aqua, red
		String^ color22 = "aqua, purple"; // aqua, purple
		String^ color23 = "aqua, yellow"; // aqua, yellow
		String^ color24 = "aqua, white"; // aqua, white
		String^ color25 = "red, green"; // red, green
		String^ color26 = "red, aqua"; // red, aqua
		String^ color27 = "red, red"; // red, red
		String^ color28 = "red, purple"; // red, purple
		String^ color29 = "red, yellow"; // red, yellow
		String^ color30 = "red, white"; // red, white
		String^ color31 = "purple, green"; // purple, green
		String^ color32 = "purple, aqua"; // purple, aqua
		String^ color33 = "purple, red"; // purple, red
		String^ color34 = "purple, purple"; // purple, purple
		String^ color35 = "purple, yellow"; // purple, yellow
		String^ color36 = "purple, white"; // purple, white
		String^ color37 = "olive, green"; // olive, green
		String^ color38 = "olive, aqua"; // olive, aqua
		String^ color39 = "olive, red"; // olive, red
		String^ color40 = "olive, purple"; // olive, purple
		String^ color41 = "olive, yellow"; // olive, yellow
		String^ color42 = "olive, white"; // olive, white
		String^ color43 = "silver, green"; // silver, green
		String^ color44 = "silver, aqua"; // silver, aqua
		String^ color45 = "silver, red"; // silver, red
		String^ color46 = "silver, purple"; // silver, purple
		String^ color47 = "silver, yellow"; // silver, yellow
		String^ color48 = "silver, white"; // silver, white

		comboBox1->Items->Add(color);
		comboBox1->Items->Add(color2);
		comboBox1->Items->Add(color3);
		comboBox1->Items->Add(color4);
		comboBox1->Items->Add(color5);
		comboBox1->Items->Add(color6);
		comboBox1->Items->Add(color7);
		comboBox1->Items->Add(color8);
		comboBox1->Items->Add(color9);
		comboBox1->Items->Add(color10);
		comboBox1->Items->Add(color11);
		comboBox1->Items->Add(color12);
		comboBox1->Items->Add(color13);
		comboBox1->Items->Add(color14);
		comboBox1->Items->Add(color15);
		comboBox1->Items->Add(color16);
		comboBox1->Items->Add(color17);
		comboBox1->Items->Add(color18);
		comboBox1->Items->Add(color19);
		comboBox1->Items->Add(color20);
		comboBox1->Items->Add(color21);
		comboBox1->Items->Add(color22);
		comboBox1->Items->Add(color23);
		comboBox1->Items->Add(color24);
		comboBox1->Items->Add(color25);
		comboBox1->Items->Add(color26);
		comboBox1->Items->Add(color27);
		comboBox1->Items->Add(color28);
		comboBox1->Items->Add(color29);
		comboBox1->Items->Add(color30);
		comboBox1->Items->Add(color31);
		comboBox1->Items->Add(color32);
		comboBox1->Items->Add(color33);
		comboBox1->Items->Add(color34);
		comboBox1->Items->Add(color35);
		comboBox1->Items->Add(color36);
		comboBox1->Items->Add(color37);
		comboBox1->Items->Add(color38);
		comboBox1->Items->Add(color39);
		comboBox1->Items->Add(color40);
		comboBox1->Items->Add(color41);
		comboBox1->Items->Add(color42);
		comboBox1->Items->Add(color43);
		comboBox1->Items->Add(color44);
		comboBox1->Items->Add(color45);
		comboBox1->Items->Add(color46);
		comboBox1->Items->Add(color47);
		comboBox1->Items->Add(color48);
		comboBox1->Items->Add(color0);
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		lang_ger = true;
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		lang_rus = true;
	}
	private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		animtrees = true;
	}
	private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		shock = true;
	}
	private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		rumble = true;
	}
	private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		ui = true;
	}
	private: System::Void checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		vehicles = true;
	}
};
}
