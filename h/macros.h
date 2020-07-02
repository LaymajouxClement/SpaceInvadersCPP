/*
 * macros.h
 *
 *  Created on: 1 juil. 2020
 *      Author: eleve
 */

#ifndef MACROS_H_
#define MACROS_H_

#define mBitsSet(T,f,m)			(f = (T)  ((int)(f) | (int)(m)))
#define mBitsClr(T,f,m)			(f = (T)  ((int)(f) & (~(int)(m))))
#define mBitsTgl(T,f,m)			(f = (T)  ((int)(f) ^ (int)(m)))
#define mBitsMsk(T,f,m)			(         ((int)(f) & (int)(m)))
#define mIsBitsSet(T,f,m)		(((int)(f) & (int)(m))==(int)(m))
#define mIsBitsClr(T,f,m)		(((~(int)(f)) & (int)(m))==(int)(m))

#endif /* MACROS_H_ */
