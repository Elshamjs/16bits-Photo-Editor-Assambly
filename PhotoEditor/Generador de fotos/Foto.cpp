//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Foto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrm_Foto *Frm_Foto;

#include <string.h>
#include <stdio.h>
#include <io.h>
#include <sys\stat.h>
#include <fcntl.h>

#define  TFOTOx 641
#define  TFOTOy 641

char FOTO_BINARY[TFOTOx][TFOTOy];
void guardarArchivo(void);
//---------------------------------------------------------------------------
__fastcall TFrm_Foto::TFrm_Foto(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrm_Foto::But_AbrirClick(TObject *Sender)
{
OD_AbrirDialogo->Options.Clear();
OD_AbrirDialogo->Options << ofFileMustExist;
OD_AbrirDialogo->Filter = "Archivos BMP de 16 colores (*.bmp)|*.bmp";
OD_AbrirDialogo->Execute();

if(OD_AbrirDialogo->FileName != "")
{
Img_Imagen->Picture=NULL;
Img_Imagen->Refresh();


Img_Imagen->Picture->Bitmap->LoadFromFile(OD_AbrirDialogo->FileName);
Img_Imagen->AutoSize = true;
}

}
//---------------------------------------------------------------------------


void __fastcall TFrm_Foto::But_ProcesarClick(TObject *Sender)
{ int aux,b=0;


try{
for(int i = 0; i < TFOTOx; i++)
   for(int j = 0; j < TFOTOy; j++)FOTO_BINARY[i][j] = '\0';

PB->Max = Img_Imagen->Picture->Width;
for(int i = 0; i < Img_Imagen->Picture->Width; i++)
 {
   for(int j = 0; j < Img_Imagen->Picture->Height; j++)
    { aux = Img_Imagen->Canvas->Pixels[i][j];
     switch(Img_Imagen->Canvas->Pixels[i][j])
      {case 0:{FOTO_BINARY[j][i] = '0';break;}
       case 8388608:{FOTO_BINARY[j][i] = '1';break;}
       case 32768:{FOTO_BINARY[j][i] = '2';break;}
       case 8421376:{FOTO_BINARY[j][i] = '3';break;}
       case 128:{FOTO_BINARY[j][i] = '4';break;}
       case 8388736:{FOTO_BINARY[j][i] = '5';break;}
       case 32896:{FOTO_BINARY[j][i] = '6';break;}
       case 12632256:{FOTO_BINARY[j][i] = '7';break;}
       case 8421504:{FOTO_BINARY[j][i] = '8';break;}
       case 16711680:{FOTO_BINARY[j][i] = '9';break;}
       case 65280:{FOTO_BINARY[j][i] = 'A';break;}
       case 16776960:{FOTO_BINARY[j][i] = 'B';break;}
       case 255:{FOTO_BINARY[j][i] = 'C';break;}
       case 16711935:{FOTO_BINARY[j][i] = 'D';break;}
       case 65535:{FOTO_BINARY[j][i] = 'E';break;}
       case 16777215:{FOTO_BINARY[j][i] = 'F';break;}

      default:{ShowMessage("Esta foto contiene pixeles con mucha calidad de color.  Nota: Utilice unicamente imagenes de 16 colores, producidas por el programa PAINT de Windows.  ");
        i = Img_Imagen->Picture->Width;
        j = Img_Imagen->Picture->Height;
        b = 1;
        break;

        }
      }
    }
    PB->Position = i;
 }
   for(int j = 0; j < Img_Imagen->Picture->Height; j++)
   FOTO_BINARY[j][Img_Imagen->Picture->Width]='@';

}catch(...)
{ShowMessage("Errror al procesar la imagen");}
 if (b == 0)guardarArchivo();
}
//---------------------------------------------------------------------------
void guardarArchivo(void)
{
int H;
  char pix;
  FILE *P;

  try{
   Frm_Foto->PB2->Max = Frm_Foto->Img_Imagen->Picture->Height;
   P = fopen("IMAGEN.IER", "wb+");
   for(int i = 0; i < Frm_Foto->Img_Imagen->Picture->Height; i++)
   {for(int j = 0; j < Frm_Foto->Img_Imagen->Picture->Width+1; j++)
    {pix = FOTO_BINARY[i][j];
     fwrite(&pix,sizeof(pix),1,P);
    }
    Frm_Foto->PB2->Position = i;
   }
   fseek(P, 0L, SEEK_END);
   pix = '%';
   fwrite(&pix,sizeof(pix),1,P);


   fclose(P);
   ShowMessage("El archivo se genero correctamente");
   Frm_Foto->PB->Position = 0;
   Frm_Foto->PB2->Position = 0;
  }catch(...)
  {ShowMessage("Error al intentar procesar el nuevo archivo");}

}



