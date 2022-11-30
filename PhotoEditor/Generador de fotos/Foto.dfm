object Frm_Foto: TFrm_Foto
  Left = 190
  Top = 170
  Width = 836
  Height = 472
  VertScrollBar.Position = 7
  Caption = 'Frm_Foto'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object Img_Imagen: TImage
    Left = 24
    Top = 65
    Width = 425
    Height = 257
    AutoSize = True
  end
  object Progreso: TLabel
    Left = 968
    Top = 9
    Width = 42
    Height = 13
    Caption = 'Progreso'
  end
  object But_Abrir: TBitBtn
    Left = 24
    Top = 17
    Width = 89
    Height = 25
    Caption = 'Abrir'
    TabOrder = 0
    OnClick = But_AbrirClick
  end
  object But_Procesar: TBitBtn
    Left = 120
    Top = 17
    Width = 121
    Height = 25
    Caption = 'Procesar Imagen'
    TabOrder = 1
    OnClick = But_ProcesarClick
  end
  object PB: TProgressBar
    Left = 960
    Top = 33
    Width = 25
    Height = 657
    Min = 0
    Max = 100
    Orientation = pbVertical
    Smooth = True
    TabOrder = 2
  end
  object PB2: TProgressBar
    Left = 992
    Top = 33
    Width = 25
    Height = 657
    Min = 0
    Max = 100
    Orientation = pbVertical
    Smooth = True
    TabOrder = 3
  end
  object OD_AbrirDialogo: TOpenDialog
    Left = 248
    Top = 16
  end
end
