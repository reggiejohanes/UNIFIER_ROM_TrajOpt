#include "UNIFIER_dyn.h"
#include "UNIFIER_dyn_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "mwmathutil.h"
#include "rt_logging_mmi.h"
#include "UNIFIER_dyn_capi.h"
#include "UNIFIER_dyn_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , &
stopRequested ) ; } rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "23.2 (R2023b) 01-Aug-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char
* raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; ExtU rtU ; ExtY rtY ; static SimStruct model_S ; SimStruct
* const rtS = & model_S ; real_T look1_plinlcapw ( real_T u0 , const real_T
bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex
) { real_T frac ; real_T y ; real_T yL_0d0 ; uint32_T bpIdx ; if ( u0 <= bp0
[ 0U ] ) { bpIdx = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) {
for ( bpIdx = prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ; bpIdx -- ) { } while (
u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / (
bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex ; frac = 0.0
; } prevIndex [ 0U ] = bpIdx ; if ( bpIdx == maxIndex ) { y = table [ bpIdx ]
; } else { yL_0d0 = table [ bpIdx ] ; y = ( table [ bpIdx + 1U ] - yL_0d0 ) *
frac + yL_0d0 ; } return y ; } real_T look2_plinlcpw ( real_T u0 , real_T u1
, const real_T bp0 [ ] , const real_T bp1 [ ] , const real_T table [ ] ,
uint32_T prevIndex [ ] , const uint32_T maxIndex [ ] , uint32_T stride ) {
real_T fractions [ 2 ] ; real_T frac ; real_T yL_0d0 ; real_T yL_0d1 ;
uint32_T bpIndices [ 2 ] ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { bpIdx =
0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex [ 0U ] ] ) { for ( bpIdx =
prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ; bpIdx -- ) { } while ( u0 >= bp0 [
bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx +
1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex [ 0U ] - 1U ; frac = 1.0 ;
} prevIndex [ 0U ] = bpIdx ; fractions [ 0U ] = frac ; bpIndices [ 0U ] =
bpIdx ; if ( u1 <= bp1 [ 0U ] ) { bpIdx = 0U ; frac = 0.0 ; } else if ( u1 <
bp1 [ maxIndex [ 1U ] ] ) { for ( bpIdx = prevIndex [ 1U ] ; u1 < bp1 [ bpIdx
] ; bpIdx -- ) { } while ( u1 >= bp1 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = (
u1 - bp1 [ bpIdx ] ) / ( bp1 [ bpIdx + 1U ] - bp1 [ bpIdx ] ) ; } else {
bpIdx = maxIndex [ 1U ] - 1U ; frac = 1.0 ; } prevIndex [ 1U ] = bpIdx ;
bpIdx = bpIdx * stride + bpIndices [ 0U ] ; yL_0d0 = table [ bpIdx ] ; yL_0d0
+= ( table [ bpIdx + 1U ] - yL_0d0 ) * fractions [ 0U ] ; bpIdx += stride ;
yL_0d1 = table [ bpIdx ] ; return ( ( ( table [ bpIdx + 1U ] - yL_0d1 ) *
fractions [ 0U ] + yL_0d1 ) - yL_0d0 ) * frac + yL_0d0 ; } uint32_T
linsearch_u32d ( real_T u , const real_T bp [ ] , uint32_T startIndex ) {
uint32_T bpIndex ; for ( bpIndex = startIndex ; u < bp [ bpIndex ] ; bpIndex
-- ) { } while ( u >= bp [ bpIndex + 1U ] ) { bpIndex ++ ; } return bpIndex ;
} uint32_T plook_u32ff_lincpa ( real32_T u , const real32_T bp [ ] , uint32_T
maxIndex , real32_T * fraction , uint32_T * prevIndex ) { uint32_T bpIndex ;
if ( u <= bp [ 0U ] ) { bpIndex = 0U ; * fraction = 0.0F ; } else if ( u < bp
[ maxIndex ] ) { bpIndex = linsearch_u32f ( u , bp , * prevIndex ) ; *
fraction = ( u - bp [ bpIndex ] ) / ( bp [ bpIndex + 1U ] - bp [ bpIndex ] )
; } else { bpIndex = maxIndex ; * fraction = 0.0F ; } * prevIndex = bpIndex ;
return bpIndex ; } real32_T intrp4d_fu32fla_pw ( const uint32_T bpIndex [ ] ,
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
2U ] ; } y += ( yL_1d - y ) * frac [ 3U ] ; } return y ; } real32_T
look1_iflf_pbinlcpw ( real32_T u0 , const real32_T bp0 [ ] , const real32_T
table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) { real32_T frac ;
real32_T yL_0d0 ; uint32_T bpIdx ; uint32_T found ; uint32_T iLeft ; uint32_T
iRght ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ; frac = 0.0F ; } else if ( u0 <
bp0 [ maxIndex ] ) { bpIdx = prevIndex [ 0U ] ; iLeft = 0U ; iRght = maxIndex
; found = 0U ; while ( found == 0U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght =
bpIdx - 1U ; bpIdx = ( ( bpIdx + iLeft ) - 1U ) >> 1U ; } else if ( u0 < bp0
[ bpIdx + 1U ] ) { found = 1U ; } else { iLeft = bpIdx + 1U ; bpIdx = ( (
bpIdx + iRght ) + 1U ) >> 1U ; } } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [
bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac = 1.0F
; } prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [ bpIdx ] ; return ( table [
bpIdx + 1U ] - yL_0d0 ) * frac + yL_0d0 ; } uint32_T plook_u32ff_linxp (
real32_T u , const real32_T bp [ ] , uint32_T maxIndex , real32_T * fraction
, uint32_T * prevIndex ) { uint32_T bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex
= 0U ; * fraction = ( u - bp [ 0U ] ) / ( bp [ 1U ] - bp [ 0U ] ) ; } else if
( u < bp [ maxIndex ] ) { bpIndex = linsearch_u32f ( u , bp , * prevIndex ) ;
* fraction = ( u - bp [ bpIndex ] ) / ( bp [ bpIndex + 1U ] - bp [ bpIndex ]
) ; } else { bpIndex = maxIndex - 1U ; * fraction = ( u - bp [ maxIndex - 1U
] ) / ( bp [ maxIndex ] - bp [ maxIndex - 1U ] ) ; } * prevIndex = bpIndex ;
return bpIndex ; } uint32_T plook_u32ff_lincp ( real32_T u , const real32_T
bp [ ] , uint32_T maxIndex , real32_T * fraction , uint32_T * prevIndex ) {
uint32_T bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0U ; * fraction = 0.0F ;
} else if ( u < bp [ maxIndex ] ) { bpIndex = linsearch_u32f ( u , bp , *
prevIndex ) ; * fraction = ( u - bp [ bpIndex ] ) / ( bp [ bpIndex + 1U ] -
bp [ bpIndex ] ) ; } else { bpIndex = maxIndex - 1U ; * fraction = 1.0F ; } *
prevIndex = bpIndex ; return bpIndex ; } real32_T intrp4d_fl_pw ( const
uint32_T bpIndex [ ] , const real_T frac [ ] , const real32_T table [ ] ,
const uint32_T stride [ ] ) { real32_T yL_0d0 ; real32_T yL_1d ; real32_T
yL_2d ; real32_T yL_3d ; uint32_T offset_0d ; uint32_T offset_1d ; uint32_T
offset_3d ; offset_3d = ( ( bpIndex [ 3U ] * stride [ 3U ] + bpIndex [ 2U ] *
stride [ 2U ] ) + bpIndex [ 1U ] * stride [ 1U ] ) + bpIndex [ 0U ] ; yL_0d0
= table [ offset_3d ] ; yL_1d = ( real32_T ) ( ( table [ offset_3d + 1U ] -
yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ; offset_0d = offset_3d + stride [ 1U ] ;
yL_0d0 = table [ offset_0d ] ; yL_2d = ( real32_T ) ( ( ( ( real32_T ) ( (
table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) *
frac [ 1U ] ) + yL_1d ; offset_1d = offset_3d + stride [ 2U ] ; yL_0d0 =
table [ offset_1d ] ; yL_1d = ( real32_T ) ( ( table [ offset_1d + 1U ] -
yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ; offset_0d = offset_1d + stride [ 1U ] ;
yL_0d0 = table [ offset_0d ] ; yL_3d = ( real32_T ) ( ( ( ( real32_T ) ( ( (
( real32_T ) ( ( table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0
) - yL_1d ) * frac [ 1U ] ) + yL_1d ) - yL_2d ) * frac [ 2U ] ) + yL_2d ;
offset_1d = offset_3d + stride [ 3U ] ; yL_0d0 = table [ offset_1d ] ; yL_1d
= ( real32_T ) ( ( table [ offset_1d + 1U ] - yL_0d0 ) * frac [ 0U ] ) +
yL_0d0 ; offset_0d = offset_1d + stride [ 1U ] ; yL_0d0 = table [ offset_0d ]
; yL_2d = ( real32_T ) ( ( ( ( real32_T ) ( ( table [ offset_0d + 1U ] -
yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) * frac [ 1U ] ) + yL_1d ;
offset_1d += stride [ 2U ] ; yL_0d0 = table [ offset_1d ] ; yL_1d = (
real32_T ) ( ( table [ offset_1d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ;
offset_0d = offset_1d + stride [ 1U ] ; yL_0d0 = table [ offset_0d ] ; return
( real32_T ) ( ( ( ( real32_T ) ( ( ( ( real32_T ) ( ( ( ( real32_T ) ( (
table [ offset_0d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) *
frac [ 1U ] ) + yL_1d ) - yL_2d ) * frac [ 2U ] ) + yL_2d ) - yL_3d ) * frac
[ 3U ] ) + yL_3d ; } real32_T intrp3d_fl_pw ( const uint32_T bpIndex [ ] ,
const real_T frac [ ] , const real32_T table [ ] , const uint32_T stride [ ]
) { real32_T yL_0d0 ; real32_T yL_1d ; real32_T yL_2d ; uint32_T offset_0d ;
uint32_T offset_2d ; offset_2d = ( bpIndex [ 2U ] * stride [ 2U ] + bpIndex [
1U ] * stride [ 1U ] ) + bpIndex [ 0U ] ; yL_0d0 = table [ offset_2d ] ;
yL_1d = ( real32_T ) ( ( table [ offset_2d + 1U ] - yL_0d0 ) * frac [ 0U ] )
+ yL_0d0 ; offset_0d = offset_2d + stride [ 1U ] ; yL_0d0 = table [ offset_0d
] ; yL_2d = ( real32_T ) ( ( ( ( real32_T ) ( ( table [ offset_0d + 1U ] -
yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) * frac [ 1U ] ) + yL_1d ;
offset_2d += stride [ 2U ] ; yL_0d0 = table [ offset_2d ] ; yL_1d = (
real32_T ) ( ( table [ offset_2d + 1U ] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ;
offset_0d = offset_2d + stride [ 1U ] ; yL_0d0 = table [ offset_0d ] ; return
( real32_T ) ( ( ( ( real32_T ) ( ( ( ( real32_T ) ( ( table [ offset_0d + 1U
] - yL_0d0 ) * frac [ 0U ] ) + yL_0d0 ) - yL_1d ) * frac [ 1U ] ) + yL_1d ) -
yL_2d ) * frac [ 2U ] ) + yL_2d ; } real32_T intrp2d_fu32fl_pw ( const
uint32_T bpIndex [ ] , const real32_T frac [ ] , const real32_T table [ ] ,
const uint32_T stride ) { real32_T yL_0d0 ; real32_T yL_0d1 ; uint32_T
offset_1d ; offset_1d = bpIndex [ 1U ] * stride + bpIndex [ 0U ] ; yL_0d0 =
table [ offset_1d ] ; yL_0d0 += ( table [ offset_1d + 1U ] - yL_0d0 ) * frac
[ 0U ] ; offset_1d += stride ; yL_0d1 = table [ offset_1d ] ; return ( ( (
table [ offset_1d + 1U ] - yL_0d1 ) * frac [ 0U ] + yL_0d1 ) - yL_0d0 ) *
frac [ 1U ] + yL_0d0 ; } real_T look1_plinlcpw ( real_T u0 , const real_T bp0
[ ] , const real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) {
real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) {
bpIdx = 0U ; frac = 0.0 ; } else if ( u0 < bp0 [ maxIndex ] ) { for ( bpIdx =
prevIndex [ 0U ] ; u0 < bp0 [ bpIdx ] ; bpIdx -- ) { } while ( u0 >= bp0 [
bpIdx + 1U ] ) { bpIdx ++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx +
1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac = 1.0 ; }
prevIndex [ 0U ] = bpIdx ; yL_0d0 = table [ bpIdx ] ; return ( table [ bpIdx
+ 1U ] - yL_0d0 ) * frac + yL_0d0 ; } real_T look1_plinlxpw ( real_T u0 ,
const real_T bp0 [ ] , const real_T table [ ] , uint32_T prevIndex [ ] ,
uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ; if ( u0
<= bp0 [ 0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] -
bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { for ( bpIdx = prevIndex
[ 0U ] ; u0 < bp0 [ bpIdx ] ; bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ]
) { bpIdx ++ ; } frac = ( u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [
bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac = ( u0 - bp0 [ maxIndex -
1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } prevIndex [ 0U ] =
bpIdx ; yL_0d0 = table [ bpIdx ] ; return ( table [ bpIdx + 1U ] - yL_0d0 ) *
frac + yL_0d0 ; } real_T look2_plinlxpw ( real_T u0 , real_T u1 , const
real_T bp0 [ ] , const real_T bp1 [ ] , const real_T table [ ] , uint32_T
prevIndex [ ] , const uint32_T maxIndex [ ] , uint32_T stride ) { real_T
fractions [ 2 ] ; real_T frac ; real_T yL_0d0 ; real_T yL_0d1 ; uint32_T
bpIndices [ 2 ] ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { bpIdx = 0U ;
frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 <
bp0 [ maxIndex [ 0U ] ] ) { for ( bpIdx = prevIndex [ 0U ] ; u0 < bp0 [ bpIdx
] ; bpIdx -- ) { } while ( u0 >= bp0 [ bpIdx + 1U ] ) { bpIdx ++ ; } frac = (
u0 - bp0 [ bpIdx ] ) / ( bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else {
bpIdx = maxIndex [ 0U ] - 1U ; frac = ( u0 - bp0 [ maxIndex [ 0U ] - 1U ] ) /
( bp0 [ maxIndex [ 0U ] ] - bp0 [ maxIndex [ 0U ] - 1U ] ) ; } prevIndex [ 0U
] = bpIdx ; fractions [ 0U ] = frac ; bpIndices [ 0U ] = bpIdx ; if ( u1 <=
bp1 [ 0U ] ) { bpIdx = 0U ; frac = ( u1 - bp1 [ 0U ] ) / ( bp1 [ 1U ] - bp1 [
0U ] ) ; } else if ( u1 < bp1 [ maxIndex [ 1U ] ] ) { for ( bpIdx = prevIndex
[ 1U ] ; u1 < bp1 [ bpIdx ] ; bpIdx -- ) { } while ( u1 >= bp1 [ bpIdx + 1U ]
) { bpIdx ++ ; } frac = ( u1 - bp1 [ bpIdx ] ) / ( bp1 [ bpIdx + 1U ] - bp1 [
bpIdx ] ) ; } else { bpIdx = maxIndex [ 1U ] - 1U ; frac = ( u1 - bp1 [
maxIndex [ 1U ] - 1U ] ) / ( bp1 [ maxIndex [ 1U ] ] - bp1 [ maxIndex [ 1U ]
- 1U ] ) ; } prevIndex [ 1U ] = bpIdx ; bpIdx = bpIdx * stride + bpIndices [
0U ] ; yL_0d0 = table [ bpIdx ] ; yL_0d0 += ( table [ bpIdx + 1U ] - yL_0d0 )
* fractions [ 0U ] ; bpIdx += stride ; yL_0d1 = table [ bpIdx ] ; return ( (
( table [ bpIdx + 1U ] - yL_0d1 ) * fractions [ 0U ] + yL_0d1 ) - yL_0d0 ) *
frac + yL_0d0 ; } uint32_T plook_linxp ( real_T u , const real_T bp [ ] ,
uint32_T maxIndex , real_T * fraction , uint32_T * prevIndex ) { uint32_T
bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0U ; * fraction = ( u - bp [ 0U ]
) / ( bp [ 1U ] - bp [ 0U ] ) ; } else if ( u < bp [ maxIndex ] ) { bpIndex =
linsearch_u32d ( u , bp , * prevIndex ) ; * fraction = ( u - bp [ bpIndex ] )
/ ( bp [ bpIndex + 1U ] - bp [ bpIndex ] ) ; } else { bpIndex = maxIndex - 1U
; * fraction = ( u - bp [ maxIndex - 1U ] ) / ( bp [ maxIndex ] - bp [
maxIndex - 1U ] ) ; } * prevIndex = bpIndex ; return bpIndex ; } uint32_T
linsearch_u32f ( real32_T u , const real32_T bp [ ] , uint32_T startIndex ) {
uint32_T bpIndex ; for ( bpIndex = startIndex ; u < bp [ bpIndex ] ; bpIndex
-- ) { } while ( u >= bp [ bpIndex + 1U ] ) { bpIndex ++ ; } return bpIndex ;
} void ijft5h35rv ( void ) { int32_T brnrrcfc0x ; for ( brnrrcfc0x = 0 ;
brnrrcfc0x < 12 ; brnrrcfc0x ++ ) { rtB . p5rpnypkdo [ brnrrcfc0x ] .
gbstdhmylq = 0.0 ; } } void b4xsnziie2 ( int32_T brnrrcfc0x ) { real_T
iuttlsfwrg ; real_T e4d3jspw35 ; iuttlsfwrg = rtP . zeta_Value [ brnrrcfc0x ]
; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { if ( ssIsSampleHit ( rtS , 0 , 0 ) )
{ e4d3jspw35 = rtB . p5rpnypkdo [ brnrrcfc0x ] . gbstdhmylq * iuttlsfwrg +
rtP . testinput_Value [ 16 ] ; } rtB . eljuwfhp1f [ brnrrcfc0x ] = e4d3jspw35
; } } void b4xsnziie2TID1 ( int32_T brnrrcfc0x ) { rtB . p5rpnypkdo [
brnrrcfc0x ] . gbstdhmylq = muDoubleScalarTan ( rtP . p5rpnypkdo .
K_slope_Gain * rtP . testinput_Value [ 17 ] ) ; } void cjkzdk20zl ( void ) {
int32_T co50hcg2ie ; for ( co50hcg2ie = 0 ; co50hcg2ie < 16 ; co50hcg2ie ++ )
{ rtB . jz0qdcsmmm [ co50hcg2ie ] . ijneevr0hx [ 0 ] = 0.0F ; rtB .
jz0qdcsmmm [ co50hcg2ie ] . ijneevr0hx [ 1 ] = 0.0F ; rtB . jz0qdcsmmm [
co50hcg2ie ] . ijneevr0hx [ 2 ] = 0.0F ; } } void jgo5lugg00 ( int32_T
co50hcg2ie ) { real32_T brcvqepyf0 [ 3 ] ; real32_T odggjk3ov5 ; real32_T
dgcig53owe ; real32_T flh0v3bn03 ; brcvqepyf0 [ 0 ] = rtP . vtail_nodes [ 3 *
co50hcg2ie ] ; brcvqepyf0 [ 1 ] = rtP . vtail_nodes [ 3 * co50hcg2ie + 1 ] ;
brcvqepyf0 [ 2 ] = rtP . vtail_nodes [ 3 * co50hcg2ie + 2 ] ; if (
ssIsSampleHit ( rtS , 0 , 0 ) ) { { real32_T cs0quyv3jn_idx_0 ; real32_T
cs0quyv3jn_idx_1 ; real32_T cs0quyv3jn_idx_2 ; real32_T np0siriwkb_idx_0 ; if
( ssIsSampleHit ( rtS , 0 , 0 ) ) { cs0quyv3jn_idx_0 = rtB . jz0qdcsmmm [
co50hcg2ie ] . ijneevr0hx [ 0 ] - brcvqepyf0 [ 0 ] ; cs0quyv3jn_idx_1 = rtB .
jz0qdcsmmm [ co50hcg2ie ] . ijneevr0hx [ 1 ] - brcvqepyf0 [ 1 ] ;
cs0quyv3jn_idx_2 = rtB . jz0qdcsmmm [ co50hcg2ie ] . ijneevr0hx [ 2 ] -
brcvqepyf0 [ 2 ] ; np0siriwkb_idx_0 = ( cs0quyv3jn_idx_1 * rtB . lcnor15erx [
2 ] - rtB . lcnor15erx [ 1 ] * cs0quyv3jn_idx_2 ) + rtB . lxkh42xndm [ 0 ] ;
cs0quyv3jn_idx_2 = ( rtB . lcnor15erx [ 0 ] * cs0quyv3jn_idx_2 -
cs0quyv3jn_idx_0 * rtB . lcnor15erx [ 2 ] ) + rtB . lxkh42xndm [ 1 ] ;
cs0quyv3jn_idx_0 = ( cs0quyv3jn_idx_0 * rtB . lcnor15erx [ 1 ] - rtB .
lcnor15erx [ 0 ] * cs0quyv3jn_idx_1 ) + rtB . lxkh42xndm [ 2 ] ; flh0v3bn03 =
muSingleScalarSqrt ( ( muSingleScalarPower ( np0siriwkb_idx_0 , 2.0F ) +
muSingleScalarPower ( cs0quyv3jn_idx_2 , 2.0F ) ) + muSingleScalarPower (
cs0quyv3jn_idx_0 , 2.0F ) ) + rtP . jz0qdcsmmm . Constant1_Value ;
cs0quyv3jn_idx_1 = cs0quyv3jn_idx_2 / flh0v3bn03 ; if ( cs0quyv3jn_idx_1 >
1.0F ) { cs0quyv3jn_idx_1 = 1.0F ; } else if ( cs0quyv3jn_idx_1 < - 1.0F ) {
cs0quyv3jn_idx_1 = - 1.0F ; } odggjk3ov5 = muSingleScalarAsin (
cs0quyv3jn_idx_1 ) ; dgcig53owe = muSingleScalarAtan ( cs0quyv3jn_idx_0 / (
np0siriwkb_idx_0 + rtP . jz0qdcsmmm . Constant1_Value ) ) ; } } rtB .
dzpd4knetl [ co50hcg2ie ] = odggjk3ov5 ; rtB . jet1i0an5do [ co50hcg2ie ] =
dgcig53owe ; rtB . crx1qgibvon [ co50hcg2ie ] = flh0v3bn03 ; } } void
jgo5lugg00TID1 ( int32_T co50hcg2ie ) { rtB . jz0qdcsmmm [ co50hcg2ie ] .
ijneevr0hx [ 0 ] = ( real32_T ) rtP . xyz_cg [ 0 ] ; rtB . jz0qdcsmmm [
co50hcg2ie ] . ijneevr0hx [ 1 ] = ( real32_T ) rtP . xyz_cg [ 1 ] ; rtB .
jz0qdcsmmm [ co50hcg2ie ] . ijneevr0hx [ 2 ] = ( real32_T ) rtP . xyz_cg [ 2
] ; } void oa24tgolov ( void ) { int32_T bs0t4f2z5j ; for ( bs0t4f2z5j = 0 ;
bs0t4f2z5j < 14 ; bs0t4f2z5j ++ ) { rtB . jz0qdcsmmmw [ bs0t4f2z5j ] .
kz2ejerpof [ 0 ] = 0.0F ; rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof [ 1 ]
= 0.0F ; rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof [ 2 ] = 0.0F ; } }
void f53wtq1cer ( int32_T bs0t4f2z5j ) { real32_T brcvqepyf0u [ 3 ] ;
real32_T dgcig53oweg ; real32_T acnxx21gcx ; brcvqepyf0u [ 0 ] = rtP .
wing_nodes [ 3 * bs0t4f2z5j ] ; brcvqepyf0u [ 1 ] = rtP . wing_nodes [ 3 *
bs0t4f2z5j + 1 ] ; brcvqepyf0u [ 2 ] = rtP . wing_nodes [ 3 * bs0t4f2z5j + 2
] ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { { real32_T cf5uxibguv_e ; real32_T
cf5uxibguv_idx_0 ; real32_T cf5uxibguv_idx_1 ; real32_T cf5uxibguv_idx_2 ;
real32_T cf5uxibguv_p ; real32_T k2jqrxxjmu_idx_2 ; real32_T k2jqrxxjmu_idx_4
; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { cf5uxibguv_idx_0 = rtB . jz0qdcsmmmw
[ bs0t4f2z5j ] . kz2ejerpof [ 0 ] - brcvqepyf0u [ 0 ] ; cf5uxibguv_idx_1 =
rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof [ 1 ] - brcvqepyf0u [ 1 ] ;
cf5uxibguv_idx_2 = rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof [ 2 ] -
brcvqepyf0u [ 2 ] ; k2jqrxxjmu_idx_2 = cf5uxibguv_idx_0 * rtB . lcnor15erx [
1 ] ; k2jqrxxjmu_idx_4 = cf5uxibguv_idx_0 * rtB . lcnor15erx [ 2 ] ;
cf5uxibguv_e = ( cf5uxibguv_idx_1 * rtB . lcnor15erx [ 2 ] - rtB . lcnor15erx
[ 1 ] * cf5uxibguv_idx_2 ) + rtB . lxkh42xndm [ 0 ] ; cf5uxibguv_idx_0 =
cf5uxibguv_e ; cf5uxibguv_p = cf5uxibguv_e * cf5uxibguv_e ; cf5uxibguv_e = (
rtB . lcnor15erx [ 0 ] * cf5uxibguv_idx_2 - k2jqrxxjmu_idx_4 ) + rtB .
lxkh42xndm [ 1 ] ; cf5uxibguv_p += cf5uxibguv_e * cf5uxibguv_e ; cf5uxibguv_e
= ( k2jqrxxjmu_idx_2 - rtB . lcnor15erx [ 0 ] * cf5uxibguv_idx_1 ) + rtB .
lxkh42xndm [ 2 ] ; cf5uxibguv_p += cf5uxibguv_e * cf5uxibguv_e ; dgcig53oweg
= muSingleScalarAtan ( cf5uxibguv_e / ( cf5uxibguv_idx_0 + rtP . jz0qdcsmmmw
. Constant1_Value ) ) ; acnxx21gcx = muSingleScalarSqrt ( cf5uxibguv_p ) ; }
} rtB . jet1i0an5d [ bs0t4f2z5j ] = dgcig53oweg ; rtB . crx1qgibvo [
bs0t4f2z5j ] = acnxx21gcx ; } } void f53wtq1cerTID1 ( int32_T bs0t4f2z5j ) {
rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof [ 0 ] = ( real32_T ) rtP .
xyz_cg [ 0 ] ; rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof [ 1 ] = (
real32_T ) rtP . xyz_cg [ 1 ] ; rtB . jz0qdcsmmmw [ bs0t4f2z5j ] . kz2ejerpof
[ 2 ] = ( real32_T ) rtP . xyz_cg [ 2 ] ; } void lbtqalrtao ( void ) {
int32_T prlh41yr04 ; for ( prlh41yr04 = 0 ; prlh41yr04 < 16 ; prlh41yr04 ++ )
{ rtB . jz0qdcsmmmwh [ prlh41yr04 ] . m05clr3gxy [ 0 ] = 0.0F ; rtB .
jz0qdcsmmmwh [ prlh41yr04 ] . m05clr3gxy [ 1 ] = 0.0F ; rtB . jz0qdcsmmmwh [
prlh41yr04 ] . m05clr3gxy [ 2 ] = 0.0F ; } } void cv3gln2abz ( int32_T
prlh41yr04 ) { real32_T haulnsvtzw [ 3 ] ; real32_T nwl3pcl0q5 [ 3 ] ;
real32_T kvobxh0moi [ 3 ] ; haulnsvtzw [ 0 ] = rtP . vtail_nodes [ 3 *
prlh41yr04 ] ; nwl3pcl0q5 [ 0 ] = rtB . bdrmalqcon [ 3 * prlh41yr04 ] ;
haulnsvtzw [ 1 ] = rtP . vtail_nodes [ 3 * prlh41yr04 + 1 ] ; nwl3pcl0q5 [ 1
] = rtB . bdrmalqcon [ 3 * prlh41yr04 + 1 ] ; haulnsvtzw [ 2 ] = rtP .
vtail_nodes [ 3 * prlh41yr04 + 2 ] ; nwl3pcl0q5 [ 2 ] = rtB . bdrmalqcon [ 3
* prlh41yr04 + 2 ] ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { { real32_T
fpxgr2xit1_idx_0 ; real32_T fpxgr2xit1_idx_1 ; real32_T fpxgr2xit1_idx_2 ; if
( ssIsSampleHit ( rtS , 0 , 0 ) ) { fpxgr2xit1_idx_0 = haulnsvtzw [ 0 ] - rtB
. jz0qdcsmmmwh [ prlh41yr04 ] . m05clr3gxy [ 0 ] ; fpxgr2xit1_idx_1 =
haulnsvtzw [ 1 ] - rtB . jz0qdcsmmmwh [ prlh41yr04 ] . m05clr3gxy [ 1 ] ;
fpxgr2xit1_idx_2 = haulnsvtzw [ 2 ] - rtB . jz0qdcsmmmwh [ prlh41yr04 ] .
m05clr3gxy [ 2 ] ; kvobxh0moi [ 0 ] = fpxgr2xit1_idx_1 * nwl3pcl0q5 [ 2 ] -
nwl3pcl0q5 [ 1 ] * fpxgr2xit1_idx_2 ; kvobxh0moi [ 1 ] = nwl3pcl0q5 [ 0 ] *
fpxgr2xit1_idx_2 - fpxgr2xit1_idx_0 * nwl3pcl0q5 [ 2 ] ; kvobxh0moi [ 2 ] =
fpxgr2xit1_idx_0 * nwl3pcl0q5 [ 1 ] - nwl3pcl0q5 [ 0 ] * fpxgr2xit1_idx_1 ; }
} rtB . kainbdj3jznl [ 3 * prlh41yr04 ] = kvobxh0moi [ 0 ] ; rtB .
kainbdj3jznl [ 3 * prlh41yr04 + 1 ] = kvobxh0moi [ 1 ] ; rtB . kainbdj3jznl [
3 * prlh41yr04 + 2 ] = kvobxh0moi [ 2 ] ; } } void cv3gln2abzTID1 ( int32_T
prlh41yr04 ) { rtB . jz0qdcsmmmwh [ prlh41yr04 ] . m05clr3gxy [ 0 ] = (
real32_T ) rtP . xyz_cg [ 0 ] ; rtB . jz0qdcsmmmwh [ prlh41yr04 ] .
m05clr3gxy [ 1 ] = ( real32_T ) rtP . xyz_cg [ 1 ] ; rtB . jz0qdcsmmmwh [
prlh41yr04 ] . m05clr3gxy [ 2 ] = ( real32_T ) rtP . xyz_cg [ 2 ] ; } void
acqwd1nmzk ( void ) { int32_T cbsnj42nfj ; for ( cbsnj42nfj = 0 ; cbsnj42nfj
< 7 ; cbsnj42nfj ++ ) { rtB . jz0qdcsmmmwh5 [ cbsnj42nfj ] . m5kvx1lnef [ 0 ]
= 0.0F ; rtB . jz0qdcsmmmwh5 [ cbsnj42nfj ] . m5kvx1lnef [ 1 ] = 0.0F ; rtB .
jz0qdcsmmmwh5 [ cbsnj42nfj ] . m5kvx1lnef [ 2 ] = 0.0F ; } } void d2dy1jnwgp
( int32_T cbsnj42nfj ) { real32_T haulnsvtzwx [ 3 ] ; real32_T nwl3pcl0q5o [
3 ] ; real32_T kvobxh0moio [ 3 ] ; haulnsvtzwx [ 0 ] = rtP . NodePoints_Value
[ 3 * cbsnj42nfj ] ; nwl3pcl0q5o [ 0 ] = rtB . bavqi0oauug [ 3 * cbsnj42nfj ]
; haulnsvtzwx [ 1 ] = rtP . NodePoints_Value [ 3 * cbsnj42nfj + 1 ] ;
nwl3pcl0q5o [ 1 ] = rtB . bavqi0oauug [ 3 * cbsnj42nfj + 1 ] ; haulnsvtzwx [
2 ] = rtP . NodePoints_Value [ 3 * cbsnj42nfj + 2 ] ; nwl3pcl0q5o [ 2 ] = rtB
. bavqi0oauug [ 3 * cbsnj42nfj + 2 ] ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) {
{ real32_T erwbogreb1_idx_0 ; real32_T erwbogreb1_idx_1 ; real32_T
erwbogreb1_idx_2 ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { erwbogreb1_idx_0 =
haulnsvtzwx [ 0 ] - rtB . jz0qdcsmmmwh5 [ cbsnj42nfj ] . m5kvx1lnef [ 0 ] ;
erwbogreb1_idx_1 = haulnsvtzwx [ 1 ] - rtB . jz0qdcsmmmwh5 [ cbsnj42nfj ] .
m5kvx1lnef [ 1 ] ; erwbogreb1_idx_2 = haulnsvtzwx [ 2 ] - rtB . jz0qdcsmmmwh5
[ cbsnj42nfj ] . m5kvx1lnef [ 2 ] ; kvobxh0moio [ 0 ] = erwbogreb1_idx_1 *
nwl3pcl0q5o [ 2 ] - nwl3pcl0q5o [ 1 ] * erwbogreb1_idx_2 ; kvobxh0moio [ 1 ]
= nwl3pcl0q5o [ 0 ] * erwbogreb1_idx_2 - erwbogreb1_idx_0 * nwl3pcl0q5o [ 2 ]
; kvobxh0moio [ 2 ] = erwbogreb1_idx_0 * nwl3pcl0q5o [ 1 ] - nwl3pcl0q5o [ 0
] * erwbogreb1_idx_1 ; } } rtB . kainbdj3jzn [ 3 * cbsnj42nfj ] = kvobxh0moio
[ 0 ] ; rtB . kainbdj3jzn [ 3 * cbsnj42nfj + 1 ] = kvobxh0moio [ 1 ] ; rtB .
kainbdj3jzn [ 3 * cbsnj42nfj + 2 ] = kvobxh0moio [ 2 ] ; } } void
d2dy1jnwgpTID1 ( int32_T cbsnj42nfj ) { rtB . jz0qdcsmmmwh5 [ cbsnj42nfj ] .
m5kvx1lnef [ 0 ] = ( real32_T ) rtP . xyz_cg [ 0 ] ; rtB . jz0qdcsmmmwh5 [
cbsnj42nfj ] . m5kvx1lnef [ 1 ] = ( real32_T ) rtP . xyz_cg [ 1 ] ; rtB .
jz0qdcsmmmwh5 [ cbsnj42nfj ] . m5kvx1lnef [ 2 ] = ( real32_T ) rtP . xyz_cg [
2 ] ; } void fy3uhmab3v ( int32_T dwdkiverai ) { real32_T ayubdjvtaw ;
real32_T jwhvhr340n [ 3 ] ; real32_T fvusasya33 [ 3 ] ; ayubdjvtaw = rtB .
on23viyejw [ dwdkiverai ] ; jwhvhr340n [ 0 ] = rtB . pqjyj5rgda [ 3 *
dwdkiverai ] ; jwhvhr340n [ 1 ] = rtB . pqjyj5rgda [ 3 * dwdkiverai + 1 ] ;
jwhvhr340n [ 2 ] = rtB . pqjyj5rgda [ 3 * dwdkiverai + 2 ] ; if (
ssIsSampleHit ( rtS , 0 , 0 ) ) { { real_T bfcx4ysa1f [ 9 ] ; real_T
cvcubf3rmo_idx_0 ; real_T cvcubf3rmo_idx_1 ; real_T diyhvcxczz_idx_0 ; real_T
diyhvcxczz_idx_1 ; int32_T i ; real32_T tmp ; real32_T tmp_e ; real32_T tmp_p
; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { muDoubleScalarSinCos ( ayubdjvtaw ,
& diyhvcxczz_idx_0 , & cvcubf3rmo_idx_0 ) ; muDoubleScalarSinCos ( rtP .
jz0qdcsmmmwh5r . Constant_Value_bcqheaf40z , & diyhvcxczz_idx_1 , &
cvcubf3rmo_idx_1 ) ; bfcx4ysa1f [ 0 ] = cvcubf3rmo_idx_0 * cvcubf3rmo_idx_1 ;
bfcx4ysa1f [ 1 ] = - ( cvcubf3rmo_idx_0 * diyhvcxczz_idx_1 ) ; bfcx4ysa1f [ 2
] = - diyhvcxczz_idx_0 ; bfcx4ysa1f [ 3 ] = diyhvcxczz_idx_1 ; bfcx4ysa1f [ 4
] = cvcubf3rmo_idx_1 ; bfcx4ysa1f [ 5 ] = rtP . jz0qdcsmmmwh5r .
Constant_Value ; bfcx4ysa1f [ 6 ] = diyhvcxczz_idx_0 * cvcubf3rmo_idx_1 ;
bfcx4ysa1f [ 7 ] = - ( diyhvcxczz_idx_0 * diyhvcxczz_idx_1 ) ; bfcx4ysa1f [ 8
] = cvcubf3rmo_idx_0 ; tmp = - jwhvhr340n [ 0 ] ; tmp_p = jwhvhr340n [ 1 ] ;
tmp_e = - jwhvhr340n [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { fvusasya33 [ i ]
= ( ( real32_T ) bfcx4ysa1f [ 3 * i + 1 ] * tmp_p + ( real32_T ) bfcx4ysa1f [
3 * i ] * tmp ) + ( real32_T ) bfcx4ysa1f [ 3 * i + 2 ] * tmp_e ; } } } rtB .
bavqi0oauug [ 3 * dwdkiverai ] = fvusasya33 [ 0 ] ; rtB . bavqi0oauug [ 3 *
dwdkiverai + 1 ] = fvusasya33 [ 1 ] ; rtB . bavqi0oauug [ 3 * dwdkiverai + 2
] = fvusasya33 [ 2 ] ; } } void o5hfwszdxw ( void ) { int32_T pjhb2frnhh ;
for ( pjhb2frnhh = 0 ; pjhb2frnhh < 7 ; pjhb2frnhh ++ ) { rtB .
jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 0 ] = 0.0F ; rtB .
jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 1 ] = 0.0F ; rtB .
jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 2 ] = 0.0F ; } } void
pg42w5emjt ( int32_T pjhb2frnhh ) { real32_T haulnsvtzwx3 [ 3 ] ; real32_T
nwl3pcl0q5ob [ 3 ] ; real32_T kvobxh0moiob [ 3 ] ; haulnsvtzwx3 [ 0 ] = rtP .
NodePoints_Value_iel3jxerxr [ 3 * pjhb2frnhh ] ; nwl3pcl0q5ob [ 0 ] = rtB .
bavqi0oauu [ 3 * pjhb2frnhh ] ; haulnsvtzwx3 [ 1 ] = rtP .
NodePoints_Value_iel3jxerxr [ 3 * pjhb2frnhh + 1 ] ; nwl3pcl0q5ob [ 1 ] = rtB
. bavqi0oauu [ 3 * pjhb2frnhh + 1 ] ; haulnsvtzwx3 [ 2 ] = rtP .
NodePoints_Value_iel3jxerxr [ 3 * pjhb2frnhh + 2 ] ; nwl3pcl0q5ob [ 2 ] = rtB
. bavqi0oauu [ 3 * pjhb2frnhh + 2 ] ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) {
{ real32_T hpcfqu512o_idx_0 ; real32_T hpcfqu512o_idx_1 ; real32_T
hpcfqu512o_idx_2 ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { hpcfqu512o_idx_0 =
haulnsvtzwx3 [ 0 ] - rtB . jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 0 ]
; hpcfqu512o_idx_1 = haulnsvtzwx3 [ 1 ] - rtB . jz0qdcsmmmwh5rk [ pjhb2frnhh
] . omlkzp34xv [ 1 ] ; hpcfqu512o_idx_2 = haulnsvtzwx3 [ 2 ] - rtB .
jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 2 ] ; kvobxh0moiob [ 0 ] =
hpcfqu512o_idx_1 * nwl3pcl0q5ob [ 2 ] - nwl3pcl0q5ob [ 1 ] * hpcfqu512o_idx_2
; kvobxh0moiob [ 1 ] = nwl3pcl0q5ob [ 0 ] * hpcfqu512o_idx_2 -
hpcfqu512o_idx_0 * nwl3pcl0q5ob [ 2 ] ; kvobxh0moiob [ 2 ] = hpcfqu512o_idx_0
* nwl3pcl0q5ob [ 1 ] - nwl3pcl0q5ob [ 0 ] * hpcfqu512o_idx_1 ; } } rtB .
kainbdj3jz [ 3 * pjhb2frnhh ] = kvobxh0moiob [ 0 ] ; rtB . kainbdj3jz [ 3 *
pjhb2frnhh + 1 ] = kvobxh0moiob [ 1 ] ; rtB . kainbdj3jz [ 3 * pjhb2frnhh + 2
] = kvobxh0moiob [ 2 ] ; } } void pg42w5emjtTID1 ( int32_T pjhb2frnhh ) { rtB
. jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 0 ] = ( real32_T ) rtP .
xyz_cg [ 0 ] ; rtB . jz0qdcsmmmwh5rk [ pjhb2frnhh ] . omlkzp34xv [ 1 ] = (
real32_T ) rtP . xyz_cg [ 1 ] ; rtB . jz0qdcsmmmwh5rk [ pjhb2frnhh ] .
omlkzp34xv [ 2 ] = ( real32_T ) rtP . xyz_cg [ 2 ] ; } void c0cmetu4kl (
int32_T eevyujj1hd ) { real32_T ayubdjvtawn ; real32_T jwhvhr340nj [ 3 ] ;
real32_T fvusasya33h [ 3 ] ; ayubdjvtawn = rtB . jet1i0an5d [ eevyujj1hd + 7
] ; jwhvhr340nj [ 0 ] = rtB . fpov3sjl4o [ 3 * eevyujj1hd ] ; jwhvhr340nj [ 1
] = rtB . fpov3sjl4o [ 3 * eevyujj1hd + 1 ] ; jwhvhr340nj [ 2 ] = rtB .
fpov3sjl4o [ 3 * eevyujj1hd + 2 ] ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { {
real_T lvyyp3pvs0 [ 9 ] ; real_T lknmqrf40l_idx_0 ; real_T lknmqrf40l_idx_1 ;
real_T pms1qeq3tc_idx_0 ; real_T pms1qeq3tc_idx_1 ; int32_T i ; real32_T tmp
; real32_T tmp_e ; real32_T tmp_p ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) {
muDoubleScalarSinCos ( ayubdjvtawn , & pms1qeq3tc_idx_0 , & lknmqrf40l_idx_0
) ; muDoubleScalarSinCos ( rtP . oeyei2gsmn . Constant_Value_lhjgiuieqz , &
pms1qeq3tc_idx_1 , & lknmqrf40l_idx_1 ) ; lvyyp3pvs0 [ 0 ] = lknmqrf40l_idx_0
* lknmqrf40l_idx_1 ; lvyyp3pvs0 [ 1 ] = - ( lknmqrf40l_idx_0 *
pms1qeq3tc_idx_1 ) ; lvyyp3pvs0 [ 2 ] = - pms1qeq3tc_idx_0 ; lvyyp3pvs0 [ 3 ]
= pms1qeq3tc_idx_1 ; lvyyp3pvs0 [ 4 ] = lknmqrf40l_idx_1 ; lvyyp3pvs0 [ 5 ] =
rtP . oeyei2gsmn . Constant_Value ; lvyyp3pvs0 [ 6 ] = pms1qeq3tc_idx_0 *
lknmqrf40l_idx_1 ; lvyyp3pvs0 [ 7 ] = - ( pms1qeq3tc_idx_0 * pms1qeq3tc_idx_1
) ; lvyyp3pvs0 [ 8 ] = lknmqrf40l_idx_0 ; tmp = - jwhvhr340nj [ 0 ] ; tmp_p =
jwhvhr340nj [ 1 ] ; tmp_e = - jwhvhr340nj [ 2 ] ; for ( i = 0 ; i < 3 ; i ++
) { fvusasya33h [ i ] = ( ( real32_T ) lvyyp3pvs0 [ 3 * i + 1 ] * tmp_p + (
real32_T ) lvyyp3pvs0 [ 3 * i ] * tmp ) + ( real32_T ) lvyyp3pvs0 [ 3 * i + 2
] * tmp_e ; } } } rtB . bavqi0oauu [ 3 * eevyujj1hd ] = fvusasya33h [ 0 ] ;
rtB . bavqi0oauu [ 3 * eevyujj1hd + 1 ] = fvusasya33h [ 1 ] ; rtB .
bavqi0oauu [ 3 * eevyujj1hd + 2 ] = fvusasya33h [ 2 ] ; } } void eehyfjcqm2 (
void ) { int32_T fj0epmyt1u ; for ( fj0epmyt1u = 0 ; fj0epmyt1u < 12 ;
fj0epmyt1u ++ ) { rtB . au023bergz [ fj0epmyt1u ] . fai5wajm52 [ 0 ] = 0.0F ;
rtB . au023bergz [ fj0epmyt1u ] . fai5wajm52 [ 1 ] = 0.0F ; rtB . au023bergz
[ fj0epmyt1u ] . fai5wajm52 [ 2 ] = 0.0F ; memset ( & rtB . au023bergz [
fj0epmyt1u ] . aqav5cdmuv [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; } } void
eo4s0qr2ut ( int32_T fj0epmyt1u ) { real_T p2pgwaudn1 ; real_T biweknxbkt ;
real_T n3zokedgyr ; real_T kbxiq4u1ce [ 3 ] ; real_T dobh5tfoy0 ; real_T
kbf4m1b2t1 [ 3 ] ; real_T augnra3h3i ; real_T ayackqtrya ; real_T nfnxau4mca
; real_T eiacay4vdd [ 3 ] ; p2pgwaudn1 = rtB . fp54rsi3hk [ fj0epmyt1u ] ;
biweknxbkt = rtB . eljuwfhp1f [ fj0epmyt1u ] ; n3zokedgyr = rtP .
Constant2_Value_lirfr5mubp [ fj0epmyt1u ] ; kbxiq4u1ce [ 0 ] = rtP . xyz_DEP
[ 3 * fj0epmyt1u ] ; kbxiq4u1ce [ 1 ] = rtP . xyz_DEP [ 3 * fj0epmyt1u + 1 ]
; kbxiq4u1ce [ 2 ] = rtP . xyz_DEP [ 3 * fj0epmyt1u + 2 ] ; if (
ssIsSampleHit ( rtS , 0 , 0 ) ) { { real_T tmp_p [ 3 ] ; real_T aqav5cdmuv ;
real_T b5uoda2did ; real_T eiacay4vdd_p ; real_T epua10zato ; real_T
hv5dscnoqz ; real_T nssimmlg2n ; real_T oqggjfz503_idx_0 ; real_T
oqggjfz503_idx_1 ; real_T oqggjfz503_idx_2 ; real_T tmp ; real_T tmp_e ;
int32_T i ; if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { if ( biweknxbkt > rtP .
au023bergz . Saturation2_UpperSat ) { epua10zato = rtP . au023bergz .
Saturation2_UpperSat ; } else if ( biweknxbkt < rtP . au023bergz .
Saturation2_LowerSat ) { epua10zato = rtP . au023bergz . Saturation2_LowerSat
; } else { epua10zato = biweknxbkt ; } if ( epua10zato > rtP . au023bergz .
Switch1_Threshold ) { epua10zato = look2_plinlcpw ( p2pgwaudn1 , rtP .
au023bergz . actf2T_Gain * epua10zato , rtP . dp_DEP . rpm_lookup . V_vec ,
rtP . dp_DEP . rpm_lookup . T_vec , rtP . dp_DEP . rpm_lookup . rpm_gird ,
rtDW . au023bergz [ fj0epmyt1u ] . ojom230ae1 , rtP . au023bergz .
T2rpm_maxIndex , 43U ) ; } else { epua10zato = rtP . au023bergz .
Constant3_Value ; } epua10zato *= rtP . au023bergz . Gain1_Gain ; if (
epua10zato > rtP . au023bergz . Saturation_UpperSat ) { hv5dscnoqz = rtP .
au023bergz . Saturation_UpperSat ; } else if ( epua10zato < rtP . au023bergz
. Saturation_LowerSat ) { hv5dscnoqz = rtP . au023bergz . Saturation_LowerSat
; } else { hv5dscnoqz = epua10zato ; } b5uoda2did = hv5dscnoqz * hv5dscnoqz ;
hv5dscnoqz = p2pgwaudn1 / ( rtP . au023bergz . Gain2_Gain * hv5dscnoqz + rtP
. au023bergz . Constant_Value_e5dci5j5wh ) ; if ( hv5dscnoqz > rtP .
au023bergz . Saturation1_UpperSat ) { hv5dscnoqz = rtP . au023bergz .
Saturation1_UpperSat ; } else if ( hv5dscnoqz < rtP . au023bergz .
Saturation1_LowerSat ) { hv5dscnoqz = rtP . au023bergz . Saturation1_LowerSat
; } nssimmlg2n = look1_plinlcapw ( hv5dscnoqz , rtP . dp_DEP . J , rtP .
dp_DEP . C_Q , & rtDW . au023bergz [ fj0epmyt1u ] . hq0naomli3 , 45U ) ;
nssimmlg2n = rtB . jefg5cifsj * nssimmlg2n * b5uoda2did * rtP . au023bergz .
Gain_Gain ; oqggjfz503_idx_0 = kbxiq4u1ce [ 0 ] - rtB . au023bergz [
fj0epmyt1u ] . fai5wajm52 [ 0 ] ; oqggjfz503_idx_1 = kbxiq4u1ce [ 1 ] - rtB .
au023bergz [ fj0epmyt1u ] . fai5wajm52 [ 1 ] ; oqggjfz503_idx_2 = kbxiq4u1ce
[ 2 ] - rtB . au023bergz [ fj0epmyt1u ] . fai5wajm52 [ 2 ] ; ayackqtrya =
look1_plinlcapw ( hv5dscnoqz , rtP . dp_DEP . J , rtP . dp_DEP . C_T , & rtDW
. au023bergz [ fj0epmyt1u ] . g1bez0i0y4 , 45U ) ; nfnxau4mca = rtB .
jefg5cifsj * ayackqtrya * b5uoda2did * rtP . au023bergz . Gain3_Gain ; if (
nfnxau4mca > rtP . au023bergz . Saturation_UpperSat_dzx4r24qqm ) { b5uoda2did
= rtP . au023bergz . Saturation_UpperSat_dzx4r24qqm ; } else if ( nfnxau4mca
< rtP . au023bergz . Saturation_LowerSat_lu14kynpbe ) { b5uoda2did = rtP .
au023bergz . Saturation_LowerSat_lu14kynpbe ; } else { b5uoda2did =
nfnxau4mca ; } if ( nssimmlg2n > rtP . au023bergz .
Saturation1_UpperSat_o3uhb5q0dz ) { tmp = rtP . au023bergz .
Saturation1_UpperSat_o3uhb5q0dz ; } else if ( nssimmlg2n < rtP . au023bergz .
Saturation1_LowerSat_cob1qvjvl1 ) { tmp = rtP . au023bergz .
Saturation1_LowerSat_cob1qvjvl1 ; } else { tmp = nssimmlg2n ; } for ( i = 0 ;
i < 3 ; i ++ ) { aqav5cdmuv = rtB . au023bergz [ fj0epmyt1u ] . aqav5cdmuv [
i ] ; eiacay4vdd_p = aqav5cdmuv * b5uoda2did ; tmp_e = aqav5cdmuv * tmp ;
aqav5cdmuv = rtB . au023bergz [ fj0epmyt1u ] . aqav5cdmuv [ i + 3 ] ;
eiacay4vdd_p += aqav5cdmuv * rtP . au023bergz . Constant_Value ; tmp_e +=
aqav5cdmuv * rtP . au023bergz . Constant_Value ; aqav5cdmuv = rtB .
au023bergz [ fj0epmyt1u ] . aqav5cdmuv [ i + 6 ] ; eiacay4vdd [ i ] =
aqav5cdmuv * rtP . au023bergz . Constant_Value + eiacay4vdd_p ; tmp_p [ i ] =
aqav5cdmuv * rtP . au023bergz . Constant_Value + tmp_e ; } kbf4m1b2t1 [ 0 ] =
( oqggjfz503_idx_1 * eiacay4vdd [ 2 ] - eiacay4vdd [ 1 ] * oqggjfz503_idx_2 )
+ n3zokedgyr * tmp_p [ 0 ] ; kbf4m1b2t1 [ 1 ] = ( eiacay4vdd [ 0 ] *
oqggjfz503_idx_2 - oqggjfz503_idx_0 * eiacay4vdd [ 2 ] ) + n3zokedgyr * tmp_p
[ 1 ] ; kbf4m1b2t1 [ 2 ] = ( oqggjfz503_idx_0 * eiacay4vdd [ 1 ] - eiacay4vdd
[ 0 ] * oqggjfz503_idx_1 ) + n3zokedgyr * tmp_p [ 2 ] ; if ( hv5dscnoqz > rtP
. au023bergz . Saturation3_UpperSat ) { augnra3h3i = rtP . au023bergz .
Saturation3_UpperSat ; } else if ( hv5dscnoqz < rtP . au023bergz .
Saturation3_LowerSat ) { augnra3h3i = rtP . au023bergz . Saturation3_LowerSat
; } else { augnra3h3i = hv5dscnoqz ; } dobh5tfoy0 = rtP . au023bergz .
Gain3_Gain_kiqvbbswpr * epua10zato * nssimmlg2n ; } } rtB . p1lfhtknc0 [
fj0epmyt1u ] = nfnxau4mca ; rtB . nluycx3bh3 [ fj0epmyt1u ] = dobh5tfoy0 ;
rtB . etlvxwxtcy [ fj0epmyt1u ] = augnra3h3i ; rtB . jltpjpl4zp [ 3 *
fj0epmyt1u ] = kbf4m1b2t1 [ 0 ] ; rtB . fqp13muoyo [ 3 * fj0epmyt1u ] =
eiacay4vdd [ 0 ] ; rtB . jltpjpl4zp [ 3 * fj0epmyt1u + 1 ] = kbf4m1b2t1 [ 1 ]
; rtB . fqp13muoyo [ 3 * fj0epmyt1u + 1 ] = eiacay4vdd [ 1 ] ; rtB .
jltpjpl4zp [ 3 * fj0epmyt1u + 2 ] = kbf4m1b2t1 [ 2 ] ; rtB . fqp13muoyo [ 3 *
fj0epmyt1u + 2 ] = eiacay4vdd [ 2 ] ; rtB . bftm5ocvno [ fj0epmyt1u ] =
ayackqtrya ; } } void eo4s0qr2utTID1 ( int32_T fj0epmyt1u ) { { real_T
h4cy4pgi0v [ 9 ] ; real_T ksict2jjkw_idx_0 ; real_T ksict2jjkw_idx_1 ; real_T
ksict2jjkw_idx_2 ; real_T ppbeju2eke_idx_0 ; real_T ppbeju2eke_idx_1 ; real_T
ppbeju2eke_idx_2 ; int32_T i ; rtB . au023bergz [ fj0epmyt1u ] . fai5wajm52 [
0 ] = ( real32_T ) rtP . xyz_cg [ 0 ] ; muDoubleScalarSinCos ( rtP .
au023bergz . Constant1_Value , & ksict2jjkw_idx_0 , & ppbeju2eke_idx_0 ) ;
rtB . au023bergz [ fj0epmyt1u ] . fai5wajm52 [ 1 ] = ( real32_T ) rtP .
xyz_cg [ 1 ] ; muDoubleScalarSinCos ( rtP . au023bergz . DEP_incidence_Value
, & ksict2jjkw_idx_1 , & ppbeju2eke_idx_1 ) ; rtB . au023bergz [ fj0epmyt1u ]
. fai5wajm52 [ 2 ] = ( real32_T ) rtP . xyz_cg [ 2 ] ; muDoubleScalarSinCos (
rtP . au023bergz . Constant1_Value , & ksict2jjkw_idx_2 , & ppbeju2eke_idx_2
) ; h4cy4pgi0v [ 0 ] = ppbeju2eke_idx_0 * ppbeju2eke_idx_1 ; h4cy4pgi0v [ 1 ]
= ksict2jjkw_idx_1 * ksict2jjkw_idx_2 * ppbeju2eke_idx_0 - ksict2jjkw_idx_0 *
ppbeju2eke_idx_2 ; h4cy4pgi0v [ 2 ] = ksict2jjkw_idx_1 * ppbeju2eke_idx_2 *
ppbeju2eke_idx_0 + ksict2jjkw_idx_0 * ksict2jjkw_idx_2 ; h4cy4pgi0v [ 3 ] =
ksict2jjkw_idx_0 * ppbeju2eke_idx_1 ; h4cy4pgi0v [ 4 ] = ksict2jjkw_idx_1 *
ksict2jjkw_idx_2 * ksict2jjkw_idx_0 + ppbeju2eke_idx_0 * ppbeju2eke_idx_2 ;
h4cy4pgi0v [ 5 ] = ksict2jjkw_idx_1 * ppbeju2eke_idx_2 * ksict2jjkw_idx_0 -
ppbeju2eke_idx_0 * ksict2jjkw_idx_2 ; h4cy4pgi0v [ 6 ] = - ksict2jjkw_idx_1 ;
h4cy4pgi0v [ 7 ] = ppbeju2eke_idx_1 * ksict2jjkw_idx_2 ; h4cy4pgi0v [ 8 ] =
ppbeju2eke_idx_1 * ppbeju2eke_idx_2 ; for ( i = 0 ; i < 3 ; i ++ ) { rtB .
au023bergz [ fj0epmyt1u ] . aqav5cdmuv [ 3 * i ] = h4cy4pgi0v [ i ] ; rtB .
au023bergz [ fj0epmyt1u ] . aqav5cdmuv [ 3 * i + 1 ] = h4cy4pgi0v [ i + 3 ] ;
rtB . au023bergz [ fj0epmyt1u ] . aqav5cdmuv [ 3 * i + 2 ] = h4cy4pgi0v [ i +
6 ] ; } } } void rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( const real_T u0 [ 3 ]
, const real_T u1 [ 9 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; real_T a21 ;
real_T maxval ; int32_T r1 ; int32_T r2 ; int32_T r3 ; int32_T rtemp ; memcpy
( & A [ 0 ] , & u1 [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 =
2 ; maxval = muDoubleScalarAbs ( u1 [ 0 ] ) ; a21 = muDoubleScalarAbs ( u1 [
1 ] ) ; if ( a21 > maxval ) { maxval = a21 ; r1 = 1 ; r2 = 0 ; } if (
muDoubleScalarAbs ( u1 [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } A [
r2 ] = u1 [ r2 ] / u1 [ r1 ] ; A [ r3 ] /= A [ r1 ] ; A [ r2 + 3 ] -= A [ r1
+ 3 ] * A [ r2 ] ; A [ r3 + 3 ] -= A [ r1 + 3 ] * A [ r3 ] ; A [ r2 + 6 ] -=
A [ r1 + 6 ] * A [ r2 ] ; A [ r3 + 6 ] -= A [ r1 + 6 ] * A [ r3 ] ; if (
muDoubleScalarAbs ( A [ r3 + 3 ] ) > muDoubleScalarAbs ( A [ r2 + 3 ] ) ) {
rtemp = r2 + 1 ; r2 = r3 ; r3 = rtemp - 1 ; } A [ r3 + 3 ] /= A [ r2 + 3 ] ;
A [ r3 + 6 ] -= A [ r3 + 3 ] * A [ r2 + 6 ] ; y [ r1 ] = u0 [ 0 ] / A [ r1 ]
; y [ r2 ] = u0 [ 1 ] - A [ r1 + 3 ] * y [ r1 ] ; y [ r3 ] = u0 [ 2 ] - A [
r1 + 6 ] * y [ r1 ] ; y [ r2 ] /= A [ r2 + 3 ] ; y [ r3 ] -= A [ r2 + 6 ] * y
[ r2 ] ; y [ r3 ] /= A [ r3 + 6 ] ; y [ r2 ] -= A [ r3 + 3 ] * y [ r3 ] ; y [
r1 ] -= y [ r3 ] * A [ r3 ] ; y [ r1 ] -= y [ r2 ] * A [ r2 ] ; } void
MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) {
rtwISigstreamManagerSetDestinationBase ( pISigstreamManager , 0 , & rtU .
p1y0j2wmyr ) ; } } { { { bool isStreamoutAlreadyRegistered = false ; {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "UNIFIER_dyn/Out1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 70 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . mw5cjkjcde . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "fa97162e-fbd9-4200-9f3d-ff04a20ca80b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . mw5cjkjcde . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . mw5cjkjcde . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . mw5cjkjcde . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . mw5cjkjcde .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . mw5cjkjcde . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
mw5cjkjcde . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
mw5cjkjcde . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . mw5cjkjcde . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . mw5cjkjcde . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } ijft5h35rv ( ) ; cjkzdk20zl ( ) ;
oa24tgolov ( ) ; rtDW . lmdux514h1 = 0 ; lbtqalrtao ( ) ; acqwd1nmzk ( ) ;
o5hfwszdxw ( ) ; rtDW . ckg5ciehpx = 0 ; eehyfjcqm2 ( ) ; } void MdlOutputs (
int_T tid ) { real_T dagu2sl5i1 [ 70 ] ; real_T gvxohgx2qx [ 48 ] ; real_T
do1u0posi5 [ 21 ] ; real_T frac_d [ 4 ] ; real_T frac_l [ 4 ] ; real_T
esrvq4wxba [ 3 ] ; real_T frac_dz [ 3 ] ; real_T frac_fs [ 3 ] ; real_T
frac_fv [ 3 ] ; real_T frac_m4 [ 3 ] ; real_T frac_nf [ 3 ] ; real_T frac_o [
3 ] ; real_T Constant8_Value_cr0us2qlbv ; real_T f0ykxvjp2e ; int32_T i ;
int32_T i_p ; real32_T m5u5mthwev [ 48 ] ; real32_T ec1iub14lo [ 21 ] ;
real32_T kgeeoq3i0q [ 21 ] ; real32_T ktfulnpz4m [ 21 ] ; real32_T dpbd4xswtf
[ 16 ] ; real32_T ep5pua1w1i [ 16 ] ; real32_T gs5wgqurd1 [ 16 ] ; real32_T
njokkaqa44 [ 16 ] ; real32_T kmby3hj4tx [ 12 ] ; real32_T fcnqqv3bsy [ 5 ] ;
real32_T gzu1zm2zul [ 5 ] ; real32_T jtk2ho12tm [ 5 ] ; real32_T m25svtzs1a [
5 ] ; real32_T p52cvq2maf [ 5 ] ; real32_T pwsv0izi4l [ 5 ] ; real32_T frac [
4 ] ; real32_T frac_ap [ 4 ] ; real32_T frac_b [ 4 ] ; real32_T frac_c [ 4 ]
; real32_T frac_ck [ 4 ] ; real32_T frac_d0 [ 4 ] ; real32_T frac_e [ 4 ] ;
real32_T frac_f [ 4 ] ; real32_T frac_f2 [ 4 ] ; real32_T frac_g [ 4 ] ;
real32_T frac_hn [ 4 ] ; real32_T frac_i [ 4 ] ; real32_T frac_j [ 4 ] ;
real32_T frac_k [ 4 ] ; real32_T frac_kh [ 4 ] ; real32_T frac_kt [ 4 ] ;
real32_T frac_lt [ 4 ] ; real32_T frac_m [ 4 ] ; real32_T frac_m0 [ 4 ] ;
real32_T frac_n [ 4 ] ; real32_T frac_p [ 4 ] ; real32_T frac_pj [ 4 ] ;
real32_T frac_pk [ 4 ] ; real32_T frac_po [ 4 ] ; real32_T d1dhbqr5yc [ 2 ] ;
real32_T hszv10yckq [ 2 ] ; real32_T hvtxsdprmj [ 2 ] ; real32_T orrknllzxd [
2 ] ; real32_T pgkyyjejl3 [ 2 ] ; real32_T pjs3tdc01w [ 2 ] ; real32_T
bzcsjahvxl_p ; real32_T cuyoqaviu3_idx_0 ; real32_T cuyoqaviu3_idx_1 ;
real32_T cuyoqaviu3_idx_2 ; real32_T e5eea4yz11 ; real32_T nntliqh2c3 ;
real32_T noivdi5wij ; real32_T og2mhjvxrf_idx_0 ; real32_T og2mhjvxrf_idx_1 ;
real32_T og2mhjvxrf_idx_2 ; uint32_T h3nw55tjpp [ 16 ] ; uint32_T hg0sesl5ey
[ 16 ] ; uint32_T p4lqtpxnj2 [ 16 ] ; uint32_T bpIndex [ 5 ] ; uint32_T
bpIndex_ap [ 5 ] ; uint32_T bpIndex_b [ 5 ] ; uint32_T bpIndex_c [ 5 ] ;
uint32_T bpIndex_ck [ 5 ] ; uint32_T bpIndex_d [ 5 ] ; uint32_T bpIndex_d0 [
5 ] ; uint32_T bpIndex_e [ 5 ] ; uint32_T bpIndex_f [ 5 ] ; uint32_T
bpIndex_f2 [ 5 ] ; uint32_T bpIndex_g [ 5 ] ; uint32_T bpIndex_hn [ 5 ] ;
uint32_T bpIndex_i [ 5 ] ; uint32_T bpIndex_j [ 5 ] ; uint32_T bpIndex_k [ 5
] ; uint32_T bpIndex_kh [ 5 ] ; uint32_T bpIndex_kt [ 5 ] ; uint32_T
bpIndex_l [ 5 ] ; uint32_T bpIndex_lt [ 5 ] ; uint32_T bpIndex_m [ 5 ] ;
uint32_T bpIndex_m0 [ 5 ] ; uint32_T bpIndex_n [ 5 ] ; uint32_T bpIndex_p [ 5
] ; uint32_T bpIndex_pj [ 5 ] ; uint32_T bpIndex_pk [ 5 ] ; uint32_T
bpIndex_po [ 5 ] ; uint32_T glk5ydjkx2 [ 5 ] ; uint32_T i21j1alng4 [ 5 ] ;
uint32_T ii2emm2n0y [ 5 ] ; uint32_T bpIndex_dz [ 4 ] ; uint32_T bpIndex_fs [
4 ] ; uint32_T bpIndex_fv [ 4 ] ; uint32_T bpIndex_m4 [ 4 ] ; uint32_T
bpIndex_nf [ 4 ] ; uint32_T bpIndex_o [ 4 ] ; uint32_T d2tzmda3nu ; uint32_T
e20nx452ly_idx_0 ; uint32_T e20nx452ly_idx_1 ; uint32_T glo3iuekqm ; uint32_T
h2f22pqghw_idx_0 ; uint32_T h2f22pqghw_idx_1 ; uint32_T mwzdolw5gj_idx_0 ;
uint32_T mwzdolw5gj_idx_1 ; uint32_T ok0ziasf2d_idx_0 ; uint32_T
ok0ziasf2d_idx_1 ; uint32_T oogct0iaeu_idx_0 ; uint32_T oogct0iaeu_idx_1 ;
uint32_T pmh50qaazg ; uint32_T pykbfcgxvc_idx_0 ; uint32_T pykbfcgxvc_idx_1 ;
if ( gblExecutionInfo . gblObjects_ . inportFileName != ( NULL ) ) { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( slIsRapidAcceleratorSimulating ( ) &&
externalInputIsInDatasetFormat ) { const int maxErrorBufferSize = 16384 ;
char_T errMsg [ 16384 ] ; bool bSetErrorStatus = false ; if ( ssIsSampleHit (
rtS , 0 , 0 ) ) { { real_T time = ssGetTaskTime ( rtS , 0 ) ; if ( !
rtwISigstreamManagerIsPeriodicFcnCall ( pISigstreamManager , 0 ) ) { int_T
sampleHit = 0U ; bSetErrorStatus = rtwISigstreamManagerInjectDataMultiRate (
pISigstreamManager , 0 , time , 1 , "<Root>/in" , "[t, u]" , & sampleHit ,
errMsg , maxErrorBufferSize ) ; } } } if ( bSetErrorStatus ) {
ssSetErrorStatus ( rtS , errMsg ) ; return ; } } else { int_T currTimeIdx ;
int_T i ; if ( gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] .
nTimePoints > 0 ) { if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { { real_T time =
ssGetTaskTime ( rtS , 0 ) ; int k = 1 ; if ( gblExecutionInfo . gblObjects_ .
inportTUtables [ 0 ] . nTimePoints == 1 ) { k = 0 ; } currTimeIdx =
rt_getTimeIdx ( gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] . time
, time , gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] . nTimePoints
, * ( gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] . currTimeIdx ) ,
1 , 0 ) ; ( * gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] .
currTimeIdx ) = currTimeIdx ; for ( i = 0 ; i < 1 ; i ++ ) { real_T *
realPtr1 = ( real_T * ) gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ]
. ur + i * gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] .
nTimePoints + currTimeIdx ; real_T * realPtr2 = realPtr1 + 1 * k ; ( void )
rt_Interpolate_Datatype ( realPtr1 , realPtr2 , & rtU . p1y0j2wmyr , time ,
gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] . time [ currTimeIdx ]
, gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] . time [ currTimeIdx
+ k ] , gblExecutionInfo . gblObjects_ . inportTUtables [ 0 ] . uDataType ) ;
} } } } } } if ( ssIsSampleHit ( rtS , 0 , 0 ) ) { parallel_for ( 14 ,
f53wtq1cer , 1 , "f53wtq1cer" ) ; rtB . on23viyejw [ 0 ] = rtB . jet1i0an5d [
6 ] ; rtB . on23viyejw [ 1 ] = rtB . jet1i0an5d [ 5 ] ; rtB . on23viyejw [ 2
] = rtB . jet1i0an5d [ 4 ] ; rtB . on23viyejw [ 3 ] = rtB . jet1i0an5d [ 3 ]
; rtB . on23viyejw [ 4 ] = rtB . jet1i0an5d [ 2 ] ; rtB . on23viyejw [ 5 ] =
rtB . jet1i0an5d [ 1 ] ; rtB . on23viyejw [ 6 ] = rtB . jet1i0an5d [ 0 ] ;
ec1iub14lo [ 0 ] = rtB . crx1qgibvo [ 6 ] ; ec1iub14lo [ 1 ] = rtB .
crx1qgibvo [ 5 ] ; ec1iub14lo [ 2 ] = rtB . crx1qgibvo [ 4 ] ; ec1iub14lo [ 3
] = rtB . crx1qgibvo [ 3 ] ; ec1iub14lo [ 4 ] = rtB . crx1qgibvo [ 2 ] ;
ec1iub14lo [ 5 ] = rtB . crx1qgibvo [ 1 ] ; ec1iub14lo [ 6 ] = rtB .
crx1qgibvo [ 0 ] ; ec1iub14lo [ 7 ] = rtB . crx1qgibvo [ 6 ] ; ec1iub14lo [ 8
] = rtB . crx1qgibvo [ 5 ] ; ec1iub14lo [ 9 ] = rtB . crx1qgibvo [ 4 ] ;
ec1iub14lo [ 10 ] = rtB . crx1qgibvo [ 3 ] ; ec1iub14lo [ 11 ] = rtB .
crx1qgibvo [ 2 ] ; ec1iub14lo [ 12 ] = rtB . crx1qgibvo [ 1 ] ; ec1iub14lo [
13 ] = rtB . crx1qgibvo [ 0 ] ; ec1iub14lo [ 14 ] = rtB . crx1qgibvo [ 6 ] ;
ec1iub14lo [ 15 ] = rtB . crx1qgibvo [ 5 ] ; ec1iub14lo [ 16 ] = rtB .
crx1qgibvo [ 4 ] ; ec1iub14lo [ 17 ] = rtB . crx1qgibvo [ 3 ] ; ec1iub14lo [
18 ] = rtB . crx1qgibvo [ 2 ] ; ec1iub14lo [ 19 ] = rtB . crx1qgibvo [ 1 ] ;
ec1iub14lo [ 20 ] = rtB . crx1qgibvo [ 0 ] ; for ( i_p = 0 ; i_p < 7 ; i_p ++
) { kgeeoq3i0q [ 3 * i_p ] = ec1iub14lo [ i_p ] ; kgeeoq3i0q [ 3 * i_p + 1 ]
= ec1iub14lo [ i_p + 7 ] ; kgeeoq3i0q [ 3 * i_p + 2 ] = ec1iub14lo [ i_p + 14
] ; } for ( i_p = 0 ; i_p < 21 ; i_p ++ ) { og2mhjvxrf_idx_0 = kgeeoq3i0q [
i_p ] ; ec1iub14lo [ i_p ] = og2mhjvxrf_idx_0 * og2mhjvxrf_idx_0 ; }
jtk2ho12tm [ 0 ] = rtB . jet1i0an5d [ 6 ] ; jtk2ho12tm [ 1 ] = rtB .
jet1i0an5d [ 5 ] ; jtk2ho12tm [ 2 ] = rtB . jet1i0an5d [ 4 ] ; jtk2ho12tm [ 3
] = rtB . jet1i0an5d [ 3 ] ; jtk2ho12tm [ 4 ] = rtB . jet1i0an5d [ 2 ] ; for
( i_p = 0 ; i_p < 5 ; i_p ++ ) { glk5ydjkx2 [ i_p ] = plook_u32ff_lincpa (
jtk2ho12tm [ i_p ] , rtP . dp_WING_root . alphas , 24U , & fcnqqv3bsy [ i_p ]
, & rtDW . esnn32lqad [ i_p ] ) ; } jtk2ho12tm [ 0 ] = rtB . crx1qgibvo [ 6 ]
; jtk2ho12tm [ 1 ] = rtB . crx1qgibvo [ 5 ] ; jtk2ho12tm [ 2 ] = rtB .
crx1qgibvo [ 4 ] ; jtk2ho12tm [ 3 ] = rtB . crx1qgibvo [ 3 ] ; jtk2ho12tm [ 4
] = rtB . crx1qgibvo [ 2 ] ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { ii2emm2n0y
[ i_p ] = plook_u32ff_lincpa ( jtk2ho12tm [ i_p ] , rtP . dp_WING_root . V ,
1U , & pwsv0izi4l [ i_p ] , & rtDW . lkiofcx0nc [ i_p ] ) ; } parallel_for (
12 , b4xsnziie2 , 1 , "b4xsnziie2" ) ; parallel_for ( 12 , eo4s0qr2ut , 1 ,
"eo4s0qr2ut" ) ; for ( i_p = 0 ; i_p < 12 ; i_p ++ ) { kmby3hj4tx [ i_p ] = (
real32_T ) rtB . etlvxwxtcy [ i_p ] ; } jtk2ho12tm [ 0 ] = kmby3hj4tx [ 5 ] ;
jtk2ho12tm [ 1 ] = kmby3hj4tx [ 4 ] ; jtk2ho12tm [ 2 ] = kmby3hj4tx [ 3 ] ;
jtk2ho12tm [ 3 ] = kmby3hj4tx [ 2 ] ; jtk2ho12tm [ 4 ] = kmby3hj4tx [ 1 ] ;
for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { i21j1alng4 [ i_p ] = plook_u32ff_lincpa
( jtk2ho12tm [ i_p ] , rtP . dp_WING_root . DEP_J , 6U , & m25svtzs1a [ i_p ]
, & rtDW . d45t54zzh0 [ i_p ] ) ; } frac [ 0 ] = rtB . ayw0otszrq ; bpIndex [
0 ] = rtB . g53iqbai0i ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { frac [ 1 ] =
fcnqqv3bsy [ i_p ] ; frac [ 2 ] = pwsv0izi4l [ i_p ] ; frac [ 3 ] =
m25svtzs1a [ i_p ] ; bpIndex [ 1 ] = glk5ydjkx2 [ i_p ] ; bpIndex [ 2 ] =
ii2emm2n0y [ i_p ] ; bpIndex [ 3 ] = i21j1alng4 [ i_p ] ; f0ykxvjp2e = rtP .
Constant8_Value_dj5ncyqbcf [ i_p ] ; if ( f0ykxvjp2e > 4.0 ) { bpIndex [ 4 ]
= 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex [ 4 ] = ( uint32_T )
f0ykxvjp2e ; } else { bpIndex [ 4 ] = 0U ; } kgeeoq3i0q [ i_p ] =
intrp4d_fu32fla_pw ( bpIndex , frac , & rtP . dp_WING_root . CD [ 1750U *
bpIndex [ 4 ] ] , rtP . InterpolationUsingPrelookup1_dimSize , rtP .
InterpolationUsingPrelookup1_maxIndex ) ; } e20nx452ly_idx_0 =
plook_u32ff_lincpa ( rtB . jet1i0an5d [ 1 ] , rtP . dp_WING_tip . alphas ,
24U , & hvtxsdprmj [ 0 ] , & rtDW . obz0u22bxk [ 0 ] ) ; e20nx452ly_idx_1 =
plook_u32ff_lincpa ( rtB . jet1i0an5d [ 0 ] , rtP . dp_WING_tip . alphas ,
24U , & hvtxsdprmj [ 1 ] , & rtDW . obz0u22bxk [ 1 ] ) ; oogct0iaeu_idx_0 =
plook_u32ff_lincpa ( rtB . crx1qgibvo [ 1 ] , rtP . dp_WING_tip . V , 1U , &
hszv10yckq [ 0 ] , & rtDW . mtbzqory0k [ 0 ] ) ; oogct0iaeu_idx_1 =
plook_u32ff_lincpa ( rtB . crx1qgibvo [ 0 ] , rtP . dp_WING_tip . V , 1U , &
hszv10yckq [ 1 ] , & rtDW . mtbzqory0k [ 1 ] ) ; ok0ziasf2d_idx_0 =
plook_u32ff_lincpa ( kmby3hj4tx [ 1 ] , rtP . dp_WING_tip . DEP_J , 6U , &
d1dhbqr5yc [ 0 ] , & rtDW . cv4ea1x5bf [ 0 ] ) ; ok0ziasf2d_idx_1 =
plook_u32ff_lincpa ( kmby3hj4tx [ 0 ] , rtP . dp_WING_tip . DEP_J , 6U , &
d1dhbqr5yc [ 1 ] , & rtDW . cv4ea1x5bf [ 1 ] ) ; frac_p [ 0 ] = rtB .
lkci5wisjr ; bpIndex_p [ 0 ] = rtB . jqfgyi5cqv ; frac_p [ 1 ] = hvtxsdprmj [
0 ] ; frac_p [ 2 ] = hszv10yckq [ 0 ] ; frac_p [ 3 ] = d1dhbqr5yc [ 0 ] ;
bpIndex_p [ 1 ] = e20nx452ly_idx_0 ; bpIndex_p [ 2 ] = oogct0iaeu_idx_0 ;
bpIndex_p [ 3 ] = ok0ziasf2d_idx_0 ; if ( rtP . Constant8_Value_hy4ct0z05y [
0 ] > 1.0 ) { bpIndex_p [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_hy4ct0z05y [ 0 ] >= 0.0 ) { bpIndex_p [ 4 ] = ( uint32_T )
rtP . Constant8_Value_hy4ct0z05y [ 0 ] ; } else { bpIndex_p [ 4 ] = 0U ; }
kgeeoq3i0q [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_p , frac_p , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_p [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_goowtl1isu , rtP .
InterpolationUsingPrelookup1_maxIndex_gcrts0kvey ) ; frac_p [ 1 ] =
hvtxsdprmj [ 1 ] ; frac_p [ 2 ] = hszv10yckq [ 1 ] ; frac_p [ 3 ] =
d1dhbqr5yc [ 1 ] ; bpIndex_p [ 1 ] = e20nx452ly_idx_1 ; bpIndex_p [ 2 ] =
oogct0iaeu_idx_1 ; bpIndex_p [ 3 ] = ok0ziasf2d_idx_1 ; if ( rtP .
Constant8_Value_hy4ct0z05y [ 1 ] > 1.0 ) { bpIndex_p [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_hy4ct0z05y [ 1 ] >= 0.0 ) { bpIndex_p [ 4 ] = (
uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 1 ] ; } else { bpIndex_p [ 4 ]
= 0U ; } kgeeoq3i0q [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_p , frac_p , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_p [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_goowtl1isu , rtP .
InterpolationUsingPrelookup1_maxIndex_gcrts0kvey ) ; frac_e [ 0 ] = rtB .
ayw0otszrq ; bpIndex_e [ 0 ] = rtB . g53iqbai0i ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_e [ 1 ] = fcnqqv3bsy [ i_p ] ; frac_e [ 2 ] = pwsv0izi4l [
i_p ] ; frac_e [ 3 ] = m25svtzs1a [ i_p ] ; bpIndex_e [ 1 ] = glk5ydjkx2 [
i_p ] ; bpIndex_e [ 2 ] = ii2emm2n0y [ i_p ] ; bpIndex_e [ 3 ] = i21j1alng4 [
i_p ] ; f0ykxvjp2e = rtP . Constant8_Value_dj5ncyqbcf [ i_p ] ; if (
f0ykxvjp2e > 4.0 ) { bpIndex_e [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) {
bpIndex_e [ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_e [ 4 ] = 0U ; }
kgeeoq3i0q [ i_p + 7 ] = intrp4d_fu32fla_pw ( bpIndex_e , frac_e , & rtP .
dp_WING_root . CS [ 1750U * bpIndex_e [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize , rtP .
InterpolationUsingPrelookup2_maxIndex ) ; } frac_i [ 0 ] = rtB . lkci5wisjr ;
bpIndex_i [ 0 ] = rtB . jqfgyi5cqv ; frac_i [ 1 ] = hvtxsdprmj [ 0 ] ; frac_i
[ 2 ] = hszv10yckq [ 0 ] ; frac_i [ 3 ] = d1dhbqr5yc [ 0 ] ; bpIndex_i [ 1 ]
= e20nx452ly_idx_0 ; bpIndex_i [ 2 ] = oogct0iaeu_idx_0 ; bpIndex_i [ 3 ] =
ok0ziasf2d_idx_0 ; if ( rtP . Constant8_Value_hy4ct0z05y [ 0 ] > 1.0 ) {
bpIndex_i [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_hy4ct0z05y [ 0 ] >=
0.0 ) { bpIndex_i [ 4 ] = ( uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 0 ]
; } else { bpIndex_i [ 4 ] = 0U ; } kgeeoq3i0q [ 12 ] = intrp4d_fu32fla_pw (
bpIndex_i , frac_i , & rtP . dp_WING_tip . CS [ 2450U * bpIndex_i [ 4 ] ] ,
rtP . InterpolationUsingPrelookup2_dimSize_hjcwwxhrb2 , rtP .
InterpolationUsingPrelookup2_maxIndex_hmktoionv2 ) ; frac_i [ 1 ] =
hvtxsdprmj [ 1 ] ; frac_i [ 2 ] = hszv10yckq [ 1 ] ; frac_i [ 3 ] =
d1dhbqr5yc [ 1 ] ; bpIndex_i [ 1 ] = e20nx452ly_idx_1 ; bpIndex_i [ 2 ] =
oogct0iaeu_idx_1 ; bpIndex_i [ 3 ] = ok0ziasf2d_idx_1 ; if ( rtP .
Constant8_Value_hy4ct0z05y [ 1 ] > 1.0 ) { bpIndex_i [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_hy4ct0z05y [ 1 ] >= 0.0 ) { bpIndex_i [ 4 ] = (
uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 1 ] ; } else { bpIndex_i [ 4 ]
= 0U ; } kgeeoq3i0q [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_i , frac_i , & rtP
. dp_WING_tip . CS [ 2450U * bpIndex_i [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_hjcwwxhrb2 , rtP .
InterpolationUsingPrelookup2_maxIndex_hmktoionv2 ) ; frac_m [ 0 ] = rtB .
ayw0otszrq ; bpIndex_m [ 0 ] = rtB . g53iqbai0i ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_m [ 1 ] = fcnqqv3bsy [ i_p ] ; frac_m [ 2 ] = pwsv0izi4l [
i_p ] ; frac_m [ 3 ] = m25svtzs1a [ i_p ] ; bpIndex_m [ 1 ] = glk5ydjkx2 [
i_p ] ; bpIndex_m [ 2 ] = ii2emm2n0y [ i_p ] ; bpIndex_m [ 3 ] = i21j1alng4 [
i_p ] ; f0ykxvjp2e = rtP . Constant8_Value_dj5ncyqbcf [ i_p ] ; if (
f0ykxvjp2e > 4.0 ) { bpIndex_m [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) {
bpIndex_m [ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_m [ 4 ] = 0U ; }
kgeeoq3i0q [ i_p + 14 ] = intrp4d_fu32fla_pw ( bpIndex_m , frac_m , & rtP .
dp_WING_root . CL [ 1750U * bpIndex_m [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize , rtP .
InterpolationUsingPrelookup3_maxIndex ) ; } frac_g [ 0 ] = rtB . lkci5wisjr ;
bpIndex_g [ 0 ] = rtB . jqfgyi5cqv ; frac_g [ 1 ] = hvtxsdprmj [ 0 ] ; frac_g
[ 2 ] = hszv10yckq [ 0 ] ; frac_g [ 3 ] = d1dhbqr5yc [ 0 ] ; bpIndex_g [ 1 ]
= e20nx452ly_idx_0 ; bpIndex_g [ 2 ] = oogct0iaeu_idx_0 ; bpIndex_g [ 3 ] =
ok0ziasf2d_idx_0 ; if ( rtP . Constant8_Value_hy4ct0z05y [ 0 ] > 1.0 ) {
bpIndex_g [ 4 ] = 1U ; } else if ( rtP . Constant8_Value_hy4ct0z05y [ 0 ] >=
0.0 ) { bpIndex_g [ 4 ] = ( uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 0 ]
; } else { bpIndex_g [ 4 ] = 0U ; } kgeeoq3i0q [ 19 ] = intrp4d_fu32fla_pw (
bpIndex_g , frac_g , & rtP . dp_WING_tip . CL [ 2450U * bpIndex_g [ 4 ] ] ,
rtP . InterpolationUsingPrelookup3_dimSize_eey1a1evp1 , rtP .
InterpolationUsingPrelookup3_maxIndex_inqyzx0bkv ) ; frac_g [ 1 ] =
hvtxsdprmj [ 1 ] ; frac_g [ 2 ] = hszv10yckq [ 1 ] ; frac_g [ 3 ] =
d1dhbqr5yc [ 1 ] ; bpIndex_g [ 1 ] = e20nx452ly_idx_1 ; bpIndex_g [ 2 ] =
oogct0iaeu_idx_1 ; bpIndex_g [ 3 ] = ok0ziasf2d_idx_1 ; if ( rtP .
Constant8_Value_hy4ct0z05y [ 1 ] > 1.0 ) { bpIndex_g [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_hy4ct0z05y [ 1 ] >= 0.0 ) { bpIndex_g [ 4 ] = (
uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 1 ] ; } else { bpIndex_g [ 4 ]
= 0U ; } kgeeoq3i0q [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_g , frac_g , & rtP
. dp_WING_tip . CL [ 2450U * bpIndex_g [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_eey1a1evp1 , rtP .
InterpolationUsingPrelookup3_maxIndex_inqyzx0bkv ) ; for ( i_p = 0 ; i_p < 7
; i_p ++ ) { rtB . pqjyj5rgda [ 3 * i_p ] = ec1iub14lo [ 3 * i_p ] *
kgeeoq3i0q [ i_p ] * rtB . ecjaklyjaq * rtP . Gain_Gain_ovou53gniu ; rtB .
pqjyj5rgda [ 3 * i_p + 1 ] = ec1iub14lo [ 3 * i_p + 1 ] * kgeeoq3i0q [ i_p +
7 ] * rtB . ecjaklyjaq * rtP . Gain_Gain_ovou53gniu ; rtB . pqjyj5rgda [ 3 *
i_p + 2 ] = ec1iub14lo [ 3 * i_p + 2 ] * kgeeoq3i0q [ i_p + 14 ] * rtB .
ecjaklyjaq * rtP . Gain_Gain_ovou53gniu ; } parallel_for ( 7 , fy3uhmab3v , 1
, "fy3uhmab3v" ) ; for ( i_p = 0 ; i_p < 21 ; i_p ++ ) { do1u0posi5 [ i_p ] =
rtB . bavqi0oauug [ i_p ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { f0ykxvjp2e
= - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { f0ykxvjp2e += do1u0posi5 [ i * 3 +
i_p ] ; } esrvq4wxba [ i_p ] = f0ykxvjp2e ; } cuyoqaviu3_idx_0 = ( real32_T )
esrvq4wxba [ 0 ] ; cuyoqaviu3_idx_1 = ( real32_T ) esrvq4wxba [ 1 ] ;
cuyoqaviu3_idx_2 = ( real32_T ) esrvq4wxba [ 2 ] ; for ( i_p = 0 ; i_p < 7 ;
i_p ++ ) { og2mhjvxrf_idx_0 = rtB . crx1qgibvo [ i_p + 7 ] ; kgeeoq3i0q [ 3 *
i_p ] = og2mhjvxrf_idx_0 ; kgeeoq3i0q [ 3 * i_p + 1 ] = og2mhjvxrf_idx_0 ;
kgeeoq3i0q [ 3 * i_p + 2 ] = og2mhjvxrf_idx_0 ; } for ( i_p = 0 ; i_p < 21 ;
i_p ++ ) { og2mhjvxrf_idx_0 = kgeeoq3i0q [ i_p ] ; kgeeoq3i0q [ i_p ] =
og2mhjvxrf_idx_0 * og2mhjvxrf_idx_0 ; } for ( i_p = 0 ; i_p < 5 ; i_p ++ ) {
bpIndex [ i_p ] = plook_u32ff_lincpa ( rtB . jet1i0an5d [ i_p + 7 ] , rtP .
dp_WING_root . alphas , 24U , & jtk2ho12tm [ i_p ] , & rtDW . p0luwllcwa [
i_p ] ) ; } for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { bpIndex_p [ i_p ] =
plook_u32ff_lincpa ( rtB . crx1qgibvo [ i_p + 7 ] , rtP . dp_WING_root . V ,
1U , & p52cvq2maf [ i_p ] , & rtDW . momrqi2s1w [ i_p ] ) ; } for ( i_p = 0 ;
i_p < 5 ; i_p ++ ) { bpIndex_e [ i_p ] = plook_u32ff_lincpa ( kmby3hj4tx [
i_p + 6 ] , rtP . dp_WING_root . DEP_J , 6U , & gzu1zm2zul [ i_p ] , & rtDW .
jevgaddxph [ i_p ] ) ; } frac_j [ 0 ] = rtB . gbccn4rvbj ; bpIndex_j [ 0 ] =
rtB . bqft1jkk0z ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { frac_j [ 1 ] =
jtk2ho12tm [ i_p ] ; frac_j [ 2 ] = p52cvq2maf [ i_p ] ; frac_j [ 3 ] =
gzu1zm2zul [ i_p ] ; bpIndex_j [ 1 ] = bpIndex [ i_p ] ; bpIndex_j [ 2 ] =
bpIndex_p [ i_p ] ; bpIndex_j [ 3 ] = bpIndex_e [ i_p ] ; f0ykxvjp2e = rtP .
Constant8_Value_kwpfdqsyq1 [ i_p ] ; if ( f0ykxvjp2e > 4.0 ) { bpIndex_j [ 4
] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_j [ 4 ] = ( uint32_T )
f0ykxvjp2e ; } else { bpIndex_j [ 4 ] = 0U ; } ktfulnpz4m [ i_p ] =
intrp4d_fu32fla_pw ( bpIndex_j , frac_j , & rtP . dp_WING_root . CD [ 1750U *
bpIndex_j [ 4 ] ] , rtP . InterpolationUsingPrelookup1_dimSize_jgranlzjdr ,
rtP . InterpolationUsingPrelookup1_maxIndex_m1elfxqfrm ) ; } h2f22pqghw_idx_0
= plook_u32ff_lincpa ( rtB . jet1i0an5d [ 12 ] , rtP . dp_WING_tip . alphas ,
24U , & pjs3tdc01w [ 0 ] , & rtDW . dctbywbcef [ 0 ] ) ; h2f22pqghw_idx_1 =
plook_u32ff_lincpa ( rtB . jet1i0an5d [ 13 ] , rtP . dp_WING_tip . alphas ,
24U , & pjs3tdc01w [ 1 ] , & rtDW . dctbywbcef [ 1 ] ) ; pykbfcgxvc_idx_0 =
plook_u32ff_lincpa ( rtB . crx1qgibvo [ 12 ] , rtP . dp_WING_tip . V , 1U , &
pgkyyjejl3 [ 0 ] , & rtDW . iiazkmp3zq [ 0 ] ) ; pykbfcgxvc_idx_1 =
plook_u32ff_lincpa ( rtB . crx1qgibvo [ 13 ] , rtP . dp_WING_tip . V , 1U , &
pgkyyjejl3 [ 1 ] , & rtDW . iiazkmp3zq [ 1 ] ) ; mwzdolw5gj_idx_0 =
plook_u32ff_lincpa ( kmby3hj4tx [ 10 ] , rtP . dp_WING_tip . DEP_J , 6U , &
orrknllzxd [ 0 ] , & rtDW . pb5bsdxxpa [ 0 ] ) ; mwzdolw5gj_idx_1 =
plook_u32ff_lincpa ( kmby3hj4tx [ 11 ] , rtP . dp_WING_tip . DEP_J , 6U , &
orrknllzxd [ 1 ] , & rtDW . pb5bsdxxpa [ 1 ] ) ; frac_f [ 0 ] = rtB .
igwg4uissg ; bpIndex_f [ 0 ] = rtB . fu5nkfrvvl ; frac_f [ 1 ] = pjs3tdc01w [
0 ] ; frac_f [ 2 ] = pgkyyjejl3 [ 0 ] ; frac_f [ 3 ] = orrknllzxd [ 0 ] ;
bpIndex_f [ 1 ] = h2f22pqghw_idx_0 ; bpIndex_f [ 2 ] = pykbfcgxvc_idx_0 ;
bpIndex_f [ 3 ] = mwzdolw5gj_idx_0 ; if ( rtP . Constant8_Value_m3ahup3xji [
0 ] > 1.0 ) { bpIndex_f [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_m3ahup3xji [ 0 ] >= 0.0 ) { bpIndex_f [ 4 ] = ( uint32_T )
rtP . Constant8_Value_m3ahup3xji [ 0 ] ; } else { bpIndex_f [ 4 ] = 0U ; }
ktfulnpz4m [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_f , frac_f , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_f [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_hgrobm0ojs , rtP .
InterpolationUsingPrelookup1_maxIndex_kj53253sjw ) ; frac_f [ 1 ] =
pjs3tdc01w [ 1 ] ; frac_f [ 2 ] = pgkyyjejl3 [ 1 ] ; frac_f [ 3 ] =
orrknllzxd [ 1 ] ; bpIndex_f [ 1 ] = h2f22pqghw_idx_1 ; bpIndex_f [ 2 ] =
pykbfcgxvc_idx_1 ; bpIndex_f [ 3 ] = mwzdolw5gj_idx_1 ; if ( rtP .
Constant8_Value_m3ahup3xji [ 1 ] > 1.0 ) { bpIndex_f [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_m3ahup3xji [ 1 ] >= 0.0 ) { bpIndex_f [ 4 ] = (
uint32_T ) rtP . Constant8_Value_m3ahup3xji [ 1 ] ; } else { bpIndex_f [ 4 ]
= 0U ; } ktfulnpz4m [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_f , frac_f , & rtP .
dp_WING_tip . CD [ 2450U * bpIndex_f [ 4 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_hgrobm0ojs , rtP .
InterpolationUsingPrelookup1_maxIndex_kj53253sjw ) ; frac_c [ 0 ] = rtB .
gbccn4rvbj ; bpIndex_c [ 0 ] = rtB . bqft1jkk0z ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_c [ 1 ] = jtk2ho12tm [ i_p ] ; frac_c [ 2 ] = p52cvq2maf [
i_p ] ; frac_c [ 3 ] = gzu1zm2zul [ i_p ] ; bpIndex_c [ 1 ] = bpIndex [ i_p ]
; bpIndex_c [ 2 ] = bpIndex_p [ i_p ] ; bpIndex_c [ 3 ] = bpIndex_e [ i_p ] ;
f0ykxvjp2e = rtP . Constant8_Value_kwpfdqsyq1 [ i_p ] ; if ( f0ykxvjp2e > 4.0
) { bpIndex_c [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_c [ 4 ]
= ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_c [ 4 ] = 0U ; } ktfulnpz4m [
i_p + 7 ] = intrp4d_fu32fla_pw ( bpIndex_c , frac_c , & rtP . dp_WING_root .
CS [ 1750U * bpIndex_c [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_e5mnlcnsgz , rtP .
InterpolationUsingPrelookup2_maxIndex_ic1jmobgnb ) ; } frac_k [ 0 ] = rtB .
igwg4uissg ; bpIndex_k [ 0 ] = rtB . fu5nkfrvvl ; frac_k [ 1 ] = pjs3tdc01w [
0 ] ; frac_k [ 2 ] = pgkyyjejl3 [ 0 ] ; frac_k [ 3 ] = orrknllzxd [ 0 ] ;
bpIndex_k [ 1 ] = h2f22pqghw_idx_0 ; bpIndex_k [ 2 ] = pykbfcgxvc_idx_0 ;
bpIndex_k [ 3 ] = mwzdolw5gj_idx_0 ; if ( rtP . Constant8_Value_m3ahup3xji [
0 ] > 1.0 ) { bpIndex_k [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_m3ahup3xji [ 0 ] >= 0.0 ) { bpIndex_k [ 4 ] = ( uint32_T )
rtP . Constant8_Value_m3ahup3xji [ 0 ] ; } else { bpIndex_k [ 4 ] = 0U ; }
ktfulnpz4m [ 12 ] = intrp4d_fu32fla_pw ( bpIndex_k , frac_k , & rtP .
dp_WING_tip . CS [ 2450U * bpIndex_k [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_fv3gcuk1rh , rtP .
InterpolationUsingPrelookup2_maxIndex_joswbgit4t ) ; frac_k [ 1 ] =
pjs3tdc01w [ 1 ] ; frac_k [ 2 ] = pgkyyjejl3 [ 1 ] ; frac_k [ 3 ] =
orrknllzxd [ 1 ] ; bpIndex_k [ 1 ] = h2f22pqghw_idx_1 ; bpIndex_k [ 2 ] =
pykbfcgxvc_idx_1 ; bpIndex_k [ 3 ] = mwzdolw5gj_idx_1 ; if ( rtP .
Constant8_Value_m3ahup3xji [ 1 ] > 1.0 ) { bpIndex_k [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_m3ahup3xji [ 1 ] >= 0.0 ) { bpIndex_k [ 4 ] = (
uint32_T ) rtP . Constant8_Value_m3ahup3xji [ 1 ] ; } else { bpIndex_k [ 4 ]
= 0U ; } ktfulnpz4m [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_k , frac_k , & rtP
. dp_WING_tip . CS [ 2450U * bpIndex_k [ 4 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_fv3gcuk1rh , rtP .
InterpolationUsingPrelookup2_maxIndex_joswbgit4t ) ; frac_b [ 0 ] = rtB .
gbccn4rvbj ; bpIndex_b [ 0 ] = rtB . bqft1jkk0z ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_b [ 1 ] = jtk2ho12tm [ i_p ] ; frac_b [ 2 ] = p52cvq2maf [
i_p ] ; frac_b [ 3 ] = gzu1zm2zul [ i_p ] ; bpIndex_b [ 1 ] = bpIndex [ i_p ]
; bpIndex_b [ 2 ] = bpIndex_p [ i_p ] ; bpIndex_b [ 3 ] = bpIndex_e [ i_p ] ;
f0ykxvjp2e = rtP . Constant8_Value_kwpfdqsyq1 [ i_p ] ; if ( f0ykxvjp2e > 4.0
) { bpIndex_b [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_b [ 4 ]
= ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_b [ 4 ] = 0U ; } ktfulnpz4m [
i_p + 14 ] = intrp4d_fu32fla_pw ( bpIndex_b , frac_b , & rtP . dp_WING_root .
CL [ 1750U * bpIndex_b [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_gotbz31jut , rtP .
InterpolationUsingPrelookup3_maxIndex_iyvebvf0hr ) ; } frac_n [ 0 ] = rtB .
igwg4uissg ; bpIndex_n [ 0 ] = rtB . fu5nkfrvvl ; frac_n [ 1 ] = pjs3tdc01w [
0 ] ; frac_n [ 2 ] = pgkyyjejl3 [ 0 ] ; frac_n [ 3 ] = orrknllzxd [ 0 ] ;
bpIndex_n [ 1 ] = h2f22pqghw_idx_0 ; bpIndex_n [ 2 ] = pykbfcgxvc_idx_0 ;
bpIndex_n [ 3 ] = mwzdolw5gj_idx_0 ; if ( rtP . Constant8_Value_m3ahup3xji [
0 ] > 1.0 ) { bpIndex_n [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_m3ahup3xji [ 0 ] >= 0.0 ) { bpIndex_n [ 4 ] = ( uint32_T )
rtP . Constant8_Value_m3ahup3xji [ 0 ] ; } else { bpIndex_n [ 4 ] = 0U ; }
ktfulnpz4m [ 19 ] = intrp4d_fu32fla_pw ( bpIndex_n , frac_n , & rtP .
dp_WING_tip . CL [ 2450U * bpIndex_n [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_i1e0soyo1i , rtP .
InterpolationUsingPrelookup3_maxIndex_axhtziqjmb ) ; frac_n [ 1 ] =
pjs3tdc01w [ 1 ] ; frac_n [ 2 ] = pgkyyjejl3 [ 1 ] ; frac_n [ 3 ] =
orrknllzxd [ 1 ] ; bpIndex_n [ 1 ] = h2f22pqghw_idx_1 ; bpIndex_n [ 2 ] =
pykbfcgxvc_idx_1 ; bpIndex_n [ 3 ] = mwzdolw5gj_idx_1 ; if ( rtP .
Constant8_Value_m3ahup3xji [ 1 ] > 1.0 ) { bpIndex_n [ 4 ] = 1U ; } else if (
rtP . Constant8_Value_m3ahup3xji [ 1 ] >= 0.0 ) { bpIndex_n [ 4 ] = (
uint32_T ) rtP . Constant8_Value_m3ahup3xji [ 1 ] ; } else { bpIndex_n [ 4 ]
= 0U ; } ktfulnpz4m [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_n , frac_n , & rtP
. dp_WING_tip . CL [ 2450U * bpIndex_n [ 4 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_i1e0soyo1i , rtP .
InterpolationUsingPrelookup3_maxIndex_axhtziqjmb ) ; for ( i_p = 0 ; i_p < 7
; i_p ++ ) { rtB . fpov3sjl4o [ 3 * i_p ] = kgeeoq3i0q [ 3 * i_p ] *
ktfulnpz4m [ i_p ] * rtB . ecjaklyjaq * rtP . Gain_Gain_mvu5sy12vu ; rtB .
fpov3sjl4o [ 3 * i_p + 1 ] = kgeeoq3i0q [ 3 * i_p + 1 ] * ktfulnpz4m [ i_p +
7 ] * rtB . ecjaklyjaq * rtP . Gain_Gain_mvu5sy12vu ; rtB . fpov3sjl4o [ 3 *
i_p + 2 ] = kgeeoq3i0q [ 3 * i_p + 2 ] * ktfulnpz4m [ i_p + 14 ] * rtB .
ecjaklyjaq * rtP . Gain_Gain_mvu5sy12vu ; } parallel_for ( 7 , c0cmetu4kl , 1
, "c0cmetu4kl" ) ; for ( i_p = 0 ; i_p < 21 ; i_p ++ ) { do1u0posi5 [ i_p ] =
rtB . bavqi0oauu [ i_p ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { f0ykxvjp2e
= - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { f0ykxvjp2e += do1u0posi5 [ i * 3 +
i_p ] ; } esrvq4wxba [ i_p ] = f0ykxvjp2e ; } og2mhjvxrf_idx_0 = ( real32_T )
esrvq4wxba [ 0 ] ; og2mhjvxrf_idx_1 = ( real32_T ) esrvq4wxba [ 1 ] ;
og2mhjvxrf_idx_2 = ( real32_T ) esrvq4wxba [ 2 ] ; for ( i_p = 0 ; i_p < 16 ;
i_p ++ ) { ep5pua1w1i [ i_p ] = look1_iflf_pbinlcpw ( rtP . Constant7_Value [
i_p ] , rtP . uDLookupTable_bp01Data , & rtB . jet1i0an5d [ 4 ] , & rtDW .
p4va2j4maz [ i_p ] , 5U ) ; } for ( i_p = 0 ; i_p < 16 ; i_p ++ ) {
h3nw55tjpp [ i_p ] = plook_u32ff_linxp ( ep5pua1w1i [ i_p ] , rtP .
dp_VTAIL_INDUCED . alphas , 24U , & gs5wgqurd1 [ i_p ] , & rtDW . ldxzligihn
[ i_p ] ) ; } for ( i_p = 0 ; i_p < 16 ; i_p ++ ) { ep5pua1w1i [ i_p ] =
look1_iflf_pbinlcpw ( rtP . Constant7_Value [ i_p ] , rtP .
uDLookupTable1_bp01Data_o3lj0rj2gn , & rtB . crx1qgibvo [ 4 ] , & rtDW .
fb00myaqvg [ i_p ] , 5U ) ; } for ( i_p = 0 ; i_p < 16 ; i_p ++ ) {
hg0sesl5ey [ i_p ] = plook_u32ff_linxp ( ep5pua1w1i [ i_p ] , rtP .
dp_VTAIL_INDUCED . V_infs , 1U , & dpbd4xswtf [ i_p ] , & rtDW . hkblkqalfc [
i_p ] ) ; } for ( i_p = 0 ; i_p < 16 ; i_p ++ ) { ep5pua1w1i [ i_p ] =
look1_iflf_pbinlcpw ( rtP . Constant7_Value [ i_p ] , rtP .
uDLookupTable2_bp01Data , & kmby3hj4tx [ 3 ] , & rtDW . eewvdaqf4r [ i_p ] ,
5U ) ; } for ( i_p = 0 ; i_p < 16 ; i_p ++ ) { p4lqtpxnj2 [ i_p ] =
plook_u32ff_lincp ( ep5pua1w1i [ i_p ] , rtP . dp_VTAIL_INDUCED . DEP_J , 6U
, & njokkaqa44 [ i_p ] , & rtDW . dgwkzgwl00 [ i_p ] ) ; } for ( i_p = 0 ;
i_p < 16 ; i_p ++ ) { frac_l [ 0 ] = rtB . kunmel5bx4 [ i_p ] ; frac_l [ 1 ]
= gs5wgqurd1 [ i_p ] ; frac_l [ 2 ] = dpbd4xswtf [ i_p ] ; frac_l [ 3 ] =
njokkaqa44 [ i_p ] ; bpIndex_l [ 0 ] = rtB . nhcvscc4t0 [ i_p ] ; bpIndex_l [
1 ] = h3nw55tjpp [ i_p ] ; bpIndex_l [ 2 ] = hg0sesl5ey [ i_p ] ; bpIndex_l [
3 ] = p4lqtpxnj2 [ i_p ] ; f0ykxvjp2e = rtP . Constant8_Value [ i_p ] ; if (
f0ykxvjp2e > 15.0 ) { bpIndex_l [ 4 ] = 15U ; } else if ( f0ykxvjp2e >= 0.0 )
{ bpIndex_l [ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_l [ 4 ] = 0U ;
} ep5pua1w1i [ i_p ] = intrp4d_fl_pw ( bpIndex_l , frac_l , & rtP .
dp_VTAIL_INDUCED . V_induced [ 1750U * bpIndex_l [ 4 ] ] , rtP .
V_induced_dimSize ) ; } parallel_for ( 16 , jgo5lugg00 , 1 , "jgo5lugg00" ) ;
for ( i_p = 0 ; i_p < 16 ; i_p ++ ) { noivdi5wij = ep5pua1w1i [ i_p ] + rtB .
crx1qgibvon [ i_p ] ; ep5pua1w1i [ i_p ] = noivdi5wij ; m5u5mthwev [ 3 * i_p
] = noivdi5wij ; m5u5mthwev [ 3 * i_p + 1 ] = noivdi5wij ; m5u5mthwev [ 3 *
i_p + 2 ] = noivdi5wij ; } for ( i_p = 0 ; i_p < 48 ; i_p ++ ) { e5eea4yz11 =
m5u5mthwev [ i_p ] ; m5u5mthwev [ i_p ] = e5eea4yz11 * e5eea4yz11 ; } for (
i_p = 0 ; i_p < 16 ; i_p ++ ) { frac_d [ 0 ] = rtB . kunmel5bx4 [ i_p ] ;
frac_d [ 1 ] = gs5wgqurd1 [ i_p ] ; frac_d [ 2 ] = dpbd4xswtf [ i_p ] ;
frac_d [ 3 ] = njokkaqa44 [ i_p ] ; bpIndex_d [ 0 ] = rtB . nhcvscc4t0 [ i_p
] ; bpIndex_d [ 1 ] = h3nw55tjpp [ i_p ] ; bpIndex_d [ 2 ] = hg0sesl5ey [ i_p
] ; bpIndex_d [ 3 ] = p4lqtpxnj2 [ i_p ] ; f0ykxvjp2e = rtP . Constant8_Value
[ i_p ] ; if ( f0ykxvjp2e > 15.0 ) { bpIndex_d [ 4 ] = 15U ; } else if (
f0ykxvjp2e >= 0.0 ) { bpIndex_d [ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else {
bpIndex_d [ 4 ] = 0U ; } noivdi5wij = intrp4d_fl_pw ( bpIndex_d , frac_d , &
rtP . dp_VTAIL_INDUCED . alpha_induced [ 1750U * bpIndex_d [ 4 ] ] , rtP .
alpha_induced_dimSize ) ; ep5pua1w1i [ i_p ] = noivdi5wij ; njokkaqa44 [ i_p
] = noivdi5wij + rtB . jet1i0an5do [ i_p ] ; } for ( i_p = 0 ; i_p < 16 ; i_p
++ ) { p4lqtpxnj2 [ i_p ] = plook_u32ff_linxp ( njokkaqa44 [ i_p ] , rtP .
dp_VTAIL . alphas , 12U , & ep5pua1w1i [ i_p ] , & rtDW . lsgiesztth [ i_p ]
) ; } for ( i_p = 0 ; i_p < 16 ; i_p ++ ) { hg0sesl5ey [ i_p ] =
plook_u32ff_linxp ( rtB . dzpd4knetl [ i_p ] , rtP . dp_VTAIL . betas , 8U ,
& njokkaqa44 [ i_p ] , & rtDW . m05sv2n1iq [ i_p ] ) ; } for ( i_p = 0 ; i_p
< 16 ; i_p ++ ) { f0ykxvjp2e = rtB . mgyjrcfqfu [ i_p ] ; frac_o [ 0 ] =
f0ykxvjp2e ; noivdi5wij = ep5pua1w1i [ i_p ] ; frac_o [ 1 ] = noivdi5wij ;
nntliqh2c3 = njokkaqa44 [ i_p ] ; frac_o [ 2 ] = nntliqh2c3 ; pmh50qaazg =
rtB . pmh50qaazg [ i_p ] ; bpIndex_o [ 0 ] = pmh50qaazg ; d2tzmda3nu =
p4lqtpxnj2 [ i_p ] ; bpIndex_o [ 1 ] = d2tzmda3nu ; glo3iuekqm = hg0sesl5ey [
i_p ] ; bpIndex_o [ 2 ] = glo3iuekqm ; Constant8_Value_cr0us2qlbv = rtP .
Constant8_Value_cr0us2qlbv [ i_p ] ; if ( Constant8_Value_cr0us2qlbv > 15.0 )
{ bpIndex_o [ 3 ] = 15U ; } else if ( Constant8_Value_cr0us2qlbv >= 0.0 ) {
bpIndex_o [ 3 ] = ( uint32_T ) Constant8_Value_cr0us2qlbv ; } else {
bpIndex_o [ 3 ] = 0U ; } e5eea4yz11 = intrp3d_fl_pw ( bpIndex_o , frac_o , &
rtP . dp_VTAIL . CFx [ 1170U * bpIndex_o [ 3 ] ] , rtP .
InterpolationUsingPrelookup1_dimSize_kbujhpqt4p ) ; frac_dz [ 0 ] =
f0ykxvjp2e ; frac_dz [ 1 ] = noivdi5wij ; frac_dz [ 2 ] = nntliqh2c3 ;
bpIndex_dz [ 0 ] = pmh50qaazg ; bpIndex_dz [ 1 ] = d2tzmda3nu ; bpIndex_dz [
2 ] = glo3iuekqm ; if ( Constant8_Value_cr0us2qlbv > 15.0 ) { bpIndex_dz [ 3
] = 15U ; } else if ( Constant8_Value_cr0us2qlbv >= 0.0 ) { bpIndex_dz [ 3 ]
= ( uint32_T ) Constant8_Value_cr0us2qlbv ; } else { bpIndex_dz [ 3 ] = 0U ;
} bzcsjahvxl_p = intrp3d_fl_pw ( bpIndex_dz , frac_dz , & rtP . dp_VTAIL .
CFy [ 1170U * bpIndex_dz [ 3 ] ] , rtP .
InterpolationUsingPrelookup2_dimSize_it0njeibeo ) ; frac_fs [ 0 ] =
f0ykxvjp2e ; frac_fs [ 1 ] = noivdi5wij ; frac_fs [ 2 ] = nntliqh2c3 ;
bpIndex_fs [ 0 ] = pmh50qaazg ; bpIndex_fs [ 1 ] = d2tzmda3nu ; bpIndex_fs [
2 ] = glo3iuekqm ; if ( Constant8_Value_cr0us2qlbv > 15.0 ) { bpIndex_fs [ 3
] = 15U ; } else if ( Constant8_Value_cr0us2qlbv >= 0.0 ) { bpIndex_fs [ 3 ]
= ( uint32_T ) Constant8_Value_cr0us2qlbv ; } else { bpIndex_fs [ 3 ] = 0U ;
} noivdi5wij = intrp3d_fl_pw ( bpIndex_fs , frac_fs , & rtP . dp_VTAIL . CFz
[ 1170U * bpIndex_fs [ 3 ] ] , rtP .
InterpolationUsingPrelookup3_dimSize_h5lelt5fk5 ) ; rtB . bdrmalqcon [ 3 *
i_p ] = m5u5mthwev [ 3 * i_p ] * e5eea4yz11 * rtB . ecjaklyjaq * rtP .
Gain2_Gain_a2ertcz4ne ; rtB . bdrmalqcon [ 3 * i_p + 1 ] = m5u5mthwev [ 3 *
i_p + 1 ] * bzcsjahvxl_p * rtB . ecjaklyjaq * rtP . Gain2_Gain_a2ertcz4ne ;
rtB . bdrmalqcon [ 3 * i_p + 2 ] = m5u5mthwev [ 3 * i_p + 2 ] * noivdi5wij *
rtB . ecjaklyjaq * rtP . Gain2_Gain_a2ertcz4ne ; } for ( i_p = 0 ; i_p < 48 ;
i_p ++ ) { gvxohgx2qx [ i_p ] = rtB . bdrmalqcon [ i_p ] ; } for ( i_p = 0 ;
i_p < 3 ; i_p ++ ) { f0ykxvjp2e = - 0.0 ; for ( i = 0 ; i < 16 ; i ++ ) {
f0ykxvjp2e += gvxohgx2qx [ i * 3 + i_p ] ; } esrvq4wxba [ i_p ] = f0ykxvjp2e
; } rtB . jdsvzdisey [ 0 ] = ( ( ( cuyoqaviu3_idx_0 + og2mhjvxrf_idx_0 ) + (
real32_T ) esrvq4wxba [ 0 ] ) + rtB . f5f1ypai11 [ 0 ] ) + rtB . ejdl4n31el [
0 ] ; rtB . jdsvzdisey [ 1 ] = ( ( ( - cuyoqaviu3_idx_1 + og2mhjvxrf_idx_1 )
+ ( real32_T ) esrvq4wxba [ 1 ] ) + rtB . f5f1ypai11 [ 1 ] ) + rtB .
ejdl4n31el [ 1 ] ; rtB . jdsvzdisey [ 2 ] = ( ( ( cuyoqaviu3_idx_2 +
og2mhjvxrf_idx_2 ) + ( real32_T ) esrvq4wxba [ 2 ] ) + rtB . f5f1ypai11 [ 2 ]
) + rtB . ejdl4n31el [ 2 ] ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { esrvq4wxba
[ i_p ] = rtB . jdsvzdisey [ i_p ] ; f0ykxvjp2e = - 0.0 ; for ( i = 0 ; i <
12 ; i ++ ) { f0ykxvjp2e += rtB . fqp13muoyo [ i * 3 + i_p ] ; } frac_fs [
i_p ] = f0ykxvjp2e ; } frac_dz [ 0 ] = ( ( frac_fs [ 0 ] + rtB . omkpqlajlz [
0 ] ) + rtB . gfknqoynom ) + esrvq4wxba [ 0 ] ; frac_dz [ 1 ] = ( ( frac_fs [
1 ] + rtB . omkpqlajlz [ 1 ] ) + rtP . Constant_Value_dtyrktojcw ) +
esrvq4wxba [ 1 ] ; frac_dz [ 2 ] = ( ( frac_fs [ 2 ] + rtB . omkpqlajlz [ 2 ]
) + rtP . Constant_Value_dtyrktojcw ) + esrvq4wxba [ 2 ] ; parallel_for ( 7 ,
d2dy1jnwgp , 1 , "d2dy1jnwgp" ) ; frac_ck [ 0 ] = rtB . ayw0otszrq ;
bpIndex_ck [ 0 ] = rtB . g53iqbai0i ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) {
frac_ck [ 1 ] = fcnqqv3bsy [ i_p ] ; frac_ck [ 2 ] = pwsv0izi4l [ i_p ] ;
frac_ck [ 3 ] = m25svtzs1a [ i_p ] ; bpIndex_ck [ 1 ] = glk5ydjkx2 [ i_p ] ;
bpIndex_ck [ 2 ] = ii2emm2n0y [ i_p ] ; bpIndex_ck [ 3 ] = i21j1alng4 [ i_p ]
; f0ykxvjp2e = rtP . Constant8_Value_dj5ncyqbcf [ i_p ] ; if ( f0ykxvjp2e >
4.0 ) { bpIndex_ck [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_ck
[ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_ck [ 4 ] = 0U ; }
ktfulnpz4m [ i_p ] = intrp4d_fu32fla_pw ( bpIndex_ck , frac_ck , & rtP .
dp_WING_root . CMx [ 1750U * bpIndex_ck [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize , rtP .
InterpolationUsingPrelookup4_maxIndex ) ; } frac_f2 [ 0 ] = rtB . lkci5wisjr
; bpIndex_f2 [ 0 ] = rtB . jqfgyi5cqv ; frac_f2 [ 1 ] = hvtxsdprmj [ 0 ] ;
frac_f2 [ 2 ] = hszv10yckq [ 0 ] ; frac_f2 [ 3 ] = d1dhbqr5yc [ 0 ] ;
bpIndex_f2 [ 1 ] = e20nx452ly_idx_0 ; bpIndex_f2 [ 2 ] = oogct0iaeu_idx_0 ;
bpIndex_f2 [ 3 ] = ok0ziasf2d_idx_0 ; if ( rtP . Constant8_Value_hy4ct0z05y [
0 ] > 1.0 ) { bpIndex_f2 [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_hy4ct0z05y [ 0 ] >= 0.0 ) { bpIndex_f2 [ 4 ] = ( uint32_T )
rtP . Constant8_Value_hy4ct0z05y [ 0 ] ; } else { bpIndex_f2 [ 4 ] = 0U ; }
ktfulnpz4m [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_f2 , frac_f2 , & rtP .
dp_WING_tip . CMx [ 2450U * bpIndex_f2 [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_eonzf4khoz , rtP .
InterpolationUsingPrelookup4_maxIndex_ldg1ql3t42 ) ; frac_f2 [ 1 ] =
hvtxsdprmj [ 1 ] ; frac_f2 [ 2 ] = hszv10yckq [ 1 ] ; frac_f2 [ 3 ] =
d1dhbqr5yc [ 1 ] ; bpIndex_f2 [ 1 ] = e20nx452ly_idx_1 ; bpIndex_f2 [ 2 ] =
oogct0iaeu_idx_1 ; bpIndex_f2 [ 3 ] = ok0ziasf2d_idx_1 ; if ( rtP .
Constant8_Value_hy4ct0z05y [ 1 ] > 1.0 ) { bpIndex_f2 [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_hy4ct0z05y [ 1 ] >= 0.0 ) { bpIndex_f2 [ 4 ] = (
uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 1 ] ; } else { bpIndex_f2 [ 4 ]
= 0U ; } ktfulnpz4m [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_f2 , frac_f2 , & rtP
. dp_WING_tip . CMx [ 2450U * bpIndex_f2 [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_eonzf4khoz , rtP .
InterpolationUsingPrelookup4_maxIndex_ldg1ql3t42 ) ; frac_kt [ 0 ] = rtB .
ayw0otszrq ; bpIndex_kt [ 0 ] = rtB . g53iqbai0i ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_kt [ 1 ] = fcnqqv3bsy [ i_p ] ; frac_kt [ 2 ] = pwsv0izi4l [
i_p ] ; frac_kt [ 3 ] = m25svtzs1a [ i_p ] ; bpIndex_kt [ 1 ] = glk5ydjkx2 [
i_p ] ; bpIndex_kt [ 2 ] = ii2emm2n0y [ i_p ] ; bpIndex_kt [ 3 ] = i21j1alng4
[ i_p ] ; f0ykxvjp2e = rtP . Constant8_Value_dj5ncyqbcf [ i_p ] ; if (
f0ykxvjp2e > 4.0 ) { bpIndex_kt [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 )
{ bpIndex_kt [ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_kt [ 4 ] = 0U
; } ktfulnpz4m [ i_p + 7 ] = intrp4d_fu32fla_pw ( bpIndex_kt , frac_kt , &
rtP . dp_WING_root . CMy [ 1750U * bpIndex_kt [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize , rtP .
InterpolationUsingPrelookup5_maxIndex ) ; } frac_lt [ 0 ] = rtB . lkci5wisjr
; bpIndex_lt [ 0 ] = rtB . jqfgyi5cqv ; frac_lt [ 1 ] = hvtxsdprmj [ 0 ] ;
frac_lt [ 2 ] = hszv10yckq [ 0 ] ; frac_lt [ 3 ] = d1dhbqr5yc [ 0 ] ;
bpIndex_lt [ 1 ] = e20nx452ly_idx_0 ; bpIndex_lt [ 2 ] = oogct0iaeu_idx_0 ;
bpIndex_lt [ 3 ] = ok0ziasf2d_idx_0 ; if ( rtP . Constant8_Value_hy4ct0z05y [
0 ] > 1.0 ) { bpIndex_lt [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_hy4ct0z05y [ 0 ] >= 0.0 ) { bpIndex_lt [ 4 ] = ( uint32_T )
rtP . Constant8_Value_hy4ct0z05y [ 0 ] ; } else { bpIndex_lt [ 4 ] = 0U ; }
ktfulnpz4m [ 12 ] = intrp4d_fu32fla_pw ( bpIndex_lt , frac_lt , & rtP .
dp_WING_tip . CMy [ 2450U * bpIndex_lt [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_m1b3rqhw3t , rtP .
InterpolationUsingPrelookup5_maxIndex_l0p20lh4bw ) ; frac_lt [ 1 ] =
hvtxsdprmj [ 1 ] ; frac_lt [ 2 ] = hszv10yckq [ 1 ] ; frac_lt [ 3 ] =
d1dhbqr5yc [ 1 ] ; bpIndex_lt [ 1 ] = e20nx452ly_idx_1 ; bpIndex_lt [ 2 ] =
oogct0iaeu_idx_1 ; bpIndex_lt [ 3 ] = ok0ziasf2d_idx_1 ; if ( rtP .
Constant8_Value_hy4ct0z05y [ 1 ] > 1.0 ) { bpIndex_lt [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_hy4ct0z05y [ 1 ] >= 0.0 ) { bpIndex_lt [ 4 ] = (
uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 1 ] ; } else { bpIndex_lt [ 4 ]
= 0U ; } ktfulnpz4m [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_lt , frac_lt , &
rtP . dp_WING_tip . CMy [ 2450U * bpIndex_lt [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_m1b3rqhw3t , rtP .
InterpolationUsingPrelookup5_maxIndex_l0p20lh4bw ) ; frac_hn [ 0 ] = rtB .
ayw0otszrq ; bpIndex_hn [ 0 ] = rtB . g53iqbai0i ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_hn [ 1 ] = fcnqqv3bsy [ i_p ] ; frac_hn [ 2 ] = pwsv0izi4l [
i_p ] ; frac_hn [ 3 ] = m25svtzs1a [ i_p ] ; bpIndex_hn [ 1 ] = glk5ydjkx2 [
i_p ] ; bpIndex_hn [ 2 ] = ii2emm2n0y [ i_p ] ; bpIndex_hn [ 3 ] = i21j1alng4
[ i_p ] ; f0ykxvjp2e = rtP . Constant8_Value_dj5ncyqbcf [ i_p ] ; if (
f0ykxvjp2e > 4.0 ) { bpIndex_hn [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 )
{ bpIndex_hn [ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_hn [ 4 ] = 0U
; } ktfulnpz4m [ i_p + 14 ] = intrp4d_fu32fla_pw ( bpIndex_hn , frac_hn , &
rtP . dp_WING_root . CMz [ 1750U * bpIndex_hn [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize , rtP .
InterpolationUsingPrelookup6_maxIndex ) ; } frac_ap [ 0 ] = rtB . lkci5wisjr
; bpIndex_ap [ 0 ] = rtB . jqfgyi5cqv ; frac_ap [ 1 ] = hvtxsdprmj [ 0 ] ;
frac_ap [ 2 ] = hszv10yckq [ 0 ] ; frac_ap [ 3 ] = d1dhbqr5yc [ 0 ] ;
bpIndex_ap [ 1 ] = e20nx452ly_idx_0 ; bpIndex_ap [ 2 ] = oogct0iaeu_idx_0 ;
bpIndex_ap [ 3 ] = ok0ziasf2d_idx_0 ; if ( rtP . Constant8_Value_hy4ct0z05y [
0 ] > 1.0 ) { bpIndex_ap [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_hy4ct0z05y [ 0 ] >= 0.0 ) { bpIndex_ap [ 4 ] = ( uint32_T )
rtP . Constant8_Value_hy4ct0z05y [ 0 ] ; } else { bpIndex_ap [ 4 ] = 0U ; }
ktfulnpz4m [ 19 ] = intrp4d_fu32fla_pw ( bpIndex_ap , frac_ap , & rtP .
dp_WING_tip . CMz [ 2450U * bpIndex_ap [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_ewytp2yzsl , rtP .
InterpolationUsingPrelookup6_maxIndex_fa5a0eaqeu ) ; frac_ap [ 1 ] =
hvtxsdprmj [ 1 ] ; frac_ap [ 2 ] = hszv10yckq [ 1 ] ; frac_ap [ 3 ] =
d1dhbqr5yc [ 1 ] ; bpIndex_ap [ 1 ] = e20nx452ly_idx_1 ; bpIndex_ap [ 2 ] =
oogct0iaeu_idx_1 ; bpIndex_ap [ 3 ] = ok0ziasf2d_idx_1 ; if ( rtP .
Constant8_Value_hy4ct0z05y [ 1 ] > 1.0 ) { bpIndex_ap [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_hy4ct0z05y [ 1 ] >= 0.0 ) { bpIndex_ap [ 4 ] = (
uint32_T ) rtP . Constant8_Value_hy4ct0z05y [ 1 ] ; } else { bpIndex_ap [ 4 ]
= 0U ; } ktfulnpz4m [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_ap , frac_ap , &
rtP . dp_WING_tip . CMz [ 2450U * bpIndex_ap [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_ewytp2yzsl , rtP .
InterpolationUsingPrelookup6_maxIndex_fa5a0eaqeu ) ; f0ykxvjp2e = rtP . S /
2.0 ; for ( i_p = 0 ; i_p < 7 ; i_p ++ ) { do1u0posi5 [ 3 * i_p ] =
ec1iub14lo [ 3 * i_p ] * ktfulnpz4m [ i_p ] * rtP . Constant_Value_lkalxliguo
[ 3 * i_p ] * rtB . ecjaklyjaq * f0ykxvjp2e + rtB . kainbdj3jzn [ 3 * i_p ] ;
do1u0posi5 [ 3 * i_p + 1 ] = ec1iub14lo [ 3 * i_p + 1 ] * ktfulnpz4m [ i_p +
7 ] * rtP . Constant_Value_lkalxliguo [ 3 * i_p + 1 ] * rtB . ecjaklyjaq *
f0ykxvjp2e + rtB . kainbdj3jzn [ 3 * i_p + 1 ] ; do1u0posi5 [ 3 * i_p + 2 ] =
ec1iub14lo [ 3 * i_p + 2 ] * ktfulnpz4m [ i_p + 14 ] * rtP .
Constant_Value_lkalxliguo [ 3 * i_p + 2 ] * rtB . ecjaklyjaq * f0ykxvjp2e +
rtB . kainbdj3jzn [ 3 * i_p + 2 ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
f0ykxvjp2e = - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { f0ykxvjp2e += do1u0posi5
[ i * 3 + i_p ] ; } frac_o [ i_p ] = f0ykxvjp2e ; } cuyoqaviu3_idx_0 = (
real32_T ) frac_o [ 0 ] ; cuyoqaviu3_idx_1 = ( real32_T ) frac_o [ 1 ] ;
cuyoqaviu3_idx_2 = ( real32_T ) frac_o [ 2 ] ; parallel_for ( 7 , pg42w5emjt
, 1 , "pg42w5emjt" ) ; frac_pj [ 0 ] = rtB . gbccn4rvbj ; bpIndex_pj [ 0 ] =
rtB . bqft1jkk0z ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { frac_pj [ 1 ] =
jtk2ho12tm [ i_p ] ; frac_pj [ 2 ] = p52cvq2maf [ i_p ] ; frac_pj [ 3 ] =
gzu1zm2zul [ i_p ] ; bpIndex_pj [ 1 ] = bpIndex [ i_p ] ; bpIndex_pj [ 2 ] =
bpIndex_p [ i_p ] ; bpIndex_pj [ 3 ] = bpIndex_e [ i_p ] ; f0ykxvjp2e = rtP .
Constant8_Value_kwpfdqsyq1 [ i_p ] ; if ( f0ykxvjp2e > 4.0 ) { bpIndex_pj [ 4
] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_pj [ 4 ] = ( uint32_T )
f0ykxvjp2e ; } else { bpIndex_pj [ 4 ] = 0U ; } ec1iub14lo [ i_p ] =
intrp4d_fu32fla_pw ( bpIndex_pj , frac_pj , & rtP . dp_WING_root . CMx [
1750U * bpIndex_pj [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_frefplnidc , rtP .
InterpolationUsingPrelookup4_maxIndex_onrk5innhu ) ; } frac_po [ 0 ] = rtB .
igwg4uissg ; bpIndex_po [ 0 ] = rtB . fu5nkfrvvl ; frac_po [ 1 ] = pjs3tdc01w
[ 0 ] ; frac_po [ 2 ] = pgkyyjejl3 [ 0 ] ; frac_po [ 3 ] = orrknllzxd [ 0 ] ;
bpIndex_po [ 1 ] = h2f22pqghw_idx_0 ; bpIndex_po [ 2 ] = pykbfcgxvc_idx_0 ;
bpIndex_po [ 3 ] = mwzdolw5gj_idx_0 ; if ( rtP . Constant8_Value_m3ahup3xji [
0 ] > 1.0 ) { bpIndex_po [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_m3ahup3xji [ 0 ] >= 0.0 ) { bpIndex_po [ 4 ] = ( uint32_T )
rtP . Constant8_Value_m3ahup3xji [ 0 ] ; } else { bpIndex_po [ 4 ] = 0U ; }
ec1iub14lo [ 5 ] = intrp4d_fu32fla_pw ( bpIndex_po , frac_po , & rtP .
dp_WING_tip . CMx [ 2450U * bpIndex_po [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_kh3x5zfkli , rtP .
InterpolationUsingPrelookup4_maxIndex_leuk5avc1v ) ; frac_po [ 1 ] =
pjs3tdc01w [ 1 ] ; frac_po [ 2 ] = pgkyyjejl3 [ 1 ] ; frac_po [ 3 ] =
orrknllzxd [ 1 ] ; bpIndex_po [ 1 ] = h2f22pqghw_idx_1 ; bpIndex_po [ 2 ] =
pykbfcgxvc_idx_1 ; bpIndex_po [ 3 ] = mwzdolw5gj_idx_1 ; if ( rtP .
Constant8_Value_m3ahup3xji [ 1 ] > 1.0 ) { bpIndex_po [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_m3ahup3xji [ 1 ] >= 0.0 ) { bpIndex_po [ 4 ] = (
uint32_T ) rtP . Constant8_Value_m3ahup3xji [ 1 ] ; } else { bpIndex_po [ 4 ]
= 0U ; } ec1iub14lo [ 6 ] = intrp4d_fu32fla_pw ( bpIndex_po , frac_po , & rtP
. dp_WING_tip . CMx [ 2450U * bpIndex_po [ 4 ] ] , rtP .
InterpolationUsingPrelookup4_dimSize_kh3x5zfkli , rtP .
InterpolationUsingPrelookup4_maxIndex_leuk5avc1v ) ; frac_pk [ 0 ] = rtB .
gbccn4rvbj ; bpIndex_pk [ 0 ] = rtB . bqft1jkk0z ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_pk [ 1 ] = jtk2ho12tm [ i_p ] ; frac_pk [ 2 ] = p52cvq2maf [
i_p ] ; frac_pk [ 3 ] = gzu1zm2zul [ i_p ] ; bpIndex_pk [ 1 ] = bpIndex [ i_p
] ; bpIndex_pk [ 2 ] = bpIndex_p [ i_p ] ; bpIndex_pk [ 3 ] = bpIndex_e [ i_p
] ; f0ykxvjp2e = rtP . Constant8_Value_kwpfdqsyq1 [ i_p ] ; if ( f0ykxvjp2e >
4.0 ) { bpIndex_pk [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_pk
[ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_pk [ 4 ] = 0U ; }
ec1iub14lo [ i_p + 7 ] = intrp4d_fu32fla_pw ( bpIndex_pk , frac_pk , & rtP .
dp_WING_root . CMy [ 1750U * bpIndex_pk [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_licoblhfnw , rtP .
InterpolationUsingPrelookup5_maxIndex_eshiygopfu ) ; } frac_d0 [ 0 ] = rtB .
igwg4uissg ; bpIndex_d0 [ 0 ] = rtB . fu5nkfrvvl ; frac_d0 [ 1 ] = pjs3tdc01w
[ 0 ] ; frac_d0 [ 2 ] = pgkyyjejl3 [ 0 ] ; frac_d0 [ 3 ] = orrknllzxd [ 0 ] ;
bpIndex_d0 [ 1 ] = h2f22pqghw_idx_0 ; bpIndex_d0 [ 2 ] = pykbfcgxvc_idx_0 ;
bpIndex_d0 [ 3 ] = mwzdolw5gj_idx_0 ; if ( rtP . Constant8_Value_m3ahup3xji [
0 ] > 1.0 ) { bpIndex_d0 [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_m3ahup3xji [ 0 ] >= 0.0 ) { bpIndex_d0 [ 4 ] = ( uint32_T )
rtP . Constant8_Value_m3ahup3xji [ 0 ] ; } else { bpIndex_d0 [ 4 ] = 0U ; }
ec1iub14lo [ 12 ] = intrp4d_fu32fla_pw ( bpIndex_d0 , frac_d0 , & rtP .
dp_WING_tip . CMy [ 2450U * bpIndex_d0 [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_kcrhpwfjfn , rtP .
InterpolationUsingPrelookup5_maxIndex_brkchxcoij ) ; frac_d0 [ 1 ] =
pjs3tdc01w [ 1 ] ; frac_d0 [ 2 ] = pgkyyjejl3 [ 1 ] ; frac_d0 [ 3 ] =
orrknllzxd [ 1 ] ; bpIndex_d0 [ 1 ] = h2f22pqghw_idx_1 ; bpIndex_d0 [ 2 ] =
pykbfcgxvc_idx_1 ; bpIndex_d0 [ 3 ] = mwzdolw5gj_idx_1 ; if ( rtP .
Constant8_Value_m3ahup3xji [ 1 ] > 1.0 ) { bpIndex_d0 [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_m3ahup3xji [ 1 ] >= 0.0 ) { bpIndex_d0 [ 4 ] = (
uint32_T ) rtP . Constant8_Value_m3ahup3xji [ 1 ] ; } else { bpIndex_d0 [ 4 ]
= 0U ; } ec1iub14lo [ 13 ] = intrp4d_fu32fla_pw ( bpIndex_d0 , frac_d0 , &
rtP . dp_WING_tip . CMy [ 2450U * bpIndex_d0 [ 4 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_kcrhpwfjfn , rtP .
InterpolationUsingPrelookup5_maxIndex_brkchxcoij ) ; frac_kh [ 0 ] = rtB .
gbccn4rvbj ; bpIndex_kh [ 0 ] = rtB . bqft1jkk0z ; for ( i_p = 0 ; i_p < 5 ;
i_p ++ ) { frac_kh [ 1 ] = jtk2ho12tm [ i_p ] ; frac_kh [ 2 ] = p52cvq2maf [
i_p ] ; frac_kh [ 3 ] = gzu1zm2zul [ i_p ] ; bpIndex_kh [ 1 ] = bpIndex [ i_p
] ; bpIndex_kh [ 2 ] = bpIndex_p [ i_p ] ; bpIndex_kh [ 3 ] = bpIndex_e [ i_p
] ; f0ykxvjp2e = rtP . Constant8_Value_kwpfdqsyq1 [ i_p ] ; if ( f0ykxvjp2e >
4.0 ) { bpIndex_kh [ 4 ] = 4U ; } else if ( f0ykxvjp2e >= 0.0 ) { bpIndex_kh
[ 4 ] = ( uint32_T ) f0ykxvjp2e ; } else { bpIndex_kh [ 4 ] = 0U ; }
ec1iub14lo [ i_p + 14 ] = intrp4d_fu32fla_pw ( bpIndex_kh , frac_kh , & rtP .
dp_WING_root . CMz [ 1750U * bpIndex_kh [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_gllaksp5ia , rtP .
InterpolationUsingPrelookup6_maxIndex_ny0js42i4o ) ; } frac_m0 [ 0 ] = rtB .
igwg4uissg ; bpIndex_m0 [ 0 ] = rtB . fu5nkfrvvl ; frac_m0 [ 1 ] = pjs3tdc01w
[ 0 ] ; frac_m0 [ 2 ] = pgkyyjejl3 [ 0 ] ; frac_m0 [ 3 ] = orrknllzxd [ 0 ] ;
bpIndex_m0 [ 1 ] = h2f22pqghw_idx_0 ; bpIndex_m0 [ 2 ] = pykbfcgxvc_idx_0 ;
bpIndex_m0 [ 3 ] = mwzdolw5gj_idx_0 ; if ( rtP . Constant8_Value_m3ahup3xji [
0 ] > 1.0 ) { bpIndex_m0 [ 4 ] = 1U ; } else if ( rtP .
Constant8_Value_m3ahup3xji [ 0 ] >= 0.0 ) { bpIndex_m0 [ 4 ] = ( uint32_T )
rtP . Constant8_Value_m3ahup3xji [ 0 ] ; } else { bpIndex_m0 [ 4 ] = 0U ; }
ec1iub14lo [ 19 ] = intrp4d_fu32fla_pw ( bpIndex_m0 , frac_m0 , & rtP .
dp_WING_tip . CMz [ 2450U * bpIndex_m0 [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_npg5h2ocwn , rtP .
InterpolationUsingPrelookup6_maxIndex_lpfi2gwlwq ) ; frac_m0 [ 1 ] =
pjs3tdc01w [ 1 ] ; frac_m0 [ 2 ] = pgkyyjejl3 [ 1 ] ; frac_m0 [ 3 ] =
orrknllzxd [ 1 ] ; bpIndex_m0 [ 1 ] = h2f22pqghw_idx_1 ; bpIndex_m0 [ 2 ] =
pykbfcgxvc_idx_1 ; bpIndex_m0 [ 3 ] = mwzdolw5gj_idx_1 ; if ( rtP .
Constant8_Value_m3ahup3xji [ 1 ] > 1.0 ) { bpIndex_m0 [ 4 ] = 1U ; } else if
( rtP . Constant8_Value_m3ahup3xji [ 1 ] >= 0.0 ) { bpIndex_m0 [ 4 ] = (
uint32_T ) rtP . Constant8_Value_m3ahup3xji [ 1 ] ; } else { bpIndex_m0 [ 4 ]
= 0U ; } ec1iub14lo [ 20 ] = intrp4d_fu32fla_pw ( bpIndex_m0 , frac_m0 , &
rtP . dp_WING_tip . CMz [ 2450U * bpIndex_m0 [ 4 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_npg5h2ocwn , rtP .
InterpolationUsingPrelookup6_maxIndex_lpfi2gwlwq ) ; f0ykxvjp2e = rtP . S /
2.0 ; for ( i_p = 0 ; i_p < 7 ; i_p ++ ) { do1u0posi5 [ 3 * i_p ] =
kgeeoq3i0q [ 3 * i_p ] * ec1iub14lo [ i_p ] * rtP . Constant_Value_bchqth404u
[ 3 * i_p ] * rtB . ecjaklyjaq * f0ykxvjp2e + rtB . kainbdj3jz [ 3 * i_p ] ;
do1u0posi5 [ 3 * i_p + 1 ] = kgeeoq3i0q [ 3 * i_p + 1 ] * ec1iub14lo [ i_p +
7 ] * rtP . Constant_Value_bchqth404u [ 3 * i_p + 1 ] * rtB . ecjaklyjaq *
f0ykxvjp2e + rtB . kainbdj3jz [ 3 * i_p + 1 ] ; do1u0posi5 [ 3 * i_p + 2 ] =
kgeeoq3i0q [ 3 * i_p + 2 ] * ec1iub14lo [ i_p + 14 ] * rtP .
Constant_Value_bchqth404u [ 3 * i_p + 2 ] * rtB . ecjaklyjaq * f0ykxvjp2e +
rtB . kainbdj3jz [ 3 * i_p + 2 ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) {
f0ykxvjp2e = - 0.0 ; for ( i = 0 ; i < 7 ; i ++ ) { f0ykxvjp2e += do1u0posi5
[ i * 3 + i_p ] ; } frac_o [ i_p ] = f0ykxvjp2e ; } og2mhjvxrf_idx_0 = (
real32_T ) frac_o [ 0 ] ; og2mhjvxrf_idx_1 = ( real32_T ) frac_o [ 1 ] ;
og2mhjvxrf_idx_2 = ( real32_T ) frac_o [ 2 ] ; parallel_for ( 16 , cv3gln2abz
, 1 , "cv3gln2abz" ) ; for ( i_p = 0 ; i_p < 16 ; i_p ++ ) { f0ykxvjp2e = rtB
. mgyjrcfqfu [ i_p ] ; frac_fv [ 0 ] = f0ykxvjp2e ; noivdi5wij = ep5pua1w1i [
i_p ] ; frac_fv [ 1 ] = noivdi5wij ; nntliqh2c3 = njokkaqa44 [ i_p ] ;
frac_fv [ 2 ] = nntliqh2c3 ; pmh50qaazg = rtB . pmh50qaazg [ i_p ] ;
bpIndex_fv [ 0 ] = pmh50qaazg ; d2tzmda3nu = p4lqtpxnj2 [ i_p ] ; bpIndex_fv
[ 1 ] = d2tzmda3nu ; glo3iuekqm = hg0sesl5ey [ i_p ] ; bpIndex_fv [ 2 ] =
glo3iuekqm ; Constant8_Value_cr0us2qlbv = rtP . Constant8_Value_cr0us2qlbv [
i_p ] ; if ( Constant8_Value_cr0us2qlbv > 15.0 ) { bpIndex_fv [ 3 ] = 15U ; }
else if ( Constant8_Value_cr0us2qlbv >= 0.0 ) { bpIndex_fv [ 3 ] = ( uint32_T
) Constant8_Value_cr0us2qlbv ; } else { bpIndex_fv [ 3 ] = 0U ; } e5eea4yz11
= intrp3d_fl_pw ( bpIndex_fv , frac_fv , & rtP . dp_VTAIL . CMx [ 1170U *
bpIndex_fv [ 3 ] ] , rtP . InterpolationUsingPrelookup4_dimSize_lnthg1rnjp )
; frac_m4 [ 0 ] = f0ykxvjp2e ; frac_m4 [ 1 ] = noivdi5wij ; frac_m4 [ 2 ] =
nntliqh2c3 ; bpIndex_m4 [ 0 ] = pmh50qaazg ; bpIndex_m4 [ 1 ] = d2tzmda3nu ;
bpIndex_m4 [ 2 ] = glo3iuekqm ; if ( Constant8_Value_cr0us2qlbv > 15.0 ) {
bpIndex_m4 [ 3 ] = 15U ; } else if ( Constant8_Value_cr0us2qlbv >= 0.0 ) {
bpIndex_m4 [ 3 ] = ( uint32_T ) Constant8_Value_cr0us2qlbv ; } else {
bpIndex_m4 [ 3 ] = 0U ; } bzcsjahvxl_p = intrp3d_fl_pw ( bpIndex_m4 , frac_m4
, & rtP . dp_VTAIL . CMy [ 1170U * bpIndex_m4 [ 3 ] ] , rtP .
InterpolationUsingPrelookup5_dimSize_brj4qiei0w ) ; frac_nf [ 0 ] =
f0ykxvjp2e ; frac_nf [ 1 ] = noivdi5wij ; frac_nf [ 2 ] = nntliqh2c3 ;
bpIndex_nf [ 0 ] = pmh50qaazg ; bpIndex_nf [ 1 ] = d2tzmda3nu ; bpIndex_nf [
2 ] = glo3iuekqm ; if ( Constant8_Value_cr0us2qlbv > 15.0 ) { bpIndex_nf [ 3
] = 15U ; } else if ( Constant8_Value_cr0us2qlbv >= 0.0 ) { bpIndex_nf [ 3 ]
= ( uint32_T ) Constant8_Value_cr0us2qlbv ; } else { bpIndex_nf [ 3 ] = 0U ;
} noivdi5wij = intrp3d_fl_pw ( bpIndex_nf , frac_nf , & rtP . dp_VTAIL . CMz
[ 1170U * bpIndex_nf [ 3 ] ] , rtP .
InterpolationUsingPrelookup6_dimSize_nqfnlt53ag ) ; gvxohgx2qx [ 3 * i_p ] =
m5u5mthwev [ 3 * i_p ] * e5eea4yz11 * rtP . Constant1_Value_jtw2pfsmen [ 3 *
i_p ] * rtB . ecjaklyjaq * rtP . Gain3_Gain + rtB . kainbdj3jznl [ 3 * i_p ]
; gvxohgx2qx [ 3 * i_p + 1 ] = m5u5mthwev [ 3 * i_p + 1 ] * bzcsjahvxl_p *
rtP . Constant1_Value_jtw2pfsmen [ 3 * i_p + 1 ] * rtB . ecjaklyjaq * rtP .
Gain3_Gain + rtB . kainbdj3jznl [ 3 * i_p + 1 ] ; gvxohgx2qx [ 3 * i_p + 2 ]
= m5u5mthwev [ 3 * i_p + 2 ] * noivdi5wij * rtP . Constant1_Value_jtw2pfsmen
[ 3 * i_p + 2 ] * rtB . ecjaklyjaq * rtP . Gain3_Gain + rtB . kainbdj3jznl [
3 * i_p + 2 ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { f0ykxvjp2e = - 0.0 ;
for ( i = 0 ; i < 16 ; i ++ ) { f0ykxvjp2e += gvxohgx2qx [ i * 3 + i_p ] ; }
frac_o [ i_p ] = f0ykxvjp2e ; } rtB . noeiauttpl [ 0 ] = ( ( real_T ) ( -
cuyoqaviu3_idx_0 + og2mhjvxrf_idx_0 ) + ( real32_T ) frac_o [ 0 ] ) + rtB .
l3mgpdtrrg [ 0 ] ; rtB . noeiauttpl [ 1 ] = ( ( real_T ) ( cuyoqaviu3_idx_1 +
og2mhjvxrf_idx_1 ) + ( real32_T ) frac_o [ 1 ] ) + rtB . l3mgpdtrrg [ 1 ] ;
rtB . noeiauttpl [ 2 ] = ( ( real_T ) ( - cuyoqaviu3_idx_2 + og2mhjvxrf_idx_2
) + ( real32_T ) frac_o [ 2 ] ) + rtB . l3mgpdtrrg [ 2 ] ; for ( i_p = 0 ;
i_p < 3 ; i_p ++ ) { f0ykxvjp2e = - 0.0 ; for ( i = 0 ; i < 12 ; i ++ ) {
f0ykxvjp2e += rtB . jltpjpl4zp [ i * 3 + i_p ] ; } frac_o [ i_p ] =
f0ykxvjp2e ; } f0ykxvjp2e = - 0.0 ; frac_fv [ 0 ] = ( ( ( frac_o [ 0 ] + rtP
. Constant_Value_dtyrktojcw ) + rtB . noeiauttpl [ 0 ] ) - rtB . czxnr0doyy [
0 ] ) - rtB . cyv21phhbm [ 0 ] ; frac_fv [ 1 ] = ( ( ( frac_o [ 1 ] + rtP .
Constant_Value_dtyrktojcw ) + rtB . noeiauttpl [ 1 ] ) - rtB . czxnr0doyy [ 1
] ) - rtB . cyv21phhbm [ 1 ] ; frac_fv [ 2 ] = ( ( ( frac_o [ 2 ] + rtP .
Constant_Value_dtyrktojcw ) + rtB . noeiauttpl [ 2 ] ) - rtB . czxnr0doyy [ 2
] ) - rtB . cyv21phhbm [ 2 ] ; rt_mrdivide_U1d1x3_U2d3x3_Yd1x3_snf ( frac_fv
, rtB . kqrxmtokjd , frac_m4 ) ; dagu2sl5i1 [ 6 ] = rtB . bjhstbmrsn ;
dagu2sl5i1 [ 7 ] = rtB . bp0afaxpp5 ; dagu2sl5i1 [ 8 ] = rtB . osqwflveuv ;
dagu2sl5i1 [ 0 ] = rtB . hzhdx3sz5v [ 0 ] ; dagu2sl5i1 [ 3 ] = frac_dz [ 0 ]
/ rtP . m + rtB . j1stuyzs1t [ 0 ] ; dagu2sl5i1 [ 9 ] = frac_m4 [ 0 ] ;
dagu2sl5i1 [ 12 ] = frac_dz [ 0 ] ; dagu2sl5i1 [ 16 ] = esrvq4wxba [ 0 ] ;
dagu2sl5i1 [ 19 ] = rtB . noeiauttpl [ 0 ] ; dagu2sl5i1 [ 22 ] = frac_fs [ 0
] ; dagu2sl5i1 [ 25 ] = frac_o [ 0 ] ; dagu2sl5i1 [ 1 ] = rtB . hzhdx3sz5v [
1 ] ; dagu2sl5i1 [ 4 ] = frac_dz [ 1 ] / rtP . m + rtB . j1stuyzs1t [ 1 ] ;
dagu2sl5i1 [ 10 ] = frac_m4 [ 1 ] ; dagu2sl5i1 [ 13 ] = frac_dz [ 1 ] ;
dagu2sl5i1 [ 17 ] = esrvq4wxba [ 1 ] ; dagu2sl5i1 [ 20 ] = rtB . noeiauttpl [
1 ] ; dagu2sl5i1 [ 23 ] = frac_fs [ 1 ] ; dagu2sl5i1 [ 26 ] = frac_o [ 1 ] ;
dagu2sl5i1 [ 2 ] = rtB . hzhdx3sz5v [ 2 ] ; dagu2sl5i1 [ 5 ] = frac_dz [ 2 ]
/ rtP . m + rtB . j1stuyzs1t [ 2 ] ; dagu2sl5i1 [ 11 ] = frac_m4 [ 2 ] ;
dagu2sl5i1 [ 14 ] = frac_dz [ 2 ] ; dagu2sl5i1 [ 18 ] = esrvq4wxba [ 2 ] ;
dagu2sl5i1 [ 21 ] = rtB . noeiauttpl [ 2 ] ; dagu2sl5i1 [ 24 ] = frac_fs [ 2
] ; dagu2sl5i1 [ 27 ] = frac_o [ 2 ] ; dagu2sl5i1 [ 28 ] = rtB . gfknqoynom ;
dagu2sl5i1 [ 29 ] = rtP . Constant_Value_dtyrktojcw ; dagu2sl5i1 [ 30 ] = rtP
. Constant_Value_dtyrktojcw ; dagu2sl5i1 [ 31 ] = rtP .
Constant_Value_dtyrktojcw ; dagu2sl5i1 [ 32 ] = rtP .
Constant_Value_dtyrktojcw ; dagu2sl5i1 [ 33 ] = rtP .
Constant_Value_dtyrktojcw ; for ( i_p = 0 ; i_p < 12 ; i_p ++ ) { f0ykxvjp2e
+= rtB . nluycx3bh3 [ i_p ] ; dagu2sl5i1 [ i_p + 34 ] = rtB . p1lfhtknc0 [
i_p ] ; dagu2sl5i1 [ i_p + 46 ] = rtB . bftm5ocvno [ i_p ] ; dagu2sl5i1 [ i_p
+ 58 ] = rtB . etlvxwxtcy [ i_p ] ; } dagu2sl5i1 [ 15 ] = rtP . Gain1_Gain *
f0ykxvjp2e * rtP . Gain2_Gain + rtB . orlelyhfjl ; memcpy ( & rtY .
ekh2fh00tc [ 0 ] , & dagu2sl5i1 [ 0 ] , 70U * sizeof ( real_T ) ) ; { if (
rtDW . mw5cjkjcde . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . mw5cjkjcde . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) &
dagu2sl5i1 [ 0 ] + 0 ) ; } } } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID1 ( int_T tid ) { real_T cx03kvbqie [ 18 ] ; real_T e5m4lakd0l [
16 ] ; real_T tmp_e [ 10 ] ; real_T e5rpw1ek1v [ 9 ] ; real_T tmp_p [ 5 ] ;
real_T al44ljl512 [ 3 ] ; real_T kgibdgfrc0 [ 3 ] ; real_T d3eatf34tr ;
real_T gdtrsjcewr_idx_0 ; real_T gdtrsjcewr_idx_1 ; real_T hhviygi3cm ;
real_T hjttkybh1q ; real_T i4bjkjn1gf ; real_T j2eewjhdpa ; real_T kmfnrex520
; real_T lpaiahwg3w_idx_1 ; real_T lpaiahwg3w_idx_2 ; real_T mgqm32zwav_idx_0
; real_T mgqm32zwav_idx_1 ; real_T ngmxr5x0vt_idx_1 ; int32_T i ; real32_T
frac [ 2 ] ; real32_T frac_e [ 2 ] ; real32_T frac_i [ 2 ] ; real32_T frac_m
[ 2 ] ; real32_T frac_p [ 2 ] ; real32_T dym5ca3jhv_idx_0 ; real32_T
dym5ca3jhv_idx_1 ; real32_T dym5ca3jhv_idx_2 ; real32_T fftpwkdb2l ; real32_T
ifn41umu44 ; real32_T oxl1en4taa ; real32_T tmp ; real32_T tmp_i ; uint32_T
bpIndex [ 2 ] ; uint32_T bpIndex_e [ 2 ] ; uint32_T bpIndex_i [ 2 ] ;
uint32_T bpIndex_m [ 2 ] ; uint32_T bpIndex_p [ 2 ] ; uint32_T d1pa2cabjk ;
uint32_T lfhn4gnsr4 ; parallel_for ( 12 , b4xsnziie2TID1 , 1 ,
"b4xsnziie2TID1" ) ; i4bjkjn1gf = - rtP . testinput_Value [ 12 ] ; j2eewjhdpa
= rtP . testinput_Value [ 14 ] - rtP . testinput_Value [ 13 ] ; kmfnrex520 =
rtP . testinput_Value [ 13 ] + rtP . testinput_Value [ 14 ] ; if ( - rtP .
testinput_Value [ 2 ] > rtP . Limitaltitudetotroposhere_UpperSat ) {
mgqm32zwav_idx_0 = rtP . Limitaltitudetotroposhere_UpperSat ; } else if ( -
rtP . testinput_Value [ 2 ] < rtP . Limitaltitudetotroposhere_LowerSat ) {
mgqm32zwav_idx_0 = rtP . Limitaltitudetotroposhere_LowerSat ; } else {
mgqm32zwav_idx_0 = - rtP . testinput_Value [ 2 ] ; } hhviygi3cm = rtP .
SeaLevelTemperature_Value - rtP . LapseRate_Gain * mgqm32zwav_idx_0 ;
d3eatf34tr = rtP . uT0_Gain * hhviygi3cm ; hjttkybh1q = rtP .
AltitudeofTroposphere_Value - ( - rtP . testinput_Value [ 2 ] ) ; if ( (
d3eatf34tr < 0.0 ) && ( rtP . Constant_Value_mlc0xem4a2 > muDoubleScalarFloor
( rtP . Constant_Value_mlc0xem4a2 ) ) ) { mgqm32zwav_idx_0 = -
muDoubleScalarPower ( - d3eatf34tr , rtP . Constant_Value_mlc0xem4a2 ) ; }
else { mgqm32zwav_idx_0 = muDoubleScalarPower ( d3eatf34tr , rtP .
Constant_Value_mlc0xem4a2 ) ; } if ( hjttkybh1q > rtP .
LimitaltitudetoStratosphere_UpperSat ) { hjttkybh1q = rtP .
LimitaltitudetoStratosphere_UpperSat ; } else if ( hjttkybh1q < rtP .
LimitaltitudetoStratosphere_LowerSat ) { hjttkybh1q = rtP .
LimitaltitudetoStratosphere_LowerSat ; } rtB . jefg5cifsj = mgqm32zwav_idx_0
/ d3eatf34tr * rtP . rho0_Gain * muDoubleScalarExp ( 1.0 / hhviygi3cm * ( rtP
. gR_Gain * hjttkybh1q ) ) ; rtB . lxkh42xndm [ 0 ] = ( real32_T ) rtP .
testinput_Value [ 3 ] ; rtB . lcnor15erx [ 0 ] = ( real32_T ) rtP .
testinput_Value [ 9 ] ; rtB . lxkh42xndm [ 1 ] = ( real32_T ) rtP .
testinput_Value [ 4 ] ; rtB . lcnor15erx [ 1 ] = ( real32_T ) rtP .
testinput_Value [ 10 ] ; rtB . lxkh42xndm [ 2 ] = ( real32_T ) rtP .
testinput_Value [ 5 ] ; rtB . lcnor15erx [ 2 ] = ( real32_T ) rtP .
testinput_Value [ 11 ] ; parallel_for ( 16 , jgo5lugg00TID1 , 1 ,
"jgo5lugg00TID1" ) ; parallel_for ( 14 , f53wtq1cerTID1 , 1 ,
"f53wtq1cerTID1" ) ; hhviygi3cm = muDoubleScalarAtan2 ( rtP . testinput_Value
[ 5 ] , rtP . testinput_Value [ 3 ] ) ; dym5ca3jhv_idx_0 = ( real32_T ) rtP .
dp_FUSE_FIN . ref_CG [ 0 ] - ( real32_T ) rtP . xyz_cg [ 0 ] ;
dym5ca3jhv_idx_1 = ( real32_T ) rtP . dp_FUSE_FIN . ref_CG [ 1 ] - ( real32_T
) rtP . xyz_cg [ 1 ] ; dym5ca3jhv_idx_2 = ( real32_T ) rtP . dp_FUSE_FIN .
ref_CG [ 2 ] - ( real32_T ) rtP . xyz_cg [ 2 ] ; d3eatf34tr = ( rtP .
testinput_Value [ 3 ] * rtP . testinput_Value [ 3 ] + rtP . testinput_Value [
4 ] * rtP . testinput_Value [ 4 ] ) + rtP . testinput_Value [ 5 ] * rtP .
testinput_Value [ 5 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
lmdux514h1 != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
lmdux514h1 = 0 ; } hjttkybh1q = muDoubleScalarSqrt ( d3eatf34tr ) ; } else if
( d3eatf34tr < 0.0 ) { hjttkybh1q = - muDoubleScalarSqrt ( muDoubleScalarAbs
( d3eatf34tr ) ) ; rtDW . lmdux514h1 = 1 ; } else { hjttkybh1q =
muDoubleScalarSqrt ( d3eatf34tr ) ; } d3eatf34tr = hjttkybh1q + rtP .
Constant1_Value ; hjttkybh1q = rtP . testinput_Value [ 4 ] / d3eatf34tr ; if
( hjttkybh1q > 1.0 ) { hjttkybh1q = 1.0 ; } else if ( hjttkybh1q < - 1.0 ) {
hjttkybh1q = - 1.0 ; } hjttkybh1q = muDoubleScalarAsin ( hjttkybh1q ) ;
muDoubleScalarSinCos ( ( real32_T ) hhviygi3cm , & mgqm32zwav_idx_0 , &
gdtrsjcewr_idx_0 ) ; muDoubleScalarSinCos ( ( real32_T ) hjttkybh1q , &
mgqm32zwav_idx_1 , & gdtrsjcewr_idx_1 ) ; e5rpw1ek1v [ 0 ] = gdtrsjcewr_idx_0
* gdtrsjcewr_idx_1 ; e5rpw1ek1v [ 1 ] = - ( gdtrsjcewr_idx_0 *
mgqm32zwav_idx_1 ) ; e5rpw1ek1v [ 2 ] = - mgqm32zwav_idx_0 ; e5rpw1ek1v [ 3 ]
= mgqm32zwav_idx_1 ; e5rpw1ek1v [ 4 ] = gdtrsjcewr_idx_1 ; e5rpw1ek1v [ 5 ] =
rtP . Constant_Value_ll1hqpke5l ; e5rpw1ek1v [ 6 ] = mgqm32zwav_idx_0 *
gdtrsjcewr_idx_1 ; e5rpw1ek1v [ 7 ] = - ( mgqm32zwav_idx_0 * mgqm32zwav_idx_1
) ; e5rpw1ek1v [ 8 ] = gdtrsjcewr_idx_0 ; d1pa2cabjk = plook_u32ff_linxp ( (
real32_T ) hjttkybh1q , rtP . Prelookup_BreakpointsData , 12U , & ifn41umu44
, & rtDW . khbxaboxwb ) ; lfhn4gnsr4 = plook_u32ff_linxp ( ( real32_T )
hhviygi3cm , rtP . Prelookup1_BreakpointsData , 14U , & oxl1en4taa , & rtDW .
djzedhv1ik ) ; frac [ 0 ] = ifn41umu44 ; frac [ 1 ] = oxl1en4taa ; bpIndex [
0 ] = d1pa2cabjk ; bpIndex [ 1 ] = lfhn4gnsr4 ; frac_p [ 0 ] = ifn41umu44 ;
frac_p [ 1 ] = oxl1en4taa ; bpIndex_p [ 0 ] = d1pa2cabjk ; bpIndex_p [ 1 ] =
lfhn4gnsr4 ; fftpwkdb2l = ( real32_T ) d3eatf34tr * ( real32_T ) d3eatf34tr ;
rtB . ecjaklyjaq = ( real32_T ) rtB . jefg5cifsj ; tmp = intrp2d_fu32fl_pw (
bpIndex_p , frac_p , rtP . dp_FUSE_FIN . CS , 13U ) ; tmp_i = -
intrp2d_fu32fl_pw ( bpIndex , frac , rtP . dp_FUSE_FIN . CD , 13U ) ; for ( i
= 0 ; i < 3 ; i ++ ) { rtB . f5f1ypai11 [ i ] = ( ( ( real32_T ) e5rpw1ek1v [
3 * i + 1 ] * tmp + ( real32_T ) e5rpw1ek1v [ 3 * i ] * tmp_i ) + ( real32_T
) e5rpw1ek1v [ 3 * i + 2 ] * - rtP . Constant_Value_dggd0yls2s ) * fftpwkdb2l
* rtB . ecjaklyjaq * rtP . Gain_Gain_ngpzxxezsf ; } frac_e [ 0 ] = ifn41umu44
; frac_e [ 1 ] = oxl1en4taa ; bpIndex_e [ 0 ] = d1pa2cabjk ; bpIndex_e [ 1 ]
= lfhn4gnsr4 ; frac_i [ 0 ] = ifn41umu44 ; frac_i [ 1 ] = oxl1en4taa ;
bpIndex_i [ 0 ] = d1pa2cabjk ; bpIndex_i [ 1 ] = lfhn4gnsr4 ; frac_m [ 0 ] =
ifn41umu44 ; frac_m [ 1 ] = oxl1en4taa ; bpIndex_m [ 0 ] = d1pa2cabjk ;
bpIndex_m [ 1 ] = lfhn4gnsr4 ; mgqm32zwav_idx_0 = rtP . S / 2.0 ; rtB .
l3mgpdtrrg [ 0 ] = intrp2d_fu32fl_pw ( bpIndex_e , frac_e , rtP . dp_FUSE_FIN
. CMx , 13U ) * fftpwkdb2l * rtP . Constant_Value_exkenlsy3u [ 0 ] * rtB .
ecjaklyjaq * mgqm32zwav_idx_0 + ( dym5ca3jhv_idx_1 * rtB . f5f1ypai11 [ 2 ] -
rtB . f5f1ypai11 [ 1 ] * dym5ca3jhv_idx_2 ) ; rtB . l3mgpdtrrg [ 1 ] =
intrp2d_fu32fl_pw ( bpIndex_i , frac_i , rtP . dp_FUSE_FIN . CMy , 13U ) *
fftpwkdb2l * rtP . Constant_Value_exkenlsy3u [ 1 ] * rtB . ecjaklyjaq *
mgqm32zwav_idx_0 + ( rtB . f5f1ypai11 [ 0 ] * dym5ca3jhv_idx_2 -
dym5ca3jhv_idx_0 * rtB . f5f1ypai11 [ 2 ] ) ; rtB . l3mgpdtrrg [ 2 ] =
intrp2d_fu32fl_pw ( bpIndex_m , frac_m , rtP . dp_FUSE_FIN . CMz , 13U ) *
fftpwkdb2l * rtP . Constant_Value_exkenlsy3u [ 2 ] * rtB . ecjaklyjaq *
mgqm32zwav_idx_0 + ( dym5ca3jhv_idx_0 * rtB . f5f1ypai11 [ 1 ] - rtB .
f5f1ypai11 [ 0 ] * dym5ca3jhv_idx_1 ) ; if ( j2eewjhdpa > rtP .
Saturation2_UpperSat ) { j2eewjhdpa = rtP . Saturation2_UpperSat ; } else if
( j2eewjhdpa < rtP . Saturation2_LowerSat ) { j2eewjhdpa = rtP .
Saturation2_LowerSat ; } if ( kmfnrex520 > rtP . Saturation3_UpperSat ) {
kmfnrex520 = rtP . Saturation3_UpperSat ; } else if ( kmfnrex520 < rtP .
Saturation3_LowerSat ) { kmfnrex520 = rtP . Saturation3_LowerSat ; } if ( rtP
. testinput_Value [ 15 ] > rtP . Saturation6_UpperSat ) { mgqm32zwav_idx_0 =
rtP . Saturation6_UpperSat ; } else if ( rtP . testinput_Value [ 15 ] < rtP .
Saturation6_LowerSat ) { mgqm32zwav_idx_0 = rtP . Saturation6_LowerSat ; }
else { mgqm32zwav_idx_0 = rtP . testinput_Value [ 15 ] ; } if ( rtP .
testinput_Value [ 15 ] > rtP . Saturation4_UpperSat ) { gdtrsjcewr_idx_0 =
rtP . Saturation4_UpperSat ; } else if ( rtP . testinput_Value [ 15 ] < rtP .
Saturation4_LowerSat ) { gdtrsjcewr_idx_0 = rtP . Saturation4_LowerSat ; }
else { gdtrsjcewr_idx_0 = rtP . testinput_Value [ 15 ] ; } for ( i = 0 ; i <
8 ; i ++ ) { e5m4lakd0l [ i ] = rtP . Constant_Value_izgjegg0j4 [ i ] * (
real32_T ) mgqm32zwav_idx_0 ; e5m4lakd0l [ i + 8 ] = rtP .
Constant1_Value_meik51c4df [ i ] * ( real32_T ) gdtrsjcewr_idx_0 ; } for ( i
= 0 ; i < 5 ; i ++ ) { tmp_p [ i ] = rtP . dp_VTAIL_INDUCED . flap_defl [ i ]
; } for ( i = 0 ; i < 16 ; i ++ ) { rtB . nhcvscc4t0 [ i ] = plook_linxp (
e5m4lakd0l [ i ] , tmp_p , 4U , & rtB . kunmel5bx4 [ i ] , & rtDW .
luravducvq [ i ] ) ; } parallel_for ( 16 , cv3gln2abzTID1 , 1 ,
"cv3gln2abzTID1" ) ; for ( i = 0 ; i < 8 ; i ++ ) { e5m4lakd0l [ i ] = rtP .
Constant_Value_kx5dv3qh2a [ i ] * ( real32_T ) j2eewjhdpa ; e5m4lakd0l [ i +
8 ] = rtP . Constant1_Value_dxjow4r24m [ i ] * ( real32_T ) kmfnrex520 ; }
for ( i = 0 ; i < 10 ; i ++ ) { tmp_e [ i ] = rtP . dp_VTAIL . rude_defl [ i
] ; } for ( i = 0 ; i < 16 ; i ++ ) { rtB . pmh50qaazg [ i ] = plook_linxp (
e5m4lakd0l [ i ] , tmp_e , 9U , & rtB . mgyjrcfqfu [ i ] , & rtDW .
e15temhbyp [ i ] ) ; } parallel_for ( 7 , d2dy1jnwgpTID1 , 1 ,
"d2dy1jnwgpTID1" ) ; rtB . g53iqbai0i = plook_u32ff_lincpa ( ( real32_T )
mgqm32zwav_idx_0 , rtP . dp_WING_root . flap_defl , 4U , & rtB . ayw0otszrq ,
& rtDW . jseguf13yy ) ; if ( rtP . testinput_Value [ 12 ] > rtP .
Saturation_UpperSat ) { mgqm32zwav_idx_0 = rtP . Saturation_UpperSat ; } else
if ( rtP . testinput_Value [ 12 ] < rtP . Saturation_LowerSat ) {
mgqm32zwav_idx_0 = rtP . Saturation_LowerSat ; } else { mgqm32zwav_idx_0 =
rtP . testinput_Value [ 12 ] ; } rtB . jqfgyi5cqv = plook_u32ff_lincpa ( (
real32_T ) mgqm32zwav_idx_0 , rtP . dp_WING_tip . ail_defl , 6U , & rtB .
lkci5wisjr , & rtDW . cfngthrtfc ) ; parallel_for ( 7 , pg42w5emjtTID1 , 1 ,
"pg42w5emjtTID1" ) ; rtB . bqft1jkk0z = plook_u32ff_lincpa ( ( real32_T )
gdtrsjcewr_idx_0 , rtP . dp_WING_root . flap_defl , 4U , & rtB . gbccn4rvbj ,
& rtDW . k3rxirp2ci ) ; if ( i4bjkjn1gf > rtP . Saturation1_UpperSat ) {
i4bjkjn1gf = rtP . Saturation1_UpperSat ; } else if ( i4bjkjn1gf < rtP .
Saturation1_LowerSat ) { i4bjkjn1gf = rtP . Saturation1_LowerSat ; } rtB .
fu5nkfrvvl = plook_u32ff_lincpa ( ( real32_T ) i4bjkjn1gf , rtP . dp_WING_tip
. ail_defl , 6U , & rtB . igwg4uissg , & rtDW . nfqrlmtid3 ) ;
muDoubleScalarSinCos ( ( real32_T ) hhviygi3cm , & i4bjkjn1gf , & j2eewjhdpa
) ; muDoubleScalarSinCos ( ( real32_T ) hjttkybh1q , & hhviygi3cm , &
ngmxr5x0vt_idx_1 ) ; e5rpw1ek1v [ 0 ] = j2eewjhdpa * ngmxr5x0vt_idx_1 ;
e5rpw1ek1v [ 1 ] = - ( j2eewjhdpa * hhviygi3cm ) ; e5rpw1ek1v [ 2 ] = -
i4bjkjn1gf ; e5rpw1ek1v [ 3 ] = hhviygi3cm ; e5rpw1ek1v [ 4 ] =
ngmxr5x0vt_idx_1 ; e5rpw1ek1v [ 5 ] = rtP . Constant_Value_ec1rbuxqhz ;
e5rpw1ek1v [ 6 ] = i4bjkjn1gf * ngmxr5x0vt_idx_1 ; e5rpw1ek1v [ 7 ] = - (
i4bjkjn1gf * hhviygi3cm ) ; e5rpw1ek1v [ 8 ] = j2eewjhdpa ; tmp_i = - ( ( rtP
. gear_drag_Value * ( real32_T ) rtP . Constant_Value + rtP .
extra_drag_Value ) * rtB . ecjaklyjaq * rtP . Gain_Gain_jabdopn2nb * ( (
real32_T ) d3eatf34tr * ( real32_T ) d3eatf34tr ) ) ; for ( i = 0 ; i < 3 ; i
++ ) { rtB . ejdl4n31el [ i ] = ( ( real32_T ) e5rpw1ek1v [ 3 * i + 1 ] * rtP
. Constant1_Value_fodj5rxow1 + ( real32_T ) e5rpw1ek1v [ 3 * i ] * tmp_i ) +
( real32_T ) e5rpw1ek1v [ 3 * i + 2 ] * rtP . Constant1_Value_fodj5rxow1 ; }
i4bjkjn1gf = rtP . Gain_Gain * rtB . jefg5cifsj ; if ( ssIsMajorTimeStep (
rtS ) ) { if ( rtDW . ckg5ciehpx != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
ssSetContTimeOutputInconsistentWithStateAtMajorStep ( rtS ) ; rtDW .
ckg5ciehpx = 0 ; } j2eewjhdpa = muDoubleScalarSqrt ( i4bjkjn1gf ) ; } else if
( i4bjkjn1gf < 0.0 ) { j2eewjhdpa = - muDoubleScalarSqrt ( muDoubleScalarAbs
( i4bjkjn1gf ) ) ; rtDW . ckg5ciehpx = 1 ; } else { j2eewjhdpa =
muDoubleScalarSqrt ( i4bjkjn1gf ) ; } i4bjkjn1gf = d3eatf34tr * j2eewjhdpa ;
for ( i = 0 ; i < 3 ; i ++ ) { cx03kvbqie [ 6 * i ] = rtP . I [ 3 * i ] ;
cx03kvbqie [ 6 * i + 3 ] = rtP . Constant2_Value [ 3 * i ] ; cx03kvbqie [ 6 *
i + 1 ] = rtP . I [ 3 * i + 1 ] ; cx03kvbqie [ 6 * i + 4 ] = rtP .
Constant2_Value [ 3 * i + 1 ] ; cx03kvbqie [ 6 * i + 2 ] = rtP . I [ 3 * i +
2 ] ; cx03kvbqie [ 6 * i + 5 ] = rtP . Constant2_Value [ 3 * i + 2 ] ; }
d3eatf34tr = rtP . testinput_Value [ 9 ] ; j2eewjhdpa = rtP . testinput_Value
[ 10 ] ; kmfnrex520 = rtP . testinput_Value [ 11 ] ; for ( i = 0 ; i < 3 ; i
++ ) { rtB . kqrxmtokjd [ 3 * i ] = cx03kvbqie [ 6 * i ] ; rtB . kqrxmtokjd [
3 * i + 1 ] = cx03kvbqie [ 6 * i + 1 ] ; rtB . kqrxmtokjd [ 3 * i + 2 ] =
cx03kvbqie [ 6 * i + 2 ] ; rtB . czxnr0doyy [ i ] = ( cx03kvbqie [ i + 3 ] *
d3eatf34tr + cx03kvbqie [ i + 9 ] * j2eewjhdpa ) + cx03kvbqie [ i + 15 ] *
kmfnrex520 ; al44ljl512 [ i ] = ( cx03kvbqie [ i + 6 ] * j2eewjhdpa +
cx03kvbqie [ i ] * d3eatf34tr ) + cx03kvbqie [ i + 12 ] * kmfnrex520 ; } rtB
. cyv21phhbm [ 0 ] = al44ljl512 [ 2 ] * rtP . testinput_Value [ 10 ] -
al44ljl512 [ 1 ] * rtP . testinput_Value [ 11 ] ; rtB . cyv21phhbm [ 1 ] =
al44ljl512 [ 0 ] * rtP . testinput_Value [ 11 ] - al44ljl512 [ 2 ] * rtP .
testinput_Value [ 9 ] ; rtB . cyv21phhbm [ 2 ] = al44ljl512 [ 1 ] * rtP .
testinput_Value [ 9 ] - al44ljl512 [ 0 ] * rtP . testinput_Value [ 10 ] ;
al44ljl512 [ 0 ] = rtP . testinput_Value [ 8 ] ; al44ljl512 [ 1 ] = rtP .
testinput_Value [ 7 ] ; muDoubleScalarSinCos ( rtP . testinput_Value [ 8 ] ,
& d3eatf34tr , & kgibdgfrc0 [ 0 ] ) ; muDoubleScalarSinCos ( rtP .
testinput_Value [ 7 ] , & lpaiahwg3w_idx_1 , & kgibdgfrc0 [ 1 ] ) ;
muDoubleScalarSinCos ( rtP . testinput_Value [ 6 ] , & lpaiahwg3w_idx_2 , &
kgibdgfrc0 [ 2 ] ) ; e5rpw1ek1v [ 0 ] = kgibdgfrc0 [ 0 ] * kgibdgfrc0 [ 1 ] ;
e5rpw1ek1v [ 1 ] = lpaiahwg3w_idx_1 * lpaiahwg3w_idx_2 * kgibdgfrc0 [ 0 ] -
d3eatf34tr * kgibdgfrc0 [ 2 ] ; e5rpw1ek1v [ 2 ] = lpaiahwg3w_idx_1 *
kgibdgfrc0 [ 2 ] * kgibdgfrc0 [ 0 ] + d3eatf34tr * lpaiahwg3w_idx_2 ;
e5rpw1ek1v [ 3 ] = d3eatf34tr * kgibdgfrc0 [ 1 ] ; e5rpw1ek1v [ 4 ] =
lpaiahwg3w_idx_1 * lpaiahwg3w_idx_2 * d3eatf34tr + kgibdgfrc0 [ 0 ] *
kgibdgfrc0 [ 2 ] ; e5rpw1ek1v [ 5 ] = lpaiahwg3w_idx_1 * kgibdgfrc0 [ 2 ] *
d3eatf34tr - kgibdgfrc0 [ 0 ] * lpaiahwg3w_idx_2 ; e5rpw1ek1v [ 6 ] = -
lpaiahwg3w_idx_1 ; e5rpw1ek1v [ 7 ] = kgibdgfrc0 [ 1 ] * lpaiahwg3w_idx_2 ;
e5rpw1ek1v [ 8 ] = kgibdgfrc0 [ 1 ] * kgibdgfrc0 [ 2 ] ; rtB . j1stuyzs1t [ 0
] = rtP . testinput_Value [ 4 ] * rtP . testinput_Value [ 11 ] - rtP .
testinput_Value [ 5 ] * rtP . testinput_Value [ 10 ] ; rtB . j1stuyzs1t [ 1 ]
= rtP . testinput_Value [ 5 ] * rtP . testinput_Value [ 9 ] - rtP .
testinput_Value [ 3 ] * rtP . testinput_Value [ 11 ] ; rtB . j1stuyzs1t [ 2 ]
= rtP . testinput_Value [ 3 ] * rtP . testinput_Value [ 10 ] - rtP .
testinput_Value [ 4 ] * rtP . testinput_Value [ 9 ] ; for ( i = 0 ; i < 3 ; i
++ ) { muDoubleScalarSinCos ( rtP . testinput_Value [ i + 6 ] , & kgibdgfrc0
[ i ] , & al44ljl512 [ i ] ) ; rtB . hzhdx3sz5v [ i ] = ( e5rpw1ek1v [ 3 * i
+ 1 ] * rtP . testinput_Value [ 4 ] + e5rpw1ek1v [ 3 * i ] * rtP .
testinput_Value [ 3 ] ) + e5rpw1ek1v [ 3 * i + 2 ] * rtP . testinput_Value [
5 ] ; } rtB . bjhstbmrsn = ( kgibdgfrc0 [ 0 ] * rtP . testinput_Value [ 10 ]
+ al44ljl512 [ 0 ] * rtP . testinput_Value [ 11 ] ) * ( kgibdgfrc0 [ 1 ] /
al44ljl512 [ 1 ] ) + rtP . testinput_Value [ 9 ] ; rtB . osqwflveuv = (
kgibdgfrc0 [ 0 ] * rtP . testinput_Value [ 10 ] + al44ljl512 [ 0 ] * rtP .
testinput_Value [ 11 ] ) / al44ljl512 [ 1 ] ; rtB . bp0afaxpp5 = al44ljl512 [
0 ] * rtP . testinput_Value [ 10 ] - kgibdgfrc0 [ 0 ] * rtP . testinput_Value
[ 11 ] ; j2eewjhdpa = muDoubleScalarCos ( rtP . Inclination_Value ) ;
mgqm32zwav_idx_0 = rtP . testinput_Value [ 3 ] ; mgqm32zwav_idx_1 = rtP .
testinput_Value [ 11 ] ; gdtrsjcewr_idx_1 = rtP . xyz_cg [ 1 ] ; for ( i = 0
; i < 12 ; i ++ ) { rtB . fp54rsi3hk [ i ] = ( ( rtP . Gain_Gain_jhzuipt41u [
i ] * gdtrsjcewr_idx_1 - rtP . xyz_DEP [ 3 * i + 1 ] ) * mgqm32zwav_idx_1 +
mgqm32zwav_idx_0 ) * j2eewjhdpa ; } parallel_for ( 12 , eo4s0qr2utTID1 , 1 ,
"eo4s0qr2utTID1" ) ; d3eatf34tr = rtP . Multiply_Gain * rtP . m ; for ( i = 0
; i < 3 ; i ++ ) { rtB . omkpqlajlz [ i ] = ( e5rpw1ek1v [ i + 3 ] * rtP .
Constant_Value_kr4kbsbfsk + e5rpw1ek1v [ i ] * rtP .
Constant_Value_kr4kbsbfsk ) + e5rpw1ek1v [ i + 6 ] * d3eatf34tr ; }
j2eewjhdpa = look1_plinlcpw ( rtP . testinput_Value [ 18 ] , rtP .
uDLookupTable1_bp01Data , rtP . uDLookupTable1_tableData , & rtDW .
oa32expm1m , 1U ) ; kmfnrex520 = look1_plinlxpw ( i4bjkjn1gf , rtP . dp_HTU .
limits . V_up_lim , rtP . dp_HTU . limits . T_up_lim , & rtDW . fiq4gqvmys ,
4U ) ; hhviygi3cm = look1_plinlxpw ( i4bjkjn1gf , rtP . dp_HTU . limits .
V_low_lim , rtP . dp_HTU . limits . T_low_lim , & rtDW . mnbvnpxi3q , 5U ) ;
if ( j2eewjhdpa > kmfnrex520 ) { rtB . gfknqoynom = kmfnrex520 ; } else if (
j2eewjhdpa < hhviygi3cm ) { rtB . gfknqoynom = hhviygi3cm ; } else { rtB .
gfknqoynom = j2eewjhdpa ; } i4bjkjn1gf = look2_plinlxpw ( i4bjkjn1gf , rtB .
gfknqoynom , rtP . dp_HTU . V_vec , rtP . dp_HTU . T_vec , rtP . dp_HTU .
P_grid , rtDW . mitq3fljz5 , rtP . Plookup_maxIndex , 13U ) ; rtB .
orlelyhfjl = rtP . Gain_Gain_gmzj2h1bwx * i4bjkjn1gf ; UNUSED_PARAMETER ( tid
) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate
( void ) { { if ( rtDW . mw5cjkjcde . AQHandles ) { sdiTerminateStreaming ( &
rtDW . mw5cjkjcde . AQHandles ) ; } } } static void
mr_UNIFIER_dyn_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_UNIFIER_dyn_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_UNIFIER_dyn_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_UNIFIER_dyn_restoreDataFromMxArray ( void * destData , const mxArray
* srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * )
destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i
, j ) ) , numBytes ) ; } static void mr_UNIFIER_dyn_cacheBitFieldToMxArray (
mxArray * destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_UNIFIER_dyn_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int
j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_UNIFIER_dyn_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_UNIFIER_dyn_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_UNIFIER_dyn_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_UNIFIER_dyn_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
{ uint8_T * varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber (
destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes
] , ( const uint8_T * ) srcData , numBytes ) ; } static void
mr_UNIFIER_dyn_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ;
static void mr_UNIFIER_dyn_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_UNIFIER_dyn_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray
, mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_UNIFIER_dyn_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
real_T ) fieldVal ) ) ; } static uint_T
mr_UNIFIER_dyn_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_UNIFIER_dyn_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_UNIFIER_dyn_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW
= mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB )
, sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 38 ] = {
"rtDW.e3yadhhovi" , "rtDW.esnn32lqad" , "rtDW.lkiofcx0nc" , "rtDW.d45t54zzh0"
, "rtDW.obz0u22bxk" , "rtDW.mtbzqory0k" , "rtDW.cv4ea1x5bf" ,
"rtDW.p0luwllcwa" , "rtDW.momrqi2s1w" , "rtDW.jevgaddxph" , "rtDW.dctbywbcef"
, "rtDW.iiazkmp3zq" , "rtDW.pb5bsdxxpa" , "rtDW.p4va2j4maz" ,
"rtDW.ldxzligihn" , "rtDW.fb00myaqvg" , "rtDW.hkblkqalfc" , "rtDW.eewvdaqf4r"
, "rtDW.dgwkzgwl00" , "rtDW.lsgiesztth" , "rtDW.m05sv2n1iq" ,
"rtDW.khbxaboxwb" , "rtDW.djzedhv1ik" , "rtDW.luravducvq" , "rtDW.e15temhbyp"
, "rtDW.jseguf13yy" , "rtDW.cfngthrtfc" , "rtDW.k3rxirp2ci" ,
"rtDW.nfqrlmtid3" , "rtDW.oa32expm1m" , "rtDW.fiq4gqvmys" , "rtDW.mnbvnpxi3q"
, "rtDW.mitq3fljz5" , "rtDW.lmdux514h1" , "rtDW.ckg5ciehpx" ,
"rtDW.au023bergz[0].hq0naomli3" , "rtDW.au023bergz[0].g1bez0i0y4" ,
"rtDW.au023bergz[0].ojom230ae1" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 38 , rtdwDataFieldNames ) ; int k0 ;
mxSetFieldByNumber ( rtdwData , 0 , 35 , mxCreateUninitNumericMatrix ( 1 , 12
* sizeof ( rtDW . au023bergz [ 0 ] . hq0naomli3 ) , mxUINT8_CLASS , mxREAL )
) ; mxSetFieldByNumber ( rtdwData , 0 , 36 , mxCreateUninitNumericMatrix ( 1
, 12 * sizeof ( rtDW . au023bergz [ 0 ] . g1bez0i0y4 ) , mxUINT8_CLASS ,
mxREAL ) ) ; mxSetFieldByNumber ( rtdwData , 0 , 37 ,
mxCreateUninitNumericMatrix ( 1 , 12 * sizeof ( rtDW . au023bergz [ 0 ] .
ojom230ae1 ) , mxUINT8_CLASS , mxREAL ) ) ; mr_UNIFIER_dyn_cacheDataAsMxArray
( rtdwData , 0 , 0 , ( const void * ) & ( rtDW . e3yadhhovi ) , sizeof ( rtDW
. e3yadhhovi ) ) ; mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 1 , (
const void * ) & ( rtDW . esnn32lqad ) , sizeof ( rtDW . esnn32lqad ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . lkiofcx0nc ) , sizeof ( rtDW . lkiofcx0nc ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . d45t54zzh0 ) , sizeof ( rtDW . d45t54zzh0 ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . obz0u22bxk ) , sizeof ( rtDW . obz0u22bxk ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . mtbzqory0k ) , sizeof ( rtDW . mtbzqory0k ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . cv4ea1x5bf ) , sizeof ( rtDW . cv4ea1x5bf ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . p0luwllcwa ) , sizeof ( rtDW . p0luwllcwa ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . momrqi2s1w ) , sizeof ( rtDW . momrqi2s1w ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . jevgaddxph ) , sizeof ( rtDW . jevgaddxph ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) & (
rtDW . dctbywbcef ) , sizeof ( rtDW . dctbywbcef ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) & (
rtDW . iiazkmp3zq ) , sizeof ( rtDW . iiazkmp3zq ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & (
rtDW . pb5bsdxxpa ) , sizeof ( rtDW . pb5bsdxxpa ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & (
rtDW . p4va2j4maz ) , sizeof ( rtDW . p4va2j4maz ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & (
rtDW . ldxzligihn ) , sizeof ( rtDW . ldxzligihn ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & (
rtDW . fb00myaqvg ) , sizeof ( rtDW . fb00myaqvg ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & (
rtDW . hkblkqalfc ) , sizeof ( rtDW . hkblkqalfc ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & (
rtDW . eewvdaqf4r ) , sizeof ( rtDW . eewvdaqf4r ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & (
rtDW . dgwkzgwl00 ) , sizeof ( rtDW . dgwkzgwl00 ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & (
rtDW . lsgiesztth ) , sizeof ( rtDW . lsgiesztth ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & (
rtDW . m05sv2n1iq ) , sizeof ( rtDW . m05sv2n1iq ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & (
rtDW . khbxaboxwb ) , sizeof ( rtDW . khbxaboxwb ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & (
rtDW . djzedhv1ik ) , sizeof ( rtDW . djzedhv1ik ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & (
rtDW . luravducvq ) , sizeof ( rtDW . luravducvq ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & (
rtDW . e15temhbyp ) , sizeof ( rtDW . e15temhbyp ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & (
rtDW . jseguf13yy ) , sizeof ( rtDW . jseguf13yy ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & (
rtDW . cfngthrtfc ) , sizeof ( rtDW . cfngthrtfc ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & (
rtDW . k3rxirp2ci ) , sizeof ( rtDW . k3rxirp2ci ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & (
rtDW . nfqrlmtid3 ) , sizeof ( rtDW . nfqrlmtid3 ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & (
rtDW . oa32expm1m ) , sizeof ( rtDW . oa32expm1m ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & (
rtDW . fiq4gqvmys ) , sizeof ( rtDW . fiq4gqvmys ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & (
rtDW . mnbvnpxi3q ) , sizeof ( rtDW . mnbvnpxi3q ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & (
rtDW . mitq3fljz5 ) , sizeof ( rtDW . mitq3fljz5 ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & (
rtDW . lmdux514h1 ) , sizeof ( rtDW . lmdux514h1 ) ) ;
mr_UNIFIER_dyn_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & (
rtDW . ckg5ciehpx ) , sizeof ( rtDW . ckg5ciehpx ) ) ; for ( k0 = 0 ; k0 < 12
; ++ k0 ) { const mwIndex offset0 = k0 ;
mr_UNIFIER_dyn_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 35 , offset0 , &
( rtDW . au023bergz [ k0 ] . hq0naomli3 ) , sizeof ( rtDW . au023bergz [ 0 ]
. hq0naomli3 ) ) ; mr_UNIFIER_dyn_cacheDataToMxArrayWithOffset ( rtdwData , 0
, 36 , offset0 , & ( rtDW . au023bergz [ k0 ] . g1bez0i0y4 ) , sizeof ( rtDW
. au023bergz [ 0 ] . g1bez0i0y4 ) ) ;
mr_UNIFIER_dyn_cacheDataToMxArrayWithOffset ( rtdwData , 0 , 37 , offset0 , &
( rtDW . au023bergz [ k0 ] . ojom230ae1 ) , sizeof ( rtDW . au023bergz [ 0 ]
. ojom230ae1 ) ) ; } mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; }
return ssDW ; } void mr_UNIFIER_dyn_SetDWork ( const mxArray * ssDW ) { (
void ) ssDW ; mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtB ) ,
ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; int k0 ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . e3yadhhovi ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . e3yadhhovi ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . esnn32lqad ) ,
rtdwData , 0 , 1 , sizeof ( rtDW . esnn32lqad ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . lkiofcx0nc ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . lkiofcx0nc ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . d45t54zzh0 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . d45t54zzh0 ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . obz0u22bxk ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . obz0u22bxk ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . mtbzqory0k ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . mtbzqory0k ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . cv4ea1x5bf ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . cv4ea1x5bf ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . p0luwllcwa ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . p0luwllcwa ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . momrqi2s1w ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . momrqi2s1w ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . jevgaddxph ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . jevgaddxph ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . dctbywbcef ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . dctbywbcef ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . iiazkmp3zq ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . iiazkmp3zq ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . pb5bsdxxpa ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . pb5bsdxxpa ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . p4va2j4maz ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . p4va2j4maz ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . ldxzligihn ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . ldxzligihn ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . fb00myaqvg ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . fb00myaqvg ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . hkblkqalfc ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . hkblkqalfc ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . eewvdaqf4r ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . eewvdaqf4r ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . dgwkzgwl00 ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . dgwkzgwl00 ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . lsgiesztth ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . lsgiesztth ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . m05sv2n1iq ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . m05sv2n1iq ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . khbxaboxwb ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . khbxaboxwb ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . djzedhv1ik ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . djzedhv1ik ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . luravducvq ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . luravducvq ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . e15temhbyp ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . e15temhbyp ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . jseguf13yy ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . jseguf13yy ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . cfngthrtfc ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . cfngthrtfc ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . k3rxirp2ci ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . k3rxirp2ci ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . nfqrlmtid3 ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . nfqrlmtid3 ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . oa32expm1m ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . oa32expm1m ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . fiq4gqvmys ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . fiq4gqvmys ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . mnbvnpxi3q ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . mnbvnpxi3q ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . mitq3fljz5 ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . mitq3fljz5 ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . lmdux514h1 ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . lmdux514h1 ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArray ( ( void * ) & ( rtDW . ckg5ciehpx ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . ckg5ciehpx ) ) ; for ( k0 = 0 ; k0 < 12 ;
++ k0 ) { const mwIndex offset0 = k0 ;
mr_UNIFIER_dyn_restoreDataFromMxArrayWithOffset ( & ( rtDW . au023bergz [ k0
] . hq0naomli3 ) , rtdwData , 0 , 35 , offset0 , sizeof ( rtDW . au023bergz [
0 ] . hq0naomli3 ) ) ; mr_UNIFIER_dyn_restoreDataFromMxArrayWithOffset ( & (
rtDW . au023bergz [ k0 ] . g1bez0i0y4 ) , rtdwData , 0 , 36 , offset0 ,
sizeof ( rtDW . au023bergz [ 0 ] . g1bez0i0y4 ) ) ;
mr_UNIFIER_dyn_restoreDataFromMxArrayWithOffset ( & ( rtDW . au023bergz [ k0
] . ojom230ae1 ) , rtdwData , 0 , 37 , offset0 , sizeof ( rtDW . au023bergz [
0 ] . ojom230ae1 ) ) ; } } } mxArray *
mr_UNIFIER_dyn_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 2 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 2 ] = { "Scope" , "Scope" , } ; static const char_T *
blockPath [ 2 ] = { "UNIFIER_dyn/UNIFIER OBM1/Aero/aeroF" ,
"UNIFIER_dyn/UNIFIER OBM1/Aero/aeroM" , } ; static const int reason [ 2 ] = {
0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 2 ; ++ ( subs [ 0 ] ) ) {
subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 70 ) ; ssSetNumU ( rtS , 1
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 1 ) ;
ssSetNumBlocks ( rtS , 673 ) ; ssSetNumBlockIO ( rtS , 62 ) ;
ssSetNumBlockParams ( rtS , 789 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3469205189U ) ;
ssSetChecksumVal ( rtS , 1 , 2159496850U ) ; ssSetChecksumVal ( rtS , 2 ,
2886346932U ) ; ssSetChecksumVal ( rtS , 3 , 3540084195U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; const int_T inportDataTypeIdx
[ ] = { 0 } ; const int_T inportDims [ ] = { 1 , 1 } ; const int_T
inportComplex [ ] = { 0 } ; const int_T inportInterpoFlag [ ] = { 1 } ; const
int_T inportContinuous [ ] = { 0 } ; rt_modelMapInfoPtr = & ( rt_dataMapInfo
. mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ; executionInfo ->
gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_ . numFrWksBlocks
= 0 ; executionInfo -> gblObjects_ . numModelInputs = 1 ; executionInfo ->
gblObjects_ . numRootInportBlks = 1 ; executionInfo -> gblObjects_ .
inportDataTypeIdx = ( int_T * ) calloc ( 1 , sizeof ( int_T ) ) ; memcpy (
executionInfo -> gblObjects_ . inportDataTypeIdx , inportDataTypeIdx , sizeof
( inportDataTypeIdx ) ) ; executionInfo -> gblObjects_ . inportDims = ( int_T
* ) calloc ( 2 * 1 , sizeof ( int_T ) ) ; memcpy ( executionInfo ->
gblObjects_ . inportDims , inportDims , sizeof ( inportDims ) ) ;
executionInfo -> gblObjects_ . inportComplex = ( int_T * ) calloc ( 1 ,
sizeof ( int_T ) ) ; memcpy ( executionInfo -> gblObjects_ . inportComplex ,
inportComplex , sizeof ( inportComplex ) ) ; executionInfo -> gblObjects_ .
inportInterpoFlag = ( int_T * ) calloc ( 1 , sizeof ( int_T ) ) ; memcpy (
executionInfo -> gblObjects_ . inportInterpoFlag , inportInterpoFlag , sizeof
( inportInterpoFlag ) ) ; executionInfo -> gblObjects_ . inportContinuous = (
int_T * ) calloc ( 1 , sizeof ( int_T ) ) ; memcpy ( executionInfo ->
gblObjects_ . inportContinuous , inportContinuous , sizeof ( inportContinuous
) ) ; ( void ) memset ( ( char_T * ) rtS , 0 , sizeof ( SimStruct ) ) ; (
void ) memset ( ( char_T * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
( void ) memset ( ( char_T * ) & blkInfo2 , 0 , sizeof ( struct _ssBlkInfo2 )
) ; ( void ) memset ( ( char_T * ) & blkInfoSLSize , 0 , sizeof ( struct
_ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr ( rtS , & blkInfo2 ) ;
ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ; ssSetMdlInfoPtr ( rtS , &
mdlInfo ) ; ssSetExecutionInfo ( rtS , executionInfo ) ; slsaAllocOPModelData
( rtS ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static time_T
mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [ NSAMPLE_TIMES ] ;
static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T mdlSampleHits [
NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ;
static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static
time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i
< NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ;
mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } }
ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , &
mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ;
ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , &
mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr ( rtS , &
mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS , &
mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; } { ssSetU (
rtS , ( ( void * ) & rtU ) ) ; rtU . p1y0j2wmyr = 0.0 ; } { ssSetY ( rtS , &
rtY ) ; ( void ) memset ( & rtY , 0 , sizeof ( ExtY ) ) ;
ssSetWorkSizeInBytes ( rtS , sizeof ( rtY ) , "YOut" ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 33 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
UNIFIER_dyn_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "UNIFIER_dyn" ) ;
ssSetPath ( rtS , "UNIFIER_dyn" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 0.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; { static void * rt_LoggedOutputSignalPtrs [ ] = { & rtY .
ekh2fh00tc [ 0 ] } ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( (
LogSignalPtrsType ) rt_LoggedOutputSignalPtrs ) ) ; } { static int_T
rt_LoggedOutputWidths [ ] = { 70 } ; static int_T
rt_LoggedOutputNumDimensions [ ] = { 1 } ; static int_T
rt_LoggedOutputDimensions [ ] = { 70 } ; static boolean_T
rt_LoggedOutputIsVarDims [ ] = { 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) } ; static int_T
rt_LoggedCurrentSignalDimensionsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_LoggedOutputDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_LoggedOutputComplexSignals [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T *
rt_LoggedOutputLabels [ ] = { "" } ; static const char_T *
rt_LoggedOutputBlockNames [ ] = { "UNIFIER_dyn/Out1" } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedOutputSignalInfo [ ] = { { 1 , rt_LoggedOutputWidths ,
rt_LoggedOutputNumDimensions , rt_LoggedOutputDimensions ,
rt_LoggedOutputIsVarDims , rt_LoggedCurrentSignalDimensions ,
rt_LoggedCurrentSignalDimensionsSize , rt_LoggedOutputDataTypeIds ,
rt_LoggedOutputComplexSignals , ( NULL ) , rt_LoggingPreprocessingFcnPtrs , {
rt_LoggedOutputLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert , ( NULL ) } } ; rtliSetLogYSignalInfo (
ssGetRTWLogInfo ( rtS ) , rt_LoggedOutputSignalInfo ) ;
rt_LoggedCurrentSignalDimensions [ 0 ] = & rt_LoggedOutputWidths [ 0 ] ; }
rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "tmp_raccel_yout1" ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 0.2 ) ; ssSetMinStepSize ( rtS
, 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS
, 0 ) ; ssSetMaxStepSize ( rtS , 0.2 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
3469205189U ) ; ssSetChecksumVal ( rtS , 1 , 2159496850U ) ; ssSetChecksumVal
( rtS , 2 , 2886346932U ) ; ssSetChecksumVal ( rtS , 3 , 3540084195U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 20 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = &
rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = &
rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = &
rtAlwaysEnabled ; systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = &
rtAlwaysEnabled ; systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_UNIFIER_dyn_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP (
rtS , mr_UNIFIER_dyn_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_UNIFIER_dyn_SetDWork ) ; rtP . au023bergz . Saturation_UpperSat = rtInf ;
rtP . au023bergz . Saturation1_UpperSat_o3uhb5q0dz = rtInf ; rtP . au023bergz
. Saturation_UpperSat_dzx4r24qqm = rtInf ; rt_RapidReadMatFileAndUpdateParams
( rtS ) ; if ( ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID1 ( tid ) ; }
