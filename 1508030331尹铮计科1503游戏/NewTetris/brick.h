
//����Ӧ���ڽ�ѧ��������ע��������
//�ο����ף����и��������� C/C++���Գ������ �������������ӿƼ���ѧ������ 2012 318-329
#include"stdafx.h"
#ifndef _BRICK_H   //�����ظ�����
#define _BRICK_H

#include "bin.h"  

class CBrick    //����
{
    protected:
        int orientation;
        int posX;
        int posY;
        unsigned char colour;
        
    public:
        int getOrientation(){ return orientation; };
        int getPosX(){ return posX; };
        int getPosY(){ return posY; };
        unsigned char getColour(){ return colour; };
        
        void setOrientation(int newOrient){ orientation = newOrient; };
        void setPosX(int newPosX){ posX = newPosX; };
        void setPosY(int newPosY){ posY = newPosY; };
        void setColour(unsigned char newColour){ colour = newColour; };
        
        virtual int shiftLeft(CBin* bin)=0;
        virtual int shiftRight(CBin* bin)=0;
        virtual int shiftDown(CBin* bin)=0;
        virtual int rotateClockwise(CBin* bin)=0;
        
        virtual int checkCollision(CBin* bin)=0;
        
        virtual void operator>>(unsigned char** binImage)=0;
        virtual void putAtTop(int newOrient, int newPosX)=0;
};

/*  I:

      ��������      ��
                    ��
					��
					��
*/
class CIBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};
/*  L:
          ��
      ������
*/
class CLBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};
/*  S:
          ����
        ����
*/
class CSBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};
/*  O:
      ����
	  ����
*/
class COBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};
/*  T:
     ������
       ��
*/
class CTBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};
/*  J:
             ��
             ������
*/
class CJBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};
/*  J:
         ����
           ����
*/
class CZBrick : public CBrick 
{
    public:
        int shiftLeft(CBin* bin);
        int shiftRight(CBin* bin);
        int shiftDown(CBin* bin);
        int rotateClockwise(CBin* bin);
        
        int checkCollision(CBin* bin);
        
        void operator>>(unsigned char** binImage);
        void putAtTop(int newOrient, int newPosX);
};

#endif

