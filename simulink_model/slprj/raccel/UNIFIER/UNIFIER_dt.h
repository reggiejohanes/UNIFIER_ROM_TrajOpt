#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_ledTFd3zOA1QjIJZGqbRtH" , 17 , 4928 } , {
"struct_X4VfLKyPh2o5xFDym0ZDqD" , 18 , 224352 } , {
"struct_jutHZYEwOoNeidUZKCLQ8B" , 19 , 449600 } , {
"struct_IzJ4J0FtAuhnGd5tRgSyHE" , 20 , 210216 } , {
"struct_yWIZFWBbymsS8L1W0LWVH" , 21 , 117792 } , {
"struct_fnuCCPniuRknyr94YhzxZ" , 22 , 32376 } , {
"struct_e4KmvBjsHkMILSnyqn1SNH" , 23 , 304 } , {
"struct_nC6b04CeB5t4pOaoQVXKo" , 24 , 33784 } , {
"struct_jgnmaTiP1kwpD95SOjXYyE" , 25 , 176 } , {
"struct_OvGmMrPqfNtzpqofYdArSB" , 26 , 9136 } , {
"struct_rFkegYH72KGOtqmd7lp2k" , 27 , 8 } , { "uint64_T" , 28 , 8 } , {
"int64_T" , 29 , 8 } , { "uint_T" , 30 , 32 } , { "char_T" , 31 , 8 } , {
"uchar_T" , 32 , 8 } , { "time_T" , 33 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( struct_ledTFd3zOA1QjIJZGqbRtH ) , sizeof (
struct_X4VfLKyPh2o5xFDym0ZDqD ) , sizeof ( struct_jutHZYEwOoNeidUZKCLQ8B ) ,
sizeof ( struct_IzJ4J0FtAuhnGd5tRgSyHE ) , sizeof (
struct_yWIZFWBbymsS8L1W0LWVH ) , sizeof ( struct_fnuCCPniuRknyr94YhzxZ ) ,
sizeof ( struct_e4KmvBjsHkMILSnyqn1SNH ) , sizeof (
struct_nC6b04CeB5t4pOaoQVXKo ) , sizeof ( struct_jgnmaTiP1kwpD95SOjXYyE ) ,
sizeof ( struct_OvGmMrPqfNtzpqofYdArSB ) , sizeof (
struct_rFkegYH72KGOtqmd7lp2k ) , sizeof ( uint64_T ) , sizeof ( int64_T ) ,
sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_ledTFd3zOA1QjIJZGqbRtH" , "struct_X4VfLKyPh2o5xFDym0ZDqD" ,
"struct_jutHZYEwOoNeidUZKCLQ8B" , "struct_IzJ4J0FtAuhnGd5tRgSyHE" ,
"struct_yWIZFWBbymsS8L1W0LWVH" , "struct_fnuCCPniuRknyr94YhzxZ" ,
"struct_e4KmvBjsHkMILSnyqn1SNH" , "struct_nC6b04CeB5t4pOaoQVXKo" ,
"struct_jgnmaTiP1kwpD95SOjXYyE" , "struct_OvGmMrPqfNtzpqofYdArSB" ,
"struct_rFkegYH72KGOtqmd7lp2k" , "uint64_T" , "int64_T" , "uint_T" , "char_T"
, "uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions [ ] = { {
( char_T * ) ( & rtB . exyupufjt5 [ 0 ] ) , 0 , 0 , 467 } , { ( char_T * ) (
& rtB . pgacreyak0 ) , 7 , 0 , 36 } , { ( char_T * ) ( & rtB . jrm5mulpgo [ 0
] ) , 1 , 0 , 356 } , { ( char_T * ) ( & rtB . gtlyl45i3j [ 0 ] ) , 3 , 0 ,
2590 } , { ( char_T * ) ( & rtB . n3u1rxuv5j ) , 8 , 0 , 5 } , { ( char_T * )
( & rtB . hztlwupntw . h11nwvgfxj [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) (
& rtB . n1ybyykngv . h11nwvgfxj [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . jek5zaxern . gz0squozgl [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . nikuyjvr0y . gz0squozgl [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . enohy5yaap . gz0squozgl [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . pookhwl2ri . hr4wpt01um [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . hl5ibqcu3w . hr4wpt01um [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . dffuptpbcz . e1wak2s0nn [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . bd32gk0ocy . e1wak2s0nn [ 0 ] ) , 3 , 0 , 509 } , { ( char_T * ) ( &
rtB . leuhdrxpbe . ggmvjtadg3 [ 0 ] ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtB
. csf3emrtxr . ggmvjtadg3 [ 0 ] ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtB .
jvaexa3o5a . ggmvjtadg3 [ 0 ] ) , 0 , 0 , 6 } , { ( char_T * ) ( & rtB .
adqmzv0sx0 [ 11 ] . ibnqksi5kc ) , 0 , 0 , 16 } , { ( char_T * ) ( & rtB .
adqmzv0sx0 [ 11 ] . aox0khugvh [ 0 ] ) , 1 , 0 , 3 } , { ( char_T * ) ( & rtB
. adqmzv0sx0 [ 11 ] . cgxtlo5ezj ) , 8 , 0 , 2 } , { ( char_T * ) ( & rtB .
pcwoeb21pm . c1tiif3ujm ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB .
fthork0k0x2 . c1tiif3ujm ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB .
nyqetrz43uqkkpi [ 6 ] . jqzydkhuci [ 0 ] ) , 1 , 0 , 6 } , { ( char_T * ) ( &
rtB . nyqetrz43uqkk [ 6 ] . d2kygac014 [ 0 ] ) , 1 , 0 , 6 } , { ( char_T * )
( & rtB . nyqetrz43uqk [ 15 ] . f5l1thfo3b [ 0 ] ) , 1 , 0 , 6 } , { ( char_T
* ) ( & rtB . nyqetrz43uq [ 13 ] . g2bz2muoaw [ 0 ] ) , 1 , 0 , 6 } , { (
char_T * ) ( & rtB . nyqetrz43u [ 15 ] . kl452g3br4 [ 0 ] ) , 1 , 0 , 6 } , {
( char_T * ) ( & rtDW . g540jxiiax [ 0 ] ) , 0 , 0 , 2509 } , { ( char_T * )
( & rtDW . c4dytoevnt . LoggedData ) , 11 , 0 , 145 } , { ( char_T * ) ( &
rtDW . ml2zybgolh ) , 6 , 0 , 6 } , { ( char_T * ) ( & rtDW . iinforci3b [ 0
] ) , 7 , 0 , 217 } , { ( char_T * ) ( & rtDW . l1l2gip32s . Tail [ 0 ] ) ,
10 , 0 , 159 } , { ( char_T * ) ( & rtDW . cfvgbkovvu ) , 2 , 0 , 4 } , { (
char_T * ) ( & rtDW . oek5idxhme ) , 3 , 0 , 6 } , { ( char_T * ) ( & rtDW .
cg1cpca1ek ) , 8 , 0 , 18 } , { ( char_T * ) ( & rtDW . hztlwupntw .
apnlfrnpo3 ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . hztlwupntw .
ovvez5xelu ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . hztlwupntw .
dtz1ggkdpo ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . n1ybyykngv .
apnlfrnpo3 ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . n1ybyykngv .
ovvez5xelu ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . n1ybyykngv .
dtz1ggkdpo ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . jek5zaxern .
datl4fzkmc ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . jek5zaxern .
op350srgbo ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . jek5zaxern .
eiaswshrvs ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . nikuyjvr0y .
datl4fzkmc ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . nikuyjvr0y .
op350srgbo ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . nikuyjvr0y .
eiaswshrvs ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . enohy5yaap .
datl4fzkmc ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . enohy5yaap .
op350srgbo ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . enohy5yaap .
eiaswshrvs ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . pookhwl2ri .
aquds3y3qy ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . pookhwl2ri .
b4sgpwle2l ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . pookhwl2ri .
bfcbslmbdi ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . hl5ibqcu3w .
aquds3y3qy ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . hl5ibqcu3w .
b4sgpwle2l ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . hl5ibqcu3w .
bfcbslmbdi ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . dffuptpbcz .
i2hnwisoi1 ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . dffuptpbcz .
fkmv4gfkl0 ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . dffuptpbcz .
e3ed3ljbyn ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . bd32gk0ocy .
i2hnwisoi1 ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . bd32gk0ocy .
fkmv4gfkl0 ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . bd32gk0ocy .
e3ed3ljbyn ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . leuhdrxpbe .
ckwkdnls5w ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . leuhdrxpbe .
aqynsdznmr ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . leuhdrxpbe .
onahgr5syd ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . csf3emrtxr .
ckwkdnls5w ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . csf3emrtxr .
aqynsdznmr ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . csf3emrtxr .
onahgr5syd ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . jvaexa3o5a .
ckwkdnls5w ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . jvaexa3o5a .
aqynsdznmr ) , 3 , 0 , 1 } , { ( char_T * ) ( & rtDW . jvaexa3o5a .
onahgr5syd ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . adqmzv0sx0 [ 11 ] .
adrjjytrwd ) , 7 , 0 , 4 } , { ( char_T * ) ( & rtDW . adqmzv0sx0 [ 11 ] .
kd3fwxo3ke ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . pcwoeb21pm .
gxcgpda4hi ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . pcwoeb21pm .
jifjbgbgqy ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . fthork0k0x2 .
gxcgpda4hi ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . fthork0k0x2 .
jifjbgbgqy ) , 8 , 0 , 1 } } ; static DataTypeTransitionTable rtBTransTable =
{ 77U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { {
( char_T * ) ( & rtP . dp_VTAIL ) , 19 , 0 , 1 } , { ( char_T * ) ( & rtP .
dp_VTAIL_INDUCED ) , 18 , 0 , 1 } , { ( char_T * ) ( & rtP . dp_WING_root ) ,
20 , 0 , 1 } , { ( char_T * ) ( & rtP . dp_WING_tip ) , 21 , 0 , 1 } , { (
char_T * ) ( & rtP . dp_DEP ) , 24 , 0 , 1 } , { ( char_T * ) ( & rtP .
dp_HTU ) , 26 , 0 , 1 } , { ( char_T * ) ( & rtP . dp_FUSE_FIN ) , 17 , 0 , 1
} , { ( char_T * ) ( & rtP . DEP_INTEG_IC ) , 0 , 0 , 88 } , { ( char_T * ) (
& rtP . vtail_nodes [ 0 ] ) , 1 , 0 , 90 } , { ( char_T * ) ( & rtP .
CompareToConstant_const ) , 0 , 0 , 69 } , { ( char_T * ) ( & rtP .
UDPSend1_remotePort ) , 6 , 0 , 15 } , { ( char_T * ) ( & rtP .
DiscreteWindGustModel1_Gx ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtP . x_Y0 ) ,
0 , 0 , 665 } , { ( char_T * ) ( & rtP . Limitaltitudetotroposhere_UpperSat )
, 1 , 0 , 165 } , { ( char_T * ) ( & rtP .
InterpolationUsingPrelookup1_dimSize [ 0 ] ) , 7 , 0 , 220 } , { ( char_T * )
( & rtP . Constant_Value_l3yr2jaxah ) , 8 , 0 , 6 } , { ( char_T * ) ( & rtP
. Constant_Value_ecr3ukwupu [ 0 ] ) , 3 , 0 , 555 } , { ( char_T * ) ( & rtP
. adqmzv0sx0 . EM_I ) , 0 , 0 , 32 } , { ( char_T * ) ( & rtP . adqmzv0sx0 .
T2rpm_maxIndex [ 0 ] ) , 7 , 0 , 2 } , { ( char_T * ) ( & rtP . adqmzv0sx0 .
Memory_InitialCondition ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP . pcwoeb21pm
. x_Y0 ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtP . fthork0k0x2 . x_Y0 ) , 0 ,
0 , 3 } , { ( char_T * ) ( & rtP . fchchnbmez . Constant_Value ) , 0 , 0 , 1
} , { ( char_T * ) ( & rtP . fchchnbmez . Constant_Value_nflcmvsqzo ) , 1 , 0
, 1 } , { ( char_T * ) ( & rtP . nyqetrz43uqkkp . Constant_Value ) , 0 , 0 ,
1 } , { ( char_T * ) ( & rtP . nyqetrz43uqkkp . Constant_Value_dl1cryfboe ) ,
1 , 0 , 1 } , { ( char_T * ) ( & rtP . nyqetrz43uq . Constant1_Value ) , 1 ,
0 , 1 } , { ( char_T * ) ( & rtP . nyqetrz43u . Constant1_Value ) , 1 , 0 , 1
} } ; static DataTypeTransitionTable rtPTransTable = { 28U , rtPTransitions }
;
