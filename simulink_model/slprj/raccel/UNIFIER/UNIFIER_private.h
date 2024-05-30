#ifndef RTW_HEADER_UNIFIER_private_h_
#define RTW_HEADER_UNIFIER_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "UNIFIER.h"
#include "UNIFIER_types.h"
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
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
extern void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( const real_T u0 [ 3 ] ,
const real_T u1 [ 9 ] , real_T y [ 3 ] ) ; void * rt_TDelayCreateBuf ( int_T
numBuffer , int_T bufSz , int_T elemSz ) ; boolean_T
rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr , int_T *
headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
; real_T rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T *
uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx ,
real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) ; extern uint32_T plook_u32ff_lincpa (
real32_T u , const real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction
, uint32_T * prevIndex ) ; extern uint32_T plook_u32ff_linxp ( real32_T u ,
const real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T *
prevIndex ) ; extern real32_T intrp2d_fu32fl_pw ( const uint32_T bpIndex [ ]
, const real32_T frac [ ] , const real32_T table [ ] , const uint32_T stride
) ; extern real_T look2_plinlxpw ( real_T u0 , real_T u1 , const real_T bp0 [
] , const real_T bp1 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
const uint32_T maxIndex [ ] , uint32_T stride ) ; extern real_T
look1_plinlcpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , uint32_T maxIndex ) ; extern real_T look1_plinlxpw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) ; extern real_T look1_plinlcapw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) ; extern real_T look2_plinlcpw ( real_T u0 , real_T u1 ,
const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , const uint32_T maxIndex [ ] , uint32_T stride ) ;
extern real32_T intrp4d_fu32fla_pw ( const uint32_T bpIndex [ ] , const
real32_T frac [ ] , const real32_T table [ ] , const uint32_T stride [ ] ,
const uint32_T maxIndex [ ] ) ; extern uint32_T plook_linxp ( real_T u ,
const real_T bp [ ] , uint32_T maxIndex , real_T * fraction , uint32_T *
prevIndex ) ; extern real32_T look1_iflf_pbinlcpw ( real32_T u0 , const
real32_T bp0 [ ] , const real32_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) ; extern uint32_T plook_u32ff_lincp ( real32_T u , const
real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T *
prevIndex ) ; extern real32_T intrp4d_fl_pw ( const uint32_T bpIndex [ ] ,
const real_T frac [ ] , const real32_T table [ ] , const uint32_T stride [ ]
) ; extern real32_T intrp3d_fl_pw ( const uint32_T bpIndex [ ] , const real_T
frac [ ] , const real32_T table [ ] , const uint32_T stride [ ] ) ; extern
uint32_T linsearch_u32f ( real32_T u , const real32_T bp [ ] , uint32_T
startIndex ) ; extern uint32_T linsearch_u32d ( real_T u , const real_T bp [
] , uint32_T startIndex ) ; extern void sfun_output_to_console ( SimStruct *
rts ) ; extern void sfun_joyinfoex ( SimStruct * rts ) ; extern void
sfun_getSystemClockTimeval ( SimStruct * rts ) ; extern void sfun_sleep (
SimStruct * rts ) ; void rt_TDelayFreeBuf ( void * buf ) ; extern void
jep0si2kso ( ny4q0xtkup * localB , kpxwjmhxii * localP , dry5l5lsph * localX
) ; extern void lcctkqarga ( kpxwjmhxii * localP , dry5l5lsph * localX ) ;
extern void cdlmndsgcq ( SimStruct * rtS_p , fpbcqq3sgu * localDW ) ; extern
void jlrztmmapx ( real_T f5k4jjwwtb , real_T rtp_d_m , fpbcqq3sgu * localDW ,
kpxwjmhxii * localP , dry5l5lsph * localX , il4tjwsha2 * localXdot ) ; extern
void glfgiolfcq ( fpbcqq3sgu * localDW ) ; extern void fthork0k0x ( SimStruct
* rtS_i , boolean_T d5n5w15zb3 , real_T rtp_d_m , ny4q0xtkup * localB ,
fpbcqq3sgu * localDW , kpxwjmhxii * localP , dry5l5lsph * localX ) ; extern
void owmp11rhaq ( a0dvcgex5j * localDW ) ; extern void pm13c03kzl ( const
real_T oj5oksea0w [ 3 ] , boolean_T nvpbnzaf1k , np24g4gdau * localB ,
a0dvcgex5j * localDW ) ; extern void i3rx1r2kpd ( fiqejkualm * localDW ) ;
extern void bezhj2arkr ( const uint8_T lgciwm45fa [ 39 ] , real32_T
pggtavs035 , fskif30kch * localB , fiqejkualm * localDW ) ; extern void
kc3n2tu0yh ( pls4xc4scj * localDW ) ; extern void bhtkyxb11t ( const uint8_T
ellmm2bjow [ 40 ] , real32_T kxhf0arinc , p3ecnoeui5 * localB , pls4xc4scj *
localDW ) ; extern void e4y3iusrkx ( jiigegnrkw * localDW ) ; extern void
f3054a4w15 ( const uint8_T na5etytz23 [ 37 ] , real32_T emewi5swva ,
dt1fegwimr * localB , jiigegnrkw * localDW ) ; extern void k3ngcghnl5 (
gv4mkh5bt0 * localDW ) ; extern void kgud4px1j0 ( const uint8_T nhadz0vqhl [
51 ] , real32_T eifjvvxpgu , lkm4qo0z2m * localB , gv4mkh5bt0 * localDW ) ;
extern void pv5uhtasoj ( void ) ; extern void ggl0rm1hau ( int32_T g3vkebdqap
) ; extern void ggl0rm1hauTID3 ( int32_T g3vkebdqap ) ; extern void
f5orepjga5 ( void ) ; extern void ppqwruko3j ( int32_T jbk4x2dzbh ) ; extern
void ppqwruko3jTID3 ( int32_T jbk4x2dzbh ) ; extern void fhcttf5uve ( void )
; extern void femu5gktcp ( int32_T bu4vq0ye4b ) ; extern void femu5gktcpTID3
( int32_T bu4vq0ye4b ) ; extern void kyeab3bcz3 ( void ) ; extern void
ozenep403f ( int32_T peigugf4ug ) ; extern void ozenep403fTID3 ( int32_T
peigugf4ug ) ; extern void nonjggp2zg ( int32_T jagyoxt1fz ) ; extern void
gpbjdtigub ( void ) ; extern void jiwpvcutff ( int32_T nbulfcirnz ) ; extern
void jiwpvcutffTID3 ( int32_T nbulfcirnz ) ; extern void jpp5owoa3n ( int32_T
agcfuo5anh ) ;
#if defined(MULTITASKING)
#error Model (UNIFIER) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
