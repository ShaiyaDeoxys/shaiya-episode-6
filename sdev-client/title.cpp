#include <util/util.h>
#include "include/main.h"
#include "include/static.h"
#include "include/shaiya/include/CCharacter.h"
#include "include/shaiya/include/CDataFile.h"
#include "include/shaiya/include/CEffectData.h"
#include "include/shaiya/include/CMonster.h"
#include "include/shaiya/include/CStaticText.h"
#include "include/shaiya/include/ItemInfo.h"

using namespace shaiya;

namespace title
{
    constexpr float chat_y_add = 1.75F;

    struct TitleInfo {
        const char* text;
        int itemId;
        const char* effectFileName;
        uint32_t textColor;

    };

    const TitleInfo titles[] = {
        {"Champion of Shaiya", 120043, "character_effect_01.eft", 0xFFFFC0CB},  // Rosa
        {"Hero of Shaiya", 120044, "Armor_Enchant_F_A.eft", 0xFFFF0000},        // Vermelho
        {"Guardian of Shaiya", 120045, "Armor_Enchant_F_AS.eft", 0xFF00FF00},   // Verde
        {"Legend of Shaiya", 120046, "character_effect_01.eft", 0xFFFFFF00},    // Amarelo
        {"Shadow Slayer", 120047, "character_effect_01.eft", 0xFF800080},       // Roxo
        {"Divine Warrior", 120048, "character_effect_01.eft", 0xFF87CEEB},      // Azul Claro
        {"Master of Elements", 120049, "character_effect_01.eft", 0xFFFFA500},  // Laranja
        {"Eternal Conqueror", 120050, "character_effect_01.eft", 0xFF708090},   // Cinza
        {"Celestial Guardian", 120051, "character_effect_01.eft", 0xFFADD8E6},  // Azul Celeste
        {"Dragonbane", 120052, "character_effect_01.eft", 0xFF8B0000},          // Vermelho Escuro
        {"Arcane Overlord", 120053, "character_effect_01.eft", 0xFF4B0082},     // Índigo
        {"Doom Bringer", 120054, "character_effect_01.eft", 0xFF000000},        // Preto
        {"Lightbringer", 120055, "character_effect_01.eft", 0xFFFFF8DC},        // Branco Amarelado
        {"Stormcaller", 120056, "character_effect_01.eft", 0xFF4682B4},         // Azul Aço
        {"Blood Knight", 120057, "character_effect_01.eft", 0xFFDC143C},        // Carmesim
        {"Voidwalker", 120058, "character_effect_01.eft", 0xFF483D8B},          // Azul Escuro
        {"Frozen King", 120059, "character_effect_01.eft", 0xFF00FFFF},         // Ciano
        {"Hellforged", 120060, "character_effect_01.eft", 0xFFFF4500},          // Laranja Avermelhado
        {"Starborn", 120061, "character_effect_01.eft", 0xFFDAA520},            // Dourado
        {"Nightfall Sentinel", 120062, "character_effect_01.eft", 0xFF191970},  // Azul Meia-noite
        {"Soul Reaper", 120063, "character_effect_01.eft", 0xFFB22222},         // Vermelho Tijolo
        {"Eclipse Lord", 120064, "character_effect_01.eft", 0xFF2F4F4F},        // Cinza Escuro
        {"Titan of War", 120065, "character_effect_01.eft", 0xFF556B2F},        // Verde Oliva
        {"Warden of Light", 120066, "character_effect_01.eft", 0xFFFFFFF0},     // Branco Fantasma
        {"Infernal Overlord", 120067, "character_effect_01.eft", 0xFFFF6347},   // Tomate
        {"Lunar Guardian", 120068, "character_effect_01.eft", 0xFFB0C4DE},      // Azul Claro Acinzentado
        {"Solar Ascendant", 120069, "character_effect_01.eft", 0xFFFFD700},     // Ouro
        {"Abyss Stalker", 120070, "character_effect_01.eft", 0xFF2E0854},       // Roxo Profundo
        {"Cosmic Warlord", 120071, "character_effect_01.eft", 0xFF8A2BE2},      // Azul Violeta
        {"Phantom Blade", 120072, "character_effect_01.eft", 0xFF778899},       // Cinza Azul
        {"Crimson Executioner", 120073, "character_effect_01.eft", 0xFFCD5C5C}, // Castanho Avermelhado
        {"Stormbringer", 120074, "character_effect_01.eft", 0xFF00BFFF},        // Azul Céu Profundo
        {"Eldritch Master", 120075, "character_effect_01.eft", 0xFF6A5ACD},     // Azul Ardósia Médio
        {"Venomous Lord", 120076, "character_effect_01.eft", 0xFF9ACD32},       // Verde Amarelado
        {"Frostborn Titan", 120077, "character_effect_01.eft", 0xFF4682B4},     // Azul Aço
        {"Ancient Paragon", 120078, "character_effect_01.eft", 0xFF5F9EA0},     // Azul Cadete
        {"Dread Knight", 120079, "character_effect_01.eft", 0xFF8B0000},        // Vermelho Escuro
        {"Riftwalker", 120080, "character_effect_01.eft", 0xFF9400D3},          // Violeta Escuro
        {"Demonhunter", 120081, "character_effect_01.eft", 0xFFDC143C},         // Carmesim
        {"Moonshadow Assassin", 120082, "character_effect_01.eft", 0xFF778899}, // Cinza Azul
        {"Guardian of the Ancients", 120083, "character_effect_01.eft", 0xFFD2691E}, // Chocolate
        {"Starforged Champion", 120084, "character_effect_01.eft", 0xFFDAA520}, // Dourado
        {"Spectral Phantom", 120085, "character_effect_01.eft", 0xFFDDA0DD},    // Ameixa
        {"Sunfire Lord", 120086, "character_effect_01.eft", 0xFFFF4500},        // Laranja Avermelhado
        {"The Unyielding", 120087, "character_effect_01.eft", 0xFF191970},      // Azul Meia-noite
        {"Blade of the Eclipse", 120088, "character_effect_01.eft", 0xFF2F4F4F}, // Cinza Escuro
        {"Titanborn Warlord", 120089, "character_effect_01.eft", 0xFF556B2F},   // Verde Oliva
        {"Wrath of the Fallen", 120090, "character_effect_01.eft", 0xFF800000}, // Marrom Escuro
        {"Arcane Tempest", 120091, "character_effect_01.eft", 0xFF8A2BE2},      // Azul Violeta
        {"Harbinger of Chaos", 120092, "character_effect_01.eft", 0xFF9932CC},  // Orquídea Escura
        {"Avatar of Destruction", 120093, "character_effect_01.eft", 0xFFB22222}, // Vermelho Tijolo
        {"Eternal Vanguard", 120094, "character_effect_01.eft", 0xFFADFF2F},    // Verde Amarelo
        {"Voidborn Reaper", 120095, "character_effect_01.eft", 0xFF483D8B},     // Azul Escuro
        {"Ascendant Overlord", 120096, "character_effect_01.eft", 0xFFFFD700},  // Ouro
    };


    void hook(CCharacter* user, float x, float y, float extrusion)
    {
        const int effectDataId = 280;

        if (!user->pet)
        {
            // Se não houver pet, remova o título e efeito
            if (user->title.text)
            {
                user->title.text = nullptr;
            }
            if (user->title.effectDataId)
            {
                CCharacter::RemoveEffect(user, user->title.effectDataId, 0);
                user->title.effectDataId = 0;
            }
            return;
        }

        auto itemInfo = CDataFile::GetItemInfo(user->petType, user->petTypeId);
        if (!itemInfo)
            return;

        auto itemId = (itemInfo->type * 1000) + itemInfo->typeId;

        const char* titleText = nullptr;
        const char* effectFileName = nullptr;
        uint32_t textColor = 0;

        for (const auto& title : titles) {
            if (itemId == title.itemId) {
                titleText = title.text;
                effectFileName = title.effectFileName;
                textColor = title.textColor;
                break;
            }
        }

        if (!titleText || !effectFileName)
            return;

        if (user->title.text)
        {
            // Atualize o título se necessário
            user->title.text = CStaticText::Create(titleText);
        }
        else
        {
            // Crie um novo título
            user->title.text = CStaticText::Create(titleText);
        }

        auto w = CStaticText::GetTextWidth(titleText);
        user->title.pointX = long(w * 0.5);

        auto posY = y - 30.0;
        auto posX = x - user->title.pointX;

        CStaticText::Draw(user->title.text, long(posX), long(posY), extrusion, textColor);

        if (!user->title.effectDataId)
        {
            CCharacter::RemoveEffect(user, effectDataId, 0);
            CEffectData::CreateFromFile(&g_var->eftCharacterEffect01, "data/Effect", effectFileName);
            CCharacter::RenderEffect(user, effectDataId, 0, 0, &user->pos, &user->dir, &user->up, 0);
            user->title.effectDataId = effectDataId;
        }
    }

    void remove_effect(CCharacter* user)
    {
        if (!user->title.effectDataId)
            return;

        CCharacter::RemoveEffect(user, user->title.effectDataId, 0);
        user->title.effectDataId = 0;
    }

    int create_effect(const char* effectFileName)
    {
        return CEffectData::CreateFromFile(&g_var->eftCharacterEffect01, "data/Effect", effectFileName);
    }

}

unsigned u0x453E81 = 0x453E81;
void __declspec(naked) naked_0x453E7C()
{
    __asm
    {
        pushad
        pushfd

        sub esp, 0xC
        fld dword ptr[esp + 0x4C]
        fstp dword ptr[esp + 0x8]

        fld dword ptr[esp + 0x48]
        fstp dword ptr[esp + 0x4]

        fld dword ptr[esp + 0x44]
        fstp dword ptr[esp]

            push esi // user
                call title::hook
                add esp, 0x10

                popfd
                popad

                // original
                mov eax, dword ptr ds : [0x22B69A8]
                jmp u0x453E81
    }
}

unsigned u0x4184CF = 0x4184CF;
unsigned u0x418312 = 0x418312;
void __declspec(naked) naked_0x41830D()
{
    __asm
    {
        // monster->model
        cmp dword ptr[eax + 0x74], 0x0
        je _0x4184CF

        // original
        cmp dword ptr[esp + 0x38], 0x0
        jmp u0x418312

        _0x4184CF :
        jmp u0x4184CF
    }
}

unsigned u0x412765 = 0x412765;
void __declspec(naked) naked_0x41275F()
{
    __asm
    {
        fld dword ptr[title::chat_y_add]
        jmp u0x412765
    }
}

unsigned u0x59F1BC = 0x59F1BC;
void __declspec(naked) naked_0x59F114()
{
    __asm
    {
        pushad

        push esi
        call title::remove_effect
        add esp, 0x4

        popad

        jmp u0x59F1BC
    }
}

unsigned u0x59F484 = 0x59F484;
void __declspec(naked) naked_0x59F299()
{
    __asm
    {
        pushad

        push esi
        call title::remove_effect
        add esp, 0x4

        popad

        jmp u0x59F484
    }
}

unsigned u0x412320 = 0x412320;
unsigned u0x59833A = 0x59833A;
void __declspec(naked) naked_0x598335()
{
    __asm
    {
        // original
        call u0x412320

        pushad

        push edi
        call title::remove_effect
        add esp, 0x4

        popad

        jmp u0x59833A
    }
}

unsigned u0x58C460 = 0x58C460;
unsigned u0x42D6D2 = 0x42D6D2;
unsigned u0x42D8B5 = 0x42D8B5;
unsigned u0x42BC77 = 0x42BC77;
void __declspec(naked) naked_0x42D6C5()
{
    __asm
    {
        // original
        call u0x58C460
        test eax, eax
        je _0x42BC77

        pushad

        call title::create_effect
        test eax, eax

        popad

        jne _0x42D8B5
        jmp u0x42D6D2

        _0x42D8B5 :
        jmp u0x42D8B5

            _0x42BC77 :
        jmp u0x42BC77
    }
}

void hook::title()
{
    util::detour((void*)0x453E7C, naked_0x453E7C, 5);
    // hide pets without a model
    util::detour((void*)0x41830D, naked_0x41830D, 5);
    // increase chat balloon height (1.5 to 1.75)
    util::detour((void*)0x41275F, naked_0x41275F, 6);
    // pet remove case
    util::detour((void*)0x59F114, naked_0x59F114, 5);
    // pet swap case
    util::detour((void*)0x59F299, naked_0x59F299, 5);
    // 0x504 handler
    util::detour((void*)0x598335, naked_0x598335, 5);
    // create effect from .eft file
    util::detour((void*)0x42D6C5, naked_0x42D6C5, 5);
}
