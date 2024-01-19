#ifndef RTW_HEADER_UNIFIER_dyn_private_h_
#define RTW_HEADER_UNIFIER_dyn_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "UNIFIER_dyn_types.h"
#include "UNIFIER_dyn.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
extern void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( const real_T u0 [ 3 ] ,
const real_T u1 [ 9 ] , real_T y [ 3 ] ) ; extern real_T look1_plinlcapw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) ; extern real_T look2_plinlcpw ( real_T
u0 , real_T u1 , const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T
table [ ] , uint32_T prevIndex [ ] , const uint32_T maxIndex [ ] , uint32_T
stride ) ; extern uint32_T linsearch_u32d ( real_T u , const real_T bp [ ] ,
uint32_T startIndex ) ; extern uint32_T plook_u32ff_lincpa ( real32_T u ,
const real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T *
prevIndex ) ; extern real32_T intrp4d_fu32fla_pw ( const uint32_T bpIndex [ ]
, const real32_T frac [ ] , const real32_T table [ ] , const uint32_T stride
[ ] , const uint32_T maxIndex [ ] ) ; extern real32_T look1_iflf_pbinlcpw (
real32_T u0 , const real32_T bp0 [ ] , const real32_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) ; extern uint32_T plook_u32ff_linxp (
real32_T u , const real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction
, uint32_T * prevIndex ) ; extern uint32_T plook_u32ff_lincp ( real32_T u ,
const real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T *
prevIndex ) ; extern real32_T intrp4d_fl_pw ( const uint32_T bpIndex [ ] ,
const real_T frac [ ] , const real32_T table [ ] , const uint32_T stride [ ]
) ; extern real32_T intrp3d_fl_pw ( const uint32_T bpIndex [ ] , const real_T
frac [ ] , const real32_T table [ ] , const uint32_T stride [ ] ) ; extern
real32_T intrp2d_fu32fl_pw ( const uint32_T bpIndex [ ] , const real32_T frac
[ ] , const real32_T table [ ] , const uint32_T stride ) ; extern real_T
look1_plinlcpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , uint32_T maxIndex ) ; extern real_T look1_plinlxpw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) ; extern real_T look2_plinlxpw ( real_T
u0 , real_T u1 , const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T
table [ ] , uint32_T prevIndex [ ] , const uint32_T maxIndex [ ] , uint32_T
stride ) ; extern uint32_T plook_linxp ( real_T u , const real_T bp [ ] ,
uint32_T maxIndex , real_T * fraction , uint32_T * prevIndex ) ; extern
uint32_T linsearch_u32f ( real32_T u , const real32_T bp [ ] , uint32_T
startIndex ) ; extern void ijft5h35rv ( void ) ; extern void b4xsnziie2 (
int32_T brnrrcfc0x ) ; extern void b4xsnziie2TID1 ( int32_T brnrrcfc0x ) ;
extern void cjkzdk20zl ( void ) ; extern void jgo5lugg00 ( int32_T co50hcg2ie
) ; extern void jgo5lugg00TID1 ( int32_T co50hcg2ie ) ; extern void
oa24tgolov ( void ) ; extern void f53wtq1cer ( int32_T bs0t4f2z5j ) ; extern
void f53wtq1cerTID1 ( int32_T bs0t4f2z5j ) ; extern void lbtqalrtao ( void )
; extern void cv3gln2abz ( int32_T prlh41yr04 ) ; extern void cv3gln2abzTID1
( int32_T prlh41yr04 ) ; extern void acqwd1nmzk ( void ) ; extern void
d2dy1jnwgp ( int32_T cbsnj42nfj ) ; extern void d2dy1jnwgpTID1 ( int32_T
cbsnj42nfj ) ; extern void fy3uhmab3v ( int32_T dwdkiverai ) ; extern void
o5hfwszdxw ( void ) ; extern void pg42w5emjt ( int32_T pjhb2frnhh ) ; extern
void pg42w5emjtTID1 ( int32_T pjhb2frnhh ) ; extern void c0cmetu4kl ( int32_T
eevyujj1hd ) ; extern void eehyfjcqm2 ( void ) ; extern void eo4s0qr2ut (
int32_T fj0epmyt1u ) ; extern void eo4s0qr2utTID1 ( int32_T fj0epmyt1u ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
