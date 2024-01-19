#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "UNIFIER_dyn_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 27
#endif
#ifndef SS_INT64
#define SS_INT64 28
#endif
#else
#include "builtin_typeid_types.h"
#include "UNIFIER_dyn.h"
#include "UNIFIER_dyn_capi.h"
#include "UNIFIER_dyn_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 2 , TARGET_STRING (
"UNIFIER_dyn/Ganging/For Each Subsystem" ) , TARGET_STRING ( "u2" ) , 0 , 0 ,
0 , 0 , 0 } , { 1 , 0 , TARGET_STRING ( "UNIFIER_dyn/UNIFIER OBM1/Cast7" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Cast8" ) , TARGET_STRING ( "" ) , 0 , 1 , 2 , 0 , 1
} , { 3 , 0 , TARGET_STRING ( "UNIFIER_dyn/UNIFIER OBM1/Cast9" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 4 , 1 , TARGET_STRING (
"UNIFIER_dyn/Ganging/For Each Subsystem/Tan" ) , TARGET_STRING ( "" ) , 0 , 0
, 2 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Product3" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 1 } , { 6 , 4 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaVtail" ) , TARGET_STRING ( "" ) , 0 , 1 ,
3 , 0 , 0 } , { 7 , 4 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaVtail" ) , TARGET_STRING ( "" ) , 1 , 1 ,
3 , 0 , 0 } , { 8 , 4 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaVtail" ) , TARGET_STRING ( "" ) , 2 , 1 ,
3 , 0 , 0 } , { 9 , 6 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaWIng" ) , TARGET_STRING ( "" ) , 0 , 1 ,
4 , 0 , 0 } , { 10 , 6 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaWIng" ) , TARGET_STRING ( "" ) , 1 , 1 ,
4 , 0 , 0 } , { 11 , 0 , TARGET_STRING ( "UNIFIER_dyn/UNIFIER OBM1/Aero/Sum1"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 0 } , { 13 , 3 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaVtail/Cast" ) , TARGET_STRING ( "" ) , 0
, 1 , 1 , 0 , 1 } , { 14 , 5 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaWIng/Cast" ) , TARGET_STRING ( "" ) , 0 ,
1 , 1 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Gain" ) , TARGET_STRING (
"F" ) , 0 , 1 , 1 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Sum" ) , TARGET_STRING ( ""
) , 0 , 0 , 1 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/additionalDrag/Product1" ) , TARGET_STRING (
"" ) , 0 , 1 , 1 , 0 , 1 } , { 18 , 19 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP" ) , TARGET_STRING ( "" ) , 1 ,
0 , 0 , 0 , 0 } , { 19 , 19 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP" ) , TARGET_STRING ( "" ) , 2 ,
0 , 5 , 0 , 0 } , { 20 , 19 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP" ) , TARGET_STRING ( "" ) , 3 ,
0 , 5 , 0 , 0 } , { 21 , 19 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP" ) , TARGET_STRING ( "" ) , 4 ,
0 , 0 , 0 , 0 } , { 22 , 19 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP" ) , TARGET_STRING ( "" ) , 5 ,
0 , 0 , 0 , 0 } , { 23 , 19 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP" ) , TARGET_STRING ( "" ) , 6 ,
0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/Product1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Gravity/Product" ) , TARGET_STRING ( "F"
) , 0 , 0 , 1 , 0 , 1 } , { 26 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/Gain" ) , TARGET_STRING ( "" ) , 0 ,
0 , 2 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/preLook/Prelookup" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 6 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/preLook/Prelookup" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 1 } , { 29 , 8 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Subsystem/CrossProduct1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 7 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Subsystem/Gain2" ) , TARGET_STRING
( "" ) , 0 , 1 , 7 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Calculate omega_dot/Selector2"
) , TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Subsystem/phidot" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Subsystem/psidot" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Subsystem/thetadot" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Vbxw/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/transform to Inertial axes /Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 9 , 0 , 1 } , { 37 , 7 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Subsystem/CrossProduct1/Cast" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 38 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 0 , 2 , 6 , 0 , 1 } , { 39 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 1 , 0 , 6 , 0 , 1 } , { 40 , 10 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/CrossProduct" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 10 , 0 , 0 } , { 41 , 12 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/w2b" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 10 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 10 , 0 , 0 } , { 43 , 14 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/CrossProduct" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 10 , 0 , 0 } , { 44 , 16 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/w2b" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 10 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 10 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Calculate omega_dot/3x3 Cross Product/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Calculate omega_dot/I x w1/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 9 , 0 , 1 } , { 48 , 18 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Cast" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 49 , 18 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Transpose" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 8 , 0 , 1 } , { 50 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/PropAndMotor/Saturation Dynamic/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 51 , 9 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/CrossProduct/Cast" )
, TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 0 , 2 , 2 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 1 , 1 , 2 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 0 , 2 , 2 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 1 , 1 , 2 , 0 , 1 } , { 56 , 13 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/CrossProduct/Cast"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 0 , 2 , 2 , 0 , 1 } , { 58 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 1 , 1 , 2 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 0 , 2 , 2 , 0 , 1 } , { 60 , 0 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/WingRootPreLookup/Prelookup"
) , TARGET_STRING ( "" ) , 1 , 1 , 2 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 61 , TARGET_STRING ( "UNIFIER_dyn/testinput" ) ,
TARGET_STRING ( "Value" ) , 0 , 11 , 0 } , { 62 , TARGET_STRING (
"UNIFIER_dyn/Ganging/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } ,
{ 63 , TARGET_STRING ( "UNIFIER_dyn/Ganging/zeta" ) , TARGET_STRING ( "Value"
) , 0 , 12 , 0 } , { 64 , TARGET_STRING (
"UNIFIER_dyn/Ganging/For Each Subsystem/K_slope" ) , TARGET_STRING ( "Gain" )
, 0 , 2 , 0 } , { 65 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Altitude of Troposphere" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 66 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 67 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Sea Level  Temperature" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 68 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/1//T0" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 69 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Lapse Rate" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 70 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/g//R" ) , TARGET_STRING ( "Gain"
) , 0 , 2 , 0 } , { 71 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/rho0" ) , TARGET_STRING ( "Gain"
) , 0 , 2 , 0 } , { 72 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 73 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 74 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Limit  altitude  to troposhere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 75 , TARGET_STRING (
"UNIFIER_dyn/ISA Atmosphere Model1/Modelling/Limit  altitude  to troposhere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 76 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaVtail/Constant1" ) , TARGET_STRING (
"Value" ) , 1 , 2 , 0 } , { 77 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Constant" ) , TARGET_STRING
( "Value" ) , 0 , 13 , 0 } , { 78 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Gain" ) , TARGET_STRING (
"Gain" ) , 1 , 2 , 0 } , { 79 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 14 , 0 } , { 80 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 14 , 0 } , { 81 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/Constant7" ) ,
TARGET_STRING ( "Value" ) , 1 , 15 , 0 } , { 82 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/V_induced" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 83 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/alpha_induced" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 84 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/1-D Lookup Table" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 1 , 17 , 0 } , { 85 ,
TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/1-D Lookup Table1" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 1 , 17 , 0 } , { 86 ,
TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/1-D Lookup Table2" ) ,
TARGET_STRING ( "BreakpointsForDimension1" ) , 1 , 17 , 0 } , { 87 ,
TARGET_STRING ( "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 14 , 0 } , { 88 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 14 , 0 } , { 89 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/additionalDrag/Constant1" ) , TARGET_STRING (
"Value" ) , 1 , 2 , 0 } , { 90 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/additionalDrag/extra_drag" ) , TARGET_STRING (
"Value" ) , 1 , 2 , 0 } , { 91 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/additionalDrag/gear_drag" ) , TARGET_STRING (
"Value" ) , 1 , 2 , 0 } , { 92 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/additionalDrag/Gain" ) , TARGET_STRING (
"Gain" ) , 1 , 2 , 0 } , { 93 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/Conversion1/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 94 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/Conversion1/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 95 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/EOMandEnviroment/EOM/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 8 , 0 } , { 96 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 97 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 98 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation1" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 99 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation1" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 100 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation2" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 101 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation2" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 102 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation3" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 103 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation3" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 104 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation4" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 105 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation4" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 106 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation6" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 107 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Actuators/Saturation6" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 108 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 12 , 0 } , { 109 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/Inclination" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 110 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/Gain1" ) , TARGET_STRING ( "Gain" )
, 0 , 2 , 0 } , { 111 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/Gain2" ) , TARGET_STRING ( "Gain" )
, 0 , 2 , 0 } , { 112 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Gravity/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 113 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/Gravity/Multiply" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 114 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 115 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/Gain" ) , TARGET_STRING ( "Gain" ) ,
0 , 2 , 0 } , { 116 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/1-D Lookup Table1" ) , TARGET_STRING
( "Table" ) , 0 , 18 , 0 } , { 117 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/1-D Lookup Table1" ) , TARGET_STRING
( "BreakpointsForDimension1" ) , 0 , 18 , 0 } , { 118 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/AlphaWIng/ComputeAlphaBetaV/Constant1" ) ,
TARGET_STRING ( "Value" ) , 1 , 2 , 0 } , { 119 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Subsystem1/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 2 , 0 } , { 120 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/InducedAngleOfAttack/preLook/Constant8" ) ,
TARGET_STRING ( "Value" ) , 0 , 15 , 0 } , { 121 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Subsystem/Constant1" ) ,
TARGET_STRING ( "Value" ) , 1 , 7 , 0 } , { 122 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Subsystem/Gain2" ) , TARGET_STRING
( "Gain" ) , 1 , 2 , 0 } , { 123 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/Subsystem/Gain3" ) , TARGET_STRING
( "Gain" ) , 1 , 2 , 0 } , { 124 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "dimSizes" ) , 2 , 1 , 0 } , { 125 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "dimSizes" ) , 2 , 1 , 0 } , { 126 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "dimSizes" ) , 2 , 1 , 0 } , { 127 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "dimSizes" ) , 2 , 1 , 0 } , { 128 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "dimSizes" ) , 2 , 1 , 0 } , { 129 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "dimSizes" ) , 2 , 1 , 0 } , { 130 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/AngularVelocityComponent/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 12 , 0 } , { 131 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 132 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Gain3" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 133 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Gain5" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 134 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Saturation2" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 135 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Saturation2" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 136 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Saturation3" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 2 , 0 } , { 137 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Saturation3" ) , TARGET_STRING
( "LowerLimit" ) , 0 , 2 , 0 } , { 138 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/HTU/PropAndMotor/P lookup" ) ,
TARGET_STRING ( "maxIndex" ) , 2 , 19 , 0 } , { 139 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Direction Cosine Matrix Body to Wind/A32/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 140 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Subsystem1/Subsystem/Prelookup"
) , TARGET_STRING ( "BreakpointsData" ) , 1 , 20 , 0 } , { 141 ,
TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/FinFuselageForces/Subsystem1/Subsystem/Prelookup1"
) , TARGET_STRING ( "BreakpointsData" ) , 1 , 21 , 0 } , { 142 ,
TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/VtailForces/VtailForces/WingRootPreLookup/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 15 , 0 } , { 143 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 144 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/NodePoints" ) ,
TARGET_STRING ( "Value" ) , 1 , 10 , 0 } , { 145 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/Gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 2 , 0 } , { 146 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 147 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 148 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 149 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 150 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 151 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 152 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 153 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 154 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 155 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 156 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 157 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 158 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 159 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 160 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 161 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 162 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 163 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 164 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 165 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 166 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 167 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 168 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 169 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 170 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 10 , 0 } , { 171 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/NodePoints" ) ,
TARGET_STRING ( "Value" ) , 1 , 10 , 0 } , { 172 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/Gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 2 , 0 } , { 173 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 174 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 175 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 176 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 177 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 178 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 179 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 180 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 181 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 182 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 183 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 184 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 185 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 186 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup1"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 187 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 188 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup2"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 189 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 190 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup3"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 191 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 192 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup4"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 193 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 194 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup5"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 195 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "dimSizes" ) , 2 , 16 , 0 } , { 196 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/Interpolation Using Prelookup6"
) , TARGET_STRING ( "maxIndex" ) , 2 , 16 , 0 } , { 197 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/additionalDrag/Direction Cosine Matrix Body to Wind/A32/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 198 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Controller/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 199 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Controller/actf2T" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 200 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Controller/T2rpm" ) ,
TARGET_STRING ( "maxIndex" ) , 2 , 19 , 0 } , { 201 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Controller/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 2 , 0 } , { 202 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 203 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 204 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/DEP_incidence" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 205 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 206 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 207 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 208 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Conversion/Saturation1" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 209 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 210 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 211 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Gain2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 212 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Gain3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 213 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 214 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 215 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 216 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Subsystems/DEP1/DEP/Propeller/Saturation1" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 217 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/w2b/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 2 , 0 } , { 218 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingRootForces/WingRootPreLookup/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 22 , 0 } , { 219 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/WingTipForces/WingRootPreLookup/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 18 , 0 } , { 220 , TARGET_STRING (
"UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/w2b/Constant" ) ,
TARGET_STRING ( "Value" ) , 1 , 2 , 0 } , { 221 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingRootForces/WingRootPreLookup/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 22 , 0 } , { 222 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/WingTipForces/WingRootPreLookup/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 18 , 0 } , { 223 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Left/Subsystem/w2b/Direction Cosine Matrix Body to Wind/A32/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 224 , TARGET_STRING (
 "UNIFIER_dyn/UNIFIER OBM1/Aero/WingForces/Right/Subsystem/w2b/Direction Cosine Matrix Body to Wind/A32/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 225 , 0 , TARGET_STRING (
"UNIFIER_dyn/in" ) , TARGET_STRING ( "" ) , 1 , 0 , 2 , 0 , 0 } , { 0 , 0 , (
NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals
rtRootOutputs [ ] = { { 226 , 0 , TARGET_STRING ( "UNIFIER_dyn/Out1" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 23 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 227 , TARGET_STRING ( "dp_VTAIL" ) , 3 , 2 , 0 }
, { 228 , TARGET_STRING ( "dp_VTAIL_INDUCED" ) , 4 , 2 , 0 } , { 229 ,
TARGET_STRING ( "dp_WING_root" ) , 5 , 2 , 0 } , { 230 , TARGET_STRING (
"dp_WING_tip" ) , 6 , 2 , 0 } , { 231 , TARGET_STRING ( "dp_DEP" ) , 9 , 2 ,
0 } , { 232 , TARGET_STRING ( "dp_HTU" ) , 11 , 2 , 0 } , { 233 ,
TARGET_STRING ( "dp_FUSE_FIN" ) , 12 , 2 , 0 } , { 234 , TARGET_STRING ( "I"
) , 0 , 8 , 0 } , { 235 , TARGET_STRING ( "S" ) , 0 , 2 , 0 } , { 236 ,
TARGET_STRING ( "m" ) , 0 , 2 , 0 } , { 237 , TARGET_STRING ( "xyz_DEP" ) , 0
, 5 , 0 } , { 238 , TARGET_STRING ( "xyz_cg" ) , 0 , 13 , 0 } , { 239 ,
TARGET_STRING ( "vtail_nodes" ) , 1 , 7 , 0 } , { 240 , TARGET_STRING (
"wing_nodes" ) , 1 , 50 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . eljuwfhp1f [ 0 ] , & rtB .
lxkh42xndm [ 0 ] , & rtB . ecjaklyjaq , & rtB . lcnor15erx [ 0 ] , & rtB .
p5rpnypkdo [ 11 ] . gbstdhmylq , & rtB . jefg5cifsj , & rtB . jet1i0an5do [ 0
] , & rtB . dzpd4knetl [ 0 ] , & rtB . crx1qgibvon [ 0 ] , & rtB . jet1i0an5d
[ 0 ] , & rtB . crx1qgibvo [ 0 ] , & rtB . jdsvzdisey [ 0 ] , & rtB .
noeiauttpl [ 0 ] , & rtB . jz0qdcsmmm [ 15 ] . ijneevr0hx [ 0 ] , & rtB .
jz0qdcsmmmw [ 13 ] . kz2ejerpof [ 0 ] , & rtB . f5f1ypai11 [ 0 ] , & rtB .
l3mgpdtrrg [ 0 ] , & rtB . ejdl4n31el [ 0 ] , & rtB . etlvxwxtcy [ 0 ] , &
rtB . fqp13muoyo [ 0 ] , & rtB . jltpjpl4zp [ 0 ] , & rtB . nluycx3bh3 [ 0 ]
, & rtB . p1lfhtknc0 [ 0 ] , & rtB . bftm5ocvno [ 0 ] , & rtB . fp54rsi3hk [
0 ] , & rtB . omkpqlajlz [ 0 ] , & rtB . orlelyhfjl , & rtB . nhcvscc4t0 [ 0
] , & rtB . kunmel5bx4 [ 0 ] , & rtB . kainbdj3jznl [ 0 ] , & rtB .
bdrmalqcon [ 0 ] , & rtB . kqrxmtokjd [ 0 ] , & rtB . bjhstbmrsn , & rtB .
osqwflveuv , & rtB . bp0afaxpp5 , & rtB . j1stuyzs1t [ 0 ] , & rtB .
hzhdx3sz5v [ 0 ] , & rtB . jz0qdcsmmmwh [ 15 ] . m05clr3gxy [ 0 ] , & rtB .
pmh50qaazg [ 0 ] , & rtB . mgyjrcfqfu [ 0 ] , & rtB . kainbdj3jzn [ 0 ] , &
rtB . bavqi0oauug [ 0 ] , & rtB . pqjyj5rgda [ 0 ] , & rtB . kainbdj3jz [ 0 ]
, & rtB . bavqi0oauu [ 0 ] , & rtB . fpov3sjl4o [ 0 ] , & rtB . cyv21phhbm [
0 ] , & rtB . czxnr0doyy [ 0 ] , & rtB . au023bergz [ 11 ] . fai5wajm52 [ 0 ]
, & rtB . au023bergz [ 11 ] . aqav5cdmuv [ 0 ] , & rtB . gfknqoynom , & rtB .
jz0qdcsmmmwh5 [ 6 ] . m5kvx1lnef [ 0 ] , & rtB . g53iqbai0i , & rtB .
ayw0otszrq , & rtB . jqfgyi5cqv , & rtB . lkci5wisjr , & rtB .
jz0qdcsmmmwh5rk [ 6 ] . omlkzp34xv [ 0 ] , & rtB . bqft1jkk0z , & rtB .
gbccn4rvbj , & rtB . fu5nkfrvvl , & rtB . igwg4uissg , & rtP .
testinput_Value [ 0 ] , & rtP . Constant_Value , & rtP . zeta_Value [ 0 ] , &
rtP . p5rpnypkdo . K_slope_Gain , & rtP . AltitudeofTroposphere_Value , & rtP
. Constant_Value_mlc0xem4a2 , & rtP . SeaLevelTemperature_Value , & rtP .
uT0_Gain , & rtP . LapseRate_Gain , & rtP . gR_Gain , & rtP . rho0_Gain , &
rtP . LimitaltitudetoStratosphere_UpperSat , & rtP .
LimitaltitudetoStratosphere_LowerSat , & rtP .
Limitaltitudetotroposhere_UpperSat , & rtP .
Limitaltitudetotroposhere_LowerSat , & rtP . jz0qdcsmmm . Constant1_Value , &
rtP . Constant_Value_exkenlsy3u [ 0 ] , & rtP . Gain_Gain_ngpzxxezsf , & rtP
. Constant_Value_izgjegg0j4 [ 0 ] , & rtP . Constant1_Value_meik51c4df [ 0 ]
, & rtP . Constant7_Value [ 0 ] , & rtP . V_induced_dimSize [ 0 ] , & rtP .
alpha_induced_dimSize [ 0 ] , & rtP . uDLookupTable_bp01Data [ 0 ] , & rtP .
uDLookupTable1_bp01Data_o3lj0rj2gn [ 0 ] , & rtP . uDLookupTable2_bp01Data [
0 ] , & rtP . Constant_Value_kx5dv3qh2a [ 0 ] , & rtP .
Constant1_Value_dxjow4r24m [ 0 ] , & rtP . Constant1_Value_fodj5rxow1 , & rtP
. extra_drag_Value , & rtP . gear_drag_Value , & rtP . Gain_Gain_jabdopn2nb ,
& rtP . Constant1_Value , & rtP . Gain_Gain , & rtP . Constant2_Value [ 0 ] ,
& rtP . Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
Saturation3_UpperSat , & rtP . Saturation3_LowerSat , & rtP .
Saturation4_UpperSat , & rtP . Saturation4_LowerSat , & rtP .
Saturation6_UpperSat , & rtP . Saturation6_LowerSat , & rtP .
Constant2_Value_lirfr5mubp [ 0 ] , & rtP . Inclination_Value , & rtP .
Gain1_Gain , & rtP . Gain2_Gain , & rtP . Constant_Value_kr4kbsbfsk , & rtP .
Multiply_Gain , & rtP . Constant_Value_dtyrktojcw , & rtP .
Gain_Gain_gmzj2h1bwx , & rtP . uDLookupTable1_tableData [ 0 ] , & rtP .
uDLookupTable1_bp01Data [ 0 ] , & rtP . jz0qdcsmmmw . Constant1_Value , & rtP
. Constant_Value_dggd0yls2s , & rtP . Constant8_Value [ 0 ] , & rtP .
Constant1_Value_jtw2pfsmen [ 0 ] , & rtP . Gain2_Gain_a2ertcz4ne , & rtP .
Gain3_Gain , & rtP . InterpolationUsingPrelookup1_dimSize_kbujhpqt4p [ 0 ] ,
& rtP . InterpolationUsingPrelookup2_dimSize_it0njeibeo [ 0 ] , & rtP .
InterpolationUsingPrelookup3_dimSize_h5lelt5fk5 [ 0 ] , & rtP .
InterpolationUsingPrelookup4_dimSize_lnthg1rnjp [ 0 ] , & rtP .
InterpolationUsingPrelookup5_dimSize_brj4qiei0w [ 0 ] , & rtP .
InterpolationUsingPrelookup6_dimSize_nqfnlt53ag [ 0 ] , & rtP .
Gain_Gain_jhzuipt41u [ 0 ] , & rtP . au023bergz . Gain1_Gain , & rtP .
au023bergz . Gain3_Gain_kiqvbbswpr , & rtP . au023bergz . Gain5_Gain , & rtP
. au023bergz . Saturation2_UpperSat , & rtP . au023bergz .
Saturation2_LowerSat , & rtP . au023bergz . Saturation3_UpperSat , & rtP .
au023bergz . Saturation3_LowerSat , & rtP . Plookup_maxIndex [ 0 ] , & rtP .
Constant_Value_ll1hqpke5l , & rtP . Prelookup_BreakpointsData [ 0 ] , & rtP .
Prelookup1_BreakpointsData [ 0 ] , & rtP . Constant8_Value_cr0us2qlbv [ 0 ] ,
& rtP . Constant_Value_lkalxliguo [ 0 ] , & rtP . NodePoints_Value [ 0 ] , &
rtP . Gain_Gain_ovou53gniu , & rtP . InterpolationUsingPrelookup1_dimSize [ 0
] , & rtP . InterpolationUsingPrelookup1_maxIndex [ 0 ] , & rtP .
InterpolationUsingPrelookup2_dimSize [ 0 ] , & rtP .
InterpolationUsingPrelookup2_maxIndex [ 0 ] , & rtP .
InterpolationUsingPrelookup3_dimSize [ 0 ] , & rtP .
InterpolationUsingPrelookup3_maxIndex [ 0 ] , & rtP .
InterpolationUsingPrelookup4_dimSize [ 0 ] , & rtP .
InterpolationUsingPrelookup4_maxIndex [ 0 ] , & rtP .
InterpolationUsingPrelookup5_dimSize [ 0 ] , & rtP .
InterpolationUsingPrelookup5_maxIndex [ 0 ] , & rtP .
InterpolationUsingPrelookup6_dimSize [ 0 ] , & rtP .
InterpolationUsingPrelookup6_maxIndex [ 0 ] , & rtP .
InterpolationUsingPrelookup1_dimSize_goowtl1isu [ 0 ] , & rtP .
InterpolationUsingPrelookup1_maxIndex_gcrts0kvey [ 0 ] , & rtP .
InterpolationUsingPrelookup2_dimSize_hjcwwxhrb2 [ 0 ] , & rtP .
InterpolationUsingPrelookup2_maxIndex_hmktoionv2 [ 0 ] , & rtP .
InterpolationUsingPrelookup3_dimSize_eey1a1evp1 [ 0 ] , & rtP .
InterpolationUsingPrelookup3_maxIndex_inqyzx0bkv [ 0 ] , & rtP .
InterpolationUsingPrelookup4_dimSize_eonzf4khoz [ 0 ] , & rtP .
InterpolationUsingPrelookup4_maxIndex_ldg1ql3t42 [ 0 ] , & rtP .
InterpolationUsingPrelookup5_dimSize_m1b3rqhw3t [ 0 ] , & rtP .
InterpolationUsingPrelookup5_maxIndex_l0p20lh4bw [ 0 ] , & rtP .
InterpolationUsingPrelookup6_dimSize_ewytp2yzsl [ 0 ] , & rtP .
InterpolationUsingPrelookup6_maxIndex_fa5a0eaqeu [ 0 ] , & rtP .
Constant_Value_bchqth404u [ 0 ] , & rtP . NodePoints_Value_iel3jxerxr [ 0 ] ,
& rtP . Gain_Gain_mvu5sy12vu , & rtP .
InterpolationUsingPrelookup1_dimSize_jgranlzjdr [ 0 ] , & rtP .
InterpolationUsingPrelookup1_maxIndex_m1elfxqfrm [ 0 ] , & rtP .
InterpolationUsingPrelookup2_dimSize_e5mnlcnsgz [ 0 ] , & rtP .
InterpolationUsingPrelookup2_maxIndex_ic1jmobgnb [ 0 ] , & rtP .
InterpolationUsingPrelookup3_dimSize_gotbz31jut [ 0 ] , & rtP .
InterpolationUsingPrelookup3_maxIndex_iyvebvf0hr [ 0 ] , & rtP .
InterpolationUsingPrelookup4_dimSize_frefplnidc [ 0 ] , & rtP .
InterpolationUsingPrelookup4_maxIndex_onrk5innhu [ 0 ] , & rtP .
InterpolationUsingPrelookup5_dimSize_licoblhfnw [ 0 ] , & rtP .
InterpolationUsingPrelookup5_maxIndex_eshiygopfu [ 0 ] , & rtP .
InterpolationUsingPrelookup6_dimSize_gllaksp5ia [ 0 ] , & rtP .
InterpolationUsingPrelookup6_maxIndex_ny0js42i4o [ 0 ] , & rtP .
InterpolationUsingPrelookup1_dimSize_hgrobm0ojs [ 0 ] , & rtP .
InterpolationUsingPrelookup1_maxIndex_kj53253sjw [ 0 ] , & rtP .
InterpolationUsingPrelookup2_dimSize_fv3gcuk1rh [ 0 ] , & rtP .
InterpolationUsingPrelookup2_maxIndex_joswbgit4t [ 0 ] , & rtP .
InterpolationUsingPrelookup3_dimSize_i1e0soyo1i [ 0 ] , & rtP .
InterpolationUsingPrelookup3_maxIndex_axhtziqjmb [ 0 ] , & rtP .
InterpolationUsingPrelookup4_dimSize_kh3x5zfkli [ 0 ] , & rtP .
InterpolationUsingPrelookup4_maxIndex_leuk5avc1v [ 0 ] , & rtP .
InterpolationUsingPrelookup5_dimSize_kcrhpwfjfn [ 0 ] , & rtP .
InterpolationUsingPrelookup5_maxIndex_brkchxcoij [ 0 ] , & rtP .
InterpolationUsingPrelookup6_dimSize_npg5h2ocwn [ 0 ] , & rtP .
InterpolationUsingPrelookup6_maxIndex_lpfi2gwlwq [ 0 ] , & rtP .
Constant_Value_ec1rbuxqhz , & rtP . au023bergz . Constant3_Value , & rtP .
au023bergz . actf2T_Gain , & rtP . au023bergz . T2rpm_maxIndex [ 0 ] , & rtP
. au023bergz . Switch1_Threshold , & rtP . au023bergz . Constant_Value , &
rtP . au023bergz . Constant1_Value , & rtP . au023bergz . DEP_incidence_Value
, & rtP . au023bergz . Saturation_UpperSat_dzx4r24qqm , & rtP . au023bergz .
Saturation_LowerSat_lu14kynpbe , & rtP . au023bergz .
Saturation1_UpperSat_o3uhb5q0dz , & rtP . au023bergz .
Saturation1_LowerSat_cob1qvjvl1 , & rtP . au023bergz .
Constant_Value_e5dci5j5wh , & rtP . au023bergz . Gain_Gain , & rtP .
au023bergz . Gain2_Gain , & rtP . au023bergz . Gain3_Gain , & rtP .
au023bergz . Saturation_UpperSat , & rtP . au023bergz . Saturation_LowerSat ,
& rtP . au023bergz . Saturation1_UpperSat , & rtP . au023bergz .
Saturation1_LowerSat , & rtP . jz0qdcsmmmwh5r . Constant_Value_bcqheaf40z , &
rtP . Constant8_Value_dj5ncyqbcf [ 0 ] , & rtP . Constant8_Value_hy4ct0z05y [
0 ] , & rtP . oeyei2gsmn . Constant_Value_lhjgiuieqz , & rtP .
Constant8_Value_kwpfdqsyq1 [ 0 ] , & rtP . Constant8_Value_m3ahup3xji [ 0 ] ,
& rtP . jz0qdcsmmmwh5r . Constant_Value , & rtP . oeyei2gsmn . Constant_Value
, & rtU . p1y0j2wmyr , & rtY . ekh2fh00tc [ 0 ] , & rtP . dp_VTAIL , & rtP .
dp_VTAIL_INDUCED , & rtP . dp_WING_root , & rtP . dp_WING_tip , & rtP .
dp_DEP , & rtP . dp_HTU , & rtP . dp_FUSE_FIN , & rtP . I [ 0 ] , & rtP . S ,
& rtP . m , & rtP . xyz_DEP [ 0 ] , & rtP . xyz_cg [ 0 ] , & rtP .
vtail_nodes [ 0 ] , & rtP . wing_nodes [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "float" , "real32_T" , 0 , 0 , sizeof ( real32_T ) , ( uint8_T ) SS_SINGLE
, 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof ( uint32_T ) ,
( uint8_T ) SS_UINT32 , 0 , 0 , 0 } , { "struct" ,
"struct_jutHZYEwOoNeidUZKCLQ8B" , 12 , 1 , sizeof (
struct_jutHZYEwOoNeidUZKCLQ8B ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_X4VfLKyPh2o5xFDym0ZDqD" , 9 , 13 , sizeof (
struct_X4VfLKyPh2o5xFDym0ZDqD ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_IzJ4J0FtAuhnGd5tRgSyHE" , 13 , 22 , sizeof (
struct_IzJ4J0FtAuhnGd5tRgSyHE ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_yWIZFWBbymsS8L1W0LWVH" , 13 , 35 , sizeof (
struct_yWIZFWBbymsS8L1W0LWVH ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_fnuCCPniuRknyr94YhzxZ" , 3 , 48 , sizeof (
struct_fnuCCPniuRknyr94YhzxZ ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_e4KmvBjsHkMILSnyqn1SNH" , 2 , 51 , sizeof (
struct_e4KmvBjsHkMILSnyqn1SNH ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_nC6b04CeB5t4pOaoQVXKo" , 5 , 53 , sizeof (
struct_nC6b04CeB5t4pOaoQVXKo ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_jgnmaTiP1kwpD95SOjXYyE" , 4 , 58 , sizeof (
struct_jgnmaTiP1kwpD95SOjXYyE ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_OvGmMrPqfNtzpqofYdArSB" , 5 , 62 , sizeof (
struct_OvGmMrPqfNtzpqofYdArSB ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } , {
"struct" , "struct_ledTFd3zOA1QjIJZGqbRtH" , 9 , 67 , sizeof (
struct_ledTFd3zOA1QjIJZGqbRtH ) , ( uint8_T ) SS_STRUCT , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , { "rude_defl" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B ,
rude_defl ) , 1 , 24 , 0 } , { "alphas" , rt_offsetof (
struct_jutHZYEwOoNeidUZKCLQ8B , alphas ) , 1 , 25 , 0 } , { "betas" ,
rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , betas ) , 1 , 26 , 0 } , {
"CFx" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , CFx ) , 1 , 27 , 0 } ,
{ "CFy" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , CFy ) , 1 , 27 , 0 }
, { "CFz" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , CFz ) , 1 , 27 , 0
} , { "CMx" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , CMx ) , 1 , 27 ,
0 } , { "CMy" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , CMy ) , 1 , 27
, 0 } , { "CMz" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , CMz ) , 1 ,
27 , 0 } , { "Xs_LE" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B , Xs_LE )
, 1 , 3 , 0 } , { "Ys_LE" , rt_offsetof ( struct_jutHZYEwOoNeidUZKCLQ8B ,
Ys_LE ) , 1 , 3 , 0 } , { "Zs_LE" , rt_offsetof (
struct_jutHZYEwOoNeidUZKCLQ8B , Zs_LE ) , 1 , 3 , 0 } , { "flap_defl" ,
rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD , flap_defl ) , 1 , 28 , 0 } , {
"alphas" , rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD , alphas ) , 1 , 29 ,
0 } , { "V_infs" , rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD , V_infs ) , 1
, 30 , 0 } , { "DEP_J" , rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD , DEP_J
) , 1 , 31 , 0 } , { "alpha_induced" , rt_offsetof (
struct_X4VfLKyPh2o5xFDym0ZDqD , alpha_induced ) , 1 , 32 , 0 } , {
"V_induced" , rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD , V_induced ) , 1 ,
32 , 0 } , { "Xs_LE" , rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD , Xs_LE )
, 1 , 3 , 0 } , { "Ys_LE" , rt_offsetof ( struct_X4VfLKyPh2o5xFDym0ZDqD ,
Ys_LE ) , 1 , 3 , 0 } , { "Zs_LE" , rt_offsetof (
struct_X4VfLKyPh2o5xFDym0ZDqD , Zs_LE ) , 1 , 3 , 0 } , { "flap_defl" ,
rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , flap_defl ) , 1 , 28 , 0 } , {
"alphas" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , alphas ) , 1 , 29 ,
0 } , { "V" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , V ) , 1 , 30 , 0
} , { "DEP_J" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , DEP_J ) , 1 ,
31 , 0 } , { "CD" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , CD ) , 1 ,
33 , 0 } , { "CS" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , CS ) , 1 ,
33 , 0 } , { "CL" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , CL ) , 1 ,
33 , 0 } , { "CMx" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , CMx ) , 1
, 33 , 0 } , { "CMy" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , CMy ) ,
1 , 33 , 0 } , { "CMz" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , CMz )
, 1 , 33 , 0 } , { "LE_Xs" , rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE ,
LE_Xs ) , 1 , 34 , 0 } , { "LE_Ys" , rt_offsetof (
struct_IzJ4J0FtAuhnGd5tRgSyHE , LE_Ys ) , 1 , 34 , 0 } , { "LE_Zs" ,
rt_offsetof ( struct_IzJ4J0FtAuhnGd5tRgSyHE , LE_Zs ) , 1 , 34 , 0 } , {
"ail_defl" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , ail_defl ) , 1 , 35
, 0 } , { "alphas" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , alphas ) ,
1 , 29 , 0 } , { "V" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , V ) , 1 ,
30 , 0 } , { "DEP_J" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , DEP_J ) ,
1 , 31 , 0 } , { "CD" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , CD ) , 1
, 36 , 0 } , { "CS" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , CS ) , 1 ,
36 , 0 } , { "CL" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , CL ) , 1 ,
36 , 0 } , { "CMx" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , CMx ) , 1 ,
36 , 0 } , { "CMy" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , CMy ) , 1 ,
36 , 0 } , { "CMz" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , CMz ) , 1 ,
36 , 0 } , { "LE_Xs" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , LE_Xs ) ,
1 , 30 , 0 } , { "LE_Ys" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH , LE_Ys
) , 1 , 30 , 0 } , { "LE_Zs" , rt_offsetof ( struct_yWIZFWBbymsS8L1W0LWVH ,
LE_Zs ) , 1 , 30 , 0 } , { "V_vec" , rt_offsetof (
struct_fnuCCPniuRknyr94YhzxZ , V_vec ) , 0 , 38 , 0 } , { "T_vec" ,
rt_offsetof ( struct_fnuCCPniuRknyr94YhzxZ , T_vec ) , 0 , 39 , 0 } , {
"rpm_gird" , rt_offsetof ( struct_fnuCCPniuRknyr94YhzxZ , rpm_gird ) , 0 , 40
, 0 } , { "V" , rt_offsetof ( struct_e4KmvBjsHkMILSnyqn1SNH , V ) , 0 , 42 ,
0 } , { "actf" , rt_offsetof ( struct_e4KmvBjsHkMILSnyqn1SNH , actf ) , 0 ,
42 , 0 } , { "J" , rt_offsetof ( struct_nC6b04CeB5t4pOaoQVXKo , J ) , 0 , 37
, 0 } , { "C_T" , rt_offsetof ( struct_nC6b04CeB5t4pOaoQVXKo , C_T ) , 0 , 37
, 0 } , { "C_Q" , rt_offsetof ( struct_nC6b04CeB5t4pOaoQVXKo , C_Q ) , 0 , 37
, 0 } , { "rpm_lookup" , rt_offsetof ( struct_nC6b04CeB5t4pOaoQVXKo ,
rpm_lookup ) , 7 , 41 , 0 } , { "limits" , rt_offsetof (
struct_nC6b04CeB5t4pOaoQVXKo , limits ) , 8 , 41 , 0 } , { "V_low_lim" ,
rt_offsetof ( struct_jgnmaTiP1kwpD95SOjXYyE , V_low_lim ) , 0 , 43 , 0 } , {
"T_low_lim" , rt_offsetof ( struct_jgnmaTiP1kwpD95SOjXYyE , T_low_lim ) , 0 ,
43 , 0 } , { "V_up_lim" , rt_offsetof ( struct_jgnmaTiP1kwpD95SOjXYyE ,
V_up_lim ) , 0 , 34 , 0 } , { "T_up_lim" , rt_offsetof (
struct_jgnmaTiP1kwpD95SOjXYyE , T_up_lim ) , 0 , 34 , 0 } , { "limits" ,
rt_offsetof ( struct_OvGmMrPqfNtzpqofYdArSB , limits ) , 10 , 41 , 0 } , {
"V_vec" , rt_offsetof ( struct_OvGmMrPqfNtzpqofYdArSB , V_vec ) , 0 , 44 , 0
} , { "T_vec" , rt_offsetof ( struct_OvGmMrPqfNtzpqofYdArSB , T_vec ) , 0 ,
45 , 0 } , { "Q_grid" , rt_offsetof ( struct_OvGmMrPqfNtzpqofYdArSB , Q_grid
) , 0 , 46 , 0 } , { "P_grid" , rt_offsetof ( struct_OvGmMrPqfNtzpqofYdArSB ,
P_grid ) , 0 , 46 , 0 } , { "beta" , rt_offsetof (
struct_ledTFd3zOA1QjIJZGqbRtH , beta ) , 0 , 44 , 0 } , { "aoa" , rt_offsetof
( struct_ledTFd3zOA1QjIJZGqbRtH , aoa ) , 0 , 47 , 0 } , { "ref_CG" ,
rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , ref_CG ) , 0 , 48 , 0 } , {
"CD" , rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , CD ) , 1 , 49 , 0 } , {
"CS" , rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , CS ) , 1 , 49 , 0 } , {
"CL" , rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , CL ) , 1 , 49 , 0 } , {
"CMx" , rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , CMx ) , 1 , 49 , 0 } ,
{ "CMy" , rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , CMy ) , 1 , 49 , 0 }
, { "CMz" , rt_offsetof ( struct_ledTFd3zOA1QjIJZGqbRtH , CMz ) , 1 , 49 , 0
} } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_SCALAR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 10 , 2
, 0 } , { rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 16 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2
, 0 } , { rtwCAPI_VECTOR , 20 , 2 , 0 } , { rtwCAPI_VECTOR , 22 , 2 , 0 } , {
rtwCAPI_VECTOR , 24 , 2 , 0 } , { rtwCAPI_VECTOR , 26 , 2 , 0 } , {
rtwCAPI_VECTOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 28 , 2 , 0 } , {
rtwCAPI_VECTOR , 30 , 2 , 0 } , { rtwCAPI_VECTOR , 32 , 2 , 0 } , {
rtwCAPI_VECTOR , 34 , 2 , 0 } , { rtwCAPI_VECTOR , 36 , 2 , 0 } , {
rtwCAPI_VECTOR , 38 , 2 , 0 } , { rtwCAPI_VECTOR , 40 , 2 , 0 } , {
rtwCAPI_VECTOR , 42 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 44 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 46 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 48 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 50 , 4 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 54 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 56 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 32 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 58 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 60
, 5 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 65 , 5 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 40 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 70 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 72 , 5 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 77 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 79 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 81 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 83 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 4 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 85 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 30 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 36 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 87 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 89 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 38 , 2
, 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 24 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 91 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 93 , 2
, 0 } } ; static const uint_T rtDimensionArray [ ] = { 12 , 1 , 3 , 1 , 1 , 1
, 1 , 16 , 1 , 14 , 3 , 12 , 16 , 1 , 3 , 16 , 3 , 3 , 3 , 7 , 19 , 1 , 1 ,
12 , 1 , 3 , 1 , 8 , 4 , 1 , 1 , 6 , 1 , 2 , 2 , 1 , 13 , 1 , 15 , 1 , 1 , 5
, 70 , 1 , 1 , 10 , 1 , 13 , 1 , 9 , 10 , 13 , 9 , 16 , 5 , 1 , 1 , 25 , 1 ,
7 , 5 , 25 , 2 , 7 , 16 , 5 , 25 , 2 , 7 , 5 , 7 , 1 , 7 , 25 , 2 , 7 , 2 ,
46 , 1 , 43 , 1 , 91 , 1 , 43 , 91 , 1 , 19 , 41 , 1 , 13 , 41 , 13 , 15 , 3
, 14 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 1 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 61 ,
rtRootInputs , 1 , rtRootOutputs , 1 } , { rtBlockParameters , 164 ,
rtModelParameters , 14 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 3469205189U , 2159496850U , 2886346932U ,
3540084195U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * UNIFIER_dyn_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void UNIFIER_dyn_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void UNIFIER_dyn_host_InitializeDataMapInfo ( UNIFIER_dyn_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
