//---------------------------------------------------------------------------

#ifndef FotoH
#define FotoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrm_Foto : public TForm
{
__published:	// IDE-managed Components
        TOpenDialog *OD_AbrirDialogo;
        TBitBtn *But_Abrir;
        TImage *Img_Imagen;
        TBitBtn *But_Procesar;
        TProgressBar *PB;
        TProgressBar *PB2;
        TLabel *Progreso;
        void __fastcall But_AbrirClick(TObject *Sender);
        void __fastcall But_ProcesarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrm_Foto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrm_Foto *Frm_Foto;
//---------------------------------------------------------------------------
#endif
