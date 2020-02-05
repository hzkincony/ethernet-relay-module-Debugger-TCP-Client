//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		ClientSocket1->Active = false;
		ClientSocket1->Host=Edit1->Text;
		ClientSocket1->Port=StrToInt(Edit2->Text);

		try
		  {
			ClientSocket1->Active=true;
			Button2->Enabled=true;
			Button1->Enabled =false;
		  }
		catch(Exception &E)
		  {
			ShowMessage("Connect Failed��"+E.Message);
		return;
		  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ClientSocket1->Active = false;
  ClientSocket1->Close() ;

  Button2->Enabled=false;
  Button1->Enabled =true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,1,1");
Memo1->Lines ->Add("RELAY-SET-255,1,1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,1,0");
Memo1->Lines ->Add("RELAY-SET-255,1,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,2,1");
Memo1->Lines ->Add("RELAY-SET-255,2,1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,2,0");
Memo1->Lines ->Add("RELAY-SET-255,2,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button19Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,3,1");
Memo1->Lines ->Add("RELAY-SET-255,3,1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button20Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,3,0");
Memo1->Lines ->Add("RELAY-SET-255,3,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button21Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,4,1");
Memo1->Lines ->Add("RELAY-SET-255,4,1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button22Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,4,0");
Memo1->Lines ->Add("RELAY-SET-255,4,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button23Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,5,1");
Memo1->Lines ->Add("RELAY-SET-255,5,1");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button24Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET-255,5,0");
Memo1->Lines ->Add("RELAY-SET-255,5,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,255");
Memo1->Lines ->Add("RELAY-SET_ALL-255,255");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,0");
Memo1->Lines ->Add("RELAY-SET_ALL-255,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,255,255");
Memo1->Lines ->Add("RELAY-SET_ALL-255,255,255");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,0,0");
Memo1->Lines ->Add("RELAY-SET_ALL-255,0,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,255,255,255,255");
Memo1->Lines ->Add("RELAY-SET_ALL-255,255,255,255,255");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,0,0,0,0");
Memo1->Lines ->Add("RELAY-SET_ALL-255,0,0,0,0");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,85");
Memo1->Lines ->Add("RELAY-SET_ALL-255,85");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,85,85");
Memo1->Lines ->Add("RELAY-SET_ALL-255,85,85");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-SET_ALL-255,85,85,85,85");
Memo1->Lines ->Add("RELAY-SET_ALL-255,85,85,85,85");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-READ-255,"+ComboBox1->Text) ;
Memo1->Lines ->Add("RELAY-READ-255,"+ComboBox1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-STATE-255");
Memo1->Lines ->Add("RELAY-STATE-255");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button18Click(TObject *Sender)
{
ClientSocket1->Socket->SendText("RELAY-GET_INPUT-255");
Memo1->Lines ->Add("RELAY-GET_INPUT-255");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button25Click(TObject *Sender)
{
ClientSocket1->Socket->SendText(Edit3->Text );
Memo1->Lines ->Add(Edit3->Text );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button26Click(TObject *Sender)
{
  Edit3->Text ="";
  Memo2->Clear();
  Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connect(TObject *Sender, TCustomWinSocket *Socket)

{
  StatusBar1->Panels->Items[1]->Text = "Connect OK! ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Connecting(TObject *Sender, TCustomWinSocket *Socket)

{
  StatusBar1->Panels->Items[1]->Text = "Connecting... ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Disconnect(TObject *Sender, TCustomWinSocket *Socket)

{
   StatusBar1->Panels->Items[1]->Text = "DisConnected!" ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Error(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode)
{
  StatusBar1->Panels->Items[1]->Text = "Connect to Server failed!" ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
	AnsiString temp,Substr,Substr1,str,str1;
	int input_state;
	int pos; //search string position
	temp=ClientSocket1->Socket->ReceiveText();
	int real_state=0;

	Memo2->Lines ->Add(temp);

//----------------------Receive input trigger signal------�磺RELAY-ALARM-3--------

	Substr=AnsiString(temp).SubString(1,12);

	if (Substr=="RELAY-ALARM-")
	  {
		Substr1=AnsiString(temp).SubString(13,1);  //Read input channel number

		ClientSocket1->Socket->SendText("RELAY-GET_INPUT-255");  //read input state
		StatusBar1->Panels->Items[1]->Text = "Input is triggered";
	  }


//------------------------------------------------------------------
	Substr=AnsiString(temp).SubString(1,20);
	//feedback string    RELAY-GET_INPUT-255,65,OK
	if (Substr=="RELAY-GET_INPUT-255,")
	  {

		str=temp.SubString(21,temp.Length()-20 ); //get string of   65,OK

		pos=str.Pos(",");  //find , position
		str1=AnsiString(str).SubString(1,pos-1); //get input sate data

		real_state=StrToInt(str1);

	   if ((real_state&0x01)==0x01) Shape1->Brush->Color=clLime;    //input-1 trig
		 else {Shape1->Brush->Color=clRed;}

	   if ((real_state&0x02)==0x02) Shape2->Brush->Color=clLime;    //input-2 trig
		 else {Shape2->Brush->Color=clRed;}


	   if ((real_state&0x04)==0x04) Shape3->Brush->Color=clLime;    //input-3 trig
		 else {Shape3->Brush->Color=clRed;}


	   if ((real_state&0x08)==0x08) Shape4->Brush->Color=clLime;    //input-4 trig
		 else {Shape4->Brush->Color=clRed;}


	   if ((real_state&0x10)==0x10) Shape5->Brush->Color=clLime;    //input-5 trig
		 else {Shape5->Brush->Color=clRed;}


	   if ((real_state&0x20)==0x20) Shape6->Brush->Color=clLime;    //input-6 trig
		 else {Shape6->Brush->Color=clRed;}


	   if ((real_state&0x40)==0x40) Shape7->Brush->Color=clLime;    //input-7 trig
		 else {Shape7->Brush->Color=clRed;}


	   if ((real_state&0x80)==0x80) Shape8->Brush->Color=clLime;    //input-8 trig
		 else {Shape8->Brush->Color=clRed;}

	  }
}
//---------------------------------------------------------------------------
