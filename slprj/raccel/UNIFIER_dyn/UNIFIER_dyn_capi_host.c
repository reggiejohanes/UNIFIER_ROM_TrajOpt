#include "UNIFIER_dyn_capi_host.h"
static UNIFIER_dyn_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        UNIFIER_dyn_host_InitializeDataMapInfo(&(root), "UNIFIER_dyn");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
