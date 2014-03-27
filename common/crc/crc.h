#ifndef AEONGAMES_CRC_H
#define AEONGAMES_CRC_H
/**********************************************************************
 *
 * Filename:    crc.h
 *
 * Description: A header file describing the various CRC standards.
 *
 * Notes:
 *
 *
 * Copyright (c) 2000 by Michael Barr.  This software is placed into
 * the public domain and may be used for any purpose.  However, this
 * notice must not be changed or removed and no warranty is either
 * expressed or implied by its publication or distribution.
 **********************************************************************/
/*
    This copy has been modified to remove CRC calculation other than 32bit.
    and to remove the need for the init function by Rodrigo Hernandez
    for AeonGames.
*/

#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C"
{
#endif
uint32_t CRC32 ( uint8_t const* message, uint32_t size );
#ifdef __cplusplus
}
#endif

#endif
