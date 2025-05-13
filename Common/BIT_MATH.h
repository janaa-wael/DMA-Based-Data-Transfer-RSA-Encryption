/*********************************************************************************/
/* Author    : ARM Committee, SemiColon Team                                     */
/* Version   : V01                                                               */
/* Date      : 12 March 2025                                                     */
/*********************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)          VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)          VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)          ((VAR >> BIT) & 1  )
#define TOGGLE_BIT(VAR,BIT)          VAR ^=  (1 << (BIT))


#endif
