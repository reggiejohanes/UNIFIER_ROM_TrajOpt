#ifndef RTW_HEADER_UNIFIER_h_
#define RTW_HEADER_UNIFIER_h_
#ifndef UNIFIER_COMMON_INCLUDES_
#define UNIFIER_COMMON_INCLUDES_
#include <stdio.h>
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
#include "DAHostLib_Network.h"
#endif
#include "UNIFIER_types.h"
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "mwmathutil.h"
#include "rt_zcfcn.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME UNIFIER
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (226) 
#define NUM_ZC_EVENTS (2) 
#ifndef NCSTATES
#define NCSTATES (97)   
#elif NCSTATES != 97
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
typedef struct { real32_T kl452g3br4 [ 3 ] ; real32_T ico5bo4shp [ 3 ] ; }
elhu4uebig ; typedef struct { real32_T g2bz2muoaw [ 3 ] ; real32_T lkowsjx5yc
[ 3 ] ; } elhu4uebigf ; typedef struct { real32_T f5l1thfo3b [ 3 ] ; real32_T
a0tbi33tik [ 3 ] ; } elhu4uebigft ; typedef struct { real32_T d2kygac014 [ 3
] ; real32_T dbot5mi30f [ 3 ] ; } elhu4uebigftq ; typedef struct { real32_T
jqzydkhuci [ 3 ] ; real32_T gg011l2nji [ 3 ] ; } elhu4uebigftqly ; typedef
struct { real_T c1tiif3ujm ; } ny4q0xtkup ; typedef struct { int8_T
gxcgpda4hi ; boolean_T jifjbgbgqy ; } fpbcqq3sgu ; typedef struct { real_T
bwl2pyw2pm ; } dry5l5lsph ; typedef struct { real_T bwl2pyw2pm ; } il4tjwsha2
; typedef struct { boolean_T bwl2pyw2pm ; } dawqgveeyg ; typedef struct {
real_T ibnqksi5kc ; real_T jagzqtugld ; real_T dfpeduhr4c [ 3 ] ; real_T
ex2xojeend ; real_T n52zpi4j4s ; real_T dbnx540oz1 [ 9 ] ; real32_T
aox0khugvh [ 3 ] ; boolean_T cgxtlo5ezj ; boolean_T hqlowwzkov ; } jhlvrpyycj
; typedef struct { uint32_T adrjjytrwd ; uint32_T mirazmrnvl ; uint32_T
mczobgpj2t [ 2 ] ; boolean_T kd3fwxo3ke ; } o02wj5ik5e ; typedef struct {
real_T jtqvm3jkcz ; real_T dkxi20ccfc ; } pjade3oksx ; typedef struct {
real_T jtqvm3jkcz ; real_T dkxi20ccfc ; } j0w55rdezp ; typedef struct {
boolean_T jtqvm3jkcz ; boolean_T dkxi20ccfc ; } io0vggrbfj ; typedef struct {
real_T ggmvjtadg3 [ 3 ] ; real_T jr3yr4ixei [ 3 ] ; } np24g4gdau ; typedef
struct { int32_T ckwkdnls5w ; uint8_T aqynsdznmr ; boolean_T onahgr5syd ; }
a0dvcgex5j ; typedef struct { uint8_T e1wak2s0nn [ 509 ] ; } fskif30kch ;
typedef struct { int32_T i2hnwisoi1 ; uint8_T fkmv4gfkl0 ; boolean_T
e3ed3ljbyn ; } fiqejkualm ; typedef struct { uint8_T hr4wpt01um [ 509 ] ; }
p3ecnoeui5 ; typedef struct { int32_T aquds3y3qy ; uint8_T b4sgpwle2l ;
boolean_T bfcbslmbdi ; } pls4xc4scj ; typedef struct { uint8_T gz0squozgl [
509 ] ; } dt1fegwimr ; typedef struct { int32_T datl4fzkmc ; uint8_T
op350srgbo ; boolean_T eiaswshrvs ; } jiigegnrkw ; typedef struct { uint8_T
h11nwvgfxj [ 509 ] ; } lkm4qo0z2m ; typedef struct { int32_T apnlfrnpo3 ;
uint8_T ovvez5xelu ; boolean_T dtz1ggkdpo ; } gv4mkh5bt0 ; typedef struct {
real_T exyupufjt5 [ 3 ] ; real_T gt3gymd154 [ 3 ] ; real_T j3t4wyjy41 [ 16 ]
; real_T ekmklzxfox [ 4 ] ; real_T kz552dd3t1 ; real_T bopxyfw2ia ; real_T
ecvavrybwp ; real_T okge55f2b5 ; real_T n2fj5a4cso ; real_T li5x4km43d [ 3 ]
; real_T gxhe3keu3a [ 3 ] ; real_T dohtax3vu3 [ 3 ] ; real_T hszixujy0p [ 3 ]
; real_T nn0j0nwtai [ 20 ] ; real_T nupdx24lfb [ 12 ] ; real_T ieaokh1oup ;
real_T odhuccln2g ; real_T bw4iyihnma [ 16 ] ; real_T kmxfn2bnil [ 16 ] ;
real_T ody4e0c4gv [ 16 ] ; real_T d0gfg5onrd [ 16 ] ; real_T agdfetg0qt [ 16
] ; real_T hmn4gg1bt5 ; real_T hwfjzaa0nm ; real_T aeyzgmp4rb ; real_T
d1dja0jwhm [ 3 ] ; real_T jagg20wiay ; real_T cutvjsc51o [ 3 ] ; real_T
llwqqnw3ke ; real_T lpr3engkn0 ; real_T adxfu05snb ; real_T mfsumfb52o ;
real_T ibkkavp3uy ; real_T k002wprevb [ 3 ] ; real_T dwtsbon1wj ; real_T
g2lkzpk1cd ; real_T o3f4ir0mnt ; real_T phhcl0h52y ; real_T cmce4od5nu ;
real_T cvpaunpk1i ; real_T kra5wvotxw [ 3 ] ; real_T h1v0fki4wd ; real_T
atski0fwo1 ; real_T pzrd4nwhsl ; real_T hsrt1ciq4i ; real_T gmov3gnpox ;
real_T onu4r5xewk [ 3 ] ; real_T ehjp343jmw ; real_T od11ruf3th [ 9 ] ;
real_T oaagntandl ; real_T p4p4elvfjt [ 3 ] ; real_T gdwsegs0yn [ 3 ] ;
real_T bznjqb4cys ; real_T hilbxeegf0 ; real_T p0trwoq5oi ; real_T bq0j25ykt3
; real_T c5avufipwu ; real_T iovd14a0zv ; real_T fcg44x4aqz [ 3 ] ; real_T
ps23iickbr [ 3 ] ; real_T bkodm3ably ; real_T fbtjhgisvg ; real_T hgd1a1255d
[ 20 ] ; real_T hfraqjvvj1 ; real_T n00gsxq4p1 ; real_T ixwwzqb4p2 ; real_T
dienpmt5lk [ 6 ] ; real_T lyw5uzhlvp [ 6 ] ; real_T pxf22reogn [ 6 ] ; real_T
naaosn4yn2 [ 6 ] ; real_T afhieoseax [ 6 ] ; real_T niowrwikj3 [ 6 ] ; real_T
gbabd0z3bn [ 6 ] ; real_T hpmq1jfzli [ 6 ] ; real_T jdw5fy5uyh ; real_T
c0rbweqsq1 ; real_T agnrcu13e2 ; real_T ia0ra0q3ax ; real_T l4whzntd2w ;
real_T nsqrvbi5rh ; real_T kydbwk01f5 ; real_T g3dy1b3uqu ; real_T dkmnirebs0
[ 3 ] ; real_T avgj00fc45 [ 3 ] ; real_T eezj4zgsj4 [ 3 ] ; real_T m1qwau1ibb
[ 3 ] ; real_T nci1mnnllt ; real_T elv40zm3eo ; real_T jopjoprq0c ; real_T
ku55m1jm2d ; real_T af22xidizc ; real_T bifocupq14 ; real_T bxtdurt4xq ;
real_T bdfwgn2f4t ; real_T izwq3m54sy ; real_T mhiuaswy01 ; real_T hwhq5yb2fg
; real_T l1dfj2jhio ; real_T l0khcdm5vj ; real_T hc3pucpzoc ; real_T
h1pryicb3f ; real_T djshdafk4a ; real_T jurla4fp4a ; real_T pchtyrudar [ 9 ]
; real_T k0wfvnkgwy [ 9 ] ; real_T armozr15x5 [ 9 ] ; real_T dcirnuyxde [ 12
] ; real_T jferaaeyyn ; real_T jemxdtgsel ; real_T awnwv0frb5 [ 3 ] ; real_T
on14h4dmvl ; real_T lrtymnw4xi ; real_T fnmgllmgqx ; real_T fqvqdt4rd2 ;
real_T jmxba5skz5 ; real_T pr1vt54ko4 [ 3 ] ; real_T jygnbcsqf1 [ 3 ] ;
real_T lwvqxcae23 ; real_T f1a2rfeuz1 ; real_T ih10mokqjs ; real_T g344blsojt
; real_T grblrau4l1 ; real_T mythzqzjez [ 3 ] ; real_T cdxkdrlzzm [ 3 ] ;
real_T ffkpsdx0zr ; real_T ftrxuf0i4a ; real_T hqi2kczfkw ; real_T lpx2s5ac0u
; real_T pmom2ene5w ; real_T njlxqs1uc4 [ 3 ] ; real_T e32n1qjlbz [ 3 ] ;
real_T higayyxcv3 ; real_T djejdif2w5 ; real_T l2pt0kefdc [ 3 ] ; real_T
dkodtfhso0 ; real_T lw0kvssqse ; real_T nos3a2bbnv ; real_T lhydxe5abe ;
real_T pr1zzcknox ; real_T btiigxjvj2 [ 3 ] ; real_T lbzmmcd5bg ; real_T
f0lcoipiql [ 20 ] ; real_T nhnvabjkuz [ 12 ] ; real_T anhsgyheay [ 12 ] ;
real_T iu2wb1r235 ; uint32_T pgacreyak0 ; uint32_T lcfixu2lfk ; uint32_T
mb1y0b3eym ; uint32_T lj1ecmy3sj ; uint32_T nj3xuut2fh [ 16 ] ; uint32_T
ngy3pgy40m [ 16 ] ; real32_T jrm5mulpgo [ 3 ] ; real32_T kp4feo544t [ 3 ] ;
real32_T korrwukkg3 [ 7 ] ; real32_T buybsypzuh ; real32_T kdl2q2ktlu ;
real32_T bflkh3tw3c [ 21 ] ; real32_T be1wst1pkg ; real32_T gefiy4un3d ;
real32_T lif0jqyjen [ 21 ] ; real32_T ln5blvjdm3 [ 16 ] ; real32_T ge01nkozzs
[ 16 ] ; real32_T o0icr3ysdn [ 48 ] ; real32_T dlawj1hfkq [ 3 ] ; real32_T
krmhpaiwtk [ 3 ] ; real32_T phywd5jekf ; real32_T ar3fw3fuom ; real32_T
ckez2fhnc0 ; real32_T ayq52soaqw [ 21 ] ; real32_T byhpdluumb [ 21 ] ;
real32_T ayq52soaqwz [ 21 ] ; real32_T byhpdluumbu [ 21 ] ; real32_T
byhpdluumbuo [ 48 ] ; real32_T cfz24gonbx [ 14 ] ; real32_T nmxk2xrfk3 [ 14 ]
; real32_T atgyr3lfo3 [ 16 ] ; real32_T cfz24gonbxg [ 16 ] ; real32_T
nmxk2xrfk3z [ 16 ] ; uint8_T gtlyl45i3j [ 509 ] ; uint8_T o0njsmigyn [ 509 ]
; uint8_T hjcw1qdlw2 [ 45 ] ; uint8_T iffp5o1pbp [ 509 ] ; uint8_T kno2d54iit
[ 509 ] ; uint8_T bqi10o4hpx [ 509 ] ; boolean_T n3u1rxuv5j ; boolean_T
hetdp5lb3h ; boolean_T h5anqi052g ; boolean_T fvsr3tltfl ; boolean_T
dzk03qgr1o ; lkm4qo0z2m hztlwupntw ; lkm4qo0z2m n1ybyykngv ; dt1fegwimr
jek5zaxern ; dt1fegwimr nikuyjvr0y ; dt1fegwimr enohy5yaap ; p3ecnoeui5
pookhwl2ri ; p3ecnoeui5 hl5ibqcu3w ; fskif30kch dffuptpbcz ; fskif30kch
bd32gk0ocy ; np24g4gdau leuhdrxpbe ; np24g4gdau csf3emrtxr ; np24g4gdau
jvaexa3o5a ; jhlvrpyycj adqmzv0sx0 [ 12 ] ; ny4q0xtkup pcwoeb21pm ;
ny4q0xtkup fthork0k0x2 ; elhu4uebigftqly nyqetrz43uqkkpi [ 7 ] ;
elhu4uebigftq nyqetrz43uqkk [ 7 ] ; elhu4uebigft nyqetrz43uqk [ 16 ] ;
elhu4uebigf nyqetrz43uq [ 14 ] ; elhu4uebig nyqetrz43u [ 16 ] ; } B ; typedef
struct { real_T g540jxiiax [ 100 ] ; real_T crxd5n2r3l [ 100 ] ; real_T
fx230yq5sl [ 5 ] ; real_T kvnpr153yy [ 5 ] ; real_T jhfnsaqhxz [ 5 ] ; real_T
lnmqg4h42q [ 5 ] ; real_T jsnr5tvela [ 5 ] ; real_T buecpeq4re [ 5 ] ; real_T
asespk50pt [ 5 ] ; real_T pmmx1tycaz [ 5 ] ; real_T e5trjt2azz [ 5 ] ; real_T
eqbrrfiebl [ 15 ] ; real_T fkbachhibk [ 45 ] ; real_T oaqzp5s2cy [ 5 ] ;
real_T plokoj1iat [ 15 ] ; real_T p3n5g3torf [ 15 ] ; real_T avagxvnwf5 [ 15
] ; real_T lkru3wc4bj [ 5 ] ; real_T pwrdd5kibs [ 5 ] ; real_T erskmg5gj1 [ 5
] ; real_T jj43i52zwn [ 5 ] ; real_T pagqs1iwpr [ 5 ] ; real_T hvagkay33y [ 5
] ; real_T eoz1jvwwoq [ 5 ] ; real_T jgluwzgfp1 [ 5 ] ; real_T cpjltmd3l2 [ 5
] ; real_T dcos1gkpc2 [ 5 ] ; real_T eypbisuusv [ 5 ] ; real_T ezpcxtf0ip [ 5
] ; real_T ookott5jvl [ 5 ] ; real_T h3h1h5xjyq [ 5 ] ; real_T aadveypr3e [ 5
] ; real_T nwwie5t5of ; real_T keywsrry0q ; real_T faxkrudp40 [ 137 ] ;
real_T m4a0ukvmhq [ 137 ] ; real_T mbrgrjucym [ 137 ] ; real_T kedw3dybgq ;
real_T abjojyrz15 [ 137 ] ; real_T ft5azbdazn [ 137 ] ; real_T m05hfkvpqz [
137 ] ; real_T ksy2wwjv20 [ 137 ] ; real_T axqu4ckdky [ 137 ] ; real_T
f00y3b0qin [ 137 ] ; real_T ehnerh2sch [ 137 ] ; real_T h52cjzwtlm [ 137 ] ;
real_T ktsj2nkchd ; real_T hshhxf1iwg [ 137 ] ; real_T fsed3lqtd2 [ 137 ] ;
real_T oy300njhw2 [ 3 ] ; real_T ie2l444zba [ 3 ] ; real_T fr2fpc1qxz [ 3 ] ;
real_T ilac1ylth3 [ 9 ] ; real_T lwsgjestu3 [ 137 ] ; real_T o4nasosvnh [ 137
] ; struct { real_T modelTStart ; } nevgeggqm5 ; struct { real_T modelTStart
; } lq4e3tdaf4 ; struct { void * LoggedData ; } c4dytoevnt ; struct { void *
LoggedData ; } hp20t3vsp0 ; struct { void * TUbufferPtrs [ 32 ] ; }
a1p5mmdhor ; struct { void * TUbufferPtrs [ 32 ] ; } d5j1ciynjn ; struct {
void * LoggedData [ 3 ] ; } dhi5a05pfe ; struct { void * LoggedData [ 3 ] ; }
pcsd1zoeme ; struct { void * LoggedData [ 3 ] ; } iazcz4ksei ; struct { void
* LoggedData [ 3 ] ; } psp0p5103u ; struct { void * LoggedData [ 3 ] ; }
km5zthkh0j ; struct { void * LoggedData [ 3 ] ; } ipldhfa011 ; struct { void
* LoggedData [ 2 ] ; } j4e1wtbi0o ; struct { void * LoggedData [ 2 ] ; }
afn4mecjjd ; struct { void * AQHandles ; } dzukxciamp ; struct { void *
AQHandles ; } oumnpiegvc ; struct { void * AQHandles ; } kmqxlkx3v2 ; struct
{ void * AQHandles ; } oszdennjt4 ; struct { void * AQHandles ; } glhrtguzli
; struct { void * LoggedData [ 3 ] ; } m4f243pj4m ; struct { void *
LoggedData [ 3 ] ; } cbfh0ipqzy ; struct { void * AQHandles ; } dzukxciampy ;
struct { void * AQHandles ; } dzukxciampy4 ; struct { void * AQHandles ; }
dzukxciampy43 ; struct { void * AQHandles ; } dzukxciampy430 ; struct { void
* AQHandles ; } oumnpiegvcp ; struct { void * AQHandles ; } kmqxlkx3v2q ;
struct { void * AQHandles ; } oszdennjt4x ; struct { void * AQHandles ; }
glhrtguzlib ; struct { void * AQHandles ; } a01trbqc4k ; struct { void *
LoggedData [ 3 ] ; } m3daqdrf13 ; struct { void * LoggedData [ 3 ] ; }
avgcen3t22 ; struct { void * LoggedData ; } bjo4j2im3p ; struct { void *
LoggedData ; } nnuoj3bvrf ; struct { void * AQHandles ; } dzukxciampy430g ;
struct { void * LoggedData ; } lonw1kej4h ; struct { void * AQHandles ; }
hpymvgtvx5 ; struct { void * LoggedData ; } dg14esoudi ; struct { void *
LoggedData ; } kk0xhzsxeo ; struct { void * LoggedData ; } kj4zwd1p12 ;
struct { void * LoggedData [ 2 ] ; } jcdaiyxqmm ; struct { void * LoggedData
; } jm5fiea1a2 ; struct { void * LoggedData ; } mouxkhwhvf ; struct { void *
LoggedData ; } j1nymsch2a ; struct { void * LoggedData ; } dckcas4wkr ;
struct { void * LoggedData [ 2 ] ; } jalebwub1e ; struct { void * LoggedData
; } o5c5s3r4a5 ; struct { void * LoggedData ; } c0smk3nyqc ; struct { void *
LoggedData ; } kq4bolygly ; struct { void * LoggedData ; } bb4yc0itxm ;
struct { void * LoggedData [ 2 ] ; } kppaiyfjx0 ; struct { void * LoggedData
; } pa1gipcb5b ; struct { void * LoggedData ; } dkmloaeklk ; struct { void *
LoggedData [ 4 ] ; } gmerynjpyv ; struct { void * LoggedData ; } ccx3cclwb5 ;
struct { void * LoggedData ; } jtu0h5fs3x ; struct { void * LoggedData ; }
c4eormxcf2 ; int32_T ml2zybgolh ; int32_T nndt0j2iyw ; int32_T oxzbnowmim ;
int32_T csd33umrye ; int32_T odfy0ab2zu ; int32_T piktw1sptf ; uint32_T
iinforci3b [ 4 ] ; uint32_T onpp1osnf1 ; uint32_T knywr3cygt [ 5 ] ; uint32_T
bxxehqrfhk [ 5 ] ; uint32_T lybiwzq15a [ 5 ] ; uint32_T hhpqcwloh0 ; uint32_T
hxdxaozqh1 [ 2 ] ; uint32_T fknte5kkos [ 2 ] ; uint32_T mnfw2imvdw [ 2 ] ;
uint32_T felqedgyx1 ; uint32_T knvjdfedfb [ 5 ] ; uint32_T apjnubwssp [ 5 ] ;
uint32_T ptu3l2ehpk [ 5 ] ; uint32_T ebmg2d0djd ; uint32_T nmrn1j5ohh [ 2 ] ;
uint32_T hl5ux0u3e5 [ 2 ] ; uint32_T kywikzuq0z [ 2 ] ; uint32_T op4s5nmfn0 [
16 ] ; uint32_T p3qcu4kyf3 [ 16 ] ; uint32_T d1rjlxqbuf [ 16 ] ; uint32_T
g130c2x32o [ 16 ] ; uint32_T dssqgth4gt [ 16 ] ; uint32_T erz4us2nfk [ 16 ] ;
uint32_T fyjcynthf1 [ 16 ] ; uint32_T acn3fu00s1 [ 16 ] ; uint32_T itcccsf0ct
[ 16 ] ; uint32_T lipbrcbfzk [ 16 ] ; uint32_T md1fsm3br3 ; uint32_T
be05daasmg ; uint32_T nq0rryljq1 [ 2 ] ; uint32_T ddr4l0n5i3 ; uint32_T
by2jasgm4o ; uint32_T daljbq5gtz ; struct { int_T Tail [ 16 ] ; int_T Head [
16 ] ; int_T Last [ 16 ] ; int_T CircularBufSize [ 16 ] ; int_T MaxNewBufSize
; } l1l2gip32s ; struct { int_T Tail [ 16 ] ; int_T Head [ 16 ] ; int_T Last
[ 16 ] ; int_T CircularBufSize [ 16 ] ; int_T MaxNewBufSize ; } lynamxwk0r ;
int_T nt5ueu32fc ; int_T ihk13omcli [ 6 ] ; int_T iwurle5qux [ 6 ] ; int_T
pe511og3ku [ 6 ] ; int_T ldrxgujyb0 ; int_T kksik1paup ; int_T cbrsqgmwzt ;
int_T j1zkhtxhzf ; int_T lfxnks51wi [ 3 ] ; int_T c5hzybmrlt [ 3 ] ; int8_T
cfvgbkovvu ; int8_T anhm4dpp2l ; int8_T iw455stvt1 ; int8_T pakc2g42kk ;
uint8_T oek5idxhme ; uint8_T bf5ec1ihjs ; uint8_T d04ooymyox ; uint8_T
nmnxbsefd1 ; uint8_T pny1rb4usr ; uint8_T chzc3nt2yy ; boolean_T cg1cpca1ek ;
boolean_T hrnzbhxy5d ; boolean_T ikjcop0bgm ; boolean_T p2ctlaxtsk ;
boolean_T bp4ac3vvj5 ; boolean_T jl5nu1i4l3 ; boolean_T lh250aajbj ;
boolean_T edqryqv5bk ; boolean_T l3qjgn1jqc ; boolean_T cyto13o4kt ;
boolean_T jgpyhmovpk ; boolean_T mu4revjjwi ; boolean_T pdvyjvvslc ;
boolean_T kbyn225ku2 ; boolean_T o5u4b02npb ; boolean_T jcdq2ohx3t ;
boolean_T bwa1fip2ky ; boolean_T pi3jxhaf2b ; gv4mkh5bt0 hztlwupntw ;
gv4mkh5bt0 n1ybyykngv ; jiigegnrkw jek5zaxern ; jiigegnrkw nikuyjvr0y ;
jiigegnrkw enohy5yaap ; pls4xc4scj pookhwl2ri ; pls4xc4scj hl5ibqcu3w ;
fiqejkualm dffuptpbcz ; fiqejkualm bd32gk0ocy ; a0dvcgex5j leuhdrxpbe ;
a0dvcgex5j csf3emrtxr ; a0dvcgex5j jvaexa3o5a ; o02wj5ik5e adqmzv0sx0 [ 12 ]
; fpbcqq3sgu pcwoeb21pm ; fpbcqq3sgu fthork0k0x2 ; } DW ; typedef struct {
real_T dmrka4iuwk [ 3 ] ; real_T jy1l3ujv3t [ 3 ] ; real_T ppiohzkobr [ 3 ] ;
real_T gz3b4js4ds [ 3 ] ; real_T oqemwaxlko [ 2 ] ; real_T n5m0nb0nkj [ 12 ]
; real_T c1kooexubz [ 12 ] ; real_T ndpus01ld4 [ 12 ] ; real_T bdt2nf5etq [ 2
] ; real_T ai1bi54qax [ 2 ] ; real_T a1z3hbtkhc [ 2 ] ; real_T iugjf2dp5k [ 2
] ; real_T kv0bz415kr [ 6 ] ; real_T hxqf43szbj [ 6 ] ; pjade3oksx adqmzv0sx0
[ 12 ] ; dry5l5lsph pcwoeb21pm ; dry5l5lsph fthork0k0x2 ; real_T jmsbhu4m05 ;
} X ; typedef int_T PeriodicIndX [ 3 ] ; typedef real_T PeriodicRngX [ 6 ] ;
typedef struct { real_T dmrka4iuwk [ 3 ] ; real_T jy1l3ujv3t [ 3 ] ; real_T
ppiohzkobr [ 3 ] ; real_T gz3b4js4ds [ 3 ] ; real_T oqemwaxlko [ 2 ] ; real_T
n5m0nb0nkj [ 12 ] ; real_T c1kooexubz [ 12 ] ; real_T ndpus01ld4 [ 12 ] ;
real_T bdt2nf5etq [ 2 ] ; real_T ai1bi54qax [ 2 ] ; real_T a1z3hbtkhc [ 2 ] ;
real_T iugjf2dp5k [ 2 ] ; real_T kv0bz415kr [ 6 ] ; real_T hxqf43szbj [ 6 ] ;
j0w55rdezp adqmzv0sx0 [ 12 ] ; il4tjwsha2 pcwoeb21pm ; il4tjwsha2 fthork0k0x2
; real_T jmsbhu4m05 ; } XDot ; typedef struct { boolean_T dmrka4iuwk [ 3 ] ;
boolean_T jy1l3ujv3t [ 3 ] ; boolean_T ppiohzkobr [ 3 ] ; boolean_T
gz3b4js4ds [ 3 ] ; boolean_T oqemwaxlko [ 2 ] ; boolean_T n5m0nb0nkj [ 12 ] ;
boolean_T c1kooexubz [ 12 ] ; boolean_T ndpus01ld4 [ 12 ] ; boolean_T
bdt2nf5etq [ 2 ] ; boolean_T ai1bi54qax [ 2 ] ; boolean_T a1z3hbtkhc [ 2 ] ;
boolean_T iugjf2dp5k [ 2 ] ; boolean_T kv0bz415kr [ 6 ] ; boolean_T
hxqf43szbj [ 6 ] ; io0vggrbfj adqmzv0sx0 [ 12 ] ; dawqgveeyg pcwoeb21pm ;
dawqgveeyg fthork0k0x2 ; boolean_T jmsbhu4m05 ; } XDis ; typedef struct {
ZCSigState asefyvndgw ; ZCSigState poxwpyd5xz ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct jwys52rryd_ { real32_T
Constant1_Value ; } ; struct jwys52rrydz_ { real32_T Constant1_Value ; } ;
struct jwys52rrydzh00_ { real_T Constant_Value ; real32_T
Constant_Value_dl1cryfboe ; } ; struct kkuqadxzh5_ { real_T Constant_Value ;
real32_T Constant_Value_nflcmvsqzo ; } ; struct kpxwjmhxii_ { real_T x_Y0 ;
real_T DistanceintoGustxLimitedtogustlengthd_IC ; real_T
DistanceintoGustxLimitedtogustlengthd_LowerSat ; } ; struct n5t5fi0dwr_ {
real_T EM_I ; real_T EM_LowerSaturationLimit ; real_T EM_P ; real_T
EM_UpperSaturationLimit ; real_T Constant1_Value ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T actf2T_Gain ;
real_T Switch1_Threshold ; real_T Gain7_Gain ; real_T Saturation_UpperSat ;
real_T Saturation_LowerSat ; real_T Gain2_Gain ; real_T Saturation1_UpperSat
; real_T Saturation1_LowerSat ; real_T Gain3_Gain ; real_T
Saturation_UpperSat_ollczcryiu ; real_T Saturation_LowerSat_oypzpqvfzv ;
real_T Gain_Gain ; real_T Saturation1_UpperSat_e5noinhxx3 ; real_T
Saturation1_LowerSat_ghkwhqvuwp ; real_T Gain5_Gain ; real_T ZeroGain_Gain ;
real_T Gain3_Gain_cb0ak2utk4 ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Multiply1_Gain ; real_T Constant3_Value ;
real_T Constant_Value ; real_T Constant1_Value_jux1hhk5qx ; real_T
DEP_incidence_Value ; real_T Constant_Value_hl5xkc3gs1 ; uint32_T
T2rpm_maxIndex [ 2 ] ; boolean_T Memory_InitialCondition ; } ; struct P_ {
struct_jutHZYEwOoNeidUZKCLQ8B dp_VTAIL ; struct_X4VfLKyPh2o5xFDym0ZDqD
dp_VTAIL_INDUCED ; struct_IzJ4J0FtAuhnGd5tRgSyHE dp_WING_root ;
struct_yWIZFWBbymsS8L1W0LWVH dp_WING_tip ; struct_nC6b04CeB5t4pOaoQVXKo
dp_DEP ; struct_OvGmMrPqfNtzpqofYdArSB dp_HTU ; struct_ledTFd3zOA1QjIJZGqbRtH
dp_FUSE_FIN ; real_T DEP_INTEG_IC ; real_T DEP_PID_IC ; real_T Euler0 [ 3 ] ;
real_T I [ 9 ] ; real_T S ; real_T Vb0 [ 3 ] ; real_T Xe0 [ 3 ] ; real_T
ground_alt ; real_T latlong0 [ 2 ] ; real_T m ; real_T omegab0 [ 3 ] ; real_T
u1_0 [ 6 ] ; real_T u2_0 [ 12 ] ; real_T u3_0 ; real_T u4_0 ; real_T
vtail_dist_to_wing ; real_T xyz_DEP [ 36 ] ; real_T xyz_cg [ 3 ] ; real32_T
vtail_nodes [ 48 ] ; real32_T wing_nodes [ 42 ] ; real_T
CompareToConstant_const ; real_T CompareToConstant_const_i014zkpdcc ; real_T
CompareToConstant_const_jqmuxowg3j ; real_T
CompareToConstant_const_b5kwy5yvv2 ; real_T
CompareToConstant_const_j3nekrd5nd ; real_T
CompareToConstant_const_gvfea0moje ; real_T Distanceintogustx_d_m ; real_T
Distanceintogusty_d_m ; real_T Distanceintogustz_d_m ; real_T
DiscreteWindGustModel1_d_m [ 3 ] ; real_T LinearSecondOrderActuator_fin_act_0
; real_T LinearSecondOrderActuator_fin_act_0_mm13zzlfoj [ 6 ] ; real_T
LinearSecondOrderActuator1_fin_act_0 [ 6 ] ; real_T
LinearSecondOrderActuator2_fin_act_0 [ 6 ] ; real_T
LinearSecondOrderActuator4_fin_act_0 ; real_T
LinearSecondOrderActuator5_fin_act_0 ; real_T
LinearSecondOrderActuator6_fin_act_0 ; real_T
LinearSecondOrderActuator_fin_act_vel ; real_T
LinearSecondOrderActuator_fin_act_vel_ddjzhl2ptw ; real_T
LinearSecondOrderActuator1_fin_act_vel ; real_T
LinearSecondOrderActuator2_fin_act_vel ; real_T
LinearSecondOrderActuator3_fin_act_vel ; real_T
LinearSecondOrderActuator4_fin_act_vel ; real_T
LinearSecondOrderActuator5_fin_act_vel ; real_T
LinearSecondOrderActuator6_fin_act_vel ; real_T
LinearSecondOrderActuator7_fin_act_vel ; real_T
LinearSecondOrderActuator8_fin_act_vel ; real_T FlatEarthtoLLA_psi ; real_T
DiscreteWindGustModel1_t_0 ; real_T DiscreteWindGustModel1_v_m [ 3 ] ; real_T
LinearSecondOrderActuator_wn_fin ; real_T
LinearSecondOrderActuator_wn_fin_ilmnm2ylbj ; real_T
LinearSecondOrderActuator1_wn_fin ; real_T LinearSecondOrderActuator2_wn_fin
; real_T LinearSecondOrderActuator3_wn_fin ; real_T
LinearSecondOrderActuator4_wn_fin ; real_T LinearSecondOrderActuator5_wn_fin
; real_T LinearSecondOrderActuator6_wn_fin ; real_T
LinearSecondOrderActuator7_wn_fin ; real_T LinearSecondOrderActuator8_wn_fin
; real_T LinearSecondOrderActuator_z_fin ; real_T
LinearSecondOrderActuator_z_fin_ag5smfntgf ; real_T
LinearSecondOrderActuator1_z_fin ; real_T LinearSecondOrderActuator2_z_fin ;
real_T LinearSecondOrderActuator3_z_fin ; real_T
LinearSecondOrderActuator4_z_fin ; real_T LinearSecondOrderActuator5_z_fin ;
real_T LinearSecondOrderActuator6_z_fin ; real_T
LinearSecondOrderActuator7_z_fin ; real_T LinearSecondOrderActuator8_z_fin ;
int32_T UDPSend1_remotePort ; int32_T UDPSend1_remotePort_ardthcndv5 ;
int32_T UDPSend_remotePort ; int32_T UDPSend1_remotePort_fttrxcefev ; int32_T
UDPSend1_remotePort_eq52r0avzy ; int32_T UDPSend1_remotePort_jffxhvsqzl ;
int32_T UDPSend1_remotePort_ijqt2smdg0 ; int32_T
UDPSend1_remotePort_ocmwsta0fc ; int32_T UDPSend1_remotePort_lq3erkca52 ;
int32_T UDPSend1_remotePort_eimzoxna1i ; int32_T
UDPSend1_remotePort_ni5g4d2iss ; int32_T UDPSend1_remotePort_azm1mqpelq ;
int32_T UDPSend1_remotePort_dt0jkdmcmg ; int32_T
UDPSend1_remotePort_bao1nst35q ; int32_T UDPSend1_remotePort_edlmksw0fl ;
boolean_T DiscreteWindGustModel1_Gx ; boolean_T DiscreteWindGustModel1_Gy ;
boolean_T DiscreteWindGustModel1_Gz ; real_T x_Y0 ; real_T
DistanceintoGustxLimitedtogustlengthd_IC ; real_T
DistanceintoGustxLimitedtogustlengthd_LowerSat ; real_T Gain3_Gain ; real_T
DeadZone2_Start ; real_T DeadZone2_End ; real_T Gain2_Gain ; real_T
DeadZone1_Start ; real_T DeadZone1_End ; real_T Gain1_Gain ; real_T
Saturation1_UpperSat ; real_T Saturation1_LowerSat ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; real_T DeadZone_Start ;
real_T DeadZone_End ; real_T Gain_Gain ; real_T Saturation2_UpperSat ; real_T
Saturation2_LowerSat ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Constant4_Value ; real_T Constant_Value ;
real_T Constant1_Value ; real_T Constant2_Value ; real_T SFunction_P1_Size [
2 ] ; real_T SFunction_P1 [ 45 ] ; real_T Numberofsimstepstoskip_Value ;
real_T Bias_Bias ; real_T Gain_Gain_pu50nbciii ; real_T Bias1_Bias ; real_T
Bias_Bias_jjp2hxzsy1 ; real_T Bias1_Bias_jgjixhvhbb ; real_T
Bias_Bias_gvhsf5vuyl ; real_T Bias1_Bias_gvvhyuyzsh ; real_T
Constant_Value_p2sv0iawa4 ; real_T Constant_Value_ddzso0nzyx ; real_T
Constant_Value_covdqsa2k4 ; real_T phithetapsi_WrappedStateUpperValue ;
real_T phithetapsi_WrappedStateLowerValue ; real_T Gain_Gain_mszzowmsuk ;
real_T uDLookupTable_tableData [ 3 ] ; real_T uDLookupTable_bp01Data [ 3 ] ;
real_T Gain_Gain_laazcdnihk ; real_T Gain_Gain_hkwjozvx2n ; real_T
Gain_Gain_mw0psof1f3 ; real_T Memory1_InitialCondition ; real_T
Switch_Threshold ; real_T Switch_Threshold_keldsx1mfj ; real_T
Gain_Gain_n4k11xn3pg ; real_T Gain_Gain_lmgk2iw1td ; real_T
Gain_Gain_aycx2qnlhg ; real_T Gain_Gain_fqf4wrixzl ; real_T
Memory1_InitialCondition_pjfkz2iyv3 ; real_T Switch_Threshold_lm0zosgxar ;
real_T Actuatorprocessingandtransportdelay10ms_InitialCondition [ 100 ] ;
real_T LapseRate_Gain ; real_T uT0_Gain ; real_T rho0_Gain ; real_T
LimitaltitudetoStratosphere_UpperSat ; real_T
LimitaltitudetoStratosphere_LowerSat ; real_T gR_Gain ; real_T
VariableTransportDelay1_MaxDelay ; real_T VariableTransportDelay1_InitOutput
; real_T Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ; real_T
Switch_Threshold_barcjzagnb ; real_T VariableTransportDelay_MaxDelay ; real_T
VariableTransportDelay_InitOutput ; real_T Step1_Time ; real_T Step1_Y0 ;
real_T Step1_YFinal ; real_T Switch1_Threshold ; real_T
Switch_Threshold_fa0qrtsblw ; real_T Memory_InitialCondition [ 3 ] ; real_T
Saturation1_UpperSat_faajmjiyue ; real_T Saturation1_LowerSat_fjfihtgctt ;
real_T Saturation_UpperSat_hpioqrnjvm ; real_T Saturation_LowerSat_ckp25ja5tp
; real_T Switch_Threshold_nwgyj0aeyx ; real_T
Memory_InitialCondition_hnyjdse4h4 [ 3 ] ; real_T
Saturation1_UpperSat_jujzsatqjs ; real_T Saturation1_LowerSat_ifds41vj3d ;
real_T Saturation_UpperSat_n2gmlqdobk ; real_T Saturation_LowerSat_egflfzvuqx
; real_T FrictionCoefficient_Gain ; real_T
FrictionCoefficient_Gain_bld3rumxab ; real_T Switch_Threshold_kslqyxqwsc ;
real_T Memory_InitialCondition_iqeioiam5g [ 3 ] ; real_T
Saturation1_UpperSat_bgrqxpsgy2 ; real_T Saturation1_LowerSat_mtmmhddwjb ;
real_T Saturation_UpperSat_fkspttvlxs ; real_T Saturation_LowerSat_ihlfa0mqdb
; real_T FrictionCoefficient_Gain_jiuksux40s ; real_T Gain_Gain_cssolhvy5w ;
real_T Gain_Gain_ay20xvgxq5 ; real_T Gain_Gain_iuh3lzw4i0 ; real_T
Gain_Gain_inh0c1mtep ; real_T Gain_Gain_iso0wdlaw3 ; real_T
Gain_Gain_otfwfmpf50 ; real_T Gain_Gain_n2lq1m5z15 ; real_T P0_Gain ; real_T
FCCframedelay10msassumed100HzFCC_InitialCondition [ 100 ] ; real_T
Gain1_Gain_h4hra1gikq ; real_T Gain2_Gain_ic5npr3xa1 ; real_T
Gain_Gain_g41sdlhqvv ; real_T uDLookupTable1_tableData [ 2 ] ; real_T
uDLookupTable1_bp01Data [ 2 ] ; real_T Gain_Gain_b0rnnooty0 ; real_T
Gain_Gain_lercwvznpd ; real_T Delay1_InitialCondition ; real_T
Delay10_InitialCondition ; real_T Delay18_InitialCondition [ 15 ] ; real_T
Delay19_InitialCondition ; real_T Delay2_InitialCondition ; real_T
Delay20_InitialCondition ; real_T Delay21_InitialCondition [ 15 ] ; real_T
Delay22_InitialCondition ; real_T Delay23_InitialCondition ; real_T
Delay25_InitialCondition ; real_T Delay26_InitialCondition ; real_T
Delay27_InitialCondition ; real_T Delay28_InitialCondition ; real_T
Delay29_InitialCondition ; real_T Delay3_InitialCondition ; real_T
Delay35_InitialCondition ; real_T Delay6_InitialCondition ; real_T
Delay7_InitialCondition ; real_T Delay8_InitialCondition ; real_T
Delay9_InitialCondition ; real_T _InitialCondition ; real_T sms_Gain ; real_T
SFunction_P1_Size_msgrnckvzs [ 2 ] ; real_T SFunction_P1_gkb1uhxswe ; real_T
Constant_Value_grffgcb3uj ; real_T Constant1_Value_ep5qwhnxw4 ; real_T
Constant2_Value_dnaxpvvz45 ; real_T Constant2_Value_euehonucuw ; real_T
Constant_Value_o5fhcpqqyu ; real_T Constant1_Value_a0rz4phgln ; real_T
Bias_Bias_ftrguhqylg ; real_T Constant2_Value_mxdetvroc4 ; real_T
Bias1_Bias_kwaqdylxmf ; real_T Bias_Bias_konxswsfpe ; real_T
Gain_Gain_jwbuilkyxy ; real_T Bias1_Bias_gdznygtef3 ; real_T
Bias_Bias_kd45ia31j2 ; real_T Constant2_Value_d2ebp0gj1g ; real_T
Bias1_Bias_pcofu2atfo ; real_T Constant_Value_cds1oetfvb ; real_T
Constant1_Value_auykfi4siv ; real_T Constant2_Value_dc1ztqo1sh ; real_T
Constant3_Value ; real_T Constant_Value_bwixaan2i5 ; real_T
Constant_Value_joj4ebuyjq ; real_T Constant_Value_nam4eq1guw ; real_T f_Value
; real_T Constant2_Value_fqbq1clpin ; real_T Constant3_Value_nbcxsvbsnn ;
real_T Constant2_Value_evxyvbxyx4 ; real_T Constant3_Value_arqhpk5tsi ;
real_T Constant2_Value_imckxbitho ; real_T Constant3_Value_kdceg0pib4 ;
real_T Constant_Value_lkyy414dse ; real_T Constant1_Value_poq4unoobj ; real_T
Constant_Value_jra04za24u [ 3 ] ; real_T Constant_Value_lx5fpqludr ; real_T
Constant_Value_mn4jvly12r [ 8 ] ; real_T Constant1_Value_dqqxjknpbv [ 8 ] ;
real_T Constant8_Value [ 16 ] ; real_T Constant_Value_asshyiafnn [ 8 ] ;
real_T Constant1_Value_h01num5fy3 [ 8 ] ; real_T Constant8_Value_gsd4tzxrvv [
16 ] ; real_T Constant_Value_b3o3asdnd0 [ 21 ] ; real_T
Constant8_Value_fdguqum2g1 [ 5 ] ; real_T Constant8_Value_dn0swibioj [ 2 ] ;
real_T Constant_Value_benf1an55k [ 21 ] ; real_T Constant8_Value_o2vddtqbhz [
5 ] ; real_T Constant8_Value_oaybf0pjve [ 2 ] ; real_T
Constant_Value_ootamvdz1c ; real_T Constant1_Value_aexthjzkeg ; real_T
Constant2_Value_btnragtfjb [ 9 ] ; real_T AltitudeofTroposphere_Value ;
real_T Constant_Value_mmbn22yeyo ; real_T SeaLevelTemperature_Value ; real_T
u_Value ; real_T Constant_Value_nidy3scify [ 3 ] ; real_T
Gain_Gain_hvvnixqugo [ 12 ] ; real_T Constant2_Value_eyx5hzotxm [ 12 ] ;
real_T Inclination_Value ; real_T Constant_Value_jkrncbjqj3 ; real_T
Multiply_Gain ; real_T Constant_Value_jax04gsciy ; real_T
Constant_Value_ofr0qgx5yn [ 3 ] ; real_T Constant1_Value_i0jzjc51w0 [ 3 ] ;
real_T Constant2_Value_dksr45kxji [ 3 ] ; real_T Constant_Value_czh5rbe04d ;
real_T Constant_Value_fgevrsqc4v ; real_T Constant1_Value_dgi3p5u40k ; real_T
Constant2_Value_p2rjztbk2r ; real_T Constant_Value_o1yp2gl00i ; real_T
Constant1_Value_eyubj2pyfz ; real_T Constant_Value_dkfqzg3jt5 ; real_T
Constant_Value_gptvvpedc0 ; real_T Constant1_Value_es2hmwpsih ; real_T
Constant2_Value_er0w5mtd4j ; real_T Constant_Value_aqtgynqvul ; real_T
Constant1_Value_jtm4r5yj4j ; real_T Constant_Value_dosqprdn32 ; real_T
Constant_Value_ivz01hdudw ; real_T Constant1_Value_nw1qma1fjc ; real_T
Constant2_Value_hhw30thswa ; real_T Constant_Value_feb2wg5gid ; real_T
Constant1_Value_f4dk2n3412 ; real_T Constant1_Value_grmbs0ngpp [ 3 ] ; real_T
Constant2_Value_eyfztz0fxi [ 3 ] ; real_T Constant2_Value_p0sma1ifq3 ; real_T
Constant1_Value_aeivuiuwhs ; real_T Constant1_Value_crvf1ymqjc ; real_T
Constant_Value_ph3kv45jlz ; real_T Constant3_Value_gdofiqtr3v ; real_T
Constant1_Value_po2h1uw5ro ; real_T Constant_Value_nxyjglhqnl ; real_T
deviceID_Value ; real_T Constant1_Value_ksii3tuk3x ; real_T
Constant2_Value_ovsjzrpt3j ; real_T Constant_Value_b3waei3ut2 ; real_T
const_Value ; real32_T Limitaltitudetotroposhere_UpperSat ; real32_T
Limitaltitudetotroposhere_LowerSat ; real32_T Gain_Gain_igdiaogfc0 ; real32_T
Gain_Gain_acyum2oy5l ; real32_T uDLookupTable_bp01Data_anwusoh2uk [ 6 ] ;
real32_T uDLookupTable1_bp01Data_lct4mwibxn [ 6 ] ; real32_T
uDLookupTable2_bp01Data [ 6 ] ; real32_T Saturation_UpperSat_b2a52laupk ;
real32_T Saturation_LowerSat_gotqetz1tq ; real32_T Gain2_Gain_pp1pwsqq1n ;
real32_T Gain3_Gain_i1yimbgde1 ; real32_T Prelookup_BreakpointsData [ 13 ] ;
real32_T Prelookup1_BreakpointsData [ 15 ] ; real32_T Gain_Gain_llsqu3hkdm ;
real32_T Constant_Value_guxqtm0enf ; real32_T Constant7_Value [ 16 ] ;
real32_T Constant1_Value_lhco2hmkqd [ 48 ] ; real32_T NodePoints_Value [ 21 ]
; real32_T NodePoints_Value_d4b2lmxebb [ 21 ] ; real32_T
Constant1_Value_b4mc4ixfm2 ; real32_T extra_drag_Value ; real32_T
gear_drag_Value ; uint32_T InterpolationUsingPrelookup1_dimSize [ 4 ] ;
uint32_T InterpolationUsingPrelookup1_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_gfiklomvd1 [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex_kpkpckmswm [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_nrl20k3nz5 [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex_halnsma1cb [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_bwdov31odu [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex_dnuuotdmkt [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_lcwylc1smw [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex_cy2xlkh5vq [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_c5irdqqd1s [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex_d44fsejhpt [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_iia0rqhr03 [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex_f1aiexynmu [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_cc1prjb2oo [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex_n2qqbs4dob [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_kx41jhq53z [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_maxIndex_dvymep4nij [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_j2ofnaf0w0 [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex_fiuiapwlsq [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_duz043yjyq [ 4 ] ; uint32_T
InterpolationUsingPrelookup2_maxIndex_bi1sjla3q2 [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_n5hof3ggty [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex_frabtm3htz [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_dkrtirzueo [ 4 ] ; uint32_T
InterpolationUsingPrelookup3_maxIndex_imdp4seazn [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_dqlnhgz1zi [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex_o4wzqxphno [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_p4aarrlaxb [ 4 ] ; uint32_T
InterpolationUsingPrelookup4_maxIndex_mqwubj3l1q [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_hlna0n1104 [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex_p1qlpsazb4 [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_p4p42jneab [ 4 ] ; uint32_T
InterpolationUsingPrelookup5_maxIndex_oxrypmydry [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_cdsngd0wzd [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex_g3wkr4rrcb [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_dpanpvfjmk [ 4 ] ; uint32_T
InterpolationUsingPrelookup6_maxIndex_mdnu5qffrq [ 4 ] ; uint32_T
V_induced_dimSize [ 4 ] ; uint32_T alpha_induced_dimSize [ 4 ] ; uint32_T
InterpolationUsingPrelookup1_dimSize_ff4dr0zil3 [ 3 ] ; uint32_T
InterpolationUsingPrelookup2_dimSize_kfgynmyj32 [ 3 ] ; uint32_T
InterpolationUsingPrelookup3_dimSize_m2ki2jhx1z [ 3 ] ; uint32_T
InterpolationUsingPrelookup4_dimSize_juyddnk1fb [ 3 ] ; uint32_T
InterpolationUsingPrelookup5_dimSize_mnvowrob4d [ 3 ] ; uint32_T
InterpolationUsingPrelookup6_dimSize_lpul1da2p2 [ 3 ] ; uint32_T
Plookup_maxIndex [ 2 ] ; boolean_T Constant_Value_l3yr2jaxah ; boolean_T
Constant1_Value_dhktifwxn5 ; boolean_T Constant_Value_hagifheq3t ; boolean_T
Constant1_Value_apy2wpsmee ; boolean_T Constant_Value_bmpfzxx1ux ; boolean_T
Constant1_Value_fad3jx5usw ; uint8_T Constant_Value_ecr3ukwupu [ 45 ] ;
uint8_T Constant_Value_cj4suguqdh [ 48 ] ; uint8_T
ManualSwitch_CurrentSetting ; uint8_T ManualSwitch1_CurrentSetting ; uint8_T
ManualSwitch1_CurrentSetting_cwepdspi5f ; uint8_T Constant_Value_ezp4vos5at [
39 ] ; uint8_T Constant_Value_o1jhv21mne [ 39 ] ; uint8_T
Constant_Value_oln3j4ocph [ 29 ] ; uint8_T Constant_Value_deiptb1fdi [ 27 ] ;
uint8_T Constant_Value_bunajjeyd1 [ 40 ] ; uint8_T Constant_Value_fu24dwcohf
[ 40 ] ; uint8_T Constant_Value_p45zmbuefy [ 32 ] ; uint8_T
Constant_Value_mpqd4zb22a [ 37 ] ; uint8_T Constant_Value_prr5w4kjl2 [ 37 ] ;
uint8_T Constant_Value_lqvyli4q5s [ 37 ] ; uint8_T Constant_Value_e2xroppgrn
[ 51 ] ; uint8_T Constant_Value_nmj1ootknt [ 51 ] ; n5t5fi0dwr adqmzv0sx0 ;
kpxwjmhxii pcwoeb21pm ; kpxwjmhxii fthork0k0x2 ; kkuqadxzh5 fchchnbmez ;
jwys52rrydzh00 nyqetrz43uqkkp ; jwys52rrydz nyqetrz43uq ; jwys52rryd
nyqetrz43u ; } ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B
rtB ; extern X rtX ; extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern P rtP
; extern mxArray * mr_UNIFIER_GetDWork ( ) ; extern void mr_UNIFIER_SetDWork
( const mxArray * ssDW ) ; extern mxArray *
mr_UNIFIER_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * UNIFIER_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
