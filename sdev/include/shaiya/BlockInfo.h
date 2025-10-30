#pragma once
#include <shaiya/include/common.h>
#include <shaiya/include/common/UserTypes.h>

namespace shaiya
{
    #pragma pack(push, 1)
    struct BlockInfo
    {
        uint32_t charId;      //0x00
        String<21> charName;  //0x04
        String<51> memo;      //0x19
        // 0x4C
    };
    #pragma pack(pop)

    static_assert(sizeof(BlockInfo) == 0x4C);
}
