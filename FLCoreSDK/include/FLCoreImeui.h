//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreImeui.h
//	Module:			FLCoreImeui.lib
//	Description:	Interface to imeui.dll
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREIMEUI_H_
#define _FLCOREIMEUI_H_

#include "FLCoreDefs.h"

#pragma comment( lib, "FLCoreImeui.lib" )

class EXTERN CCaret
{
public:
	 CCaret(struct HWND__ *);
	 ~CCaret(void);
	 class CCaret & operator=(class CCaret const &);
	 void SetBlink(bool);
	 bool SetPos(int,int);
	 void Show(bool);
	 bool UpdateCaret(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

class EXTERN CInputBox
{
public:
	 CInputBox(class CInputBox const &);
	 CInputBox(void);
	 virtual ~CInputBox(void);
	 class CInputBox & operator=(class CInputBox const &);
	 virtual bool CharFilter(unsigned short)const ;
	 class CCaret * GetCaret(void);
	 unsigned long GetMarginX(void)const ;
	 unsigned long GetMarginY(void)const ;
	 struct tagRECT const * GetRect(void);
	 unsigned short * GetTitle(void);
	 virtual bool HandleKey(unsigned int);
	 bool HandleMultiByteChar(char);
	 bool HandleWideChar(unsigned short);
	 virtual void OnKillFocus(void);
	 virtual void OnSetFocus(void);
	 virtual void Resize(struct tagRECT const *);
	 void SetInputBufferSize(unsigned long);
	 void SetMargins(unsigned long,unsigned long);
	 void SetTitle(unsigned short *);
	 virtual void UpdatedText(unsigned short const *);

protected:
	 void AddChar(unsigned short);
	 bool DeleteChar(void);
	 int GetFreeInputBufferSize(void)const ;
	 virtual bool MoveCaret(bool,bool);
	 bool MoveCaretHead(void);
	 bool MoveCaretLeft(bool);
	 bool MoveCaretRight(bool);
	 bool MoveCaretTail(void);
	 virtual void RecalcCaretPos(void);
	 void ResetCaret(void);
	 virtual void ToggleInsertMode(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN IMEFocus
{
	 IMEFocus(struct IMEFocus const &);
	 IMEFocus(struct HWND__ *);
	 virtual ~IMEFocus(void);
	 struct IMEFocus & operator=(struct IMEFocus const &);
	 void Draw(void *);
	 struct _IMEUI_APPEARANCE const * GetDefaultAppearance(void);
	 struct IMEInputBox * GetFocus(void)const ;
	 struct IMEInputBox * GetInputBox(int)const ;
	 static struct IMEFocus * __cdecl GetSingleton(void);
	 class CImeUiFont_Base * GetSymbolFont(void);
	 bool HasRevertedLevel3Drawing(void)const ;
	 bool IgnoreHotKey(struct tagMSG const *)const ;
	 bool IsImeAvailable(void)const ;
	 int NumInputBoxes(void)const ;
	 virtual bool OnChar(unsigned int);
	 virtual bool OnKeyDown(unsigned int);
	 virtual void OnKillFocus(void);
	 virtual bool OnLButtonDown(struct HWND__ *,unsigned int,long);
	 virtual bool OnLButtonUp(struct HWND__ *,unsigned int,long);
	 virtual bool OnMouseMove(struct HWND__ *,unsigned int,long);
	 virtual void OnSetFocus(void);
	 virtual void OnSize(struct HWND__ *,unsigned int,long);
	 struct IMEInputBox * RegisterInputBox(struct IMEInputBox *);
	 struct IMEInputBox * RemoveInputBox(int);
	 struct IMEInputBox * RemoveInputBox(struct IMEInputBox *);
	 void RevertLevel3Drawing(bool);
	 virtual void SetFocus(struct IMEInputBox *,bool);
	 void SetSupportLevel(int);
	 bool WndProc(struct HWND__ *,unsigned int,unsigned int,long,int *);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

struct EXTERN IMEInputBox
{
	 IMEInputBox(struct IMEInputBox const &);
	 IMEInputBox(struct tagLOGFONTA const *);
	 virtual ~IMEInputBox(void);
	 struct IMEInputBox & operator=(struct IMEInputBox const &);
	 struct tagLOGFONTA const * GetFont(void);
	 struct HFONT__ * GetHFont(void);
	 bool IsImeOn(void)const ;
	 virtual void OnKillFocus(void);
	 virtual void OnSetFocus(void);
	 virtual void Resize(struct tagRECT const *);
	 void SetFont(struct tagLOGFONTA *);

protected:
	 virtual bool CalcCaretPos(struct tagPOINT *);
	 virtual void ImeShowToolbar(bool);
	 virtual void ToggleInsertMode(void);
	 void UpdateAppearance(void);

public:
	unsigned char data[OBJECT_DATA_SIZE];
};

#endif // _FLCOREIMEUI_H_