#include "stdafx.h"
#include "brick.h"
#include <string.h>
#include <malloc.h>//¿ª±Ù¿Õ¼ä

/*  I:
     0     1     2      3
     ¡ö          ¡ö  
	 ¡ö ¡ö¡ö¡ö¡ö ¡ö ¡ö¡ö¡ö¡ö 
	 ¡ö          ¡ö 
	 ¡ö          ¡ö  
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
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
///////////////³åÍ»¼ì²é//////////////
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
    //I-brick×´Ì¬0
	if (orientation==0) 
	{
        //×©¿éÅöµ½±ß½ç
		if(	(posX<0)||
			(posX>width-1)||
			(posY<1)||
			(posY+2>height-1))
		  return 0;
		//×©¿éÅöµ½ÆäËû¹Ì¶¨×©¿é
		if ( (image[posY-1][posX]!=0)||
			 (image[posY][posX]!=0)||
             (image[posY+1][posX]!=0)||
			 (image[posY+2][posX]!=0))
             return 0;
	}
	//×´Ì¬1
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
    //×´Ì¬ 2
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
	//×´Ì¬ 0
	if (orientation==0) 
	{
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
		binImage[posY+2][posX]=colour;
    }
	//×´Ì¬ 1
	if (orientation==1) 
	{
		binImage[posY][posX-2]=colour;
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
    }	
	//×´Ì¬ 2
	if (orientation==2) 
	{
		binImage[posY-2][posX]=colour;
		binImage[posY-1][posX]=colour;
        binImage[posY][posX]=colour;
		binImage[posY+1][posX]=colour;
    }
	//×´Ì¬ 3
	if (orientation==3) 
	{
        binImage[posY][posX-1]=colour;
		binImage[posY][posX]=colour;
		binImage[posY][posX+1]=colour;
		binImage[posY][posX+2]=colour;
    }	
}
///////////////ÖÃ¶¥//////////////
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
          ¡ö             ¡ö¡ö 
		  ¡ö    ¡ö¡ö¡ö     ¡ö      ¡ö 
		  ¡ö¡ö  ¡ö         ¡ö  ¡ö¡ö¡ö		               
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
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
	if (checkCollision(bin)== 0) //Èç¹û³åÍ»Ôò»¹Ô­
	{
        setOrientation(oldOrientation);
        return 0;
    }
    return 1;
}
///////////////³åÍ»¼ì²é//////////////
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
///////////////ÖÃ¶¥//////////////
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
            ¡ö¡ö   ¡ö       ¡ö¡ö   ¡ö      
		  ¡ö¡ö     ¡ö¡ö   ¡ö¡ö     ¡ö¡ö 
		             ¡ö              ¡ö
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
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
///////////////³åÍ»¼ì²é//////////////
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
///////////////ÖÃ¶¥//////////////
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
      ¡ö¡ö    ¡ö¡ö    ¡ö¡ö   ¡ö¡ö
	  ¡ö¡ö    ¡ö¡ö    ¡ö¡ö   ¡ö¡ö
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
int COBrick::rotateClockwise(CBin* bin)
{
	//Õâ¸ö·½¿é²»ÐèÒªÐý×ª
    return 1;
}
///////////////³åÍ»¼ì²é//////////////
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
	//×´Ì¬1
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
	//×´Ì¬2
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
	//×´Ì¬3
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
	//×´Ì¬4
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
///////////////ÖÃ¶¥//////////////
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
         ¡ö     ¡ö     ¡ö    ¡ö¡ö¡ö   
       ¡ö¡ö   ¡ö¡ö¡ö   ¡ö¡ö    ¡ö
	     ¡ö            ¡ö   
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
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
///////////////³åÍ»¼ì²é//////////////
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
	//×´Ì¬1
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
	//×´Ì¬2
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
	//×´Ì¬3
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
	//×´Ì¬4
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
///////////////ÖÃ¶¥//////////////
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
            ¡ö           ¡ö¡ö   ¡ö¡ö¡ö
            ¡ö   ¡ö      ¡ö         ¡ö
	      ¡ö¡ö   ¡ö¡ö¡ö  ¡ö     
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
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
///////////////³åÍ»¼ì²é//////////////
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
	//×´Ì¬1
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
	//×´Ì¬2
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
	//×´Ì¬3
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
	//×´Ì¬4
	if (orientation==3) 
	{
		if( (posX<2)||
			(posX>width-1)||
			(posY<0)||					//¸Ä¶¯!!!!posY < 0
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
///////////////ÖÃ¶¥//////////////
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
       ¡ö¡ö       ¡ö     ¡ö¡ö    ¡ö   
         ¡ö¡ö   ¡ö¡ö   ¡ö¡ö      ¡ö¡ö
                ¡ö                 ¡ö
*/
///////////////×óÒÆ//////////////
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
///////////////Ò»¼üÏÂÒÆ//////////////
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
///////////////ÓÒÒÆ//////////////
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
///////////////Ðý×ª//////////////
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
///////////////³åÍ»¼ì²é//////////////
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
	//×´Ì¬1
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
	//×´Ì¬2
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
	//×´Ì¬3
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
	//×´Ì¬4
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
///////////////ÖÃ¶¥//////////////
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
