#ifndef RTW_HEADER_UNIFIER_types_h_
#define RTW_HEADER_UNIFIER_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_ledTFd3zOA1QjIJZGqbRtH_
#define DEFINED_TYPEDEF_FOR_struct_ledTFd3zOA1QjIJZGqbRtH_
typedef struct { real_T beta [ 13 ] ; real_T aoa [ 15 ] ; real_T ref_CG [ 3 ]
; real32_T CD [ 195 ] ; real32_T CS [ 195 ] ; real32_T CL [ 195 ] ; real32_T
CMx [ 195 ] ; real32_T CMy [ 195 ] ; real32_T CMz [ 195 ] ; }
struct_ledTFd3zOA1QjIJZGqbRtH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_X4VfLKyPh2o5xFDym0ZDqD_
#define DEFINED_TYPEDEF_FOR_struct_X4VfLKyPh2o5xFDym0ZDqD_
typedef struct { real32_T flap_defl [ 5 ] ; real32_T alphas [ 25 ] ; real32_T
V_infs [ 2 ] ; real32_T DEP_J [ 7 ] ; real32_T alpha_induced [ 28000 ] ;
real32_T V_induced [ 28000 ] ; real32_T Xs_LE [ 16 ] ; real32_T Ys_LE [ 16 ]
; real32_T Zs_LE [ 16 ] ; uint8_T sl_padding0 [ 4 ] ; }
struct_X4VfLKyPh2o5xFDym0ZDqD ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_jutHZYEwOoNeidUZKCLQ8B_
#define DEFINED_TYPEDEF_FOR_struct_jutHZYEwOoNeidUZKCLQ8B_
typedef struct { real32_T rude_defl [ 10 ] ; real32_T alphas [ 13 ] ;
real32_T betas [ 9 ] ; real32_T CFx [ 18720 ] ; real32_T CFy [ 18720 ] ;
real32_T CFz [ 18720 ] ; real32_T CMx [ 18720 ] ; real32_T CMy [ 18720 ] ;
real32_T CMz [ 18720 ] ; real32_T Xs_LE [ 16 ] ; real32_T Ys_LE [ 16 ] ;
real32_T Zs_LE [ 16 ] ; } struct_jutHZYEwOoNeidUZKCLQ8B ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_IzJ4J0FtAuhnGd5tRgSyHE_
#define DEFINED_TYPEDEF_FOR_struct_IzJ4J0FtAuhnGd5tRgSyHE_
typedef struct { real32_T flap_defl [ 5 ] ; real32_T alphas [ 25 ] ; real32_T
V [ 2 ] ; real32_T DEP_J [ 7 ] ; real32_T CD [ 8750 ] ; real32_T CS [ 8750 ]
; real32_T CL [ 8750 ] ; real32_T CMx [ 8750 ] ; real32_T CMy [ 8750 ] ;
real32_T CMz [ 8750 ] ; real32_T LE_Xs [ 5 ] ; real32_T LE_Ys [ 5 ] ;
real32_T LE_Zs [ 5 ] ; } struct_IzJ4J0FtAuhnGd5tRgSyHE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_yWIZFWBbymsS8L1W0LWVH_
#define DEFINED_TYPEDEF_FOR_struct_yWIZFWBbymsS8L1W0LWVH_
typedef struct { real32_T ail_defl [ 7 ] ; real32_T alphas [ 25 ] ; real32_T
V [ 2 ] ; real32_T DEP_J [ 7 ] ; real32_T CD [ 4900 ] ; real32_T CS [ 4900 ]
; real32_T CL [ 4900 ] ; real32_T CMx [ 4900 ] ; real32_T CMy [ 4900 ] ;
real32_T CMz [ 4900 ] ; real32_T LE_Xs [ 2 ] ; real32_T LE_Ys [ 2 ] ;
real32_T LE_Zs [ 2 ] ; uint8_T sl_padding0 [ 4 ] ; }
struct_yWIZFWBbymsS8L1W0LWVH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_fnuCCPniuRknyr94YhzxZ_
#define DEFINED_TYPEDEF_FOR_struct_fnuCCPniuRknyr94YhzxZ_
typedef struct { real_T V_vec [ 43 ] ; real_T T_vec [ 91 ] ; real_T rpm_gird
[ 3913 ] ; } struct_fnuCCPniuRknyr94YhzxZ ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_e4KmvBjsHkMILSnyqn1SNH_
#define DEFINED_TYPEDEF_FOR_struct_e4KmvBjsHkMILSnyqn1SNH_
typedef struct { real_T V [ 19 ] ; real_T actf [ 19 ] ; }
struct_e4KmvBjsHkMILSnyqn1SNH ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_nC6b04CeB5t4pOaoQVXKo_
#define DEFINED_TYPEDEF_FOR_struct_nC6b04CeB5t4pOaoQVXKo_
typedef struct { real_T J [ 46 ] ; real_T C_T [ 46 ] ; real_T C_Q [ 46 ] ;
struct_fnuCCPniuRknyr94YhzxZ rpm_lookup ; struct_e4KmvBjsHkMILSnyqn1SNH
limits ; } struct_nC6b04CeB5t4pOaoQVXKo ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_jgnmaTiP1kwpD95SOjXYyE_
#define DEFINED_TYPEDEF_FOR_struct_jgnmaTiP1kwpD95SOjXYyE_
typedef struct { real_T V_low_lim [ 6 ] ; real_T T_low_lim [ 6 ] ; real_T
V_up_lim [ 5 ] ; real_T T_up_lim [ 5 ] ; } struct_jgnmaTiP1kwpD95SOjXYyE ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_OvGmMrPqfNtzpqofYdArSB_
#define DEFINED_TYPEDEF_FOR_struct_OvGmMrPqfNtzpqofYdArSB_
typedef struct { struct_jgnmaTiP1kwpD95SOjXYyE limits ; real_T V_vec [ 13 ] ;
real_T T_vec [ 41 ] ; real_T Q_grid [ 533 ] ; real_T P_grid [ 533 ] ; }
struct_OvGmMrPqfNtzpqofYdArSB ;
#endif
#ifndef DEFINED_TYPEDEF_FOR_struct_rFkegYH72KGOtqmd7lp2k_
#define DEFINED_TYPEDEF_FOR_struct_rFkegYH72KGOtqmd7lp2k_
typedef struct { real_T dt ; } struct_rFkegYH72KGOtqmd7lp2k ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 28
#endif
#ifndef SS_INT64
#define SS_INT64 29
#endif
typedef struct jwys52rryd_ jwys52rryd ; typedef struct jwys52rrydz_
jwys52rrydz ; typedef struct jwys52rrydzh00_ jwys52rrydzh00 ; typedef struct
kkuqadxzh5_ kkuqadxzh5 ; typedef struct kpxwjmhxii_ kpxwjmhxii ; typedef
struct n5t5fi0dwr_ n5t5fi0dwr ; typedef struct P_ P ;
#endif
