#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace LossyTextExample {

	/// <summary>
	/// Summary for Stats
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Stats : public System::Windows::Forms::Form
	{
		double targetX, targetY;
		double floatAngle, dirAngle, dirAngleSpeed;

	public:
		Stats(void)
		{
			InitializeComponent();
			dirAngle = 1.7;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Stats()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::Label^  plainLength;
	private: 
	public: System::Windows::Forms::Label^  cBSLength;
	public: System::Windows::Forms::Label^  BSratio;
	public: System::Windows::Forms::ProgressBar^  ratioBar;

	public: 

	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Timer^  updatePosition;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Stats::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->plainLength = (gcnew System::Windows::Forms::Label());
			this->cBSLength = (gcnew System::Windows::Forms::Label());
			this->BSratio = (gcnew System::Windows::Forms::Label());
			this->ratioBar = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->updatePosition = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 8);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Plain text length:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 32);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"BitSqueeze length:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 58);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Compression ratio:";
			// 
			// plainLength
			// 
			this->plainLength->Location = System::Drawing::Point(159, 8);
			this->plainLength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->plainLength->Name = L"plainLength";
			this->plainLength->Size = System::Drawing::Size(99, 22);
			this->plainLength->TabIndex = 3;
			this->plainLength->Text = L"0";
			// 
			// cBSLength
			// 
			this->cBSLength->Location = System::Drawing::Point(159, 32);
			this->cBSLength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->cBSLength->Name = L"cBSLength";
			this->cBSLength->Size = System::Drawing::Size(99, 22);
			this->cBSLength->TabIndex = 4;
			this->cBSLength->Text = L"0";
			// 
			// BSratio
			// 
			this->BSratio->Location = System::Drawing::Point(159, 58);
			this->BSratio->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->BSratio->Name = L"BSratio";
			this->BSratio->Size = System::Drawing::Size(99, 22);
			this->BSratio->TabIndex = 5;
			this->BSratio->Text = L"0";
			// 
			// ratioBar
			// 
			this->ratioBar->Enabled = false;
			this->ratioBar->Location = System::Drawing::Point(14, 181);
			this->ratioBar->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->ratioBar->Name = L"ratioBar";
			this->ratioBar->Size = System::Drawing::Size(232, 26);
			this->ratioBar->TabIndex = 6;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Location = System::Drawing::Point(85, 85);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(99, 88);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// updatePosition
			// 
			this->updatePosition->Enabled = true;
			this->updatePosition->Interval = 16;
			this->updatePosition->Tick += gcnew System::EventHandler(this, &Stats::updatePosition_Tick);
			// 
			// Stats
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(258, 216);
			this->ControlBox = false;
			this->Controls->Add(this->ratioBar);
			this->Controls->Add(this->BSratio);
			this->Controls->Add(this->cBSLength);
			this->Controls->Add(this->plainLength);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Stats";
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Info";
			this->MouseHover += gcnew System::EventHandler(this, &Stats::Stats_MouseHover);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Stats::Stats_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void updatePosition_Tick(System::Object^  sender, System::EventArgs^  e) {
				 int radius = Math::Sqrt(((Owner->Height/2)*(Owner->Height/2) + (Owner->Width/2)*(Owner->Width/2)));
				 radius *= 1.4;

				 targetX = (Owner->Left+Owner->Width/2)
					 + Math::Sin(dirAngle)*radius
					 - Width/2;
				 targetY = (Owner->Top+Owner->Height/2)
					 + Math::Cos(dirAngle)*radius
					 - Height/2;

				 if(Left < SystemInformation::VirtualScreen.Left+20)
				 {
					 if(Top < Owner->Top+Owner->Height/2)
						 dirAngleSpeed = -0.25;
					 else
						 dirAngleSpeed = 0.25;
				 }

				 if(Left > SystemInformation::VirtualScreen.Right - 20 - Width)
				 {
					 if(Top < Owner->Top+Owner->Height/2)
						 dirAngleSpeed = 0.25;
					 else
						 dirAngleSpeed = -0.25;
				 }

				 if(Top < SystemInformation::WorkingArea.Top+20)
				 {
					 if(Left < Owner->Left+Owner->Width/2)
						 dirAngleSpeed = 0.25;
					 else
						 dirAngleSpeed = -0.25;
				 }

				 if(Top > SystemInformation::WorkingArea.Bottom-20 - Height)
				 {
					 if(Left < Owner->Left+Owner->Width/2)
						 dirAngleSpeed = -0.25;
					 else
						 dirAngleSpeed = 0.25;
				 }

				 dirAngle += (dirAngleSpeed *= 0.8);

				 targetX = Math::Min(Math::Max(targetX, Owner->Left-Width*1.1), Owner->Left+Owner->Width*1.1);
				 targetY = Math::Min(Math::Max(targetY, Owner->Top-Height*1.1), Owner->Top+Owner->Height*1.1);

				 Left = Left*0.9+targetX*0.1;
				 Top = Top*0.9+targetY*0.1;
			 }
private: System::Void Stats_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if(dirAngleSpeed > 0.05)
			 {
				 dirAngleSpeed = 0.2;
				 return;
			 }
			 if(dirAngleSpeed < -0.05)
			 {
				 dirAngleSpeed = -0.2;
				 return;
			 }
			 if((e->X < Width/2 && e->Y < Height/2) || (e->X > Width/2 && e->Y > Height/2))
				 dirAngleSpeed = 0.2;
			 else
				 dirAngleSpeed = -0.2;
		 }
private: System::Void Stats_MouseHover(System::Object^  sender, System::EventArgs^  e) {
			 
		 }
};
}
