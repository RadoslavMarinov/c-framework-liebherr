
#ifndef utils_H
#define utils_H





#define utils_getNumberOfBitsIn(arrayElement)						( sizeof(arrayElement) * 8U )
#define utils_getArrayIndexOfBit(bit, array)						( (bit) / utils_getNumberOfBitsIn(array[0]) )
#define utils_getBitPositionInArrayElement(bit, array)				( (bit) % utils_getNumberOfBitsIn(array[0]) )
#define utils_getBitMaskInArrayElement(bit, array)					( 1U << utils_getBitPositionInArrayElement(bit, array) )

#define utils_isHighArrayBit(bit, array)							( array[utils_getArrayIndexOfBit(bit, array)] & utils_getBitMaskInArrayElement(bit, array) )
#define utils_raiseBitInArray(bit, array)							( array[utils_getArrayIndexOfBit(bit, array)] |= utils_getBitMaskInArrayElement(bit, array) )
#define utils_clearBitInArray(bit, array)							( array[utils_getArrayIndexOfBit(bit, array)] &= (~utils_getBitMaskInArrayElement(bit, array)) )

#define utils_getAbsoluteBitPosition(array, index, contextBit)		( ((index) * utils_getNumberOfBitsIn(array[0]) * 1U ) + contextBit ) //Relative to the start of the array
#define utils_getNumberOfElementsInArray(array)						( sizeof(array) / sizeof(array[0]) )

#endif /* utils_H */
