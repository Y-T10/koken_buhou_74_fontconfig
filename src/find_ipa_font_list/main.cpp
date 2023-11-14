#include <initializer_list>
#include <filesystem>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

#include "fontconfig/fontconfig.h"

const std::string GetPropValue(const FcPattern* pattern, const char* prop) {
    FcChar8* str = nullptr;
    FcPatternGetString(pattern, prop, 0, &str);
    return (char*)str;
}

FcFontSet* ListFonts(FcPattern* pattern, FcConfig* config, const std::initializer_list<const char*>& props) {
    FcObjectSet* propObj = FcObjectSetCreate();
    if(!propObj) {
        return NULL;
    }

    for(const auto& p: props) {
        // TODO: FcFalseに対する処理を追加する
        FcObjectSetAdd(propObj, p);
    }

    FcFontSet* list = FcFontList(config, pattern, propObj);
    FcObjectSetDestroy(propObj);
    return list;
}

const std::filesystem::path GetFontPath(FcFontSet* list) {
    if(list->nfont <= 0) {
        return "";
    }
    return GetPropValue(list->fonts[0], FC_FILE);
}

const std::filesystem::path SearchFontPath(FcPattern* pattern, FcConfig* config = nullptr) {
    FcFontSet* list = ListFonts(pattern, config, {FC_FAMILY, FC_FULLNAME, FC_FILE});
    if(!list) {
        return "";
    }
    const std::filesystem::path foundPath = GetFontPath(list);
    FcFontSetDestroy(list);
    return foundPath;
}

int main() {
    FcInit();

    FcPattern* searchPattern = FcPatternCreate();
    FcPatternAddString(searchPattern, FC_FAMILY, (const FcChar8*)"IPAex明朝");

    const auto foundPath = SearchFontPath(searchPattern);
    if(!foundPath.empty()) {
	    printf("found font path: %s\n", foundPath.generic_string().c_str());
    }

    FcPatternDestroy(searchPattern);

    FcFini();
    return 0;
}