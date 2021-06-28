//////////////////////////////////////////////////////////////////////
//	Project FLCoreSDK v1.1
//--------------------------
//
//	File:			FLCoreDefs.h
//	Module:			
//	Description:	Common declarations
//
//	Web: www.skif.be/flcoresdk.php
//  
//
//////////////////////////////////////////////////////////////////////
#ifndef _FLCOREDEFS_H_
#define _FLCOREDEFS_H_

#define EXTERN 				__declspec(dllimport)
#define OBJECT_DATA_SIZE	2048

template <int size> struct TString
{
	int len;
	char data[size+1];
	
	TString():len(0) { data[0] = 0; }
};

class Vector
{
public:
	float x,y,z;
};

class Matrix
{
public:
	float m[3][3];
};

#endif // _FLCOREDEFS_H_
