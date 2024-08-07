#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "String.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "KeyPad_Int.h"

#define F_CPU  8000000
#include <util/delay.h>




int main(void)
{
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	
	
	typedef enum{
		ADD_FLAG,
		SUBTRACT_FLAG,
		DIVISION_FLAG,
		MULTI_FLAG,
		Eqal_FlAG,
		DEFAULT_FLAG
	}math_operation_t;
	
	u8 k,i=0,j=0,num=0,flag=0,c=0,c2=0,num1=0,num_total=0;
	math_operation_t op=DEFAULT_FLAG;
	
	while (1)
	{
		k=KEYPAD_GetKey();
		if (k!=NO_KEY)
		{
			if (k>='0'&&k<='9')
			{
				if (flag==1)
				{
					LCD_ClearCursor(1,1,c);
					LCD_SetCursor(1,1);
					c=0;
					flag=0;
				}
				LCD_WriteChar(k);
				num=num*10+k-'0';
				c++;
			}
			else if (k=='+')
			{
				
				if (flag==1)
				{
					LCD_ClearCursor(1,1,c);
					LCD_SetCursor(1,1);
					op=ADD_FLAG;
					num1=num_total;
					LCD_WriteNumber(num1);
					LCD_WriteChar(k);
					flag=0;
				}
				else
				{
					LCD_WriteChar(k);
					op=ADD_FLAG;
					num1=num;
				}
				c++;
				num=0;
			}
			else if (k=='-')
			{
				
				if (flag==1)
				{
					LCD_ClearCursor(1,1,c);
					LCD_SetCursor(1,1);
					op=SUBTRACT_FLAG;
					num1=num_total;
					LCD_WriteNumber(num1);
					LCD_WriteChar(k);
					flag=0;
				}
				else
				{
					LCD_WriteChar(k);
					op=SUBTRACT_FLAG;
					num1=num;
				}
				c++;
				num=0;
			}
			else if (k=='*')
			{
				
				if (flag==1)
				{
					LCD_ClearCursor(1,1,c);
					LCD_SetCursor(1,1);
					op=MULTI_FLAG;
					num1=num_total;
					LCD_WriteNumber(num1);
					LCD_WriteChar(k);
					flag=0;
				}
				else
				{
					LCD_WriteChar(k);
					op=MULTI_FLAG;
					num1=num;
				}
				c++;
				num=0;
			}
			else if (k=='/')
			{
				
				if (flag==1)
				{
					LCD_ClearCursor(1,1,c);
					op=DIVISION_FLAG;
					LCD_SetCursor(1,1);
					num1=num_total;
					LCD_WriteNumber(num1);
					LCD_WriteChar(k);
					flag=0;
				}
				else
				{
					LCD_WriteChar(k);
					op=DIVISION_FLAG;
					num1=num;
				}
				c++;
				num=0;
			}
			else if (k=='=')
			{
				flag=1;
				for (c2;num_total>0;c2++)
				{
					num_total=num_total/10;
				}
				LCD_ClearCursor(2,1,c2);
				LCD_SetCursor(2,1);
				c2=0;
				switch(op)
				{
					case ADD_FLAG:
					num_total=num1+num;
					LCD_WriteNumber(num_total);
					num=0;
					num1=0;
					break;
					case SUBTRACT_FLAG:
					num_total=num1-num;
					LCD_WriteNumber(num_total);
					num=0;
					num1=0;
					break;
					case MULTI_FLAG:
					num_total=num1*num;
					LCD_WriteNumber(num_total);
					num=0;
					num1=0;
					break;
					case DIVISION_FLAG:
					num_total=num1/num;
					LCD_WriteNumber(num_total);
					num=0;
					num1=0;
					break;
					default:
					num_total=num;
					LCD_WriteNumber(num_total);
					num=0;
					break;

				}
				op=DEFAULT_FLAG;
				
				
			}
			else if (k=='c')
			{
				LCD_Clear();
			}
			
			
		}
		
		
	}
	
}
