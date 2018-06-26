//////////////////////////////////////////////////////////////////////
//
// wImage.h: interface for the wImage class.
//
// 20071002 
//   �⺻���� ��� ���� �Ϸ� 
//
// 20081012 
//   ������ Ÿ���� �����Ͽ���. 
//	 ex) MV_Y8 0x0211 = 
//	  0 : ���� ù�ڸ��� ������ 0
//	  2 : category
//	  1 : category ���� ����
//	  1 : �ȼ��� depth 1 
// 20081014 
//   GetNumPixels() �Լ� �߰�  
//
// 20100107 
//   Load(), Save() �Լ� ����
//   Load() �Լ����� �پ��� ����� ���� bmp ������ ���� �� �ֵ��� ����
//
//////////////////////////////////////////////////////////////////////
#if !defined(WIMAGE_H)
#define WIMAGE_H

#ifndef S8
#define	S8  	char
#define S16 	short
#define S32 	int
#define U8  	unsigned char
#define U16 	unsigned short
#define U32 	unsigned int
#endif

#ifndef TRUE
#define	TRUE	1
#define	FALSE	0
#endif

/*
#define MV_RGB32				0x0004 
#define MV_RGB24     			0x1103
#define MV_RGB16     			0x2202
#define MV_RGB15     			0x3302
#define MV_YUV422    			0x4402
#define MV_Y8        			0x6601
*/
#define MV_RGB15     			0x0112
#define MV_RGB16     			0x0122
#define MV_RGB24     			0x0133
#define MV_RGB32				0x0134

#define MV_Y8        			0x0211	// unsigned char 8bit 1 channel format
#define MV_YUV422    			0x0222

#define MV_S8        			0x0311
#define MV_S16        			0x0322
#define MV_S32        			0x0334

#define MV_U8        			0x0411
#define MV_U16        			0x0422
#define MV_U32        			0x0433

#define MV_FLOAT       			0x0514
#define MV_DOUBLE      			0x0528

class wImage  
{
public:
	wImage();
	wImage(int Width, int Height, int Type);
	virtual ~wImage();
	void operator=(wImage &rhs);
	int  operator==(wImage &rhs);
	int  operator!=(wImage &rhs);

	void Alloc(int Width, int Height, int Type);
	void Alloc(wImage& Image, int Type=0);
	void Free();

	void *GetPtr2D();
	void *GetPtr1D();
	int  GetType() {return Type;};
	int	 GetWidth() {return Width;};
	int	 GetHeight() {return Height;};
	int	 GetDepth() {return (Type&0xf);};
	int	 GetSize() {return (Width*Height*GetDepth());};
	int	 GetNumPixels() {return (Width*Height);};

#ifdef _WIN32
	int  Load(string FileName);
	int  Save(string FileName);
#endif

public:
	int 	Width;			
	int 	Height;
	int		Type;			// DataType : color_format|color_depth

private:
	// ���� ������ 
	void** 	ppBuf;	
};

#endif // !defined(WIMAGE_H)
