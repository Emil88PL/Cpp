//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int   numbers[1000];
bool game_begin = false;
int how_meny = 0;
int click=0;


void sequence(){

        Application->ProcessMessages(); Sleep(1000);

        Form1->z1->Picture->LoadFromFile("img/p1.bmp");
        Form1->z2->Picture->LoadFromFile("img/p2.bmp");
        Form1->z3->Picture->LoadFromFile("img/p3.bmp");
        Form1->z4->Picture->LoadFromFile("img/p4.bmp");
        Form1->z5->Picture->LoadFromFile("img/p5.bmp");

        Form1->z1->Enabled = false;
        Form1->z2->Enabled = false;
        Form1->z3->Enabled = false;
        Form1->z4->Enabled = false;
        Form1->z5->Enabled = false;

        Form1->Label1->Caption = "Next round in : 2";
        Application->ProcessMessages(); Sleep(1000);
        Form1->Label1->Caption = "Next round in : 1";
        Application->ProcessMessages(); Sleep(1000);

        Form1->Label1->Caption = "Remember sequence";
        Application->ProcessMessages(); Sleep(1000);


        how_meny++;
        for(int i= 0 ; i<how_meny ;i++){
           switch(numbers[i]){

              case 1:{
              sndPlaySound("snd/d1.wav", SND_ASYNC);
              Form1->z1a->Visible = true;
              }break;

                case 2:{
              sndPlaySound("snd/d2.wav", SND_ASYNC);
              Form1->z2a->Visible = true;
              }break;

                case 3:{
              sndPlaySound("snd/d3.wav", SND_ASYNC);
              Form1->z3a->Visible = true;
              }break;

                case 4:{
              sndPlaySound("snd/d4.wav", SND_ASYNC);
              Form1->z4a->Visible = true;
              }break;

                case 5:{
              sndPlaySound("snd/d5.wav", SND_ASYNC);
              Form1->z5a->Visible = true;
              }break;

           }//switch
           Application->ProcessMessages();Sleep(1200);
           Form1->z1a->Visible = false;
           Form1->z2a->Visible = false;
           Form1->z3a->Visible = false;
           Form1->z4a->Visible = false;
           Form1->z5a->Visible = false;
           Application->ProcessMessages();Sleep(100);
        } //for
        Form1->z1->Enabled = true;
        Form1->z2->Enabled = true;
        Form1->z3->Enabled = true;
        Form1->z4->Enabled = true;
        Form1->z5->Enabled = true;

        Form1->Label1->Caption = "Repeat sequence";

        click=0;

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        randomize();
        for(int i = 0; i < 1000 ; i++){

            numbers[i] = random(5)+1;

        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
       if (game_begin == false) {
            game_begin = true;
            sndPlaySound("snd/start.wav", SND_ASYNC);

             sequence();

       }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1Click(TObject *Sender)
{
   if(game_begin == true){
    click++;
    if (numbers[click-1] !=1){
    how_meny--;
    Label1->Caption = "Game Over! Score: " +IntToStr(how_meny);
    sndPlaySound("snd/end.wav", SND_ASYNC);
    game_begin = false;
    }

    if(click == how_meny){
        Label1->Caption = "Well done!";
        sequence();
    }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z2Click(TObject *Sender)
{
   if(game_begin == true){
    click++;
    if (numbers[click-1] !=2){
    how_meny--;
    Label1->Caption = "Game Over! Score: " +IntToStr(how_meny);
    sndPlaySound("snd/end.wav", SND_ASYNC);
    game_begin = false;
    }

    if(click == how_meny){
        Label1->Caption = "Well done!";
        sequence();
    }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z3Click(TObject *Sender)
{
   if(game_begin == true){
    click++;
    if (numbers[click-1] !=3){
    how_meny--;
    Label1->Caption = "Game Over! Score: " +IntToStr(how_meny);
    sndPlaySound("snd/end.wav", SND_ASYNC);
    game_begin = false;
    }

    if(click == how_meny){
        Label1->Caption = "Well done!";
        sequence();
    }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z4Click(TObject *Sender)
{
   if(game_begin == true){
    click++;
    if (numbers[click-1] !=4){
    how_meny--;
    Label1->Caption = "Game Over! Score: " +IntToStr(how_meny);
    sndPlaySound("snd/end.wav", SND_ASYNC);
    game_begin = false;
    }

    if(click == how_meny){
        Label1->Caption = "Well done!";
        sequence();
    }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z5Click(TObject *Sender)
{
   if(game_begin == true){
    click++;
    if (numbers[click-1] !=5){
    how_meny-- ;
    Label1->Caption = "Game Over! Score: " +IntToStr(how_meny);
    sndPlaySound("snd/end.wav", SND_ASYNC);
    game_begin = false;
    }

    if(click == how_meny){
        Label1->Caption = "Well done!";
        sequence();
    }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        z1->Picture->LoadFromFile("img/p1a.bmp");
        sndPlaySound("snd/d1.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
         z1->Picture->LoadFromFile("img/p1.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
            z2->Picture->LoadFromFile("img/p2a.bmp");
        sndPlaySound("snd/d2.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
            z2->Picture->LoadFromFile("img/p2.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z3MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        z3->Picture->LoadFromFile("img/p3a.bmp");
        sndPlaySound("snd/d3.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        z3->Picture->LoadFromFile("img/p3.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z4MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        z4->Picture->LoadFromFile("img/p4a.bmp");
        sndPlaySound("snd/d4.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        z4->Picture->LoadFromFile("img/p4.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z5MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
           z5->Picture->LoadFromFile("img/p5a.bmp");
        sndPlaySound("snd/d5.wav", SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
           z5->Picture->LoadFromFile("img/p5.bmp");
}
//---------------------------------------------------------------------------
