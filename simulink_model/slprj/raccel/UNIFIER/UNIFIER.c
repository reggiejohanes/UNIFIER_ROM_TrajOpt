#include "UNIFIER.h"
#include "rtwtypes.h"
#include "UNIFIER_private.h"
#include <string.h>
#include <stddef.h>
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "UNIFIER_capi.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "UNIFIER_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "10.7 (R2023a) 19-Nov-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define basxtpz3jk (-1)
#define fy11crjkru (-1)
#define fv0gv35ypk (-1)
#define kiiv3nluju (-1)
#define dpqd33l220 (-1)
#define ccx3jljkx1 (-1)
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; PeriodicIndX rtPeriodicIndX ;
PeriodicRngX rtPeriodicRngX ; static SimStruct model_S ; SimStruct * const
rtS = & model_S ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ;
if ( istransportdelay ) { numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; }
testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <=
tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * uBuf ,
int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T
initOutput , boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput )
{ int_T i ; real_T yout , t1 , t2 , u1 , u2 ; real_T * tBuf = uBuf + bufSz ;
if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
uint32_T plook_u32ff_lincpa ( real32_T u , const real32_T bp [ ] , uint32_T
maxIndex , real32_T * fraction , uint32_T * prevIndex ) { uint32_T bpIndex ;
if ( u <= bp [ 0U ] ) { bpIndex = 0U ; * fraction = 0.0F ; } else if ( u < bp
[ maxIndex ] ) { bpIndex = linsearch_u32f ( u , bp , * prevIndex ) ; *
fraction = ( u - bp [ bpIndex ] ) / ( bp [ bpIndex + 1U ] - bp [ bpIndex ] )
; } else { bpIndex = maxIndex ; * fraction = 0.0F ; } * prevIndex = bpIndex ;
return bpIndex ; } uint32_T plook_u32ff_linxp ( real32_T u , const real32_T
bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T * prevIndex ) {
uint32_T bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0U ; * fraction = ( u -
bp [ 0U ] ) / ( bp [ 1U ] - bp [ 0U ] ) ; } else if ( u < bp [ maxIndex ] ) {
bpIndex = linsearch_u32f ( u , bp , * prevIndex ) ; * fraction = ( u - bp [
bpIndex ] ) / ( bp [ bpIndex + 1U ] - bp [ bpIndex ] ) ; } else { bpIndex =
maxIndex - 1U ; * fraction = ( u - bp [ maxIndex - 1U ] ) / ( bp [ maxIndex ]
- bp [ maxIndex - 1U ] ) ; } * prevIndex = bpIndex ; return bpIndex ; }
real32_T intrp2d_fu32fl_pw ( const uint32_T bpIndex [ ] , const real32_T frac
[ ] , const real32_T table [ ] , const uint32_T stride ) { real32_T yL_0d0 ;
real32_T yL_0d1 ; uint32_T offset_1d ; offset_1d = bpIndex [ 1U ] * stride +
bpIndex [ 0U ] ; yL_0d0 = table [ offset_1d ] ; yL_0d0 += ( table [ offset_1d
+ 1U ] - yL_0d0 ) * frac [ 0U ] ; offset_1d += stride ; yL_0d1 = table [
offset_1d ] ; return ( ( ( table [ offset_1d + 1U ] - yL_0d1 ) * frac [ 0U ]
+ yL_0d1 ) - yL_0d0 ) * frac [ 1U ] + yL_0d0 ; } real_T look2_plinlxpw (
real_T u0 , real_T u1 , const real_T bp0 [ ] , const real_T bp1 [ ] , const
real_T table [ ] , uint32_T prevIndex [ ] , const uint32_T maxIndex [ ] ,
uint32_T stride ) { real_T fractions [ 2 ] ; real_T frac ; real_T yL_0d0 ;
real_T yL_0d1 ; uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ; if ( u0 <= bp0 [
0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ]
) ; } else if ( u0 < bp0 [ maxIndex [ 0U ] ] ) { for ( bpIdx = prevIndex [ 0U
] ; u0 < bp0 [ bpIdx ] ; bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) {
bpIdx ++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [
bpIdx ] ) ; } else { bpIdx = maxIndex [ 0U ] - 1U ; frac = ( u0 - bp0 [
maxIndex [ 0U ] - 1U ] ) / ( bp0 [ maxIndex [ 0U ] ] - bp0 [ maxIndex [ 0U ]
- 1U ] ) ; } prevIndex [ 0U ] = bpIdx ; fractions [ 0U ] = frac ; bpIndices [
0U ] = bpIdx ; if ( u1 <= bp1 [ 0U ] ) { bpIdx = 0U ; frac = ( u1 - bp1 [ 0U
] ) / ( bp1 [ 1U ] - bp1 [ 0U ] ) ; } else if ( u1 < bp1 [ maxIndex [ 1U ] ]
) { for ( bpIdx = prevIndex [ 1U ] ; u1 < bp1 [ bpIdx ] ; bpIdx -- ) { }
while ( u1 >= bp1 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u1 - bp1 [ bpIdx ]
) / ( bp1 [ bpIdx + 1U ] - bp1 [ bpIdx ] ) ; } else { bpIdx = maxIndex [ 1U ]
- 1U ; frac = ( u1 - bp1 [ maxIndex [ 1U ] - 1U ] ) / ( bp1 [ maxIndex [ 1U ]
] - bp1 [ maxIndex [ 1U ] - 1U ] ) ; } prevIndex [ 1U ] = bpIdx ; bpIdx =
bpIdx * stride + bpIndices [ 0U ] ; yL_0d0 = table [ bpIdx ] ; yL_0d0 += (
table [ bpIdx + 1U ] - yL_0d0 ) * fractions [ 0U ] ; bpIdx += stride ; yL_0d1
= table [ bpIdx ] ; return ( ( ( table [ bpIdx + 1U ] - yL_0d1 ) * fractions
[ 0U ] + yL_0d1 ) - yL_0d0 ) * frac + yL_0d0 ; } real_T look1_plinlcpw (
real_T u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ; uint32_T
bpIdx ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = 0.0 ; } else if ( u0 <
bp0 [ maxIndex ] ) { for ( bpIdx = prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ;
bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0
- bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx =
maxIndex - 1U ; frac = 1.0 ; } prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [
bpIdx ] ; return ( table [ bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } real_T
look1_plinlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
for ( bpIdx = prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ; bpIdx -- ) { } while (
u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / (
bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac
= ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ]
) ; } prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [ bpIdx ] ; return ( table [
bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } real_T look1_plinlcapw ( real_T
u0 , const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) { real_T frac ; real_T y ; real_T yL_0d0 ; uint32_T bpIdx
; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [
maxIndex ] ) { for ( bpIdx = prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ; bpIdx --
) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0 - bp0 [
bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx =
maxIndex ; frac = 0.0 ; } prevIndex [ 0U ] = bpIdx ; if ( bpIdx == maxIndex )
{ y = table [ bpIdx ] ; } else { yL_0d0 = table [ bpIdx ] ; y = ( table [
bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } return y ; } real_T
look2_plinlcpw ( real_T u0 , real_T u1 , const real_T bp0 [ ] , const real_T
bp1 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] , const uint32_T
maxIndex [ ] , uint32_T stride ) { real_T fractions [ 2 ] ; real_T frac ;
real_T yL_0d0 ; real_T yL_0d1 ; uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ;
if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [
maxIndex [ 0U ] ] ) { for ( bpIdx = prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ;
bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0
- bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx =
maxIndex [ 0U ] - 1U ; frac = 1.0 ; } prevIndex [ 0U ] = bpIdx ; fractions [
0U ] = frac ; bpIndices [ 0U ] = bpIdx ; if ( u1 <= bp1 [ 0U ] ) { bpIdx = 0U
; frac = 0.0 ; } else if ( u1 < bp1 [ maxIndex [ 1U ] ] ) { for ( bpIdx =
prevIndex [ 1U ] ; u1 < bp1 [ bpIdx ] ; bpIdx -- ) { } while ( u1 >= bp1 [
bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u1 - bp1 [ bpIdx ] ) / ( bp1 [ bpIdx +
1U ] - bp1 [ bpIdx ] ) ; } else { bpIdx = maxIndex [ 1U ] - 1U ; frac = 1.0 ;
} prevIndex [ 1U ] = bpIdx ; bpIdx = bpIdx * stride + bpIndices [ 0U ] ;
yL_0d0 = table [ bpIdx ] ; yL_0d0 += ( table [ bpIdx + 1U ] - yL_0d0 ) *
fractions [ 0U ] ; bpIdx += stride ; yL_0d1 = table [ bpIdx ] ; return ( ( (
table [ bpIdx + 1U ] - yL_0d1 ) * fractions [ 0U ] + yL_0d1 ) - yL_0d0 ) *
frac + yL_0d0 ; } real32_T intrp4d_fu32fla_pw ( const uint32_T bpIndex [ ] ,
const real32_T frac [ ] , const real32_T table [ ] , const uint32_T stride [
] , const uint32_T maxIndex [ ] ) { real32_T y ; real32_T yL_0d0 ; real32_T
yL_1d ; real32_T yL_1d_p ; uint32_T offset_0d ; uint32_T offset_1d ; uint32_T
offset_3d ; offset_3d = ( ( bpIndex [ 3U ] * stride [ 3U ] + bpIndex [ 2U ] *
stride [ 2U ] ) + bpIndex [ 1U ] * stride [ 1U ] ) + bpIndex [ 0U ] ; if (
bpIndex [ 0U ] == maxIndex [ 0U ] ) { y = table [ offset_3d ] ; } else {
yL_0d0 = table [ offset_3d ] ; y = ( table [ offset_3d + 1U ] - yL_0d0 ) *
frac [ 0U ] + yL_0d0 ; } if ( bpIndex [ 1U ] == maxIndex [ 1U ] ) { } else {
offset_0d = offset_3d + stride [ 1U ] ; if ( bpIndex [ 0U ] == maxIndex [ 0U
] ) { yL_0d0 = table [ offset_0d ] ; } else { yL_0d0 = table [ offset_0d ] ;
yL_0d0 += ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ; } y += (
yL_0d0 - y ) * frac [ 1U ] ; } if ( bpIndex [ 2U ] == maxIndex [ 2U ] ) { }
else { offset_1d = offset_3d + stride [ 2U ] ; if ( bpIndex [ 0U ] ==
maxIndex [ 0U ] ) { yL_1d = table [ offset_1d ] ; } else { yL_0d0 = table [
offset_1d ] ; yL_1d = ( table [ offset_1d + 1U ] - yL_0d0 ) * frac [ 0U ] +
yL_0d0 ; } if ( bpIndex [ 1U ] == maxIndex [ 1U ] ) { } else { offset_0d =
offset_1d + stride [ 1U ] ; if ( bpIndex [ 0U ] == maxIndex [ 0U ] ) { yL_0d0
= table [ offset_0d ] ; } else { yL_0d0 = table [ offset_0d ] ; yL_0d0 += (
table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ; } yL_1d += ( yL_0d0 -
yL_1d ) * frac [ 1U ] ; } y += ( yL_1d - y ) * frac [ 2U ] ; } if ( bpIndex [
3U ] == maxIndex [ 3U ] ) { } else { offset_1d = offset_3d + stride [ 3U ] ;
if ( bpIndex [ 0U ] == maxIndex [ 0U ] ) { yL_1d = table [ offset_1d ] ; }
else { yL_0d0 = table [ offset_1d ] ; yL_1d = ( table [ offset_1d + 1U ] -
yL_0d0 ) * frac [ 0U ] + yL_0d0 ; } if ( bpIndex [ 1U ] == maxIndex [ 1U ] )
{ } else { offset_0d = offset_1d + stride [ 1U ] ; if ( bpIndex [ 0U ] ==
maxIndex [ 0U ] ) { yL_0d0 = table [ offset_0d ] ; } else { yL_0d0 = table [
offset_0d ] ; yL_0d0 += ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ;
} yL_1d += ( yL_0d0 - yL_1d ) * frac [ 1U ] ; } if ( bpIndex [ 2U ] ==
maxIndex [ 2U ] ) { } else { offset_1d += stride [ 2U ] ; if ( bpIndex [ 0U ]
== maxIndex [ 0U ] ) { yL_1d_p = table [ offset_1d ] ; } else { yL_0d0 =
table [ offset_1d ] ; yL_1d_p = ( table [ offset_1d + 1U ] - yL_0d0 ) * frac
[ 0U ] + yL_0d0 ; } if ( bpIndex [ 1U ] == maxIndex [ 1U ] ) { } else {
offset_0d = offset_1d + stride [ 1U ] ; if ( bpIndex [ 0U ] == maxIndex [ 0U
] ) { yL_0d0 = table [ offset_0d ] ; } else { yL_0d0 = table [ offset_0d ] ;
yL_0d0 += ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ; } yL_1d_p +=
( yL_0d0 - yL_1d_p ) * frac [ 1U ] ; } yL_1d += ( yL_1d_p - yL_1d ) * frac [
2U ] ; } y += ( yL_1d - y ) * frac [ 3U ] ; } return y ; } uint32_T
plook_linxp ( real_T u , const real_T bp [ ] , uint32_T maxIndex , real_T *
fraction , uint32_T * prevIndex ) { uint32_T bpIndex ; if ( u <= bp [ 0U ] )
{ bpIndex = 0U ; * fraction = ( u - bp [ 0U ] ) / ( bp [ 1U ] - bp [ 0U ] ) ;
} else if ( u < bp [ maxIndex ] ) { bpIndex = linsearch_u32d ( u , bp , *
prevIndex ) ; * fraction = ( u - bp [ bpIndex ] ) / ( bp [ bpIndex + 1U ] -
bp [ bpIndex ] ) ; } else { bpIndex = maxIndex - 1U ; * fraction = ( u - bp [
maxIndex - 1U ] ) / ( bp [ maxIndex ] - bp [ maxIndex - 1U ] ) ; } *
prevIndex = bpIndex ; return bpIndex ; } real32_T look1_iflf_pbinlcpw (
real32_T u0 , const real32_T bp0 [ ] , const real32_T table [ ] , uint32_T
prevIndex [ ] , uint32_T maxIndex ) { real32_T frac ; real32_T yL_0d0 ;
uint32_T bpIdx ; uint32_T found ; uint32_T iLeft ; uint32_T iRght ; if ( u0
<= bp0 [ 0U ] ) { bpIdx = 0U ; frac = 0.0F ; } else if ( u0 < bp0 [ maxIndex
] ) { bpIdx = prevIndex [ 0U ] ; iLeft = 0U ; iRght = maxIndex ; found = 0U ;
while ( found == 0U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx - 1U ;
bpIdx = ( ( bpIdx + iLeft ) - 1U ) >> 1U ; } else if ( u0 < bp0 [ bpIdx + 1U
] ) { found = 1U ; } else { iLeft = bpIdx + 1U ; bpIdx = ( ( bpIdx + iRght )
+ 1U ) >> 1U ; } } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0
[ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac = 1.0F ; } prevIndex [ 0U
] = bpIdx ; yL_0d0 = table [ bpIdx ] ; return ( table [ bpIdx + 1U ] - yL_0d0
) * frac + yL_0d0 ; } uint32_T plook_u32ff_lincp ( real32_T u , const
real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T *
prevIndex ) { uint32_T bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0U ; *
fraction = 0.0F ; } else if ( u < bp [ maxIndex ] ) { bpIndex =
linsearch_u32f ( u , bp , * prevIndex ) ; * fraction = ( u - bp [ bpIndex ] )
/ ( bp [ bpIndex + 1U ] - bp [ bpIndex ] ) ; } else { bpIndex = maxIndex - 1U
; * fraction = 1.0F ; } * prevIndex = bpIndex ; return bpIndex ; } real32_T
intrp4d_fl_pw ( const uint32_T bpIndex [ ] , const real_T frac [ ] , const
real32_T table [ ] , const uint32_T stride [ ] ) { real32_T yL_0d0 ; real32_T
yL_1d ; real32_T yL_2d ; real32_T yL_3d ; uint32_T offset_0d ; uint32_T
offset_1d ; uint32_T offset_3d ; offset_3d = ( ( bpIndex [ 3U ] * stride [ 3U
] + bpIndex [ 2U ] * stride [ 2U ] ) + bpIndex [ 1U ] * stride [ 1U ] ) +
bpIndex [ 0U ] ; yL_0d0 = table [ offset_3d ] ; yL_1d = ( real32_T ) ( (
table [ offset_3d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ; offset_0d =
offset_3d + stride [ 1U ] ; yL_0d0 = table [ offset_0d ] ; yL_2d = ( real32_T
) ( ( ( ( real32_T ) ( ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] )
+ yL_0d0 ) - yL_1d ) * frac [ 1U ] ) + yL_1d ; offset_1d = offset_3d + stride
[ 2U ] ; yL_0d0 = table [ offset_1d ] ; yL_1d = ( real32_T ) ( ( table [
offset_1d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ; offset_0d = offset_1d
+ stride [ 1U ] ; yL_0d0 = table [ offset_0d ] ; yL_3d = ( real32_T ) ( ( ( (
real32_T ) ( ( ( ( real32_T ) ( ( table [ offset_0d + 1U ] - yL_0d0 ) * frac
[ 0U ] ) + yL_0d0 ) - yL_1d ) * frac [ 1U ] ) + yL_1d ) - yL_2d ) * frac [ 2U
] ) + yL_2d ; offset_1d = offset_3d + stride [ 3U ] ; yL_0d0 = table [
offset_1d ] ; yL_1d = ( real32_T ) ( ( table [ offset_1d + 1U ] - yL_0d0 ) *
frac [ 0U ] ) + yL_0d0 ; offset_0d = offset_1d + stride [ 1U ] ; yL_0d0 =
table [ offset_0d ] ; yL_2d = ( real32_T ) ( ( ( ( real32_T ) ( ( table [
offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) * frac [ 1U
] ) + yL_1d ; offset_1d += stride [ 2U ] ; yL_0d0 = table [ offset_1d ] ;
yL_1d = ( real32_T ) ( ( table [ offset_1d + 1U ] - yL_0d0 ) * frac [ 0U ] )
+ yL_0d0 ; offset_0d = offset_1d + stride [ 1U ] ; yL_0d0 = table [ offset_0d
] ; return ( real32_T ) ( ( ( ( real32_T ) ( ( ( ( real32_T ) ( ( ( (
real32_T ) ( ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 )
- yL_1d ) * frac [ 1U ] ) + yL_1d ) - yL_2d ) * frac [ 2U ] ) + yL_2d ) -
yL_3d ) * frac [ 3U ] ) + yL_3d ; } real32_T intrp3d_fl_pw ( const uint32_T
bpIndex [ ] , const real_T frac [ ] , const real32_T table [ ] , const
uint32_T stride [ ] ) { real32_T yL_0d0 ; real32_T yL_1d ; real32_T yL_2d ;
uint32_T offset_0d ; uint32_T offset_2d ; offset_2d = ( bpIndex [ 2U ] *
stride [ 2U ] + bpIndex [ 1U ] * stride [ 1U ] ) + bpIndex [ 0U ] ; yL_0d0 =
table [ offset_2d ] ; yL_1d = ( real32_T ) ( ( table [ offset_2d + 1U ] -
yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ; offset_0d = offset_2d + stride [ 1U ] ;
yL_0d0 = table [ offset_0d ] ; yL_2d = ( real32_T ) ( ( ( ( real32_T ) ( (
table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) *
frac [ 1U ] ) + yL_1d ; offset_2d += stride [ 2U ] ; yL_0d0 = table [
offset_2d ] ; yL_1d = ( real32_T ) ( ( table [ offset_2d + 1U ] - yL_0d0 ) *
frac [ 0U ] ) + yL_0d0 ; offset_0d = offset_2d + stride [ 1U ] ; yL_0d0 =
table [ offset_0d ] ; return ( real32_T ) ( ( ( ( real32_T ) ( ( ( ( real32_T
) ( ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d
) * frac [ 1U ] ) + yL_1d ) - yL_2d ) * frac [ 2U ] ) + yL_2d ; } uint32_T
linsearch_u32f ( real32_T u , const real32_T bp [ ] , uint32_T startIndex ) {
uint32_T bpIndex ; for ( bpIndex = startIndex ; u < bp [ bpIndex ] ; bpIndex
-- ) { } while ( u >= bp [ bpIndex + 1U ] ) { bpIndex ++ ; } return bpIndex ;
} uint32_T linsearch_u32d ( real_T u , const real_T bp [ ] , uint32_T
startIndex ) { uint32_T bpIndex ; for ( bpIndex = startIndex ; u < bp [
bpIndex ] ; bpIndex -- ) { } while ( u >= bp [ bpIndex + 1U ] ) { bpIndex ++
; } return bpIndex ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void pv5uhtasoj (
void ) { int32_T g3vkebdqap ; for ( g3vkebdqap = 0 ; g3vkebdqap < 16 ;
g3vkebdqap ++ ) { rtB . nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 0 ] = 0.0F ;
rtB . nyqetrz43u [ g3vkebdqap ] . ico5bo4shp [ 0 ] = 0.0F ; rtB . nyqetrz43u
[ g3vkebdqap ] . kl452g3br4 [ 1 ] = 0.0F ; rtB . nyqetrz43u [ g3vkebdqap ] .
ico5bo4shp [ 1 ] = 0.0F ; rtB . nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 2 ]
= 0.0F ; rtB . nyqetrz43u [ g3vkebdqap ] . ico5bo4shp [ 2 ] = 0.0F ; } } void
ggl0rm1hau ( int32_T g3vkebdqap ) { real32_T dv3vcft3j5 [ 3 ] ; real32_T
a31o02awz5 ; real32_T lodn0twybn ; real32_T pxiddofnts ; dv3vcft3j5 [ 0 ] =
rtP . vtail_nodes [ 3 * g3vkebdqap ] ; dv3vcft3j5 [ 1 ] = rtP . vtail_nodes [
3 * g3vkebdqap + 1 ] ; dv3vcft3j5 [ 2 ] = rtP . vtail_nodes [ 3 * g3vkebdqap
+ 2 ] ; { real32_T f5q4yqlcqc_idx_0 ; real32_T f5q4yqlcqc_idx_1 ; real32_T
f5q4yqlcqc_idx_2 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . nyqetrz43u [
g3vkebdqap ] . kl452g3br4 [ 0 ] = rtB . nyqetrz43u [ g3vkebdqap ] .
ico5bo4shp [ 0 ] - dv3vcft3j5 [ 0 ] ; rtB . nyqetrz43u [ g3vkebdqap ] .
kl452g3br4 [ 1 ] = rtB . nyqetrz43u [ g3vkebdqap ] . ico5bo4shp [ 1 ] -
dv3vcft3j5 [ 1 ] ; rtB . nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 2 ] = rtB .
nyqetrz43u [ g3vkebdqap ] . ico5bo4shp [ 2 ] - dv3vcft3j5 [ 2 ] ; }
f5q4yqlcqc_idx_0 = ( rtB . nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 1 ] * rtB
. kp4feo544t [ 2 ] - rtB . kp4feo544t [ 1 ] * rtB . nyqetrz43u [ g3vkebdqap ]
. kl452g3br4 [ 2 ] ) + rtB . jrm5mulpgo [ 0 ] ; f5q4yqlcqc_idx_1 = ( rtB .
kp4feo544t [ 0 ] * rtB . nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 2 ] - rtB .
nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 0 ] * rtB . kp4feo544t [ 2 ] ) + rtB
. jrm5mulpgo [ 1 ] ; f5q4yqlcqc_idx_2 = ( rtB . nyqetrz43u [ g3vkebdqap ] .
kl452g3br4 [ 0 ] * rtB . kp4feo544t [ 1 ] - rtB . kp4feo544t [ 0 ] * rtB .
nyqetrz43u [ g3vkebdqap ] . kl452g3br4 [ 1 ] ) + rtB . jrm5mulpgo [ 2 ] ;
pxiddofnts = muSingleScalarSqrt ( ( muSingleScalarPower ( f5q4yqlcqc_idx_0 ,
2.0F ) + muSingleScalarPower ( f5q4yqlcqc_idx_1 , 2.0F ) ) +
muSingleScalarPower ( f5q4yqlcqc_idx_2 , 2.0F ) ) + rtP . nyqetrz43u .
Constant1_Value ; f5q4yqlcqc_idx_1 /= pxiddofnts ; if ( f5q4yqlcqc_idx_1 >
1.0F ) { f5q4yqlcqc_idx_1 = 1.0F ; } else if ( f5q4yqlcqc_idx_1 < - 1.0F ) {
f5q4yqlcqc_idx_1 = - 1.0F ; } a31o02awz5 = muSingleScalarAsin (
f5q4yqlcqc_idx_1 ) ; lodn0twybn = muSingleScalarAtan ( f5q4yqlcqc_idx_2 / (
f5q4yqlcqc_idx_0 + rtP . nyqetrz43u . Constant1_Value ) ) ; } rtB .
atgyr3lfo3 [ g3vkebdqap ] = a31o02awz5 ; rtB . cfz24gonbxg [ g3vkebdqap ] =
lodn0twybn ; rtB . nmxk2xrfk3z [ g3vkebdqap ] = pxiddofnts ; } void
ggl0rm1hauTID3 ( int32_T g3vkebdqap ) { rtB . nyqetrz43u [ g3vkebdqap ] .
ico5bo4shp [ 0 ] = ( real32_T ) rtP . xyz_cg [ 0 ] ; rtB . nyqetrz43u [
g3vkebdqap ] . ico5bo4shp [ 1 ] = ( real32_T ) rtP . xyz_cg [ 1 ] ; rtB .
nyqetrz43u [ g3vkebdqap ] . ico5bo4shp [ 2 ] = ( real32_T ) rtP . xyz_cg [ 2
] ; } void f5orepjga5 ( void ) { int32_T jbk4x2dzbh ; for ( jbk4x2dzbh = 0 ;
jbk4x2dzbh < 14 ; jbk4x2dzbh ++ ) { rtB . nyqetrz43uq [ jbk4x2dzbh ] .
g2bz2muoaw [ 0 ] = 0.0F ; rtB . nyqetrz43uq [ jbk4x2dzbh ] . lkowsjx5yc [ 0 ]
= 0.0F ; rtB . nyqetrz43uq [ jbk4x2dzbh ] . g2bz2muoaw [ 1 ] = 0.0F ; rtB .
nyqetrz43uq [ jbk4x2dzbh ] . lkowsjx5yc [ 1 ] = 0.0F ; rtB . nyqetrz43uq [
jbk4x2dzbh ] . g2bz2muoaw [ 2 ] = 0.0F ; rtB . nyqetrz43uq [ jbk4x2dzbh ] .
lkowsjx5yc [ 2 ] = 0.0F ; } } void ppqwruko3j ( int32_T jbk4x2dzbh ) {
real32_T dv3vcft3j53 [ 3 ] ; real32_T lodn0twybnh ; real32_T ogh5qnuedf ;
dv3vcft3j53 [ 0 ] = rtP . wing_nodes [ 3 * jbk4x2dzbh ] ; dv3vcft3j53 [ 1 ] =
rtP . wing_nodes [ 3 * jbk4x2dzbh + 1 ] ; dv3vcft3j53 [ 2 ] = rtP .
wing_nodes [ 3 * jbk4x2dzbh + 2 ] ; { real32_T lpwc5s211m_e ; real32_T
lpwc5s211m_idx_0 ; real32_T lpwc5s211m_p ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { rtB . nyqetrz43uq [ jbk4x2dzbh ] . g2bz2muoaw [ 0 ] = rtB . nyqetrz43uq [
jbk4x2dzbh ] . lkowsjx5yc [ 0 ] - dv3vcft3j53 [ 0 ] ; rtB . nyqetrz43uq [
jbk4x2dzbh ] . g2bz2muoaw [ 1 ] = rtB . nyqetrz43uq [ jbk4x2dzbh ] .
lkowsjx5yc [ 1 ] - dv3vcft3j53 [ 1 ] ; rtB . nyqetrz43uq [ jbk4x2dzbh ] .
g2bz2muoaw [ 2 ] = rtB . nyqetrz43uq [ jbk4x2dzbh ] . lkowsjx5yc [ 2 ] -
dv3vcft3j53 [ 2 ] ; } lpwc5s211m_e = ( rtB . nyqetrz43uq [ jbk4x2dzbh ] .
g2bz2muoaw [ 1 ] * rtB . kp4feo544t [ 2 ] - rtB . kp4feo544t [ 1 ] * rtB .
nyqetrz43uq [ jbk4x2dzbh ] . g2bz2muoaw [ 2 ] ) + rtB . jrm5mulpgo [ 0 ] ;
lpwc5s211m_idx_0 = lpwc5s211m_e ; lpwc5s211m_p = lpwc5s211m_e * lpwc5s211m_e
; lpwc5s211m_e = ( rtB . kp4feo544t [ 0 ] * rtB . nyqetrz43uq [ jbk4x2dzbh ]
. g2bz2muoaw [ 2 ] - rtB . nyqetrz43uq [ jbk4x2dzbh ] . g2bz2muoaw [ 0 ] *
rtB . kp4feo544t [ 2 ] ) + rtB . jrm5mulpgo [ 1 ] ; lpwc5s211m_p +=
lpwc5s211m_e * lpwc5s211m_e ; lpwc5s211m_e = ( rtB . nyqetrz43uq [ jbk4x2dzbh
] . g2bz2muoaw [ 0 ] * rtB . kp4feo544t [ 1 ] - rtB . kp4feo544t [ 0 ] * rtB
. nyqetrz43uq [ jbk4x2dzbh ] . g2bz2muoaw [ 1 ] ) + rtB . jrm5mulpgo [ 2 ] ;
lpwc5s211m_p += lpwc5s211m_e * lpwc5s211m_e ; lodn0twybnh =
muSingleScalarAtan ( lpwc5s211m_e / ( lpwc5s211m_idx_0 + rtP . nyqetrz43uq .
Constant1_Value ) ) ; ogh5qnuedf = muSingleScalarSqrt ( lpwc5s211m_p ) ; }
rtB . cfz24gonbx [ jbk4x2dzbh ] = lodn0twybnh ; rtB . nmxk2xrfk3 [ jbk4x2dzbh
] = ogh5qnuedf ; } void ppqwruko3jTID3 ( int32_T jbk4x2dzbh ) { rtB .
nyqetrz43uq [ jbk4x2dzbh ] . lkowsjx5yc [ 0 ] = ( real32_T ) rtP . xyz_cg [ 0
] ; rtB . nyqetrz43uq [ jbk4x2dzbh ] . lkowsjx5yc [ 1 ] = ( real32_T ) rtP .
xyz_cg [ 1 ] ; rtB . nyqetrz43uq [ jbk4x2dzbh ] . lkowsjx5yc [ 2 ] = (
real32_T ) rtP . xyz_cg [ 2 ] ; } void fhcttf5uve ( void ) { int32_T
bu4vq0ye4b ; for ( bu4vq0ye4b = 0 ; bu4vq0ye4b < 16 ; bu4vq0ye4b ++ ) { rtB .
nyqetrz43uqk [ bu4vq0ye4b ] . f5l1thfo3b [ 0 ] = 0.0F ; rtB . nyqetrz43uqk [
bu4vq0ye4b ] . a0tbi33tik [ 0 ] = 0.0F ; rtB . nyqetrz43uqk [ bu4vq0ye4b ] .
f5l1thfo3b [ 1 ] = 0.0F ; rtB . nyqetrz43uqk [ bu4vq0ye4b ] . a0tbi33tik [ 1
] = 0.0F ; rtB . nyqetrz43uqk [ bu4vq0ye4b ] . f5l1thfo3b [ 2 ] = 0.0F ; rtB
. nyqetrz43uqk [ bu4vq0ye4b ] . a0tbi33tik [ 2 ] = 0.0F ; } } void femu5gktcp
( int32_T bu4vq0ye4b ) { real32_T bzv0spra3z [ 3 ] ; real32_T lwj5ue2hgk [ 3
] ; real32_T jnkxh0rf3g [ 3 ] ; bzv0spra3z [ 0 ] = rtP . vtail_nodes [ 3 *
bu4vq0ye4b ] ; lwj5ue2hgk [ 0 ] = rtB . o0icr3ysdn [ 3 * bu4vq0ye4b ] ;
bzv0spra3z [ 1 ] = rtP . vtail_nodes [ 3 * bu4vq0ye4b + 1 ] ; lwj5ue2hgk [ 1
] = rtB . o0icr3ysdn [ 3 * bu4vq0ye4b + 1 ] ; bzv0spra3z [ 2 ] = rtP .
vtail_nodes [ 3 * bu4vq0ye4b + 2 ] ; lwj5ue2hgk [ 2 ] = rtB . o0icr3ysdn [ 3
* bu4vq0ye4b + 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
nyqetrz43uqk [ bu4vq0ye4b ] . f5l1thfo3b [ 0 ] = bzv0spra3z [ 0 ] - rtB .
nyqetrz43uqk [ bu4vq0ye4b ] . a0tbi33tik [ 0 ] ; rtB . nyqetrz43uqk [
bu4vq0ye4b ] . f5l1thfo3b [ 1 ] = bzv0spra3z [ 1 ] - rtB . nyqetrz43uqk [
bu4vq0ye4b ] . a0tbi33tik [ 1 ] ; rtB . nyqetrz43uqk [ bu4vq0ye4b ] .
f5l1thfo3b [ 2 ] = bzv0spra3z [ 2 ] - rtB . nyqetrz43uqk [ bu4vq0ye4b ] .
a0tbi33tik [ 2 ] ; } jnkxh0rf3g [ 0 ] = rtB . nyqetrz43uqk [ bu4vq0ye4b ] .
f5l1thfo3b [ 1 ] * lwj5ue2hgk [ 2 ] - lwj5ue2hgk [ 1 ] * rtB . nyqetrz43uqk [
bu4vq0ye4b ] . f5l1thfo3b [ 2 ] ; jnkxh0rf3g [ 1 ] = lwj5ue2hgk [ 0 ] * rtB .
nyqetrz43uqk [ bu4vq0ye4b ] . f5l1thfo3b [ 2 ] - rtB . nyqetrz43uqk [
bu4vq0ye4b ] . f5l1thfo3b [ 0 ] * lwj5ue2hgk [ 2 ] ; jnkxh0rf3g [ 2 ] = rtB .
nyqetrz43uqk [ bu4vq0ye4b ] . f5l1thfo3b [ 0 ] * lwj5ue2hgk [ 1 ] -
lwj5ue2hgk [ 0 ] * rtB . nyqetrz43uqk [ bu4vq0ye4b ] . f5l1thfo3b [ 1 ] ; rtB
. byhpdluumbuo [ 3 * bu4vq0ye4b ] = jnkxh0rf3g [ 0 ] ; rtB . byhpdluumbuo [ 3
* bu4vq0ye4b + 1 ] = jnkxh0rf3g [ 1 ] ; rtB . byhpdluumbuo [ 3 * bu4vq0ye4b +
2 ] = jnkxh0rf3g [ 2 ] ; } void femu5gktcpTID3 ( int32_T bu4vq0ye4b ) { rtB .
nyqetrz43uqk [ bu4vq0ye4b ] . a0tbi33tik [ 0 ] = ( real32_T ) rtP . xyz_cg [
0 ] ; rtB . nyqetrz43uqk [ bu4vq0ye4b ] . a0tbi33tik [ 1 ] = ( real32_T ) rtP
. xyz_cg [ 1 ] ; rtB . nyqetrz43uqk [ bu4vq0ye4b ] . a0tbi33tik [ 2 ] = (
real32_T ) rtP . xyz_cg [ 2 ] ; } void kyeab3bcz3 ( void ) { int32_T
peigugf4ug ; for ( peigugf4ug = 0 ; peigugf4ug < 7 ; peigugf4ug ++ ) { rtB .
nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 0 ] = 0.0F ; rtB . nyqetrz43uqkk
[ peigugf4ug ] . dbot5mi30f [ 0 ] = 0.0F ; rtB . nyqetrz43uqkk [ peigugf4ug ]
. d2kygac014 [ 1 ] = 0.0F ; rtB . nyqetrz43uqkk [ peigugf4ug ] . dbot5mi30f [
1 ] = 0.0F ; rtB . nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 2 ] = 0.0F ;
rtB . nyqetrz43uqkk [ peigugf4ug ] . dbot5mi30f [ 2 ] = 0.0F ; } } void
ozenep403f ( int32_T peigugf4ug ) { real32_T bzv0spra3zj [ 3 ] ; real32_T
lwj5ue2hgkd [ 3 ] ; real32_T jnkxh0rf3gh [ 3 ] ; bzv0spra3zj [ 0 ] = rtP .
NodePoints_Value [ 3 * peigugf4ug ] ; lwj5ue2hgkd [ 0 ] = rtB . ayq52soaqwz [
3 * peigugf4ug ] ; bzv0spra3zj [ 1 ] = rtP . NodePoints_Value [ 3 *
peigugf4ug + 1 ] ; lwj5ue2hgkd [ 1 ] = rtB . ayq52soaqwz [ 3 * peigugf4ug + 1
] ; bzv0spra3zj [ 2 ] = rtP . NodePoints_Value [ 3 * peigugf4ug + 2 ] ;
lwj5ue2hgkd [ 2 ] = rtB . ayq52soaqwz [ 3 * peigugf4ug + 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . nyqetrz43uqkk [ peigugf4ug ] .
d2kygac014 [ 0 ] = bzv0spra3zj [ 0 ] - rtB . nyqetrz43uqkk [ peigugf4ug ] .
dbot5mi30f [ 0 ] ; rtB . nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 1 ] =
bzv0spra3zj [ 1 ] - rtB . nyqetrz43uqkk [ peigugf4ug ] . dbot5mi30f [ 1 ] ;
rtB . nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 2 ] = bzv0spra3zj [ 2 ] -
rtB . nyqetrz43uqkk [ peigugf4ug ] . dbot5mi30f [ 2 ] ; } jnkxh0rf3gh [ 0 ] =
rtB . nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 1 ] * lwj5ue2hgkd [ 2 ] -
lwj5ue2hgkd [ 1 ] * rtB . nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 2 ] ;
jnkxh0rf3gh [ 1 ] = lwj5ue2hgkd [ 0 ] * rtB . nyqetrz43uqkk [ peigugf4ug ] .
d2kygac014 [ 2 ] - rtB . nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 0 ] *
lwj5ue2hgkd [ 2 ] ; jnkxh0rf3gh [ 2 ] = rtB . nyqetrz43uqkk [ peigugf4ug ] .
d2kygac014 [ 0 ] * lwj5ue2hgkd [ 1 ] - lwj5ue2hgkd [ 0 ] * rtB .
nyqetrz43uqkk [ peigugf4ug ] . d2kygac014 [ 1 ] ; rtB . byhpdluumbu [ 3 *
peigugf4ug ] = jnkxh0rf3gh [ 0 ] ; rtB . byhpdluumbu [ 3 * peigugf4ug + 1 ] =
jnkxh0rf3gh [ 1 ] ; rtB . byhpdluumbu [ 3 * peigugf4ug + 2 ] = jnkxh0rf3gh [
2 ] ; } void ozenep403fTID3 ( int32_T peigugf4ug ) { rtB . nyqetrz43uqkk [
peigugf4ug ] . dbot5mi30f [ 0 ] = ( real32_T ) rtP . xyz_cg [ 0 ] ; rtB .
nyqetrz43uqkk [ peigugf4ug ] . dbot5mi30f [ 1 ] = ( real32_T ) rtP . xyz_cg [
1 ] ; rtB . nyqetrz43uqkk [ peigugf4ug ] . dbot5mi30f [ 2 ] = ( real32_T )
rtP . xyz_cg [ 2 ] ; } void nonjggp2zg ( int32_T jagyoxt1fz ) { real32_T
jbwi0xitxv ; real32_T c1lu2bs0gg [ 3 ] ; real32_T kjzcbd5o3r [ 3 ] ;
jbwi0xitxv = rtB . korrwukkg3 [ jagyoxt1fz ] ; c1lu2bs0gg [ 0 ] = rtB .
bflkh3tw3c [ 3 * jagyoxt1fz ] ; c1lu2bs0gg [ 1 ] = rtB . bflkh3tw3c [ 3 *
jagyoxt1fz + 1 ] ; c1lu2bs0gg [ 2 ] = rtB . bflkh3tw3c [ 3 * jagyoxt1fz + 2 ]
; { real_T fpimk5asyt [ 9 ] ; real_T k1hih2hasy_idx_0 ; real_T
k1hih2hasy_idx_1 ; real_T onujjcrdl4_idx_0 ; real_T onujjcrdl4_idx_1 ;
int32_T i ; real32_T tmp ; real32_T tmp_e ; real32_T tmp_p ;
muDoubleScalarSinCos ( jbwi0xitxv , & k1hih2hasy_idx_0 , & onujjcrdl4_idx_0 )
; muDoubleScalarSinCos ( rtP . nyqetrz43uqkkp . Constant_Value_dl1cryfboe , &
k1hih2hasy_idx_1 , & onujjcrdl4_idx_1 ) ; fpimk5asyt [ 0 ] = onujjcrdl4_idx_0
* onujjcrdl4_idx_1 ; fpimk5asyt [ 1 ] = - ( onujjcrdl4_idx_0 *
k1hih2hasy_idx_1 ) ; fpimk5asyt [ 2 ] = - k1hih2hasy_idx_0 ; fpimk5asyt [ 3 ]
= k1hih2hasy_idx_1 ; fpimk5asyt [ 4 ] = onujjcrdl4_idx_1 ; fpimk5asyt [ 5 ] =
rtP . nyqetrz43uqkkp . Constant_Value ; fpimk5asyt [ 6 ] = k1hih2hasy_idx_0 *
onujjcrdl4_idx_1 ; fpimk5asyt [ 7 ] = - ( k1hih2hasy_idx_0 * k1hih2hasy_idx_1
) ; fpimk5asyt [ 8 ] = onujjcrdl4_idx_0 ; tmp = - c1lu2bs0gg [ 0 ] ; tmp_p =
c1lu2bs0gg [ 1 ] ; tmp_e = - c1lu2bs0gg [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ )
{ kjzcbd5o3r [ i ] = ( ( real32_T ) fpimk5asyt [ 3 * i + 1 ] * tmp_p + (
real32_T ) fpimk5asyt [ 3 * i ] * tmp ) + ( real32_T ) fpimk5asyt [ 3 * i + 2
] * tmp_e ; } } rtB . ayq52soaqwz [ 3 * jagyoxt1fz ] = kjzcbd5o3r [ 0 ] ; rtB
. ayq52soaqwz [ 3 * jagyoxt1fz + 1 ] = kjzcbd5o3r [ 1 ] ; rtB . ayq52soaqwz [
3 * jagyoxt1fz + 2 ] = kjzcbd5o3r [ 2 ] ; } void gpbjdtigub ( void ) {
int32_T nbulfcirnz ; for ( nbulfcirnz = 0 ; nbulfcirnz < 7 ; nbulfcirnz ++ )
{ rtB . nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 0 ] = 0.0F ; rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . gg011l2nji [ 0 ] = 0.0F ; rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 1 ] = 0.0F ; rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . gg011l2nji [ 1 ] = 0.0F ; rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 2 ] = 0.0F ; rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . gg011l2nji [ 2 ] = 0.0F ; } } void
jiwpvcutff ( int32_T nbulfcirnz ) { real32_T bzv0spra3zj4 [ 3 ] ; real32_T
lwj5ue2hgkdi [ 3 ] ; real32_T jnkxh0rf3ghc [ 3 ] ; bzv0spra3zj4 [ 0 ] = rtP .
NodePoints_Value_d4b2lmxebb [ 3 * nbulfcirnz ] ; lwj5ue2hgkdi [ 0 ] = rtB .
ayq52soaqw [ 3 * nbulfcirnz ] ; bzv0spra3zj4 [ 1 ] = rtP .
NodePoints_Value_d4b2lmxebb [ 3 * nbulfcirnz + 1 ] ; lwj5ue2hgkdi [ 1 ] = rtB
. ayq52soaqw [ 3 * nbulfcirnz + 1 ] ; bzv0spra3zj4 [ 2 ] = rtP .
NodePoints_Value_d4b2lmxebb [ 3 * nbulfcirnz + 2 ] ; lwj5ue2hgkdi [ 2 ] = rtB
. ayq52soaqw [ 3 * nbulfcirnz + 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 0 ] = bzv0spra3zj4 [ 0 ]
- rtB . nyqetrz43uqkkpi [ nbulfcirnz ] . gg011l2nji [ 0 ] ; rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 1 ] = bzv0spra3zj4 [ 1 ] - rtB
. nyqetrz43uqkkpi [ nbulfcirnz ] . gg011l2nji [ 1 ] ; rtB . nyqetrz43uqkkpi [
nbulfcirnz ] . jqzydkhuci [ 2 ] = bzv0spra3zj4 [ 2 ] - rtB . nyqetrz43uqkkpi
[ nbulfcirnz ] . gg011l2nji [ 2 ] ; } jnkxh0rf3ghc [ 0 ] = rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 1 ] * lwj5ue2hgkdi [ 2 ] -
lwj5ue2hgkdi [ 1 ] * rtB . nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 2 ]
; jnkxh0rf3ghc [ 1 ] = lwj5ue2hgkdi [ 0 ] * rtB . nyqetrz43uqkkpi [
nbulfcirnz ] . jqzydkhuci [ 2 ] - rtB . nyqetrz43uqkkpi [ nbulfcirnz ] .
jqzydkhuci [ 0 ] * lwj5ue2hgkdi [ 2 ] ; jnkxh0rf3ghc [ 2 ] = rtB .
nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 0 ] * lwj5ue2hgkdi [ 1 ] -
lwj5ue2hgkdi [ 0 ] * rtB . nyqetrz43uqkkpi [ nbulfcirnz ] . jqzydkhuci [ 1 ]
; rtB . byhpdluumb [ 3 * nbulfcirnz ] = jnkxh0rf3ghc [ 0 ] ; rtB . byhpdluumb
[ 3 * nbulfcirnz + 1 ] = jnkxh0rf3ghc [ 1 ] ; rtB . byhpdluumb [ 3 *
nbulfcirnz + 2 ] = jnkxh0rf3ghc [ 2 ] ; } void jiwpvcutffTID3 ( int32_T
nbulfcirnz ) { rtB . nyqetrz43uqkkpi [ nbulfcirnz ] . gg011l2nji [ 0 ] = (
real32_T ) rtP . xyz_cg [ 0 ] ; rtB . nyqetrz43uqkkpi [ nbulfcirnz ] .
gg011l2nji [ 1 ] = ( real32_T ) rtP . xyz_cg [ 1 ] ; rtB . nyqetrz43uqkkpi [
nbulfcirnz ] . gg011l2nji [ 2 ] = ( real32_T ) rtP . xyz_cg [ 2 ] ; } void
jpp5owoa3n ( int32_T agcfuo5anh ) { real32_T jbwi0xitxvj ; real32_T
c1lu2bs0ggd [ 3 ] ; real32_T kjzcbd5o3rz [ 3 ] ; jbwi0xitxvj = rtB .
cfz24gonbx [ agcfuo5anh + 7 ] ; c1lu2bs0ggd [ 0 ] = rtB . lif0jqyjen [ 3 *
agcfuo5anh ] ; c1lu2bs0ggd [ 1 ] = rtB . lif0jqyjen [ 3 * agcfuo5anh + 1 ] ;
c1lu2bs0ggd [ 2 ] = rtB . lif0jqyjen [ 3 * agcfuo5anh + 2 ] ; { real_T
pgunyuqaz3 [ 9 ] ; real_T dmp5won5gc_idx_0 ; real_T dmp5won5gc_idx_1 ; real_T
mccgl4diem_idx_0 ; real_T mccgl4diem_idx_1 ; int32_T i ; real32_T tmp ;
real32_T tmp_e ; real32_T tmp_p ; muDoubleScalarSinCos ( jbwi0xitxvj , &
mccgl4diem_idx_0 , & dmp5won5gc_idx_0 ) ; muDoubleScalarSinCos ( rtP .
fchchnbmez . Constant_Value_nflcmvsqzo , & mccgl4diem_idx_1 , &
dmp5won5gc_idx_1 ) ; pgunyuqaz3 [ 0 ] = dmp5won5gc_idx_0 * dmp5won5gc_idx_1 ;
pgunyuqaz3 [ 1 ] = - ( dmp5won5gc_idx_0 * mccgl4diem_idx_1 ) ; pgunyuqaz3 [ 2
] = - mccgl4diem_idx_0 ; pgunyuqaz3 [ 3 ] = mccgl4diem_idx_1 ; pgunyuqaz3 [ 4
] = dmp5won5gc_idx_1 ; pgunyuqaz3 [ 5 ] = rtP . fchchnbmez . Constant_Value ;
pgunyuqaz3 [ 6 ] = mccgl4diem_idx_0 * dmp5won5gc_idx_1 ; pgunyuqaz3 [ 7 ] = -
( mccgl4diem_idx_0 * mccgl4diem_idx_1 ) ; pgunyuqaz3 [ 8 ] = dmp5won5gc_idx_0
; tmp = - c1lu2bs0ggd [ 0 ] ; tmp_p = c1lu2bs0ggd [ 1 ] ; tmp_e = -
c1lu2bs0ggd [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { kjzcbd5o3rz [ i ] = ( (
real32_T ) pgunyuqaz3 [ 3 * i + 1 ] * tmp_p + ( real32_T ) pgunyuqaz3 [ 3 * i
] * tmp ) + ( real32_T ) pgunyuqaz3 [ 3 * i + 2 ] * tmp_e ; } } rtB .
ayq52soaqw [ 3 * agcfuo5anh ] = kjzcbd5o3rz [ 0 ] ; rtB . ayq52soaqw [ 3 *
agcfuo5anh + 1 ] = kjzcbd5o3rz [ 1 ] ; rtB . ayq52soaqw [ 3 * agcfuo5anh + 2
] = kjzcbd5o3rz [ 2 ] ; } void jep0si2kso ( ny4q0xtkup * localB , kpxwjmhxii
* localP , dry5l5lsph * localX ) { localX -> bwl2pyw2pm = localP ->
DistanceintoGustxLimitedtogustlengthd_IC ; localB -> c1tiif3ujm = localP ->
x_Y0 ; } void lcctkqarga ( kpxwjmhxii * localP , dry5l5lsph * localX ) {
localX -> bwl2pyw2pm = localP -> DistanceintoGustxLimitedtogustlengthd_IC ; }
void glfgiolfcq ( fpbcqq3sgu * localDW ) { localDW -> jifjbgbgqy = false ; }
void cdlmndsgcq ( SimStruct * rtS_p , fpbcqq3sgu * localDW ) { localDW ->
jifjbgbgqy = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS_p ) ; }
void fthork0k0x ( SimStruct * rtS_i , boolean_T d5n5w15zb3 , real_T rtp_d_m ,
ny4q0xtkup * localB , fpbcqq3sgu * localDW , kpxwjmhxii * localP , dry5l5lsph
* localX ) { if ( ssIsSampleHit ( rtS_i , 1 , 0 ) && ssIsModeUpdateTimeStep (
rtS_i ) ) { if ( d5n5w15zb3 ) { if ( ! localDW -> jifjbgbgqy ) { if (
ssGetTaskTime ( rtS_i , 1 ) != ssGetTStart ( rtS_i ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } lcctkqarga ( localP
, localX ) ; localDW -> jifjbgbgqy = true ; } } else if ( localDW ->
jifjbgbgqy ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ;
glfgiolfcq ( localDW ) ; } } if ( localDW -> jifjbgbgqy ) { if (
ssIsModeUpdateTimeStep ( rtS_i ) ) { if ( localX -> bwl2pyw2pm >= rtp_d_m ) {
if ( localX -> bwl2pyw2pm != rtp_d_m ) { localX -> bwl2pyw2pm = rtp_d_m ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } } else if ( ( localX
-> bwl2pyw2pm <= localP -> DistanceintoGustxLimitedtogustlengthd_LowerSat )
&& ( localX -> bwl2pyw2pm != localP ->
DistanceintoGustxLimitedtogustlengthd_LowerSat ) ) { localX -> bwl2pyw2pm =
localP -> DistanceintoGustxLimitedtogustlengthd_LowerSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } localB -> c1tiif3ujm
= localX -> bwl2pyw2pm ; srUpdateBC ( localDW -> gxcgpda4hi ) ; } else if (
localX -> bwl2pyw2pm >= rtp_d_m ) { localB -> c1tiif3ujm = rtp_d_m ; } else
if ( localX -> bwl2pyw2pm <= localP ->
DistanceintoGustxLimitedtogustlengthd_LowerSat ) { localB -> c1tiif3ujm =
localP -> DistanceintoGustxLimitedtogustlengthd_LowerSat ; } else { localB ->
c1tiif3ujm = localX -> bwl2pyw2pm ; } } } void jlrztmmapx ( real_T f5k4jjwwtb
, real_T rtp_d_m , fpbcqq3sgu * localDW , kpxwjmhxii * localP , dry5l5lsph *
localX , il4tjwsha2 * localXdot ) { if ( localDW -> jifjbgbgqy ) { if ( ( (
localX -> bwl2pyw2pm > localP ->
DistanceintoGustxLimitedtogustlengthd_LowerSat ) && ( localX -> bwl2pyw2pm <
rtp_d_m ) ) || ( ( localX -> bwl2pyw2pm <= localP ->
DistanceintoGustxLimitedtogustlengthd_LowerSat ) && ( f5k4jjwwtb > 0.0 ) ) ||
( ( localX -> bwl2pyw2pm >= rtp_d_m ) && ( f5k4jjwwtb < 0.0 ) ) ) { localXdot
-> bwl2pyw2pm = f5k4jjwwtb ; } else { localXdot -> bwl2pyw2pm = 0.0 ; } }
else { localXdot -> bwl2pyw2pm = 0.0 ; } } void owmp11rhaq ( a0dvcgex5j *
localDW ) { localDW -> ckwkdnls5w = basxtpz3jk ; localDW -> aqynsdznmr = 0U ;
} void pm13c03kzl ( const real_T oj5oksea0w [ 3 ] , boolean_T nvpbnzaf1k ,
np24g4gdau * localB , a0dvcgex5j * localDW ) { localB -> ggmvjtadg3 [ 0 ] =
oj5oksea0w [ 0 ] ; localB -> ggmvjtadg3 [ 1 ] = oj5oksea0w [ 1 ] ; localB ->
ggmvjtadg3 [ 2 ] = oj5oksea0w [ 2 ] ; localDW -> ckwkdnls5w = basxtpz3jk ; if
( nvpbnzaf1k ) { localB -> ggmvjtadg3 [ 0 ] = localB -> jr3yr4ixei [ 0 ] ;
localB -> ggmvjtadg3 [ 1 ] = localB -> jr3yr4ixei [ 1 ] ; localB ->
ggmvjtadg3 [ 2 ] = localB -> jr3yr4ixei [ 2 ] ; } else { localB -> jr3yr4ixei
[ 0 ] = localB -> ggmvjtadg3 [ 0 ] ; localB -> jr3yr4ixei [ 1 ] = localB ->
ggmvjtadg3 [ 1 ] ; localB -> jr3yr4ixei [ 2 ] = localB -> ggmvjtadg3 [ 2 ] ;
} } void i3rx1r2kpd ( fiqejkualm * localDW ) { localDW -> i2hnwisoi1 =
fy11crjkru ; localDW -> fkmv4gfkl0 = 0U ; } void bezhj2arkr ( const uint8_T
lgciwm45fa [ 39 ] , real32_T pggtavs035 , fskif30kch * localB , fiqejkualm *
localDW ) { int32_T i ; uint8_T y [ 4 ] ; static const uint8_T b [ 5 ] = {
68U , 82U , 69U , 70U , 48U } ; localDW -> i2hnwisoi1 = fy11crjkru ; memset (
& localB -> e1wak2s0nn [ 0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0
; i < 5 ; i ++ ) { localB -> e1wak2s0nn [ i ] = b [ i ] ; } memcpy ( ( void *
) & y [ 0 ] , ( void * ) & pggtavs035 , ( uint32_T ) ( ( size_t ) 4 * sizeof
( uint8_T ) ) ) ; localB -> e1wak2s0nn [ 5 ] = y [ 0 ] ; localB -> e1wak2s0nn
[ 6 ] = y [ 1 ] ; localB -> e1wak2s0nn [ 7 ] = y [ 2 ] ; localB -> e1wak2s0nn
[ 8 ] = y [ 3 ] ; for ( i = 0 ; i < 39 ; i ++ ) { localB -> e1wak2s0nn [ i +
9 ] = lgciwm45fa [ i ] ; } localB -> e1wak2s0nn [ 48 ] = 0U ; } void
kc3n2tu0yh ( pls4xc4scj * localDW ) { localDW -> aquds3y3qy = fv0gv35ypk ;
localDW -> b4sgpwle2l = 0U ; } void bhtkyxb11t ( const uint8_T ellmm2bjow [
40 ] , real32_T kxhf0arinc , p3ecnoeui5 * localB , pls4xc4scj * localDW ) {
int32_T i ; uint8_T y [ 4 ] ; static const uint8_T b [ 5 ] = { 68U , 82U ,
69U , 70U , 48U } ; localDW -> aquds3y3qy = fv0gv35ypk ; memset ( & localB ->
hr4wpt01um [ 0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0 ; i < 5 ; i
++ ) { localB -> hr4wpt01um [ i ] = b [ i ] ; } memcpy ( ( void * ) & y [ 0 ]
, ( void * ) & kxhf0arinc , ( uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T )
) ) ; localB -> hr4wpt01um [ 5 ] = y [ 0 ] ; localB -> hr4wpt01um [ 6 ] = y [
1 ] ; localB -> hr4wpt01um [ 7 ] = y [ 2 ] ; localB -> hr4wpt01um [ 8 ] = y [
3 ] ; for ( i = 0 ; i < 40 ; i ++ ) { localB -> hr4wpt01um [ i + 9 ] =
ellmm2bjow [ i ] ; } localB -> hr4wpt01um [ 49 ] = 0U ; } void e4y3iusrkx (
jiigegnrkw * localDW ) { localDW -> datl4fzkmc = kiiv3nluju ; localDW ->
op350srgbo = 0U ; } void f3054a4w15 ( const uint8_T na5etytz23 [ 37 ] ,
real32_T emewi5swva , dt1fegwimr * localB , jiigegnrkw * localDW ) { int32_T
i ; uint8_T y [ 4 ] ; static const uint8_T b [ 5 ] = { 68U , 82U , 69U , 70U
, 48U } ; localDW -> datl4fzkmc = kiiv3nluju ; memset ( & localB ->
gz0squozgl [ 0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0 ; i < 5 ; i
++ ) { localB -> gz0squozgl [ i ] = b [ i ] ; } memcpy ( ( void * ) & y [ 0 ]
, ( void * ) & emewi5swva , ( uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T )
) ) ; localB -> gz0squozgl [ 5 ] = y [ 0 ] ; localB -> gz0squozgl [ 6 ] = y [
1 ] ; localB -> gz0squozgl [ 7 ] = y [ 2 ] ; localB -> gz0squozgl [ 8 ] = y [
3 ] ; for ( i = 0 ; i < 37 ; i ++ ) { localB -> gz0squozgl [ i + 9 ] =
na5etytz23 [ i ] ; } localB -> gz0squozgl [ 46 ] = 0U ; } void k3ngcghnl5 (
gv4mkh5bt0 * localDW ) { localDW -> apnlfrnpo3 = dpqd33l220 ; localDW ->
ovvez5xelu = 0U ; } void kgud4px1j0 ( const uint8_T nhadz0vqhl [ 51 ] ,
real32_T eifjvvxpgu , lkm4qo0z2m * localB , gv4mkh5bt0 * localDW ) { int32_T
i ; uint8_T y [ 4 ] ; static const uint8_T b [ 5 ] = { 68U , 82U , 69U , 70U
, 48U } ; localDW -> apnlfrnpo3 = dpqd33l220 ; memset ( & localB ->
h11nwvgfxj [ 0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0 ; i < 5 ; i
++ ) { localB -> h11nwvgfxj [ i ] = b [ i ] ; } memcpy ( ( void * ) & y [ 0 ]
, ( void * ) & eifjvvxpgu , ( uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T )
) ) ; localB -> h11nwvgfxj [ 5 ] = y [ 0 ] ; localB -> h11nwvgfxj [ 6 ] = y [
1 ] ; localB -> h11nwvgfxj [ 7 ] = y [ 2 ] ; localB -> h11nwvgfxj [ 8 ] = y [
3 ] ; for ( i = 0 ; i < 51 ; i ++ ) { localB -> h11nwvgfxj [ i + 9 ] =
nhadz0vqhl [ i ] ; } localB -> h11nwvgfxj [ 60 ] = 0U ; } void
rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( const real_T u0 [ 3 ] , const real_T u1
[ 9 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; real_T a21 ; real_T maxval ;
int32_T r1 ; int32_T r2 ; int32_T r3 ; int32_T rtemp ; memcpy ( & A [ 0 ] , &
u1 [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 = 2 ; maxval =
muDoubleScalarAbs ( u1 [ 0 ] ) ; a21 = muDoubleScalarAbs ( u1 [ 1 ] ) ; if (
a21 > maxval ) { maxval = a21 ; r1 = 1 ; r2 = 0 ; } if ( muDoubleScalarAbs (
u1 [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } A [ r2 ] = u1 [ r2 ] /
u1 [ r1 ] ; A [ r3 ] /= A [ r1 ] ; A [ r2 + 3 ] -= A [ r1 + 3 ] * A [ r2 ] ;
A [ r3 + 3 ] -= A [ r1 + 3 ] * A [ r3 ] ; A [ r2 + 6 ] -= A [ r1 + 6 ] * A [
r2 ] ; A [ r3 + 6 ] -= A [ r1 + 6 ] * A [ r3 ] ; if ( muDoubleScalarAbs ( A [
r3 + 3 ] ) > muDoubleScalarAbs ( A [ r2 + 3 ] ) ) { rtemp = r2 + 1 ; r2 = r3
; r3 = rtemp - 1 ; } A [ r3 + 3 ] /= A [ r2 + 3 ] ; A [ r3 + 6 ] -= A [ r3 +
3 ] * A [ r2 + 6 ] ; y [ r1 ] = u0 [ 0 ] / A [ r1 ] ; y [ r2 ] = u0 [ 1 ] - A
[ r1 + 3 ] * y [ r1 ] ; y [ r3 ] = u0 [ 2 ] - A [ r1 + 6 ] * y [ r1 ] ; y [
r2 ] /= A [ r2 + 3 ] ; y [ r3 ] -= A [ r2 + 6 ] * y [ r2 ] ; y [ r3 ] /= A [
r3 + 6 ] ; y [ r2 ] -= A [ r3 + 3 ] * y [ r3 ] ; y [ r1 ] -= y [ r3 ] * A [
r3 ] ; y [ r1 ] -= y [ r2 ] * A [ r2 ] ; } void MdlInitialize ( void ) {
int32_T aldazsptev ; real_T Euler0 ; real_T Euler0_e ; real_T Euler0_p ;
real_T Vb0 ; real_T Vb0_e ; real_T Vb0_p ; int32_T i ; rtDW . kedw3dybgq =
rtP . Memory1_InitialCondition ; rtDW . ktsj2nkchd = rtP .
Memory1_InitialCondition_pjfkz2iyv3 ; rtX . dmrka4iuwk [ 0 ] = rtP . Xe0 [ 0
] ; rtX . jy1l3ujv3t [ 0 ] = rtP . Euler0 [ 0 ] ; rtX . ppiohzkobr [ 0 ] =
rtP . Vb0 [ 0 ] ; rtX . gz3b4js4ds [ 0 ] = rtP . omegab0 [ 0 ] ; rtX .
dmrka4iuwk [ 1 ] = rtP . Xe0 [ 1 ] ; rtX . jy1l3ujv3t [ 1 ] = rtP . Euler0 [
1 ] ; rtX . ppiohzkobr [ 1 ] = rtP . Vb0 [ 1 ] ; rtX . gz3b4js4ds [ 1 ] = rtP
. omegab0 [ 1 ] ; rtX . dmrka4iuwk [ 2 ] = rtP . Xe0 [ 2 ] ; rtX . jy1l3ujv3t
[ 2 ] = rtP . Euler0 [ 2 ] ; rtX . ppiohzkobr [ 2 ] = rtP . Vb0 [ 2 ] ; rtX .
gz3b4js4ds [ 2 ] = rtP . omegab0 [ 2 ] ; memcpy ( & rtDW . g540jxiiax [ 0 ] ,
& rtP . Actuatorprocessingandtransportdelay10ms_InitialCondition [ 0 ] , 100U
* sizeof ( real_T ) ) ; rtDW . oy300njhw2 [ 0 ] = rtP .
Memory_InitialCondition [ 0 ] ; rtDW . ie2l444zba [ 0 ] = rtP .
Memory_InitialCondition_hnyjdse4h4 [ 0 ] ; rtDW . fr2fpc1qxz [ 0 ] = rtP .
Memory_InitialCondition_iqeioiam5g [ 0 ] ; rtDW . oy300njhw2 [ 1 ] = rtP .
Memory_InitialCondition [ 1 ] ; rtDW . ie2l444zba [ 1 ] = rtP .
Memory_InitialCondition_hnyjdse4h4 [ 1 ] ; rtDW . fr2fpc1qxz [ 1 ] = rtP .
Memory_InitialCondition_iqeioiam5g [ 1 ] ; rtDW . oy300njhw2 [ 2 ] = rtP .
Memory_InitialCondition [ 2 ] ; rtDW . ie2l444zba [ 2 ] = rtP .
Memory_InitialCondition_hnyjdse4h4 [ 2 ] ; rtDW . fr2fpc1qxz [ 2 ] = rtP .
Memory_InitialCondition_iqeioiam5g [ 2 ] ; rtX . oqemwaxlko [ 0 ] = rtP .
LinearSecondOrderActuator_fin_act_0 ; rtX . oqemwaxlko [ 1 ] = rtP .
LinearSecondOrderActuator_fin_act_vel ; rtDW . nt5ueu32fc = 0 ; memcpy ( &
rtDW . crxd5n2r3l [ 0 ] , & rtP .
FCCframedelay10msassumed100HzFCC_InitialCondition [ 0 ] , 100U * sizeof (
real_T ) ) ; Vb0 = rtP . Vb0 [ 0 ] ; Vb0_p = rtP . Vb0 [ 1 ] ; Vb0_e = rtP .
Vb0 [ 2 ] ; Euler0 = rtP . Euler0 [ 0 ] ; Euler0_p = rtP . Euler0 [ 1 ] ;
Euler0_e = rtP . Euler0 [ 2 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtDW .
fx230yq5sl [ i ] = rtP . Delay1_InitialCondition ; rtDW . kvnpr153yy [ i ] =
rtP . Delay10_InitialCondition ; rtDW . jhfnsaqhxz [ i ] = Vb0 ; rtDW .
lnmqg4h42q [ i ] = Vb0_p ; rtDW . jsnr5tvela [ i ] = Vb0_e ; rtDW .
buecpeq4re [ i ] = rtP . Xe0 [ 2 ] ; rtDW . asespk50pt [ i ] = Euler0 ; rtDW
. pmmx1tycaz [ i ] = Euler0_p ; rtDW . e5trjt2azz [ i ] = Euler0_e ; } memcpy
( & rtDW . eqbrrfiebl [ 0 ] , & rtP . Delay18_InitialCondition [ 0 ] , 15U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 45 ; i ++ ) { rtDW . fkbachhibk [ i ]
= rtP . Delay19_InitialCondition ; } for ( i = 0 ; i < 5 ; i ++ ) { rtDW .
oaqzp5s2cy [ i ] = rtP . Delay2_InitialCondition ; } for ( i = 0 ; i < 15 ; i
++ ) { rtDW . plokoj1iat [ i ] = rtP . Delay20_InitialCondition ; rtDW .
p3n5g3torf [ i ] = rtP . Delay21_InitialCondition [ i ] ; rtDW . avagxvnwf5 [
i ] = rtP . Delay22_InitialCondition ; } Vb0 = muDoubleScalarAtan ( rtP . Vb0
[ 2 ] / rtP . Vb0 [ 0 ] ) ; Vb0_p = rtP . Xe0 [ 0 ] ; Vb0_e = rtP . Xe0 [ 1 ]
; for ( i = 0 ; i < 5 ; i ++ ) { rtDW . lkru3wc4bj [ i ] = rtP .
Delay23_InitialCondition ; rtDW . pwrdd5kibs [ i ] = Vb0 ; rtDW . erskmg5gj1
[ i ] = rtP . Delay25_InitialCondition ; rtDW . jj43i52zwn [ i ] = rtP .
Delay26_InitialCondition ; rtDW . pagqs1iwpr [ i ] = rtP .
Delay27_InitialCondition ; rtDW . hvagkay33y [ i ] = rtP .
Delay28_InitialCondition ; rtDW . eoz1jvwwoq [ i ] = rtP .
Delay29_InitialCondition ; rtDW . jgluwzgfp1 [ i ] = rtP .
Delay3_InitialCondition ; rtDW . cpjltmd3l2 [ i ] = rtP .
Delay35_InitialCondition ; rtDW . dcos1gkpc2 [ i ] = Vb0_p ; rtDW .
eypbisuusv [ i ] = Vb0_e ; rtDW . ezpcxtf0ip [ i ] = rtP .
Delay6_InitialCondition ; rtDW . ookott5jvl [ i ] = rtP .
Delay7_InitialCondition ; rtDW . h3h1h5xjyq [ i ] = rtP .
Delay8_InitialCondition ; rtDW . aadveypr3e [ i ] = rtP .
Delay9_InitialCondition ; } for ( i = 0 ; i < 6 ; i ++ ) { rtX . n5m0nb0nkj [
i ] = rtP . LinearSecondOrderActuator_fin_act_0_mm13zzlfoj [ i ] ; rtX .
n5m0nb0nkj [ i + 6 ] = rtP . LinearSecondOrderActuator_fin_act_vel_ddjzhl2ptw
; rtDW . ihk13omcli [ i ] = 0 ; rtX . c1kooexubz [ i ] = rtP .
LinearSecondOrderActuator1_fin_act_0 [ i ] ; rtX . c1kooexubz [ i + 6 ] = rtP
. LinearSecondOrderActuator1_fin_act_vel ; rtDW . iwurle5qux [ i ] = 0 ; rtX
. ndpus01ld4 [ i ] = rtP . LinearSecondOrderActuator2_fin_act_0 [ i ] ; rtX .
ndpus01ld4 [ i + 6 ] = rtP . LinearSecondOrderActuator2_fin_act_vel ; rtDW .
pe511og3ku [ i ] = 0 ; } rtX . bdt2nf5etq [ 0 ] = muDoubleScalarAtan ( rtP .
Vb0 [ 2 ] / rtP . Vb0 [ 0 ] ) ; rtX . bdt2nf5etq [ 1 ] = rtP .
LinearSecondOrderActuator3_fin_act_vel ; rtDW . ldrxgujyb0 = 0 ; rtX .
ai1bi54qax [ 0 ] = rtP . LinearSecondOrderActuator4_fin_act_0 ; rtX .
ai1bi54qax [ 1 ] = rtP . LinearSecondOrderActuator4_fin_act_vel ; rtDW .
kksik1paup = 0 ; rtX . a1z3hbtkhc [ 0 ] = rtP .
LinearSecondOrderActuator5_fin_act_0 ; rtX . a1z3hbtkhc [ 1 ] = rtP .
LinearSecondOrderActuator5_fin_act_vel ; rtDW . cbrsqgmwzt = 0 ; rtX .
iugjf2dp5k [ 0 ] = rtP . LinearSecondOrderActuator6_fin_act_0 ; rtX .
iugjf2dp5k [ 1 ] = rtP . LinearSecondOrderActuator6_fin_act_vel ; rtDW .
j1zkhtxhzf = 0 ; rtX . kv0bz415kr [ 0 ] = rtP . Vb0 [ 0 ] ; rtX . kv0bz415kr
[ 1 ] = rtP . Vb0 [ 1 ] ; rtX . kv0bz415kr [ 2 ] = rtP . Vb0 [ 2 ] ; rtX .
kv0bz415kr [ 3 ] = rtP . LinearSecondOrderActuator7_fin_act_vel ; rtDW .
lfxnks51wi [ 0 ] = 0 ; rtX . hxqf43szbj [ 0 ] = rtP . omegab0 [ 0 ] ; rtX .
kv0bz415kr [ 4 ] = rtP . LinearSecondOrderActuator7_fin_act_vel ; rtDW .
lfxnks51wi [ 1 ] = 0 ; rtX . hxqf43szbj [ 1 ] = rtP . omegab0 [ 1 ] ; rtX .
kv0bz415kr [ 5 ] = rtP . LinearSecondOrderActuator7_fin_act_vel ; rtDW .
lfxnks51wi [ 2 ] = 0 ; rtX . hxqf43szbj [ 2 ] = rtP . omegab0 [ 2 ] ; rtX .
hxqf43szbj [ 3 ] = rtP . LinearSecondOrderActuator8_fin_act_vel ; rtDW .
c5hzybmrlt [ 0 ] = 0 ; rtX . hxqf43szbj [ 4 ] = rtP .
LinearSecondOrderActuator8_fin_act_vel ; rtDW . c5hzybmrlt [ 1 ] = 0 ; rtX .
hxqf43szbj [ 5 ] = rtP . LinearSecondOrderActuator8_fin_act_vel ; rtDW .
c5hzybmrlt [ 2 ] = 0 ; { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; {
static const char * blockSIDForSFcnLoader = "UNIFIER:8429" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn .
mdlInitializeConditions . level2 ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtDW . nwwie5t5of = rtP . _InitialCondition ; { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; { static const char * blockSIDForSFcnLoader =
"UNIFIER:8424" ; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader )
; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn .
mdlInitializeConditions . level2 ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
rtDW . oxzbnowmim = ccx3jljkx1 ; rtDW . d04ooymyox = 0U ; i3rx1r2kpd ( & rtDW
. bd32gk0ocy ) ; i3rx1r2kpd ( & rtDW . dffuptpbcz ) ; rtDW . piktw1sptf =
ccx3jljkx1 ; rtDW . chzc3nt2yy = 0U ; rtDW . odfy0ab2zu = ccx3jljkx1 ; rtDW .
pny1rb4usr = 0U ; kc3n2tu0yh ( & rtDW . hl5ibqcu3w ) ; kc3n2tu0yh ( & rtDW .
pookhwl2ri ) ; rtDW . csd33umrye = ccx3jljkx1 ; rtDW . nmnxbsefd1 = 0U ;
e4y3iusrkx ( & rtDW . enohy5yaap ) ; e4y3iusrkx ( & rtDW . nikuyjvr0y ) ;
e4y3iusrkx ( & rtDW . jek5zaxern ) ; k3ngcghnl5 ( & rtDW . n1ybyykngv ) ;
k3ngcghnl5 ( & rtDW . hztlwupntw ) ; rtDW . nndt0j2iyw = ccx3jljkx1 ; rtDW .
bf5ec1ihjs = 0U ; rtPrevZCX . poxwpyd5xz = ZERO_ZCSIG ; rtDW . ml2zybgolh =
ccx3jljkx1 ; rtDW . oek5idxhme = 0U ; rtPrevZCX . asefyvndgw = ZERO_ZCSIG ;
rtX . jmsbhu4m05 = rtP . DistanceintoGustxLimitedtogustlengthd_IC ; rtB .
iu2wb1r235 = rtP . x_Y0 ; jep0si2kso ( & rtB . fthork0k0x2 , & rtP .
fthork0k0x2 , & rtX . fthork0k0x2 ) ; jep0si2kso ( & rtB . pcwoeb21pm , & rtP
. pcwoeb21pm , & rtX . pcwoeb21pm ) ; for ( aldazsptev = 0 ; aldazsptev < 12
; aldazsptev ++ ) { rtX . adqmzv0sx0 [ aldazsptev ] . jtqvm3jkcz = rtP .
DEP_INTEG_IC ; rtX . adqmzv0sx0 [ aldazsptev ] . dkxi20ccfc = rtP .
DEP_PID_IC ; rtDW . adqmzv0sx0 [ aldazsptev ] . kd3fwxo3ke = rtP . adqmzv0sx0
. Memory_InitialCondition ; } owmp11rhaq ( & rtDW . jvaexa3o5a ) ; owmp11rhaq
( & rtDW . leuhdrxpbe ) ; owmp11rhaq ( & rtDW . csf3emrtxr ) ; { SimStruct *
rts = ssGetSFunction ( rtS , 0 ) ; { static const char *
blockSIDForSFcnLoader = "UNIFIER:8414" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlInitializeConditions . level2 ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { int_T
rootPeriodicContStateIndices [ 3 ] = { 3 , 4 , 5 } ; real_T
rootPeriodicContStateRanges [ 6 ] = { - 3.1415926535897931 ,
3.1415926535897931 , - 3.1415926535897931 , 3.1415926535897931 , -
3.1415926535897931 , 3.1415926535897931 } ; ( void ) memcpy ( ( void * )
rtPeriodicIndX , rootPeriodicContStateIndices , 3 * sizeof ( int_T ) ) ; (
void ) memcpy ( ( void * ) rtPeriodicRngX , rootPeriodicContStateRanges , 6 *
sizeof ( real_T ) ) ; } } void MdlStart ( void ) { int32_T aldazsptev ;
char_T * sErr ; { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "u1 (rad)" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "u1 (rad)" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER/C7A_HARW/Aero/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "u1 (rad)" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 6 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. dzukxciamp . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"6c1294bc-6f2c-46cc-adca-18da5faeff09" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . dzukxciamp . AQHandles , hDT , & srcInfo ) ; if ( rtDW . dzukxciamp .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . dzukxciamp . AQHandles ,
"0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
dzukxciamp . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dzukxciamp .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . dzukxciamp . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . dzukxciamp . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . dzukxciamp . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"u1" ) ; sdiRegisterWksVariable ( rtDW . dzukxciamp . AQHandles , varName ,
"structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Sum" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"Sum" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"UNIFIER/C7A_HARW/Aero/To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Sum" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_SINGLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 2 ] = { 1 , 16 } ; sigDims . nDims = 2 ; sigDims . dimensions =
sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = (
sdiFullBlkPathU ) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ;
srcInfo . subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . oumnpiegvc .
AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo .
mmi . InstanceMap . fullPath , "37807c3c-b0d3-42e9-9697-fee3768c0ef4" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . oumnpiegvc . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . oumnpiegvc . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . oumnpiegvc . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . oumnpiegvc . AQHandles
, 0.0 ) ; sdiSetRunStartTime ( rtDW . oumnpiegvc . AQHandles , ssGetTaskTime
( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . oumnpiegvc .
AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . oumnpiegvc .
AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . oumnpiegvc . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"vtail_alpha" ) ; sdiRegisterWksVariable ( rtDW . oumnpiegvc . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "InducedAngleOfAttack:2" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "InducedAngleOfAttack:2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER/C7A_HARW/Aero/To Workspace2" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "InducedAngleOfAttack:2" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_SINGLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 16 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . kmqxlkx3v2 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "1e046056-40a9-4f1e-9d68-4db4943076e7" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . kmqxlkx3v2 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . kmqxlkx3v2 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . kmqxlkx3v2 . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . kmqxlkx3v2 . AQHandles
, 0.0 ) ; sdiSetRunStartTime ( rtDW . kmqxlkx3v2 . AQHandles , ssGetTaskTime
( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . kmqxlkx3v2 .
AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . kmqxlkx3v2 .
AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . kmqxlkx3v2 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"vtail_V_induced" ) ; sdiRegisterWksVariable ( rtDW . kmqxlkx3v2 . AQHandles
, varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "AlphaVtail:2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "AlphaVtail:2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER/C7A_HARW/Aero/To Workspace3" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "AlphaVtail:2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 1 , 16 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . oszdennjt4 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , &
srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"2da700bc-670e-4dbd-9c38-e3e44cea95e6" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . oszdennjt4 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . oszdennjt4 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . oszdennjt4 . AQHandles ,
"0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
oszdennjt4 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . oszdennjt4 .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . oszdennjt4 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . oszdennjt4 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . oszdennjt4 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"vtail_beta" ) ; sdiRegisterWksVariable ( rtDW . oszdennjt4 . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "AlphaWIng:1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "AlphaWIng:1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER/C7A_HARW/Aero/To Workspace4" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "AlphaWIng:1" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 1 , 14 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . glhrtguzli . AQHandles = sdiStartAsyncioQueueCreation ( hDT , &
srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"22e72533-3fe0-406b-8a34-2a0853e1b966" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . glhrtguzli . AQHandles , hDT , & srcInfo ) ; if ( rtDW . glhrtguzli .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . glhrtguzli . AQHandles ,
"0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
glhrtguzli . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . glhrtguzli .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . glhrtguzli . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . glhrtguzli . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . glhrtguzli . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"wing_alpha" ) ; sdiRegisterWksVariable ( rtDW . glhrtguzli . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Gain2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Gain2" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "UNIFIER/C7A_HARW/Aero/VtailForces/Subsystem/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Gain2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 3 , 16 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . dzukxciampy . AQHandles = sdiStartAsyncioQueueCreation ( hDT , &
srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"111f64b9-76f8-4bfb-8fe7-a33dff8665d3" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . dzukxciampy . AQHandles , hDT , & srcInfo ) ; if ( rtDW . dzukxciampy
. AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . dzukxciampy . AQHandles
, "0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
dzukxciampy . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dzukxciampy .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . dzukxciampy . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName
( rtDW . dzukxciampy . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . dzukxciampy . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"vtail_F" ) ; sdiRegisterWksVariable ( rtDW . dzukxciampy . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "w2b" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"w2b" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"UNIFIER/C7A_HARW/Aero/WingForces/Left/Subsystem/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "w2b" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 3 , 7 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . dzukxciampy4 . AQHandles = sdiStartAsyncioQueueCreation ( hDT ,
& srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b6c41388-f1c9-4bdd-8641-b60885b61233" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . dzukxciampy4 . AQHandles , hDT , & srcInfo ) ; if ( rtDW .
dzukxciampy4 . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW .
dzukxciampy4 . AQHandles , "0.01" , 0.01 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . dzukxciampy4 . AQHandles , 0.0 ) ;
sdiSetRunStartTime ( rtDW . dzukxciampy4 . AQHandles , ssGetTaskTime ( rtS ,
2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . dzukxciampy4 . AQHandles
, 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . dzukxciampy4 . AQHandles
, loggedName , origSigName , propName ) ; sdiAsyncRepoSetBlockPathDomain (
rtDW . dzukxciampy4 . AQHandles ) ; } sdiFreeLabel ( sigName ) ; sdiFreeLabel
( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel ( propName ) ;
sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; sdiFreeLabel (
subPath ) ; } } if ( ! isStreamoutAlreadyRegistered ) { { sdiLabelU varName =
sdiGetLabelFromChars ( "wingL_F" ) ; sdiRegisterWksVariable ( rtDW .
dzukxciampy4 . AQHandles , varName , "structwithtime" ) ; sdiFreeLabel (
varName ) ; } } } } } { { { bool isStreamoutAlreadyRegistered = false ; {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"w2b" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "w2b" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"UNIFIER/C7A_HARW/Aero/WingForces/Right/Subsystem/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "w2b" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 3 , 7 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . dzukxciampy43 . AQHandles = sdiStartAsyncioQueueCreation ( hDT ,
& srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"eb6a1a1e-3ee1-4ec3-87bc-3cc41db51576" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . dzukxciampy43 . AQHandles , hDT , & srcInfo ) ; if ( rtDW .
dzukxciampy43 . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW .
dzukxciampy43 . AQHandles , "0.01" , 0.01 , ssGetTFinal ( rtS ) ) ;
sdiSetSignalRefRate ( rtDW . dzukxciampy43 . AQHandles , 0.0 ) ;
sdiSetRunStartTime ( rtDW . dzukxciampy43 . AQHandles , ssGetTaskTime ( rtS ,
2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . dzukxciampy43 .
AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . dzukxciampy43
. AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . dzukxciampy43 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"wingR_F" ) ; sdiRegisterWksVariable ( rtDW . dzukxciampy43 . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "alpha" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "alpha" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "alpha" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "UNIFIER/C7A_HARW/EOMandEnviroment1/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "alpha" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dzukxciampy430 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "1f094952-10ca-4fde-a174-db17585139d1" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . dzukxciampy430 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . dzukxciampy430 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . dzukxciampy430 . AQHandles , "0.01" ,
0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . dzukxciampy430 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dzukxciampy430 . AQHandles ,
ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
dzukxciampy430 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW
. dzukxciampy430 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . dzukxciampy430 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"alpha" ) ; sdiRegisterWksVariable ( rtDW . dzukxciampy430 . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Mux2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Mux2" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "UNIFIER/C7A_HARW/EOMandEnviroment1/To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Mux2" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 6 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . oumnpiegvcp . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "df5f2f77-aa10-4b95-b8bd-8c874df47d98" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . oumnpiegvcp . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . oumnpiegvcp . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . oumnpiegvcp . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . oumnpiegvcp .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . oumnpiegvcp . AQHandles ,
ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
oumnpiegvcp . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
oumnpiegvcp . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . oumnpiegvcp . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"X3" ) ; sdiRegisterWksVariable ( rtDW . oumnpiegvcp . AQHandles , varName ,
"structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Mux1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Mux1" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "UNIFIER/C7A_HARW/EOMandEnviroment1/To Workspace2" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Mux1" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 6 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . kmqxlkx3v2q . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "62b9e246-2526-43fc-86ad-bca150790284" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . kmqxlkx3v2q . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . kmqxlkx3v2q . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . kmqxlkx3v2q . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . kmqxlkx3v2q .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . kmqxlkx3v2q . AQHandles ,
ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
kmqxlkx3v2q . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
kmqxlkx3v2q . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . kmqxlkx3v2q . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"X2" ) ; sdiRegisterWksVariable ( rtDW . kmqxlkx3v2q . AQHandles , varName ,
"structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Mux" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"Mux" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"UNIFIER/C7A_HARW/EOMandEnviroment1/To Workspace3" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Mux" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 6 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . oszdennjt4x . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "bc600833-c24b-4ef7-81d8-8f401734996b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . oszdennjt4x . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . oszdennjt4x . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . oszdennjt4x . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . oszdennjt4x .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . oszdennjt4x . AQHandles ,
ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
oszdennjt4x . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
oszdennjt4x . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . oszdennjt4x . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"X1" ) ; sdiRegisterWksVariable ( rtDW . oszdennjt4x . AQHandles , varName ,
"structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "beta" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "beta" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "beta" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "UNIFIER/C7A_HARW/EOMandEnviroment1/To Workspace4" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "beta" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . glhrtguzlib . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "e00ef68a-9f5a-417f-af8a-0626b6f78b35" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . glhrtguzlib . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . glhrtguzlib . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . glhrtguzlib . AQHandles , "0.01" , 0.01
, ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . glhrtguzlib .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . glhrtguzlib . AQHandles ,
ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
glhrtguzlib . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
glhrtguzlib . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . glhrtguzlib . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"beta" ) ; sdiRegisterWksVariable ( rtDW . glhrtguzlib . AQHandles , varName
, "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "V_rw_mag_tas" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "V_rw_mag_tas" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "V_rw_mag_tas" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER/C7A_HARW/EOMandEnviroment1/To Workspace5" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "V_rw_mag_tas" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. a01trbqc4k . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"3e7e1ec6-d4e1-49ec-91bf-a748b8f49590" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . a01trbqc4k . AQHandles , hDT , & srcInfo ) ; if ( rtDW . a01trbqc4k .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . a01trbqc4k . AQHandles ,
"0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
a01trbqc4k . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . a01trbqc4k .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . a01trbqc4k . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . a01trbqc4k . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . a01trbqc4k . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"Vrw_mag" ) ; sdiRegisterWksVariable ( rtDW . a01trbqc4k . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "DEP:1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "DEP:1" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "UNIFIER/C7A_HARW/Subsystems/DEP/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "DEP:1" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 12 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dzukxciampy430g . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "d993ee96-a6ae-42e7-b999-bfb0d5a57586" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . dzukxciampy430g . AQHandles , hDT ,
& srcInfo ) ; if ( rtDW . dzukxciampy430g . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . dzukxciampy430g . AQHandles , "0.01" ,
0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . dzukxciampy430g .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dzukxciampy430g . AQHandles ,
ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
dzukxciampy430g . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . dzukxciampy430g . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . dzukxciampy430g . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"rpm" ) ; sdiRegisterWksVariable ( rtDW . dzukxciampy430g . AQHandles ,
varName , "structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } { { {
bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "PropAndMotor:2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "PropAndMotor:2" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER/C7A_HARW/Subsystems/HTU/To Workspace" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "PropAndMotor:2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. hpymvgtvx5 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"36c5c2a1-9af8-48a8-8c85-cfee8e327364" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . hpymvgtvx5 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . hpymvgtvx5 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . hpymvgtvx5 . AQHandles ,
"0.01" , 0.01 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
hpymvgtvx5 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . hpymvgtvx5 .
AQHandles , ssGetTaskTime ( rtS , 2 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . hpymvgtvx5 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . hpymvgtvx5 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . hpymvgtvx5 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"HTU" ) ; sdiRegisterWksVariable ( rtDW . hpymvgtvx5 . AQHandles , varName ,
"structwithtime" ) ; sdiFreeLabel ( varName ) ; } } } } } sErr =
GetErrorBuffer ( & rtDW . o4nasosvnh [ 0U ] ) ; CreateUDPInterface ( & rtDW .
o4nasosvnh [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
o4nasosvnh [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) { LibStart ( &
rtDW . o4nasosvnh [ 0U ] ) ; } if ( * sErr != 0 ) { DestroyUDPInterface ( &
rtDW . o4nasosvnh [ 0U ] ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS ,
sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr = GetErrorBuffer ( & rtDW
. lwsgjestu3 [ 0U ] ) ; CreateUDPInterface ( & rtDW . lwsgjestu3 [ 0U ] ) ;
if ( * sErr == 0 ) { LibCreate_Network ( & rtDW . lwsgjestu3 [ 0U ] , 1 ,
"0.0.0.0" , - 1 , "127.0.0.1" , rtP . UDPSend1_remotePort_ardthcndv5 , 8192 ,
1 , 0 ) ; } if ( * sErr == 0 ) { LibStart ( & rtDW . lwsgjestu3 [ 0U ] ) ; }
if ( * sErr != 0 ) { DestroyUDPInterface ( & rtDW . lwsgjestu3 [ 0U ] ) ; if
( * sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS
, 1 ) ; } } pv5uhtasoj ( ) ; f5orepjga5 ( ) ; fhcttf5uve ( ) ; kyeab3bcz3 ( )
; gpbjdtigub ( ) ; for ( aldazsptev = 0 ; aldazsptev < 12 ; aldazsptev ++ ) {
rtB . adqmzv0sx0 [ aldazsptev ] . ibnqksi5kc = 0.0 ; rtB . adqmzv0sx0 [
aldazsptev ] . jagzqtugld = 0.0 ; rtB . adqmzv0sx0 [ aldazsptev ] .
cgxtlo5ezj = false ; rtB . adqmzv0sx0 [ aldazsptev ] . hqlowwzkov = false ;
rtB . adqmzv0sx0 [ aldazsptev ] . ex2xojeend = 0.0 ; rtB . adqmzv0sx0 [
aldazsptev ] . n52zpi4j4s = 0.0 ; rtB . adqmzv0sx0 [ aldazsptev ] .
dfpeduhr4c [ 0 ] = 0.0 ; rtB . adqmzv0sx0 [ aldazsptev ] . aox0khugvh [ 0 ] =
0.0F ; rtB . adqmzv0sx0 [ aldazsptev ] . dfpeduhr4c [ 1 ] = 0.0 ; rtB .
adqmzv0sx0 [ aldazsptev ] . aox0khugvh [ 1 ] = 0.0F ; rtB . adqmzv0sx0 [
aldazsptev ] . dfpeduhr4c [ 2 ] = 0.0 ; rtB . adqmzv0sx0 [ aldazsptev ] .
aox0khugvh [ 2 ] = 0.0F ; memset ( & rtB . adqmzv0sx0 [ aldazsptev ] .
dbnx540oz1 [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; } rtB . pr1zzcknox = rtP .
deviceID_Value ; rtDW . bwa1fip2ky = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtB . lbzmmcd5bg = rtP .
Numberofsimstepstoskip_Value ; { SimStruct * rts = ssGetSFunction ( rtS , 0 )
; { static const char * blockSIDForSFcnLoader = "UNIFIER:8414" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = ssGetmdlStart ( rts ) ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } sErr = GetErrorBuffer ( &
rtDW . faxkrudp40 [ 0U ] ) ; CreateUDPInterface ( & rtDW . faxkrudp40 [ 0U ]
) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW . faxkrudp40 [ 0U ] , 1 ,
"0.0.0.0" , - 1 , "127.0.0.1" , rtP . UDPSend_remotePort , 8192 , 1 , 0 ) ; }
if ( * sErr == 0 ) { LibStart ( & rtDW . faxkrudp40 [ 0U ] ) ; } if ( * sErr
!= 0 ) { DestroyUDPInterface ( & rtDW . faxkrudp40 [ 0U ] ) ; if ( * sErr !=
0 ) { ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } }
{ SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; { static const char *
blockSIDForSFcnLoader = "UNIFIER:31022" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) =
ssGetmdlStart ( rts ) ; sfcnLoader_separateComplexHandler ( rts ,
sfcnMethodPtr ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
sErr = GetErrorBuffer ( & rtDW . m4a0ukvmhq [ 0U ] ) ; CreateUDPInterface ( &
rtDW . m4a0ukvmhq [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW
. m4a0ukvmhq [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_fttrxcefev , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . m4a0ukvmhq [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . m4a0ukvmhq [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . mbrgrjucym [ 0U ] ) ; CreateUDPInterface ( & rtDW .
mbrgrjucym [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
mbrgrjucym [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_eq52r0avzy , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . mbrgrjucym [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . mbrgrjucym [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . abjojyrz15 [ 0U ] ) ; CreateUDPInterface ( & rtDW .
abjojyrz15 [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
abjojyrz15 [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_jffxhvsqzl , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . abjojyrz15 [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . abjojyrz15 [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . ft5azbdazn [ 0U ] ) ; CreateUDPInterface ( & rtDW .
ft5azbdazn [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
ft5azbdazn [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_ijqt2smdg0 , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . ft5azbdazn [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . ft5azbdazn [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . m05hfkvpqz [ 0U ] ) ; CreateUDPInterface ( & rtDW .
m05hfkvpqz [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
m05hfkvpqz [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_ocmwsta0fc , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . m05hfkvpqz [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . m05hfkvpqz [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . ksy2wwjv20 [ 0U ] ) ; CreateUDPInterface ( & rtDW .
ksy2wwjv20 [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
ksy2wwjv20 [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_lq3erkca52 , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . ksy2wwjv20 [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . ksy2wwjv20 [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . axqu4ckdky [ 0U ] ) ; CreateUDPInterface ( & rtDW .
axqu4ckdky [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
axqu4ckdky [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_eimzoxna1i , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . axqu4ckdky [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . axqu4ckdky [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . f00y3b0qin [ 0U ] ) ; CreateUDPInterface ( & rtDW .
f00y3b0qin [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
f00y3b0qin [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_ni5g4d2iss , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . f00y3b0qin [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . f00y3b0qin [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . ehnerh2sch [ 0U ] ) ; CreateUDPInterface ( & rtDW .
ehnerh2sch [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
ehnerh2sch [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_azm1mqpelq , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . ehnerh2sch [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . ehnerh2sch [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . h52cjzwtlm [ 0U ] ) ; CreateUDPInterface ( & rtDW .
h52cjzwtlm [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
h52cjzwtlm [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_dt0jkdmcmg , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . h52cjzwtlm [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . h52cjzwtlm [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . hshhxf1iwg [ 0U ] ) ; CreateUDPInterface ( & rtDW .
hshhxf1iwg [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
hshhxf1iwg [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_bao1nst35q , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . hshhxf1iwg [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . hshhxf1iwg [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } sErr =
GetErrorBuffer ( & rtDW . fsed3lqtd2 [ 0U ] ) ; CreateUDPInterface ( & rtDW .
fsed3lqtd2 [ 0U ] ) ; if ( * sErr == 0 ) { LibCreate_Network ( & rtDW .
fsed3lqtd2 [ 0U ] , 1 , "0.0.0.0" , - 1 , "127.0.0.1" , rtP .
UDPSend1_remotePort_edlmksw0fl , 8192 , 1 , 0 ) ; } if ( * sErr == 0 ) {
LibStart ( & rtDW . fsed3lqtd2 [ 0U ] ) ; } if ( * sErr != 0 ) {
DestroyUDPInterface ( & rtDW . fsed3lqtd2 [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } } rtDW .
pi3jxhaf2b = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
cdlmndsgcq ( rtS , & rtDW . fthork0k0x2 ) ; cdlmndsgcq ( rtS , & rtDW .
pcwoeb21pm ) ; { int_T j ; char ptrKey [ 1024 ] ; { int_T i1 ; int_T *
iw_Tail = & rtDW . l1l2gip32s . Tail [ 0 ] ; int_T * iw_Head = & rtDW .
l1l2gip32s . Head [ 0 ] ; int_T * iw_Last = & rtDW . l1l2gip32s . Last [ 0 ]
; int_T * iw_CircularBufSize = & rtDW . l1l2gip32s . CircularBufSize [ 0 ] ;
void * * pw_TUbufferPtrs = & rtDW . a1p5mmdhor . TUbufferPtrs [ 0 ] ; for (
i1 = 0 ; i1 < 16 ; i1 ++ ) { real_T * pBuffer = ( real_T * )
rt_TDelayCreateBuf ( 2 , 5072 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL
) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ;
} iw_Tail [ i1 ] = 0 ; iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ;
iw_CircularBufSize [ i1 ] = 5072 ; for ( j = 0 ; j < 5072 ; j ++ ) { pBuffer
[ j ] = rtP . VariableTransportDelay1_InitOutput ; pBuffer [ 5072 + j ] =
ssGetT ( rtS ) ; } pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ;
sprintf ( ptrKey ,
 "UNIFIER/C7A_HARW/Aero/InducedAngleOfAttack/addDelay/Variable\nTransport Delay1_TUbuffer%d"
, i1 ) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( &
pw_TUbufferPtrs [ i1 ] ) , 2 * 5072 * sizeof ( real_T ) , ( NULL ) , ( NULL )
) ; } } } { int_T j ; char ptrKey [ 1024 ] ; { int_T i1 ; int_T * iw_Tail = &
rtDW . lynamxwk0r . Tail [ 0 ] ; int_T * iw_Head = & rtDW . lynamxwk0r . Head
[ 0 ] ; int_T * iw_Last = & rtDW . lynamxwk0r . Last [ 0 ] ; int_T *
iw_CircularBufSize = & rtDW . lynamxwk0r . CircularBufSize [ 0 ] ; void * *
pw_TUbufferPtrs = & rtDW . d5j1ciynjn . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ;
i1 < 16 ; i1 ++ ) { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 ,
5072 , sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus (
rtS , "vtdelay memory allocation error" ) ; return ; } iw_Tail [ i1 ] = 0 ;
iw_Head [ i1 ] = 0 ; iw_Last [ i1 ] = 0 ; iw_CircularBufSize [ i1 ] = 5072 ;
for ( j = 0 ; j < 5072 ; j ++ ) { pBuffer [ j ] = rtP .
VariableTransportDelay_InitOutput ; pBuffer [ 5072 + j ] = ssGetT ( rtS ) ; }
pw_TUbufferPtrs [ i1 ] = ( void * ) & pBuffer [ 0 ] ; sprintf ( ptrKey ,
 "UNIFIER/C7A_HARW/Aero/InducedAngleOfAttack/addDelay/Variable\nTransport Delay_TUbuffer%d"
, i1 ) ; slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( &
pw_TUbufferPtrs [ i1 ] ) , 2 * 5072 * sizeof ( real_T ) , ( NULL ) , ( NULL )
) ; } } } { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; { static const
char * blockSIDForSFcnLoader = "UNIFIER:8429" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = ssGetmdlStart ( rts ) ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; { static const char * blockSIDForSFcnLoader =
"UNIFIER:8424" ; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader )
; void ( * sfcnMethodPtr ) ( SimStruct * ) = ssGetmdlStart ( rts ) ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } MdlInitialize ( ) ; } void
MdlOutputs ( int_T tid ) { real_T frhju144cl [ 3 ] ; real_T j4ckedbbex [ 3 ]
; real_T egh4jyhxcm [ 3 ] ; real_T pb5onpph4x [ 16 ] ; real_T j1ncyjcm0a [ 16
] ; real32_T jiw1iujqjc ; real32_T ojlhabvsec ; real32_T nfkmzcdnvu ;
real32_T ddrshnc1rz ; real32_T oympz1skih ; real32_T oqpjcq5edz ; real32_T
iwbdjbsqge ; real32_T fqtwihsnmo ; real32_T arynktfrap ; int32_T aldazsptev ;
real_T ftphjt5uz2 [ 48 ] ; real_T dsccgxajgj [ 36 ] ; real_T gsnhdicnm0 [ 36
] ; real_T hg2rsg5czq [ 21 ] ; real_T nvl2rva03y [ 16 ] ; real_T gmj3cy4km1 [
12 ] ; real_T tmp_p [ 10 ] ; real_T hvlby4ocab [ 9 ] ; real_T eavok2n1gr [ 6
] ; real_T gotsf53ixb [ 6 ] ; real_T tmp [ 5 ] ; real_T frac_pk [ 4 ] ;
real_T frac_po [ 4 ] ; real_T a5zxkwaluu [ 3 ] ; real_T cuwl4zp4yw [ 3 ] ;
real_T frac_d0 [ 3 ] ; real_T frac_fv [ 3 ] ; real_T frac_kh [ 3 ] ; real_T
frac_m0 [ 3 ] ; real_T frac_m4 [ 3 ] ; real_T frac_nf [ 3 ] ; real_T
ga0emsz5x4 [ 3 ] ; real_T jgywcuuufn [ 3 ] ; real_T lk0wlvwohy [ 3 ] ; real_T
nhudhta0yo [ 3 ] ; real_T d0tg15yv0e_idx_1 ; real_T da5ukodejx ; real_T
dmol4f0gb0_idx_1 ; real_T dmol4f0gb0_idx_2 ; real_T do2fmqm0jw_idx_0 ; real_T
do2fmqm0jw_idx_1 ; real_T e12efcqisd ; real_T hndnwewn14_idx_1 ; real_T
hp3vnvb34m_idx_1 ; real_T hp3vnvb34m_idx_2 ; real_T hszixujy0p ; real_T
j2olvplitn_idx_0 ; real_T jgzcqdfrmy_idx_1 ; real_T jgzcqdfrmy_idx_2 ; real_T
jxoxz3uefs ; real_T kkgsybg5mg ; real_T ky1lxji0nf ; real_T lfy4nc2shm ;
real_T lir1dfa45c ; real_T mfkf5g0cet_idx_1 ; real_T mfkf5g0cet_idx_2 ;
real_T mohryahy3p_idx_0 ; real_T mohryahy3p_idx_1 ; real_T mohryahy3p_idx_2 ;
real_T n1fwtevrzf_idx_1 ; real_T ou02bea1mb_idx_0 ; real_T ou02bea1mb_idx_1 ;
real_T pbzebb1cbu_idx_1 ; real_T pbzebb1cbu_idx_2 ; real_T prsndtjjt2 ;
real_T tmp_m ; int32_T i ; int_T jdx ; real32_T iigtngxjbp [ 48 ] ; real32_T
ck1tgxwfew [ 21 ] ; real32_T mpg33qrdtp [ 21 ] ; real32_T bjb5ael2po [ 16 ] ;
real32_T dkboypdf3m [ 16 ] ; real32_T hmfdyqp1cp [ 16 ] ; real32_T lzm2khqk43
[ 16 ] ; real32_T c0f5gkmurs [ 12 ] ; real32_T khgvdadyv1 [ 6 ] ; real32_T
d1u044ebak [ 5 ] ; real32_T gsmuzimw5z [ 5 ] ; real32_T kybpw4f1la [ 5 ] ;
real32_T l2m0tr3gxj [ 5 ] ; real32_T frac [ 4 ] ; real32_T frac_ap [ 4 ] ;
real32_T frac_b [ 4 ] ; real32_T frac_c [ 4 ] ; real32_T frac_ck [ 4 ] ;
real32_T frac_d [ 4 ] ; real32_T frac_dz [ 4 ] ; real32_T frac_e [ 4 ] ;
real32_T frac_f [ 4 ] ; real32_T frac_f2 [ 4 ] ; real32_T frac_fs [ 4 ] ;
real32_T frac_g [ 4 ] ; real32_T frac_hn [ 4 ] ; real32_T frac_i [ 4 ] ;
real32_T frac_j [ 4 ] ; real32_T frac_k [ 4 ] ; real32_T frac_kt [ 4 ] ;
real32_T frac_l [ 4 ] ; real32_T frac_lt [ 4 ] ; real32_T frac_m [ 4 ] ;
real32_T frac_n [ 4 ] ; real32_T frac_o [ 4 ] ; real32_T frac_p [ 4 ] ;
real32_T frac_pj [ 4 ] ; real32_T a4viish00u_p [ 3 ] ; real32_T g0uuf55mpg [
3 ] ; real32_T d3scbkbwlb [ 2 ] ; real32_T frac_b0 [ 2 ] ; real32_T frac_cc [
2 ] ; real32_T frac_gw [ 2 ] ; real32_T frac_iz [ 2 ] ; real32_T frac_mi [ 2
] ; real32_T gsguxbdffk [ 2 ] ; real32_T m1ahso5u4m [ 2 ] ; real32_T
njurhkovsz [ 2 ] ; real32_T ovjd1la42y [ 2 ] ; real32_T pyfokpvamr [ 2 ] ;
real32_T a4viish00u_idx_0 ; real32_T a4viish00u_idx_1 ; real32_T
a4viish00u_idx_2 ; real32_T k11flw5eod ; real32_T kubly5n2ia ; real32_T
lwh2w2o2to ; real32_T mmxlym3ls1_idx_0 ; real32_T mmxlym3ls1_idx_1 ; real32_T
mmxlym3ls1_idx_2 ; real32_T oyx2gc3mag_idx_0 ; real32_T oyx2gc3mag_idx_1 ;
real32_T oyx2gc3mag_idx_2 ; real32_T tmp_e ; real32_T tmp_i ; uint32_T
aovbnhpt5r [ 16 ] ; uint32_T kfwhlxjyld [ 16 ] ; uint32_T nw4cbc4l10 [ 16 ] ;
uint32_T b45rg52mcj [ 5 ] ; uint32_T bpIndex [ 5 ] ; uint32_T bpIndex_ap [ 5
] ; uint32_T bpIndex_b [ 5 ] ; uint32_T bpIndex_c [ 5 ] ; uint32_T bpIndex_ck
[ 5 ] ; uint32_T bpIndex_d [ 5 ] ; uint32_T bpIndex_dz [ 5 ] ; uint32_T
bpIndex_e [ 5 ] ; uint32_T bpIndex_f [ 5 ] ; uint32_T bpIndex_f2 [ 5 ] ;
uint32_T bpIndex_fs [ 5 ] ; uint32_T bpIndex_g [ 5 ] ; uint32_T bpIndex_hn [
5 ] ; uint32_T bpIndex_i [ 5 ] ; uint32_T bpIndex_j [ 5 ] ; uint32_T
bpIndex_k [ 5 ] ; uint32_T bpIndex_kt [ 5 ] ; uint32_T bpIndex_l [ 5 ] ;
uint32_T bpIndex_lt [ 5 ] ; uint32_T bpIndex_m [ 5 ] ; uint32_T bpIndex_n [ 5
] ; uint32_T bpIndex_o [ 5 ] ; uint32_T bpIndex_p [ 5 ] ; uint32_T bpIndex_pj
[ 5 ] ; uint32_T bpIndex_pk [ 5 ] ; uint32_T bpIndex_po [ 5 ] ; uint32_T
ii415rcvoz [ 5 ] ; uint32_T mlqqrra0eq [ 5 ] ; uint32_T bpIndex_d0 [ 4 ] ;
uint32_T bpIndex_fv [ 4 ] ; uint32_T bpIndex_kh [ 4 ] ; uint32_T bpIndex_m0 [
4 ] ; uint32_T bpIndex_m4 [ 4 ] ; uint32_T bpIndex_nf [ 4 ] ; uint32_T
bpIndex_b0 [ 2 ] ; uint32_T bpIndex_cc [ 2 ] ; uint32_T bpIndex_gw [ 2 ] ;
uint32_T bpIndex_iz [ 2 ] ; uint32_T bpIndex_mi [ 2 ] ; uint32_T
jzjq4t0ecb_idx_0 ; uint32_T jzjq4t0ecb_idx_1 ; uint32_T o3v0lawphs_idx_0 ;
uint32_T o3v0lawphs_idx_1 ; uint32_T oejjwkdimx_idx_0 ; uint32_T
oejjwkdimx_idx_1 ; char_T * sErr ; uint8_T y [ 8 ] ; uint8_T b_y [ 4 ] ;
ZCEventType zcEvent ; static const uint8_T b [ 5 ] = { 86U , 69U , 72U , 88U
, 48U } ; static const uint8_T b_p [ 5 ] = { 68U , 82U , 69U , 70U , 48U } ;
srClearBC ( rtDW . pakc2g42kk ) ; srClearBC ( rtDW . fthork0k0x2 . gxcgpda4hi
) ; srClearBC ( rtDW . iw455stvt1 ) ; srClearBC ( rtDW . anhm4dpp2l ) ;
srClearBC ( rtDW . cfvgbkovvu ) ; rtB . exyupufjt5 [ 0 ] = rtX . dmrka4iuwk [
0 ] ; rtB . exyupufjt5 [ 1 ] = rtX . dmrka4iuwk [ 1 ] ; rtB . exyupufjt5 [ 2
] = rtX . dmrka4iuwk [ 2 ] ; j2olvplitn_idx_0 = ( rtB . exyupufjt5 [ 0 ] *
rtB . jurla4fp4a - rtB . exyupufjt5 [ 1 ] * rtB . djshdafk4a ) * rtB .
hc3pucpzoc * 57.295779513082323 + rtB . l1dfj2jhio ; if ( muDoubleScalarAbs (
j2olvplitn_idx_0 ) > rtP . CompareToConstant_const_i014zkpdcc ) {
j2olvplitn_idx_0 = muDoubleScalarMod ( j2olvplitn_idx_0 + rtP .
Bias_Bias_jjp2hxzsy1 , rtP . Constant2_Value_dnaxpvvz45 ) + rtP .
Bias1_Bias_jgjixhvhbb ; } lir1dfa45c = muDoubleScalarAbs ( j2olvplitn_idx_0 )
; if ( lir1dfa45c > rtP . CompareToConstant_const ) { j2olvplitn_idx_0 = ( (
lir1dfa45c + rtP . Bias_Bias ) * rtP . Gain_Gain_pu50nbciii + rtP .
Bias1_Bias ) * muDoubleScalarSign ( j2olvplitn_idx_0 ) ; tmp_m = rtP .
Constant_Value_grffgcb3uj ; } else { tmp_m = rtP . Constant1_Value_ep5qwhnxw4
; } lir1dfa45c = ( ( rtB . exyupufjt5 [ 0 ] * rtB . djshdafk4a + rtB .
exyupufjt5 [ 1 ] * rtB . jurla4fp4a ) * rtB . h1pryicb3f * 57.295779513082323
+ rtB . l0khcdm5vj ) + tmp_m ; if ( muDoubleScalarAbs ( lir1dfa45c ) > rtP .
CompareToConstant_const_jqmuxowg3j ) { lir1dfa45c = muDoubleScalarMod (
lir1dfa45c + rtP . Bias_Bias_gvhsf5vuyl , rtP . Constant2_Value_euehonucuw )
+ rtP . Bias1_Bias_gvvhyuyzsh ; } ga0emsz5x4 [ 0 ] = j2olvplitn_idx_0 ;
ga0emsz5x4 [ 1 ] = lir1dfa45c ; ga0emsz5x4 [ 2 ] = - rtB . exyupufjt5 [ 2 ] -
rtB . exyupufjt5 [ 2 ] ; rtB . gt3gymd154 [ 0 ] = rtX . jy1l3ujv3t [ 0 ] ;
rtB . gt3gymd154 [ 1 ] = rtX . jy1l3ujv3t [ 1 ] ; rtB . gt3gymd154 [ 2 ] =
rtX . jy1l3ujv3t [ 2 ] ; nhudhta0yo [ 0 ] = rtB . gt3gymd154 [ 2 ] ;
nhudhta0yo [ 1 ] = rtB . gt3gymd154 [ 1 ] ; nhudhta0yo [ 2 ] = rtB .
gt3gymd154 [ 0 ] ; g0uuf55mpg [ 0 ] = ( real32_T ) ( rtP .
Gain_Gain_mszzowmsuk * rtB . gt3gymd154 [ 2 ] ) ; g0uuf55mpg [ 1 ] = (
real32_T ) ( rtP . Gain_Gain_mszzowmsuk * rtB . gt3gymd154 [ 1 ] ) ;
g0uuf55mpg [ 2 ] = ( real32_T ) ( rtP . Gain_Gain_mszzowmsuk * rtB .
gt3gymd154 [ 0 ] ) ; rtDW . oxzbnowmim = ccx3jljkx1 ; for ( i = 0 ; i < 45 ;
i ++ ) { rtB . hjcw1qdlw2 [ i ] = 0U ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB .
hjcw1qdlw2 [ i ] = b [ i ] ; } memcpy ( ( void * ) & y [ 0 ] , ( void * ) &
ga0emsz5x4 [ 0 ] , ( uint32_T ) ( ( size_t ) 8 * sizeof ( uint8_T ) ) ) ; for
( i = 0 ; i < 8 ; i ++ ) { rtB . hjcw1qdlw2 [ i + 9 ] = y [ i ] ; } memcpy (
( void * ) & y [ 0 ] , ( void * ) & ga0emsz5x4 [ 1 ] , ( uint32_T ) ( (
size_t ) 8 * sizeof ( uint8_T ) ) ) ; for ( i = 0 ; i < 8 ; i ++ ) { rtB .
hjcw1qdlw2 [ i + 17 ] = y [ i ] ; } memcpy ( ( void * ) & y [ 0 ] , ( void *
) & ga0emsz5x4 [ 2 ] , ( uint32_T ) ( ( size_t ) 8 * sizeof ( uint8_T ) ) ) ;
for ( i = 0 ; i < 8 ; i ++ ) { rtB . hjcw1qdlw2 [ i + 25 ] = y [ i ] ; }
memcpy ( ( void * ) & b_y [ 0 ] , ( void * ) & g0uuf55mpg [ 0 ] , ( uint32_T
) ( ( size_t ) 4 * sizeof ( uint8_T ) ) ) ; rtB . hjcw1qdlw2 [ 33 ] = b_y [ 0
] ; rtB . hjcw1qdlw2 [ 34 ] = b_y [ 1 ] ; rtB . hjcw1qdlw2 [ 35 ] = b_y [ 2 ]
; rtB . hjcw1qdlw2 [ 36 ] = b_y [ 3 ] ; memcpy ( ( void * ) & b_y [ 0 ] , (
void * ) & g0uuf55mpg [ 1 ] , ( uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T
) ) ) ; rtB . hjcw1qdlw2 [ 37 ] = b_y [ 0 ] ; rtB . hjcw1qdlw2 [ 38 ] = b_y [
1 ] ; rtB . hjcw1qdlw2 [ 39 ] = b_y [ 2 ] ; rtB . hjcw1qdlw2 [ 40 ] = b_y [ 3
] ; memcpy ( ( void * ) & b_y [ 0 ] , ( void * ) & g0uuf55mpg [ 2 ] , (
uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T ) ) ) ; rtB . hjcw1qdlw2 [ 41 ]
= b_y [ 0 ] ; rtB . hjcw1qdlw2 [ 42 ] = b_y [ 1 ] ; rtB . hjcw1qdlw2 [ 43 ] =
b_y [ 2 ] ; rtB . hjcw1qdlw2 [ 44 ] = b_y [ 3 ] ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; { static const
char * blockSIDForSFcnLoader = "UNIFIER:31022" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * , int ) = rts -> modelMethods . sFcn .
mdlOutputs . level2 ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } } rtB .
ekmklzxfox [ 0 ] = look1_plinlcapw ( rtB . j3t4wyjy41 [ 0 ] , rtP .
uDLookupTable_bp01Data , rtP . uDLookupTable_tableData , & rtDW . iinforci3b
[ 0 ] , 2U ) ; rtB . ekmklzxfox [ 1 ] = look1_plinlcapw ( rtB . j3t4wyjy41 [
1 ] , rtP . uDLookupTable_bp01Data , rtP . uDLookupTable_tableData , & rtDW .
iinforci3b [ 1 ] , 2U ) ; rtB . ekmklzxfox [ 2 ] = look1_plinlcapw ( rtB .
j3t4wyjy41 [ 2 ] , rtP . uDLookupTable_bp01Data , rtP .
uDLookupTable_tableData , & rtDW . iinforci3b [ 2 ] , 2U ) ; rtB . ekmklzxfox
[ 3 ] = look1_plinlcapw ( rtB . j3t4wyjy41 [ 3 ] , rtP .
uDLookupTable_bp01Data , rtP . uDLookupTable_tableData , & rtDW . iinforci3b
[ 3 ] , 2U ) ; rtB . kz552dd3t1 = rtP . Gain_Gain_laazcdnihk * - rtB .
ekmklzxfox [ 2 ] + rtP . Constant_Value_nxyjglhqnl ; } if ( ssIsSampleHit (
rtS , 2 , 0 ) ) { if ( ( int32_T ) rtP . Constant4_Value == 1 ) { for ( i = 0
; i < 6 ; i ++ ) { rtB . f0lcoipiql [ i ] = rtP . u1_0 [ i ] ; } memcpy ( &
rtB . f0lcoipiql [ 6 ] , & rtP . u2_0 [ 0 ] , 12U * sizeof ( real_T ) ) ; rtB
. f0lcoipiql [ 18 ] = rtP . u3_0 ; rtB . f0lcoipiql [ 19 ] = rtP . u4_0 ; }
else { rtB . f0lcoipiql [ 18 ] = rtP . Gain3_Gain * rtB . kz552dd3t1 ; rtB .
f0lcoipiql [ 19 ] = rtP . Constant1_Value ; rtB . f0lcoipiql [ 6 ] = rtB .
kz552dd3t1 ; rtB . f0lcoipiql [ 7 ] = rtB . kz552dd3t1 ; rtB . f0lcoipiql [ 8
] = rtB . kz552dd3t1 ; rtB . f0lcoipiql [ 9 ] = rtP . Constant2_Value ; rtB .
f0lcoipiql [ 10 ] = rtP . Constant2_Value ; rtB . f0lcoipiql [ 11 ] = rtP .
Constant2_Value ; rtB . f0lcoipiql [ 12 ] = rtP . Constant2_Value ; rtB .
f0lcoipiql [ 13 ] = rtP . Constant2_Value ; rtB . f0lcoipiql [ 14 ] = rtP .
Constant2_Value ; rtB . f0lcoipiql [ 15 ] = rtB . kz552dd3t1 ; rtB .
f0lcoipiql [ 16 ] = rtB . kz552dd3t1 ; rtB . f0lcoipiql [ 17 ] = rtB .
kz552dd3t1 ; if ( rtB . ekmklzxfox [ 3 ] > rtP . DeadZone2_End ) { tmp_m =
rtB . ekmklzxfox [ 3 ] - rtP . DeadZone2_End ; } else if ( rtB . ekmklzxfox [
3 ] >= rtP . DeadZone2_Start ) { tmp_m = 0.0 ; } else { tmp_m = rtB .
ekmklzxfox [ 3 ] - rtP . DeadZone2_Start ; } j2olvplitn_idx_0 = rtP .
Gain2_Gain * tmp_m ; if ( rtB . ekmklzxfox [ 1 ] > rtP . DeadZone1_End ) {
tmp_m = rtB . ekmklzxfox [ 1 ] - rtP . DeadZone1_End ; } else if ( rtB .
ekmklzxfox [ 1 ] >= rtP . DeadZone1_Start ) { tmp_m = 0.0 ; } else { tmp_m =
rtB . ekmklzxfox [ 1 ] - rtP . DeadZone1_Start ; } lir1dfa45c = rtP .
Gain1_Gain * tmp_m ; if ( rtB . ekmklzxfox [ 0 ] > rtP . DeadZone_End ) {
tmp_m = rtB . ekmklzxfox [ 0 ] - rtP . DeadZone_End ; } else if ( rtB .
ekmklzxfox [ 0 ] >= rtP . DeadZone_Start ) { tmp_m = 0.0 ; } else { tmp_m =
rtB . ekmklzxfox [ 0 ] - rtP . DeadZone_Start ; } prsndtjjt2 = rtP .
Gain_Gain * tmp_m ; if ( prsndtjjt2 > rtP . Saturation3_UpperSat ) { rtB .
f0lcoipiql [ 0 ] = rtP . Saturation3_UpperSat ; } else if ( prsndtjjt2 < rtP
. Saturation3_LowerSat ) { rtB . f0lcoipiql [ 0 ] = rtP .
Saturation3_LowerSat ; } else { rtB . f0lcoipiql [ 0 ] = prsndtjjt2 ; } if (
- prsndtjjt2 > rtP . Saturation2_UpperSat ) { rtB . f0lcoipiql [ 1 ] = rtP .
Saturation2_UpperSat ; } else if ( - prsndtjjt2 < rtP . Saturation2_LowerSat
) { rtB . f0lcoipiql [ 1 ] = rtP . Saturation2_LowerSat ; } else { rtB .
f0lcoipiql [ 1 ] = - prsndtjjt2 ; } ky1lxji0nf = lir1dfa45c -
j2olvplitn_idx_0 ; if ( ky1lxji0nf > rtP . Saturation_UpperSat ) { rtB .
f0lcoipiql [ 2 ] = rtP . Saturation_UpperSat ; } else if ( ky1lxji0nf < rtP .
Saturation_LowerSat ) { rtB . f0lcoipiql [ 2 ] = rtP . Saturation_LowerSat ;
} else { rtB . f0lcoipiql [ 2 ] = ky1lxji0nf ; } ky1lxji0nf = lir1dfa45c +
j2olvplitn_idx_0 ; if ( ky1lxji0nf > rtP . Saturation1_UpperSat ) { rtB .
f0lcoipiql [ 3 ] = rtP . Saturation1_UpperSat ; } else if ( ky1lxji0nf < rtP
. Saturation1_LowerSat ) { rtB . f0lcoipiql [ 3 ] = rtP .
Saturation1_LowerSat ; } else { rtB . f0lcoipiql [ 3 ] = ky1lxji0nf ; } rtB .
f0lcoipiql [ 4 ] = rtP . Constant_Value ; rtB . f0lcoipiql [ 5 ] = rtP .
Constant_Value ; } jiw1iujqjc = ( real32_T ) ( rtP . Gain_Gain_hkwjozvx2n *
rtB . f0lcoipiql [ 0 ] ) ; bezhj2arkr ( rtP . Constant_Value_ezp4vos5at ,
jiw1iujqjc , & rtB . bd32gk0ocy , & rtDW . bd32gk0ocy ) ; ojlhabvsec = (
real32_T ) ( rtP . Gain_Gain_mw0psof1f3 * rtB . f0lcoipiql [ 1 ] ) ;
bezhj2arkr ( rtP . Constant_Value_o1jhv21mne , ojlhabvsec , & rtB .
dffuptpbcz , & rtDW . dffuptpbcz ) ; rtB . bopxyfw2ia = rtDW . kedw3dybgq ;
j2olvplitn_idx_0 = rtB . f0lcoipiql [ 11 ] * rtP . Constant3_Value_arqhpk5tsi
+ rtB . bopxyfw2ia ; if ( j2olvplitn_idx_0 > rtP . Switch_Threshold ) { rtB .
ecvavrybwp = rtP . Constant2_Value_evxyvbxyx4 ; } else { rtB . ecvavrybwp =
j2olvplitn_idx_0 ; } k11flw5eod = ( real32_T ) rtB . ecvavrybwp ; rtDW .
piktw1sptf = ccx3jljkx1 ; memset ( & rtB . bqi10o4hpx [ 0 ] , 32 , 509U *
sizeof ( uint8_T ) ) ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . bqi10o4hpx [ i ]
= b_p [ i ] ; } memcpy ( ( void * ) & b_y [ 0 ] , ( void * ) & k11flw5eod , (
uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T ) ) ) ; rtB . bqi10o4hpx [ 5 ] =
b_y [ 0 ] ; rtB . bqi10o4hpx [ 6 ] = b_y [ 1 ] ; rtB . bqi10o4hpx [ 7 ] = b_y
[ 2 ] ; rtB . bqi10o4hpx [ 8 ] = b_y [ 3 ] ; for ( i = 0 ; i < 29 ; i ++ ) {
rtB . bqi10o4hpx [ i + 9 ] = rtP . Constant_Value_oln3j4ocph [ i ] ; } rtB .
bqi10o4hpx [ 38 ] = 0U ; if ( rtB . f0lcoipiql [ 11 ] > rtP .
Switch_Threshold_keldsx1mfj ) { k11flw5eod = ( real32_T ) rtP .
Constant2_Value_fqbq1clpin ; } else { k11flw5eod = ( real32_T ) rtP .
Constant3_Value_nbcxsvbsnn ; } rtDW . odfy0ab2zu = ccx3jljkx1 ; memset ( &
rtB . kno2d54iit [ 0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0 ; i <
5 ; i ++ ) { rtB . kno2d54iit [ i ] = b_p [ i ] ; } memcpy ( ( void * ) & b_y
[ 0 ] , ( void * ) & k11flw5eod , ( uint32_T ) ( ( size_t ) 4 * sizeof (
uint8_T ) ) ) ; rtB . kno2d54iit [ 5 ] = b_y [ 0 ] ; rtB . kno2d54iit [ 6 ] =
b_y [ 1 ] ; rtB . kno2d54iit [ 7 ] = b_y [ 2 ] ; rtB . kno2d54iit [ 8 ] = b_y
[ 3 ] ; for ( i = 0 ; i < 27 ; i ++ ) { rtB . kno2d54iit [ i + 9 ] = rtP .
Constant_Value_deiptb1fdi [ i ] ; } rtB . kno2d54iit [ 36 ] = 0U ; nfkmzcdnvu
= ( real32_T ) ( rtP . Gain_Gain_n4k11xn3pg * rtB . f0lcoipiql [ 2 ] ) ;
bhtkyxb11t ( rtP . Constant_Value_bunajjeyd1 , nfkmzcdnvu , & rtB .
hl5ibqcu3w , & rtDW . hl5ibqcu3w ) ; ddrshnc1rz = ( real32_T ) ( rtP .
Gain_Gain_lmgk2iw1td * rtB . f0lcoipiql [ 3 ] ) ; bhtkyxb11t ( rtP .
Constant_Value_fu24dwcohf , ddrshnc1rz , & rtB . pookhwl2ri , & rtDW .
pookhwl2ri ) ; k11flw5eod = ( real32_T ) ( rtP . Gain_Gain_aycx2qnlhg * rtB .
f0lcoipiql [ 4 ] * rtP . Gain_Gain_fqf4wrixzl ) ; rtDW . csd33umrye =
ccx3jljkx1 ; memset ( & rtB . iffp5o1pbp [ 0 ] , 32 , 509U * sizeof ( uint8_T
) ) ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . iffp5o1pbp [ i ] = b_p [ i ] ; }
memcpy ( ( void * ) & b_y [ 0 ] , ( void * ) & k11flw5eod , ( uint32_T ) ( (
size_t ) 4 * sizeof ( uint8_T ) ) ) ; rtB . iffp5o1pbp [ 5 ] = b_y [ 0 ] ;
rtB . iffp5o1pbp [ 6 ] = b_y [ 1 ] ; rtB . iffp5o1pbp [ 7 ] = b_y [ 2 ] ; rtB
. iffp5o1pbp [ 8 ] = b_y [ 3 ] ; for ( i = 0 ; i < 32 ; i ++ ) { rtB .
iffp5o1pbp [ i + 9 ] = rtP . Constant_Value_p45zmbuefy [ i ] ; } rtB .
iffp5o1pbp [ 41 ] = 0U ; oympz1skih = ( real32_T ) rtB . f0lcoipiql [ 19 ] ;
f3054a4w15 ( rtP . Constant_Value_mpqd4zb22a , oympz1skih , & rtB .
enohy5yaap , & rtDW . enohy5yaap ) ; oqpjcq5edz = ( real32_T ) rtB .
f0lcoipiql [ 19 ] ; f3054a4w15 ( rtP . Constant_Value_prr5w4kjl2 , oqpjcq5edz
, & rtB . nikuyjvr0y , & rtDW . nikuyjvr0y ) ; iwbdjbsqge = ( real32_T ) rtB
. f0lcoipiql [ 19 ] ; f3054a4w15 ( rtP . Constant_Value_lqvyli4q5s ,
iwbdjbsqge , & rtB . jek5zaxern , & rtDW . jek5zaxern ) ; rtB . okge55f2b5 =
rtDW . ktsj2nkchd ; j2olvplitn_idx_0 = rtB . f0lcoipiql [ 18 ] * rtP .
Constant3_Value_kdceg0pib4 + rtB . okge55f2b5 ; if ( j2olvplitn_idx_0 > rtP .
Switch_Threshold_lm0zosgxar ) { rtB . n2fj5a4cso = rtP .
Constant2_Value_imckxbitho ; } else { rtB . n2fj5a4cso = j2olvplitn_idx_0 ; }
fqtwihsnmo = ( real32_T ) rtB . n2fj5a4cso ; kgud4px1j0 ( rtP .
Constant_Value_e2xroppgrn , fqtwihsnmo , & rtB . n1ybyykngv , & rtDW .
n1ybyykngv ) ; arynktfrap = ( real32_T ) rtB . ecvavrybwp ; kgud4px1j0 ( rtP
. Constant_Value_nmj1ootknt , arynktfrap , & rtB . hztlwupntw , & rtDW .
hztlwupntw ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsModeUpdateTimeStep
( rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX .
poxwpyd5xz , ( rtP . Constant_Value_lkyy414dse ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { rtDW . nndt0j2iyw = ccx3jljkx1 ; memset ( & rtB . o0njsmigyn [
0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0 ; i < 5 ; i ++ ) { rtB .
o0njsmigyn [ i ] = b_p [ i ] ; } memcpy ( ( void * ) & b_y [ 0 ] , ( void * )
& rtB . ckez2fhnc0 , ( uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T ) ) ) ;
rtB . o0njsmigyn [ 5 ] = b_y [ 0 ] ; rtB . o0njsmigyn [ 6 ] = b_y [ 1 ] ; rtB
. o0njsmigyn [ 7 ] = b_y [ 2 ] ; rtB . o0njsmigyn [ 8 ] = b_y [ 3 ] ; for ( i
= 0 ; i < 45 ; i ++ ) { rtB . o0njsmigyn [ i + 9 ] = rtP .
Constant_Value_ecr3ukwupu [ i ] ; } rtB . o0njsmigyn [ 54 ] = 0U ; sErr =
GetErrorBuffer ( & rtDW . o4nasosvnh [ 0U ] ) ; LibUpdate_Network ( & rtDW .
o4nasosvnh [ 0U ] , & rtB . o0njsmigyn [ 0U ] , 509 ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } rtDW .
anhm4dpp2l = 4 ; } zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX .
asefyvndgw , ( rtP . Constant1_Value_poq4unoobj ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { rtDW . ml2zybgolh = ccx3jljkx1 ; memset ( & rtB . gtlyl45i3j [
0 ] , 32 , 509U * sizeof ( uint8_T ) ) ; for ( i = 0 ; i < 5 ; i ++ ) { rtB .
gtlyl45i3j [ i ] = b_p [ i ] ; } memcpy ( ( void * ) & b_y [ 0 ] , ( void * )
& rtB . ar3fw3fuom , ( uint32_T ) ( ( size_t ) 4 * sizeof ( uint8_T ) ) ) ;
rtB . gtlyl45i3j [ 5 ] = b_y [ 0 ] ; rtB . gtlyl45i3j [ 6 ] = b_y [ 1 ] ; rtB
. gtlyl45i3j [ 7 ] = b_y [ 2 ] ; rtB . gtlyl45i3j [ 8 ] = b_y [ 3 ] ; for ( i
= 0 ; i < 48 ; i ++ ) { rtB . gtlyl45i3j [ i + 9 ] = rtP .
Constant_Value_cj4suguqdh [ i ] ; } rtB . gtlyl45i3j [ 57 ] = 0U ; sErr =
GetErrorBuffer ( & rtDW . lwsgjestu3 [ 0U ] ) ; LibUpdate_Network ( & rtDW .
lwsgjestu3 [ 0U ] , & rtB . gtlyl45i3j [ 0U ] , 509 ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } rtDW .
cfvgbkovvu = 4 ; } } mohryahy3p_idx_0 = rtX . ppiohzkobr [ 0 ] ; rtB .
li5x4km43d [ 0 ] = rtX . ppiohzkobr [ 0 ] ; mohryahy3p_idx_1 = rtX .
ppiohzkobr [ 1 ] ; rtB . li5x4km43d [ 1 ] = rtX . ppiohzkobr [ 1 ] ;
mohryahy3p_idx_2 = rtX . ppiohzkobr [ 2 ] ; rtB . li5x4km43d [ 2 ] = rtX .
ppiohzkobr [ 2 ] ; j2olvplitn_idx_0 = ( ssGetT ( rtS ) >= rtP .
DiscreteWindGustModel1_t_0 ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) &&
ssIsModeUpdateTimeStep ( rtS ) ) { if ( ( j2olvplitn_idx_0 != 0.0 ) && rtP .
DiscreteWindGustModel1_Gx ) { if ( ! rtDW . pi3jxhaf2b ) { if ( ssGetTaskTime
( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtX . jmsbhu4m05 = rtP
. DistanceintoGustxLimitedtogustlengthd_IC ; rtDW . pi3jxhaf2b = true ; } }
else if ( rtDW . pi3jxhaf2b ) { ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; rtDW . pi3jxhaf2b = false ; } } if ( rtDW . pi3jxhaf2b ) { if (
ssIsModeUpdateTimeStep ( rtS ) ) { if ( rtX . jmsbhu4m05 >= rtP .
Distanceintogustx_d_m ) { if ( rtX . jmsbhu4m05 != rtP .
Distanceintogustx_d_m ) { rtX . jmsbhu4m05 = rtP . Distanceintogustx_d_m ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } else if ( ( rtX .
jmsbhu4m05 <= rtP . DistanceintoGustxLimitedtogustlengthd_LowerSat ) && ( rtX
. jmsbhu4m05 != rtP . DistanceintoGustxLimitedtogustlengthd_LowerSat ) ) {
rtX . jmsbhu4m05 = rtP . DistanceintoGustxLimitedtogustlengthd_LowerSat ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtB . iu2wb1r235 = rtX
. jmsbhu4m05 ; srUpdateBC ( rtDW . pakc2g42kk ) ; } else if ( rtX .
jmsbhu4m05 >= rtP . Distanceintogustx_d_m ) { rtB . iu2wb1r235 = rtP .
Distanceintogustx_d_m ; } else if ( rtX . jmsbhu4m05 <= rtP .
DistanceintoGustxLimitedtogustlengthd_LowerSat ) { rtB . iu2wb1r235 = rtP .
DistanceintoGustxLimitedtogustlengthd_LowerSat ; } else { rtB . iu2wb1r235 =
rtX . jmsbhu4m05 ; } } rtB . n3u1rxuv5j = ( ( j2olvplitn_idx_0 != 0.0 ) &&
rtP . DiscreteWindGustModel1_Gy ) ; fthork0k0x ( rtS , rtB . n3u1rxuv5j , rtP
. Distanceintogusty_d_m , & rtB . fthork0k0x2 , & rtDW . fthork0k0x2 , & rtP
. fthork0k0x2 , & rtX . fthork0k0x2 ) ; rtB . hetdp5lb3h = ( (
j2olvplitn_idx_0 != 0.0 ) && rtP . DiscreteWindGustModel1_Gz ) ; fthork0k0x (
rtS , rtB . hetdp5lb3h , rtP . Distanceintogustz_d_m , & rtB . pcwoeb21pm , &
rtDW . pcwoeb21pm , & rtP . pcwoeb21pm , & rtX . pcwoeb21pm ) ; rtB .
gxhe3keu3a [ 0 ] = ( rtP . u_Value - muDoubleScalarCos ( 3.1415926535897931 /
rtP . DiscreteWindGustModel1_d_m [ 0 ] * rtB . iu2wb1r235 ) ) * ( rtP .
DiscreteWindGustModel1_v_m [ 0 ] / 2.0 ) + rtB . li5x4km43d [ 0 ] ; rtB .
gxhe3keu3a [ 1 ] = ( rtP . u_Value - muDoubleScalarCos ( 3.1415926535897931 /
rtP . DiscreteWindGustModel1_d_m [ 1 ] * rtB . fthork0k0x2 . c1tiif3ujm ) ) *
( rtP . DiscreteWindGustModel1_v_m [ 1 ] / 2.0 ) + rtB . li5x4km43d [ 1 ] ;
rtB . gxhe3keu3a [ 2 ] = ( rtP . u_Value - muDoubleScalarCos (
3.1415926535897931 / rtP . DiscreteWindGustModel1_d_m [ 2 ] * rtB .
pcwoeb21pm . c1tiif3ujm ) ) * ( rtP . DiscreteWindGustModel1_v_m [ 2 ] / 2.0
) + rtB . li5x4km43d [ 2 ] ; if ( rtP . ManualSwitch_CurrentSetting == 1 ) {
jxoxz3uefs = rtB . li5x4km43d [ 0 ] ; } else { jxoxz3uefs = rtB . gxhe3keu3a
[ 0 ] ; } ga0emsz5x4 [ 0 ] = jxoxz3uefs ; rtB . jrm5mulpgo [ 0 ] = ( real32_T
) jxoxz3uefs ; rtB . dohtax3vu3 [ 0 ] = rtX . gz3b4js4ds [ 0 ] ; hszixujy0p =
rtP . Constant_Value_nidy3scify [ 0 ] + rtX . gz3b4js4ds [ 0 ] ; rtB .
hszixujy0p [ 0 ] = hszixujy0p ; if ( rtP . ManualSwitch1_CurrentSetting != 1
) { hszixujy0p = rtX . gz3b4js4ds [ 0 ] ; } ou02bea1mb_idx_0 = hszixujy0p ;
rtB . kp4feo544t [ 0 ] = ( real32_T ) hszixujy0p ; if ( rtP .
ManualSwitch_CurrentSetting == 1 ) { jxoxz3uefs = rtB . li5x4km43d [ 1 ] ; }
else { jxoxz3uefs = rtB . gxhe3keu3a [ 1 ] ; } ga0emsz5x4 [ 1 ] = jxoxz3uefs
; rtB . jrm5mulpgo [ 1 ] = ( real32_T ) jxoxz3uefs ; rtB . dohtax3vu3 [ 1 ] =
rtX . gz3b4js4ds [ 1 ] ; hszixujy0p = rtP . Constant_Value_nidy3scify [ 1 ] +
rtX . gz3b4js4ds [ 1 ] ; rtB . hszixujy0p [ 1 ] = hszixujy0p ; if ( rtP .
ManualSwitch1_CurrentSetting != 1 ) { hszixujy0p = rtX . gz3b4js4ds [ 1 ] ; }
ou02bea1mb_idx_1 = hszixujy0p ; rtB . kp4feo544t [ 1 ] = ( real32_T )
hszixujy0p ; if ( rtP . ManualSwitch_CurrentSetting == 1 ) { jxoxz3uefs = rtB
. li5x4km43d [ 2 ] ; } else { jxoxz3uefs = rtB . gxhe3keu3a [ 2 ] ; } rtB .
jrm5mulpgo [ 2 ] = ( real32_T ) jxoxz3uefs ; rtB . dohtax3vu3 [ 2 ] = rtX .
gz3b4js4ds [ 2 ] ; hszixujy0p = rtP . Constant_Value_nidy3scify [ 2 ] + rtX .
gz3b4js4ds [ 2 ] ; rtB . hszixujy0p [ 2 ] = hszixujy0p ; if ( rtP .
ManualSwitch1_CurrentSetting != 1 ) { hszixujy0p = rtX . gz3b4js4ds [ 2 ] ; }
rtB . kp4feo544t [ 2 ] = ( real32_T ) hszixujy0p ; parallel_for ( 14 ,
ppqwruko3j , 1 , "ppqwruko3j" ) ; rtB . korrwukkg3 [ 0 ] = rtB . cfz24gonbx [
6 ] ; rtB . korrwukkg3 [ 1 ] = rtB . cfz24gonbx [ 5 ] ; rtB . korrwukkg3 [ 2
] = rtB . cfz24gonbx [ 4 ] ; rtB . korrwukkg3 [ 3 ] = rtB . cfz24gonbx [ 3 ]
; rtB . korrwukkg3 [ 4 ] = rtB . cfz24gonbx [ 2 ] ; rtB . korrwukkg3 [ 5 ] =
rtB . cfz24gonbx [ 1 ] ; rtB . korrwukkg3 [ 6 ] = rtB . cfz24gonbx [ 0 ] ;
mpg33qrdtp [ 0 ] = rtB . nmxk2xrfk3 [ 6 ] ; mpg33qrdtp [ 1 ] = rtB .
nmxk2xrfk3 [ 5 ] ; mpg33qrdtp [ 2 ] = rtB . nmxk2xrfk3 [ 4 ] ; mpg33qrdtp [ 3
] = rtB . nmxk2xrfk3 [ 3 ] ; mpg33qrdtp [ 4 ] = rtB . nmxk2xrfk3 [ 2 ] ;
mpg33qrdtp [ 5 ] = rtB . nmxk2xrfk3 [ 1 ] ; mpg33qrdtp [ 6 ] = rtB .
nmxk2xrfk3 [ 0 ] ; mpg33qrdtp [ 7 ] = rtB . nmxk2xrfk3 [ 6 ] ; mpg33qrdtp [ 8
] = rtB . nmxk2xrfk3 [ 5 ] ; mpg33qrdtp [ 9 ] = rtB . nmxk2xrfk3 [ 4 ] ;
mpg33qrdtp [ 10 ] = rtB . nmxk2xrfk3 [ 3 ] ; mpg33qrdtp [ 11 ] = rtB .
nmxk2xrfk3 [ 2 ] ; mpg33qrdtp [ 12 ] = rtB . nmxk2xrfk3 [ 1 ] ; mpg33qrdtp [
13 ] = rtB . nmxk2xrfk3 [ 0 ] ; mpg33qrdtp [ 14 ] = rtB . nmxk2xrfk3 [ 6 ] ;
mpg33qrdtp [ 15 ] = rtB . nmxk2xrfk3 [ 5 ] ; mpg33qrdtp [ 16 ] = rtB .
nmxk2xrfk3 [ 4 ] ; mpg33qrdtp [ 17 ] = rtB . nmxk2xrfk3 [ 3 ] ; mpg33qrdtp [
18 ] = rtB . nmxk2xrfk3 [ 2 ] ; mpg33qrdtp [ 19 ] = rtB . nmxk2xrfk3 [ 1 ] ;
mpg33qrdtp [ 20 ] = rtB . nmxk2xrfk3 [ 0 ] ; for ( i = 0 ; i < 7 ; i ++ ) {
ck1tgxwfew [ 3 * i ] = mpg33qrdtp [ i ] ; ck1tgxwfew [ 3 * i + 1 ] =
mpg33qrdtp [ i + 7 ] ; ck1tgxwfew [ 3 * i + 2 ] = mpg33qrdtp [ i + 14 ] ; }
for ( i = 0 ; i < 21 ; i ++ ) { mmxlym3ls1_idx_0 = ck1tgxwfew [ i ] ;
ck1tgxwfew [ i ] = mmxlym3ls1_idx_0 * mmxlym3ls1_idx_0 ; } if ( ssIsSampleHit
( rtS , 2 , 0 ) ) { memcpy ( & rtB . nn0j0nwtai [ 0 ] , & rtDW . g540jxiiax [
0 ] , 20U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 6 ; i ++ ) { khgvdadyv1 [
i ] = ( real32_T ) rtB . nn0j0nwtai [ i ] ; } rtB . pgacreyak0 =
plook_u32ff_lincpa ( khgvdadyv1 [ 4 ] , rtP . dp_WING_root . flap_defl , 4U ,
& rtB . buybsypzuh , & rtDW . onpp1osnf1 ) ; } d1u044ebak [ 0 ] = rtB .
cfz24gonbx [ 6 ] ; d1u044ebak [ 1 ] = rtB . cfz24gonbx [ 5 ] ; d1u044ebak [ 2
] = rtB . cfz24gonbx [ 4 ] ; d1u044ebak [ 3 ] = rtB . cfz24gonbx [ 3 ] ;
d1u044ebak [ 4 ] = rtB . cfz24gonbx [ 2 ] ; for ( jdx = 0 ; jdx < 5 ; jdx ++
) { b45rg52mcj [ jdx ] = plook_u32ff_lincpa ( d1u044ebak [ jdx ] , rtP .
dp_WING_root . alphas , 24U , & gsmuzimw5z [ jdx ] , & rtDW . knywr3cygt [
jdx ] ) ; } d1u044ebak [ 0 ] = rtB . nmxk2xrfk3 [ 6 ] ; d1u044ebak [ 1 ] =
rtB . nmxk2xrfk3 [ 5 ] ; d1u044ebak [ 2 ] = rtB . nmxk2xrfk3 [ 4 ] ;
d1u044ebak [ 3 ] = rtB . nmxk2xrfk3 [ 3 ] ; d1u044ebak [ 4 ] = rtB .
nmxk2xrfk3 [ 2 ] ; for ( jdx = 0 ; jdx < 5 ; jdx ++ ) { mlqqrra0eq [ jdx ] =
plook_u32ff_lincpa ( d1u044ebak [ jdx ] , rtP . dp_WING_root . V , 1U , &
l2m0tr3gxj [ jdx ] , & rtDW . bxxehqrfhk [ jdx ] ) ; } for ( i = 0 ; i < 12 ;
i ++ ) { rtB . nupdx24lfb [ i ] = ( rtB . dohtax3vu3 [ 2 ] * rtB . dcirnuyxde
[ i ] + ga0emsz5x4 [ 0 ] ) * rtB . jferaaeyyn ; } if ( ( real32_T ) - rtB .
exyupufjt5 [ 2 ] > rtP . Limitaltitudetotroposhere_UpperSat ) {
a4viish00u_idx_0 = rtP . Limitaltitudetotroposhere_UpperSat ; } else if ( (
real32_T ) - rtB . exyupufjt5 [ 2 ] < rtP .
Limitaltitudetotroposhere_LowerSat ) { a4viish00u_idx_0 = rtP .
Limitaltitudetotroposhere_LowerSat ; } else { a4viish00u_idx_0 = ( real32_T )
- rtB . exyupufjt5 [ 2 ] ; } rtB . ieaokh1oup = rtP .
SeaLevelTemperature_Value - ( real32_T ) ( rtP . LapseRate_Gain *
a4viish00u_idx_0 ) ; prsndtjjt2 = rtP . uT0_Gain * rtB . ieaokh1oup ; if ( (
prsndtjjt2 < 0.0 ) && ( rtP . Constant_Value_mmbn22yeyo > muDoubleScalarFloor
( rtP . Constant_Value_mmbn22yeyo ) ) ) { j2olvplitn_idx_0 = -
muDoubleScalarPower ( - prsndtjjt2 , rtP . Constant_Value_mmbn22yeyo ) ; }
else { j2olvplitn_idx_0 = muDoubleScalarPower ( prsndtjjt2 , rtP .
Constant_Value_mmbn22yeyo ) ; } ky1lxji0nf = rtP .
AltitudeofTroposphere_Value - ( real32_T ) - rtB . exyupufjt5 [ 2 ] ; if (
ky1lxji0nf > rtP . LimitaltitudetoStratosphere_UpperSat ) { ky1lxji0nf = rtP
. LimitaltitudetoStratosphere_UpperSat ; } else if ( ky1lxji0nf < rtP .
LimitaltitudetoStratosphere_LowerSat ) { ky1lxji0nf = rtP .
LimitaltitudetoStratosphere_LowerSat ; } lir1dfa45c = muDoubleScalarExp ( 1.0
/ rtB . ieaokh1oup * ( rtP . gR_Gain * ky1lxji0nf ) ) ; rtB . odhuccln2g =
j2olvplitn_idx_0 / prsndtjjt2 * rtP . rho0_Gain * lir1dfa45c ; for (
aldazsptev = 0 ; aldazsptev < 12 ; aldazsptev ++ ) { if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { ky1lxji0nf = rtB . nn0j0nwtai [ aldazsptev + 6 ] ; if (
ky1lxji0nf > rtP . adqmzv0sx0 . Saturation2_UpperSat ) { rtB . adqmzv0sx0 [
aldazsptev ] . ibnqksi5kc = rtP . adqmzv0sx0 . Saturation2_UpperSat ; } else
if ( ky1lxji0nf < rtP . adqmzv0sx0 . Saturation2_LowerSat ) { rtB .
adqmzv0sx0 [ aldazsptev ] . ibnqksi5kc = rtP . adqmzv0sx0 .
Saturation2_LowerSat ; } else { rtB . adqmzv0sx0 [ aldazsptev ] . ibnqksi5kc
= ky1lxji0nf ; } rtB . adqmzv0sx0 [ aldazsptev ] . jagzqtugld = rtP .
adqmzv0sx0 . actf2T_Gain * rtB . adqmzv0sx0 [ aldazsptev ] . ibnqksi5kc ; }
if ( rtB . adqmzv0sx0 [ aldazsptev ] . ibnqksi5kc > rtP . adqmzv0sx0 .
Switch1_Threshold ) { e12efcqisd = look2_plinlcpw ( rtB . nupdx24lfb [
aldazsptev ] , rtB . adqmzv0sx0 [ aldazsptev ] . jagzqtugld , rtP . dp_DEP .
rpm_lookup . V_vec , rtP . dp_DEP . rpm_lookup . T_vec , rtP . dp_DEP .
rpm_lookup . rpm_gird , rtDW . adqmzv0sx0 [ aldazsptev ] . mczobgpj2t , rtP .
adqmzv0sx0 . T2rpm_maxIndex , 43U ) ; } else { e12efcqisd = rtP . adqmzv0sx0
. Constant3_Value ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . adqmzv0sx0
[ aldazsptev ] . dfpeduhr4c [ 0 ] = rtP . xyz_DEP [ 3 * aldazsptev ] - rtB .
adqmzv0sx0 [ aldazsptev ] . aox0khugvh [ 0 ] ; rtB . adqmzv0sx0 [ aldazsptev
] . dfpeduhr4c [ 1 ] = rtP . xyz_DEP [ 3 * aldazsptev + 1 ] - rtB .
adqmzv0sx0 [ aldazsptev ] . aox0khugvh [ 1 ] ; rtB . adqmzv0sx0 [ aldazsptev
] . dfpeduhr4c [ 2 ] = rtP . xyz_DEP [ 3 * aldazsptev + 2 ] - rtB .
adqmzv0sx0 [ aldazsptev ] . aox0khugvh [ 2 ] ; } prsndtjjt2 = rtP .
adqmzv0sx0 . Gain7_Gain * rtX . adqmzv0sx0 [ aldazsptev ] . jtqvm3jkcz ; if (
prsndtjjt2 > rtP . adqmzv0sx0 . Saturation_UpperSat ) { kkgsybg5mg = rtP .
adqmzv0sx0 . Saturation_UpperSat ; } else if ( prsndtjjt2 < rtP . adqmzv0sx0
. Saturation_LowerSat ) { kkgsybg5mg = rtP . adqmzv0sx0 . Saturation_LowerSat
; } else { kkgsybg5mg = prsndtjjt2 ; } do2fmqm0jw_idx_0 = rtB . nupdx24lfb [
aldazsptev ] / ( rtP . adqmzv0sx0 . Gain2_Gain * kkgsybg5mg + rtP .
adqmzv0sx0 . Constant_Value_hl5xkc3gs1 ) ; if ( do2fmqm0jw_idx_0 > rtP .
adqmzv0sx0 . Saturation1_UpperSat ) { do2fmqm0jw_idx_0 = rtP . adqmzv0sx0 .
Saturation1_UpperSat ; } else if ( do2fmqm0jw_idx_0 < rtP . adqmzv0sx0 .
Saturation1_LowerSat ) { do2fmqm0jw_idx_0 = rtP . adqmzv0sx0 .
Saturation1_LowerSat ; } ky1lxji0nf = look1_plinlcapw ( do2fmqm0jw_idx_0 ,
rtP . dp_DEP . J , rtP . dp_DEP . C_T , & rtDW . adqmzv0sx0 [ aldazsptev ] .
adrjjytrwd , 45U ) ; kkgsybg5mg *= kkgsybg5mg ; ky1lxji0nf = rtB . odhuccln2g
* ky1lxji0nf * kkgsybg5mg * rtP . adqmzv0sx0 . Gain3_Gain ; if ( ky1lxji0nf >
rtP . adqmzv0sx0 . Saturation_UpperSat_ollczcryiu ) { ky1lxji0nf = rtP .
adqmzv0sx0 . Saturation_UpperSat_ollczcryiu ; } else if ( ky1lxji0nf < rtP .
adqmzv0sx0 . Saturation_LowerSat_oypzpqvfzv ) { ky1lxji0nf = rtP . adqmzv0sx0
. Saturation_LowerSat_oypzpqvfzv ; } for ( i = 0 ; i < 3 ; i ++ ) {
cuwl4zp4yw [ i ] = ( rtB . adqmzv0sx0 [ aldazsptev ] . dbnx540oz1 [ i + 3 ] *
rtP . adqmzv0sx0 . Constant_Value + rtB . adqmzv0sx0 [ aldazsptev ] .
dbnx540oz1 [ i ] * ky1lxji0nf ) + rtB . adqmzv0sx0 [ aldazsptev ] .
dbnx540oz1 [ i + 6 ] * rtP . adqmzv0sx0 . Constant_Value ; } ky1lxji0nf =
look1_plinlcapw ( do2fmqm0jw_idx_0 , rtP . dp_DEP . J , rtP . dp_DEP . C_Q ,
& rtDW . adqmzv0sx0 [ aldazsptev ] . mirazmrnvl , 45U ) ; ky1lxji0nf = rtB .
odhuccln2g * ky1lxji0nf * kkgsybg5mg * rtP . adqmzv0sx0 . Gain_Gain ; if (
ky1lxji0nf > rtP . adqmzv0sx0 . Saturation1_UpperSat_e5noinhxx3 ) {
lk0wlvwohy [ 0 ] = rtP . adqmzv0sx0 . Saturation1_UpperSat_e5noinhxx3 ; }
else if ( ky1lxji0nf < rtP . adqmzv0sx0 . Saturation1_LowerSat_ghkwhqvuwp ) {
lk0wlvwohy [ 0 ] = rtP . adqmzv0sx0 . Saturation1_LowerSat_ghkwhqvuwp ; }
else { lk0wlvwohy [ 0 ] = ky1lxji0nf ; } for ( i = 0 ; i < 3 ; i ++ ) {
a5zxkwaluu [ i ] = ( rtB . adqmzv0sx0 [ aldazsptev ] . dbnx540oz1 [ i + 3 ] *
rtP . adqmzv0sx0 . Constant_Value + rtB . adqmzv0sx0 [ aldazsptev ] .
dbnx540oz1 [ i ] * lk0wlvwohy [ 0 ] ) + rtB . adqmzv0sx0 [ aldazsptev ] .
dbnx540oz1 [ i + 6 ] * rtP . adqmzv0sx0 . Constant_Value ; } kkgsybg5mg = rtP
. adqmzv0sx0 . Gain5_Gain * prsndtjjt2 ; lfy4nc2shm = e12efcqisd - kkgsybg5mg
; e12efcqisd = rtP . adqmzv0sx0 . EM_P * lfy4nc2shm + rtX . adqmzv0sx0 [
aldazsptev ] . dkxi20ccfc ; if ( e12efcqisd > rtP . adqmzv0sx0 .
EM_UpperSaturationLimit ) { da5ukodejx = e12efcqisd - rtP . adqmzv0sx0 .
EM_UpperSaturationLimit ; } else if ( e12efcqisd >= rtP . adqmzv0sx0 .
EM_LowerSaturationLimit ) { da5ukodejx = 0.0 ; } else { da5ukodejx =
e12efcqisd - rtP . adqmzv0sx0 . EM_LowerSaturationLimit ; } lfy4nc2shm *= rtP
. adqmzv0sx0 . EM_I ; tmp_m = muDoubleScalarSign ( da5ukodejx ) ; if (
muDoubleScalarIsNaN ( tmp_m ) ) { i = 0 ; } else { i = ( int32_T )
muDoubleScalarRem ( tmp_m , 256.0 ) ; } tmp_m = muDoubleScalarSign (
lfy4nc2shm ) ; if ( muDoubleScalarIsNaN ( tmp_m ) ) { jdx = 0 ; } else { jdx
= ( int32_T ) muDoubleScalarRem ( tmp_m , 256.0 ) ; } rtB . adqmzv0sx0 [
aldazsptev ] . cgxtlo5ezj = ( ( rtP . adqmzv0sx0 . ZeroGain_Gain * e12efcqisd
!= da5ukodejx ) && ( ( i < 0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T
) - ( real_T ) i : i ) == ( jdx < 0 ? ( int32_T ) ( int8_T ) - ( int8_T ) (
uint8_T ) - ( real_T ) jdx : jdx ) ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ rtB . adqmzv0sx0 [ aldazsptev ] . hqlowwzkov = rtDW . adqmzv0sx0 [
aldazsptev ] . kd3fwxo3ke ; } if ( rtB . adqmzv0sx0 [ aldazsptev ] .
hqlowwzkov ) { rtB . adqmzv0sx0 [ aldazsptev ] . ex2xojeend = rtP .
adqmzv0sx0 . Constant1_Value ; } else { rtB . adqmzv0sx0 [ aldazsptev ] .
ex2xojeend = lfy4nc2shm ; } if ( e12efcqisd > rtP . adqmzv0sx0 .
EM_UpperSaturationLimit ) { e12efcqisd = rtP . adqmzv0sx0 .
EM_UpperSaturationLimit ; } else if ( e12efcqisd < rtP . adqmzv0sx0 .
EM_LowerSaturationLimit ) { e12efcqisd = rtP . adqmzv0sx0 .
EM_LowerSaturationLimit ; } rtB . adqmzv0sx0 [ aldazsptev ] . n52zpi4j4s = (
e12efcqisd - ky1lxji0nf ) * rtP . adqmzv0sx0 . Multiply1_Gain ; rtB .
nhnvabjkuz [ aldazsptev ] = kkgsybg5mg ; gmj3cy4km1 [ aldazsptev ] = rtP .
adqmzv0sx0 . Gain3_Gain_cb0ak2utk4 * prsndtjjt2 * ky1lxji0nf ; tmp_m = rtP .
Constant2_Value_eyx5hzotxm [ aldazsptev ] ; if ( do2fmqm0jw_idx_0 > rtP .
adqmzv0sx0 . Saturation3_UpperSat ) { rtB . anhsgyheay [ aldazsptev ] = rtP .
adqmzv0sx0 . Saturation3_UpperSat ; } else if ( do2fmqm0jw_idx_0 < rtP .
adqmzv0sx0 . Saturation3_LowerSat ) { rtB . anhsgyheay [ aldazsptev ] = rtP .
adqmzv0sx0 . Saturation3_LowerSat ; } else { rtB . anhsgyheay [ aldazsptev ]
= do2fmqm0jw_idx_0 ; } gsnhdicnm0 [ 3 * aldazsptev ] = ( rtB . adqmzv0sx0 [
aldazsptev ] . dfpeduhr4c [ 1 ] * cuwl4zp4yw [ 2 ] - cuwl4zp4yw [ 1 ] * rtB .
adqmzv0sx0 [ aldazsptev ] . dfpeduhr4c [ 2 ] ) + tmp_m * a5zxkwaluu [ 0 ] ;
dsccgxajgj [ 3 * aldazsptev ] = cuwl4zp4yw [ 0 ] ; gsnhdicnm0 [ 3 *
aldazsptev + 1 ] = ( cuwl4zp4yw [ 0 ] * rtB . adqmzv0sx0 [ aldazsptev ] .
dfpeduhr4c [ 2 ] - rtB . adqmzv0sx0 [ aldazsptev ] . dfpeduhr4c [ 0 ] *
cuwl4zp4yw [ 2 ] ) + tmp_m * a5zxkwaluu [ 1 ] ; dsccgxajgj [ 3 * aldazsptev +
1 ] = cuwl4zp4yw [ 1 ] ; gsnhdicnm0 [ 3 * aldazsptev + 2 ] = ( rtB .
adqmzv0sx0 [ aldazsptev ] . dfpeduhr4c [ 0 ] * cuwl4zp4yw [ 1 ] - cuwl4zp4yw
[ 0 ] * rtB . adqmzv0sx0 [ aldazsptev ] . dfpeduhr4c [ 1 ] ) + tmp_m *
a5zxkwaluu [ 2 ] ; dsccgxajgj [ 3 * aldazsptev + 2 ] = cuwl4zp4yw [ 2 ] ; }
for ( i = 0 ; i < 12 ; i ++ ) { c0f5gkmurs [ i ] = ( real32_T ) rtB .
anhsgyheay [ i ] ; } d1u044ebak [ 0 ] = c0f5gkmurs [ 5 ] ; d1u044ebak [ 1 ] =
c0f5gkmurs [ 4 ] ; d1u044ebak [ 2 ] = c0f5gkmurs [ 3 ] ; d1u044ebak [ 3 ] =
c0f5gkmurs [ 2 ] ; d1u044ebak [ 4 ] = c0f5gkmurs [ 1 ] ; for ( jdx = 0 ; jdx
< 5 ; jdx ++ ) { ii415rcvoz [ jdx ] = plook_u32ff_lincpa ( d1u044ebak [ jdx ]
, rtP . dp_WING_root . DEP_J , 6U , & kybpw4f1la [ jdx ] , & rtDW .
lybiwzq15a [ jdx ] ) ; } frac [ 0 ] = rtB . buybsypzuh ; bpIndex [ 0 ] = rtB
. pgacreyak0 ; for ( jdx = 0 ; jdx < 5 ; jdx ++ ) { frac [ 1 ] = gsmuzimw5z [
jdx ] ; frac [ 2 ] = l2m0tr3gxj [ jdx ] ; frac [ 3 ] = kybpw4f1la [ jdx ] ;
bpIndex [ 1 ] = b45rg52mcj [ jdx ] ; bpIndex [ 2 ] = mlqqrra0eq [ jdx ] ;
bpIndex [ 3 ] = ii415rcvoz [ jdx ] ; prsndtjjt2 = rtP .
Constant8_Value_fdguqum2g1 [ jdx ] ; if ( prsndtjjt2 > 4.0 ) { bpIndex [ 4 ]
= 4U ; } else if ( prsndtjjt2 >= 0.0 ) { bpIndex [ 4 ] = ( uint32_T )
prsndtjjt2 ; } else { bpIndex [ 4 ] = 0U ; } mpg33qrdtp [ jdx ] =
intrp4d_fu32fla_pw ( bpIndex , frac , & rtP . dp_WING_root . CD [ 1750U *
bpIndex [ 4 ] ] , rtP . InterpolationUsingPrelookup1_dimSize , rtP .
InterpolationUsingPrelookup1_maxIndex ) ; } if ( ssIsSampleHit ( rtS , 2 , 0
) ) { rtB . lcfixu2lfk = plook_u32ff_lincpa ( khgvdadyv1 [ 0 ] , rtP .
dp_WING_tip . ail_defl , 6U , & rtB . kdl2q2ktlu , & rtDW . hhpqcwloh0 ) ; }
o3v0lawphs_idx_0 = plook_u32ff_lincpa ( rtB . cfz24gonbx [ 1 ] , rtP .
dp_WING_tip . alphas , 24U , & m1ahso5u4m [ 0 ] , & rtDW . hxdxaozqh1 [ 0 ] )
; o3v0lawphs_idx_1 = plook_u32ff_lincpa ( rtB . cfz24gonbx [ 0 ] , rtP .
dp_WING_tip . alphas , 24U , & m1ahso5u4m [ 1 ] , & rtDW . hxdxaozqh1 [ 1 ] )
; oejjwkdimx_idx_0 = plook_u32ff_lincpa ( rtB . nmxk2xrfk3 [ 1 ] , rtP .
dp_WING_tip . V , 1U , & d3scbkbwlb [ 0 ] , & rtDW . fknte5kkos [ 0 ] ) ;
oejjwkdimx_idx_1 = plook_u32ff_lincpa ( rtB . nmxk2xrfk3 [ 0 ] , rtP .
dp_WING_tip . V , 1U , & d3scbkbwlb [ 1 ] , & rtDW . fknte5kkos [ 1 ] ) ;
jzjq4t0ecb_idx_0 = plook_u32ff_lincpa ( c0f5gkmurs [ 1 ] , rtP . dp_WING_tip
. DEP_J , 6U , & njurhkovsz [ 0 ] , & rtDW . mnfw2imvdw [ 0 ] ) ;
jzjq4t0ecb_idx_1 = plook_u32ff_lincpa ( c0f5gkmurs [ 0 ] , rtP . dp_WING_tip
. DEP_J , 6U , & njurhkovsz [ 1 ] , & rtDW . mnfw2imvdw [ 1 ] ) ; frac_p [ 0
] = rtB . kdl2q2ktlu ; bpIndex_p [ 0 ] = rtB . lcfixu2lfk ; frac_p [ 1 ] =
m1ahso5u4m [ 0 ] ; frac_p [ 2 ] = d3scbkbwlb [ 0 ] ; frac_p [ 3 ] =
njurhkovsz [ 0 ] ; bpIndex_p [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_p [ 2 ] =
oejjwkdimx_idx_0 ; bpIndex_p [ 3 ] = jzjq4t0ecb_idx_0 ; if ( rtP .
Constant8_Value_dn0swibioj [ 0 ] > 1.0 ) { bpIndex_p [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 0 ] >= 0.0 ) { bpIndex_p [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 0 ] ; } else { bpIndex_p [ 4 ]
= 0U ; } mpg33qrdtp [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_p , frac_p , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_p [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_gfiklomvd1 , rtP .
InterpolationUsingPrelookup1_maxIndex_kpkpckmswm ) ; frac_p [ 1 ] =
m1ahso5u4m [ 1 ] ; frac_p [ 2 ] = d3scbkbwlb [ 1 ] ; frac_p [ 3 ] =
njurhkovsz [ 1 ] ; bpIndex_p [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_p [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_p [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_dn0swibioj [ 1 ] > 1.0 ) { bpIndex_p [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 1 ] >= 0.0 ) { bpIndex_p [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 1 ] ; } else { bpIndex_p [ 4 ]
= 0U ; } mpg33qrdtp [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_p , frac_p , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_p [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_gfiklomvd1 , rtP .
InterpolationUsingPrelookup1_maxIndex_kpkpckmswm ) ; frac_e [ 0 ] = rtB .
buybsypzuh ; bpIndex_e [ 0 ] = rtB . pgacreyak0 ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_e [ 1 ] = gsmuzimw5z [ jdx ] ; frac_e [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_e [ 3 ] = kybpw4f1la [ jdx ] ; bpIndex_e [ 1 ] = b45rg52mcj [
jdx ] ; bpIndex_e [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_e [ 3 ] = ii415rcvoz [
jdx ] ; prsndtjjt2 = rtP . Constant8_Value_fdguqum2g1 [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_e [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) {
bpIndex_e [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_e [ 4 ] = 0U ; }
mpg33qrdtp [ jdx + 7 ] = intrp4d_fu32fla_pw ( bpIndex_e , frac_e , & rtP .
dp_WING_root . CS [ 1750U * bpIndex_e [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize , rtP .
InterpolationUsingPrelookup2_maxIndex ) ; } frac_i [ 0 ] = rtB . kdl2q2ktlu ;
bpIndex_i [ 0 ] = rtB . lcfixu2lfk ; frac_i [ 1 ] = m1ahso5u4m [ 0 ] ; frac_i
[ 2 ] = d3scbkbwlb [ 0 ] ; frac_i [ 3 ] = njurhkovsz [ 0 ] ; bpIndex_i [ 1 ]
= o3v0lawphs_idx_0 ; bpIndex_i [ 2 ] = oejjwkdimx_idx_0 ; bpIndex_i [ 3 ] =
jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_dn0swibioj [ 0 ] > 1.0 ) {
bpIndex_i [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_dn0swibioj [ 0 ] >=
0.0 ) { bpIndex_i [ 4 ] = ( uint32_T ) rtP . Constant8_Value_dn0swibioj [ 0 ]
; } else { bpIndex_i [ 4 ] = 0U ; } mpg33qrdtp [ 12 ] = intrp4d_fu32fla_pw (
bpIndex_i , frac_i , & rtP . dp_WING_tip . CS [ 2450U * bpIndex_i [ 4 ] ] ,
rtP . InterpolationUsingPrelookup2_dimSize_nrl20k3nz5 , rtP .
InterpolationUsingPrelookup2_maxIndex_halnsma1cb ) ; frac_i [ 1 ] =
m1ahso5u4m [ 1 ] ; frac_i [ 2 ] = d3scbkbwlb [ 1 ] ; frac_i [ 3 ] =
njurhkovsz [ 1 ] ; bpIndex_i [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_i [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_i [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_dn0swibioj [ 1 ] > 1.0 ) { bpIndex_i [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 1 ] >= 0.0 ) { bpIndex_i [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 1 ] ; } else { bpIndex_i [ 4 ]
= 0U ; } mpg33qrdtp [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_i , frac_i , & rtP
. dp_WING_tip . CS [ 2450U * bpIndex_i [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_nrl20k3nz5 , rtP .
InterpolationUsingPrelookup2_maxIndex_halnsma1cb ) ; frac_m [ 0 ] = rtB .
buybsypzuh ; bpIndex_m [ 0 ] = rtB . pgacreyak0 ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_m [ 1 ] = gsmuzimw5z [ jdx ] ; frac_m [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_m [ 3 ] = kybpw4f1la [ jdx ] ; bpIndex_m [ 1 ] = b45rg52mcj [
jdx ] ; bpIndex_m [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_m [ 3 ] = ii415rcvoz [
jdx ] ; prsndtjjt2 = rtP . Constant8_Value_fdguqum2g1 [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_m [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) {
bpIndex_m [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_m [ 4 ] = 0U ; }
mpg33qrdtp [ jdx + 14 ] = intrp4d_fu32fla_pw ( bpIndex_m , frac_m , & rtP .
dp_WING_root . CL [ 1750U * bpIndex_m [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize , rtP .
InterpolationUsingPrelookup3_maxIndex ) ; } frac_g [ 0 ] = rtB . kdl2q2ktlu ;
bpIndex_g [ 0 ] = rtB . lcfixu2lfk ; frac_g [ 1 ] = m1ahso5u4m [ 0 ] ; frac_g
[ 2 ] = d3scbkbwlb [ 0 ] ; frac_g [ 3 ] = njurhkovsz [ 0 ] ; bpIndex_g [ 1 ]
= o3v0lawphs_idx_0 ; bpIndex_g [ 2 ] = oejjwkdimx_idx_0 ; bpIndex_g [ 3 ] =
jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_dn0swibioj [ 0 ] > 1.0 ) {
bpIndex_g [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_dn0swibioj [ 0 ] >=
0.0 ) { bpIndex_g [ 4 ] = ( uint32_T ) rtP . Constant8_Value_dn0swibioj [ 0 ]
; } else { bpIndex_g [ 4 ] = 0U ; } mpg33qrdtp [ 19 ] = intrp4d_fu32fla_pw (
bpIndex_g , frac_g , & rtP . dp_WING_tip . CL [ 2450U * bpIndex_g [ 4 ] ] ,
rtP . InterpolationUsingPrelookup3_dimSize_bwdov31odu , rtP .
InterpolationUsingPrelookup3_maxIndex_dnuuotdmkt ) ; frac_g [ 1 ] =
m1ahso5u4m [ 1 ] ; frac_g [ 2 ] = d3scbkbwlb [ 1 ] ; frac_g [ 3 ] =
njurhkovsz [ 1 ] ; bpIndex_g [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_g [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_g [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_dn0swibioj [ 1 ] > 1.0 ) { bpIndex_g [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 1 ] >= 0.0 ) { bpIndex_g [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 1 ] ; } else { bpIndex_g [ 4 ]
= 0U ; } mpg33qrdtp [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_g , frac_g , & rtP
. dp_WING_tip . CL [ 2450U * bpIndex_g [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_bwdov31odu , rtP .
InterpolationUsingPrelookup3_maxIndex_dnuuotdmkt ) ; for ( i = 0 ; i < 7 ; i
++ ) { rtB . bflkh3tw3c [ 3 * i ] = ck1tgxwfew [ 3 * i ] * mpg33qrdtp [ i ] *
( real32_T ) rtB . odhuccln2g * rtP . Gain_Gain_igdiaogfc0 ; rtB . bflkh3tw3c
[ 3 * i + 1 ] = ck1tgxwfew [ 3 * i + 1 ] * mpg33qrdtp [ i + 7 ] * ( real32_T
) rtB . odhuccln2g * rtP . Gain_Gain_igdiaogfc0 ; rtB . bflkh3tw3c [ 3 * i +
2 ] = ck1tgxwfew [ 3 * i + 2 ] * mpg33qrdtp [ i + 14 ] * ( real32_T ) rtB .
odhuccln2g * rtP . Gain_Gain_igdiaogfc0 ; } parallel_for ( 7 , nonjggp2zg , 1
, "nonjggp2zg" ) ; parallel_for ( 7 , ozenep403f , 1 , "ozenep403f" ) ;
frac_j [ 0 ] = rtB . buybsypzuh ; bpIndex_j [ 0 ] = rtB . pgacreyak0 ; for (
jdx = 0 ; jdx < 5 ; jdx ++ ) { frac_j [ 1 ] = gsmuzimw5z [ jdx ] ; frac_j [ 2
] = l2m0tr3gxj [ jdx ] ; frac_j [ 3 ] = kybpw4f1la [ jdx ] ; bpIndex_j [ 1 ]
= b45rg52mcj [ jdx ] ; bpIndex_j [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_j [ 3 ]
= ii415rcvoz [ jdx ] ; prsndtjjt2 = rtP . Constant8_Value_fdguqum2g1 [ jdx ]
; if ( prsndtjjt2 > 4.0 ) { bpIndex_j [ 4 ] = 4U ; } else if ( prsndtjjt2 >=
0.0 ) { bpIndex_j [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_j [ 4 ]
= 0U ; } mpg33qrdtp [ jdx ] = intrp4d_fu32fla_pw ( bpIndex_j , frac_j , & rtP
. dp_WING_root . CMx [ 1750U * bpIndex_j [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize , rtP .
InterpolationUsingPrelookup4_maxIndex ) ; } frac_f [ 0 ] = rtB . kdl2q2ktlu ;
bpIndex_f [ 0 ] = rtB . lcfixu2lfk ; frac_f [ 1 ] = m1ahso5u4m [ 0 ] ; frac_f
[ 2 ] = d3scbkbwlb [ 0 ] ; frac_f [ 3 ] = njurhkovsz [ 0 ] ; bpIndex_f [ 1 ]
= o3v0lawphs_idx_0 ; bpIndex_f [ 2 ] = oejjwkdimx_idx_0 ; bpIndex_f [ 3 ] =
jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_dn0swibioj [ 0 ] > 1.0 ) {
bpIndex_f [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_dn0swibioj [ 0 ] >=
0.0 ) { bpIndex_f [ 4 ] = ( uint32_T ) rtP . Constant8_Value_dn0swibioj [ 0 ]
; } else { bpIndex_f [ 4 ] = 0U ; } mpg33qrdtp [ 5 ] = intrp4d_fu32fla_pw (
bpIndex_f , frac_f , & rtP . dp_WING_tip . CMx [ 2450U * bpIndex_f [ 4 ] ] ,
rtP . InterpolationUsingPrelookup4_dimSize_lcwylc1smw , rtP .
InterpolationUsingPrelookup4_maxIndex_cy2xlkh5vq ) ; frac_f [ 1 ] =
m1ahso5u4m [ 1 ] ; frac_f [ 2 ] = d3scbkbwlb [ 1 ] ; frac_f [ 3 ] =
njurhkovsz [ 1 ] ; bpIndex_f [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_f [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_f [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_dn0swibioj [ 1 ] > 1.0 ) { bpIndex_f [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 1 ] >= 0.0 ) { bpIndex_f [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 1 ] ; } else { bpIndex_f [ 4 ]
= 0U ; } mpg33qrdtp [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_f , frac_f , & rtP .
dp_WING_tip . CMx [ 2450U * bpIndex_f [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_lcwylc1smw , rtP .
InterpolationUsingPrelookup4_maxIndex_cy2xlkh5vq ) ; frac_c [ 0 ] = rtB .
buybsypzuh ; bpIndex_c [ 0 ] = rtB . pgacreyak0 ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_c [ 1 ] = gsmuzimw5z [ jdx ] ; frac_c [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_c [ 3 ] = kybpw4f1la [ jdx ] ; bpIndex_c [ 1 ] = b45rg52mcj [
jdx ] ; bpIndex_c [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_c [ 3 ] = ii415rcvoz [
jdx ] ; prsndtjjt2 = rtP . Constant8_Value_fdguqum2g1 [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_c [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) {
bpIndex_c [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_c [ 4 ] = 0U ; }
mpg33qrdtp [ jdx + 7 ] = intrp4d_fu32fla_pw ( bpIndex_c , frac_c , & rtP .
dp_WING_root . CMy [ 1750U * bpIndex_c [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize , rtP .
InterpolationUsingPrelookup5_maxIndex ) ; } frac_k [ 0 ] = rtB . kdl2q2ktlu ;
bpIndex_k [ 0 ] = rtB . lcfixu2lfk ; frac_k [ 1 ] = m1ahso5u4m [ 0 ] ; frac_k
[ 2 ] = d3scbkbwlb [ 0 ] ; frac_k [ 3 ] = njurhkovsz [ 0 ] ; bpIndex_k [ 1 ]
= o3v0lawphs_idx_0 ; bpIndex_k [ 2 ] = oejjwkdimx_idx_0 ; bpIndex_k [ 3 ] =
jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_dn0swibioj [ 0 ] > 1.0 ) {
bpIndex_k [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_dn0swibioj [ 0 ] >=
0.0 ) { bpIndex_k [ 4 ] = ( uint32_T ) rtP . Constant8_Value_dn0swibioj [ 0 ]
; } else { bpIndex_k [ 4 ] = 0U ; } mpg33qrdtp [ 12 ] = intrp4d_fu32fla_pw (
bpIndex_k , frac_k , & rtP . dp_WING_tip . CMy [ 2450U * bpIndex_k [ 4 ] ] ,
rtP . InterpolationUsingPrelookup5_dimSize_c5irdqqd1s , rtP .
InterpolationUsingPrelookup5_maxIndex_d44fsejhpt ) ; frac_k [ 1 ] =
m1ahso5u4m [ 1 ] ; frac_k [ 2 ] = d3scbkbwlb [ 1 ] ; frac_k [ 3 ] =
njurhkovsz [ 1 ] ; bpIndex_k [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_k [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_k [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_dn0swibioj [ 1 ] > 1.0 ) { bpIndex_k [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 1 ] >= 0.0 ) { bpIndex_k [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 1 ] ; } else { bpIndex_k [ 4 ]
= 0U ; } mpg33qrdtp [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_k , frac_k , & rtP
. dp_WING_tip . CMy [ 2450U * bpIndex_k [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_c5irdqqd1s , rtP .
InterpolationUsingPrelookup5_maxIndex_d44fsejhpt ) ; frac_b [ 0 ] = rtB .
buybsypzuh ; bpIndex_b [ 0 ] = rtB . pgacreyak0 ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_b [ 1 ] = gsmuzimw5z [ jdx ] ; frac_b [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_b [ 3 ] = kybpw4f1la [ jdx ] ; bpIndex_b [ 1 ] = b45rg52mcj [
jdx ] ; bpIndex_b [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_b [ 3 ] = ii415rcvoz [
jdx ] ; prsndtjjt2 = rtP . Constant8_Value_fdguqum2g1 [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_b [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) {
bpIndex_b [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_b [ 4 ] = 0U ; }
mpg33qrdtp [ jdx + 14 ] = intrp4d_fu32fla_pw ( bpIndex_b , frac_b , & rtP .
dp_WING_root . CMz [ 1750U * bpIndex_b [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize , rtP .
InterpolationUsingPrelookup6_maxIndex ) ; } frac_n [ 0 ] = rtB . kdl2q2ktlu ;
bpIndex_n [ 0 ] = rtB . lcfixu2lfk ; frac_n [ 1 ] = m1ahso5u4m [ 0 ] ; frac_n
[ 2 ] = d3scbkbwlb [ 0 ] ; frac_n [ 3 ] = njurhkovsz [ 0 ] ; bpIndex_n [ 1 ]
= o3v0lawphs_idx_0 ; bpIndex_n [ 2 ] = oejjwkdimx_idx_0 ; bpIndex_n [ 3 ] =
jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_dn0swibioj [ 0 ] > 1.0 ) {
bpIndex_n [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_dn0swibioj [ 0 ] >=
0.0 ) { bpIndex_n [ 4 ] = ( uint32_T ) rtP . Constant8_Value_dn0swibioj [ 0 ]
; } else { bpIndex_n [ 4 ] = 0U ; } mpg33qrdtp [ 19 ] = intrp4d_fu32fla_pw (
bpIndex_n , frac_n , & rtP . dp_WING_tip . CMz [ 2450U * bpIndex_n [ 4 ] ] ,
rtP . InterpolationUsingPrelookup6_dimSize_iia0rqhr03 , rtP .
InterpolationUsingPrelookup6_maxIndex_f1aiexynmu ) ; frac_n [ 1 ] =
m1ahso5u4m [ 1 ] ; frac_n [ 2 ] = d3scbkbwlb [ 1 ] ; frac_n [ 3 ] =
njurhkovsz [ 1 ] ; bpIndex_n [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_n [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_n [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_dn0swibioj [ 1 ] > 1.0 ) { bpIndex_n [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_dn0swibioj [ 1 ] >= 0.0 ) { bpIndex_n [ 4 ] = (
uint32_T ) rtP . Constant8_Value_dn0swibioj [ 1 ] ; } else { bpIndex_n [ 4 ]
= 0U ; } mpg33qrdtp [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_n , frac_n , & rtP
. dp_WING_tip . CMz [ 2450U * bpIndex_n [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_iia0rqhr03 , rtP .
InterpolationUsingPrelookup6_maxIndex_f1aiexynmu ) ; e12efcqisd = rtP . S /
2.0 ; for ( i = 0 ; i < 7 ; i ++ ) { hg2rsg5czq [ 3 * i ] = ck1tgxwfew [ 3 *
i ] * mpg33qrdtp [ i ] * rtP . Constant_Value_b3o3asdnd0 [ 3 * i ] * (
real32_T ) rtB . odhuccln2g * e12efcqisd + rtB . byhpdluumbu [ 3 * i ] ;
hg2rsg5czq [ 3 * i + 1 ] = ck1tgxwfew [ 3 * i + 1 ] * mpg33qrdtp [ i + 7 ] *
rtP . Constant_Value_b3o3asdnd0 [ 3 * i + 1 ] * ( real32_T ) rtB . odhuccln2g
* e12efcqisd + rtB . byhpdluumbu [ 3 * i + 1 ] ; hg2rsg5czq [ 3 * i + 2 ] =
ck1tgxwfew [ 3 * i + 2 ] * mpg33qrdtp [ i + 14 ] * rtP .
Constant_Value_b3o3asdnd0 [ 3 * i + 2 ] * ( real32_T ) rtB . odhuccln2g *
e12efcqisd + rtB . byhpdluumbu [ 3 * i + 2 ] ; } for ( jdx = 0 ; jdx < 3 ;
jdx ++ ) { e12efcqisd = - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { e12efcqisd +=
hg2rsg5czq [ i * 3 + jdx ] ; } cuwl4zp4yw [ jdx ] = e12efcqisd ; }
a4viish00u_idx_0 = ( real32_T ) cuwl4zp4yw [ 0 ] ; a4viish00u_idx_1 = (
real32_T ) cuwl4zp4yw [ 1 ] ; a4viish00u_idx_2 = ( real32_T ) cuwl4zp4yw [ 2
] ; for ( i = 0 ; i < 7 ; i ++ ) { mmxlym3ls1_idx_0 = rtB . nmxk2xrfk3 [ i +
7 ] ; ck1tgxwfew [ 3 * i ] = mmxlym3ls1_idx_0 ; ck1tgxwfew [ 3 * i + 1 ] =
mmxlym3ls1_idx_0 ; ck1tgxwfew [ 3 * i + 2 ] = mmxlym3ls1_idx_0 ; } for ( i =
0 ; i < 21 ; i ++ ) { mmxlym3ls1_idx_0 = ck1tgxwfew [ i ] ; ck1tgxwfew [ i ]
= mmxlym3ls1_idx_0 * mmxlym3ls1_idx_0 ; } if ( ssIsSampleHit ( rtS , 2 , 0 )
) { rtB . mb1y0b3eym = plook_u32ff_lincpa ( khgvdadyv1 [ 5 ] , rtP .
dp_WING_root . flap_defl , 4U , & rtB . be1wst1pkg , & rtDW . felqedgyx1 ) ;
} for ( jdx = 0 ; jdx < 5 ; jdx ++ ) { ii415rcvoz [ jdx ] =
plook_u32ff_lincpa ( rtB . cfz24gonbx [ jdx + 7 ] , rtP . dp_WING_root .
alphas , 24U , & kybpw4f1la [ jdx ] , & rtDW . knvjdfedfb [ jdx ] ) ; } for (
jdx = 0 ; jdx < 5 ; jdx ++ ) { mlqqrra0eq [ jdx ] = plook_u32ff_lincpa ( rtB
. nmxk2xrfk3 [ jdx + 7 ] , rtP . dp_WING_root . V , 1U , & l2m0tr3gxj [ jdx ]
, & rtDW . apjnubwssp [ jdx ] ) ; } for ( jdx = 0 ; jdx < 5 ; jdx ++ ) {
b45rg52mcj [ jdx ] = plook_u32ff_lincpa ( c0f5gkmurs [ jdx + 6 ] , rtP .
dp_WING_root . DEP_J , 6U , & gsmuzimw5z [ jdx ] , & rtDW . ptu3l2ehpk [ jdx
] ) ; } frac_l [ 0 ] = rtB . be1wst1pkg ; bpIndex_l [ 0 ] = rtB . mb1y0b3eym
; for ( jdx = 0 ; jdx < 5 ; jdx ++ ) { frac_l [ 1 ] = kybpw4f1la [ jdx ] ;
frac_l [ 2 ] = l2m0tr3gxj [ jdx ] ; frac_l [ 3 ] = gsmuzimw5z [ jdx ] ;
bpIndex_l [ 1 ] = ii415rcvoz [ jdx ] ; bpIndex_l [ 2 ] = mlqqrra0eq [ jdx ] ;
bpIndex_l [ 3 ] = b45rg52mcj [ jdx ] ; prsndtjjt2 = rtP .
Constant8_Value_o2vddtqbhz [ jdx ] ; if ( prsndtjjt2 > 4.0 ) { bpIndex_l [ 4
] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) { bpIndex_l [ 4 ] = ( uint32_T )
prsndtjjt2 ; } else { bpIndex_l [ 4 ] = 0U ; } mpg33qrdtp [ jdx ] =
intrp4d_fu32fla_pw ( bpIndex_l , frac_l , & rtP . dp_WING_root . CD [ 1750U *
bpIndex_l [ 4 ] ] , rtP . InterpolationUsingPrelookup1_dimSize_cc1prjb2oo ,
rtP . InterpolationUsingPrelookup1_maxIndex_n2qqbs4dob ) ; } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . lj1ecmy3sj = plook_u32ff_lincpa (
khgvdadyv1 [ 1 ] , rtP . dp_WING_tip . ail_defl , 6U , & rtB . gefiy4un3d , &
rtDW . ebmg2d0djd ) ; } o3v0lawphs_idx_0 = plook_u32ff_lincpa ( rtB .
cfz24gonbx [ 12 ] , rtP . dp_WING_tip . alphas , 24U , & gsguxbdffk [ 0 ] , &
rtDW . nmrn1j5ohh [ 0 ] ) ; o3v0lawphs_idx_1 = plook_u32ff_lincpa ( rtB .
cfz24gonbx [ 13 ] , rtP . dp_WING_tip . alphas , 24U , & gsguxbdffk [ 1 ] , &
rtDW . nmrn1j5ohh [ 1 ] ) ; oejjwkdimx_idx_0 = plook_u32ff_lincpa ( rtB .
nmxk2xrfk3 [ 12 ] , rtP . dp_WING_tip . V , 1U , & ovjd1la42y [ 0 ] , & rtDW
. hl5ux0u3e5 [ 0 ] ) ; oejjwkdimx_idx_1 = plook_u32ff_lincpa ( rtB .
nmxk2xrfk3 [ 13 ] , rtP . dp_WING_tip . V , 1U , & ovjd1la42y [ 1 ] , & rtDW
. hl5ux0u3e5 [ 1 ] ) ; jzjq4t0ecb_idx_0 = plook_u32ff_lincpa ( c0f5gkmurs [
10 ] , rtP . dp_WING_tip . DEP_J , 6U , & pyfokpvamr [ 0 ] , & rtDW .
kywikzuq0z [ 0 ] ) ; jzjq4t0ecb_idx_1 = plook_u32ff_lincpa ( c0f5gkmurs [ 11
] , rtP . dp_WING_tip . DEP_J , 6U , & pyfokpvamr [ 1 ] , & rtDW . kywikzuq0z
[ 1 ] ) ; frac_d [ 0 ] = rtB . gefiy4un3d ; bpIndex_d [ 0 ] = rtB .
lj1ecmy3sj ; frac_d [ 1 ] = gsguxbdffk [ 0 ] ; frac_d [ 2 ] = ovjd1la42y [ 0
] ; frac_d [ 3 ] = pyfokpvamr [ 0 ] ; bpIndex_d [ 1 ] = o3v0lawphs_idx_0 ;
bpIndex_d [ 2 ] = oejjwkdimx_idx_0 ; bpIndex_d [ 3 ] = jzjq4t0ecb_idx_0 ; if
( rtP . Constant8_Value_oaybf0pjve [ 0 ] > 1.0 ) { bpIndex_d [ 4 ] = 1U ; }
else if ( rtP . Constant8_Value_oaybf0pjve [ 0 ] >= 0.0 ) { bpIndex_d [ 4 ] =
( uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 0 ] ; } else { bpIndex_d [ 4
] = 0U ; } mpg33qrdtp [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_d , frac_d , & rtP
. dp_WING_tip . CD [ 2450U * bpIndex_d [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_kx41jhq53z , rtP .
InterpolationUsingPrelookup1_maxIndex_dvymep4nij ) ; frac_d [ 1 ] =
gsguxbdffk [ 1 ] ; frac_d [ 2 ] = ovjd1la42y [ 1 ] ; frac_d [ 3 ] =
pyfokpvamr [ 1 ] ; bpIndex_d [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_d [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_d [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_oaybf0pjve [ 1 ] > 1.0 ) { bpIndex_d [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_oaybf0pjve [ 1 ] >= 0.0 ) { bpIndex_d [ 4 ] = (
uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 1 ] ; } else { bpIndex_d [ 4 ]
= 0U ; } mpg33qrdtp [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_d , frac_d , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_d [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_kx41jhq53z , rtP .
InterpolationUsingPrelookup1_maxIndex_dvymep4nij ) ; frac_o [ 0 ] = rtB .
be1wst1pkg ; bpIndex_o [ 0 ] = rtB . mb1y0b3eym ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_o [ 1 ] = kybpw4f1la [ jdx ] ; frac_o [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_o [ 3 ] = gsmuzimw5z [ jdx ] ; bpIndex_o [ 1 ] = ii415rcvoz [
jdx ] ; bpIndex_o [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_o [ 3 ] = b45rg52mcj [
jdx ] ; prsndtjjt2 = rtP . Constant8_Value_o2vddtqbhz [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_o [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) {
bpIndex_o [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_o [ 4 ] = 0U ; }
mpg33qrdtp [ jdx + 7 ] = intrp4d_fu32fla_pw ( bpIndex_o , frac_o , & rtP .
dp_WING_root . CS [ 1750U * bpIndex_o [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_j2ofnaf0w0 , rtP .
InterpolationUsingPrelookup2_maxIndex_fiuiapwlsq ) ; } frac_dz [ 0 ] = rtB .
gefiy4un3d ; bpIndex_dz [ 0 ] = rtB . lj1ecmy3sj ; frac_dz [ 1 ] = gsguxbdffk
[ 0 ] ; frac_dz [ 2 ] = ovjd1la42y [ 0 ] ; frac_dz [ 3 ] = pyfokpvamr [ 0 ] ;
bpIndex_dz [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_dz [ 2 ] = oejjwkdimx_idx_0 ;
bpIndex_dz [ 3 ] = jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_oaybf0pjve [
0 ] > 1.0 ) { bpIndex_dz [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_oaybf0pjve [ 0 ] >= 0.0 ) { bpIndex_dz [ 4 ] = ( uint32_T )
rtP . Constant8_Value_oaybf0pjve [ 0 ] ; } else { bpIndex_dz [ 4 ] = 0U ; }
mpg33qrdtp [ 12 ] = intrp4d_fu32fla_pw ( bpIndex_dz , frac_dz , & rtP .
dp_WING_tip . CS [ 2450U * bpIndex_dz [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_duz043yjyq , rtP .
InterpolationUsingPrelookup2_maxIndex_bi1sjla3q2 ) ; frac_dz [ 1 ] =
gsguxbdffk [ 1 ] ; frac_dz [ 2 ] = ovjd1la42y [ 1 ] ; frac_dz [ 3 ] =
pyfokpvamr [ 1 ] ; bpIndex_dz [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_dz [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_dz [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_oaybf0pjve [ 1 ] > 1.0 ) { bpIndex_dz [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_oaybf0pjve [ 1 ] >= 0.0 ) { bpIndex_dz [ 4 ] = (
uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 1 ] ; } else { bpIndex_dz [ 4 ]
= 0U ; } mpg33qrdtp [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_dz , frac_dz , &
rtP . dp_WING_tip . CS [ 2450U * bpIndex_dz [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_duz043yjyq , rtP .
InterpolationUsingPrelookup2_maxIndex_bi1sjla3q2 ) ; frac_fs [ 0 ] = rtB .
be1wst1pkg ; bpIndex_fs [ 0 ] = rtB . mb1y0b3eym ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_fs [ 1 ] = kybpw4f1la [ jdx ] ; frac_fs [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_fs [ 3 ] = gsmuzimw5z [ jdx ] ; bpIndex_fs [ 1 ] = ii415rcvoz [
jdx ] ; bpIndex_fs [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_fs [ 3 ] = b45rg52mcj
[ jdx ] ; prsndtjjt2 = rtP . Constant8_Value_o2vddtqbhz [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_fs [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 )
{ bpIndex_fs [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_fs [ 4 ] = 0U
; } mpg33qrdtp [ jdx + 14 ] = intrp4d_fu32fla_pw ( bpIndex_fs , frac_fs , &
rtP . dp_WING_root . CL [ 1750U * bpIndex_fs [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_n5hof3ggty , rtP .
InterpolationUsingPrelookup3_maxIndex_frabtm3htz ) ; } frac_ck [ 0 ] = rtB .
gefiy4un3d ; bpIndex_ck [ 0 ] = rtB . lj1ecmy3sj ; frac_ck [ 1 ] = gsguxbdffk
[ 0 ] ; frac_ck [ 2 ] = ovjd1la42y [ 0 ] ; frac_ck [ 3 ] = pyfokpvamr [ 0 ] ;
bpIndex_ck [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_ck [ 2 ] = oejjwkdimx_idx_0 ;
bpIndex_ck [ 3 ] = jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_oaybf0pjve [
0 ] > 1.0 ) { bpIndex_ck [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_oaybf0pjve [ 0 ] >= 0.0 ) { bpIndex_ck [ 4 ] = ( uint32_T )
rtP . Constant8_Value_oaybf0pjve [ 0 ] ; } else { bpIndex_ck [ 4 ] = 0U ; }
mpg33qrdtp [ 19 ] = intrp4d_fu32fla_pw ( bpIndex_ck , frac_ck , & rtP .
dp_WING_tip . CL [ 2450U * bpIndex_ck [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_dkrtirzueo , rtP .
InterpolationUsingPrelookup3_maxIndex_imdp4seazn ) ; frac_ck [ 1 ] =
gsguxbdffk [ 1 ] ; frac_ck [ 2 ] = ovjd1la42y [ 1 ] ; frac_ck [ 3 ] =
pyfokpvamr [ 1 ] ; bpIndex_ck [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_ck [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_ck [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_oaybf0pjve [ 1 ] > 1.0 ) { bpIndex_ck [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_oaybf0pjve [ 1 ] >= 0.0 ) { bpIndex_ck [ 4 ] = (
uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 1 ] ; } else { bpIndex_ck [ 4 ]
= 0U ; } mpg33qrdtp [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_ck , frac_ck , &
rtP . dp_WING_tip . CL [ 2450U * bpIndex_ck [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_dkrtirzueo , rtP .
InterpolationUsingPrelookup3_maxIndex_imdp4seazn ) ; for ( i = 0 ; i < 7 ; i
++ ) { rtB . lif0jqyjen [ 3 * i ] = ck1tgxwfew [ 3 * i ] * mpg33qrdtp [ i ] *
( real32_T ) rtB . odhuccln2g * rtP . Gain_Gain_acyum2oy5l ; rtB . lif0jqyjen
[ 3 * i + 1 ] = ck1tgxwfew [ 3 * i + 1 ] * mpg33qrdtp [ i + 7 ] * ( real32_T
) rtB . odhuccln2g * rtP . Gain_Gain_acyum2oy5l ; rtB . lif0jqyjen [ 3 * i +
2 ] = ck1tgxwfew [ 3 * i + 2 ] * mpg33qrdtp [ i + 14 ] * ( real32_T ) rtB .
odhuccln2g * rtP . Gain_Gain_acyum2oy5l ; } parallel_for ( 7 , jpp5owoa3n , 1
, "jpp5owoa3n" ) ; parallel_for ( 7 , jiwpvcutff , 1 , "jiwpvcutff" ) ;
frac_f2 [ 0 ] = rtB . be1wst1pkg ; bpIndex_f2 [ 0 ] = rtB . mb1y0b3eym ; for
( jdx = 0 ; jdx < 5 ; jdx ++ ) { frac_f2 [ 1 ] = kybpw4f1la [ jdx ] ; frac_f2
[ 2 ] = l2m0tr3gxj [ jdx ] ; frac_f2 [ 3 ] = gsmuzimw5z [ jdx ] ; bpIndex_f2
[ 1 ] = ii415rcvoz [ jdx ] ; bpIndex_f2 [ 2 ] = mlqqrra0eq [ jdx ] ;
bpIndex_f2 [ 3 ] = b45rg52mcj [ jdx ] ; prsndtjjt2 = rtP .
Constant8_Value_o2vddtqbhz [ jdx ] ; if ( prsndtjjt2 > 4.0 ) { bpIndex_f2 [ 4
] = 4U ; } else if ( prsndtjjt2 >= 0.0 ) { bpIndex_f2 [ 4 ] = ( uint32_T )
prsndtjjt2 ; } else { bpIndex_f2 [ 4 ] = 0U ; } mpg33qrdtp [ jdx ] =
intrp4d_fu32fla_pw ( bpIndex_f2 , frac_f2 , & rtP . dp_WING_root . CMx [
1750U * bpIndex_f2 [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_dqlnhgz1zi , rtP .
InterpolationUsingPrelookup4_maxIndex_o4wzqxphno ) ; } frac_kt [ 0 ] = rtB .
gefiy4un3d ; bpIndex_kt [ 0 ] = rtB . lj1ecmy3sj ; frac_kt [ 1 ] = gsguxbdffk
[ 0 ] ; frac_kt [ 2 ] = ovjd1la42y [ 0 ] ; frac_kt [ 3 ] = pyfokpvamr [ 0 ] ;
bpIndex_kt [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_kt [ 2 ] = oejjwkdimx_idx_0 ;
bpIndex_kt [ 3 ] = jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_oaybf0pjve [
0 ] > 1.0 ) { bpIndex_kt [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_oaybf0pjve [ 0 ] >= 0.0 ) { bpIndex_kt [ 4 ] = ( uint32_T )
rtP . Constant8_Value_oaybf0pjve [ 0 ] ; } else { bpIndex_kt [ 4 ] = 0U ; }
mpg33qrdtp [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_kt , frac_kt , & rtP .
dp_WING_tip . CMx [ 2450U * bpIndex_kt [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_p4aarrlaxb , rtP .
InterpolationUsingPrelookup4_maxIndex_mqwubj3l1q ) ; frac_kt [ 1 ] =
gsguxbdffk [ 1 ] ; frac_kt [ 2 ] = ovjd1la42y [ 1 ] ; frac_kt [ 3 ] =
pyfokpvamr [ 1 ] ; bpIndex_kt [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_kt [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_kt [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_oaybf0pjve [ 1 ] > 1.0 ) { bpIndex_kt [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_oaybf0pjve [ 1 ] >= 0.0 ) { bpIndex_kt [ 4 ] = (
uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 1 ] ; } else { bpIndex_kt [ 4 ]
= 0U ; } mpg33qrdtp [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_kt , frac_kt , & rtP
. dp_WING_tip . CMx [ 2450U * bpIndex_kt [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_p4aarrlaxb , rtP .
InterpolationUsingPrelookup4_maxIndex_mqwubj3l1q ) ; frac_lt [ 0 ] = rtB .
be1wst1pkg ; bpIndex_lt [ 0 ] = rtB . mb1y0b3eym ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_lt [ 1 ] = kybpw4f1la [ jdx ] ; frac_lt [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_lt [ 3 ] = gsmuzimw5z [ jdx ] ; bpIndex_lt [ 1 ] = ii415rcvoz [
jdx ] ; bpIndex_lt [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_lt [ 3 ] = b45rg52mcj
[ jdx ] ; prsndtjjt2 = rtP . Constant8_Value_o2vddtqbhz [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_lt [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 )
{ bpIndex_lt [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_lt [ 4 ] = 0U
; } mpg33qrdtp [ jdx + 7 ] = intrp4d_fu32fla_pw ( bpIndex_lt , frac_lt , &
rtP . dp_WING_root . CMy [ 1750U * bpIndex_lt [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_hlna0n1104 , rtP .
InterpolationUsingPrelookup5_maxIndex_p1qlpsazb4 ) ; } frac_hn [ 0 ] = rtB .
gefiy4un3d ; bpIndex_hn [ 0 ] = rtB . lj1ecmy3sj ; frac_hn [ 1 ] = gsguxbdffk
[ 0 ] ; frac_hn [ 2 ] = ovjd1la42y [ 0 ] ; frac_hn [ 3 ] = pyfokpvamr [ 0 ] ;
bpIndex_hn [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_hn [ 2 ] = oejjwkdimx_idx_0 ;
bpIndex_hn [ 3 ] = jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_oaybf0pjve [
0 ] > 1.0 ) { bpIndex_hn [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_oaybf0pjve [ 0 ] >= 0.0 ) { bpIndex_hn [ 4 ] = ( uint32_T )
rtP . Constant8_Value_oaybf0pjve [ 0 ] ; } else { bpIndex_hn [ 4 ] = 0U ; }
mpg33qrdtp [ 12 ] = intrp4d_fu32fla_pw ( bpIndex_hn , frac_hn , & rtP .
dp_WING_tip . CMy [ 2450U * bpIndex_hn [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_p4p42jneab , rtP .
InterpolationUsingPrelookup5_maxIndex_oxrypmydry ) ; frac_hn [ 1 ] =
gsguxbdffk [ 1 ] ; frac_hn [ 2 ] = ovjd1la42y [ 1 ] ; frac_hn [ 3 ] =
pyfokpvamr [ 1 ] ; bpIndex_hn [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_hn [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_hn [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_oaybf0pjve [ 1 ] > 1.0 ) { bpIndex_hn [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_oaybf0pjve [ 1 ] >= 0.0 ) { bpIndex_hn [ 4 ] = (
uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 1 ] ; } else { bpIndex_hn [ 4 ]
= 0U ; } mpg33qrdtp [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_hn , frac_hn , &
rtP . dp_WING_tip . CMy [ 2450U * bpIndex_hn [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_p4p42jneab , rtP .
InterpolationUsingPrelookup5_maxIndex_oxrypmydry ) ; frac_ap [ 0 ] = rtB .
be1wst1pkg ; bpIndex_ap [ 0 ] = rtB . mb1y0b3eym ; for ( jdx = 0 ; jdx < 5 ;
jdx ++ ) { frac_ap [ 1 ] = kybpw4f1la [ jdx ] ; frac_ap [ 2 ] = l2m0tr3gxj [
jdx ] ; frac_ap [ 3 ] = gsmuzimw5z [ jdx ] ; bpIndex_ap [ 1 ] = ii415rcvoz [
jdx ] ; bpIndex_ap [ 2 ] = mlqqrra0eq [ jdx ] ; bpIndex_ap [ 3 ] = b45rg52mcj
[ jdx ] ; prsndtjjt2 = rtP . Constant8_Value_o2vddtqbhz [ jdx ] ; if (
prsndtjjt2 > 4.0 ) { bpIndex_ap [ 4 ] = 4U ; } else if ( prsndtjjt2 >= 0.0 )
{ bpIndex_ap [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_ap [ 4 ] = 0U
; } mpg33qrdtp [ jdx + 14 ] = intrp4d_fu32fla_pw ( bpIndex_ap , frac_ap , &
rtP . dp_WING_root . CMz [ 1750U * bpIndex_ap [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_cdsngd0wzd , rtP .
InterpolationUsingPrelookup6_maxIndex_g3wkr4rrcb ) ; } frac_pj [ 0 ] = rtB .
gefiy4un3d ; bpIndex_pj [ 0 ] = rtB . lj1ecmy3sj ; frac_pj [ 1 ] = gsguxbdffk
[ 0 ] ; frac_pj [ 2 ] = ovjd1la42y [ 0 ] ; frac_pj [ 3 ] = pyfokpvamr [ 0 ] ;
bpIndex_pj [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_pj [ 2 ] = oejjwkdimx_idx_0 ;
bpIndex_pj [ 3 ] = jzjq4t0ecb_idx_0 ; if ( rtP . Constant8_Value_oaybf0pjve [
0 ] > 1.0 ) { bpIndex_pj [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_oaybf0pjve [ 0 ] >= 0.0 ) { bpIndex_pj [ 4 ] = ( uint32_T )
rtP . Constant8_Value_oaybf0pjve [ 0 ] ; } else { bpIndex_pj [ 4 ] = 0U ; }
mpg33qrdtp [ 19 ] = intrp4d_fu32fla_pw ( bpIndex_pj , frac_pj , & rtP .
dp_WING_tip . CMz [ 2450U * bpIndex_pj [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_dpanpvfjmk , rtP .
InterpolationUsingPrelookup6_maxIndex_mdnu5qffrq ) ; frac_pj [ 1 ] =
gsguxbdffk [ 1 ] ; frac_pj [ 2 ] = ovjd1la42y [ 1 ] ; frac_pj [ 3 ] =
pyfokpvamr [ 1 ] ; bpIndex_pj [ 1 ] = o3v0lawphs_idx_1 ; bpIndex_pj [ 2 ] =
oejjwkdimx_idx_1 ; bpIndex_pj [ 3 ] = jzjq4t0ecb_idx_1 ; if ( rtP .
Constant8_Value_oaybf0pjve [ 1 ] > 1.0 ) { bpIndex_pj [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_oaybf0pjve [ 1 ] >= 0.0 ) { bpIndex_pj [ 4 ] = (
uint32_T ) rtP . Constant8_Value_oaybf0pjve [ 1 ] ; } else { bpIndex_pj [ 4 ]
= 0U ; } mpg33qrdtp [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_pj , frac_pj , &
rtP . dp_WING_tip . CMz [ 2450U * bpIndex_pj [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_dpanpvfjmk , rtP .
InterpolationUsingPrelookup6_maxIndex_mdnu5qffrq ) ; e12efcqisd = rtP . S /
2.0 ; for ( i = 0 ; i < 7 ; i ++ ) { hg2rsg5czq [ 3 * i ] = ck1tgxwfew [ 3 *
i ] * mpg33qrdtp [ i ] * rtP . Constant_Value_benf1an55k [ 3 * i ] * (
real32_T ) rtB . odhuccln2g * e12efcqisd + rtB . byhpdluumb [ 3 * i ] ;
hg2rsg5czq [ 3 * i + 1 ] = ck1tgxwfew [ 3 * i + 1 ] * mpg33qrdtp [ i + 7 ] *
rtP . Constant_Value_benf1an55k [ 3 * i + 1 ] * ( real32_T ) rtB . odhuccln2g
* e12efcqisd + rtB . byhpdluumb [ 3 * i + 1 ] ; hg2rsg5czq [ 3 * i + 2 ] =
ck1tgxwfew [ 3 * i + 2 ] * mpg33qrdtp [ i + 14 ] * rtP .
Constant_Value_benf1an55k [ 3 * i + 2 ] * ( real32_T ) rtB . odhuccln2g *
e12efcqisd + rtB . byhpdluumb [ 3 * i + 2 ] ; } for ( jdx = 0 ; jdx < 3 ; jdx
++ ) { e12efcqisd = - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { e12efcqisd +=
hg2rsg5czq [ i * 3 + jdx ] ; } cuwl4zp4yw [ jdx ] = e12efcqisd ; }
mmxlym3ls1_idx_0 = ( real32_T ) cuwl4zp4yw [ 0 ] ; mmxlym3ls1_idx_1 = (
real32_T ) cuwl4zp4yw [ 1 ] ; mmxlym3ls1_idx_2 = ( real32_T ) cuwl4zp4yw [ 2
] ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { k11flw5eod = khgvdadyv1 [ 4 ] ;
oyx2gc3mag_idx_0 = khgvdadyv1 [ 5 ] ; for ( i = 0 ; i < 8 ; i ++ ) {
nvl2rva03y [ i ] = rtP . Constant_Value_mn4jvly12r [ i ] * k11flw5eod ;
nvl2rva03y [ i + 8 ] = rtP . Constant1_Value_dqqxjknpbv [ i ] *
oyx2gc3mag_idx_0 ; } for ( i = 0 ; i < 5 ; i ++ ) { tmp [ i ] = rtP .
dp_VTAIL_INDUCED . flap_defl [ i ] ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) {
rtB . nj3xuut2fh [ jdx ] = plook_linxp ( nvl2rva03y [ jdx ] , tmp , 4U , &
rtB . bw4iyihnma [ jdx ] , & rtDW . op4s5nmfn0 [ jdx ] ) ; } } for ( jdx = 0
; jdx < 16 ; jdx ++ ) { bjb5ael2po [ jdx ] = look1_iflf_pbinlcpw ( rtP .
Constant7_Value [ jdx ] , rtP . uDLookupTable_bp01Data_anwusoh2uk , & rtB .
cfz24gonbx [ 4 ] , & rtDW . p3qcu4kyf3 [ jdx ] , 5U ) ; } for ( jdx = 0 ; jdx
< 16 ; jdx ++ ) { aovbnhpt5r [ jdx ] = plook_u32ff_linxp ( bjb5ael2po [ jdx ]
, rtP . dp_VTAIL_INDUCED . alphas , 24U , & hmfdyqp1cp [ jdx ] , & rtDW .
d1rjlxqbuf [ jdx ] ) ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { bjb5ael2po [
jdx ] = look1_iflf_pbinlcpw ( rtP . Constant7_Value [ jdx ] , rtP .
uDLookupTable1_bp01Data_lct4mwibxn , & rtB . nmxk2xrfk3 [ 4 ] , & rtDW .
g130c2x32o [ jdx ] , 5U ) ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) {
kfwhlxjyld [ jdx ] = plook_u32ff_linxp ( bjb5ael2po [ jdx ] , rtP .
dp_VTAIL_INDUCED . V_infs , 1U , & dkboypdf3m [ jdx ] , & rtDW . dssqgth4gt [
jdx ] ) ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { bjb5ael2po [ jdx ] =
look1_iflf_pbinlcpw ( rtP . Constant7_Value [ jdx ] , rtP .
uDLookupTable2_bp01Data , & c0f5gkmurs [ 3 ] , & rtDW . erz4us2nfk [ jdx ] ,
5U ) ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { nw4cbc4l10 [ jdx ] =
plook_u32ff_lincp ( bjb5ael2po [ jdx ] , rtP . dp_VTAIL_INDUCED . DEP_J , 6U
, & lzm2khqk43 [ jdx ] , & rtDW . fyjcynthf1 [ jdx ] ) ; } for ( jdx = 0 ;
jdx < 16 ; jdx ++ ) { frac_po [ 0 ] = rtB . bw4iyihnma [ jdx ] ; frac_po [ 1
] = hmfdyqp1cp [ jdx ] ; frac_po [ 2 ] = dkboypdf3m [ jdx ] ; frac_po [ 3 ] =
lzm2khqk43 [ jdx ] ; bpIndex_po [ 0 ] = rtB . nj3xuut2fh [ jdx ] ; bpIndex_po
[ 1 ] = aovbnhpt5r [ jdx ] ; bpIndex_po [ 2 ] = kfwhlxjyld [ jdx ] ;
bpIndex_po [ 3 ] = nw4cbc4l10 [ jdx ] ; prsndtjjt2 = rtP . Constant8_Value [
jdx ] ; if ( prsndtjjt2 > 15.0 ) { bpIndex_po [ 4 ] = 15U ; } else if (
prsndtjjt2 >= 0.0 ) { bpIndex_po [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else {
bpIndex_po [ 4 ] = 0U ; } oyx2gc3mag_idx_1 = intrp4d_fl_pw ( bpIndex_po ,
frac_po , & rtP . dp_VTAIL_INDUCED . V_induced [ 1750U * bpIndex_po [ 4 ] ] ,
rtP . V_induced_dimSize ) ; bjb5ael2po [ jdx ] = oyx2gc3mag_idx_1 ; rtB .
kmxfn2bnil [ jdx ] = oyx2gc3mag_idx_1 ; } parallel_for ( 16 , ggl0rm1hau , 1
, "ggl0rm1hau" ) ; for ( i = 0 ; i < 16 ; i ++ ) { k11flw5eod = bjb5ael2po [
i ] + rtB . nmxk2xrfk3z [ i ] ; if ( k11flw5eod > rtP .
Saturation_UpperSat_b2a52laupk ) { k11flw5eod = rtP .
Saturation_UpperSat_b2a52laupk ; } else if ( k11flw5eod < rtP .
Saturation_LowerSat_gotqetz1tq ) { k11flw5eod = rtP .
Saturation_LowerSat_gotqetz1tq ; } rtB . ody4e0c4gv [ i ] = rtP .
vtail_dist_to_wing / k11flw5eod ; } { real_T * * uBuffer = ( real_T * * ) &
rtDW . a1p5mmdhor . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ;
real_T appliedDelay ; { int_T i1 ; const real_T * u0 = & rtB . kmxfn2bnil [ 0
] ; const real_T * u1 = & rtB . ody4e0c4gv [ 0 ] ; real_T * y0 = & pb5onpph4x
[ 0 ] ; int_T * iw_Tail = & rtDW . l1l2gip32s . Tail [ 0 ] ; int_T * iw_Head
= & rtDW . l1l2gip32s . Head [ 0 ] ; int_T * iw_Last = & rtDW . l1l2gip32s .
Last [ 0 ] ; int_T * iw_CircularBufSize = & rtDW . l1l2gip32s .
CircularBufSize [ 0 ] ; for ( i1 = 0 ; i1 < 16 ; i1 ++ ) { appliedDelay = u1
[ i1 ] ; if ( appliedDelay > rtP . VariableTransportDelay1_MaxDelay ) {
appliedDelay = rtP . VariableTransportDelay1_MaxDelay ; } if ( appliedDelay <
0.0 ) { appliedDelay = 0.0 ; } if ( appliedDelay == 0.0 ) { y0 [ i1 ] = u0 [
i1 ] ; } else { y0 [ i1 ] = rt_TDelayInterpolate ( simTime - appliedDelay ,
0.0 , * uBuffer , iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1
] , iw_Head [ i1 ] , rtP . VariableTransportDelay1_InitOutput , 0 , (
boolean_T ) ( ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + iw_CircularBufSize
[ i1 ] ) [ iw_Head [ i1 ] ] == ssGetT ( rtS ) ) ) ) ; } uBuffer ++ ; } } } if
( ssGetTaskTime ( rtS , 0 ) < rtP . Step_Time ) { prsndtjjt2 = rtP . Step_Y0
; } else { prsndtjjt2 = rtP . Step_YFinal ; } for ( i = 0 ; i < 16 ; i ++ ) {
if ( prsndtjjt2 > rtP . Switch_Threshold_barcjzagnb ) { do2fmqm0jw_idx_0 =
pb5onpph4x [ i ] ; } else { do2fmqm0jw_idx_0 = rtB . kmxfn2bnil [ i ] ; }
j1ncyjcm0a [ i ] = do2fmqm0jw_idx_0 ; rtB . ln5blvjdm3 [ i ] = ( real32_T )
do2fmqm0jw_idx_0 ; oyx2gc3mag_idx_1 = ( real32_T ) do2fmqm0jw_idx_0 + rtB .
nmxk2xrfk3z [ i ] ; iigtngxjbp [ 3 * i ] = oyx2gc3mag_idx_1 ; iigtngxjbp [ 3
* i + 1 ] = oyx2gc3mag_idx_1 ; iigtngxjbp [ 3 * i + 2 ] = oyx2gc3mag_idx_1 ;
} for ( i = 0 ; i < 48 ; i ++ ) { k11flw5eod = iigtngxjbp [ i ] ; iigtngxjbp
[ i ] = k11flw5eod * k11flw5eod ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
k11flw5eod = khgvdadyv1 [ 2 ] ; oyx2gc3mag_idx_0 = khgvdadyv1 [ 3 ] ; for ( i
= 0 ; i < 8 ; i ++ ) { nvl2rva03y [ i ] = rtP . Constant_Value_asshyiafnn [ i
] * k11flw5eod ; nvl2rva03y [ i + 8 ] = rtP . Constant1_Value_h01num5fy3 [ i
] * oyx2gc3mag_idx_0 ; } for ( i = 0 ; i < 10 ; i ++ ) { tmp_p [ i ] = rtP .
dp_VTAIL . rude_defl [ i ] ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { rtB .
ngy3pgy40m [ jdx ] = plook_linxp ( nvl2rva03y [ jdx ] , tmp_p , 9U , & rtB .
d0gfg5onrd [ jdx ] , & rtDW . acn3fu00s1 [ jdx ] ) ; } } for ( jdx = 0 ; jdx
< 16 ; jdx ++ ) { frac_pk [ 0 ] = rtB . bw4iyihnma [ jdx ] ; frac_pk [ 1 ] =
hmfdyqp1cp [ jdx ] ; frac_pk [ 2 ] = dkboypdf3m [ jdx ] ; frac_pk [ 3 ] =
lzm2khqk43 [ jdx ] ; bpIndex_pk [ 0 ] = rtB . nj3xuut2fh [ jdx ] ; bpIndex_pk
[ 1 ] = aovbnhpt5r [ jdx ] ; bpIndex_pk [ 2 ] = kfwhlxjyld [ jdx ] ;
bpIndex_pk [ 3 ] = nw4cbc4l10 [ jdx ] ; prsndtjjt2 = rtP . Constant8_Value [
jdx ] ; if ( prsndtjjt2 > 15.0 ) { bpIndex_pk [ 4 ] = 15U ; } else if (
prsndtjjt2 >= 0.0 ) { bpIndex_pk [ 4 ] = ( uint32_T ) prsndtjjt2 ; } else {
bpIndex_pk [ 4 ] = 0U ; } oyx2gc3mag_idx_1 = intrp4d_fl_pw ( bpIndex_pk ,
frac_pk , & rtP . dp_VTAIL_INDUCED . alpha_induced [ 1750U * bpIndex_pk [ 4 ]
] , rtP . alpha_induced_dimSize ) ; rtB . agdfetg0qt [ jdx ] =
oyx2gc3mag_idx_1 ; } { real_T * * uBuffer = ( real_T * * ) & rtDW .
d5j1ciynjn . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T
appliedDelay ; { int_T i1 ; const real_T * u0 = & rtB . agdfetg0qt [ 0 ] ;
const real_T * u1 = & rtB . ody4e0c4gv [ 0 ] ; real_T * y0 = & j1ncyjcm0a [ 0
] ; int_T * iw_Tail = & rtDW . lynamxwk0r . Tail [ 0 ] ; int_T * iw_Head = &
rtDW . lynamxwk0r . Head [ 0 ] ; int_T * iw_Last = & rtDW . lynamxwk0r . Last
[ 0 ] ; int_T * iw_CircularBufSize = & rtDW . lynamxwk0r . CircularBufSize [
0 ] ; for ( i1 = 0 ; i1 < 16 ; i1 ++ ) { appliedDelay = u1 [ i1 ] ; if (
appliedDelay > rtP . VariableTransportDelay_MaxDelay ) { appliedDelay = rtP .
VariableTransportDelay_MaxDelay ; } if ( appliedDelay < 0.0 ) { appliedDelay
= 0.0 ; } if ( appliedDelay == 0.0 ) { y0 [ i1 ] = u0 [ i1 ] ; } else { y0 [
i1 ] = rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , * uBuffer ,
iw_CircularBufSize [ i1 ] , & iw_Last [ i1 ] , iw_Tail [ i1 ] , iw_Head [ i1
] , rtP . VariableTransportDelay_InitOutput , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( rtS ) && ( ( * uBuffer + iw_CircularBufSize [ i1 ] ) [
iw_Head [ i1 ] ] == ssGetT ( rtS ) ) ) ) ; } uBuffer ++ ; } } } if (
ssGetTaskTime ( rtS , 0 ) < rtP . Step1_Time ) { prsndtjjt2 = rtP . Step1_Y0
; } else { prsndtjjt2 = rtP . Step1_YFinal ; } for ( i = 0 ; i < 16 ; i ++ )
{ if ( prsndtjjt2 > rtP . Switch1_Threshold ) { do2fmqm0jw_idx_0 = j1ncyjcm0a
[ i ] ; } else { do2fmqm0jw_idx_0 = rtB . agdfetg0qt [ i ] ; } pb5onpph4x [ i
] = do2fmqm0jw_idx_0 ; bjb5ael2po [ i ] = ( real32_T ) do2fmqm0jw_idx_0 ; rtB
. ge01nkozzs [ i ] = ( real32_T ) do2fmqm0jw_idx_0 + rtB . cfz24gonbxg [ i ]
; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { nw4cbc4l10 [ jdx ] =
plook_u32ff_linxp ( rtB . ge01nkozzs [ jdx ] , rtP . dp_VTAIL . alphas , 12U
, & bjb5ael2po [ jdx ] , & rtDW . itcccsf0ct [ jdx ] ) ; } for ( jdx = 0 ;
jdx < 16 ; jdx ++ ) { kfwhlxjyld [ jdx ] = plook_u32ff_linxp ( rtB .
atgyr3lfo3 [ jdx ] , rtP . dp_VTAIL . betas , 8U , & lzm2khqk43 [ jdx ] , &
rtDW . lipbrcbfzk [ jdx ] ) ; } for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { frac_d0
[ 0 ] = rtB . d0gfg5onrd [ jdx ] ; oyx2gc3mag_idx_1 = bjb5ael2po [ jdx ] ;
frac_d0 [ 1 ] = oyx2gc3mag_idx_1 ; oyx2gc3mag_idx_2 = lzm2khqk43 [ jdx ] ;
frac_d0 [ 2 ] = oyx2gc3mag_idx_2 ; bpIndex_d0 [ 0 ] = rtB . ngy3pgy40m [ jdx
] ; o3v0lawphs_idx_0 = nw4cbc4l10 [ jdx ] ; bpIndex_d0 [ 1 ] =
o3v0lawphs_idx_0 ; o3v0lawphs_idx_1 = kfwhlxjyld [ jdx ] ; bpIndex_d0 [ 2 ] =
o3v0lawphs_idx_1 ; prsndtjjt2 = rtP . Constant8_Value_gsd4tzxrvv [ jdx ] ; if
( prsndtjjt2 > 15.0 ) { bpIndex_d0 [ 3 ] = 15U ; } else if ( prsndtjjt2 >=
0.0 ) { bpIndex_d0 [ 3 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_d0 [ 3
] = 0U ; } k11flw5eod = intrp3d_fl_pw ( bpIndex_d0 , frac_d0 , & rtP .
dp_VTAIL . CFx [ 1170U * bpIndex_d0 [ 3 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_ff4dr0zil3 ) ; frac_kh [ 0 ] = rtB .
d0gfg5onrd [ jdx ] ; frac_kh [ 1 ] = oyx2gc3mag_idx_1 ; frac_kh [ 2 ] =
oyx2gc3mag_idx_2 ; bpIndex_kh [ 0 ] = rtB . ngy3pgy40m [ jdx ] ; bpIndex_kh [
1 ] = o3v0lawphs_idx_0 ; bpIndex_kh [ 2 ] = o3v0lawphs_idx_1 ; prsndtjjt2 =
rtP . Constant8_Value_gsd4tzxrvv [ jdx ] ; if ( prsndtjjt2 > 15.0 ) {
bpIndex_kh [ 3 ] = 15U ; } else if ( prsndtjjt2 >= 0.0 ) { bpIndex_kh [ 3 ] =
( uint32_T ) prsndtjjt2 ; } else { bpIndex_kh [ 3 ] = 0U ; } oyx2gc3mag_idx_0
= intrp3d_fl_pw ( bpIndex_kh , frac_kh , & rtP . dp_VTAIL . CFy [ 1170U *
bpIndex_kh [ 3 ] ] , rtP . InterpolationUsingPrelookup2_dimSize_kfgynmyj32 )
; frac_m0 [ 0 ] = rtB . d0gfg5onrd [ jdx ] ; frac_m0 [ 1 ] = oyx2gc3mag_idx_1
; frac_m0 [ 2 ] = oyx2gc3mag_idx_2 ; bpIndex_m0 [ 0 ] = rtB . ngy3pgy40m [
jdx ] ; bpIndex_m0 [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_m0 [ 2 ] =
o3v0lawphs_idx_1 ; prsndtjjt2 = rtP . Constant8_Value_gsd4tzxrvv [ jdx ] ; if
( prsndtjjt2 > 15.0 ) { bpIndex_m0 [ 3 ] = 15U ; } else if ( prsndtjjt2 >=
0.0 ) { bpIndex_m0 [ 3 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_m0 [ 3
] = 0U ; } oyx2gc3mag_idx_1 = intrp3d_fl_pw ( bpIndex_m0 , frac_m0 , & rtP .
dp_VTAIL . CFz [ 1170U * bpIndex_m0 [ 3 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_m2ki2jhx1z ) ; rtB . o0icr3ysdn [ 3 *
jdx ] = iigtngxjbp [ 3 * jdx ] * k11flw5eod * ( real32_T ) rtB . odhuccln2g *
rtP . Gain2_Gain_pp1pwsqq1n ; rtB . o0icr3ysdn [ 3 * jdx + 1 ] = iigtngxjbp [
3 * jdx + 1 ] * oyx2gc3mag_idx_0 * ( real32_T ) rtB . odhuccln2g * rtP .
Gain2_Gain_pp1pwsqq1n ; rtB . o0icr3ysdn [ 3 * jdx + 2 ] = iigtngxjbp [ 3 *
jdx + 2 ] * oyx2gc3mag_idx_1 * ( real32_T ) rtB . odhuccln2g * rtP .
Gain2_Gain_pp1pwsqq1n ; } parallel_for ( 16 , femu5gktcp , 1 , "femu5gktcp" )
; for ( jdx = 0 ; jdx < 16 ; jdx ++ ) { frac_fv [ 0 ] = rtB . d0gfg5onrd [
jdx ] ; oyx2gc3mag_idx_1 = bjb5ael2po [ jdx ] ; frac_fv [ 1 ] =
oyx2gc3mag_idx_1 ; oyx2gc3mag_idx_2 = lzm2khqk43 [ jdx ] ; frac_fv [ 2 ] =
oyx2gc3mag_idx_2 ; bpIndex_fv [ 0 ] = rtB . ngy3pgy40m [ jdx ] ;
o3v0lawphs_idx_0 = nw4cbc4l10 [ jdx ] ; bpIndex_fv [ 1 ] = o3v0lawphs_idx_0 ;
o3v0lawphs_idx_1 = kfwhlxjyld [ jdx ] ; bpIndex_fv [ 2 ] = o3v0lawphs_idx_1 ;
prsndtjjt2 = rtP . Constant8_Value_gsd4tzxrvv [ jdx ] ; if ( prsndtjjt2 >
15.0 ) { bpIndex_fv [ 3 ] = 15U ; } else if ( prsndtjjt2 >= 0.0 ) {
bpIndex_fv [ 3 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_fv [ 3 ] = 0U ;
} k11flw5eod = intrp3d_fl_pw ( bpIndex_fv , frac_fv , & rtP . dp_VTAIL . CMx
[ 1170U * bpIndex_fv [ 3 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_juyddnk1fb ) ; frac_m4 [ 0 ] = rtB .
d0gfg5onrd [ jdx ] ; frac_m4 [ 1 ] = oyx2gc3mag_idx_1 ; frac_m4 [ 2 ] =
oyx2gc3mag_idx_2 ; bpIndex_m4 [ 0 ] = rtB . ngy3pgy40m [ jdx ] ; bpIndex_m4 [
1 ] = o3v0lawphs_idx_0 ; bpIndex_m4 [ 2 ] = o3v0lawphs_idx_1 ; prsndtjjt2 =
rtP . Constant8_Value_gsd4tzxrvv [ jdx ] ; if ( prsndtjjt2 > 15.0 ) {
bpIndex_m4 [ 3 ] = 15U ; } else if ( prsndtjjt2 >= 0.0 ) { bpIndex_m4 [ 3 ] =
( uint32_T ) prsndtjjt2 ; } else { bpIndex_m4 [ 3 ] = 0U ; } oyx2gc3mag_idx_0
= intrp3d_fl_pw ( bpIndex_m4 , frac_m4 , & rtP . dp_VTAIL . CMy [ 1170U *
bpIndex_m4 [ 3 ] ] , rtP . InterpolationUsingPrelookup5_dimSize_mnvowrob4d )
; frac_nf [ 0 ] = rtB . d0gfg5onrd [ jdx ] ; frac_nf [ 1 ] = oyx2gc3mag_idx_1
; frac_nf [ 2 ] = oyx2gc3mag_idx_2 ; bpIndex_nf [ 0 ] = rtB . ngy3pgy40m [
jdx ] ; bpIndex_nf [ 1 ] = o3v0lawphs_idx_0 ; bpIndex_nf [ 2 ] =
o3v0lawphs_idx_1 ; prsndtjjt2 = rtP . Constant8_Value_gsd4tzxrvv [ jdx ] ; if
( prsndtjjt2 > 15.0 ) { bpIndex_nf [ 3 ] = 15U ; } else if ( prsndtjjt2 >=
0.0 ) { bpIndex_nf [ 3 ] = ( uint32_T ) prsndtjjt2 ; } else { bpIndex_nf [ 3
] = 0U ; } oyx2gc3mag_idx_1 = intrp3d_fl_pw ( bpIndex_nf , frac_nf , & rtP .
dp_VTAIL . CMz [ 1170U * bpIndex_nf [ 3 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_lpul1da2p2 ) ; ftphjt5uz2 [ 3 * jdx ] =
iigtngxjbp [ 3 * jdx ] * k11flw5eod * rtP . Constant1_Value_lhco2hmkqd [ 3 *
jdx ] * ( real32_T ) rtB . odhuccln2g * rtP . Gain3_Gain_i1yimbgde1 + rtB .
byhpdluumbuo [ 3 * jdx ] ; ftphjt5uz2 [ 3 * jdx + 1 ] = iigtngxjbp [ 3 * jdx
+ 1 ] * oyx2gc3mag_idx_0 * rtP . Constant1_Value_lhco2hmkqd [ 3 * jdx + 1 ] *
( real32_T ) rtB . odhuccln2g * rtP . Gain3_Gain_i1yimbgde1 + rtB .
byhpdluumbuo [ 3 * jdx + 1 ] ; ftphjt5uz2 [ 3 * jdx + 2 ] = iigtngxjbp [ 3 *
jdx + 2 ] * oyx2gc3mag_idx_1 * rtP . Constant1_Value_lhco2hmkqd [ 3 * jdx + 2
] * ( real32_T ) rtB . odhuccln2g * rtP . Gain3_Gain_i1yimbgde1 + rtB .
byhpdluumbuo [ 3 * jdx + 2 ] ; } for ( jdx = 0 ; jdx < 3 ; jdx ++ ) {
e12efcqisd = - 0.0 ; for ( i = 0 ; i < 16 ; i ++ ) { e12efcqisd += ftphjt5uz2
[ i * 3 + jdx ] ; } cuwl4zp4yw [ jdx ] = e12efcqisd ; } rtB . hmn4gg1bt5 =
muDoubleScalarAtan2 ( jxoxz3uefs , ga0emsz5x4 [ 0 ] ) ; oyx2gc3mag_idx_0 = (
real32_T ) cuwl4zp4yw [ 0 ] ; oyx2gc3mag_idx_1 = ( real32_T ) cuwl4zp4yw [ 1
] ; oyx2gc3mag_idx_2 = ( real32_T ) cuwl4zp4yw [ 2 ] ; rtB . hwfjzaa0nm =
muDoubleScalarSqrt ( ( ga0emsz5x4 [ 0 ] * ga0emsz5x4 [ 0 ] + ga0emsz5x4 [ 1 ]
* ga0emsz5x4 [ 1 ] ) + jxoxz3uefs * jxoxz3uefs ) + rtP .
Constant1_Value_aexthjzkeg ; ky1lxji0nf = ga0emsz5x4 [ 1 ] / rtB . hwfjzaa0nm
; if ( ky1lxji0nf > 1.0 ) { ky1lxji0nf = 1.0 ; } else if ( ky1lxji0nf < - 1.0
) { ky1lxji0nf = - 1.0 ; } rtB . aeyzgmp4rb = muDoubleScalarAsin ( ky1lxji0nf
) ; muDoubleScalarSinCos ( ( real32_T ) rtB . hmn4gg1bt5 , & prsndtjjt2 , &
do2fmqm0jw_idx_0 ) ; muDoubleScalarSinCos ( ( real32_T ) rtB . aeyzgmp4rb , &
d0tg15yv0e_idx_1 , & do2fmqm0jw_idx_1 ) ; hvlby4ocab [ 0 ] = do2fmqm0jw_idx_0
* do2fmqm0jw_idx_1 ; hvlby4ocab [ 1 ] = - ( do2fmqm0jw_idx_0 *
d0tg15yv0e_idx_1 ) ; hvlby4ocab [ 2 ] = - prsndtjjt2 ; hvlby4ocab [ 3 ] =
d0tg15yv0e_idx_1 ; hvlby4ocab [ 4 ] = do2fmqm0jw_idx_1 ; hvlby4ocab [ 5 ] =
rtP . Constant_Value_lx5fpqludr ; hvlby4ocab [ 6 ] = prsndtjjt2 *
do2fmqm0jw_idx_1 ; hvlby4ocab [ 7 ] = - ( prsndtjjt2 * d0tg15yv0e_idx_1 ) ;
hvlby4ocab [ 8 ] = do2fmqm0jw_idx_0 ; o3v0lawphs_idx_0 = plook_u32ff_linxp (
( real32_T ) rtB . aeyzgmp4rb , rtP . Prelookup_BreakpointsData , 12U , &
k11flw5eod , & rtDW . md1fsm3br3 ) ; o3v0lawphs_idx_1 = plook_u32ff_linxp ( (
real32_T ) rtB . hmn4gg1bt5 , rtP . Prelookup1_BreakpointsData , 14U , &
lwh2w2o2to , & rtDW . be05daasmg ) ; frac_mi [ 0 ] = k11flw5eod ; frac_mi [ 1
] = lwh2w2o2to ; bpIndex_mi [ 0 ] = o3v0lawphs_idx_0 ; bpIndex_mi [ 1 ] =
o3v0lawphs_idx_1 ; frac_b0 [ 0 ] = k11flw5eod ; frac_b0 [ 1 ] = lwh2w2o2to ;
bpIndex_b0 [ 0 ] = o3v0lawphs_idx_0 ; bpIndex_b0 [ 1 ] = o3v0lawphs_idx_1 ;
kubly5n2ia = ( real32_T ) rtB . hwfjzaa0nm * ( real32_T ) rtB . hwfjzaa0nm ;
tmp_e = intrp2d_fu32fl_pw ( bpIndex_b0 , frac_b0 , rtP . dp_FUSE_FIN . CS ,
13U ) ; tmp_i = - intrp2d_fu32fl_pw ( bpIndex_mi , frac_mi , rtP .
dp_FUSE_FIN . CD , 13U ) ; frac_cc [ 0 ] = k11flw5eod ; frac_cc [ 1 ] =
lwh2w2o2to ; bpIndex_cc [ 0 ] = o3v0lawphs_idx_0 ; bpIndex_cc [ 1 ] =
o3v0lawphs_idx_1 ; frac_gw [ 0 ] = k11flw5eod ; frac_gw [ 1 ] = lwh2w2o2to ;
bpIndex_gw [ 0 ] = o3v0lawphs_idx_0 ; bpIndex_gw [ 1 ] = o3v0lawphs_idx_1 ;
frac_iz [ 0 ] = k11flw5eod ; frac_iz [ 1 ] = lwh2w2o2to ; bpIndex_iz [ 0 ] =
o3v0lawphs_idx_0 ; bpIndex_iz [ 1 ] = o3v0lawphs_idx_1 ; cuwl4zp4yw [ 0 ] =
intrp2d_fu32fl_pw ( bpIndex_cc , frac_cc , rtP . dp_FUSE_FIN . CMx , 13U ) *
kubly5n2ia * rtP . Constant_Value_jra04za24u [ 0 ] ; cuwl4zp4yw [ 1 ] =
intrp2d_fu32fl_pw ( bpIndex_gw , frac_gw , rtP . dp_FUSE_FIN . CMy , 13U ) *
kubly5n2ia * rtP . Constant_Value_jra04za24u [ 1 ] ; cuwl4zp4yw [ 2 ] =
intrp2d_fu32fl_pw ( bpIndex_iz , frac_iz , rtP . dp_FUSE_FIN . CMz , 13U ) *
kubly5n2ia * rtP . Constant_Value_jra04za24u [ 2 ] ; for ( i = 0 ; i < 3 ; i
++ ) { g0uuf55mpg [ i ] = ( ( ( real32_T ) hvlby4ocab [ 3 * i + 1 ] * tmp_e +
( real32_T ) hvlby4ocab [ 3 * i ] * tmp_i ) + ( real32_T ) hvlby4ocab [ 3 * i
+ 2 ] * rtB . phywd5jekf ) * kubly5n2ia * ( real32_T ) rtB . odhuccln2g * rtP
. Gain_Gain_llsqu3hkdm ; frac_d0 [ i ] = ( real32_T ) rtB . odhuccln2g *
cuwl4zp4yw [ i ] ; } e12efcqisd = rtP . S / 2.0 ; rtB . d1dja0jwhm [ 0 ] = (
( rtB . krmhpaiwtk [ 1 ] * g0uuf55mpg [ 2 ] - g0uuf55mpg [ 1 ] * rtB .
krmhpaiwtk [ 2 ] ) + e12efcqisd * frac_d0 [ 0 ] ) + ( ( real_T ) ( -
a4viish00u_idx_0 + mmxlym3ls1_idx_0 ) + oyx2gc3mag_idx_0 ) ; rtB . d1dja0jwhm
[ 1 ] = ( ( g0uuf55mpg [ 0 ] * rtB . krmhpaiwtk [ 2 ] - rtB . krmhpaiwtk [ 0
] * g0uuf55mpg [ 2 ] ) + e12efcqisd * frac_d0 [ 1 ] ) + ( ( real_T ) (
a4viish00u_idx_1 + mmxlym3ls1_idx_1 ) + oyx2gc3mag_idx_1 ) ; rtB . d1dja0jwhm
[ 2 ] = ( ( rtB . krmhpaiwtk [ 0 ] * g0uuf55mpg [ 1 ] - g0uuf55mpg [ 0 ] *
rtB . krmhpaiwtk [ 1 ] ) + e12efcqisd * frac_d0 [ 2 ] ) + ( ( real_T ) ( -
a4viish00u_idx_2 + mmxlym3ls1_idx_2 ) + oyx2gc3mag_idx_2 ) ; for ( jdx = 0 ;
jdx < 3 ; jdx ++ ) { e12efcqisd = - 0.0 ; for ( i = 0 ; i < 12 ; i ++ ) {
e12efcqisd += gsnhdicnm0 [ i * 3 + jdx ] ; } frac_d0 [ jdx ] = e12efcqisd ;
muDoubleScalarSinCos ( nhudhta0yo [ jdx ] , & cuwl4zp4yw [ jdx ] , &
a5zxkwaluu [ jdx ] ) ; } hvlby4ocab [ 0 ] = a5zxkwaluu [ 0 ] * a5zxkwaluu [ 1
] ; hvlby4ocab [ 1 ] = cuwl4zp4yw [ 1 ] * cuwl4zp4yw [ 2 ] * a5zxkwaluu [ 0 ]
- cuwl4zp4yw [ 0 ] * a5zxkwaluu [ 2 ] ; hvlby4ocab [ 2 ] = cuwl4zp4yw [ 1 ] *
a5zxkwaluu [ 2 ] * a5zxkwaluu [ 0 ] + cuwl4zp4yw [ 0 ] * cuwl4zp4yw [ 2 ] ;
hvlby4ocab [ 3 ] = cuwl4zp4yw [ 0 ] * a5zxkwaluu [ 1 ] ; hvlby4ocab [ 4 ] =
cuwl4zp4yw [ 1 ] * cuwl4zp4yw [ 2 ] * cuwl4zp4yw [ 0 ] + a5zxkwaluu [ 0 ] *
a5zxkwaluu [ 2 ] ; hvlby4ocab [ 5 ] = cuwl4zp4yw [ 1 ] * a5zxkwaluu [ 2 ] *
cuwl4zp4yw [ 0 ] - a5zxkwaluu [ 0 ] * cuwl4zp4yw [ 2 ] ; hvlby4ocab [ 6 ] = -
cuwl4zp4yw [ 1 ] ; hvlby4ocab [ 7 ] = a5zxkwaluu [ 1 ] * cuwl4zp4yw [ 2 ] ;
hvlby4ocab [ 8 ] = a5zxkwaluu [ 1 ] * a5zxkwaluu [ 2 ] ; prsndtjjt2 = rtB .
pr1vt54ko4 [ 1 ] ; do2fmqm0jw_idx_0 = rtB . pr1vt54ko4 [ 0 ] ; ky1lxji0nf =
rtB . pr1vt54ko4 [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { frhju144cl [ i ] = (
( hvlby4ocab [ 3 * i + 1 ] * prsndtjjt2 + hvlby4ocab [ 3 * i ] *
do2fmqm0jw_idx_0 ) + hvlby4ocab [ 3 * i + 2 ] * ky1lxji0nf ) + rtB .
exyupufjt5 [ i ] ; } rtB . jagg20wiay = rtP . ground_alt - frhju144cl [ 2 ] ;
if ( rtB . jagg20wiay > rtP . Switch_Threshold_fa0qrtsblw ) { rtB .
h5anqi052g = rtP . Constant1_Value_dhktifwxn5 ; } else { rtB . h5anqi052g =
rtP . Constant_Value_l3yr2jaxah ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . cutvjsc51o [ 0 ] = rtDW . oy300njhw2 [ 0 ] ; rtB . cutvjsc51o [ 1 ] =
rtDW . oy300njhw2 [ 1 ] ; rtB . cutvjsc51o [ 2 ] = rtDW . oy300njhw2 [ 2 ] ;
} rtB . jvaexa3o5a . jr3yr4ixei [ 0 ] = rtB . cutvjsc51o [ 0 ] ; rtB .
jvaexa3o5a . jr3yr4ixei [ 1 ] = rtB . cutvjsc51o [ 1 ] ; rtB . jvaexa3o5a .
jr3yr4ixei [ 2 ] = rtB . cutvjsc51o [ 2 ] ; pm13c03kzl ( frhju144cl , rtB .
h5anqi052g , & rtB . jvaexa3o5a , & rtDW . jvaexa3o5a ) ; if ( rtB .
h5anqi052g ) { tmp_m = rtB . jvaexa3o5a . ggmvjtadg3 [ 2 ] - frhju144cl [ 2 ]
; } else { tmp_m = rtP . Constant_Value_o1yp2gl00i ; } ky1lxji0nf = tmp_m +
rtP . Constant2_Value_p2rjztbk2r ; if ( ky1lxji0nf > rtP .
Saturation1_UpperSat_faajmjiyue ) { ky1lxji0nf = rtP .
Saturation1_UpperSat_faajmjiyue ; } else if ( ky1lxji0nf < rtP .
Saturation1_LowerSat_fjfihtgctt ) { ky1lxji0nf = rtP .
Saturation1_LowerSat_fjfihtgctt ; } rtB . llwqqnw3ke = ky1lxji0nf * rtP .
Constant_Value_fgevrsqc4v ; if ( rtB . h5anqi052g ) { muDoubleScalarSinCos (
rtP . Constant1_Value_eyubj2pyfz , & prsndtjjt2 , & do2fmqm0jw_idx_0 ) ;
muDoubleScalarSinCos ( rtB . gt3gymd154 [ 1 ] , & mfkf5g0cet_idx_1 , &
hp3vnvb34m_idx_1 ) ; muDoubleScalarSinCos ( rtB . gt3gymd154 [ 0 ] , &
mfkf5g0cet_idx_2 , & hp3vnvb34m_idx_2 ) ; hvlby4ocab [ 8 ] = hp3vnvb34m_idx_1
* hp3vnvb34m_idx_2 ; hvlby4ocab [ 7 ] = hp3vnvb34m_idx_1 * mfkf5g0cet_idx_2 ;
hvlby4ocab [ 6 ] = - mfkf5g0cet_idx_1 ; hvlby4ocab [ 5 ] = mfkf5g0cet_idx_1 *
hp3vnvb34m_idx_2 * prsndtjjt2 - do2fmqm0jw_idx_0 * mfkf5g0cet_idx_2 ;
hvlby4ocab [ 4 ] = mfkf5g0cet_idx_1 * mfkf5g0cet_idx_2 * prsndtjjt2 +
do2fmqm0jw_idx_0 * hp3vnvb34m_idx_2 ; hvlby4ocab [ 3 ] = prsndtjjt2 *
hp3vnvb34m_idx_1 ; hvlby4ocab [ 2 ] = mfkf5g0cet_idx_1 * hp3vnvb34m_idx_2 *
do2fmqm0jw_idx_0 + prsndtjjt2 * mfkf5g0cet_idx_2 ; hvlby4ocab [ 1 ] =
mfkf5g0cet_idx_1 * mfkf5g0cet_idx_2 * do2fmqm0jw_idx_0 - prsndtjjt2 *
hp3vnvb34m_idx_2 ; hvlby4ocab [ 0 ] = do2fmqm0jw_idx_0 * hp3vnvb34m_idx_1 ;
ky1lxji0nf = ( rtB . dohtax3vu3 [ 1 ] * rtB . pr1vt54ko4 [ 2 ] - rtB .
pr1vt54ko4 [ 1 ] * rtB . dohtax3vu3 [ 2 ] ) + rtB . li5x4km43d [ 0 ] ; tmp_m
= ( rtB . pr1vt54ko4 [ 0 ] * rtB . dohtax3vu3 [ 2 ] - rtB . dohtax3vu3 [ 0 ]
* rtB . pr1vt54ko4 [ 2 ] ) + rtB . li5x4km43d [ 1 ] ; mfkf5g0cet_idx_2 = (
rtB . dohtax3vu3 [ 0 ] * rtB . pr1vt54ko4 [ 1 ] - rtB . pr1vt54ko4 [ 0 ] *
rtB . dohtax3vu3 [ 1 ] ) + rtB . li5x4km43d [ 2 ] ; for ( i = 0 ; i < 3 ; i
++ ) { frac_kh [ i ] = ( hvlby4ocab [ 3 * i + 1 ] * tmp_m + hvlby4ocab [ 3 *
i ] * ky1lxji0nf ) + hvlby4ocab [ 3 * i + 2 ] * mfkf5g0cet_idx_2 ; }
prsndtjjt2 = - frac_kh [ 2 ] ; } else { prsndtjjt2 = rtP .
Constant_Value_o1yp2gl00i ; } rtB . lpr3engkn0 = rtP .
Constant1_Value_dgi3p5u40k * prsndtjjt2 ; rtB . adxfu05snb = rtB . llwqqnw3ke
+ rtB . lpr3engkn0 ; if ( rtB . adxfu05snb > rtP .
Saturation_UpperSat_hpioqrnjvm ) { rtB . mfsumfb52o = rtP .
Saturation_UpperSat_hpioqrnjvm ; } else if ( rtB . adxfu05snb < rtP .
Saturation_LowerSat_ckp25ja5tp ) { rtB . mfsumfb52o = rtP .
Saturation_LowerSat_ckp25ja5tp ; } else { rtB . mfsumfb52o = rtB . adxfu05snb
; } muDoubleScalarSinCos ( nhudhta0yo [ 0 ] , & a5zxkwaluu [ 0 ] , &
cuwl4zp4yw [ 0 ] ) ; muDoubleScalarSinCos ( nhudhta0yo [ 1 ] , & a5zxkwaluu [
1 ] , & cuwl4zp4yw [ 1 ] ) ; muDoubleScalarSinCos ( nhudhta0yo [ 2 ] , &
a5zxkwaluu [ 2 ] , & cuwl4zp4yw [ 2 ] ) ; hvlby4ocab [ 0 ] = cuwl4zp4yw [ 0 ]
* cuwl4zp4yw [ 1 ] ; hvlby4ocab [ 1 ] = a5zxkwaluu [ 1 ] * a5zxkwaluu [ 2 ] *
cuwl4zp4yw [ 0 ] - a5zxkwaluu [ 0 ] * cuwl4zp4yw [ 2 ] ; hvlby4ocab [ 2 ] =
a5zxkwaluu [ 1 ] * cuwl4zp4yw [ 2 ] * cuwl4zp4yw [ 0 ] + a5zxkwaluu [ 0 ] *
a5zxkwaluu [ 2 ] ; hvlby4ocab [ 3 ] = a5zxkwaluu [ 0 ] * cuwl4zp4yw [ 1 ] ;
hvlby4ocab [ 4 ] = a5zxkwaluu [ 1 ] * a5zxkwaluu [ 2 ] * a5zxkwaluu [ 0 ] +
cuwl4zp4yw [ 0 ] * cuwl4zp4yw [ 2 ] ; hvlby4ocab [ 5 ] = a5zxkwaluu [ 1 ] *
cuwl4zp4yw [ 2 ] * a5zxkwaluu [ 0 ] - cuwl4zp4yw [ 0 ] * a5zxkwaluu [ 2 ] ;
hvlby4ocab [ 6 ] = - a5zxkwaluu [ 1 ] ; hvlby4ocab [ 7 ] = cuwl4zp4yw [ 1 ] *
a5zxkwaluu [ 2 ] ; hvlby4ocab [ 8 ] = cuwl4zp4yw [ 1 ] * cuwl4zp4yw [ 2 ] ;
prsndtjjt2 = rtB . njlxqs1uc4 [ 1 ] ; do2fmqm0jw_idx_0 = rtB . njlxqs1uc4 [ 0
] ; ky1lxji0nf = rtB . njlxqs1uc4 [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) {
j4ckedbbex [ i ] = ( ( hvlby4ocab [ 3 * i + 1 ] * prsndtjjt2 + hvlby4ocab [ 3
* i ] * do2fmqm0jw_idx_0 ) + hvlby4ocab [ 3 * i + 2 ] * ky1lxji0nf ) + rtB .
exyupufjt5 [ i ] ; } rtB . ibkkavp3uy = rtP . ground_alt - j4ckedbbex [ 2 ] ;
if ( rtB . ibkkavp3uy > rtP . Switch_Threshold_nwgyj0aeyx ) { rtB .
fvsr3tltfl = rtP . Constant1_Value_fad3jx5usw ; } else { rtB . fvsr3tltfl =
rtP . Constant_Value_bmpfzxx1ux ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . k002wprevb [ 0 ] = rtDW . ie2l444zba [ 0 ] ; rtB . k002wprevb [ 1 ] =
rtDW . ie2l444zba [ 1 ] ; rtB . k002wprevb [ 2 ] = rtDW . ie2l444zba [ 2 ] ;
} rtB . leuhdrxpbe . jr3yr4ixei [ 0 ] = rtB . k002wprevb [ 0 ] ; rtB .
leuhdrxpbe . jr3yr4ixei [ 1 ] = rtB . k002wprevb [ 1 ] ; rtB . leuhdrxpbe .
jr3yr4ixei [ 2 ] = rtB . k002wprevb [ 2 ] ; pm13c03kzl ( j4ckedbbex , rtB .
fvsr3tltfl , & rtB . leuhdrxpbe , & rtDW . leuhdrxpbe ) ; if ( rtB .
fvsr3tltfl ) { tmp_m = rtB . leuhdrxpbe . ggmvjtadg3 [ 2 ] - j4ckedbbex [ 2 ]
; } else { tmp_m = rtP . Constant_Value_feb2wg5gid ; } ky1lxji0nf = tmp_m +
rtP . Constant2_Value_hhw30thswa ; if ( ky1lxji0nf > rtP .
Saturation1_UpperSat_jujzsatqjs ) { ky1lxji0nf = rtP .
Saturation1_UpperSat_jujzsatqjs ; } else if ( ky1lxji0nf < rtP .
Saturation1_LowerSat_ifds41vj3d ) { ky1lxji0nf = rtP .
Saturation1_LowerSat_ifds41vj3d ; } rtB . dwtsbon1wj = ky1lxji0nf * rtP .
Constant_Value_ivz01hdudw ; if ( rtB . fvsr3tltfl ) { muDoubleScalarSinCos (
rtP . Constant1_Value_f4dk2n3412 , & prsndtjjt2 , & do2fmqm0jw_idx_0 ) ;
muDoubleScalarSinCos ( rtB . gt3gymd154 [ 1 ] , & pbzebb1cbu_idx_1 , &
dmol4f0gb0_idx_1 ) ; muDoubleScalarSinCos ( rtB . gt3gymd154 [ 0 ] , &
pbzebb1cbu_idx_2 , & dmol4f0gb0_idx_2 ) ; hvlby4ocab [ 8 ] = dmol4f0gb0_idx_1
* dmol4f0gb0_idx_2 ; hvlby4ocab [ 7 ] = dmol4f0gb0_idx_1 * pbzebb1cbu_idx_2 ;
hvlby4ocab [ 6 ] = - pbzebb1cbu_idx_1 ; hvlby4ocab [ 5 ] = pbzebb1cbu_idx_1 *
dmol4f0gb0_idx_2 * prsndtjjt2 - do2fmqm0jw_idx_0 * pbzebb1cbu_idx_2 ;
hvlby4ocab [ 4 ] = pbzebb1cbu_idx_1 * pbzebb1cbu_idx_2 * prsndtjjt2 +
do2fmqm0jw_idx_0 * dmol4f0gb0_idx_2 ; hvlby4ocab [ 3 ] = prsndtjjt2 *
dmol4f0gb0_idx_1 ; hvlby4ocab [ 2 ] = pbzebb1cbu_idx_1 * dmol4f0gb0_idx_2 *
do2fmqm0jw_idx_0 + prsndtjjt2 * pbzebb1cbu_idx_2 ; hvlby4ocab [ 1 ] =
pbzebb1cbu_idx_1 * pbzebb1cbu_idx_2 * do2fmqm0jw_idx_0 - prsndtjjt2 *
dmol4f0gb0_idx_2 ; hvlby4ocab [ 0 ] = do2fmqm0jw_idx_0 * dmol4f0gb0_idx_1 ;
ky1lxji0nf = ( rtB . dohtax3vu3 [ 1 ] * rtB . njlxqs1uc4 [ 2 ] - rtB .
njlxqs1uc4 [ 1 ] * rtB . dohtax3vu3 [ 2 ] ) + rtB . li5x4km43d [ 0 ] ; tmp_m
= ( rtB . njlxqs1uc4 [ 0 ] * rtB . dohtax3vu3 [ 2 ] - rtB . dohtax3vu3 [ 0 ]
* rtB . njlxqs1uc4 [ 2 ] ) + rtB . li5x4km43d [ 1 ] ; mfkf5g0cet_idx_2 = (
rtB . dohtax3vu3 [ 0 ] * rtB . njlxqs1uc4 [ 1 ] - rtB . njlxqs1uc4 [ 0 ] *
rtB . dohtax3vu3 [ 1 ] ) + rtB . li5x4km43d [ 2 ] ; for ( i = 0 ; i < 3 ; i
++ ) { frac_kh [ i ] = ( hvlby4ocab [ 3 * i + 1 ] * tmp_m + hvlby4ocab [ 3 *
i ] * ky1lxji0nf ) + hvlby4ocab [ 3 * i + 2 ] * mfkf5g0cet_idx_2 ; }
prsndtjjt2 = - frac_kh [ 2 ] ; } else { prsndtjjt2 = rtP .
Constant_Value_feb2wg5gid ; } rtB . g2lkzpk1cd = rtP .
Constant1_Value_nw1qma1fjc * prsndtjjt2 ; rtB . o3f4ir0mnt = rtB . dwtsbon1wj
+ rtB . g2lkzpk1cd ; if ( rtB . o3f4ir0mnt > rtP .
Saturation_UpperSat_n2gmlqdobk ) { rtB . phhcl0h52y = rtP .
Saturation_UpperSat_n2gmlqdobk ; } else if ( rtB . o3f4ir0mnt < rtP .
Saturation_LowerSat_egflfzvuqx ) { rtB . phhcl0h52y = rtP .
Saturation_LowerSat_egflfzvuqx ; } else { rtB . phhcl0h52y = rtB . o3f4ir0mnt
; } a5zxkwaluu [ 2 ] = rtB . mfsumfb52o + rtB . phhcl0h52y ; prsndtjjt2 = rtP
. FrictionCoefficient_Gain * muDoubleScalarAbs ( a5zxkwaluu [ 2 ] ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . cmce4od5nu = rtP .
Constant1_Value_aeivuiuwhs * rtB . j3t4wyjy41 [ 4 ] ; } if ( ! ( rtB .
cmce4od5nu > prsndtjjt2 ) ) { if ( rtB . cmce4od5nu < - prsndtjjt2 ) {
prsndtjjt2 = - prsndtjjt2 ; } else { prsndtjjt2 = rtB . cmce4od5nu ; } }
do2fmqm0jw_idx_0 = rtP . FrictionCoefficient_Gain_bld3rumxab *
muDoubleScalarAbs ( a5zxkwaluu [ 2 ] ) ; if ( rtB . h5anqi052g || rtB .
fvsr3tltfl ) { tmp_m = - rtB . li5x4km43d [ 1 ] ; } else { tmp_m = rtP .
Constant_Value_ph3kv45jlz ; } e12efcqisd = rtP . Constant1_Value_crvf1ymqjc *
tmp_m ; if ( ! ( e12efcqisd > do2fmqm0jw_idx_0 ) ) { if ( e12efcqisd < -
do2fmqm0jw_idx_0 ) { do2fmqm0jw_idx_0 = - do2fmqm0jw_idx_0 ; } else {
do2fmqm0jw_idx_0 = e12efcqisd ; } } muDoubleScalarSinCos ( nhudhta0yo [ 0 ] ,
& cuwl4zp4yw [ 0 ] , & lk0wlvwohy [ 0 ] ) ; muDoubleScalarSinCos ( nhudhta0yo
[ 1 ] , & cuwl4zp4yw [ 1 ] , & lk0wlvwohy [ 1 ] ) ; muDoubleScalarSinCos (
nhudhta0yo [ 2 ] , & cuwl4zp4yw [ 2 ] , & lk0wlvwohy [ 2 ] ) ; hvlby4ocab [ 0
] = lk0wlvwohy [ 0 ] * lk0wlvwohy [ 1 ] ; hvlby4ocab [ 1 ] = cuwl4zp4yw [ 1 ]
* cuwl4zp4yw [ 2 ] * lk0wlvwohy [ 0 ] - cuwl4zp4yw [ 0 ] * lk0wlvwohy [ 2 ] ;
hvlby4ocab [ 2 ] = cuwl4zp4yw [ 1 ] * lk0wlvwohy [ 2 ] * lk0wlvwohy [ 0 ] +
cuwl4zp4yw [ 0 ] * cuwl4zp4yw [ 2 ] ; hvlby4ocab [ 3 ] = cuwl4zp4yw [ 0 ] *
lk0wlvwohy [ 1 ] ; hvlby4ocab [ 4 ] = cuwl4zp4yw [ 1 ] * cuwl4zp4yw [ 2 ] *
cuwl4zp4yw [ 0 ] + lk0wlvwohy [ 0 ] * lk0wlvwohy [ 2 ] ; hvlby4ocab [ 5 ] =
cuwl4zp4yw [ 1 ] * lk0wlvwohy [ 2 ] * cuwl4zp4yw [ 0 ] - lk0wlvwohy [ 0 ] *
cuwl4zp4yw [ 2 ] ; hvlby4ocab [ 6 ] = - cuwl4zp4yw [ 1 ] ; hvlby4ocab [ 7 ] =
lk0wlvwohy [ 1 ] * cuwl4zp4yw [ 2 ] ; hvlby4ocab [ 8 ] = lk0wlvwohy [ 1 ] *
lk0wlvwohy [ 2 ] ; pbzebb1cbu_idx_1 = rtB . mythzqzjez [ 1 ] ;
dmol4f0gb0_idx_1 = rtB . mythzqzjez [ 0 ] ; pbzebb1cbu_idx_2 = rtB .
mythzqzjez [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { egh4jyhxcm [ i ] = ( (
hvlby4ocab [ 3 * i + 1 ] * pbzebb1cbu_idx_1 + hvlby4ocab [ 3 * i ] *
dmol4f0gb0_idx_1 ) + hvlby4ocab [ 3 * i + 2 ] * pbzebb1cbu_idx_2 ) + rtB .
exyupufjt5 [ i ] ; } rtB . cvpaunpk1i = rtP . ground_alt - egh4jyhxcm [ 2 ] ;
if ( rtB . cvpaunpk1i > rtP . Switch_Threshold_kslqyxqwsc ) { rtB .
dzk03qgr1o = rtP . Constant1_Value_apy2wpsmee ; } else { rtB . dzk03qgr1o =
rtP . Constant_Value_hagifheq3t ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtB . kra5wvotxw [ 0 ] = rtDW . fr2fpc1qxz [ 0 ] ; rtB . kra5wvotxw [ 1 ] =
rtDW . fr2fpc1qxz [ 1 ] ; rtB . kra5wvotxw [ 2 ] = rtDW . fr2fpc1qxz [ 2 ] ;
} rtB . csf3emrtxr . jr3yr4ixei [ 0 ] = rtB . kra5wvotxw [ 0 ] ; rtB .
csf3emrtxr . jr3yr4ixei [ 1 ] = rtB . kra5wvotxw [ 1 ] ; rtB . csf3emrtxr .
jr3yr4ixei [ 2 ] = rtB . kra5wvotxw [ 2 ] ; pm13c03kzl ( egh4jyhxcm , rtB .
dzk03qgr1o , & rtB . csf3emrtxr , & rtDW . csf3emrtxr ) ; if ( rtB .
dzk03qgr1o ) { tmp_m = rtB . csf3emrtxr . ggmvjtadg3 [ 2 ] - egh4jyhxcm [ 2 ]
; } else { tmp_m = rtP . Constant_Value_aqtgynqvul ; } ky1lxji0nf = tmp_m +
rtP . Constant2_Value_er0w5mtd4j ; if ( ky1lxji0nf > rtP .
Saturation1_UpperSat_bgrqxpsgy2 ) { ky1lxji0nf = rtP .
Saturation1_UpperSat_bgrqxpsgy2 ; } else if ( ky1lxji0nf < rtP .
Saturation1_LowerSat_mtmmhddwjb ) { ky1lxji0nf = rtP .
Saturation1_LowerSat_mtmmhddwjb ; } rtB . h1v0fki4wd = ky1lxji0nf * rtP .
Constant_Value_gptvvpedc0 ; if ( rtB . dzk03qgr1o ) { muDoubleScalarSinCos (
rtP . Constant1_Value_jtm4r5yj4j , & jgywcuuufn [ 0 ] , & pbzebb1cbu_idx_1 )
; muDoubleScalarSinCos ( rtB . gt3gymd154 [ 1 ] , & jgywcuuufn [ 1 ] , &
jgzcqdfrmy_idx_1 ) ; muDoubleScalarSinCos ( rtB . gt3gymd154 [ 0 ] , &
jgywcuuufn [ 2 ] , & jgzcqdfrmy_idx_2 ) ; hvlby4ocab [ 8 ] = jgzcqdfrmy_idx_1
* jgzcqdfrmy_idx_2 ; hvlby4ocab [ 7 ] = jgzcqdfrmy_idx_1 * jgywcuuufn [ 2 ] ;
hvlby4ocab [ 6 ] = - jgywcuuufn [ 1 ] ; hvlby4ocab [ 5 ] = jgywcuuufn [ 1 ] *
jgzcqdfrmy_idx_2 * jgywcuuufn [ 0 ] - pbzebb1cbu_idx_1 * jgywcuuufn [ 2 ] ;
hvlby4ocab [ 4 ] = jgywcuuufn [ 1 ] * jgywcuuufn [ 2 ] * jgywcuuufn [ 0 ] +
pbzebb1cbu_idx_1 * jgzcqdfrmy_idx_2 ; hvlby4ocab [ 3 ] = jgywcuuufn [ 0 ] *
jgzcqdfrmy_idx_1 ; hvlby4ocab [ 2 ] = jgywcuuufn [ 1 ] * jgzcqdfrmy_idx_2 *
pbzebb1cbu_idx_1 + jgywcuuufn [ 0 ] * jgywcuuufn [ 2 ] ; hvlby4ocab [ 1 ] =
jgywcuuufn [ 1 ] * jgywcuuufn [ 2 ] * pbzebb1cbu_idx_1 - jgywcuuufn [ 0 ] *
jgzcqdfrmy_idx_2 ; hvlby4ocab [ 0 ] = pbzebb1cbu_idx_1 * jgzcqdfrmy_idx_1 ;
ky1lxji0nf = ( rtB . dohtax3vu3 [ 1 ] * rtB . mythzqzjez [ 2 ] - rtB .
mythzqzjez [ 1 ] * rtB . dohtax3vu3 [ 2 ] ) + rtB . li5x4km43d [ 0 ] ; tmp_m
= ( rtB . mythzqzjez [ 0 ] * rtB . dohtax3vu3 [ 2 ] - rtB . dohtax3vu3 [ 0 ]
* rtB . mythzqzjez [ 2 ] ) + rtB . li5x4km43d [ 1 ] ; mfkf5g0cet_idx_2 = (
rtB . dohtax3vu3 [ 0 ] * rtB . mythzqzjez [ 1 ] - rtB . mythzqzjez [ 0 ] *
rtB . dohtax3vu3 [ 1 ] ) + rtB . li5x4km43d [ 2 ] ; for ( i = 0 ; i < 3 ; i
++ ) { frac_kh [ i ] = ( hvlby4ocab [ 3 * i + 1 ] * tmp_m + hvlby4ocab [ 3 *
i ] * ky1lxji0nf ) + hvlby4ocab [ 3 * i + 2 ] * mfkf5g0cet_idx_2 ; }
e12efcqisd = - frac_kh [ 2 ] ; } else { e12efcqisd = rtP .
Constant_Value_aqtgynqvul ; } rtB . atski0fwo1 = rtP .
Constant1_Value_es2hmwpsih * e12efcqisd ; rtB . pzrd4nwhsl = rtB . h1v0fki4wd
+ rtB . atski0fwo1 ; if ( rtB . pzrd4nwhsl > rtP .
Saturation_UpperSat_fkspttvlxs ) { rtB . hsrt1ciq4i = rtP .
Saturation_UpperSat_fkspttvlxs ; } else if ( rtB . pzrd4nwhsl < rtP .
Saturation_LowerSat_ihlfa0mqdb ) { rtB . hsrt1ciq4i = rtP .
Saturation_LowerSat_ihlfa0mqdb ; } else { rtB . hsrt1ciq4i = rtB . pzrd4nwhsl
; } ky1lxji0nf = rtP . FrictionCoefficient_Gain_jiuksux40s *
muDoubleScalarAbs ( rtB . hsrt1ciq4i ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ rtB . gmov3gnpox = rtP . Gain_Gain_cssolhvy5w * rtB . ekmklzxfox [ 3 ] ; }
if ( rtB . dzk03qgr1o ) { e12efcqisd = rtB . gmov3gnpox ; } else { e12efcqisd
= rtP . Constant1_Value_po2h1uw5ro ; } if ( ! ( e12efcqisd > ky1lxji0nf ) ) {
if ( e12efcqisd < - ky1lxji0nf ) { ky1lxji0nf = - ky1lxji0nf ; } else {
ky1lxji0nf = e12efcqisd ; } } jgzcqdfrmy_idx_1 = rtB . dohtax3vu3 [ 1 ] ;
pbzebb1cbu_idx_1 = rtB . dohtax3vu3 [ 0 ] ; jgzcqdfrmy_idx_2 = rtB .
dohtax3vu3 [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { lk0wlvwohy [ i ] = ( rtB .
pchtyrudar [ i + 3 ] * jgzcqdfrmy_idx_1 + rtB . pchtyrudar [ i ] *
pbzebb1cbu_idx_1 ) + rtB . pchtyrudar [ i + 6 ] * jgzcqdfrmy_idx_2 ; }
cuwl4zp4yw [ 0 ] = rtB . dohtax3vu3 [ 1 ] * lk0wlvwohy [ 2 ] ; cuwl4zp4yw [ 1
] = lk0wlvwohy [ 0 ] * rtB . dohtax3vu3 [ 2 ] ; cuwl4zp4yw [ 2 ] = rtB .
dohtax3vu3 [ 0 ] * lk0wlvwohy [ 1 ] ; jgywcuuufn [ 0 ] = lk0wlvwohy [ 1 ] *
rtB . dohtax3vu3 [ 2 ] ; jgywcuuufn [ 1 ] = rtB . dohtax3vu3 [ 0 ] *
lk0wlvwohy [ 2 ] ; jgywcuuufn [ 2 ] = lk0wlvwohy [ 0 ] * rtB . dohtax3vu3 [ 1
] ; frac_kh [ 0 ] = ( ( ( ( ( ( rtB . higayyxcv3 - rtB . e32n1qjlbz [ 2 ] *
do2fmqm0jw_idx_0 ) + ( rtB . dkodtfhso0 - rtB . l2pt0kefdc [ 2 ] * ky1lxji0nf
) ) + ( rtB . awnwv0frb5 [ 1 ] * rtB . mfsumfb52o - rtB . jmxba5skz5 ) ) + (
rtB . cdxkdrlzzm [ 1 ] * rtB . phhcl0h52y - rtB . pmom2ene5w ) ) + ( rtB .
jygnbcsqf1 [ 1 ] * rtB . hsrt1ciq4i - rtB . grblrau4l1 ) ) + ( frac_d0 [ 0 ]
+ rtP . Constant_Value_jax04gsciy ) ) + rtB . d1dja0jwhm [ 0 ] ; frac_kh [ 1
] = ( ( ( ( ( ( rtB . e32n1qjlbz [ 2 ] * prsndtjjt2 - rtB . djejdif2w5 ) + (
rtB . lw0kvssqse - rtB . nos3a2bbnv ) ) + ( rtB . fnmgllmgqx - rtB .
awnwv0frb5 [ 0 ] * rtB . mfsumfb52o ) ) + ( rtB . hqi2kczfkw - rtB .
cdxkdrlzzm [ 0 ] * rtB . phhcl0h52y ) ) + ( rtB . ih10mokqjs - rtB .
jygnbcsqf1 [ 0 ] * rtB . hsrt1ciq4i ) ) + ( frac_d0 [ 1 ] + rtP .
Constant_Value_jax04gsciy ) ) + rtB . d1dja0jwhm [ 1 ] ; frac_kh [ 2 ] = ( (
( ( ( ( rtB . e32n1qjlbz [ 0 ] * do2fmqm0jw_idx_0 - rtB . e32n1qjlbz [ 1 ] *
prsndtjjt2 ) + ( rtB . l2pt0kefdc [ 0 ] * ky1lxji0nf - rtB . lhydxe5abe ) ) +
( rtB . lrtymnw4xi - rtB . fqvqdt4rd2 ) ) + ( rtB . ftrxuf0i4a - rtB .
lpx2s5ac0u ) ) + ( rtB . f1a2rfeuz1 - rtB . g344blsojt ) ) + ( frac_d0 [ 2 ]
+ rtP . Constant_Value_jax04gsciy ) ) + rtB . d1dja0jwhm [ 2 ] ;
jgzcqdfrmy_idx_1 = rtB . dohtax3vu3 [ 1 ] ; pbzebb1cbu_idx_1 = rtB .
dohtax3vu3 [ 0 ] ; jgzcqdfrmy_idx_2 = rtB . dohtax3vu3 [ 2 ] ; for ( i = 0 ;
i < 3 ; i ++ ) { a5zxkwaluu [ i ] = ( frac_kh [ i ] - ( ( rtB . k0wfvnkgwy [
i + 3 ] * jgzcqdfrmy_idx_1 + rtB . k0wfvnkgwy [ i ] * pbzebb1cbu_idx_1 ) +
rtB . k0wfvnkgwy [ i + 6 ] * jgzcqdfrmy_idx_2 ) ) - ( cuwl4zp4yw [ i ] -
jgywcuuufn [ i ] ) ; } rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( a5zxkwaluu , rtB
. armozr15x5 , jgywcuuufn ) ; rtB . onu4r5xewk [ 0 ] = jgywcuuufn [ 0 ] ; rtB
. onu4r5xewk [ 1 ] = jgywcuuufn [ 1 ] ; rtB . onu4r5xewk [ 2 ] = jgywcuuufn [
2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } for ( i = 0 ; i < 21 ; i ++ )
{ hg2rsg5czq [ i ] = rtB . ayq52soaqwz [ i ] ; } for ( jdx = 0 ; jdx < 3 ;
jdx ++ ) { e12efcqisd = - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { e12efcqisd +=
hg2rsg5czq [ i * 3 + jdx ] ; } jgywcuuufn [ jdx ] = e12efcqisd ; }
a4viish00u_idx_0 = ( real32_T ) jgywcuuufn [ 0 ] ; a4viish00u_idx_1 = (
real32_T ) jgywcuuufn [ 1 ] ; a4viish00u_idx_2 = ( real32_T ) jgywcuuufn [ 2
] ; for ( i = 0 ; i < 21 ; i ++ ) { hg2rsg5czq [ i ] = rtB . ayq52soaqw [ i ]
; } for ( jdx = 0 ; jdx < 3 ; jdx ++ ) { e12efcqisd = - 0.0 ; for ( i = 0 ; i
< 7 ; i ++ ) { e12efcqisd += hg2rsg5czq [ i * 3 + jdx ] ; } jgywcuuufn [ jdx
] = e12efcqisd ; } mmxlym3ls1_idx_0 = ( real32_T ) jgywcuuufn [ 0 ] ;
mmxlym3ls1_idx_1 = ( real32_T ) jgywcuuufn [ 1 ] ; mmxlym3ls1_idx_2 = (
real32_T ) jgywcuuufn [ 2 ] ; for ( i = 0 ; i < 48 ; i ++ ) { ftphjt5uz2 [ i
] = rtB . o0icr3ysdn [ i ] ; } for ( jdx = 0 ; jdx < 3 ; jdx ++ ) {
e12efcqisd = - 0.0 ; for ( i = 0 ; i < 16 ; i ++ ) { e12efcqisd += ftphjt5uz2
[ i * 3 + jdx ] ; } jgywcuuufn [ jdx ] = e12efcqisd ; } muDoubleScalarSinCos
( ( real32_T ) rtB . hmn4gg1bt5 , & jgzcqdfrmy_idx_1 , & pbzebb1cbu_idx_1 ) ;
muDoubleScalarSinCos ( ( real32_T ) rtB . aeyzgmp4rb , & hndnwewn14_idx_1 , &
n1fwtevrzf_idx_1 ) ; hvlby4ocab [ 0 ] = pbzebb1cbu_idx_1 * n1fwtevrzf_idx_1 ;
hvlby4ocab [ 1 ] = - ( pbzebb1cbu_idx_1 * hndnwewn14_idx_1 ) ; hvlby4ocab [ 2
] = - jgzcqdfrmy_idx_1 ; hvlby4ocab [ 3 ] = hndnwewn14_idx_1 ; hvlby4ocab [ 4
] = n1fwtevrzf_idx_1 ; hvlby4ocab [ 5 ] = rtP . Constant_Value_ootamvdz1c ;
hvlby4ocab [ 6 ] = jgzcqdfrmy_idx_1 * n1fwtevrzf_idx_1 ; hvlby4ocab [ 7 ] = -
( jgzcqdfrmy_idx_1 * hndnwewn14_idx_1 ) ; hvlby4ocab [ 8 ] = pbzebb1cbu_idx_1
; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtB . ehjp343jmw = rtP .
gear_drag_Value * rtB . nn0j0nwtai [ 19 ] + rtP . extra_drag_Value ; } tmp_i
= - ( real32_T ) ( rtP . S / 2.0 * ( rtB . ehjp343jmw * ( real32_T ) rtB .
odhuccln2g ) * ( ( real32_T ) rtB . hwfjzaa0nm * ( real32_T ) rtB .
hwfjzaa0nm ) ) ; a4viish00u_p [ 0 ] = ( ( a4viish00u_idx_0 + mmxlym3ls1_idx_0
) + ( real32_T ) jgywcuuufn [ 0 ] ) + g0uuf55mpg [ 0 ] ; a4viish00u_p [ 1 ] =
( ( - a4viish00u_idx_1 + mmxlym3ls1_idx_1 ) + ( real32_T ) jgywcuuufn [ 1 ] )
+ g0uuf55mpg [ 1 ] ; a4viish00u_p [ 2 ] = ( ( a4viish00u_idx_2 +
mmxlym3ls1_idx_2 ) + ( real32_T ) jgywcuuufn [ 2 ] ) + g0uuf55mpg [ 2 ] ; for
( jdx = 0 ; jdx < 3 ; jdx ++ ) { rtB . dlawj1hfkq [ jdx ] = ( ( ( real32_T )
hvlby4ocab [ 3 * jdx + 1 ] * rtP . Constant1_Value_b4mc4ixfm2 + ( real32_T )
hvlby4ocab [ 3 * jdx ] * tmp_i ) + ( real32_T ) hvlby4ocab [ 3 * jdx + 2 ] *
rtP . Constant1_Value_b4mc4ixfm2 ) + a4viish00u_p [ jdx ] ; e12efcqisd = -
0.0 ; for ( i = 0 ; i < 12 ; i ++ ) { e12efcqisd += dsccgxajgj [ i * 3 + jdx
] ; } lk0wlvwohy [ jdx ] = e12efcqisd ; muDoubleScalarSinCos ( nhudhta0yo [
jdx ] , & a5zxkwaluu [ jdx ] , & frac_d0 [ jdx ] ) ; } rtB . od11ruf3th [ 0 ]
= frac_d0 [ 0 ] * frac_d0 [ 1 ] ; rtB . od11ruf3th [ 1 ] = a5zxkwaluu [ 1 ] *
a5zxkwaluu [ 2 ] * frac_d0 [ 0 ] - a5zxkwaluu [ 0 ] * frac_d0 [ 2 ] ; rtB .
od11ruf3th [ 2 ] = a5zxkwaluu [ 1 ] * frac_d0 [ 2 ] * frac_d0 [ 0 ] +
a5zxkwaluu [ 0 ] * a5zxkwaluu [ 2 ] ; rtB . od11ruf3th [ 3 ] = a5zxkwaluu [ 0
] * frac_d0 [ 1 ] ; rtB . od11ruf3th [ 4 ] = a5zxkwaluu [ 1 ] * a5zxkwaluu [
2 ] * a5zxkwaluu [ 0 ] + frac_d0 [ 0 ] * frac_d0 [ 2 ] ; rtB . od11ruf3th [ 5
] = a5zxkwaluu [ 1 ] * frac_d0 [ 2 ] * a5zxkwaluu [ 0 ] - frac_d0 [ 0 ] *
a5zxkwaluu [ 2 ] ; rtB . od11ruf3th [ 6 ] = - a5zxkwaluu [ 1 ] ; rtB .
od11ruf3th [ 7 ] = frac_d0 [ 1 ] * a5zxkwaluu [ 2 ] ; rtB . od11ruf3th [ 8 ]
= frac_d0 [ 1 ] * frac_d0 [ 2 ] ; rtB . oaagntandl = rtX . oqemwaxlko [ 0 ] ;
cuwl4zp4yw [ 0 ] = rtB . oaagntandl ; cuwl4zp4yw [ 1 ] = rtP .
Constant_Value_jax04gsciy ; cuwl4zp4yw [ 2 ] = rtP .
Constant_Value_jax04gsciy ; a5zxkwaluu [ 0 ] = ( prsndtjjt2 + rtP .
Constant3_Value_gdofiqtr3v ) + rtB . on14h4dmvl ; a5zxkwaluu [ 1 ] = (
do2fmqm0jw_idx_0 + ky1lxji0nf ) + rtB . on14h4dmvl ; a5zxkwaluu [ 2 ] = ( rtP
. Constant2_Value_p0sma1ifq3 + rtP . Constant3_Value_gdofiqtr3v ) + rtB .
mfsumfb52o ; frac_kh [ 0 ] = rtB . ffkpsdx0zr ; frac_kh [ 1 ] = rtB .
ffkpsdx0zr ; frac_kh [ 2 ] = rtB . phhcl0h52y ; nhudhta0yo [ 0 ] = rtB .
lwvqxcae23 ; nhudhta0yo [ 1 ] = rtB . lwvqxcae23 ; nhudhta0yo [ 2 ] = rtB .
hsrt1ciq4i ; jgywcuuufn [ 0 ] = mohryahy3p_idx_1 * rtB . dohtax3vu3 [ 2 ] -
rtB . dohtax3vu3 [ 1 ] * mohryahy3p_idx_2 ; jgywcuuufn [ 1 ] = rtB .
dohtax3vu3 [ 0 ] * mohryahy3p_idx_2 - mohryahy3p_idx_0 * rtB . dohtax3vu3 [ 2
] ; jgywcuuufn [ 2 ] = mohryahy3p_idx_0 * rtB . dohtax3vu3 [ 1 ] - rtB .
dohtax3vu3 [ 0 ] * mohryahy3p_idx_1 ; for ( i = 0 ; i < 3 ; i ++ ) {
jgzcqdfrmy_idx_2 = ( ( ( ( ( ( rtB . od11ruf3th [ i + 3 ] * rtP .
Constant_Value_jkrncbjqj3 + rtB . od11ruf3th [ i ] * rtP .
Constant_Value_jkrncbjqj3 ) + rtB . od11ruf3th [ i + 6 ] * rtB . jemxdtgsel )
+ lk0wlvwohy [ i ] ) + cuwl4zp4yw [ i ] ) + ( ( a5zxkwaluu [ i ] + frac_kh [
i ] ) + nhudhta0yo [ i ] ) ) + rtB . dlawj1hfkq [ i ] ) / rtP . m ; rtB .
p4p4elvfjt [ i ] = jgzcqdfrmy_idx_2 ; rtB . gdwsegs0yn [ i ] =
jgzcqdfrmy_idx_2 + jgywcuuufn [ i ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ } rtB . bznjqb4cys = rtP . Gain_Gain_ay20xvgxq5 * rtB . gt3gymd154 [ 0 ] ;
rtB . hilbxeegf0 = rtP . Gain_Gain_iuh3lzw4i0 * rtB . gt3gymd154 [ 1 ] ; rtB
. p0trwoq5oi = rtP . Gain_Gain_inh0c1mtep * rtB . gt3gymd154 [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . bq0j25ykt3 = muDoubleScalarSqrt (
rtP . Gain_Gain_iso0wdlaw3 * rtB . odhuccln2g ) * rtB . hwfjzaa0nm ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . c5avufipwu = rtP .
Gain_Gain_otfwfmpf50 * rtB . hmn4gg1bt5 ; rtB . iovd14a0zv = rtP .
Gain_Gain_n2lq1m5z15 * rtB . aeyzgmp4rb ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { { if ( rtDW . dzukxciamp .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . dzukxciamp .
AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & khgvdadyv1 [ 0 ] + 0 ) ;
} } { if ( rtDW . oumnpiegvc . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . oumnpiegvc . AQHandles , ssGetTaskTime ( rtS , 2 ) ,
( char * ) & rtB . ge01nkozzs [ 0 ] + 0 ) ; } } { if ( rtDW . kmqxlkx3v2 .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . kmqxlkx3v2 .
AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB . ln5blvjdm3 [ 0 ] +
0 ) ; } } { if ( rtDW . oszdennjt4 . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . oszdennjt4 . AQHandles , ssGetTaskTime ( rtS , 2 ) ,
( char * ) & rtB . atgyr3lfo3 [ 0 ] + 0 ) ; } } { if ( rtDW . glhrtguzli .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . glhrtguzli .
AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB . cfz24gonbx [ 0 ] +
0 ) ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { { if ( rtDW . dzukxciampy . AQHandles && ssGetLogOutput ( rtS )
) { sdiWriteSignal ( rtDW . dzukxciampy . AQHandles , ssGetTaskTime ( rtS , 2
) , ( char * ) & rtB . o0icr3ysdn [ 0 ] + 0 ) ; } } { if ( rtDW .
dzukxciampy4 . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW
. dzukxciampy4 . AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB .
ayq52soaqwz [ 0 ] + 0 ) ; } } { if ( rtDW . dzukxciampy43 . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . dzukxciampy43 . AQHandles
, ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB . ayq52soaqw [ 0 ] + 0 ) ; } }
{ if ( rtDW . dzukxciampy430 . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . dzukxciampy430 . AQHandles , ssGetTaskTime ( rtS , 2
) , ( char * ) & rtB . hmn4gg1bt5 + 0 ) ; } } gotsf53ixb [ 0 ] = rtB .
exyupufjt5 [ 0 ] ; gotsf53ixb [ 3 ] = rtB . gt3gymd154 [ 0 ] ; gotsf53ixb [ 1
] = rtB . exyupufjt5 [ 1 ] ; gotsf53ixb [ 4 ] = rtB . gt3gymd154 [ 1 ] ;
gotsf53ixb [ 2 ] = rtB . exyupufjt5 [ 2 ] ; gotsf53ixb [ 5 ] = rtB .
gt3gymd154 [ 2 ] ; { if ( rtDW . oumnpiegvcp . AQHandles && ssGetLogOutput (
rtS ) ) { sdiWriteSignal ( rtDW . oumnpiegvcp . AQHandles , ssGetTaskTime (
rtS , 2 ) , ( char * ) & gotsf53ixb [ 0 ] + 0 ) ; } } gotsf53ixb [ 0 ] = rtB
. li5x4km43d [ 0 ] ; gotsf53ixb [ 3 ] = rtB . dohtax3vu3 [ 0 ] ; gotsf53ixb [
1 ] = rtB . li5x4km43d [ 1 ] ; gotsf53ixb [ 4 ] = rtB . dohtax3vu3 [ 1 ] ;
gotsf53ixb [ 2 ] = rtB . li5x4km43d [ 2 ] ; gotsf53ixb [ 5 ] = rtB .
dohtax3vu3 [ 2 ] ; { if ( rtDW . kmqxlkx3v2q . AQHandles && ssGetLogOutput (
rtS ) ) { sdiWriteSignal ( rtDW . kmqxlkx3v2q . AQHandles , ssGetTaskTime (
rtS , 2 ) , ( char * ) & gotsf53ixb [ 0 ] + 0 ) ; } } gotsf53ixb [ 0 ] = rtB
. gdwsegs0yn [ 0 ] ; gotsf53ixb [ 3 ] = rtB . onu4r5xewk [ 0 ] ; gotsf53ixb [
1 ] = rtB . gdwsegs0yn [ 1 ] ; gotsf53ixb [ 4 ] = rtB . onu4r5xewk [ 1 ] ;
gotsf53ixb [ 2 ] = rtB . gdwsegs0yn [ 2 ] ; gotsf53ixb [ 5 ] = rtB .
onu4r5xewk [ 2 ] ; { if ( rtDW . oszdennjt4x . AQHandles && ssGetLogOutput (
rtS ) ) { sdiWriteSignal ( rtDW . oszdennjt4x . AQHandles , ssGetTaskTime (
rtS , 2 ) , ( char * ) & gotsf53ixb [ 0 ] + 0 ) ; } } { if ( rtDW .
glhrtguzlib . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
glhrtguzlib . AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB .
aeyzgmp4rb + 0 ) ; } } { if ( rtDW . a01trbqc4k . AQHandles && ssGetLogOutput
( rtS ) ) { sdiWriteSignal ( rtDW . a01trbqc4k . AQHandles , ssGetTaskTime (
rtS , 2 ) , ( char * ) & rtB . hwfjzaa0nm + 0 ) ; } } } muDoubleScalarSinCos
( rtB . gt3gymd154 [ 0 ] , & jgywcuuufn [ 0 ] , & lk0wlvwohy [ 0 ] ) ;
muDoubleScalarSinCos ( rtB . gt3gymd154 [ 1 ] , & jgywcuuufn [ 1 ] , &
lk0wlvwohy [ 1 ] ) ; rtB . fcg44x4aqz [ 0 ] = ( jgywcuuufn [ 0 ] * rtB .
dohtax3vu3 [ 1 ] + lk0wlvwohy [ 0 ] * rtB . dohtax3vu3 [ 2 ] ) * ( jgywcuuufn
[ 1 ] / lk0wlvwohy [ 1 ] ) + rtB . dohtax3vu3 [ 0 ] ; rtB . fcg44x4aqz [ 1 ]
= lk0wlvwohy [ 0 ] * rtB . dohtax3vu3 [ 1 ] - jgywcuuufn [ 0 ] * rtB .
dohtax3vu3 [ 2 ] ; rtB . fcg44x4aqz [ 2 ] = ( jgywcuuufn [ 0 ] * rtB .
dohtax3vu3 [ 1 ] + lk0wlvwohy [ 0 ] * rtB . dohtax3vu3 [ 2 ] ) / lk0wlvwohy [
1 ] ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . ps23iickbr [ i ] = ( rtB .
od11ruf3th [ 3 * i + 1 ] * mohryahy3p_idx_1 + rtB . od11ruf3th [ 3 * i ] *
mohryahy3p_idx_0 ) + rtB . od11ruf3th [ 3 * i + 2 ] * mohryahy3p_idx_2 ; } if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . bkodm3ably = rtP . P0_Gain *
j2olvplitn_idx_0 * lir1dfa45c ; rtB . fbtjhgisvg = muDoubleScalarSqrt ( ( rtB
. li5x4km43d [ 0 ] * rtB . li5x4km43d [ 0 ] + rtB . li5x4km43d [ 1 ] * rtB .
li5x4km43d [ 1 ] ) + rtB . li5x4km43d [ 2 ] * rtB . li5x4km43d [ 2 ] ) ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { memcpy ( & rtB . hgd1a1255d [ 0 ] , & rtDW
. crxd5n2r3l [ 0 ] , 20U * sizeof ( real_T ) ) ; } j2olvplitn_idx_0 = - 0.0 ;
for ( i = 0 ; i < 12 ; i ++ ) { j2olvplitn_idx_0 += gmj3cy4km1 [ i ] ; }
lir1dfa45c = look2_plinlxpw ( rtB . bq0j25ykt3 , rtB . oaagntandl , rtP .
dp_HTU . V_vec , rtP . dp_HTU . T_vec , rtP . dp_HTU . P_grid , rtDW .
nq0rryljq1 , rtP . Plookup_maxIndex , 13U ) ; rtB . hfraqjvvj1 = rtP .
Gain1_Gain_h4hra1gikq * j2olvplitn_idx_0 * rtP . Gain2_Gain_ic5npr3xa1 + rtP
. Gain_Gain_g41sdlhqvv * lir1dfa45c ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
} if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { { if ( rtDW . dzukxciampy430g .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
dzukxciampy430g . AQHandles , ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB .
nhnvabjkuz [ 0 ] + 0 ) ; } } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { { if ( rtDW . hpymvgtvx5 . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . hpymvgtvx5 . AQHandles ,
ssGetTaskTime ( rtS , 2 ) , ( char * ) & rtB . oaagntandl + 0 ) ; } } rtB .
n00gsxq4p1 = look1_plinlcpw ( rtB . nn0j0nwtai [ 18 ] , rtP .
uDLookupTable1_bp01Data , rtP . uDLookupTable1_tableData , & rtDW .
ddr4l0n5i3 , 1U ) ; } j2olvplitn_idx_0 = look1_plinlxpw ( rtB . bq0j25ykt3 ,
rtP . dp_HTU . limits . V_up_lim , rtP . dp_HTU . limits . T_up_lim , & rtDW
. by2jasgm4o , 4U ) ; if ( ! ( rtB . n00gsxq4p1 > j2olvplitn_idx_0 ) ) {
j2olvplitn_idx_0 = look1_plinlxpw ( rtB . bq0j25ykt3 , rtP . dp_HTU . limits
. V_low_lim , rtP . dp_HTU . limits . T_low_lim , & rtDW . daljbq5gtz , 5U )
; if ( ! ( rtB . n00gsxq4p1 < j2olvplitn_idx_0 ) ) { j2olvplitn_idx_0 = rtB .
n00gsxq4p1 ; } } rtB . ixwwzqb4p2 = rtP . LinearSecondOrderActuator_wn_fin *
rtP . LinearSecondOrderActuator_wn_fin * ( j2olvplitn_idx_0 - rtB .
oaagntandl ) - 2.0 * rtP . LinearSecondOrderActuator_z_fin * rtP .
LinearSecondOrderActuator_wn_fin * rtX . oqemwaxlko [ 1 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
for ( i = 0 ; i < 6 ; i ++ ) { j2olvplitn_idx_0 = rtB . nn0j0nwtai [ i ] ;
rtB . dienpmt5lk [ i ] = rtP . Gain_Gain_b0rnnooty0 * j2olvplitn_idx_0 ; rtB
. lyw5uzhlvp [ i ] = rtP . Gain_Gain_lercwvznpd * j2olvplitn_idx_0 ; } } jdx
= 6 ; e12efcqisd = 2.0 * rtP . LinearSecondOrderActuator_z_fin_ag5smfntgf *
rtP . LinearSecondOrderActuator_wn_fin_ilmnm2ylbj ; for ( i = 0 ; i < 6 ; i
++ ) { rtB . pxf22reogn [ i ] = rtX . n5m0nb0nkj [ i ] ; j2olvplitn_idx_0 =
rtX . n5m0nb0nkj [ jdx ] ; jdx ++ ; gotsf53ixb [ i ] = e12efcqisd *
j2olvplitn_idx_0 ; } eavok2n1gr [ 0 ] = rtB . gdwsegs0yn [ 0 ] - rtB .
pxf22reogn [ 0 ] ; eavok2n1gr [ 3 ] = rtB . onu4r5xewk [ 0 ] - rtB .
pxf22reogn [ 3 ] ; eavok2n1gr [ 1 ] = rtB . gdwsegs0yn [ 1 ] - rtB .
pxf22reogn [ 1 ] ; eavok2n1gr [ 4 ] = rtB . onu4r5xewk [ 1 ] - rtB .
pxf22reogn [ 4 ] ; eavok2n1gr [ 2 ] = rtB . gdwsegs0yn [ 2 ] - rtB .
pxf22reogn [ 2 ] ; eavok2n1gr [ 5 ] = rtB . onu4r5xewk [ 2 ] - rtB .
pxf22reogn [ 5 ] ; e12efcqisd = rtP .
LinearSecondOrderActuator_wn_fin_ilmnm2ylbj * rtP .
LinearSecondOrderActuator_wn_fin_ilmnm2ylbj ; jdx = 6 ; for ( i = 0 ; i < 6 ;
i ++ ) { rtB . naaosn4yn2 [ i ] = e12efcqisd * eavok2n1gr [ i ] - gotsf53ixb
[ i ] ; rtB . afhieoseax [ i ] = rtX . c1kooexubz [ i ] ; eavok2n1gr [ i ] =
rtX . c1kooexubz [ jdx ] ; jdx ++ ; } e12efcqisd = 2.0 * rtP .
LinearSecondOrderActuator1_z_fin * rtP . LinearSecondOrderActuator1_wn_fin ;
for ( i = 0 ; i < 6 ; i ++ ) { gotsf53ixb [ i ] = e12efcqisd * eavok2n1gr [ i
] ; } eavok2n1gr [ 0 ] = rtB . li5x4km43d [ 0 ] - rtB . afhieoseax [ 0 ] ;
eavok2n1gr [ 3 ] = rtB . dohtax3vu3 [ 0 ] - rtB . afhieoseax [ 3 ] ;
eavok2n1gr [ 1 ] = rtB . li5x4km43d [ 1 ] - rtB . afhieoseax [ 1 ] ;
eavok2n1gr [ 4 ] = rtB . dohtax3vu3 [ 1 ] - rtB . afhieoseax [ 4 ] ;
eavok2n1gr [ 2 ] = rtB . li5x4km43d [ 2 ] - rtB . afhieoseax [ 2 ] ;
eavok2n1gr [ 5 ] = rtB . dohtax3vu3 [ 2 ] - rtB . afhieoseax [ 5 ] ;
e12efcqisd = rtP . LinearSecondOrderActuator1_wn_fin * rtP .
LinearSecondOrderActuator1_wn_fin ; jdx = 6 ; for ( i = 0 ; i < 6 ; i ++ ) {
rtB . niowrwikj3 [ i ] = e12efcqisd * eavok2n1gr [ i ] - gotsf53ixb [ i ] ;
rtB . gbabd0z3bn [ i ] = rtX . ndpus01ld4 [ i ] ; eavok2n1gr [ i ] = rtX .
ndpus01ld4 [ jdx ] ; jdx ++ ; } e12efcqisd = 2.0 * rtP .
LinearSecondOrderActuator2_z_fin * rtP . LinearSecondOrderActuator2_wn_fin ;
j2olvplitn_idx_0 = rtP . LinearSecondOrderActuator2_wn_fin * rtP .
LinearSecondOrderActuator2_wn_fin ; rtB . jdw5fy5uyh = rtX . bdt2nf5etq [ 0 ]
; rtB . c0rbweqsq1 = rtP . LinearSecondOrderActuator3_wn_fin * rtP .
LinearSecondOrderActuator3_wn_fin * ( rtB . hmn4gg1bt5 - rtB . jdw5fy5uyh ) -
2.0 * rtP . LinearSecondOrderActuator3_z_fin * rtP .
LinearSecondOrderActuator3_wn_fin * rtX . bdt2nf5etq [ 1 ] ; rtB . agnrcu13e2
= rtX . ai1bi54qax [ 0 ] ; rtB . ia0ra0q3ax = rtP .
LinearSecondOrderActuator4_wn_fin * rtP . LinearSecondOrderActuator4_wn_fin *
( rtB . hwfjzaa0nm - rtB . agnrcu13e2 ) - 2.0 * rtP .
LinearSecondOrderActuator4_z_fin * rtP . LinearSecondOrderActuator4_wn_fin *
rtX . ai1bi54qax [ 1 ] ; rtB . l4whzntd2w = rtX . a1z3hbtkhc [ 0 ] ; rtB .
nsqrvbi5rh = rtP . LinearSecondOrderActuator5_wn_fin * rtP .
LinearSecondOrderActuator5_wn_fin * ( rtB . aeyzgmp4rb - rtB . l4whzntd2w ) -
2.0 * rtP . LinearSecondOrderActuator5_z_fin * rtP .
LinearSecondOrderActuator5_wn_fin * rtX . a1z3hbtkhc [ 1 ] ; rtB . kydbwk01f5
= rtX . iugjf2dp5k [ 0 ] ; rtB . g3dy1b3uqu = rtP .
LinearSecondOrderActuator6_wn_fin * rtP . LinearSecondOrderActuator6_wn_fin *
( rtB . bq0j25ykt3 - rtB . kydbwk01f5 ) - 2.0 * rtP .
LinearSecondOrderActuator6_z_fin * rtP . LinearSecondOrderActuator6_wn_fin *
rtX . iugjf2dp5k [ 1 ] ; rtB . hpmq1jfzli [ 0 ] = ( rtB . exyupufjt5 [ 0 ] -
rtB . gbabd0z3bn [ 0 ] ) * j2olvplitn_idx_0 - e12efcqisd * eavok2n1gr [ 0 ] ;
rtB . hpmq1jfzli [ 3 ] = ( rtB . gt3gymd154 [ 0 ] - rtB . gbabd0z3bn [ 3 ] )
* j2olvplitn_idx_0 - e12efcqisd * eavok2n1gr [ 3 ] ; rtB . dkmnirebs0 [ 0 ] =
rtX . kv0bz415kr [ 0 ] ; rtB . hpmq1jfzli [ 1 ] = ( rtB . exyupufjt5 [ 1 ] -
rtB . gbabd0z3bn [ 1 ] ) * j2olvplitn_idx_0 - e12efcqisd * eavok2n1gr [ 1 ] ;
rtB . hpmq1jfzli [ 4 ] = ( rtB . gt3gymd154 [ 1 ] - rtB . gbabd0z3bn [ 4 ] )
* j2olvplitn_idx_0 - e12efcqisd * eavok2n1gr [ 4 ] ; rtB . dkmnirebs0 [ 1 ] =
rtX . kv0bz415kr [ 1 ] ; rtB . hpmq1jfzli [ 2 ] = ( rtB . exyupufjt5 [ 2 ] -
rtB . gbabd0z3bn [ 2 ] ) * j2olvplitn_idx_0 - e12efcqisd * eavok2n1gr [ 2 ] ;
rtB . hpmq1jfzli [ 5 ] = ( rtB . gt3gymd154 [ 2 ] - rtB . gbabd0z3bn [ 5 ] )
* j2olvplitn_idx_0 - e12efcqisd * eavok2n1gr [ 5 ] ; rtB . dkmnirebs0 [ 2 ] =
rtX . kv0bz415kr [ 2 ] ; e12efcqisd = 2.0 * rtP .
LinearSecondOrderActuator7_z_fin * rtP . LinearSecondOrderActuator7_wn_fin ;
j2olvplitn_idx_0 = rtP . LinearSecondOrderActuator7_wn_fin * rtP .
LinearSecondOrderActuator7_wn_fin ; rtB . avgj00fc45 [ 0 ] = ( ga0emsz5x4 [ 0
] - rtB . dkmnirebs0 [ 0 ] ) * j2olvplitn_idx_0 - e12efcqisd * rtX .
kv0bz415kr [ 3 ] ; rtB . eezj4zgsj4 [ 0 ] = rtX . hxqf43szbj [ 0 ] ; rtB .
avgj00fc45 [ 1 ] = ( ga0emsz5x4 [ 1 ] - rtB . dkmnirebs0 [ 1 ] ) *
j2olvplitn_idx_0 - e12efcqisd * rtX . kv0bz415kr [ 4 ] ; rtB . eezj4zgsj4 [ 1
] = rtX . hxqf43szbj [ 1 ] ; rtB . avgj00fc45 [ 2 ] = ( jxoxz3uefs - rtB .
dkmnirebs0 [ 2 ] ) * j2olvplitn_idx_0 - e12efcqisd * rtX . kv0bz415kr [ 5 ] ;
rtB . eezj4zgsj4 [ 2 ] = rtX . hxqf43szbj [ 2 ] ; e12efcqisd = 2.0 * rtP .
LinearSecondOrderActuator8_z_fin * rtP . LinearSecondOrderActuator8_wn_fin ;
j2olvplitn_idx_0 = rtP . LinearSecondOrderActuator8_wn_fin * rtP .
LinearSecondOrderActuator8_wn_fin ; rtB . m1qwau1ibb [ 0 ] = (
ou02bea1mb_idx_0 - rtB . eezj4zgsj4 [ 0 ] ) * j2olvplitn_idx_0 - e12efcqisd *
rtX . hxqf43szbj [ 3 ] ; rtB . m1qwau1ibb [ 1 ] = ( ou02bea1mb_idx_1 - rtB .
eezj4zgsj4 [ 1 ] ) * j2olvplitn_idx_0 - e12efcqisd * rtX . hxqf43szbj [ 4 ] ;
rtB . m1qwau1ibb [ 2 ] = ( hszixujy0p - rtB . eezj4zgsj4 [ 2 ] ) *
j2olvplitn_idx_0 - e12efcqisd * rtX . hxqf43szbj [ 5 ] ; { SimStruct * rts =
ssGetSFunction ( rtS , 2 ) ; { static const char * blockSIDForSFcnLoader =
"UNIFIER:8429" ; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader )
; void ( * sfcnMethodPtr ) ( SimStruct * , int ) = rts -> modelMethods . sFcn
. mdlOutputs . level2 ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } } rtB .
ku55m1jm2d = ssGetT ( rtS ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
af22xidizc = rtDW . nwwie5t5of ; } if ( ( rtB . ku55m1jm2d == rtP .
Constant_Value_covdqsa2k4 ) == rtP . const_Value ) { rtB . bifocupq14 = rtB .
jopjoprq0c ; } else { rtB . bifocupq14 = rtB . af22xidizc ; } rtB .
bxtdurt4xq = rtB . jopjoprq0c - rtB . bifocupq14 ; rtB . bdfwgn2f4t = ssGetT
( rtS ) - rtB . bxtdurt4xq ; rtB . izwq3m54sy = muDoubleScalarMax ( rtB .
bdfwgn2f4t , rtP . Constant_Value_b3waei3ut2 ) ; if ( ssIsSampleHit ( rtS , 1
, 0 ) ) { if ( rtP . ManualSwitch1_CurrentSetting_cwepdspi5f == 1 ) { rtB .
mhiuaswy01 = rtP . Constant2_Value_ovsjzrpt3j ; } else { rtB . mhiuaswy01 =
rtP . Constant1_Value_ksii3tuk3x ; } if ( ssIsModeUpdateTimeStep ( rtS ) ) {
if ( rtB . mhiuaswy01 > 0.0 ) { if ( ! rtDW . bwa1fip2ky ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . bwa1fip2ky =
true ; } } else if ( rtDW . bwa1fip2ky ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . bwa1fip2ky =
false ; } } } if ( rtDW . bwa1fip2ky ) { rtB . btiigxjvj2 [ 0 ] = ssGetT (
rtS ) ; rtB . btiigxjvj2 [ 1 ] = rtB . bxtdurt4xq ; rtB . btiigxjvj2 [ 2 ] =
rtB . izwq3m54sy ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; { static
const char * blockSIDForSFcnLoader = "UNIFIER:8414" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * , int ) = rts -> modelMethods . sFcn .
mdlOutputs . level2 ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } } if (
ssIsModeUpdateTimeStep ( rtS ) ) { srUpdateBC ( rtDW . iw455stvt1 ) ; } } if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . hwhq5yb2fg = rtP . sms_Gain * rtB
. izwq3m54sy ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; { static const char * blockSIDForSFcnLoader =
"UNIFIER:8424" ; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader )
; void ( * sfcnMethodPtr ) ( SimStruct * , int ) = rts -> modelMethods . sFcn
. mdlOutputs . level2 ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } } }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID3 ( int_T tid ) { int32_T
aldazsptev ; real_T akixfm5ltq [ 9 ] ; real_T b030ufckb2_idx_0 ; real_T
chvpb4ztbe ; real_T cnx245efe2 ; real_T f3k5g2dr2y ; real_T h34dwrxh1c_idx_0
; real_T jnnfqkezxe ; int32_T i ; if ( muDoubleScalarAbs ( rtP . latlong0 [ 0
] ) > rtP . CompareToConstant_const_b5kwy5yvv2 ) { jnnfqkezxe =
muDoubleScalarMod ( rtP . latlong0 [ 0 ] + rtP . Bias_Bias_ftrguhqylg , rtP .
Constant2_Value_mxdetvroc4 ) + rtP . Bias1_Bias_kwaqdylxmf ; } else {
jnnfqkezxe = rtP . latlong0 [ 0 ] ; } cnx245efe2 = muDoubleScalarAbs (
jnnfqkezxe ) ; if ( cnx245efe2 > rtP . CompareToConstant_const_j3nekrd5nd ) {
rtB . l1dfj2jhio = ( ( cnx245efe2 + rtP . Bias_Bias_konxswsfpe ) * rtP .
Gain_Gain_jwbuilkyxy + rtP . Bias1_Bias_gdznygtef3 ) * muDoubleScalarSign (
jnnfqkezxe ) ; jnnfqkezxe = rtP . Constant_Value_o5fhcpqqyu ; } else { rtB .
l1dfj2jhio = jnnfqkezxe ; jnnfqkezxe = rtP . Constant1_Value_a0rz4phgln ; }
jnnfqkezxe += rtP . latlong0 [ 1 ] ; if ( muDoubleScalarAbs ( jnnfqkezxe ) >
rtP . CompareToConstant_const_gvfea0moje ) { rtB . l0khcdm5vj =
muDoubleScalarMod ( jnnfqkezxe + rtP . Bias_Bias_kd45ia31j2 , rtP .
Constant2_Value_d2ebp0gj1g ) + rtP . Bias1_Bias_pcofu2atfo ; } else { rtB .
l0khcdm5vj = jnnfqkezxe ; } jnnfqkezxe = 0.017453292519943295 * rtB .
l1dfj2jhio ; cnx245efe2 = rtP . f_Value - rtP . Constant_Value_nam4eq1guw ;
cnx245efe2 = muDoubleScalarSqrt ( rtP . Constant_Value_joj4ebuyjq -
cnx245efe2 * cnx245efe2 ) ; f3k5g2dr2y = muDoubleScalarSin ( jnnfqkezxe ) ;
f3k5g2dr2y = rtP . Constant_Value_bwixaan2i5 - cnx245efe2 * cnx245efe2 *
f3k5g2dr2y * f3k5g2dr2y ; chvpb4ztbe = rtP . Constant1_Value_auykfi4siv /
muDoubleScalarSqrt ( f3k5g2dr2y ) ; rtB . hc3pucpzoc = muDoubleScalarAtan2 (
rtP . Constant2_Value_dc1ztqo1sh , ( rtP . Constant_Value_cds1oetfvb -
cnx245efe2 * cnx245efe2 ) * chvpb4ztbe / f3k5g2dr2y ) ; rtB . h1pryicb3f =
muDoubleScalarAtan2 ( rtP . Constant3_Value , chvpb4ztbe * muDoubleScalarCos
( jnnfqkezxe ) ) ; muDoubleScalarSinCos ( 0.017453292519943295 * rtP .
FlatEarthtoLLA_psi , & rtB . djshdafk4a , & rtB . jurla4fp4a ) ; rtB .
ckez2fhnc0 = ( real32_T ) rtP . Constant_Value_p2sv0iawa4 ; rtB . ar3fw3fuom
= ( real32_T ) rtP . Constant_Value_ddzso0nzyx ; parallel_for ( 16 ,
ggl0rm1hauTID3 , 1 , "ggl0rm1hauTID3" ) ; parallel_for ( 14 , ppqwruko3jTID3
, 1 , "ppqwruko3jTID3" ) ; rtB . krmhpaiwtk [ 0 ] = ( real32_T ) rtP .
dp_FUSE_FIN . ref_CG [ 0 ] - ( real32_T ) rtP . xyz_cg [ 0 ] ; rtB .
krmhpaiwtk [ 1 ] = ( real32_T ) rtP . dp_FUSE_FIN . ref_CG [ 1 ] - ( real32_T
) rtP . xyz_cg [ 1 ] ; rtB . krmhpaiwtk [ 2 ] = ( real32_T ) rtP .
dp_FUSE_FIN . ref_CG [ 2 ] - ( real32_T ) rtP . xyz_cg [ 2 ] ; rtB .
phywd5jekf = - rtP . Constant_Value_guxqtm0enf ; parallel_for ( 16 ,
femu5gktcpTID3 , 1 , "femu5gktcpTID3" ) ; parallel_for ( 7 , ozenep403fTID3 ,
1 , "ozenep403fTID3" ) ; parallel_for ( 7 , jiwpvcutffTID3 , 1 ,
"jiwpvcutffTID3" ) ; for ( i = 0 ; i < 3 ; i ++ ) { h34dwrxh1c_idx_0 = rtP .
I [ 3 * i ] ; rtB . pchtyrudar [ 3 * i ] = h34dwrxh1c_idx_0 ; rtB .
k0wfvnkgwy [ 3 * i ] = rtP . Constant2_Value_btnragtfjb [ 3 * i ] ; rtB .
armozr15x5 [ 3 * i ] = h34dwrxh1c_idx_0 ; h34dwrxh1c_idx_0 = rtP . I [ 3 * i
+ 1 ] ; rtB . pchtyrudar [ 3 * i + 1 ] = h34dwrxh1c_idx_0 ; rtB . k0wfvnkgwy
[ 3 * i + 1 ] = rtP . Constant2_Value_btnragtfjb [ 3 * i + 1 ] ; rtB .
armozr15x5 [ 3 * i + 1 ] = h34dwrxh1c_idx_0 ; h34dwrxh1c_idx_0 = rtP . I [ 3
* i + 2 ] ; rtB . pchtyrudar [ 3 * i + 2 ] = h34dwrxh1c_idx_0 ; rtB .
k0wfvnkgwy [ 3 * i + 2 ] = rtP . Constant2_Value_btnragtfjb [ 3 * i + 2 ] ;
rtB . armozr15x5 [ 3 * i + 2 ] = h34dwrxh1c_idx_0 ; } jnnfqkezxe = rtP .
xyz_cg [ 1 ] ; for ( i = 0 ; i < 12 ; i ++ ) { rtB . dcirnuyxde [ i ] = rtP .
Gain_Gain_hvvnixqugo [ i ] * jnnfqkezxe - rtP . xyz_DEP [ 3 * i + 1 ] ; } rtB
. jferaaeyyn = muDoubleScalarCos ( rtP . Inclination_Value ) ; for (
aldazsptev = 0 ; aldazsptev < 12 ; aldazsptev ++ ) { rtB . adqmzv0sx0 [
aldazsptev ] . aox0khugvh [ 0 ] = ( real32_T ) rtP . xyz_cg [ 0 ] ;
muDoubleScalarSinCos ( rtP . adqmzv0sx0 . Constant1_Value_jux1hhk5qx , &
h34dwrxh1c_idx_0 , & b030ufckb2_idx_0 ) ; rtB . adqmzv0sx0 [ aldazsptev ] .
aox0khugvh [ 1 ] = ( real32_T ) rtP . xyz_cg [ 1 ] ; muDoubleScalarSinCos (
rtP . adqmzv0sx0 . DEP_incidence_Value , & jnnfqkezxe , & cnx245efe2 ) ; rtB
. adqmzv0sx0 [ aldazsptev ] . aox0khugvh [ 2 ] = ( real32_T ) rtP . xyz_cg [
2 ] ; muDoubleScalarSinCos ( rtP . adqmzv0sx0 . Constant1_Value_jux1hhk5qx ,
& f3k5g2dr2y , & chvpb4ztbe ) ; akixfm5ltq [ 0 ] = b030ufckb2_idx_0 *
cnx245efe2 ; akixfm5ltq [ 1 ] = jnnfqkezxe * f3k5g2dr2y * b030ufckb2_idx_0 -
h34dwrxh1c_idx_0 * chvpb4ztbe ; akixfm5ltq [ 2 ] = jnnfqkezxe * chvpb4ztbe *
b030ufckb2_idx_0 + h34dwrxh1c_idx_0 * f3k5g2dr2y ; akixfm5ltq [ 3 ] =
h34dwrxh1c_idx_0 * cnx245efe2 ; akixfm5ltq [ 4 ] = jnnfqkezxe * f3k5g2dr2y *
h34dwrxh1c_idx_0 + b030ufckb2_idx_0 * chvpb4ztbe ; akixfm5ltq [ 5 ] =
jnnfqkezxe * chvpb4ztbe * h34dwrxh1c_idx_0 - b030ufckb2_idx_0 * f3k5g2dr2y ;
akixfm5ltq [ 6 ] = - jnnfqkezxe ; akixfm5ltq [ 7 ] = cnx245efe2 * f3k5g2dr2y
; akixfm5ltq [ 8 ] = cnx245efe2 * chvpb4ztbe ; for ( i = 0 ; i < 3 ; i ++ ) {
rtB . adqmzv0sx0 [ aldazsptev ] . dbnx540oz1 [ 3 * i ] = akixfm5ltq [ i ] ;
rtB . adqmzv0sx0 [ aldazsptev ] . dbnx540oz1 [ 3 * i + 1 ] = akixfm5ltq [ i +
3 ] ; rtB . adqmzv0sx0 [ aldazsptev ] . dbnx540oz1 [ 3 * i + 2 ] = akixfm5ltq
[ i + 6 ] ; } } rtB . jemxdtgsel = rtP . Multiply_Gain * rtP . m ; rtB .
on14h4dmvl = rtP . Constant_Value_czh5rbe04d ; rtB . lwvqxcae23 = rtP .
Constant_Value_dkfqzg3jt5 ; rtB . ffkpsdx0zr = rtP .
Constant_Value_dosqprdn32 ; rtB . awnwv0frb5 [ 0 ] = rtP .
Constant_Value_ofr0qgx5yn [ 0 ] - rtP . xyz_cg [ 0 ] ; rtB . pr1vt54ko4 [ 0 ]
= rtP . Constant_Value_ofr0qgx5yn [ 0 ] - rtP . xyz_cg [ 0 ] ; rtB .
jygnbcsqf1 [ 0 ] = rtP . Constant2_Value_dksr45kxji [ 0 ] - rtP . xyz_cg [ 0
] ; rtB . mythzqzjez [ 0 ] = rtP . Constant2_Value_dksr45kxji [ 0 ] - rtP .
xyz_cg [ 0 ] ; rtB . cdxkdrlzzm [ 0 ] = rtP . Constant1_Value_i0jzjc51w0 [ 0
] - rtP . xyz_cg [ 0 ] ; rtB . njlxqs1uc4 [ 0 ] = rtP .
Constant1_Value_i0jzjc51w0 [ 0 ] - rtP . xyz_cg [ 0 ] ; rtB . e32n1qjlbz [ 0
] = rtP . Constant1_Value_grmbs0ngpp [ 0 ] - rtP . xyz_cg [ 0 ] ; rtB .
l2pt0kefdc [ 0 ] = rtP . Constant2_Value_eyfztz0fxi [ 0 ] - rtP . xyz_cg [ 0
] ; rtB . awnwv0frb5 [ 1 ] = rtP . Constant_Value_ofr0qgx5yn [ 1 ] - rtP .
xyz_cg [ 1 ] ; rtB . pr1vt54ko4 [ 1 ] = rtP . Constant_Value_ofr0qgx5yn [ 1 ]
- rtP . xyz_cg [ 1 ] ; rtB . jygnbcsqf1 [ 1 ] = rtP .
Constant2_Value_dksr45kxji [ 1 ] - rtP . xyz_cg [ 1 ] ; rtB . mythzqzjez [ 1
] = rtP . Constant2_Value_dksr45kxji [ 1 ] - rtP . xyz_cg [ 1 ] ; rtB .
cdxkdrlzzm [ 1 ] = rtP . Constant1_Value_i0jzjc51w0 [ 1 ] - rtP . xyz_cg [ 1
] ; rtB . njlxqs1uc4 [ 1 ] = rtP . Constant1_Value_i0jzjc51w0 [ 1 ] - rtP .
xyz_cg [ 1 ] ; rtB . e32n1qjlbz [ 1 ] = rtP . Constant1_Value_grmbs0ngpp [ 1
] - rtP . xyz_cg [ 1 ] ; rtB . l2pt0kefdc [ 1 ] = rtP .
Constant2_Value_eyfztz0fxi [ 1 ] - rtP . xyz_cg [ 1 ] ; rtB . awnwv0frb5 [ 2
] = rtP . Constant_Value_ofr0qgx5yn [ 2 ] - rtP . xyz_cg [ 2 ] ; rtB .
pr1vt54ko4 [ 2 ] = rtP . Constant_Value_ofr0qgx5yn [ 2 ] - rtP . xyz_cg [ 2 ]
; rtB . jygnbcsqf1 [ 2 ] = rtP . Constant2_Value_dksr45kxji [ 2 ] - rtP .
xyz_cg [ 2 ] ; rtB . mythzqzjez [ 2 ] = rtP . Constant2_Value_dksr45kxji [ 2
] - rtP . xyz_cg [ 2 ] ; rtB . cdxkdrlzzm [ 2 ] = rtP .
Constant1_Value_i0jzjc51w0 [ 2 ] - rtP . xyz_cg [ 2 ] ; rtB . njlxqs1uc4 [ 2
] = rtP . Constant1_Value_i0jzjc51w0 [ 2 ] - rtP . xyz_cg [ 2 ] ; rtB .
e32n1qjlbz [ 2 ] = rtP . Constant1_Value_grmbs0ngpp [ 2 ] - rtP . xyz_cg [ 2
] ; rtB . l2pt0kefdc [ 2 ] = rtP . Constant2_Value_eyfztz0fxi [ 2 ] - rtP .
xyz_cg [ 2 ] ; rtB . lrtymnw4xi = rtB . awnwv0frb5 [ 0 ] * rtB . on14h4dmvl ;
rtB . fnmgllmgqx = rtB . awnwv0frb5 [ 2 ] * rtB . on14h4dmvl ; rtB .
fqvqdt4rd2 = rtB . awnwv0frb5 [ 1 ] * rtB . on14h4dmvl ; rtB . jmxba5skz5 =
rtB . awnwv0frb5 [ 2 ] * rtB . on14h4dmvl ; rtB . f1a2rfeuz1 = rtB .
jygnbcsqf1 [ 0 ] * rtB . lwvqxcae23 ; rtB . ih10mokqjs = rtB . jygnbcsqf1 [ 2
] * rtB . lwvqxcae23 ; rtB . g344blsojt = rtB . jygnbcsqf1 [ 1 ] * rtB .
lwvqxcae23 ; rtB . grblrau4l1 = rtB . jygnbcsqf1 [ 2 ] * rtB . lwvqxcae23 ;
rtB . ftrxuf0i4a = rtB . cdxkdrlzzm [ 0 ] * rtB . ffkpsdx0zr ; rtB .
hqi2kczfkw = rtB . cdxkdrlzzm [ 2 ] * rtB . ffkpsdx0zr ; rtB . lpx2s5ac0u =
rtB . cdxkdrlzzm [ 1 ] * rtB . ffkpsdx0zr ; rtB . pmom2ene5w = rtB .
cdxkdrlzzm [ 2 ] * rtB . ffkpsdx0zr ; rtB . higayyxcv3 = rtB . e32n1qjlbz [ 1
] * rtP . Constant2_Value_p0sma1ifq3 ; rtB . djejdif2w5 = rtB . e32n1qjlbz [
0 ] * rtP . Constant2_Value_p0sma1ifq3 ; rtB . dkodtfhso0 = rtB . l2pt0kefdc
[ 1 ] * rtP . Constant3_Value_gdofiqtr3v ; rtB . lw0kvssqse = rtB .
l2pt0kefdc [ 2 ] * rtP . Constant3_Value_gdofiqtr3v ; rtB . nos3a2bbnv = rtB
. l2pt0kefdc [ 0 ] * rtP . Constant3_Value_gdofiqtr3v ; rtB . lhydxe5abe =
rtB . l2pt0kefdc [ 1 ] * rtP . Constant3_Value_gdofiqtr3v ; rtB . pr1zzcknox
= rtP . deviceID_Value ; rtB . lbzmmcd5bg = rtP .
Numberofsimstepstoskip_Value ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . iw455stvt1 ) ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdate ( int_T tid ) { int32_T aldazsptev ; int32_T i ; int32_T idxWidth ;
char_T * sErr ; sErr = GetErrorBuffer ( & rtDW . faxkrudp40 [ 0U ] ) ;
LibUpdate_Network ( & rtDW . faxkrudp40 [ 0U ] , & rtB . hjcw1qdlw2 [ 0U ] ,
45 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ;
ssSetStopRequested ( rtS , 1 ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; { static const char *
blockSIDForSFcnLoader = "UNIFIER:31022" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * , int ) =
ssGetmdlUpdate ( rts ) ; sfcnLoader_separateComplexHandler_withTID ( rts ,
sfcnMethodPtr , ( 0 <= 1 ) && gbl_raccel_tid01eq ? 0 : 0 ) ; } if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } } if ( ssIsSampleHit ( rtS
, 2 , 0 ) ) { sErr = GetErrorBuffer ( & rtDW . m4a0ukvmhq [ 0U ] ) ;
LibUpdate_Network ( & rtDW . m4a0ukvmhq [ 0U ] , & rtB . bd32gk0ocy .
e1wak2s0nn [ 0U ] , 509 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS ,
sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } sErr = GetErrorBuffer ( & rtDW .
mbrgrjucym [ 0U ] ) ; LibUpdate_Network ( & rtDW . mbrgrjucym [ 0U ] , & rtB
. dffuptpbcz . e1wak2s0nn [ 0U ] , 509 ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } rtDW .
kedw3dybgq = rtB . ecvavrybwp ; sErr = GetErrorBuffer ( & rtDW . abjojyrz15 [
0U ] ) ; LibUpdate_Network ( & rtDW . abjojyrz15 [ 0U ] , & rtB . bqi10o4hpx
[ 0U ] , 509 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ;
ssSetStopRequested ( rtS , 1 ) ; } sErr = GetErrorBuffer ( & rtDW .
ft5azbdazn [ 0U ] ) ; LibUpdate_Network ( & rtDW . ft5azbdazn [ 0U ] , & rtB
. kno2d54iit [ 0U ] , 509 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS ,
sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } sErr = GetErrorBuffer ( & rtDW .
m05hfkvpqz [ 0U ] ) ; LibUpdate_Network ( & rtDW . m05hfkvpqz [ 0U ] , & rtB
. hl5ibqcu3w . hr4wpt01um [ 0U ] , 509 ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } sErr =
GetErrorBuffer ( & rtDW . ksy2wwjv20 [ 0U ] ) ; LibUpdate_Network ( & rtDW .
ksy2wwjv20 [ 0U ] , & rtB . pookhwl2ri . hr4wpt01um [ 0U ] , 509 ) ; if ( *
sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1
) ; } sErr = GetErrorBuffer ( & rtDW . axqu4ckdky [ 0U ] ) ;
LibUpdate_Network ( & rtDW . axqu4ckdky [ 0U ] , & rtB . iffp5o1pbp [ 0U ] ,
509 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ;
ssSetStopRequested ( rtS , 1 ) ; } sErr = GetErrorBuffer ( & rtDW .
f00y3b0qin [ 0U ] ) ; LibUpdate_Network ( & rtDW . f00y3b0qin [ 0U ] , & rtB
. enohy5yaap . gz0squozgl [ 0U ] , 509 ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } sErr =
GetErrorBuffer ( & rtDW . ehnerh2sch [ 0U ] ) ; LibUpdate_Network ( & rtDW .
ehnerh2sch [ 0U ] , & rtB . nikuyjvr0y . gz0squozgl [ 0U ] , 509 ) ; if ( *
sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1
) ; } sErr = GetErrorBuffer ( & rtDW . h52cjzwtlm [ 0U ] ) ;
LibUpdate_Network ( & rtDW . h52cjzwtlm [ 0U ] , & rtB . jek5zaxern .
gz0squozgl [ 0U ] , 509 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS ,
sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } rtDW . ktsj2nkchd = rtB .
n2fj5a4cso ; sErr = GetErrorBuffer ( & rtDW . hshhxf1iwg [ 0U ] ) ;
LibUpdate_Network ( & rtDW . hshhxf1iwg [ 0U ] , & rtB . n1ybyykngv .
h11nwvgfxj [ 0U ] , 509 ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS ,
sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } sErr = GetErrorBuffer ( & rtDW .
fsed3lqtd2 [ 0U ] ) ; LibUpdate_Network ( & rtDW . fsed3lqtd2 [ 0U ] , & rtB
. hztlwupntw . h11nwvgfxj [ 0U ] , 509 ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } for ( i
= 0 ; i < 4 ; i ++ ) { for ( idxWidth = 0 ; idxWidth < 20 ; idxWidth ++ ) {
rtDW . g540jxiiax [ ( uint32_T ) i * 20U + ( uint32_T ) idxWidth ] = rtDW .
g540jxiiax [ ( ( uint32_T ) i + 1U ) * 20U + ( uint32_T ) idxWidth ] ; } }
memcpy ( & rtDW . g540jxiiax [ 80 ] , & rtB . hgd1a1255d [ 0 ] , 20U * sizeof
( real_T ) ) ; } for ( aldazsptev = 0 ; aldazsptev < 12 ; aldazsptev ++ ) {
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . adqmzv0sx0 [ aldazsptev ] .
kd3fwxo3ke = rtB . adqmzv0sx0 [ aldazsptev ] . cgxtlo5ezj ; } } { real_T * *
uBuffer = ( real_T * * ) & rtDW . a1p5mmdhor . TUbufferPtrs [ 0 ] ; int
numBuffers = 2 ; real_T simTime = ssGetT ( rtS ) ; { int_T i1 ; const real_T
* u0 = & rtB . kmxfn2bnil [ 0 ] ; const real_T * u1 = & rtB . ody4e0c4gv [ 0
] ; int_T * iw_Tail = & rtDW . l1l2gip32s . Tail [ 0 ] ; int_T * iw_Head = &
rtDW . l1l2gip32s . Head [ 0 ] ; int_T * iw_Last = & rtDW . l1l2gip32s . Last
[ 0 ] ; int_T * iw_CircularBufSize = & rtDW . l1l2gip32s . CircularBufSize [
0 ] ; for ( i1 = 0 ; i1 < 16 ; i1 ++ ) { iw_Head [ i1 ] = ( ( iw_Head [ i1 ]
< ( iw_CircularBufSize [ i1 ] - 1 ) ) ? ( iw_Head [ i1 ] + 1 ) : 0 ) ; if (
iw_Head [ i1 ] == iw_Tail [ i1 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
iw_CircularBufSize [ i1 ] , & iw_Tail [ i1 ] , & iw_Head [ i1 ] , & iw_Last [
i1 ] , simTime - rtP . VariableTransportDelay1_MaxDelay , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . l1l2gip32s . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
 "UNIFIER/C7A_HARW/Aero/InducedAngleOfAttack/addDelay/Variable\nTransport Delay1_TUbuffer0"
, ( void * * ) ( & uBuffer [ 0 ] ) , numBuffers * iw_CircularBufSize [ i1 ] *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer +
iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] = simTime ; ( * uBuffer ++ ) [
iw_Head [ i1 ] ] = u0 [ i1 ] ; } } } { real_T * * uBuffer = ( real_T * * ) &
rtDW . d5j1ciynjn . TUbufferPtrs [ 0 ] ; int numBuffers = 2 ; real_T simTime
= ssGetT ( rtS ) ; { int_T i1 ; const real_T * u0 = & rtB . agdfetg0qt [ 0 ]
; const real_T * u1 = & rtB . ody4e0c4gv [ 0 ] ; int_T * iw_Tail = & rtDW .
lynamxwk0r . Tail [ 0 ] ; int_T * iw_Head = & rtDW . lynamxwk0r . Head [ 0 ]
; int_T * iw_Last = & rtDW . lynamxwk0r . Last [ 0 ] ; int_T *
iw_CircularBufSize = & rtDW . lynamxwk0r . CircularBufSize [ 0 ] ; for ( i1 =
0 ; i1 < 16 ; i1 ++ ) { iw_Head [ i1 ] = ( ( iw_Head [ i1 ] < (
iw_CircularBufSize [ i1 ] - 1 ) ) ? ( iw_Head [ i1 ] + 1 ) : 0 ) ; if (
iw_Head [ i1 ] == iw_Tail [ i1 ] ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( &
iw_CircularBufSize [ i1 ] , & iw_Tail [ i1 ] , & iw_Head [ i1 ] , & iw_Last [
i1 ] , simTime - rtP . VariableTransportDelay_MaxDelay , uBuffer , (
boolean_T ) 0 , ( boolean_T ) 0 , & rtDW . lynamxwk0r . MaxNewBufSize ) ) {
ssSetErrorStatus ( rtS , "vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
 "UNIFIER/C7A_HARW/Aero/InducedAngleOfAttack/addDelay/Variable\nTransport Delay_TUbuffer0"
, ( void * * ) ( & uBuffer [ 0 ] ) , numBuffers * iw_CircularBufSize [ i1 ] *
sizeof ( real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer +
iw_CircularBufSize [ i1 ] ) [ iw_Head [ i1 ] ] = simTime ; ( * uBuffer ++ ) [
iw_Head [ i1 ] ] = u0 [ i1 ] ; } } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) {
for ( i = 0 ; i < 4 ; i ++ ) { for ( idxWidth = 0 ; idxWidth < 20 ; idxWidth
++ ) { rtDW . crxd5n2r3l [ ( uint32_T ) i * 20U + ( uint32_T ) idxWidth ] =
rtDW . crxd5n2r3l [ ( ( uint32_T ) i + 1U ) * 20U + ( uint32_T ) idxWidth ] ;
} } memcpy ( & rtDW . crxd5n2r3l [ 80 ] , & rtB . f0lcoipiql [ 0 ] , 20U *
sizeof ( real_T ) ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW .
oy300njhw2 [ 0 ] = rtB . jvaexa3o5a . jr3yr4ixei [ 0 ] ; rtDW . oy300njhw2 [
1 ] = rtB . jvaexa3o5a . jr3yr4ixei [ 1 ] ; rtDW . oy300njhw2 [ 2 ] = rtB .
jvaexa3o5a . jr3yr4ixei [ 2 ] ; rtDW . ie2l444zba [ 0 ] = rtB . leuhdrxpbe .
jr3yr4ixei [ 0 ] ; rtDW . ie2l444zba [ 1 ] = rtB . leuhdrxpbe . jr3yr4ixei [
1 ] ; rtDW . ie2l444zba [ 2 ] = rtB . leuhdrxpbe . jr3yr4ixei [ 2 ] ; rtDW .
fr2fpc1qxz [ 0 ] = rtB . csf3emrtxr . jr3yr4ixei [ 0 ] ; rtDW . fr2fpc1qxz [
1 ] = rtB . csf3emrtxr . jr3yr4ixei [ 1 ] ; rtDW . fr2fpc1qxz [ 2 ] = rtB .
csf3emrtxr . jr3yr4ixei [ 2 ] ; for ( i = 0 ; i < 4 ; i ++ ) { rtDW .
fx230yq5sl [ ( uint32_T ) i ] = rtDW . fx230yq5sl [ ( uint32_T ) i + 1U ] ;
rtDW . kvnpr153yy [ ( uint32_T ) i ] = rtDW . kvnpr153yy [ ( uint32_T ) i +
1U ] ; rtDW . jhfnsaqhxz [ ( uint32_T ) i ] = rtDW . jhfnsaqhxz [ ( uint32_T
) i + 1U ] ; rtDW . lnmqg4h42q [ ( uint32_T ) i ] = rtDW . lnmqg4h42q [ (
uint32_T ) i + 1U ] ; rtDW . jsnr5tvela [ ( uint32_T ) i ] = rtDW .
jsnr5tvela [ ( uint32_T ) i + 1U ] ; rtDW . buecpeq4re [ ( uint32_T ) i ] =
rtDW . buecpeq4re [ ( uint32_T ) i + 1U ] ; rtDW . asespk50pt [ ( uint32_T )
i ] = rtDW . asespk50pt [ ( uint32_T ) i + 1U ] ; rtDW . pmmx1tycaz [ (
uint32_T ) i ] = rtDW . pmmx1tycaz [ ( uint32_T ) i + 1U ] ; rtDW .
e5trjt2azz [ ( uint32_T ) i ] = rtDW . e5trjt2azz [ ( uint32_T ) i + 1U ] ;
rtDW . eqbrrfiebl [ ( uint32_T ) i * 3U ] = rtDW . eqbrrfiebl [ ( ( uint32_T
) i + 1U ) * 3U ] ; rtDW . eqbrrfiebl [ ( uint32_T ) i * 3U + 1U ] = rtDW .
eqbrrfiebl [ ( ( uint32_T ) i + 1U ) * 3U + 1U ] ; rtDW . eqbrrfiebl [ (
uint32_T ) i * 3U + 2U ] = rtDW . eqbrrfiebl [ ( ( uint32_T ) i + 1U ) * 3U +
2U ] ; for ( idxWidth = 0 ; idxWidth < 9 ; idxWidth ++ ) { rtDW . fkbachhibk
[ ( uint32_T ) i * 9U + ( uint32_T ) idxWidth ] = rtDW . fkbachhibk [ ( (
uint32_T ) i + 1U ) * 9U + ( uint32_T ) idxWidth ] ; } } rtDW . fx230yq5sl [
4 ] = rtB . afhieoseax [ 3 ] ; rtDW . kvnpr153yy [ 4 ] = rtB . pxf22reogn [ 5
] ; rtDW . jhfnsaqhxz [ 4 ] = rtB . afhieoseax [ 0 ] ; rtDW . lnmqg4h42q [ 4
] = rtB . afhieoseax [ 1 ] ; rtDW . jsnr5tvela [ 4 ] = rtB . afhieoseax [ 2 ]
; rtDW . buecpeq4re [ 4 ] = rtB . gbabd0z3bn [ 2 ] ; rtDW . asespk50pt [ 4 ]
= rtB . gbabd0z3bn [ 3 ] ; rtDW . pmmx1tycaz [ 4 ] = rtB . gbabd0z3bn [ 4 ] ;
rtDW . e5trjt2azz [ 4 ] = rtB . gbabd0z3bn [ 5 ] ; rtDW . eqbrrfiebl [ 12 ] =
rtB . ps23iickbr [ 0 ] ; rtDW . eqbrrfiebl [ 13 ] = rtB . ps23iickbr [ 1 ] ;
rtDW . eqbrrfiebl [ 14 ] = rtB . ps23iickbr [ 2 ] ; memcpy ( & rtDW .
fkbachhibk [ 36 ] , & rtB . od11ruf3th [ 0 ] , 9U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 4 ; i ++ ) { rtDW . oaqzp5s2cy [ ( uint32_T ) i ] = rtDW .
oaqzp5s2cy [ ( uint32_T ) i + 1U ] ; rtDW . plokoj1iat [ ( uint32_T ) i * 3U
] = rtDW . plokoj1iat [ ( ( uint32_T ) i + 1U ) * 3U ] ; rtDW . plokoj1iat [
( uint32_T ) i * 3U + 1U ] = rtDW . plokoj1iat [ ( ( uint32_T ) i + 1U ) * 3U
+ 1U ] ; rtDW . plokoj1iat [ ( uint32_T ) i * 3U + 2U ] = rtDW . plokoj1iat [
( ( uint32_T ) i + 1U ) * 3U + 2U ] ; rtDW . p3n5g3torf [ ( uint32_T ) i * 3U
] = rtDW . p3n5g3torf [ ( ( uint32_T ) i + 1U ) * 3U ] ; rtDW . p3n5g3torf [
( uint32_T ) i * 3U + 1U ] = rtDW . p3n5g3torf [ ( ( uint32_T ) i + 1U ) * 3U
+ 1U ] ; rtDW . p3n5g3torf [ ( uint32_T ) i * 3U + 2U ] = rtDW . p3n5g3torf [
( ( uint32_T ) i + 1U ) * 3U + 2U ] ; rtDW . avagxvnwf5 [ ( uint32_T ) i * 3U
] = rtDW . avagxvnwf5 [ ( ( uint32_T ) i + 1U ) * 3U ] ; rtDW . avagxvnwf5 [
( uint32_T ) i * 3U + 1U ] = rtDW . avagxvnwf5 [ ( ( uint32_T ) i + 1U ) * 3U
+ 1U ] ; rtDW . avagxvnwf5 [ ( uint32_T ) i * 3U + 2U ] = rtDW . avagxvnwf5 [
( ( uint32_T ) i + 1U ) * 3U + 2U ] ; } rtDW . oaqzp5s2cy [ 4 ] = rtB .
afhieoseax [ 4 ] ; rtDW . plokoj1iat [ 12 ] = rtB . p4p4elvfjt [ 0 ] ; rtDW .
plokoj1iat [ 13 ] = rtB . p4p4elvfjt [ 1 ] ; rtDW . plokoj1iat [ 14 ] = rtB .
p4p4elvfjt [ 2 ] ; rtDW . p3n5g3torf [ 12 ] = rtB . dkmnirebs0 [ 0 ] ; rtDW .
p3n5g3torf [ 13 ] = rtB . dkmnirebs0 [ 1 ] ; rtDW . p3n5g3torf [ 14 ] = rtB .
dkmnirebs0 [ 2 ] ; rtDW . avagxvnwf5 [ 12 ] = rtB . eezj4zgsj4 [ 0 ] ; rtDW .
avagxvnwf5 [ 13 ] = rtB . eezj4zgsj4 [ 1 ] ; rtDW . avagxvnwf5 [ 14 ] = rtB .
eezj4zgsj4 [ 2 ] ; rtDW . lkru3wc4bj [ 0U ] = rtDW . lkru3wc4bj [ 1U ] ; rtDW
. pwrdd5kibs [ 0U ] = rtDW . pwrdd5kibs [ 1U ] ; rtDW . erskmg5gj1 [ 0U ] =
rtDW . erskmg5gj1 [ 1U ] ; rtDW . jj43i52zwn [ 0U ] = rtDW . jj43i52zwn [ 1U
] ; rtDW . pagqs1iwpr [ 0U ] = rtDW . pagqs1iwpr [ 1U ] ; rtDW . hvagkay33y [
0U ] = rtDW . hvagkay33y [ 1U ] ; rtDW . eoz1jvwwoq [ 0U ] = rtDW .
eoz1jvwwoq [ 1U ] ; rtDW . jgluwzgfp1 [ 0U ] = rtDW . jgluwzgfp1 [ 1U ] ;
rtDW . cpjltmd3l2 [ 0U ] = rtDW . cpjltmd3l2 [ 1U ] ; rtDW . dcos1gkpc2 [ 0U
] = rtDW . dcos1gkpc2 [ 1U ] ; rtDW . eypbisuusv [ 0U ] = rtDW . eypbisuusv [
1U ] ; rtDW . ezpcxtf0ip [ 0U ] = rtDW . ezpcxtf0ip [ 1U ] ; rtDW .
ookott5jvl [ 0U ] = rtDW . ookott5jvl [ 1U ] ; rtDW . h3h1h5xjyq [ 0U ] =
rtDW . h3h1h5xjyq [ 1U ] ; rtDW . aadveypr3e [ 0U ] = rtDW . aadveypr3e [ 1U
] ; rtDW . lkru3wc4bj [ 1U ] = rtDW . lkru3wc4bj [ 2U ] ; rtDW . pwrdd5kibs [
1U ] = rtDW . pwrdd5kibs [ 2U ] ; rtDW . erskmg5gj1 [ 1U ] = rtDW .
erskmg5gj1 [ 2U ] ; rtDW . jj43i52zwn [ 1U ] = rtDW . jj43i52zwn [ 2U ] ;
rtDW . pagqs1iwpr [ 1U ] = rtDW . pagqs1iwpr [ 2U ] ; rtDW . hvagkay33y [ 1U
] = rtDW . hvagkay33y [ 2U ] ; rtDW . eoz1jvwwoq [ 1U ] = rtDW . eoz1jvwwoq [
2U ] ; rtDW . jgluwzgfp1 [ 1U ] = rtDW . jgluwzgfp1 [ 2U ] ; rtDW .
cpjltmd3l2 [ 1U ] = rtDW . cpjltmd3l2 [ 2U ] ; rtDW . dcos1gkpc2 [ 1U ] =
rtDW . dcos1gkpc2 [ 2U ] ; rtDW . eypbisuusv [ 1U ] = rtDW . eypbisuusv [ 2U
] ; rtDW . ezpcxtf0ip [ 1U ] = rtDW . ezpcxtf0ip [ 2U ] ; rtDW . ookott5jvl [
1U ] = rtDW . ookott5jvl [ 2U ] ; rtDW . h3h1h5xjyq [ 1U ] = rtDW .
h3h1h5xjyq [ 2U ] ; rtDW . aadveypr3e [ 1U ] = rtDW . aadveypr3e [ 2U ] ;
rtDW . lkru3wc4bj [ 2U ] = rtDW . lkru3wc4bj [ 3U ] ; rtDW . pwrdd5kibs [ 2U
] = rtDW . pwrdd5kibs [ 3U ] ; rtDW . erskmg5gj1 [ 2U ] = rtDW . erskmg5gj1 [
3U ] ; rtDW . jj43i52zwn [ 2U ] = rtDW . jj43i52zwn [ 3U ] ; rtDW .
pagqs1iwpr [ 2U ] = rtDW . pagqs1iwpr [ 3U ] ; rtDW . hvagkay33y [ 2U ] =
rtDW . hvagkay33y [ 3U ] ; rtDW . eoz1jvwwoq [ 2U ] = rtDW . eoz1jvwwoq [ 3U
] ; rtDW . jgluwzgfp1 [ 2U ] = rtDW . jgluwzgfp1 [ 3U ] ; rtDW . cpjltmd3l2 [
2U ] = rtDW . cpjltmd3l2 [ 3U ] ; rtDW . dcos1gkpc2 [ 2U ] = rtDW .
dcos1gkpc2 [ 3U ] ; rtDW . eypbisuusv [ 2U ] = rtDW . eypbisuusv [ 3U ] ;
rtDW . ezpcxtf0ip [ 2U ] = rtDW . ezpcxtf0ip [ 3U ] ; rtDW . ookott5jvl [ 2U
] = rtDW . ookott5jvl [ 3U ] ; rtDW . h3h1h5xjyq [ 2U ] = rtDW . h3h1h5xjyq [
3U ] ; rtDW . aadveypr3e [ 2U ] = rtDW . aadveypr3e [ 3U ] ; rtDW .
lkru3wc4bj [ 3U ] = rtDW . lkru3wc4bj [ 4U ] ; rtDW . pwrdd5kibs [ 3U ] =
rtDW . pwrdd5kibs [ 4U ] ; rtDW . erskmg5gj1 [ 3U ] = rtDW . erskmg5gj1 [ 4U
] ; rtDW . jj43i52zwn [ 3U ] = rtDW . jj43i52zwn [ 4U ] ; rtDW . pagqs1iwpr [
3U ] = rtDW . pagqs1iwpr [ 4U ] ; rtDW . hvagkay33y [ 3U ] = rtDW .
hvagkay33y [ 4U ] ; rtDW . eoz1jvwwoq [ 3U ] = rtDW . eoz1jvwwoq [ 4U ] ;
rtDW . jgluwzgfp1 [ 3U ] = rtDW . jgluwzgfp1 [ 4U ] ; rtDW . cpjltmd3l2 [ 3U
] = rtDW . cpjltmd3l2 [ 4U ] ; rtDW . dcos1gkpc2 [ 3U ] = rtDW . dcos1gkpc2 [
4U ] ; rtDW . eypbisuusv [ 3U ] = rtDW . eypbisuusv [ 4U ] ; rtDW .
ezpcxtf0ip [ 3U ] = rtDW . ezpcxtf0ip [ 4U ] ; rtDW . ookott5jvl [ 3U ] =
rtDW . ookott5jvl [ 4U ] ; rtDW . h3h1h5xjyq [ 3U ] = rtDW . h3h1h5xjyq [ 4U
] ; rtDW . aadveypr3e [ 3U ] = rtDW . aadveypr3e [ 4U ] ; rtDW . lkru3wc4bj [
4 ] = rtB . agnrcu13e2 ; rtDW . pwrdd5kibs [ 4 ] = rtB . jdw5fy5uyh ; rtDW .
erskmg5gj1 [ 4 ] = rtB . l4whzntd2w ; rtDW . jj43i52zwn [ 4 ] = rtB .
ieaokh1oup ; rtDW . pagqs1iwpr [ 4 ] = rtB . bkodm3ably ; rtDW . hvagkay33y [
4 ] = rtB . odhuccln2g ; rtDW . eoz1jvwwoq [ 4 ] = rtB . kydbwk01f5 ; rtDW .
jgluwzgfp1 [ 4 ] = rtB . afhieoseax [ 5 ] ; rtDW . cpjltmd3l2 [ 4 ] = rtB .
pxf22reogn [ 0 ] ; rtDW . dcos1gkpc2 [ 4 ] = rtB . gbabd0z3bn [ 0 ] ; rtDW .
eypbisuusv [ 4 ] = rtB . gbabd0z3bn [ 1 ] ; rtDW . ezpcxtf0ip [ 4 ] = rtB .
pxf22reogn [ 1 ] ; rtDW . ookott5jvl [ 4 ] = rtB . pxf22reogn [ 2 ] ; rtDW .
h3h1h5xjyq [ 4 ] = rtB . pxf22reogn [ 3 ] ; rtDW . aadveypr3e [ 4 ] = rtB .
pxf22reogn [ 4 ] ; } { SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; {
static const char * blockSIDForSFcnLoader = "UNIFIER:8429" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * , int ) = ssGetmdlUpdate ( rts ) ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . nwwie5t5of = rtB .
bifocupq14 ; } if ( rtDW . bwa1fip2ky ) { { SimStruct * rts = ssGetSFunction
( rtS , 0 ) ; { static const char * blockSIDForSFcnLoader = "UNIFIER:8414" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * , int ) = ssGetmdlUpdate ( rts ) ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { { SimStruct * rts =
ssGetSFunction ( rtS , 3 ) ; { static const char * blockSIDForSFcnLoader =
"UNIFIER:8424" ; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader )
; void ( * sfcnMethodPtr ) ( SimStruct * , int ) = ssGetmdlUpdate ( rts ) ;
sfcnLoader_separateComplexHandler_withTID ( rts , sfcnMethodPtr , ( 0 <= 1 )
&& gbl_raccel_tid01eq ? 0 : 0 ) ; } if ( ssGetErrorStatus ( rts ) != ( NULL )
) return ; } } UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID3 ( int_T tid )
{ UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { int32_T
aldazsptev ; XDot * _rtXdot ; int_T iS ; int_T jdx ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> dmrka4iuwk [ 0 ] = rtB . ps23iickbr [ 0 ] ;
_rtXdot -> jy1l3ujv3t [ 0 ] = rtB . fcg44x4aqz [ 0 ] ; _rtXdot -> ppiohzkobr
[ 0 ] = rtB . gdwsegs0yn [ 0 ] ; _rtXdot -> dmrka4iuwk [ 1 ] = rtB .
ps23iickbr [ 1 ] ; _rtXdot -> jy1l3ujv3t [ 1 ] = rtB . fcg44x4aqz [ 1 ] ;
_rtXdot -> ppiohzkobr [ 1 ] = rtB . gdwsegs0yn [ 1 ] ; _rtXdot -> dmrka4iuwk
[ 2 ] = rtB . ps23iickbr [ 2 ] ; _rtXdot -> jy1l3ujv3t [ 2 ] = rtB .
fcg44x4aqz [ 2 ] ; _rtXdot -> ppiohzkobr [ 2 ] = rtB . gdwsegs0yn [ 2 ] ; if
( rtDW . pi3jxhaf2b ) { if ( ( ( rtX . jmsbhu4m05 > rtP .
DistanceintoGustxLimitedtogustlengthd_LowerSat ) && ( rtX . jmsbhu4m05 < rtP
. Distanceintogustx_d_m ) ) || ( ( rtX . jmsbhu4m05 <= rtP .
DistanceintoGustxLimitedtogustlengthd_LowerSat ) && ( rtB . fbtjhgisvg > 0.0
) ) || ( ( rtX . jmsbhu4m05 >= rtP . Distanceintogustx_d_m ) && ( rtB .
fbtjhgisvg < 0.0 ) ) ) { _rtXdot -> jmsbhu4m05 = rtB . fbtjhgisvg ; } else {
_rtXdot -> jmsbhu4m05 = 0.0 ; } } else { ( ( XDot * ) ssGetdX ( rtS ) ) ->
jmsbhu4m05 = 0.0 ; } jlrztmmapx ( rtB . fbtjhgisvg , rtP .
Distanceintogusty_d_m , & rtDW . fthork0k0x2 , & rtP . fthork0k0x2 , & rtX .
fthork0k0x2 , & _rtXdot -> fthork0k0x2 ) ; jlrztmmapx ( rtB . fbtjhgisvg ,
rtP . Distanceintogustz_d_m , & rtDW . pcwoeb21pm , & rtP . pcwoeb21pm , &
rtX . pcwoeb21pm , & _rtXdot -> pcwoeb21pm ) ; _rtXdot -> gz3b4js4ds [ 0 ] =
rtB . onu4r5xewk [ 0 ] ; _rtXdot -> gz3b4js4ds [ 1 ] = rtB . onu4r5xewk [ 1 ]
; _rtXdot -> gz3b4js4ds [ 2 ] = rtB . onu4r5xewk [ 2 ] ; for ( aldazsptev = 0
; aldazsptev < 12 ; aldazsptev ++ ) { _rtXdot -> adqmzv0sx0 [ aldazsptev ] .
jtqvm3jkcz = rtB . adqmzv0sx0 [ aldazsptev ] . n52zpi4j4s ; _rtXdot ->
adqmzv0sx0 [ aldazsptev ] . dkxi20ccfc = rtB . adqmzv0sx0 [ aldazsptev ] .
ex2xojeend ; } { } { } if ( rtDW . nt5ueu32fc == 0 ) { _rtXdot -> oqemwaxlko
[ 0 ] = rtX . oqemwaxlko [ 1 ] ; _rtXdot -> oqemwaxlko [ 1 ] = rtB .
ixwwzqb4p2 ; } jdx = 6 ; for ( iS = 0 ; iS < 6 ; iS ++ ) { if ( rtDW .
ihk13omcli [ iS ] == 0 ) { _rtXdot -> n5m0nb0nkj [ iS ] = rtX . n5m0nb0nkj [
jdx ] ; _rtXdot -> n5m0nb0nkj [ jdx ] = rtB . naaosn4yn2 [ iS ] ; } jdx ++ ;
} jdx = 6 ; for ( iS = 0 ; iS < 6 ; iS ++ ) { if ( rtDW . iwurle5qux [ iS ]
== 0 ) { _rtXdot -> c1kooexubz [ iS ] = rtX . c1kooexubz [ jdx ] ; _rtXdot ->
c1kooexubz [ jdx ] = rtB . niowrwikj3 [ iS ] ; } jdx ++ ; } jdx = 6 ; for (
iS = 0 ; iS < 6 ; iS ++ ) { if ( rtDW . pe511og3ku [ iS ] == 0 ) { _rtXdot ->
ndpus01ld4 [ iS ] = rtX . ndpus01ld4 [ jdx ] ; _rtXdot -> ndpus01ld4 [ jdx ]
= rtB . hpmq1jfzli [ iS ] ; } jdx ++ ; } if ( rtDW . ldrxgujyb0 == 0 ) {
_rtXdot -> bdt2nf5etq [ 0 ] = rtX . bdt2nf5etq [ 1 ] ; _rtXdot -> bdt2nf5etq
[ 1 ] = rtB . c0rbweqsq1 ; } if ( rtDW . kksik1paup == 0 ) { _rtXdot ->
ai1bi54qax [ 0 ] = rtX . ai1bi54qax [ 1 ] ; _rtXdot -> ai1bi54qax [ 1 ] = rtB
. ia0ra0q3ax ; } if ( rtDW . cbrsqgmwzt == 0 ) { _rtXdot -> a1z3hbtkhc [ 0 ]
= rtX . a1z3hbtkhc [ 1 ] ; _rtXdot -> a1z3hbtkhc [ 1 ] = rtB . nsqrvbi5rh ; }
if ( rtDW . j1zkhtxhzf == 0 ) { _rtXdot -> iugjf2dp5k [ 0 ] = rtX .
iugjf2dp5k [ 1 ] ; _rtXdot -> iugjf2dp5k [ 1 ] = rtB . g3dy1b3uqu ; } if (
rtDW . lfxnks51wi [ 0 ] == 0 ) { _rtXdot -> kv0bz415kr [ 0 ] = rtX .
kv0bz415kr [ 3 ] ; _rtXdot -> kv0bz415kr [ 3 ] = rtB . avgj00fc45 [ 0 ] ; }
if ( rtDW . lfxnks51wi [ 1 ] == 0 ) { _rtXdot -> kv0bz415kr [ 1 ] = rtX .
kv0bz415kr [ 4 ] ; _rtXdot -> kv0bz415kr [ 4 ] = rtB . avgj00fc45 [ 1 ] ; }
if ( rtDW . lfxnks51wi [ 2 ] == 0 ) { _rtXdot -> kv0bz415kr [ 2 ] = rtX .
kv0bz415kr [ 5 ] ; _rtXdot -> kv0bz415kr [ 5 ] = rtB . avgj00fc45 [ 2 ] ; }
if ( rtDW . c5hzybmrlt [ 0 ] == 0 ) { _rtXdot -> hxqf43szbj [ 0 ] = rtX .
hxqf43szbj [ 3 ] ; _rtXdot -> hxqf43szbj [ 3 ] = rtB . m1qwau1ibb [ 0 ] ; }
if ( rtDW . c5hzybmrlt [ 1 ] == 0 ) { _rtXdot -> hxqf43szbj [ 1 ] = rtX .
hxqf43szbj [ 4 ] ; _rtXdot -> hxqf43szbj [ 4 ] = rtB . m1qwau1ibb [ 1 ] ; }
if ( rtDW . c5hzybmrlt [ 2 ] == 0 ) { _rtXdot -> hxqf43szbj [ 2 ] = rtX .
hxqf43szbj [ 5 ] ; _rtXdot -> hxqf43szbj [ 5 ] = rtB . m1qwau1ibb [ 2 ] ; } }
void MdlProjection ( void ) { } void MdlTerminate ( void ) { char_T * sErr ;
sErr = GetErrorBuffer ( & rtDW . o4nasosvnh [ 0U ] ) ; LibTerminate ( & rtDW
. o4nasosvnh [ 0U ] ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS , sErr )
; ssSetStopRequested ( rtS , 1 ) ; } LibDestroy ( & rtDW . o4nasosvnh [ 0U ]
, 1 ) ; DestroyUDPInterface ( & rtDW . o4nasosvnh [ 0U ] ) ; sErr =
GetErrorBuffer ( & rtDW . lwsgjestu3 [ 0U ] ) ; LibTerminate ( & rtDW .
lwsgjestu3 [ 0U ] ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS , sErr ) ;
ssSetStopRequested ( rtS , 1 ) ; } LibDestroy ( & rtDW . lwsgjestu3 [ 0U ] ,
1 ) ; DestroyUDPInterface ( & rtDW . lwsgjestu3 [ 0U ] ) ; { SimStruct * rts
= ssGetSFunction ( rtS , 0 ) ; { static const char * blockSIDForSFcnLoader =
"UNIFIER:8414" ; sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader )
; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn .
mdlTerminate ; sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; }
} sErr = GetErrorBuffer ( & rtDW . faxkrudp40 [ 0U ] ) ; LibTerminate ( &
rtDW . faxkrudp40 [ 0U ] ) ; if ( * sErr != 0 ) { ssSetErrorStatus ( rtS ,
sErr ) ; ssSetStopRequested ( rtS , 1 ) ; } LibDestroy ( & rtDW . faxkrudp40
[ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW . faxkrudp40 [ 0U ] ) ; {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; { static const char *
blockSIDForSFcnLoader = "UNIFIER:31022" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlTerminate ; sfcnLoader_separateComplexHandler ( rts
, sfcnMethodPtr ) ; } } sErr = GetErrorBuffer ( & rtDW . m4a0ukvmhq [ 0U ] )
; LibTerminate ( & rtDW . m4a0ukvmhq [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . m4a0ukvmhq [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. m4a0ukvmhq [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . mbrgrjucym [ 0U ] )
; LibTerminate ( & rtDW . mbrgrjucym [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . mbrgrjucym [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. mbrgrjucym [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . abjojyrz15 [ 0U ] )
; LibTerminate ( & rtDW . abjojyrz15 [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . abjojyrz15 [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. abjojyrz15 [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . ft5azbdazn [ 0U ] )
; LibTerminate ( & rtDW . ft5azbdazn [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . ft5azbdazn [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. ft5azbdazn [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . m05hfkvpqz [ 0U ] )
; LibTerminate ( & rtDW . m05hfkvpqz [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . m05hfkvpqz [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. m05hfkvpqz [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . ksy2wwjv20 [ 0U ] )
; LibTerminate ( & rtDW . ksy2wwjv20 [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . ksy2wwjv20 [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. ksy2wwjv20 [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . axqu4ckdky [ 0U ] )
; LibTerminate ( & rtDW . axqu4ckdky [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . axqu4ckdky [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. axqu4ckdky [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . f00y3b0qin [ 0U ] )
; LibTerminate ( & rtDW . f00y3b0qin [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . f00y3b0qin [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. f00y3b0qin [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . ehnerh2sch [ 0U ] )
; LibTerminate ( & rtDW . ehnerh2sch [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . ehnerh2sch [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. ehnerh2sch [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . h52cjzwtlm [ 0U ] )
; LibTerminate ( & rtDW . h52cjzwtlm [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . h52cjzwtlm [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. h52cjzwtlm [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . hshhxf1iwg [ 0U ] )
; LibTerminate ( & rtDW . hshhxf1iwg [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . hshhxf1iwg [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. hshhxf1iwg [ 0U ] ) ; sErr = GetErrorBuffer ( & rtDW . fsed3lqtd2 [ 0U ] )
; LibTerminate ( & rtDW . fsed3lqtd2 [ 0U ] ) ; if ( * sErr != 0 ) {
ssSetErrorStatus ( rtS , sErr ) ; ssSetStopRequested ( rtS , 1 ) ; }
LibDestroy ( & rtDW . fsed3lqtd2 [ 0U ] , 1 ) ; DestroyUDPInterface ( & rtDW
. fsed3lqtd2 [ 0U ] ) ; { int_T i1 ; void * * pw_TUbufferPtrs = & rtDW .
a1p5mmdhor . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ; i1 < 16 ; i1 ++ ) {
rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } } { int_T i1 ; void * *
pw_TUbufferPtrs = & rtDW . d5j1ciynjn . TUbufferPtrs [ 0 ] ; for ( i1 = 0 ;
i1 < 16 ; i1 ++ ) { rt_TDelayFreeBuf ( pw_TUbufferPtrs [ i1 ] ) ; } } {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; { static const char *
blockSIDForSFcnLoader = "UNIFIER:8429" ; sfcnLoader_setCurrentSFcnBlockSID (
blockSIDForSFcnLoader ) ; void ( * sfcnMethodPtr ) ( SimStruct * ) = rts ->
modelMethods . sFcn . mdlTerminate ; sfcnLoader_separateComplexHandler ( rts
, sfcnMethodPtr ) ; } } { SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; {
static const char * blockSIDForSFcnLoader = "UNIFIER:8424" ;
sfcnLoader_setCurrentSFcnBlockSID ( blockSIDForSFcnLoader ) ; void ( *
sfcnMethodPtr ) ( SimStruct * ) = rts -> modelMethods . sFcn . mdlTerminate ;
sfcnLoader_separateComplexHandler ( rts , sfcnMethodPtr ) ; } } { if ( rtDW .
dzukxciamp . AQHandles ) { sdiTerminateStreaming ( & rtDW . dzukxciamp .
AQHandles ) ; } } { if ( rtDW . oumnpiegvc . AQHandles ) {
sdiTerminateStreaming ( & rtDW . oumnpiegvc . AQHandles ) ; } } { if ( rtDW .
kmqxlkx3v2 . AQHandles ) { sdiTerminateStreaming ( & rtDW . kmqxlkx3v2 .
AQHandles ) ; } } { if ( rtDW . oszdennjt4 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . oszdennjt4 . AQHandles ) ; } } { if ( rtDW .
glhrtguzli . AQHandles ) { sdiTerminateStreaming ( & rtDW . glhrtguzli .
AQHandles ) ; } } { if ( rtDW . dzukxciampy . AQHandles ) {
sdiTerminateStreaming ( & rtDW . dzukxciampy . AQHandles ) ; } } { if ( rtDW
. dzukxciampy4 . AQHandles ) { sdiTerminateStreaming ( & rtDW . dzukxciampy4
. AQHandles ) ; } } { if ( rtDW . dzukxciampy43 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . dzukxciampy43 . AQHandles ) ; } } { if (
rtDW . dzukxciampy430 . AQHandles ) { sdiTerminateStreaming ( & rtDW .
dzukxciampy430 . AQHandles ) ; } } { if ( rtDW . oumnpiegvcp . AQHandles ) {
sdiTerminateStreaming ( & rtDW . oumnpiegvcp . AQHandles ) ; } } { if ( rtDW
. kmqxlkx3v2q . AQHandles ) { sdiTerminateStreaming ( & rtDW . kmqxlkx3v2q .
AQHandles ) ; } } { if ( rtDW . oszdennjt4x . AQHandles ) {
sdiTerminateStreaming ( & rtDW . oszdennjt4x . AQHandles ) ; } } { if ( rtDW
. glhrtguzlib . AQHandles ) { sdiTerminateStreaming ( & rtDW . glhrtguzlib .
AQHandles ) ; } } { if ( rtDW . a01trbqc4k . AQHandles ) {
sdiTerminateStreaming ( & rtDW . a01trbqc4k . AQHandles ) ; } } { if ( rtDW .
dzukxciampy430g . AQHandles ) { sdiTerminateStreaming ( & rtDW .
dzukxciampy430g . AQHandles ) ; } } { if ( rtDW . hpymvgtvx5 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . hpymvgtvx5 . AQHandles ) ; } } } static void
mr_UNIFIER_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_UNIFIER_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_UNIFIER_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_UNIFIER_restoreDataFromMxArray ( void * destData , const mxArray *
srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_UNIFIER_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_UNIFIER_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_UNIFIER_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) ; static uint_T
mr_UNIFIER_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i
, int j , uint_T numBits ) { const uint_T varVal = ( uint_T ) mxGetScalar (
mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( ( 1u << numBits
) - 1u ) ; } static void mr_UNIFIER_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void mr_UNIFIER_cacheDataToMxArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , const void *
srcData , size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_UNIFIER_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_UNIFIER_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_UNIFIER_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_UNIFIER_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_UNIFIER_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_UNIFIER_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray
, mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T
fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray
, i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; }
mxArray * mr_UNIFIER_GetDWork ( ) { static const char_T * ssDWFieldNames [ 3
] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_UNIFIER_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 165 ] = {
"rtDW.g540jxiiax" , "rtDW.crxd5n2r3l" , "rtDW.fx230yq5sl" , "rtDW.kvnpr153yy"
, "rtDW.jhfnsaqhxz" , "rtDW.lnmqg4h42q" , "rtDW.jsnr5tvela" ,
"rtDW.buecpeq4re" , "rtDW.asespk50pt" , "rtDW.pmmx1tycaz" , "rtDW.e5trjt2azz"
, "rtDW.eqbrrfiebl" , "rtDW.fkbachhibk" , "rtDW.oaqzp5s2cy" ,
"rtDW.plokoj1iat" , "rtDW.p3n5g3torf" , "rtDW.avagxvnwf5" , "rtDW.lkru3wc4bj"
, "rtDW.pwrdd5kibs" , "rtDW.erskmg5gj1" , "rtDW.jj43i52zwn" ,
"rtDW.pagqs1iwpr" , "rtDW.hvagkay33y" , "rtDW.eoz1jvwwoq" , "rtDW.jgluwzgfp1"
, "rtDW.cpjltmd3l2" , "rtDW.dcos1gkpc2" , "rtDW.eypbisuusv" ,
"rtDW.ezpcxtf0ip" , "rtDW.ookott5jvl" , "rtDW.h3h1h5xjyq" , "rtDW.aadveypr3e"
, "rtDW.nwwie5t5of" , "rtDW.keywsrry0q" , "rtDW.kedw3dybgq" ,
"rtDW.ktsj2nkchd" , "rtDW.oy300njhw2" , "rtDW.ie2l444zba" , "rtDW.fr2fpc1qxz"
, "rtDW.ilac1ylth3" , "rtDW.nevgeggqm5" , "rtDW.lq4e3tdaf4" ,
"rtDW.ml2zybgolh" , "rtDW.nndt0j2iyw" , "rtDW.oxzbnowmim" , "rtDW.csd33umrye"
, "rtDW.odfy0ab2zu" , "rtDW.piktw1sptf" , "rtDW.iinforci3b" ,
"rtDW.onpp1osnf1" , "rtDW.knywr3cygt" , "rtDW.bxxehqrfhk" , "rtDW.lybiwzq15a"
, "rtDW.hhpqcwloh0" , "rtDW.hxdxaozqh1" , "rtDW.fknte5kkos" ,
"rtDW.mnfw2imvdw" , "rtDW.felqedgyx1" , "rtDW.knvjdfedfb" , "rtDW.apjnubwssp"
, "rtDW.ptu3l2ehpk" , "rtDW.ebmg2d0djd" , "rtDW.nmrn1j5ohh" ,
"rtDW.hl5ux0u3e5" , "rtDW.kywikzuq0z" , "rtDW.op4s5nmfn0" , "rtDW.p3qcu4kyf3"
, "rtDW.d1rjlxqbuf" , "rtDW.g130c2x32o" , "rtDW.dssqgth4gt" ,
"rtDW.erz4us2nfk" , "rtDW.fyjcynthf1" , "rtDW.acn3fu00s1" , "rtDW.itcccsf0ct"
, "rtDW.lipbrcbfzk" , "rtDW.md1fsm3br3" , "rtDW.be05daasmg" ,
"rtDW.nq0rryljq1" , "rtDW.ddr4l0n5i3" , "rtDW.by2jasgm4o" , "rtDW.daljbq5gtz"
, "rtDW.l1l2gip32s" , "rtDW.lynamxwk0r" , "rtDW.nt5ueu32fc" ,
"rtDW.ihk13omcli" , "rtDW.iwurle5qux" , "rtDW.pe511og3ku" , "rtDW.ldrxgujyb0"
, "rtDW.kksik1paup" , "rtDW.cbrsqgmwzt" , "rtDW.j1zkhtxhzf" ,
"rtDW.lfxnks51wi" , "rtDW.c5hzybmrlt" , "rtDW.cfvgbkovvu" , "rtDW.anhm4dpp2l"
, "rtDW.iw455stvt1" , "rtDW.pakc2g42kk" , "rtDW.oek5idxhme" ,
"rtDW.bf5ec1ihjs" , "rtDW.d04ooymyox" , "rtDW.nmnxbsefd1" , "rtDW.pny1rb4usr"
, "rtDW.chzc3nt2yy" , "rtDW.cg1cpca1ek" , "rtDW.hrnzbhxy5d" ,
"rtDW.ikjcop0bgm" , "rtDW.p2ctlaxtsk" , "rtDW.bp4ac3vvj5" , "rtDW.jl5nu1i4l3"
, "rtDW.lh250aajbj" , "rtDW.edqryqv5bk" , "rtDW.l3qjgn1jqc" ,
"rtDW.cyto13o4kt" , "rtDW.jgpyhmovpk" , "rtDW.mu4revjjwi" , "rtDW.pdvyjvvslc"
, "rtDW.kbyn225ku2" , "rtDW.o5u4b02npb" , "rtDW.jcdq2ohx3t" ,
"rtDW.bwa1fip2ky" , "rtDW.pi3jxhaf2b" , "rtDW.hztlwupntw.apnlfrnpo3" ,
"rtDW.hztlwupntw.ovvez5xelu" , "rtDW.hztlwupntw.dtz1ggkdpo" ,
"rtDW.n1ybyykngv.apnlfrnpo3" , "rtDW.n1ybyykngv.ovvez5xelu" ,
"rtDW.n1ybyykngv.dtz1ggkdpo" , "rtDW.jek5zaxern.datl4fzkmc" ,
"rtDW.jek5zaxern.op350srgbo" , "rtDW.jek5zaxern.eiaswshrvs" ,
"rtDW.nikuyjvr0y.datl4fzkmc" , "rtDW.nikuyjvr0y.op350srgbo" ,
"rtDW.nikuyjvr0y.eiaswshrvs" , "rtDW.enohy5yaap.datl4fzkmc" ,
"rtDW.enohy5yaap.op350srgbo" , "rtDW.enohy5yaap.eiaswshrvs" ,
"rtDW.pookhwl2ri.aquds3y3qy" , "rtDW.pookhwl2ri.b4sgpwle2l" ,
"rtDW.pookhwl2ri.bfcbslmbdi" , "rtDW.hl5ibqcu3w.aquds3y3qy" ,
"rtDW.hl5ibqcu3w.b4sgpwle2l" , "rtDW.hl5ibqcu3w.bfcbslmbdi" ,
"rtDW.dffuptpbcz.i2hnwisoi1" , "rtDW.dffuptpbcz.fkmv4gfkl0" ,
"rtDW.dffuptpbcz.e3ed3ljbyn" , "rtDW.bd32gk0ocy.i2hnwisoi1" ,
"rtDW.bd32gk0ocy.fkmv4gfkl0" , "rtDW.bd32gk0ocy.e3ed3ljbyn" ,
"rtDW.leuhdrxpbe.ckwkdnls5w" , "rtDW.leuhdrxpbe.aqynsdznmr" ,
"rtDW.leuhdrxpbe.onahgr5syd" , "rtDW.csf3emrtxr.ckwkdnls5w" ,
"rtDW.csf3emrtxr.aqynsdznmr" , "rtDW.csf3emrtxr.onahgr5syd" ,
"rtDW.jvaexa3o5a.ckwkdnls5w" , "rtDW.jvaexa3o5a.aqynsdznmr" ,
"rtDW.jvaexa3o5a.onahgr5syd" , "rtDW.pcwoeb21pm.gxcgpda4hi" ,
"rtDW.pcwoeb21pm.jifjbgbgqy" , "rtDW.fthork0k0x2.gxcgpda4hi" ,
"rtDW.fthork0k0x2.jifjbgbgqy" , "rtDW.adqmzv0sx0[0].adrjjytrwd" ,
"rtDW.adqmzv0sx0[0].mirazmrnvl" , "rtDW.adqmzv0sx0[0].mczobgpj2t" ,
"rtDW.adqmzv0sx0[0].kd3fwxo3ke" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 165 , rtdwDataFieldNames ) ; int k0 ;
mxSetFieldByNumber ( rtdwData , 0 , 161 , mxCreateUninitNumericMatrix ( 1 ,
12 * sizeof ( rtDW . adqmzv0sx0 [ 0 ] . adrjjytrwd ) , mxUINT8_CLASS , mxREAL
) ) ; mxSetFieldByNumber ( rtdwData , 0 , 162 , mxCreateUninitNumericMatrix (
1 , 12 * sizeof ( rtDW . adqmzv0sx0 [ 0 ] . mirazmrnvl ) , mxUINT8_CLASS ,
mxREAL ) ) ; mxSetFieldByNumber ( rtdwData , 0 , 163 ,
mxCreateUninitNumericMatrix ( 1 , 12 * sizeof ( rtDW . adqmzv0sx0 [ 0 ] .
mczobgpj2t ) , mxUINT8_CLASS , mxREAL ) ) ; mxSetFieldByNumber ( rtdwData , 0
, 164 , mxCreateUninitNumericMatrix ( 1 , 12 * sizeof ( rtDW . adqmzv0sx0 [ 0
] . kd3fwxo3ke ) , mxUINT8_CLASS , mxREAL ) ) ; mr_UNIFIER_cacheDataAsMxArray
( rtdwData , 0 , 0 , ( const void * ) & ( rtDW . g540jxiiax ) , sizeof ( rtDW
. g540jxiiax ) ) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const
void * ) & ( rtDW . crxd5n2r3l ) , sizeof ( rtDW . crxd5n2r3l ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & ( rtDW
. fx230yq5sl ) , sizeof ( rtDW . fx230yq5sl ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW
. kvnpr153yy ) , sizeof ( rtDW . kvnpr153yy ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & ( rtDW
. jhfnsaqhxz ) , sizeof ( rtDW . jhfnsaqhxz ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & ( rtDW
. lnmqg4h42q ) , sizeof ( rtDW . lnmqg4h42q ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW
. jsnr5tvela ) , sizeof ( rtDW . jsnr5tvela ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & ( rtDW
. buecpeq4re ) , sizeof ( rtDW . buecpeq4re ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & ( rtDW
. asespk50pt ) , sizeof ( rtDW . asespk50pt ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & ( rtDW
. pmmx1tycaz ) , sizeof ( rtDW . pmmx1tycaz ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & ( rtDW
. e5trjt2azz ) , sizeof ( rtDW . e5trjt2azz ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & ( rtDW
. eqbrrfiebl ) , sizeof ( rtDW . eqbrrfiebl ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & ( rtDW
. fkbachhibk ) , sizeof ( rtDW . fkbachhibk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & ( rtDW
. oaqzp5s2cy ) , sizeof ( rtDW . oaqzp5s2cy ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & ( rtDW
. plokoj1iat ) , sizeof ( rtDW . plokoj1iat ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & ( rtDW
. p3n5g3torf ) , sizeof ( rtDW . p3n5g3torf ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & ( rtDW
. avagxvnwf5 ) , sizeof ( rtDW . avagxvnwf5 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & ( rtDW
. lkru3wc4bj ) , sizeof ( rtDW . lkru3wc4bj ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & ( rtDW
. pwrdd5kibs ) , sizeof ( rtDW . pwrdd5kibs ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & ( rtDW
. erskmg5gj1 ) , sizeof ( rtDW . erskmg5gj1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & ( rtDW
. jj43i52zwn ) , sizeof ( rtDW . jj43i52zwn ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & ( rtDW
. pagqs1iwpr ) , sizeof ( rtDW . pagqs1iwpr ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & ( rtDW
. hvagkay33y ) , sizeof ( rtDW . hvagkay33y ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & ( rtDW
. eoz1jvwwoq ) , sizeof ( rtDW . eoz1jvwwoq ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & ( rtDW
. jgluwzgfp1 ) , sizeof ( rtDW . jgluwzgfp1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & ( rtDW
. cpjltmd3l2 ) , sizeof ( rtDW . cpjltmd3l2 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & ( rtDW
. dcos1gkpc2 ) , sizeof ( rtDW . dcos1gkpc2 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & ( rtDW
. eypbisuusv ) , sizeof ( rtDW . eypbisuusv ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & ( rtDW
. ezpcxtf0ip ) , sizeof ( rtDW . ezpcxtf0ip ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & ( rtDW
. ookott5jvl ) , sizeof ( rtDW . ookott5jvl ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & ( rtDW
. h3h1h5xjyq ) , sizeof ( rtDW . h3h1h5xjyq ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & ( rtDW
. aadveypr3e ) , sizeof ( rtDW . aadveypr3e ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & ( rtDW
. nwwie5t5of ) , sizeof ( rtDW . nwwie5t5of ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & ( rtDW
. keywsrry0q ) , sizeof ( rtDW . keywsrry0q ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & ( rtDW
. kedw3dybgq ) , sizeof ( rtDW . kedw3dybgq ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) & ( rtDW
. ktsj2nkchd ) , sizeof ( rtDW . ktsj2nkchd ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) & ( rtDW
. oy300njhw2 ) , sizeof ( rtDW . oy300njhw2 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) & ( rtDW
. ie2l444zba ) , sizeof ( rtDW . ie2l444zba ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) & ( rtDW
. fr2fpc1qxz ) , sizeof ( rtDW . fr2fpc1qxz ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) & ( rtDW
. ilac1ylth3 ) , sizeof ( rtDW . ilac1ylth3 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void * ) & ( rtDW
. nevgeggqm5 ) , sizeof ( rtDW . nevgeggqm5 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) & ( rtDW
. lq4e3tdaf4 ) , sizeof ( rtDW . lq4e3tdaf4 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void * ) & ( rtDW
. ml2zybgolh ) , sizeof ( rtDW . ml2zybgolh ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void * ) & ( rtDW
. nndt0j2iyw ) , sizeof ( rtDW . nndt0j2iyw ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) & ( rtDW
. oxzbnowmim ) , sizeof ( rtDW . oxzbnowmim ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void * ) & ( rtDW
. csd33umrye ) , sizeof ( rtDW . csd33umrye ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void * ) & ( rtDW
. odfy0ab2zu ) , sizeof ( rtDW . odfy0ab2zu ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * ) & ( rtDW
. piktw1sptf ) , sizeof ( rtDW . piktw1sptf ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void * ) & ( rtDW
. iinforci3b ) , sizeof ( rtDW . iinforci3b ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void * ) & ( rtDW
. onpp1osnf1 ) , sizeof ( rtDW . onpp1osnf1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void * ) & ( rtDW
. knywr3cygt ) , sizeof ( rtDW . knywr3cygt ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void * ) & ( rtDW
. bxxehqrfhk ) , sizeof ( rtDW . bxxehqrfhk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void * ) & ( rtDW
. lybiwzq15a ) , sizeof ( rtDW . lybiwzq15a ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void * ) & ( rtDW
. hhpqcwloh0 ) , sizeof ( rtDW . hhpqcwloh0 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 54 , ( const void * ) & ( rtDW
. hxdxaozqh1 ) , sizeof ( rtDW . hxdxaozqh1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const void * ) & ( rtDW
. fknte5kkos ) , sizeof ( rtDW . fknte5kkos ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void * ) & ( rtDW
. mnfw2imvdw ) , sizeof ( rtDW . mnfw2imvdw ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const void * ) & ( rtDW
. felqedgyx1 ) , sizeof ( rtDW . felqedgyx1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const void * ) & ( rtDW
. knvjdfedfb ) , sizeof ( rtDW . knvjdfedfb ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 59 , ( const void * ) & ( rtDW
. apjnubwssp ) , sizeof ( rtDW . apjnubwssp ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 60 , ( const void * ) & ( rtDW
. ptu3l2ehpk ) , sizeof ( rtDW . ptu3l2ehpk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 61 , ( const void * ) & ( rtDW
. ebmg2d0djd ) , sizeof ( rtDW . ebmg2d0djd ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 62 , ( const void * ) & ( rtDW
. nmrn1j5ohh ) , sizeof ( rtDW . nmrn1j5ohh ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 63 , ( const void * ) & ( rtDW
. hl5ux0u3e5 ) , sizeof ( rtDW . hl5ux0u3e5 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 64 , ( const void * ) & ( rtDW
. kywikzuq0z ) , sizeof ( rtDW . kywikzuq0z ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 65 , ( const void * ) & ( rtDW
. op4s5nmfn0 ) , sizeof ( rtDW . op4s5nmfn0 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 66 , ( const void * ) & ( rtDW
. p3qcu4kyf3 ) , sizeof ( rtDW . p3qcu4kyf3 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 67 , ( const void * ) & ( rtDW
. d1rjlxqbuf ) , sizeof ( rtDW . d1rjlxqbuf ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 68 , ( const void * ) & ( rtDW
. g130c2x32o ) , sizeof ( rtDW . g130c2x32o ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 69 , ( const void * ) & ( rtDW
. dssqgth4gt ) , sizeof ( rtDW . dssqgth4gt ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 70 , ( const void * ) & ( rtDW
. erz4us2nfk ) , sizeof ( rtDW . erz4us2nfk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 71 , ( const void * ) & ( rtDW
. fyjcynthf1 ) , sizeof ( rtDW . fyjcynthf1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 72 , ( const void * ) & ( rtDW
. acn3fu00s1 ) , sizeof ( rtDW . acn3fu00s1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 73 , ( const void * ) & ( rtDW
. itcccsf0ct ) , sizeof ( rtDW . itcccsf0ct ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 74 , ( const void * ) & ( rtDW
. lipbrcbfzk ) , sizeof ( rtDW . lipbrcbfzk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 75 , ( const void * ) & ( rtDW
. md1fsm3br3 ) , sizeof ( rtDW . md1fsm3br3 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 76 , ( const void * ) & ( rtDW
. be05daasmg ) , sizeof ( rtDW . be05daasmg ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 77 , ( const void * ) & ( rtDW
. nq0rryljq1 ) , sizeof ( rtDW . nq0rryljq1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 78 , ( const void * ) & ( rtDW
. ddr4l0n5i3 ) , sizeof ( rtDW . ddr4l0n5i3 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 79 , ( const void * ) & ( rtDW
. by2jasgm4o ) , sizeof ( rtDW . by2jasgm4o ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 80 , ( const void * ) & ( rtDW
. daljbq5gtz ) , sizeof ( rtDW . daljbq5gtz ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 81 , ( const void * ) & ( rtDW
. l1l2gip32s ) , sizeof ( rtDW . l1l2gip32s ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 82 , ( const void * ) & ( rtDW
. lynamxwk0r ) , sizeof ( rtDW . lynamxwk0r ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 83 , ( const void * ) & ( rtDW
. nt5ueu32fc ) , sizeof ( rtDW . nt5ueu32fc ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 84 , ( const void * ) & ( rtDW
. ihk13omcli ) , sizeof ( rtDW . ihk13omcli ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 85 , ( const void * ) & ( rtDW
. iwurle5qux ) , sizeof ( rtDW . iwurle5qux ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 86 , ( const void * ) & ( rtDW
. pe511og3ku ) , sizeof ( rtDW . pe511og3ku ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 87 , ( const void * ) & ( rtDW
. ldrxgujyb0 ) , sizeof ( rtDW . ldrxgujyb0 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 88 , ( const void * ) & ( rtDW
. kksik1paup ) , sizeof ( rtDW . kksik1paup ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 89 , ( const void * ) & ( rtDW
. cbrsqgmwzt ) , sizeof ( rtDW . cbrsqgmwzt ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 90 , ( const void * ) & ( rtDW
. j1zkhtxhzf ) , sizeof ( rtDW . j1zkhtxhzf ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 91 , ( const void * ) & ( rtDW
. lfxnks51wi ) , sizeof ( rtDW . lfxnks51wi ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 92 , ( const void * ) & ( rtDW
. c5hzybmrlt ) , sizeof ( rtDW . c5hzybmrlt ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 93 , ( const void * ) & ( rtDW
. cfvgbkovvu ) , sizeof ( rtDW . cfvgbkovvu ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 94 , ( const void * ) & ( rtDW
. anhm4dpp2l ) , sizeof ( rtDW . anhm4dpp2l ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 95 , ( const void * ) & ( rtDW
. iw455stvt1 ) , sizeof ( rtDW . iw455stvt1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 96 , ( const void * ) & ( rtDW
. pakc2g42kk ) , sizeof ( rtDW . pakc2g42kk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 97 , ( const void * ) & ( rtDW
. oek5idxhme ) , sizeof ( rtDW . oek5idxhme ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 98 , ( const void * ) & ( rtDW
. bf5ec1ihjs ) , sizeof ( rtDW . bf5ec1ihjs ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 99 , ( const void * ) & ( rtDW
. d04ooymyox ) , sizeof ( rtDW . d04ooymyox ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 100 , ( const void * ) & (
rtDW . nmnxbsefd1 ) , sizeof ( rtDW . nmnxbsefd1 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 101 , ( const void * ) & (
rtDW . pny1rb4usr ) , sizeof ( rtDW . pny1rb4usr ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 102 , ( const void * ) & (
rtDW . chzc3nt2yy ) , sizeof ( rtDW . chzc3nt2yy ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 103 , ( const void * ) & (
rtDW . cg1cpca1ek ) , sizeof ( rtDW . cg1cpca1ek ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 104 , ( const void * ) & (
rtDW . hrnzbhxy5d ) , sizeof ( rtDW . hrnzbhxy5d ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 105 , ( const void * ) & (
rtDW . ikjcop0bgm ) , sizeof ( rtDW . ikjcop0bgm ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 106 , ( const void * ) & (
rtDW . p2ctlaxtsk ) , sizeof ( rtDW . p2ctlaxtsk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 107 , ( const void * ) & (
rtDW . bp4ac3vvj5 ) , sizeof ( rtDW . bp4ac3vvj5 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 108 , ( const void * ) & (
rtDW . jl5nu1i4l3 ) , sizeof ( rtDW . jl5nu1i4l3 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 109 , ( const void * ) & (
rtDW . lh250aajbj ) , sizeof ( rtDW . lh250aajbj ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 110 , ( const void * ) & (
rtDW . edqryqv5bk ) , sizeof ( rtDW . edqryqv5bk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 111 , ( const void * ) & (
rtDW . l3qjgn1jqc ) , sizeof ( rtDW . l3qjgn1jqc ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 112 , ( const void * ) & (
rtDW . cyto13o4kt ) , sizeof ( rtDW . cyto13o4kt ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 113 , ( const void * ) & (
rtDW . jgpyhmovpk ) , sizeof ( rtDW . jgpyhmovpk ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 114 , ( const void * ) & (
rtDW . mu4revjjwi ) , sizeof ( rtDW . mu4revjjwi ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 115 , ( const void * ) & (
rtDW . pdvyjvvslc ) , sizeof ( rtDW . pdvyjvvslc ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 116 , ( const void * ) & (
rtDW . kbyn225ku2 ) , sizeof ( rtDW . kbyn225ku2 ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 117 , ( const void * ) & (
rtDW . o5u4b02npb ) , sizeof ( rtDW . o5u4b02npb ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 118 , ( const void * ) & (
rtDW . jcdq2ohx3t ) , sizeof ( rtDW . jcdq2ohx3t ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 119 , ( const void * ) & (
rtDW . bwa1fip2ky ) , sizeof ( rtDW . bwa1fip2ky ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 120 , ( const void * ) & (
rtDW . pi3jxhaf2b ) , sizeof ( rtDW . pi3jxhaf2b ) ) ;
mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 121 , ( const void * ) & (
rtDW . hztlwupntw . apnlfrnpo3 ) , sizeof ( rtDW . hztlwupntw . apnlfrnpo3 )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 122 , ( const void * ) & (
rtDW . hztlwupntw . ovvez5xelu ) , sizeof ( rtDW . hztlwupntw . ovvez5xelu )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 123 , ( const void * ) & (
rtDW . hztlwupntw . dtz1ggkdpo ) , sizeof ( rtDW . hztlwupntw . dtz1ggkdpo )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 124 , ( const void * ) & (
rtDW . n1ybyykngv . apnlfrnpo3 ) , sizeof ( rtDW . n1ybyykngv . apnlfrnpo3 )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 125 , ( const void * ) & (
rtDW . n1ybyykngv . ovvez5xelu ) , sizeof ( rtDW . n1ybyykngv . ovvez5xelu )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 126 , ( const void * ) & (
rtDW . n1ybyykngv . dtz1ggkdpo ) , sizeof ( rtDW . n1ybyykngv . dtz1ggkdpo )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 127 , ( const void * ) & (
rtDW . jek5zaxern . datl4fzkmc ) , sizeof ( rtDW . jek5zaxern . datl4fzkmc )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 128 , ( const void * ) & (
rtDW . jek5zaxern . op350srgbo ) , sizeof ( rtDW . jek5zaxern . op350srgbo )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 129 , ( const void * ) & (
rtDW . jek5zaxern . eiaswshrvs ) , sizeof ( rtDW . jek5zaxern . eiaswshrvs )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 130 , ( const void * ) & (
rtDW . nikuyjvr0y . datl4fzkmc ) , sizeof ( rtDW . nikuyjvr0y . datl4fzkmc )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 131 , ( const void * ) & (
rtDW . nikuyjvr0y . op350srgbo ) , sizeof ( rtDW . nikuyjvr0y . op350srgbo )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 132 , ( const void * ) & (
rtDW . nikuyjvr0y . eiaswshrvs ) , sizeof ( rtDW . nikuyjvr0y . eiaswshrvs )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 133 , ( const void * ) & (
rtDW . enohy5yaap . datl4fzkmc ) , sizeof ( rtDW . enohy5yaap . datl4fzkmc )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 134 , ( const void * ) & (
rtDW . enohy5yaap . op350srgbo ) , sizeof ( rtDW . enohy5yaap . op350srgbo )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 135 , ( const void * ) & (
rtDW . enohy5yaap . eiaswshrvs ) , sizeof ( rtDW . enohy5yaap . eiaswshrvs )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 136 , ( const void * ) & (
rtDW . pookhwl2ri . aquds3y3qy ) , sizeof ( rtDW . pookhwl2ri . aquds3y3qy )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 137 , ( const void * ) & (
rtDW . pookhwl2ri . b4sgpwle2l ) , sizeof ( rtDW . pookhwl2ri . b4sgpwle2l )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 138 , ( const void * ) & (
rtDW . pookhwl2ri . bfcbslmbdi ) , sizeof ( rtDW . pookhwl2ri . bfcbslmbdi )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 139 , ( const void * ) & (
rtDW . hl5ibqcu3w . aquds3y3qy ) , sizeof ( rtDW . hl5ibqcu3w . aquds3y3qy )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 140 , ( const void * ) & (
rtDW . hl5ibqcu3w . b4sgpwle2l ) , sizeof ( rtDW . hl5ibqcu3w . b4sgpwle2l )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 141 , ( const void * ) & (
rtDW . hl5ibqcu3w . bfcbslmbdi ) , sizeof ( rtDW . hl5ibqcu3w . bfcbslmbdi )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 142 , ( const void * ) & (
rtDW . dffuptpbcz . i2hnwisoi1 ) , sizeof ( rtDW . dffuptpbcz . i2hnwisoi1 )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 143 , ( const void * ) & (
rtDW . dffuptpbcz . fkmv4gfkl0 ) , sizeof ( rtDW . dffuptpbcz . fkmv4gfkl0 )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 144 , ( const void * ) & (
rtDW . dffuptpbcz . e3ed3ljbyn ) , sizeof ( rtDW . dffuptpbcz . e3ed3ljbyn )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 145 , ( const void * ) & (
rtDW . bd32gk0ocy . i2hnwisoi1 ) , sizeof ( rtDW . bd32gk0ocy . i2hnwisoi1 )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 146 , ( const void * ) & (
rtDW . bd32gk0ocy . fkmv4gfkl0 ) , sizeof ( rtDW . bd32gk0ocy . fkmv4gfkl0 )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 147 , ( const void * ) & (
rtDW . bd32gk0ocy . e3ed3ljbyn ) , sizeof ( rtDW . bd32gk0ocy . e3ed3ljbyn )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 148 , ( const void * ) & (
rtDW . leuhdrxpbe . ckwkdnls5w ) , sizeof ( rtDW . leuhdrxpbe . ckwkdnls5w )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 149 , ( const void * ) & (
rtDW . leuhdrxpbe . aqynsdznmr ) , sizeof ( rtDW . leuhdrxpbe . aqynsdznmr )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 150 , ( const void * ) & (
rtDW . leuhdrxpbe . onahgr5syd ) , sizeof ( rtDW . leuhdrxpbe . onahgr5syd )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 151 , ( const void * ) & (
rtDW . csf3emrtxr . ckwkdnls5w ) , sizeof ( rtDW . csf3emrtxr . ckwkdnls5w )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 152 , ( const void * ) & (
rtDW . csf3emrtxr . aqynsdznmr ) , sizeof ( rtDW . csf3emrtxr . aqynsdznmr )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 153 , ( const void * ) & (
rtDW . csf3emrtxr . onahgr5syd ) , sizeof ( rtDW . csf3emrtxr . onahgr5syd )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 154 , ( const void * ) & (
rtDW . jvaexa3o5a . ckwkdnls5w ) , sizeof ( rtDW . jvaexa3o5a . ckwkdnls5w )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 155 , ( const void * ) & (
rtDW . jvaexa3o5a . aqynsdznmr ) , sizeof ( rtDW . jvaexa3o5a . aqynsdznmr )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 156 , ( const void * ) & (
rtDW . jvaexa3o5a . onahgr5syd ) , sizeof ( rtDW . jvaexa3o5a . onahgr5syd )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 157 , ( const void * ) & (
rtDW . pcwoeb21pm . gxcgpda4hi ) , sizeof ( rtDW . pcwoeb21pm . gxcgpda4hi )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 158 , ( const void * ) & (
rtDW . pcwoeb21pm . jifjbgbgqy ) , sizeof ( rtDW . pcwoeb21pm . jifjbgbgqy )
) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 159 , ( const void * ) & (
rtDW . fthork0k0x2 . gxcgpda4hi ) , sizeof ( rtDW . fthork0k0x2 . gxcgpda4hi
) ) ; mr_UNIFIER_cacheDataAsMxArray ( rtdwData , 0 , 160 , ( const void * ) &
( rtDW . fthork0k0x2 . jifjbgbgqy ) , sizeof ( rtDW . fthork0k0x2 .
jifjbgbgqy ) ) ; for ( k0 = 0 ; k0 < 12 ; ++ k0 ) { const mwIndex offset0 =
k0 ; mr_UNIFIER_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 161 , offset0 ,
& ( rtDW . adqmzv0sx0 [ k0 ] . adrjjytrwd ) , sizeof ( rtDW . adqmzv0sx0 [ 0
] . adrjjytrwd ) ) ; mr_UNIFIER_cacheDataToMxArrayWithOffset ( rtdwData , 0 ,
162 , offset0 , & ( rtDW . adqmzv0sx0 [ k0 ] . mirazmrnvl ) , sizeof ( rtDW .
adqmzv0sx0 [ 0 ] . mirazmrnvl ) ) ; mr_UNIFIER_cacheDataToMxArrayWithOffset (
rtdwData , 0 , 163 , offset0 , & ( rtDW . adqmzv0sx0 [ k0 ] . mczobgpj2t ) ,
sizeof ( rtDW . adqmzv0sx0 [ 0 ] . mczobgpj2t ) ) ;
mr_UNIFIER_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 164 , offset0 , & (
rtDW . adqmzv0sx0 [ k0 ] . kd3fwxo3ke ) , sizeof ( rtDW . adqmzv0sx0 [ 0 ] .
kd3fwxo3ke ) ) ; } mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; }
mr_UNIFIER_cacheDataAsMxArray ( ssDW , 0 , 2 , ( const void * ) & ( rtPrevZCX
) , sizeof ( rtPrevZCX ) ) ; return ssDW ; } void mr_UNIFIER_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_UNIFIER_restoreDataFromMxArray ( ( void
* ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ; int k0 ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . g540jxiiax ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . g540jxiiax ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . crxd5n2r3l ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . crxd5n2r3l ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fx230yq5sl ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . fx230yq5sl ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . kvnpr153yy ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . kvnpr153yy ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jhfnsaqhxz ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . jhfnsaqhxz ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lnmqg4h42q ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . lnmqg4h42q ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jsnr5tvela ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . jsnr5tvela ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . buecpeq4re ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . buecpeq4re ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . asespk50pt ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . asespk50pt ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pmmx1tycaz ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . pmmx1tycaz ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . e5trjt2azz ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . e5trjt2azz ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . eqbrrfiebl ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . eqbrrfiebl ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fkbachhibk ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . fkbachhibk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . oaqzp5s2cy ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . oaqzp5s2cy ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . plokoj1iat ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . plokoj1iat ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . p3n5g3torf ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . p3n5g3torf ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . avagxvnwf5 ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . avagxvnwf5 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lkru3wc4bj ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . lkru3wc4bj ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pwrdd5kibs ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . pwrdd5kibs ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . erskmg5gj1 ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . erskmg5gj1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jj43i52zwn ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . jj43i52zwn ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pagqs1iwpr ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . pagqs1iwpr ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hvagkay33y ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . hvagkay33y ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . eoz1jvwwoq ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . eoz1jvwwoq ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jgluwzgfp1 ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . jgluwzgfp1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . cpjltmd3l2 ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . cpjltmd3l2 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . dcos1gkpc2 ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . dcos1gkpc2 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . eypbisuusv ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . eypbisuusv ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ezpcxtf0ip ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . ezpcxtf0ip ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ookott5jvl ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . ookott5jvl ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . h3h1h5xjyq ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . h3h1h5xjyq ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . aadveypr3e ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . aadveypr3e ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nwwie5t5of ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . nwwie5t5of ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . keywsrry0q ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . keywsrry0q ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . kedw3dybgq ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . kedw3dybgq ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ktsj2nkchd ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . ktsj2nkchd ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . oy300njhw2 ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . oy300njhw2 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ie2l444zba ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . ie2l444zba ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fr2fpc1qxz ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . fr2fpc1qxz ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ilac1ylth3 ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . ilac1ylth3 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nevgeggqm5 ) ,
rtdwData , 0 , 40 , sizeof ( rtDW . nevgeggqm5 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lq4e3tdaf4 ) ,
rtdwData , 0 , 41 , sizeof ( rtDW . lq4e3tdaf4 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ml2zybgolh ) ,
rtdwData , 0 , 42 , sizeof ( rtDW . ml2zybgolh ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nndt0j2iyw ) ,
rtdwData , 0 , 43 , sizeof ( rtDW . nndt0j2iyw ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . oxzbnowmim ) ,
rtdwData , 0 , 44 , sizeof ( rtDW . oxzbnowmim ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . csd33umrye ) ,
rtdwData , 0 , 45 , sizeof ( rtDW . csd33umrye ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . odfy0ab2zu ) ,
rtdwData , 0 , 46 , sizeof ( rtDW . odfy0ab2zu ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . piktw1sptf ) ,
rtdwData , 0 , 47 , sizeof ( rtDW . piktw1sptf ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . iinforci3b ) ,
rtdwData , 0 , 48 , sizeof ( rtDW . iinforci3b ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . onpp1osnf1 ) ,
rtdwData , 0 , 49 , sizeof ( rtDW . onpp1osnf1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . knywr3cygt ) ,
rtdwData , 0 , 50 , sizeof ( rtDW . knywr3cygt ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bxxehqrfhk ) ,
rtdwData , 0 , 51 , sizeof ( rtDW . bxxehqrfhk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lybiwzq15a ) ,
rtdwData , 0 , 52 , sizeof ( rtDW . lybiwzq15a ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hhpqcwloh0 ) ,
rtdwData , 0 , 53 , sizeof ( rtDW . hhpqcwloh0 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hxdxaozqh1 ) ,
rtdwData , 0 , 54 , sizeof ( rtDW . hxdxaozqh1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fknte5kkos ) ,
rtdwData , 0 , 55 , sizeof ( rtDW . fknte5kkos ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . mnfw2imvdw ) ,
rtdwData , 0 , 56 , sizeof ( rtDW . mnfw2imvdw ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . felqedgyx1 ) ,
rtdwData , 0 , 57 , sizeof ( rtDW . felqedgyx1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . knvjdfedfb ) ,
rtdwData , 0 , 58 , sizeof ( rtDW . knvjdfedfb ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . apjnubwssp ) ,
rtdwData , 0 , 59 , sizeof ( rtDW . apjnubwssp ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ptu3l2ehpk ) ,
rtdwData , 0 , 60 , sizeof ( rtDW . ptu3l2ehpk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ebmg2d0djd ) ,
rtdwData , 0 , 61 , sizeof ( rtDW . ebmg2d0djd ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nmrn1j5ohh ) ,
rtdwData , 0 , 62 , sizeof ( rtDW . nmrn1j5ohh ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hl5ux0u3e5 ) ,
rtdwData , 0 , 63 , sizeof ( rtDW . hl5ux0u3e5 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . kywikzuq0z ) ,
rtdwData , 0 , 64 , sizeof ( rtDW . kywikzuq0z ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . op4s5nmfn0 ) ,
rtdwData , 0 , 65 , sizeof ( rtDW . op4s5nmfn0 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . p3qcu4kyf3 ) ,
rtdwData , 0 , 66 , sizeof ( rtDW . p3qcu4kyf3 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . d1rjlxqbuf ) ,
rtdwData , 0 , 67 , sizeof ( rtDW . d1rjlxqbuf ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . g130c2x32o ) ,
rtdwData , 0 , 68 , sizeof ( rtDW . g130c2x32o ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . dssqgth4gt ) ,
rtdwData , 0 , 69 , sizeof ( rtDW . dssqgth4gt ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . erz4us2nfk ) ,
rtdwData , 0 , 70 , sizeof ( rtDW . erz4us2nfk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fyjcynthf1 ) ,
rtdwData , 0 , 71 , sizeof ( rtDW . fyjcynthf1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . acn3fu00s1 ) ,
rtdwData , 0 , 72 , sizeof ( rtDW . acn3fu00s1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . itcccsf0ct ) ,
rtdwData , 0 , 73 , sizeof ( rtDW . itcccsf0ct ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lipbrcbfzk ) ,
rtdwData , 0 , 74 , sizeof ( rtDW . lipbrcbfzk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . md1fsm3br3 ) ,
rtdwData , 0 , 75 , sizeof ( rtDW . md1fsm3br3 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . be05daasmg ) ,
rtdwData , 0 , 76 , sizeof ( rtDW . be05daasmg ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nq0rryljq1 ) ,
rtdwData , 0 , 77 , sizeof ( rtDW . nq0rryljq1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ddr4l0n5i3 ) ,
rtdwData , 0 , 78 , sizeof ( rtDW . ddr4l0n5i3 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . by2jasgm4o ) ,
rtdwData , 0 , 79 , sizeof ( rtDW . by2jasgm4o ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . daljbq5gtz ) ,
rtdwData , 0 , 80 , sizeof ( rtDW . daljbq5gtz ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . l1l2gip32s ) ,
rtdwData , 0 , 81 , sizeof ( rtDW . l1l2gip32s ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lynamxwk0r ) ,
rtdwData , 0 , 82 , sizeof ( rtDW . lynamxwk0r ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nt5ueu32fc ) ,
rtdwData , 0 , 83 , sizeof ( rtDW . nt5ueu32fc ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ihk13omcli ) ,
rtdwData , 0 , 84 , sizeof ( rtDW . ihk13omcli ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . iwurle5qux ) ,
rtdwData , 0 , 85 , sizeof ( rtDW . iwurle5qux ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pe511og3ku ) ,
rtdwData , 0 , 86 , sizeof ( rtDW . pe511og3ku ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ldrxgujyb0 ) ,
rtdwData , 0 , 87 , sizeof ( rtDW . ldrxgujyb0 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . kksik1paup ) ,
rtdwData , 0 , 88 , sizeof ( rtDW . kksik1paup ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . cbrsqgmwzt ) ,
rtdwData , 0 , 89 , sizeof ( rtDW . cbrsqgmwzt ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . j1zkhtxhzf ) ,
rtdwData , 0 , 90 , sizeof ( rtDW . j1zkhtxhzf ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lfxnks51wi ) ,
rtdwData , 0 , 91 , sizeof ( rtDW . lfxnks51wi ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . c5hzybmrlt ) ,
rtdwData , 0 , 92 , sizeof ( rtDW . c5hzybmrlt ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . cfvgbkovvu ) ,
rtdwData , 0 , 93 , sizeof ( rtDW . cfvgbkovvu ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . anhm4dpp2l ) ,
rtdwData , 0 , 94 , sizeof ( rtDW . anhm4dpp2l ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . iw455stvt1 ) ,
rtdwData , 0 , 95 , sizeof ( rtDW . iw455stvt1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pakc2g42kk ) ,
rtdwData , 0 , 96 , sizeof ( rtDW . pakc2g42kk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . oek5idxhme ) ,
rtdwData , 0 , 97 , sizeof ( rtDW . oek5idxhme ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bf5ec1ihjs ) ,
rtdwData , 0 , 98 , sizeof ( rtDW . bf5ec1ihjs ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . d04ooymyox ) ,
rtdwData , 0 , 99 , sizeof ( rtDW . d04ooymyox ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nmnxbsefd1 ) ,
rtdwData , 0 , 100 , sizeof ( rtDW . nmnxbsefd1 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pny1rb4usr ) ,
rtdwData , 0 , 101 , sizeof ( rtDW . pny1rb4usr ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . chzc3nt2yy ) ,
rtdwData , 0 , 102 , sizeof ( rtDW . chzc3nt2yy ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . cg1cpca1ek ) ,
rtdwData , 0 , 103 , sizeof ( rtDW . cg1cpca1ek ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hrnzbhxy5d ) ,
rtdwData , 0 , 104 , sizeof ( rtDW . hrnzbhxy5d ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . ikjcop0bgm ) ,
rtdwData , 0 , 105 , sizeof ( rtDW . ikjcop0bgm ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . p2ctlaxtsk ) ,
rtdwData , 0 , 106 , sizeof ( rtDW . p2ctlaxtsk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bp4ac3vvj5 ) ,
rtdwData , 0 , 107 , sizeof ( rtDW . bp4ac3vvj5 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jl5nu1i4l3 ) ,
rtdwData , 0 , 108 , sizeof ( rtDW . jl5nu1i4l3 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . lh250aajbj ) ,
rtdwData , 0 , 109 , sizeof ( rtDW . lh250aajbj ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . edqryqv5bk ) ,
rtdwData , 0 , 110 , sizeof ( rtDW . edqryqv5bk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . l3qjgn1jqc ) ,
rtdwData , 0 , 111 , sizeof ( rtDW . l3qjgn1jqc ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . cyto13o4kt ) ,
rtdwData , 0 , 112 , sizeof ( rtDW . cyto13o4kt ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jgpyhmovpk ) ,
rtdwData , 0 , 113 , sizeof ( rtDW . jgpyhmovpk ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . mu4revjjwi ) ,
rtdwData , 0 , 114 , sizeof ( rtDW . mu4revjjwi ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pdvyjvvslc ) ,
rtdwData , 0 , 115 , sizeof ( rtDW . pdvyjvvslc ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . kbyn225ku2 ) ,
rtdwData , 0 , 116 , sizeof ( rtDW . kbyn225ku2 ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . o5u4b02npb ) ,
rtdwData , 0 , 117 , sizeof ( rtDW . o5u4b02npb ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jcdq2ohx3t ) ,
rtdwData , 0 , 118 , sizeof ( rtDW . jcdq2ohx3t ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bwa1fip2ky ) ,
rtdwData , 0 , 119 , sizeof ( rtDW . bwa1fip2ky ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pi3jxhaf2b ) ,
rtdwData , 0 , 120 , sizeof ( rtDW . pi3jxhaf2b ) ) ;
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hztlwupntw .
apnlfrnpo3 ) , rtdwData , 0 , 121 , sizeof ( rtDW . hztlwupntw . apnlfrnpo3 )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hztlwupntw .
ovvez5xelu ) , rtdwData , 0 , 122 , sizeof ( rtDW . hztlwupntw . ovvez5xelu )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hztlwupntw .
dtz1ggkdpo ) , rtdwData , 0 , 123 , sizeof ( rtDW . hztlwupntw . dtz1ggkdpo )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . n1ybyykngv .
apnlfrnpo3 ) , rtdwData , 0 , 124 , sizeof ( rtDW . n1ybyykngv . apnlfrnpo3 )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . n1ybyykngv .
ovvez5xelu ) , rtdwData , 0 , 125 , sizeof ( rtDW . n1ybyykngv . ovvez5xelu )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . n1ybyykngv .
dtz1ggkdpo ) , rtdwData , 0 , 126 , sizeof ( rtDW . n1ybyykngv . dtz1ggkdpo )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jek5zaxern .
datl4fzkmc ) , rtdwData , 0 , 127 , sizeof ( rtDW . jek5zaxern . datl4fzkmc )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jek5zaxern .
op350srgbo ) , rtdwData , 0 , 128 , sizeof ( rtDW . jek5zaxern . op350srgbo )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jek5zaxern .
eiaswshrvs ) , rtdwData , 0 , 129 , sizeof ( rtDW . jek5zaxern . eiaswshrvs )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nikuyjvr0y .
datl4fzkmc ) , rtdwData , 0 , 130 , sizeof ( rtDW . nikuyjvr0y . datl4fzkmc )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nikuyjvr0y .
op350srgbo ) , rtdwData , 0 , 131 , sizeof ( rtDW . nikuyjvr0y . op350srgbo )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . nikuyjvr0y .
eiaswshrvs ) , rtdwData , 0 , 132 , sizeof ( rtDW . nikuyjvr0y . eiaswshrvs )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . enohy5yaap .
datl4fzkmc ) , rtdwData , 0 , 133 , sizeof ( rtDW . enohy5yaap . datl4fzkmc )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . enohy5yaap .
op350srgbo ) , rtdwData , 0 , 134 , sizeof ( rtDW . enohy5yaap . op350srgbo )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . enohy5yaap .
eiaswshrvs ) , rtdwData , 0 , 135 , sizeof ( rtDW . enohy5yaap . eiaswshrvs )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pookhwl2ri .
aquds3y3qy ) , rtdwData , 0 , 136 , sizeof ( rtDW . pookhwl2ri . aquds3y3qy )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pookhwl2ri .
b4sgpwle2l ) , rtdwData , 0 , 137 , sizeof ( rtDW . pookhwl2ri . b4sgpwle2l )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pookhwl2ri .
bfcbslmbdi ) , rtdwData , 0 , 138 , sizeof ( rtDW . pookhwl2ri . bfcbslmbdi )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hl5ibqcu3w .
aquds3y3qy ) , rtdwData , 0 , 139 , sizeof ( rtDW . hl5ibqcu3w . aquds3y3qy )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hl5ibqcu3w .
b4sgpwle2l ) , rtdwData , 0 , 140 , sizeof ( rtDW . hl5ibqcu3w . b4sgpwle2l )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . hl5ibqcu3w .
bfcbslmbdi ) , rtdwData , 0 , 141 , sizeof ( rtDW . hl5ibqcu3w . bfcbslmbdi )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . dffuptpbcz .
i2hnwisoi1 ) , rtdwData , 0 , 142 , sizeof ( rtDW . dffuptpbcz . i2hnwisoi1 )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . dffuptpbcz .
fkmv4gfkl0 ) , rtdwData , 0 , 143 , sizeof ( rtDW . dffuptpbcz . fkmv4gfkl0 )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . dffuptpbcz .
e3ed3ljbyn ) , rtdwData , 0 , 144 , sizeof ( rtDW . dffuptpbcz . e3ed3ljbyn )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bd32gk0ocy .
i2hnwisoi1 ) , rtdwData , 0 , 145 , sizeof ( rtDW . bd32gk0ocy . i2hnwisoi1 )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bd32gk0ocy .
fkmv4gfkl0 ) , rtdwData , 0 , 146 , sizeof ( rtDW . bd32gk0ocy . fkmv4gfkl0 )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . bd32gk0ocy .
e3ed3ljbyn ) , rtdwData , 0 , 147 , sizeof ( rtDW . bd32gk0ocy . e3ed3ljbyn )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . leuhdrxpbe .
ckwkdnls5w ) , rtdwData , 0 , 148 , sizeof ( rtDW . leuhdrxpbe . ckwkdnls5w )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . leuhdrxpbe .
aqynsdznmr ) , rtdwData , 0 , 149 , sizeof ( rtDW . leuhdrxpbe . aqynsdznmr )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . leuhdrxpbe .
onahgr5syd ) , rtdwData , 0 , 150 , sizeof ( rtDW . leuhdrxpbe . onahgr5syd )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . csf3emrtxr .
ckwkdnls5w ) , rtdwData , 0 , 151 , sizeof ( rtDW . csf3emrtxr . ckwkdnls5w )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . csf3emrtxr .
aqynsdznmr ) , rtdwData , 0 , 152 , sizeof ( rtDW . csf3emrtxr . aqynsdznmr )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . csf3emrtxr .
onahgr5syd ) , rtdwData , 0 , 153 , sizeof ( rtDW . csf3emrtxr . onahgr5syd )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jvaexa3o5a .
ckwkdnls5w ) , rtdwData , 0 , 154 , sizeof ( rtDW . jvaexa3o5a . ckwkdnls5w )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jvaexa3o5a .
aqynsdznmr ) , rtdwData , 0 , 155 , sizeof ( rtDW . jvaexa3o5a . aqynsdznmr )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . jvaexa3o5a .
onahgr5syd ) , rtdwData , 0 , 156 , sizeof ( rtDW . jvaexa3o5a . onahgr5syd )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pcwoeb21pm .
gxcgpda4hi ) , rtdwData , 0 , 157 , sizeof ( rtDW . pcwoeb21pm . gxcgpda4hi )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . pcwoeb21pm .
jifjbgbgqy ) , rtdwData , 0 , 158 , sizeof ( rtDW . pcwoeb21pm . jifjbgbgqy )
) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fthork0k0x2 .
gxcgpda4hi ) , rtdwData , 0 , 159 , sizeof ( rtDW . fthork0k0x2 . gxcgpda4hi
) ) ; mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtDW . fthork0k0x2 .
jifjbgbgqy ) , rtdwData , 0 , 160 , sizeof ( rtDW . fthork0k0x2 . jifjbgbgqy
) ) ; for ( k0 = 0 ; k0 < 12 ; ++ k0 ) { const mwIndex offset0 = k0 ;
mr_UNIFIER_restoreDataFromMxArrayWithOffset ( & ( rtDW . adqmzv0sx0 [ k0 ] .
adrjjytrwd ) , rtdwData , 0 , 161 , offset0 , sizeof ( rtDW . adqmzv0sx0 [ 0
] . adrjjytrwd ) ) ; mr_UNIFIER_restoreDataFromMxArrayWithOffset ( & ( rtDW .
adqmzv0sx0 [ k0 ] . mirazmrnvl ) , rtdwData , 0 , 162 , offset0 , sizeof (
rtDW . adqmzv0sx0 [ 0 ] . mirazmrnvl ) ) ;
mr_UNIFIER_restoreDataFromMxArrayWithOffset ( & ( rtDW . adqmzv0sx0 [ k0 ] .
mczobgpj2t ) , rtdwData , 0 , 163 , offset0 , sizeof ( rtDW . adqmzv0sx0 [ 0
] . mczobgpj2t ) ) ; mr_UNIFIER_restoreDataFromMxArrayWithOffset ( & ( rtDW .
adqmzv0sx0 [ k0 ] . kd3fwxo3ke ) , rtdwData , 0 , 164 , offset0 , sizeof (
rtDW . adqmzv0sx0 [ 0 ] . kd3fwxo3ke ) ) ; } }
mr_UNIFIER_restoreDataFromMxArray ( ( void * ) & ( rtPrevZCX ) , ssDW , 0 , 2
, sizeof ( rtPrevZCX ) ) ; } mxArray * mr_UNIFIER_GetSimStateDisallowedBlocks
( ) { mxArray * data = mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] ,
offset ; { static const char_T * blockType [ 10 ] = { "Scope" , "Scope" ,
"Scope" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope"
, } ; static const char_T * blockPath [ 10 ] = {
"UNIFIER/X_PLANE_VISUALS/DEPSpinning/Scope" ,
"UNIFIER/X_PLANE_VISUALS/PusherSpinning/Scope" ,
"UNIFIER/C7A_HARW/Scopes/pqr_dot" , "UNIFIER/C7A_HARW/Scopes/uvw_dot" ,
"UNIFIER/C7A_HARW/Scopes/pqr" , "UNIFIER/C7A_HARW/Scopes/uvw" ,
"UNIFIER/C7A_HARW/Scopes/phithetapsi" , "UNIFIER/C7A_HARW/Scopes/xyz" ,
"UNIFIER/C7A_HARW/Scopes/Vrw_mag" , "UNIFIER/C7A_HARW/Scopes/alphabeta" , } ;
static const int reason [ 10 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , }
; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] =
0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
97 ) ; ssSetNumPeriodicContStates ( rtS , 3 ) ; ssSetNumY ( rtS , 0 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 1392 ) ;
ssSetNumBlockIO ( rtS , 226 ) ; ssSetNumBlockParams ( rtS , 1930 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.002 ) ; ssSetSampleTime ( rtS , 2 , 0.01 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 4207121147U ) ; ssSetChecksumVal ( rtS , 1 ,
2496750584U ) ; ssSetChecksumVal ( rtS , 2 , 3458008039U ) ; ssSetChecksumVal
( rtS , 3 , 3961977088U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char_T * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo ,
0 , sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) &
blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T *
) & blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ;
ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , &
blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo (
rtS , executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T
mdlPeriod [ NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ;
static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [
NSAMPLE_TIMES ] ; static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static
boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T
mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T
mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i <
NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { real_T * x
= ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void
* ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ;
ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW )
) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) &
dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ;
dtInfo . numDataTypes = 34 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ]
; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } UNIFIER_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"UNIFIER" ) ; ssSetPath ( rtS , "UNIFIER" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 60.0 ) ; ssSetStepSize ( rtS , 0.002 ) ;
ssSetFixedStepSize ( rtS , 0.002 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 3
, 3 , 3 , 2 , 12 , 12 , 12 , 2 , 2 , 2 , 2 , 6 , 6 , 1 , 1 , 1 , 100 , 100 ,
5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 15 , 45 , 5 , 15 , 15 , 15 , 5 , 5 , 5 ,
5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 3 , 3 , 3 , 3 , 2 , 12
, 12 , 12 , 2 , 2 , 2 , 2 , 6 , 6 , 1 , 1 , 1 , 100 , 100 , 5 , 5 , 5 , 5 , 5
, 5 , 5 , 5 , 5 , 15 , 45 , 5 , 15 , 15 , 15 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5
, 5 , 5 , 5 , 5 , 5 , 5 , 5 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
} ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"UNIFIER/C7A_HARW/EOMandEnviroment1/EOM: 6DOF (Euler Angles)/xe,ye,ze" ,
 "UNIFIER/C7A_HARW/EOMandEnviroment1/EOM: 6DOF (Euler Angles)/Calculate DCM &\nEuler Angles/phi\ntheta\npsi"
, "UNIFIER/C7A_HARW/EOMandEnviroment1/EOM: 6DOF (Euler Angles)/ub,vb,wb" ,
"UNIFIER/C7A_HARW/EOMandEnviroment1/EOM: 6DOF (Euler Angles)/p,q,r " ,
 "UNIFIER/C7A_HARW/Subsystems/HTU/PropAndMotor/Linear Second-Order Actuator/Integrator,\nSecond-Order"
, "UNIFIER/SENSORS/Linear Second-Order Actuator/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator1/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator2/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator3/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator4/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator5/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator6/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator7/Integrator,\nSecond-Order" ,
"UNIFIER/SENSORS/Linear Second-Order Actuator8/Integrator,\nSecond-Order" ,
 "UNIFIER/C7A_HARW/EOMandEnviroment1/Enviroment/Wind model/Discrete Wind Gust Model1/Distance into\ngust (z)/Distance into\nGust (x)\n(Limited to gust length d)\n"
,
 "UNIFIER/C7A_HARW/EOMandEnviroment1/Enviroment/Wind model/Discrete Wind Gust Model1/Distance into\ngust (y)/Distance into\nGust (x)\n(Limited to gust length d)\n"
,
 "UNIFIER/C7A_HARW/EOMandEnviroment1/Enviroment/Wind model/Discrete Wind Gust Model1/Distance into\ngust (x)/Distance into\nGust (x)\n(Limited to gust length d)"
, "UNIFIER/C7A_HARW/Actuator processing \nand transport delay\n10 ms" ,
"UNIFIER/C7A_HARW/FCC frame delay\n10 ms\n(assumed 100Hz FCC)" ,
"UNIFIER/SENSORS/Delay1" , "UNIFIER/SENSORS/Delay10" ,
"UNIFIER/SENSORS/Delay11" , "UNIFIER/SENSORS/Delay12" ,
"UNIFIER/SENSORS/Delay13" , "UNIFIER/SENSORS/Delay14" ,
"UNIFIER/SENSORS/Delay15" , "UNIFIER/SENSORS/Delay16" ,
"UNIFIER/SENSORS/Delay17" , "UNIFIER/SENSORS/Delay18" ,
"UNIFIER/SENSORS/Delay19" , "UNIFIER/SENSORS/Delay2" ,
"UNIFIER/SENSORS/Delay20" , "UNIFIER/SENSORS/Delay21" ,
"UNIFIER/SENSORS/Delay22" , "UNIFIER/SENSORS/Delay23" ,
"UNIFIER/SENSORS/Delay24" , "UNIFIER/SENSORS/Delay25" ,
"UNIFIER/SENSORS/Delay26" , "UNIFIER/SENSORS/Delay27" ,
"UNIFIER/SENSORS/Delay28" , "UNIFIER/SENSORS/Delay29" ,
"UNIFIER/SENSORS/Delay3" , "UNIFIER/SENSORS/Delay35" ,
"UNIFIER/SENSORS/Delay4" , "UNIFIER/SENSORS/Delay5" ,
"UNIFIER/SENSORS/Delay6" , "UNIFIER/SENSORS/Delay7" ,
"UNIFIER/SENSORS/Delay8" , "UNIFIER/SENSORS/Delay9" ,
 "UNIFIER/PACER/soft real time subsystem/get elapsed wall-clock time/triggered capture & hold/."
, "UNIFIER/PACER/Output to Console/S-Function" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE"
, "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE"
, "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE"
, "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE"
, "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE"
, "DSTATE" , "DSTATE" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = {
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11
, 12 , 13 , 16 , 17 , 18 , 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 ,
12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 27
, 28 , 29 , 30 , 31 , 32 , 33 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 51 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 51 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . dmrka4iuwk [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . jy1l3ujv3t [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ppiohzkobr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . gz3b4js4ds [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . oqemwaxlko [ 0 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . n5m0nb0nkj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . c1kooexubz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . ndpus01ld4 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . bdt2nf5etq [ 0 ] ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . ai1bi54qax [ 0 ] ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . a1z3hbtkhc [ 0 ] ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . iugjf2dp5k [ 0 ] ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . kv0bz415kr [ 0 ] ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . hxqf43szbj [ 0 ] ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . pcwoeb21pm . bwl2pyw2pm
; rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . fthork0k0x2 .
bwl2pyw2pm ; rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . jmsbhu4m05
; rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) rtDW . g540jxiiax ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) rtDW . crxd5n2r3l ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) rtDW . fx230yq5sl ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) rtDW . kvnpr153yy ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) rtDW . jhfnsaqhxz ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) rtDW . lnmqg4h42q ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) rtDW . jsnr5tvela ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) rtDW . buecpeq4re ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) rtDW . asespk50pt ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) rtDW . pmmx1tycaz ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) rtDW . e5trjt2azz ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) rtDW . eqbrrfiebl ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) rtDW . fkbachhibk ;
rt_LoggedStateSignalPtrs [ 30 ] = ( void * ) rtDW . oaqzp5s2cy ;
rt_LoggedStateSignalPtrs [ 31 ] = ( void * ) rtDW . plokoj1iat ;
rt_LoggedStateSignalPtrs [ 32 ] = ( void * ) rtDW . p3n5g3torf ;
rt_LoggedStateSignalPtrs [ 33 ] = ( void * ) rtDW . avagxvnwf5 ;
rt_LoggedStateSignalPtrs [ 34 ] = ( void * ) rtDW . lkru3wc4bj ;
rt_LoggedStateSignalPtrs [ 35 ] = ( void * ) rtDW . pwrdd5kibs ;
rt_LoggedStateSignalPtrs [ 36 ] = ( void * ) rtDW . erskmg5gj1 ;
rt_LoggedStateSignalPtrs [ 37 ] = ( void * ) rtDW . jj43i52zwn ;
rt_LoggedStateSignalPtrs [ 38 ] = ( void * ) rtDW . pagqs1iwpr ;
rt_LoggedStateSignalPtrs [ 39 ] = ( void * ) rtDW . hvagkay33y ;
rt_LoggedStateSignalPtrs [ 40 ] = ( void * ) rtDW . eoz1jvwwoq ;
rt_LoggedStateSignalPtrs [ 41 ] = ( void * ) rtDW . jgluwzgfp1 ;
rt_LoggedStateSignalPtrs [ 42 ] = ( void * ) rtDW . cpjltmd3l2 ;
rt_LoggedStateSignalPtrs [ 43 ] = ( void * ) rtDW . dcos1gkpc2 ;
rt_LoggedStateSignalPtrs [ 44 ] = ( void * ) rtDW . eypbisuusv ;
rt_LoggedStateSignalPtrs [ 45 ] = ( void * ) rtDW . ezpcxtf0ip ;
rt_LoggedStateSignalPtrs [ 46 ] = ( void * ) rtDW . ookott5jvl ;
rt_LoggedStateSignalPtrs [ 47 ] = ( void * ) rtDW . h3h1h5xjyq ;
rt_LoggedStateSignalPtrs [ 48 ] = ( void * ) rtDW . aadveypr3e ;
rt_LoggedStateSignalPtrs [ 49 ] = ( void * ) & rtDW . nwwie5t5of ;
rt_LoggedStateSignalPtrs [ 50 ] = ( void * ) & rtDW . keywsrry0q ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ;
ssSetPeriodicContStateIndices ( rtS , rtPeriodicIndX ) ; ( void ) memset ( (
void * ) rtPeriodicIndX , 0 , 3 * sizeof ( int_T ) ) ;
ssSetPeriodicContStateRanges ( rtS , rtPeriodicRngX ) ; ( void ) memset ( (
void * ) rtPeriodicRngX , 0 , 6 * sizeof ( real_T ) ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 97 ] ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 127 ] = { { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . n00gsxq4p1 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . ehjp343jmw ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . gmov3gnpox ) , ( NULL ) } , { 3 * sizeof (
real_T ) , ( char * ) ( & rtB . kra5wvotxw [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . cmce4od5nu ) , ( NULL ) } , { 3 *
sizeof ( real_T ) , ( char * ) ( & rtB . k002wprevb [ 0 ] ) , ( NULL ) } , {
3 * sizeof ( real_T ) , ( char * ) ( & rtB . cutvjsc51o [ 0 ] ) , ( NULL ) }
, { 16 * sizeof ( real_T ) , ( char * ) ( & rtB . d0gfg5onrd [ 0 ] ) , ( NULL
) } , { 16 * sizeof ( uint32_T ) , ( char * ) ( & rtB . ngy3pgy40m [ 0 ] ) ,
( NULL ) } , { 16 * sizeof ( real_T ) , ( char * ) ( & rtB . bw4iyihnma [ 0 ]
) , ( NULL ) } , { 16 * sizeof ( uint32_T ) , ( char * ) ( & rtB . nj3xuut2fh
[ 0 ] ) , ( NULL ) } , { 1 * sizeof ( real32_T ) , ( char * ) ( & rtB .
gefiy4un3d ) , ( NULL ) } , { 1 * sizeof ( uint32_T ) , ( char * ) ( & rtB .
lj1ecmy3sj ) , ( NULL ) } , { 1 * sizeof ( real32_T ) , ( char * ) ( & rtB .
be1wst1pkg ) , ( NULL ) } , { 1 * sizeof ( uint32_T ) , ( char * ) ( & rtB .
mb1y0b3eym ) , ( NULL ) } , { 1 * sizeof ( real32_T ) , ( char * ) ( & rtB .
kdl2q2ktlu ) , ( NULL ) } , { 1 * sizeof ( uint32_T ) , ( char * ) ( & rtB .
lcfixu2lfk ) , ( NULL ) } , { 1 * sizeof ( real32_T ) , ( char * ) ( & rtB .
buybsypzuh ) , ( NULL ) } , { 1 * sizeof ( uint32_T ) , ( char * ) ( & rtB .
pgacreyak0 ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 11 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 11 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 11 ] . jagzqtugld ) ,
( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 11 ]
. ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB
. adqmzv0sx0 [ 10 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 10 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1
* sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 10 ] . jagzqtugld ) ,
( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 10 ]
. ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB
. adqmzv0sx0 [ 9 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 9 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 9 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 9 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 8 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 8 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 8 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 8 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 7 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 7 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 7 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 7 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 6 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 6 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 6 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 6 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 5 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 5 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 5 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 5 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 4 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 4 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 4 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 4 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 3 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 3 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 3 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 3 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 2 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 2 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 2 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 2 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 1 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 1 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 1 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 1 ] .
ibnqksi5kc ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
adqmzv0sx0 [ 0 ] . hqlowwzkov ) , ( NULL ) } , { 3 * sizeof ( real_T ) , (
char * ) ( & rtB . adqmzv0sx0 [ 0 ] . dfpeduhr4c [ 0 ] ) , ( NULL ) } , { 1 *
sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 0 ] . jagzqtugld ) , (
NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . adqmzv0sx0 [ 0 ] .
ibnqksi5kc ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqkkpi [ 6 ] . jqzydkhuci [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkkpi [ 5 ] . jqzydkhuci [ 0 ] )
, ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqkkpi [ 4 ] . jqzydkhuci [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkkpi [ 3 ] . jqzydkhuci [ 0 ] )
, ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqkkpi [ 2 ] . jqzydkhuci [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkkpi [ 1 ] . jqzydkhuci [ 0 ] )
, ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqkkpi [ 0 ] . jqzydkhuci [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkk [ 6 ] . d2kygac014 [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkk [
5 ] . d2kygac014 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char *
) ( & rtB . nyqetrz43uqkk [ 4 ] . d2kygac014 [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkk [ 3 ] . d2kygac014 [
0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqkk [ 2 ] . d2kygac014 [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkk [ 1 ] . d2kygac014 [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqkk [
0 ] . d2kygac014 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char *
) ( & rtB . nyqetrz43uqk [ 15 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 14 ] . f5l1thfo3b [
0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqk [ 13 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 12 ] . f5l1thfo3b [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [
11 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char *
) ( & rtB . nyqetrz43uqk [ 10 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 9 ] . f5l1thfo3b [
0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqk [ 8 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 7 ] . f5l1thfo3b [ 0 ] ) , (
NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 6
] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43uqk [ 5 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 4 ] . f5l1thfo3b [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [
3 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char *
) ( & rtB . nyqetrz43uqk [ 2 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 *
sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uqk [ 1 ] . f5l1thfo3b [
0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB .
nyqetrz43uqk [ 0 ] . f5l1thfo3b [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 13 ] . g2bz2muoaw [ 0 ] ) , (
NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 12
] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43uq [ 11 ] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 10 ] . g2bz2muoaw [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 9
] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43uq [ 8 ] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 7 ] . g2bz2muoaw [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 6
] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43uq [ 5 ] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 4 ] . g2bz2muoaw [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 3
] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43uq [ 2 ] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 1 ] . g2bz2muoaw [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43uq [ 0
] . g2bz2muoaw [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43u [ 15 ] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 14 ] . kl452g3br4 [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 13
] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43u [ 12 ] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof
( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 11 ] . kl452g3br4 [ 0 ] ) ,
( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 10
] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * )
( & rtB . nyqetrz43u [ 9 ] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 8 ] . kl452g3br4 [ 0 ] ) , (
NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 7 ]
. kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) (
& rtB . nyqetrz43u [ 6 ] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 5 ] . kl452g3br4 [ 0 ] ) , (
NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 4 ]
. kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) (
& rtB . nyqetrz43u [ 3 ] . kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof (
real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 2 ] . kl452g3br4 [ 0 ] ) , (
NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) ( & rtB . nyqetrz43u [ 1 ]
. kl452g3br4 [ 0 ] ) , ( NULL ) } , { 3 * sizeof ( real32_T ) , ( char * ) (
& rtB . nyqetrz43u [ 0 ] . kl452g3br4 [ 0 ] ) , ( NULL ) } } ;
ssSetNumNonContDerivSigInfos ( rtS , 127 ) ; ssSetNonContDerivSigInfos ( rtS
, nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode1" ) ; ssSetVariableStepSolver ( rtS , 0 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelUpdate ( rtS , MdlUpdate )
; ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } { ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ;
ssSetPrevZCSigState ( rtS , zc ) ; } { } ssSetChecksumVal ( rtS , 0 ,
4207121147U ) ; ssSetChecksumVal ( rtS , 1 , 2496750584U ) ; ssSetChecksumVal
( rtS , 2 , 3458008039U ) ; ssSetChecksumVal ( rtS , 3 , 3961977088U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 58 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = &
rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = &
rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = (
sysRanDType * ) & rtDW . pakc2g42kk ; systemRan [ 16 ] = ( sysRanDType * ) &
rtDW . fthork0k0x2 . gxcgpda4hi ; systemRan [ 17 ] = ( sysRanDType * ) & rtDW
. pcwoeb21pm . gxcgpda4hi ; systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan
[ 19 ] = & rtAlwaysEnabled ; systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan
[ 21 ] = & rtAlwaysEnabled ; systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan
[ 23 ] = & rtAlwaysEnabled ; systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan
[ 25 ] = & rtAlwaysEnabled ; systemRan [ 26 ] = & rtAlwaysEnabled ; systemRan
[ 27 ] = & rtAlwaysEnabled ; systemRan [ 28 ] = & rtAlwaysEnabled ; systemRan
[ 29 ] = & rtAlwaysEnabled ; systemRan [ 30 ] = & rtAlwaysEnabled ; systemRan
[ 31 ] = & rtAlwaysEnabled ; systemRan [ 32 ] = & rtAlwaysEnabled ; systemRan
[ 33 ] = & rtAlwaysEnabled ; systemRan [ 34 ] = & rtAlwaysEnabled ; systemRan
[ 35 ] = & rtAlwaysEnabled ; systemRan [ 36 ] = & rtAlwaysEnabled ; systemRan
[ 37 ] = ( sysRanDType * ) & rtDW . iw455stvt1 ; systemRan [ 38 ] = &
rtAlwaysEnabled ; systemRan [ 39 ] = & rtAlwaysEnabled ; systemRan [ 40 ] = &
rtAlwaysEnabled ; systemRan [ 41 ] = & rtAlwaysEnabled ; systemRan [ 42 ] = &
rtAlwaysEnabled ; systemRan [ 43 ] = & rtAlwaysEnabled ; systemRan [ 44 ] = &
rtAlwaysEnabled ; systemRan [ 45 ] = & rtAlwaysEnabled ; systemRan [ 46 ] = &
rtAlwaysEnabled ; systemRan [ 47 ] = & rtAlwaysEnabled ; systemRan [ 48 ] = &
rtAlwaysEnabled ; systemRan [ 49 ] = & rtAlwaysEnabled ; systemRan [ 50 ] = &
rtAlwaysEnabled ; systemRan [ 51 ] = & rtAlwaysEnabled ; systemRan [ 52 ] = &
rtAlwaysEnabled ; systemRan [ 53 ] = & rtAlwaysEnabled ; systemRan [ 54 ] = (
sysRanDType * ) & rtDW . anhm4dpp2l ; systemRan [ 55 ] = ( sysRanDType * ) &
rtDW . anhm4dpp2l ; systemRan [ 56 ] = ( sysRanDType * ) & rtDW . cfvgbkovvu
; systemRan [ 57 ] = ( sysRanDType * ) & rtDW . cfvgbkovvu ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_UNIFIER_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_UNIFIER_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_UNIFIER_SetDWork ) ; rtP . Saturation1_LowerSat_fjfihtgctt = rtMinusInf ;
rtP . Saturation_LowerSat_ckp25ja5tp = rtMinusInf ; rtP .
Saturation1_LowerSat_ifds41vj3d = rtMinusInf ; rtP .
Saturation_LowerSat_egflfzvuqx = rtMinusInf ; rtP .
Saturation1_LowerSat_mtmmhddwjb = rtMinusInf ; rtP .
Saturation_LowerSat_ihlfa0mqdb = rtMinusInf ; rtP .
Saturation_UpperSat_b2a52laupk = rtInfF ; rtP . adqmzv0sx0 .
Saturation_UpperSat = rtInf ; rtP . adqmzv0sx0 .
Saturation_UpperSat_ollczcryiu = rtInf ; rtP . adqmzv0sx0 .
Saturation1_UpperSat_e5noinhxx3 = rtInf ; rt_RapidReadMatFileAndUpdateParams
( rtS ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } ssSetNumSFunctions
( rtS , 4 ) ; { static SimStruct childSFunctions [ 4 ] ; static SimStruct *
childSFunctionPtrs [ 4 ] ; ( void ) memset ( ( void * ) & childSFunctions [ 0
] , 0 , sizeof ( childSFunctions ) ) ; ssSetSFunctions ( rtS , &
childSFunctionPtrs [ 0 ] ) ; ssSetSFunction ( rtS , 0 , & childSFunctions [ 0
] ) ; ssSetSFunction ( rtS , 1 , & childSFunctions [ 1 ] ) ; ssSetSFunction (
rtS , 2 , & childSFunctions [ 2 ] ) ; ssSetSFunction ( rtS , 3 , &
childSFunctions [ 3 ] ) ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ;
static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static
int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof
( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 2 ) ; static struct _ssPortInputs inputPortInfo [
2 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 2 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ;
ssSetInputPortUnit ( rts , 1 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 2 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . lbzmmcd5bg ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } {
ssSetInputPortRequiredContiguous ( rts , 1 , 1 ) ; ssSetInputPortSignal ( rts
, 1 , rtB . btiigxjvj2 ) ; _ssSetInputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 1 , 3 ) ; } } ssSetDiscStates ( rts , (
real_T * ) & rtDW . keywsrry0q ) ; ssSetModelName ( rts ,
"sfun_output_to_console" ) ; ssSetPath ( rts ,
"UNIFIER/PACER/Output to Console/S-Function" ) ; if ( ssGetRTModel ( rtS ) ==
( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 1 ] ;
ssSetSFcnParamsCount ( rts , 1 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . SFunction_P1_Size ) ;
} { static struct _ssDWorkRecord dWorkRecord [ 1 ] ; static struct
_ssDWorkAuxRecord dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord )
; ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 1 )
; ssSetDWorkWidthAsInt ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 ,
SS_DOUBLE ) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ;
ssSetDWorkUsedAsDState ( rts , 0 , 1 ) ; ssSetDWork ( rts , 0 , & rtDW .
keywsrry0q ) ; } { raccelLoadSFcnMexFile ( "sfun_output_to_console" ,
"UNIFIER:8414" , rts , 0 ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; }
} sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetInputPortWidthAsInt ( rts , 1 , 3 ) ; ssSetInputPortDataType ( rts , 1 ,
SS_DOUBLE ) ; ssSetInputPortComplexSignal ( rts , 1 , 0 ) ;
ssSetInputPortFrameData ( rts , 1 , 0 ) ; ssSetInputPortUnit ( rts , 1 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 1 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetInputPortConnected ( rts , 1 , 1 ) ; ssSetInputPortBufferDstPort
( rts , 0 , - 1 ) ; ssSetInputPortBufferDstPort ( rts , 1 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . pr1zzcknox ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 16 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB .
j3t4wyjy41 ) ) ; } } ssSetModelName ( rts , "sfun_joyinfoex" ) ; ssSetPath (
rts , "UNIFIER/STICK_INPUT/S-Function" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { raccelLoadSFcnMexFile (
"sfun_joyinfoex" , "UNIFIER:31022" , rts , 1 ) ; if ( ssGetErrorStatus ( rtS
) ) { return rtS ; } } sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime (
rts , 0 , 0.002 ) ; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
static struct _ssPortOutputs outputPortInfo [ 3 ] ; ssSetPortInfoForOutputs (
rts , & outputPortInfo [ 0 ] ) ; _ssSetNumOutputPorts ( rts , 3 ) ; { static
struct _ssOutPortUnit outputPortUnits [ 3 ] ; _ssSetPortInfo2ForOutputUnits (
rts , & outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ;
ssSetOutputPortUnit ( rts , 1 , 0 ) ; ssSetOutputPortUnit ( rts , 2 , 0 ) ; {
static struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 3 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 1 , 0 ) ;
ssSetOutputPortIsContinuousQuantity ( rts , 2 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
nci1mnnllt ) ) ; } { _ssSetOutputPortNumDimensions ( rts , 1 , 1 ) ;
ssSetOutputPortWidthAsInt ( rts , 1 , 1 ) ; ssSetOutputPortSignal ( rts , 1 ,
( ( real_T * ) & rtB . elv40zm3eo ) ) ; } { _ssSetOutputPortNumDimensions (
rts , 2 , 1 ) ; ssSetOutputPortWidthAsInt ( rts , 2 , 1 ) ;
ssSetOutputPortSignal ( rts , 2 , ( ( real_T * ) & rtB . jopjoprq0c ) ) ; } }
ssSetModelName ( rts , "sfun_getSystemClockTimeval" ) ; ssSetPath ( rts ,
"UNIFIER/PACER/soft real time subsystem/get elapsed wall-clock time/S-Function"
) ; if ( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; {
raccelLoadSFcnMexFile ( "sfun_getSystemClockTimeval" , "UNIFIER:8429" , rts ,
2 ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } }
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetOutputPortConnected ( rts , 0
, 1 ) ; _ssSetOutputPortConnected ( rts , 1 , 1 ) ; _ssSetOutputPortConnected
( rts , 2 , 1 ) ; _ssSetOutputPortBeingMerged ( rts , 0 , 0 ) ;
_ssSetOutputPortBeingMerged ( rts , 1 , 0 ) ; _ssSetOutputPortBeingMerged (
rts , 2 , 0 ) ; } { SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; static
time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T
sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof (
time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof (
time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ; static
ssJacobianPerturbationBounds jacPerturbationBounds ; ssSetStatesInfo2 ( rts ,
& statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . hwhq5yb2fg ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } ssSetModelName ( rts ,
"sfun_sleep" ) ; ssSetPath ( rts ,
"UNIFIER/PACER/soft real time subsystem/S-Function" ) ; if ( ssGetRTModel (
rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts ,
ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) )
; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; }
ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray *
sfcnParams [ 1 ] ; ssSetSFcnParamsCount ( rts , 1 ) ; ssSetSFcnParamsPtr (
rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP .
SFunction_P1_Size_msgrnckvzs ) ; } { raccelLoadSFcnMexFile ( "sfun_sleep" ,
"UNIFIER:8424" , rts , 3 ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; }
} sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.01 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
