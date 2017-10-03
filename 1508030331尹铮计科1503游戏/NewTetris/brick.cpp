#include "stdafx.h"
#include "brick.h"
#include <string.h>
#include <malloc.h>//���ٿռ�

/*  I:
     0     1     2      3
     ��          ��  
	 �� �������� �� �������� 
	 ��          �� 
	 ��          ��  
*/
///////////////����//////////////
int CIBrick::shiftLeft(CBin* bin)
{
	int posX;
	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)==0) 
	{
        setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////һ������//////////////
int CIBrick::shiftDown(CBin* bin)
{
	int posY;
     
	posY=getPosY();
	setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int CIBrick::shiftRight(CBin* bin)
{
	int posX;
	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int CIBrick::rotateClockwise(CBin* bin)
{
	int orientation,oldOrientation;
    orientation=getOrientation();
	oldOrientation=orientation;
	if (orientation==3)
		orientation=0;
	else
		orientation=orientation+1;
    setOrientation(orientation);
	if (checkCollision(bin)==0) 
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////��ͻ���//////////////
int CIBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
    //I-brick״̬0
	if (orientation==0) 
	{
        //ש�������߽�
		if(	(posX<0)||
			(posX>width-1)||
			(posY<1)||
			(posY+2>height-1))
		  return 0;
		//ש�����������̶�ש��
		if ( (image[posY-1][posX]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY+1][posX]!=0)||
			 (image[posY+2][posX]!=0))
             return 0;
	}
	//״̬1
	if (orientation==1) 
	{
		if( (posX<2)||
			(posX+1>width-1)||
			(posY<0)||
			(posY>height-1))
		  return 0;
		if ( (image[posY][posX-2]!=0)||
			 (image[posY][posX-1]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0))
             return 0;
	}
    //״̬ 2
	if (orientation==2) 
	{
		if((posX<0)||
			(posX>width-1)||
			(posY<2)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY-2][posX]!=0)||
			 (image[posY-1][posX]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0))
             return 0;
	}
	if (orientation==3) 
	{
		if( (posX<1)||
			(posX+2>width-1)||
			(posY<0)||
			(posY>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0)||
			 (image[posY][posX+2]!=0))
             return 0;
	}

    return 1;
}
void CIBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	//״̬ 0
	if (orientation==0) 
	{
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
		binImage[posY+2][posX]=colour;
    }
	//״̬ 1
	if (orientation==1) 
	{
		binImage[posY][posX-2]=colour;
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
    }	
	//״̬ 2
	if (orientation==2) 
	{
		binImage[posY-2][posX]=colour;
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
    }
	//״̬ 3
	if (orientation==3) 
	{
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY][posX+2]=colour;
    }	
}
///////////////�ö�//////////////
void CIBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:	setPosY(1); break;
	case 1: setPosY(0); break;
	case 2: setPosY(2); break;
	case 3: setPosY(0); break;
	}
}
/*  L:
          0       1        2       3
          ��             ���� 
		  ��    ������     ��      �� 
		  ����  ��         ��  ������		               
*/
///////////////����//////////////
int CLBrick::shiftLeft(CBin* bin)
{
	int posX;

	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)== 0) 
	{
        setPosX(posX);
        return 0;
    }

    return 1;
}
///////////////һ������//////////////
int CLBrick::shiftDown(CBin* bin)
{
	int posY;
	posY=getPosY();
    setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int CLBrick::shiftRight(CBin* bin)
{
	int posX;
 	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int CLBrick::rotateClockwise(CBin* bin)
{
	int orientation,oldOrientation;
    orientation=getOrientation();
	oldOrientation=orientation;

	if (orientation==3)
		orientation=0;
	else
		orientation=orientation+1;
    setOrientation(orientation);
	if (checkCollision(bin)== 0) //�����ͻ��ԭ
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////��ͻ���//////////////
int CLBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
	if (orientation==0) 
	{
		if((posX<0)||
			(posX+1>width-1)||
			(posY<1)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY-1][posX]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY+1][posX]!=0)||
			 (image[posY+1][posX+1]!=0))
             return 0;
	}
	if (orientation==1) 
	{
		if( (posX<1)||
			(posX+1>width-1)||
			(posY<0)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY+1][posX-1]!=0)||
			 (image[posY][posX-1]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0))
             return 0;
	}
	if (orientation==2) 
	{
		if( (posX<1)||
			(posX>width-1)||
			(posY<1)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY-1][posX-1]!=0)||
			 (image[posY-1][posX]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0))
             return 0;
	}
	if (orientation==3) 
	{
		if( (posX<1)||
			(posX+1>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0)||
			 (image[posY-1][posX+1]!=0))
             return 0;
	}
    return 1;
}
void CLBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	if (orientation==0) 
	{
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
		binImage[posY+1][posX+1]=colour;
    }
	if (orientation==1) 
	{
		binImage[posY+1][posX-1]=colour;
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
    }	
	if (orientation==2) 
	{
		binImage[posY-1][posX-1]=colour;
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
    }
	if (orientation==3) 
	{
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY-1][posX+1]=colour;
    }	
}
///////////////�ö�//////////////
void CLBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:	setPosY(1); break;
	case 1: setPosY(0); break;
	case 2: setPosY(1); break;
	case 3: setPosY(1); break;
	
	}
}
/*  S:
              0      1       2       3 
            ����   ��       ����   ��      
		  ����     ����   ����     ���� 
		             ��              ��
*/
///////////////����//////////////
int CSBrick::shiftLeft(CBin* bin)
{
	int posX;

	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)== 0) 
	{
        setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////һ������//////////////
int CSBrick::shiftDown(CBin* bin)
{
	int posY;
     
	posY=getPosY();
    setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int CSBrick::shiftRight(CBin* bin)
{
	int posX;
	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int CSBrick::rotateClockwise(CBin* bin)
{
	int orientation,oldOrientation;
    orientation=getOrientation();
	oldOrientation=orientation;
	if (orientation==3)
		orientation=0;
	else
		orientation=orientation+1;
    setOrientation(orientation);
	if (checkCollision(bin)== 0) 
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////��ͻ���//////////////
int CSBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
	if (orientation==0) 
	{
		if((posX<1)||
			((posX+1)>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY-1][posX]!=0)||
			 (image[posY-1][posX+1]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY][posX-1]!=0))
             return 0;
	}
	if (orientation==1) 
	{
		if( (posX<0)||
			((posX+1)>width-1)||
			(posY<1)||
			((posY+1)>height-1))
		  return 0;
		if ( (image[posY-1][posX]!=0)||
			 (image[posY][posX+1]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY+1][posX+1]!=0))
             return 0;
	}
	if (orientation==2) 
	{
		if((posX<1)||
			((posX+1)>width-1)||
			(posY<0)||
			((posY+1)>height-1))
		  return 0;
		if ( (image[posY][posX+1]!=0)||
			 (image[posY+1][posX]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY+1][posX-1]!=0))
             return 0;
	}
	if (orientation==3) 
	{
		if( (posX<1)||
			(posX>width-1)||
			(posY<1)||
			((posY+1)>height-1))
	    return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY-1][posX-1]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0))
             return 0;
	}
    return 1;
}

void CSBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
 
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	if (orientation==0) 
	{
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY-1][posX+1]=colour;
		binImage[posY][posX-1]=colour;
    }
	if (orientation==1) 
	{
		binImage[posY+1][posX+1]=colour;
        binImage[posY][posX+1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY-1][posX]=colour;
    }	
	if (orientation==2) 
	{
		binImage[posY][posX+1]=colour;
		binImage[posY+1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX-1]=colour;
    }
	if (orientation==3) 
	{
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY-1][posX-1]=colour;
		binImage[posY+1][posX]=colour;
    }	

}
///////////////�ö�//////////////
void CSBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
    switch(newOrient)
	{
	case 0:	setPosY(1); break;
	case 1: setPosY(1); break;
	case 2: setPosY(0); break;
	case 3: setPosY(1); break;
	}
}
/*  O:
        0       1       2     3
      ����    ����    ����   ����
	  ����    ����    ����   ����
*/
///////////////����//////////////
int COBrick::shiftLeft(CBin* bin)
{
	int posX;

	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)== 0) 
	{
        setPosX(posX);
        return 0;
    }

    return 1;
}
///////////////һ������//////////////
int COBrick::shiftDown(CBin* bin)
{
	int posY;
	posY=getPosY();
    setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int COBrick::shiftRight(CBin* bin)
{
	int posX;
 	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int COBrick::rotateClockwise(CBin* bin)
{
	//������鲻��Ҫ��ת
    return 1;
}
///////////////��ͻ���//////////////
int COBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
	//״̬1
	if (orientation==0)   
	{
		if((posX<1)||
			(posX>width-1)||
			(posY<0)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY+1][posX-1]!=0)||
			 (image[posY+1][posX]!=0))
             return 0;
	}
	//״̬2
	if (orientation==1) 
	{
		if( (posX<1)||
			(posX>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY-1][posX-1]!=0)||
			 (image[posY-1][posX]!=0)||
             (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0))
             return 0;
	}
	//״̬3
	if (orientation==2) 
	{
		if( (posX<0)||
			(posX+1>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY-1][posX]!=0)||
			 (image[posY-1][posX+1]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0))
             return 0;
	}
	//״̬4
	if (orientation==3) 
	{
		if( (posX<0)||
			(posX+1>width-1)||
			(posY<0)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY][posX+1]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0)||
			 (image[posY+1][posX+1]!=0))
             return 0;
	}
    return 1;
}
void COBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	if (orientation==0) 
	{
		binImage[posY][posX-1]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX-1]=colour;
		binImage[posY+1][posX]=colour;
    }
	if (orientation==1) 
	{
		binImage[posY-1][posX-1]=colour;
        binImage[posY-1][posX]=colour;
		binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
    }	
	if (orientation==2) 
	{
		binImage[posY-1][posX]=colour;
		binImage[posY-1][posX+1]=colour;
        binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
    }
	if (orientation==3) 
	{
        binImage[posY][posX+1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
		binImage[posY+1][posX+1]=colour;
    }	
}
///////////////�ö�//////////////
void COBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:	setPosY(0); break;
	case 1: setPosY(1); break;
	case 2: setPosY(1); break;
	case 3: setPosY(0); break;
	
	}
}
/*  T:
         0       1     2        3
         ��     ��     ��    ������   
       ����   ������   ����    ��
	     ��            ��   
*/
///////////////����//////////////
int CTBrick::shiftLeft(CBin* bin)
{
	int posX;

	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)== 0) 
	{
        setPosX(posX);
        return 0;
    }

    return 1;
}
///////////////һ������//////////////
int CTBrick::shiftDown(CBin* bin)
{
	int posY;
	posY=getPosY();
    setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int CTBrick::shiftRight(CBin* bin)
{
	int posX;
 	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int CTBrick::rotateClockwise(CBin* bin)
{
	int orientation,oldOrientation;
    orientation=getOrientation();
	oldOrientation=orientation;

	if (orientation==3)
		orientation=0;
	else
		orientation=orientation+1;
    setOrientation(orientation);
	if (checkCollision(bin)== 0) 
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////��ͻ���//////////////
int CTBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
	//״̬1
	if (orientation==0)   
	{
		if((posX<1)||
			(posX>width-1)||
			(posY<1)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY+1][posX-1]!=0)||
			 (image[posY-1][posX]!=0))
             return 0;
	}
	//״̬2
	if (orientation==1) 
	{
		if( (posX<1)||
			(posX+1>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY-1][posX-1]!=0)||
			 (image[posY-1][posX]!=0)||
             (image[posY][posX+1]!=0)||
			 (image[posY][posX]!=0))
             return 0;
	}
	//״̬3
	if (orientation==2) 
	{
		if( (posX<0)||
			(posX+1>width-1)||
			(posY<1)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY+1][posX]!=0)||
			 (image[posY-1][posX+1]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0))
             return 0;
	}
	//״̬4
	if (orientation==3) 
	{
		if( (posX<1)||
			(posX+1>width-1)||
			(posY<0)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY+1][posX+1]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0)||
			 (image[posY+1][posX+1]!=0))
             return 0;
	}
    return 1;
}
void CTBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	if (orientation==0) 
	{
		binImage[posY][posX-1]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX-1]=colour;
		binImage[posY-1][posX]=colour;
    }
	if (orientation==1) 
	{
		binImage[posY-1][posX-1]=colour;
        binImage[posY-1][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY][posX]=colour;
    }	
	if (orientation==2) 
	{
		binImage[posY+1][posX]=colour;
		binImage[posY-1][posX+1]=colour;
        binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
    }
	if (orientation==3) 
	{
        binImage[posY+1][posX+1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
		binImage[posY][posX-1]=colour;
    }	
}
///////////////�ö�//////////////
void CTBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:	setPosY(1); break;
	case 1: setPosY(1); break;
	case 2: setPosY(1); break;
	case 3: setPosY(0); break;
	
	}
}
/*  J:
            0       1      2       3
            ��           ����   ������
            ��   ��      ��         ��
	      ����   ������  ��     
*/
///////////////����//////////////
int CJBrick::shiftLeft(CBin* bin)
{
	int posX;

	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)== 0) 
	{
        setPosX(posX);
        return 0;
    }

    return 1;
}
///////////////һ������//////////////
int CJBrick::shiftDown(CBin* bin)
{
	int posY;
	posY=getPosY();
    setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int CJBrick::shiftRight(CBin* bin)
{
	int posX;
 	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int CJBrick::rotateClockwise(CBin* bin)
{
	int orientation,oldOrientation;
    orientation=getOrientation();
	oldOrientation=orientation;

	if (orientation==3)
		orientation=0;
	else
		orientation=orientation+1;
    setOrientation(orientation);
	if (checkCollision(bin)== 0) 
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////��ͻ���//////////////
int CJBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
	//״̬1
	if (orientation==0)   
	{
		if((posX<1)||
			(posX>width-1)||
			(posY<2)||
			(posY>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY-2][posX]!=0)||
			 (image[posY-1][posX]!=0))
             return 0;
	}
	//״̬2
	if (orientation==1) 
	{
		if( (posX<0)||
			(posX+2>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY][posX+2]!=0)||
			 (image[posY-1][posX]!=0)||
             (image[posY][posX+1]!=0)||
			 (image[posY][posX]!=0))
             return 0;
	}
	//״̬3
	if (orientation==2) 
	{
		if( (posX<0)||
			(posX+1>width-1)||
			(posY<0)||
			(posY+2>height-1))
		  return 0;
		if ( (image[posY+1][posX]!=0)||
			 (image[posY+2][posX]!=0)||
             (image[posY][posX]!=0)||
			 (image[posY][posX+1]!=0))
             return 0;
	}
	//״̬4
	if (orientation==3) 
	{
		if( (posX<2)||
			(posX>width-1)||
			(posY<0)||					//�Ķ�!!!!posY < 0
			(posY+1>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX-2]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0))
             return 0;
	}
    return 1;
}
void CJBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	if (orientation==0) 
	{
		binImage[posY][posX-1]=colour;
        binImage[posY][posX]=colour;
		binImage[posY-2][posX]=colour;
		binImage[posY-1][posX]=colour;
    }
	if (orientation==1) 
	{
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY][posX+2]=colour;
    }	
	if (orientation==2) 
	{
		binImage[posY+1][posX]=colour;
		binImage[posY][posX+1]=colour;
        binImage[posY+2][posX]=colour;
		binImage[posY][posX]=colour;
    }
	if (orientation==3) 
	{
        binImage[posY+1][posX]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX-2]=colour;
		binImage[posY][posX-1]=colour;
    }	
}
///////////////�ö�//////////////
void CJBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:	setPosY(2); break;
	case 1: setPosY(1); break;
	case 2: setPosY(0); break;
	case 3: setPosY(0); break;
	
	}
}
/*  Z:
         0        1       2        3
       ����       ��     ����    ��   
         ����   ����   ����      ����
                ��                 ��
*/
///////////////����//////////////
int CZBrick::shiftLeft(CBin* bin)
{
	int posX;

	posX=getPosX();
    setPosX(posX-1);
    if (checkCollision(bin)== 0) 
	{
        setPosX(posX);
        return 0;
    }

    return 1;
}
///////////////һ������//////////////
int CZBrick::shiftDown(CBin* bin)
{
	int posY;
	posY=getPosY();
    setPosY(posY+1);
    if (checkCollision(bin)== 0) 
	{
		setPosY(posY);
        return 0;
    }
    return 1;
}
///////////////����//////////////
int CZBrick::shiftRight(CBin* bin)
{
	int posX;
 	posX=getPosX();
    setPosX(posX+1);
    if (checkCollision(bin)==0) 
	{
		setPosX(posX);
        return 0;
    }
    return 1;
}
///////////////��ת//////////////
int CZBrick::rotateClockwise(CBin* bin)
{
	int orientation,oldOrientation;
    orientation=getOrientation();
	oldOrientation=orientation;

	if (orientation==3)
		orientation=0;
	else
		orientation=orientation+1;
    setOrientation(orientation);
	if (checkCollision(bin)== 0) 
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////��ͻ���//////////////
int CZBrick::checkCollision(CBin* bin)
{
	int width;
    int height;
    unsigned char** image;
	int orientation;
	int posX;
	int posY;
	width=bin->getWidth();
	height=bin->getHeight();
	image = new unsigned char* [height];
    for (int i = 0; i<height; i++) 
	{
        image[i] = new unsigned char [width]; 
    }
	bin->getImage(image);
    orientation=getOrientation();
    posX=getPosX();
	posY=getPosY();
	//״̬1
	if (orientation==0)   
	{
		if((posX<1)||
			(posX+1>width-1)||
			(posY<1)||
			(posY>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY][posX+1]!=0)||
			 (image[posY-1][posX]!=0))
             return 0;
	}
	//״̬2
	if (orientation==1) 
	{
		if( (posX<0)||
			(posX+1>width-1)||
			(posY<1)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY][posX+1]!=0)||
			 (image[posY-1][posX]!=0)||
             (image[posY+1][posX]!=0)||
			 (image[posY][posX]!=0))
             return 0;
	}
	//״̬3
	if (orientation==2) 
	{
		if( (posX<1)||
			(posX+1>width-1)||
			(posY<0)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY+1][posX]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY][posX-1]!=0)||
			 (image[posY][posX+1]!=0))
             return 0;
	}
	//״̬4
	if (orientation==3) 
	{
		if( (posX<1)||
			(posX>width-1)||
			(posY<1)||
			(posY+1>height-1))
		  return 0;
		if ( (image[posY][posX-1]!=0)||
			 (image[posY-1][posX]!=0)||
			 (image[posY][posX]!=0)||
			 (image[posY+1][posX]!=0))
             return 0;
	}
    return 1;
}
void CZBrick::operator>>(unsigned char** binImage)
{
	int orientation;
	int posX;
	int posY;
	unsigned char colour;
	posX=getPosX();
	posY=getPosY();
	orientation=getOrientation();
	colour=getColour();
	if (orientation==0) 
	{
		binImage[posY][posX-1]=colour;
        binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY-1][posX]=colour;
    }
	if (orientation==1) 
	{
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY+1][posX]=colour;
    }	
	if (orientation==2) 
	{
		binImage[posY+1][posX]=colour;
		binImage[posY][posX+1]=colour;
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
    }
	if (orientation==3) 
	{
        binImage[posY+1][posX]=colour;
		binImage[posY][posX]=colour;
		binImage[posY-1][posX]=colour;
		binImage[posY][posX-1]=colour;
    }	
}
///////////////�ö�//////////////
void CZBrick::putAtTop(int newOrient, int newPosX)
{
    setPosX(newPosX);
	setOrientation(newOrient);
	switch(newOrient)
	{
	case 0:	setPosY(1); break;
	case 1: setPosY(1); break;
	case 2: setPosY(0); break;
	case 3: setPosY(1); break;
	}
}
