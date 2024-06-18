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
"struct_OvGmMrPqfNtzpqofYdArSB" , 26 , 9136 } , { "uint64_T" , 27 , 8 } , {
"int64_T" , 28 , 8 } , { "uint_T" , 29 , 32 } , { "char_T" , 30 , 8 } , {
"uchar_T" , 31 , 8 } , { "time_T" , 32 , 8 } } ; static uint_T
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
sizeof ( struct_OvGmMrPqfNtzpqofYdArSB ) , sizeof ( uint64_T ) , sizeof (
int64_T ) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) ,
sizeof ( time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T"
, "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"struct_ledTFd3zOA1QjIJZGqbRtH" , "struct_X4VfLKyPh2o5xFDym0ZDqD" ,
"struct_jutHZYEwOoNeidUZKCLQ8B" , "struct_IzJ4J0FtAuhnGd5tRgSyHE" ,
"struct_yWIZFWBbymsS8L1W0LWVH" , "struct_fnuCCPniuRknyr94YhzxZ" ,
"struct_e4KmvBjsHkMILSnyqn1SNH" , "struct_nC6b04CeB5t4pOaoQVXKo" ,
"struct_jgnmaTiP1kwpD95SOjXYyE" , "struct_OvGmMrPqfNtzpqofYdArSB" ,
"uint64_T" , "int64_T" , "uint_T" , "char_T" , "uchar_T" , "time_T" } ;
static DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB .
bzx2uazgws [ 0 ] ) , 0 , 0 , 249 } , { ( char_T * ) ( & rtB . nhcvscc4t0 [ 0
] ) , 7 , 0 , 36 } , { ( char_T * ) ( & rtB . on23viyejw [ 0 ] ) , 1 , 0 ,
347 } , { ( char_T * ) ( & rtB . au023bergz [ 11 ] . aqav5cdmuv [ 0 ] ) , 0 ,
0 , 9 } , { ( char_T * ) ( & rtB . au023bergz [ 11 ] . fai5wajm52 [ 0 ] ) , 1
, 0 , 3 } , { ( char_T * ) ( & rtB . jz0qdcsmmmwh5rk [ 6 ] . omlkzp34xv [ 0 ]
) , 1 , 0 , 3 } , { ( char_T * ) ( & rtB . jz0qdcsmmmwh5 [ 6 ] . m5kvx1lnef [
0 ] ) , 1 , 0 , 3 } , { ( char_T * ) ( & rtB . jz0qdcsmmmwh [ 15 ] .
m05clr3gxy [ 0 ] ) , 1 , 0 , 3 } , { ( char_T * ) ( & rtB . jz0qdcsmmmw [ 13
] . kz2ejerpof [ 0 ] ) , 1 , 0 , 3 } , { ( char_T * ) ( & rtB . jz0qdcsmmm [
15 ] . ijneevr0hx [ 0 ] ) , 1 , 0 , 3 } , { ( char_T * ) ( & rtB . p5rpnypkdo
[ 11 ] . gbstdhmylq ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW . e3yadhhovi [
0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtDW . dvyolrqdzv . AQHandles ) , 11
, 0 , 18 } , { ( char_T * ) ( & rtDW . esnn32lqad [ 0 ] ) , 7 , 0 , 213 } , {
( char_T * ) ( & rtDW . lmdux514h1 ) , 2 , 0 , 2 } , { ( char_T * ) ( & rtDW
. au023bergz [ 11 ] . g1bez0i0y4 ) , 7 , 0 , 4 } } ; static
DataTypeTransitionTable rtBTransTable = { 16U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . dp_VTAIL )
, 19 , 0 , 1 } , { ( char_T * ) ( & rtP . dp_VTAIL_INDUCED ) , 18 , 0 , 1 } ,
{ ( char_T * ) ( & rtP . dp_WING_root ) , 20 , 0 , 1 } , { ( char_T * ) ( &
rtP . dp_WING_tip ) , 21 , 0 , 1 } , { ( char_T * ) ( & rtP . dp_DEP ) , 24 ,
0 , 1 } , { ( char_T * ) ( & rtP . dp_HTU ) , 26 , 0 , 1 } , { ( char_T * ) (
& rtP . dp_FUSE_FIN ) , 17 , 0 , 1 } , { ( char_T * ) ( & rtP . I [ 0 ] ) , 0
, 0 , 69 } , { ( char_T * ) ( & rtP . vtail_nodes [ 0 ] ) , 1 , 0 , 90 } , {
( char_T * ) ( & rtP . Gain1_Gain ) , 0 , 0 , 207 } , { ( char_T * ) ( & rtP
. Gain_Gain_ovou53gniu ) , 1 , 0 , 162 } , { ( char_T * ) ( & rtP .
InterpolationUsingPrelookup1_dimSize [ 0 ] ) , 7 , 0 , 220 } , { ( char_T * )
( & rtP . au023bergz . actf2T_Gain ) , 0 , 0 , 25 } , { ( char_T * ) ( & rtP
. au023bergz . T2rpm_maxIndex [ 0 ] ) , 7 , 0 , 2 } , { ( char_T * ) ( & rtP
. oeyei2gsmn . Constant_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
oeyei2gsmn . Constant_Value_lhjgiuieqz ) , 1 , 0 , 1 } , { ( char_T * ) ( &
rtP . jz0qdcsmmmwh5r . Constant_Value ) , 0 , 0 , 1 } , { ( char_T * ) ( &
rtP . jz0qdcsmmmwh5r . Constant_Value_bcqheaf40z ) , 1 , 0 , 1 } , { ( char_T
* ) ( & rtP . jz0qdcsmmmw . Constant1_Value ) , 1 , 0 , 1 } , { ( char_T * )
( & rtP . jz0qdcsmmm . Constant1_Value ) , 1 , 0 , 1 } , { ( char_T * ) ( &
rtP . p5rpnypkdo . K_slope_Gain ) , 0 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 21U , rtPTransitions } ;
