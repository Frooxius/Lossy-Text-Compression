#pragma once
#include "Stats.h"

// For x86 abd some others
typedef unsigned short int UINT16;
#define CHECK_PLATFORM

/* ****** Method BitSqueeze ****** */
struct BitBuffer;
void LossyTextCompressBS(char *input, char *outbuf, unsigned int outbuf_size);
bool BitBufferWrite(UINT16 value, unsigned int bits, BitBuffer &bitbuf, char *&outbuf);
void LossyTextDecompressBS(char *input, char *outbuf, unsigned int outbuf_size);
UINT16 BitBufferRead(unsigned int bits, BitBuffer &bitbuf, char *&input);
UINT16 ReverseBits(UINT16 value, unsigned int bits);
const char *BITSQUEEZETABLE = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&()*+/<>";
template<class X> inline X Min(X a, X b) { return (a<b)?a:b; }

namespace LossyTextExample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		Stats ^stat;

	public:
		Form1(void)
		{
			InitializeComponent();
			stat = gcnew Stats();
			stat->Show(this);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  plainText;
	protected: 
	private: System::Windows::Forms::TextBox^  bitSqueeze;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  decrypt;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::Button^  copyBS;
	private: System::Windows::Forms::Button^  copyPlain;
	private: System::Windows::Forms::Button^  compressfile;
	private: System::Windows::Forms::Button^  decompressfile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->plainText = (gcnew System::Windows::Forms::TextBox());
			this->bitSqueeze = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->decrypt = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->copyBS = (gcnew System::Windows::Forms::Button());
			this->copyPlain = (gcnew System::Windows::Forms::Button());
			this->compressfile = (gcnew System::Windows::Forms::Button());
			this->decompressfile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// plainText
			// 
			this->plainText->AcceptsReturn = true;
			this->plainText->AcceptsTab = true;
			this->plainText->AllowDrop = true;
			this->plainText->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->plainText->Location = System::Drawing::Point(12, 23);
			this->plainText->MaxLength = 0;
			this->plainText->Multiline = true;
			this->plainText->Name = L"plainText";
			this->plainText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->plainText->Size = System::Drawing::Size(370, 134);
			this->plainText->TabIndex = 0;
			this->plainText->TextChanged += gcnew System::EventHandler(this, &Form1::plainText_TextChanged);
			// 
			// bitSqueeze
			// 
			this->bitSqueeze->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->bitSqueeze->Location = System::Drawing::Point(12, 182);
			this->bitSqueeze->MaxLength = 0;
			this->bitSqueeze->Multiline = true;
			this->bitSqueeze->Name = L"bitSqueeze";
			this->bitSqueeze->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->bitSqueeze->Size = System::Drawing::Size(370, 134);
			this->bitSqueeze->TabIndex = 1;
			this->bitSqueeze->TextChanged += gcnew System::EventHandler(this, &Form1::bitSqueeze_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Plain text:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Lossy Text Compression - BitSqueeze Algorithm:";
			// 
			// decrypt
			// 
			this->decrypt->Location = System::Drawing::Point(290, 158);
			this->decrypt->Name = L"decrypt";
			this->decrypt->Size = System::Drawing::Size(92, 23);
			this->decrypt->TabIndex = 4;
			this->decrypt->Text = L"Decompress";
			this->decrypt->UseVisualStyleBackColor = true;
			this->decrypt->Click += gcnew System::EventHandler(this, &Form1::decrypt_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(13, 323);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(217, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Warning: This algorithm is intentionally silly :3";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(257, 323);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(124, 13);
			this->linkLabel1->TabIndex = 6;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"http://frooxius.solirax.org";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Form1::linkLabel1_LinkClicked);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(331, 0);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(50, 23);
			this->clear->TabIndex = 7;
			this->clear->Text = L"Clear";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &Form1::clear_Click);
			// 
			// copyBS
			// 
			this->copyBS->Location = System::Drawing::Point(228, 0);
			this->copyBS->Name = L"copyBS";
			this->copyBS->Size = System::Drawing::Size(100, 23);
			this->copyBS->TabIndex = 8;
			this->copyBS->Text = L"Copy BitSqueeze";
			this->copyBS->UseVisualStyleBackColor = true;
			this->copyBS->Click += gcnew System::EventHandler(this, &Form1::copyBS_Click);
			// 
			// copyPlain
			// 
			this->copyPlain->Location = System::Drawing::Point(155, 0);
			this->copyPlain->Name = L"copyPlain";
			this->copyPlain->Size = System::Drawing::Size(70, 23);
			this->copyPlain->TabIndex = 9;
			this->copyPlain->Text = L"Copy Plain";
			this->copyPlain->UseVisualStyleBackColor = true;
			this->copyPlain->Click += gcnew System::EventHandler(this, &Form1::copyPlain_Click);
			// 
			// compressfile
			// 
			this->compressfile->Location = System::Drawing::Point(16, 341);
			this->compressfile->Name = L"compressfile";
			this->compressfile->Size = System::Drawing::Size(100, 23);
			this->compressfile->TabIndex = 10;
			this->compressfile->Text = L"Compress file";
			this->compressfile->UseVisualStyleBackColor = true;
			this->compressfile->Click += gcnew System::EventHandler(this, &Form1::compressfile_Click);
			// 
			// decompressfile
			// 
			this->decompressfile->Location = System::Drawing::Point(122, 341);
			this->decompressfile->Name = L"decompressfile";
			this->decompressfile->Size = System::Drawing::Size(99, 23);
			this->decompressfile->TabIndex = 11;
			this->decompressfile->Text = L"Decompress file";
			this->decompressfile->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(394, 371);
			this->Controls->Add(this->decompressfile);
			this->Controls->Add(this->compressfile);
			this->Controls->Add(this->copyPlain);
			this->Controls->Add(this->copyBS);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->decrypt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bitSqueeze);
			this->Controls->Add(this->plainText);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Lossy Text Example by Frooxius, written in C++";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void plainText_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(!this->plainText->Focused)
					 return;

				 if(this->plainText->Text->Length == 0)
				 {
					 this->bitSqueeze->Text = gcnew String("");
					 UpdateStats();
					 return;
				 }
				 String ^plain = this->plainText->Text;
				 plain = plain->Replace(System::Environment::NewLine, "\n");
				 char *plainC = new char[plain->Length+1];
				 char *compressBS = new char[(plain->Length+1) * 2];

				 for(int i = 0; i < plain->Length; i++)
					 plainC[i] = (char)plain[i];
				 plainC[plain->Length] = 0;

				 LossyTextCompressBS(plainC, compressBS, (plain->Length+1) * 2);

				 this->bitSqueeze->Text = gcnew System::String(compressBS);

				 delete plainC;
				 delete compressBS;
				 UpdateStats();
			 }
	private: System::Void bitSqueeze_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 if(!this->bitSqueeze->Focused)
					 return;

				 if(this->bitSqueeze->Text->Length == 0)
				 {
					 this->plainText->Text = gcnew String("");
					 UpdateStats();
					 return;
				 }
				 String ^bs = this->bitSqueeze->Text;
				 char *bsC = new char[this->bitSqueeze->Text->Length+1];
				 char *plain = new char[(this->bitSqueeze->Text->Length+1) * 2];

				 for(int i = 0; i < bs->Length; i++)
					 bsC[i] = (char)bs[i];
				 bsC[this->bitSqueeze->Text->Length] = 0;

				 LossyTextDecompressBS(bsC, plain, (this->bitSqueeze->Text->Length+1) * 2);

				 this->plainText->Text = (gcnew System::String(plain))->Replace("\n", System::Environment::NewLine);
				 this->plainText->Text;

				 delete bsC;
				 delete plain;
				 UpdateStats();
			 }

			 void UpdateStats()
			 {
				 stat->plainLength->Text = this->plainText->Text->Length.ToString();
				 stat->cBSLength->Text = this->bitSqueeze->Text->Length.ToString();
				 if(this->plainText->Text->Length == 0)
				 {
					 stat->ratioBar->Value = 0;
					 stat->BSratio->Text = "N/A";
				 }
				 else
				 {
					stat->BSratio->Text = (( (int)(((double)this->bitSqueeze->Text->Length/this->plainText->Text->Length)*10000.0) ) / 100.0).ToString() + " %";
					stat->ratioBar->Value = Math::Min(((double)this->bitSqueeze->Text->Length/this->plainText->Text->Length)*100, 100.0);
				 }
			 }


private: System::Void decrypt_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->bitSqueeze->Focus();
			 bitSqueeze_TextChanged(sender, e);
		 }
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 System::Diagnostics::Process::Start("http://frooxius.solirax.org");
		 }
private: System::Void copyPlain_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->plainText->Text->Length == 0)
				 return;
			 Clipboard::SetText(this->plainText->Text);
		 }
private: System::Void copyBS_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->bitSqueeze->Text->Length == 0)
				 return;
			 Clipboard::SetText(this->bitSqueeze->Text);
		 }
private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->bitSqueeze->Text = gcnew String("");
			 this->plainText->Text = gcnew String("");
			 this->bitSqueeze->Focus();
			 bitSqueeze_TextChanged(sender, e);
		 }
private: System::Void compressfile_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->openFileDialog1->ShowDialog();
		 }
};
}







struct BitBuffer
{
	UINT16 bitbuf;
	unsigned short bitnum;
	BitBuffer() { bitbuf = bitnum = 0; }
};

void LossyTextCompressBS(char *input, char *outbuf, unsigned int outbuf_size)
{
#ifdef CHECK_PLATFORM
	// Can't check this with the preprocessor -_-, throws a simple expression, feel free to alter the error reporting the way you want
	if(sizeof(UINT16) < 2)	// well not strictly UINT16, but meh >.>
		throw "UINT16 HAS WRONG SIZE";
#endif
	BitBuffer bitbuf;
	bool wasspace, skipspace = false;

	while(*input && outbuf_size)
	{
		wasspace = false;
		// encode only certain characters using 5 bits and insert them into the bitbuffer
		if(*input >= 'a' && *input <= 'z')
			outbuf_size -= BitBufferWrite(*input - 'a', 5, bitbuf, outbuf);
		else if (*input >= 'A' && *input <= 'Z')
			outbuf_size -= BitBufferWrite(*input - 'A', 5, bitbuf, outbuf);
		else if (*input >= '0' && *input <= '3')
			outbuf_size -= BitBufferWrite(*input - '0' + 'z' - 'a' + 2, 5, bitbuf, outbuf);
		else if (*input >= '4' && *input <= '9')
			outbuf_size -= BitBufferWrite(31, 5, bitbuf, outbuf) | BitBufferWrite(*input - '4', 3, bitbuf, outbuf);
		else if(*input == '.' || *input == '!' || *input == '?')
			outbuf_size -= BitBufferWrite(31, 5, bitbuf, outbuf) | BitBufferWrite('9'-'4'+1, 3, bitbuf, outbuf);
		else if(*input == '\n' || *input == '\r')
			outbuf_size -= BitBufferWrite(31, 5, bitbuf, outbuf) | BitBufferWrite('9'-'4'+2, 3, bitbuf, outbuf);
		else
		{
			wasspace = true; // indicate that 
			if(!skipspace)
				outbuf_size -= BitBufferWrite('z'+1 - 'a', 5, bitbuf, outbuf); // anythig else is converted to space
		}
		skipspace = wasspace;
		input++;
	}
	// finalize it - insert null character at the end
	if(outbuf_size)
	{
		BitBufferWrite('z'+1 - 'a', 6-bitbuf.bitnum, bitbuf, outbuf);
		*outbuf = 0;
	}
	else
		*(outbuf-1) = 0;
}

// bit buffer takes bits and once there's enough of them to print a character from the squeeze table it stores it in the output
bool BitBufferWrite(UINT16 value, unsigned int bits, BitBuffer &bitbuf, char *&outbuf)
{
	// the value sanitization isn't strictly needed for this example, but in case you wanted to use this elsewhere, it's there ;)
	bitbuf.bitbuf |= (value & ~(0xFFFFU << bits)) << bitbuf.bitnum; // add the new value to the buffer
	// if there's enough to generate a character
	if((bitbuf.bitnum += bits) >= 6)
	{
		*(outbuf++) = *(BITSQUEEZETABLE + ( bitbuf.bitbuf & 0x3FU)) ;
		bitbuf.bitbuf >>= 6;
		bitbuf.bitnum -= 6;
		return true;
	}
	return false;
}

void LossyTextDecompressBS(char *input, char *outbuf, unsigned int outbuf_size)
{
#ifdef CHECK_PLATFORM
	// Can't check this with the preprocessor -_-, throws a simple expression, feel free to alter the error reporting the way you want
	if(sizeof(UINT16) < 2)	// well not strictly UINT16, but meh >.>
		throw "UINT16 HAS WRONG SIZE";
#endif

	BitBuffer bitbuf;
	UINT16 temp;
	while((temp = BitBufferRead(5, bitbuf, input)) != 0xFFFFU && outbuf_size--)
	{
		if(temp <= ('z'-'a'))
			*(outbuf++) = 'a'+temp;
		else if(temp == ('z'-'a'+1))
			*(outbuf++) = ' ';
		else if(temp == 31U)
			*(outbuf++) = "456789.\n"[Min((int)BitBufferRead(3, bitbuf, input), 7)];
		else *(outbuf++) = '0'-('z'-'a'+2)+temp;
	}
	// finish it
	if(outbuf_size)
		*outbuf = 0;
	else
		*(outbuf-1) = 0;
}

UINT16 BitBufferRead(unsigned int bits, BitBuffer &bitbuf, char *&input)
{
	if(bitbuf.bitnum < bits)
	{
		if(*input == 0)
		return 0xFFFFU;

		UINT16 newvalue;
		for(newvalue = 0; (*input != *(BITSQUEEZETABLE+newvalue)) && newvalue < 64; ++newvalue); // not most efficient, can be replaced with generated conversion table
		bitbuf.bitbuf |= newvalue << bitbuf.bitnum;
		bitbuf.bitnum += 6;
		input++;
	}
	UINT16 ret = bitbuf.bitbuf & ~(0xFFFFU << bits);
	bitbuf.bitnum -= bits;
	bitbuf.bitbuf >>= bits;
	return ret;
}

UINT16 ReverseBits(UINT16 value, unsigned int bits)
{
	UINT16 reversed = 0;
	for(unsigned int i = 0; i < bits; ++i)
		reversed |= ((bool)(value & (1<<i))) << (bits-i-1);
	return reversed;
}