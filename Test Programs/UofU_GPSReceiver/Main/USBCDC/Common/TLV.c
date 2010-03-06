// TLV Access Function Definition file

#include "TLV_descriptors.h"

/* Function Defintion
   Passing parameters:
      tag - The specific/particular tag information (length and data address location) required by the user
      *length - Address of the variable (byte long) where the number of bytes allocated for the particular 'tag' is to be stored
      *data_address - Address of the variable (word long) which is used to access the value info of the the particular 'tag' (in the TLV structure)

  NOTE: If 'length' and 'data_address' returned = 0, it implies that there was no tag match. This condition can be checked for in the 
        main function that calls this Get_TLV_info(..) function and appropriate actions can be taken
*/

void Get_TLV_info(unsigned char tag, unsigned char *length, unsigned int *data_address)
{
  char *TLV_address = (char *)TLV_START;               // TLV Structure Start Address


  while((*TLV_address != tag) && (*TLV_address != TLV_TAGEND) && ((unsigned int)TLV_address < TLV_END))
  {
    TLV_address += *(TLV_address+1) + 2;               // add (Current TAG address + LENGTH) + 2
  }
  if (*TLV_address == tag)                             // Check if Tag match happened..
  {
    *length = *(TLV_address+1);                        // Return length = Address + 1 
    *data_address = (unsigned int)(TLV_address+2);     // Return address of first data/value info = Address + 2 
  }
  else                                                 // If there was no tag match and the end of TLV structure was reached..
  {
    *length = 0;                                       // Return 0 for TAG not found
    data_address = 0;                                  // Return 0 for TAG not found
  }
}
