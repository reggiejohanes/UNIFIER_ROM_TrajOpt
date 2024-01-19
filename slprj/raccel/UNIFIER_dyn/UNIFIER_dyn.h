#ifndef RTW_HEADER_UNIFIER_dyn_h_
#define RTW_HEADER_UNIFIER_dyn_h_
#ifndef UNIFIER_dyn_COMMON_INCLUDES_
#define UNIFIER_dyn_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "slexec_parallel.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "UNIFIER_dyn_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rt_nonfinite.h"
#define MODEL_NAME UNIFIER_dyn
#define NSAMPLE_TIMES (2) 
#define NINPUTS (1)       
#define NOUTPUTS (70)     
#define NBLOCKIO (62) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T gbstdhmylq ; } bquln0nszd ; typedef struct { real32_T
ijneevr0hx [ 3 ] ; } ji3ndkntu1 ; typedef struct { real32_T kz2ejerpof [ 3 ]
; } ji3ndkntu1y ; typedef struct { real32_T m05clr3gxy [ 3 ] ; } ji3ndkntu1ys
; typedef struct { real32_T m5kvx1lnef [ 3 ] ; } ji3ndkntu1ys2 ; typedef
struct { real32_T omlkzp34xv [ 3 ] ; } ji3ndkntu1ys25k ; typedef struct {
real_T aqav5cdmuv [ 9 ] ; real32_T fai5wajm52 [ 3 ] ; } frwhndjhji ; typedef
struct { uint32_T hq0naomli3 ; uint32_T g1bez0i0y4 ; uint32_T ojom230ae1 [ 2
] ; } iuffgcvqdz ; typedef struct { real_T noeiauttpl [ 3 ] ; real_T
jefg5cifsj ; real_T l3mgpdtrrg [ 3 ] ; real_T kunmel5bx4 [ 16 ] ; real_T
mgyjrcfqfu [ 16 ] ; real_T cyv21phhbm [ 3 ] ; real_T czxnr0doyy [ 3 ] ;
real_T kqrxmtokjd [ 9 ] ; real_T bjhstbmrsn ; real_T osqwflveuv ; real_T
bp0afaxpp5 ; real_T j1stuyzs1t [ 3 ] ; real_T hzhdx3sz5v [ 3 ] ; real_T
fp54rsi3hk [ 12 ] ; real_T omkpqlajlz [ 3 ] ; real_T gfknqoynom ; real_T
orlelyhfjl ; real_T p1lfhtknc0 [ 12 ] ; real_T nluycx3bh3 [ 12 ] ; real_T
jltpjpl4zp [ 36 ] ; real_T etlvxwxtcy [ 12 ] ; real_T fqp13muoyo [ 36 ] ;
real_T bftm5ocvno [ 12 ] ; real_T eljuwfhp1f [ 12 ] ; uint32_T nhcvscc4t0 [
16 ] ; uint32_T pmh50qaazg [ 16 ] ; uint32_T g53iqbai0i ; uint32_T jqfgyi5cqv
; uint32_T bqft1jkk0z ; uint32_T fu5nkfrvvl ; real32_T on23viyejw [ 7 ] ;
real32_T pqjyj5rgda [ 21 ] ; real32_T fpov3sjl4o [ 21 ] ; real32_T bdrmalqcon
[ 48 ] ; real32_T jdsvzdisey [ 3 ] ; real32_T lxkh42xndm [ 3 ] ; real32_T
lcnor15erx [ 3 ] ; real32_T ecjaklyjaq ; real32_T f5f1ypai11 [ 3 ] ; real32_T
ayw0otszrq ; real32_T lkci5wisjr ; real32_T gbccn4rvbj ; real32_T igwg4uissg
; real32_T ejdl4n31el [ 3 ] ; real32_T bavqi0oauu [ 21 ] ; real32_T
kainbdj3jz [ 21 ] ; real32_T bavqi0oauug [ 21 ] ; real32_T kainbdj3jzn [ 21 ]
; real32_T kainbdj3jznl [ 48 ] ; real32_T jet1i0an5d [ 14 ] ; real32_T
crx1qgibvo [ 14 ] ; real32_T dzpd4knetl [ 16 ] ; real32_T jet1i0an5do [ 16 ]
; real32_T crx1qgibvon [ 16 ] ; frwhndjhji au023bergz [ 12 ] ;
ji3ndkntu1ys25k jz0qdcsmmmwh5rk [ 7 ] ; ji3ndkntu1ys2 jz0qdcsmmmwh5 [ 7 ] ;
ji3ndkntu1ys jz0qdcsmmmwh [ 16 ] ; ji3ndkntu1y jz0qdcsmmmw [ 14 ] ;
ji3ndkntu1 jz0qdcsmmm [ 16 ] ; bquln0nszd p5rpnypkdo [ 12 ] ; } B ; typedef
struct { real_T e3yadhhovi [ 9 ] ; struct { void * AQHandles ; } mw5cjkjcde ;
struct { void * LoggedData [ 3 ] ; } flhwc3z3tt ; struct { void * LoggedData
[ 3 ] ; } nw45trtl3m ; uint32_T esnn32lqad [ 5 ] ; uint32_T lkiofcx0nc [ 5 ]
; uint32_T d45t54zzh0 [ 5 ] ; uint32_T obz0u22bxk [ 2 ] ; uint32_T mtbzqory0k
[ 2 ] ; uint32_T cv4ea1x5bf [ 2 ] ; uint32_T p0luwllcwa [ 5 ] ; uint32_T
momrqi2s1w [ 5 ] ; uint32_T jevgaddxph [ 5 ] ; uint32_T dctbywbcef [ 2 ] ;
uint32_T iiazkmp3zq [ 2 ] ; uint32_T pb5bsdxxpa [ 2 ] ; uint32_T p4va2j4maz [
16 ] ; uint32_T ldxzligihn [ 16 ] ; uint32_T fb00myaqvg [ 16 ] ; uint32_T
hkblkqalfc [ 16 ] ; uint32_T eewvdaqf4r [ 16 ] ; uint32_T dgwkzgwl00 [ 16 ] ;
uint32_T lsgiesztth [ 16 ] ; uint32_T m05sv2n1iq [ 16 ] ; uint32_T khbxaboxwb
; uint32_T djzedhv1ik ; uint32_T luravducvq [ 16 ] ; uint32_T e15temhbyp [ 16
] ; uint32_T jseguf13yy ; uint32_T cfngthrtfc ; uint32_T k3rxirp2ci ;
uint32_T nfqrlmtid3 ; uint32_T oa32expm1m ; uint32_T fiq4gqvmys ; uint32_T
mnbvnpxi3q ; uint32_T mitq3fljz5 [ 2 ] ; int8_T lmdux514h1 ; int8_T
ckg5ciehpx ; iuffgcvqdz au023bergz [ 12 ] ; } DW ; typedef struct { real_T
p1y0j2wmyr ; } ExtU ; typedef struct { real_T ekh2fh00tc [ 70 ] ; } ExtY ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
opnvvzhshw_ { real_T K_slope_Gain ; } ; struct j53mv3qbck_ { real32_T
Constant1_Value ; } ; struct j53mv3qbck1_ { real32_T Constant1_Value ; } ;
struct j53mv3qbck1cop_ { real_T Constant_Value ; real32_T
Constant_Value_bcqheaf40z ; } ; struct dlxjkzkckz_ { real_T Constant_Value ;
real32_T Constant_Value_lhjgiuieqz ; } ; struct ou5c4vmqt0_ { real_T
actf2T_Gain ; real_T Saturation2_UpperSat ; real_T Saturation2_LowerSat ;
real_T Switch1_Threshold ; real_T Gain1_Gain ; real_T Saturation_UpperSat ;
real_T Saturation_LowerSat ; real_T Gain2_Gain ; real_T Saturation1_UpperSat
; real_T Saturation1_LowerSat ; real_T Gain_Gain ; real_T
Saturation1_UpperSat_o3uhb5q0dz ; real_T Saturation1_LowerSat_cob1qvjvl1 ;
real_T Gain3_Gain ; real_T Saturation_UpperSat_dzx4r24qqm ; real_T
Saturation_LowerSat_lu14kynpbe ; real_T Gain3_Gain_kiqvbbswpr ; real_T
Gain5_Gain ; real_T Saturation3_UpperSat ; real_T Saturation3_LowerSat ;
real_T Constant3_Value ; real_T Constant_Value ; real_T Constant1_Value ;
real_T DEP_incidence_Value ; real_T Constant_Value_e5dci5j5wh ; uint32_T
T2rpm_maxIndex [ 2 ] ; } ; struct P_ { struct_jutHZYEwOoNeidUZKCLQ8B dp_VTAIL
; struct_X4VfLKyPh2o5xFDym0ZDqD dp_VTAIL_INDUCED ;
struct_IzJ4J0FtAuhnGd5tRgSyHE dp_WING_root ; struct_yWIZFWBbymsS8L1W0LWVH
dp_WING_tip ; struct_nC6b04CeB5t4pOaoQVXKo dp_DEP ;
struct_OvGmMrPqfNtzpqofYdArSB dp_HTU ; struct_ledTFd3zOA1QjIJZGqbRtH
dp_FUSE_FIN ; real_T I [ 9 ] ; real_T S ; real_T m ; real_T xyz_DEP [ 36 ] ;
real_T xyz_cg [ 3 ] ; real32_T vtail_nodes [ 48 ] ; real32_T wing_nodes [ 42
] ; real_T Gain1_Gain ; real_T Gain2_Gain ; real_T Constant_Value ; real_T
zeta_Value [ 12 ] ; real_T testinput_Value [ 19 ] ; real_T
SeaLevelTemperature_Value ; real_T Limitaltitudetotroposhere_UpperSat ;
real_T Limitaltitudetotroposhere_LowerSat ; real_T LapseRate_Gain ; real_T
uT0_Gain ; real_T Constant_Value_mlc0xem4a2 ; real_T
AltitudeofTroposphere_Value ; real_T LimitaltitudetoStratosphere_UpperSat ;
real_T LimitaltitudetoStratosphere_LowerSat ; real_T gR_Gain ; real_T
rho0_Gain ; real_T Constant1_Value ; real_T Constant_Value_ll1hqpke5l ;
real_T Constant_Value_exkenlsy3u [ 3 ] ; real_T Constant_Value_izgjegg0j4 [ 8
] ; real_T Constant1_Value_meik51c4df [ 8 ] ; real_T Saturation_UpperSat ;
real_T Saturation_LowerSat ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T Saturation2_UpperSat ; real_T
Saturation2_LowerSat ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Saturation6_UpperSat ; real_T
Saturation6_LowerSat ; real_T Saturation4_UpperSat ; real_T
Saturation4_LowerSat ; real_T Constant8_Value [ 16 ] ; real_T
Constant_Value_kx5dv3qh2a [ 8 ] ; real_T Constant1_Value_dxjow4r24m [ 8 ] ;
real_T Constant8_Value_cr0us2qlbv [ 16 ] ; real_T Constant_Value_lkalxliguo [
21 ] ; real_T Constant8_Value_dj5ncyqbcf [ 5 ] ; real_T
Constant8_Value_hy4ct0z05y [ 2 ] ; real_T Constant_Value_bchqth404u [ 21 ] ;
real_T Constant8_Value_kwpfdqsyq1 [ 5 ] ; real_T Constant8_Value_m3ahup3xji [
2 ] ; real_T Constant_Value_ec1rbuxqhz ; real_T Gain_Gain ; real_T
Constant2_Value [ 9 ] ; real_T Gain_Gain_jhzuipt41u [ 12 ] ; real_T
Constant2_Value_lirfr5mubp [ 12 ] ; real_T Inclination_Value ; real_T
Constant_Value_kr4kbsbfsk ; real_T Multiply_Gain ; real_T
uDLookupTable1_tableData [ 2 ] ; real_T uDLookupTable1_bp01Data [ 2 ] ;
real_T Constant_Value_dtyrktojcw ; real_T Gain_Gain_gmzj2h1bwx ; real32_T
Gain_Gain_ovou53gniu ; real32_T Gain_Gain_mvu5sy12vu ; real32_T
uDLookupTable_bp01Data [ 6 ] ; real32_T uDLookupTable1_bp01Data_o3lj0rj2gn [
6 ] ; real32_T uDLookupTable2_bp01Data [ 6 ] ; real32_T Gain2_Gain_a2ertcz4ne
; real32_T Gain3_Gain ; real32_T Prelookup_BreakpointsData [ 13 ] ; real32_T
Prelookup1_BreakpointsData [ 15 ] ; real32_T Constant_Value_dggd0yls2s ;
real32_T Gain_Gain_ngpzxxezsf ; real32_T Constant7_Value [ 16 ] ; real32_T
Constant1_Value_jtw2pfsmen [ 48 ] ; real32_T NodePoints_Value [ 21 ] ;
real32_T NodePoints_Value_iel3jxerxr [ 21 ] ; real32_T
Constant1_Value_fodj5rxow1 ; real32_T extra_drag_Value ; real32_T
gear_drag_Value ; real32_T Gain_Gain_jabdopn2nb ; uint32_T
InterpolationUsingPrelookup1_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_goowtl1isu [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex_gcrts0kvey [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_hjcwwxhrb2 [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex_hmktoionv2 [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_eey1a1evp1 [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex_inqyzx0bkv [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_jgranlzjdr [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex_m1elfxqfrm [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_hgrobm0ojs [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex_kj53253sjw [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_e5mnlcnsgz [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex_ic1jmobgnb [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_fv3gcuk1rh [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex_joswbgit4t [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_gotbz31jut [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex_iyvebvf0hr [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_i1e0soyo1i [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex_axhtziqjmb [ 4 ] ; uint32_T
V_induced_dimSize [ 4 ] ; uint32_T alpha_induced_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_kbujhpqt4p [ 3 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_it0njeibeo [ 3 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_h5lelt5fk5 [ 3 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_eonzf4khoz [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex_ldg1ql3t42 [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_m1b3rqhw3t [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex_l0p20lh4bw [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_ewytp2yzsl [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex_fa5a0eaqeu [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_frefplnidc [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex_onrk5innhu [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_kh3x5zfkli [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex_leuk5avc1v [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_licoblhfnw [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex_eshiygopfu [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_kcrhpwfjfn [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex_brkchxcoij [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_gllaksp5ia [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex_ny0js42i4o [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_npg5h2ocwn [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex_lpfi2gwlwq [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_lnthg1rnjp [ 3 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_brj4qiei0w [ 3 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_nqfnlt53ag [ 3 ] ; uint32_T
Plookup_maxIndex [ 2 ] ; ou5c4vmqt0 au023bergz ; dlxjkzkckz oeyei2gsmn ;
j53mv3qbck1cop jz0qdcsmmmwh5r ; j53mv3qbck1 jz0qdcsmmmw ; j53mv3qbck
jz0qdcsmmm ; opnvvzhshw p5rpnypkdo ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern ExtU rtU
; extern ExtY rtY ; extern P rtP ; extern mxArray * mr_UNIFIER_dyn_GetDWork (
) ; extern void mr_UNIFIER_dyn_SetDWork ( const mxArray * ssDW ) ; extern
mxArray * mr_UNIFIER_dyn_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * UNIFIER_dyn_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
