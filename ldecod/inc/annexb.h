
/*!
 *************************************************************************************
 * \file annexb.h
 *
 * \brief
 *    Annex B byte stream buffer handling.
 *
 *************************************************************************************
 */

#ifndef _ANNEXB_H_
#define _ANNEXB_H_

#include "nalucommon.h"

typedef struct annex_b_struct 
{
  int  BitStreamFile;                //!< the bit stream file fd�ļ�������
  byte *iobuffer;					//h264�ļ�,����Ϊbytesinbuffer
  byte *iobufferread;
  int bytesinbuffer;		//ʵ�ʶ��뵽iobuffer�ĳ���
  int is_eof;
  int iIOBufferSize;		//һ���Զ�ȡ��iobuffer�ĳ���

  int IsFirstByteStreamNALU;	//NALU��һλΪ0 0x67:0110 0111
  int nextstartcodebytes;  //��ʼ��λ��
  byte *Buf;				//����ǰ׺������  
} ANNEXB_t;

extern int  get_annex_b_NALU (VideoParameters *p_Vid, NALU_t *nalu, ANNEXB_t *annex_b);

extern void open_annex_b     (char *fn, ANNEXB_t *annex_b);
extern void close_annex_b    (ANNEXB_t *annex_b);
extern void malloc_annex_b   (VideoParameters *p_Vid, ANNEXB_t **p_annex_b);
extern void free_annex_b     (ANNEXB_t **p_annex_b);
extern void init_annex_b     (ANNEXB_t *annex_b);
extern void reset_annex_b    (ANNEXB_t *annex_b);
#endif

