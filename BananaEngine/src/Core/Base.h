#pragma once

#define BN_THROW_ERROR(type, check, msg) { if(!(check)) { printf("ERROR (%s): %s\n", type, msg); __debugbreak(); assert(0); } }
#define BN_THROW_SOFT_ERROR(type, check, msg) { if(!(check)) { printf("ERROR (%s): %s\n", type, msg); __debugbreak(); } }
#define BN_THROW_WARNING(type, check, msg) { if(!(check)) { printf("WARNING (%s): %s\n", type, msg); } }
